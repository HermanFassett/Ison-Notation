#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QFontDatabase>
#include <QFont>
#include <QPrinter>
#include <QTextDocument>
#include <QTextDocumentWriter>
#include <QMidiFile.h>
#include <QMidiOut.h>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Load Byzantine symbol fonts
    const int FONT_COUNT = 6;
    QString fonts[FONT_COUNT] = { "Fthora", "Omega", "Oxeia", "Psaltica", "Special1", "Special2" };
    int id = 0;
    for (int i = 0; i < FONT_COUNT; i++) {
        id = m_fonts.addApplicationFont(":/ByzMusicFonts/" + fonts[i]);
        if (id < 0) {
            QMessageBox::critical(NULL, "Error", "Failed to load all Byzantine Music fonts. Please contact developer.");
            return;
        }
    }
    ui->textBrowser->setFontFamily(m_fonts.applicationFontFamilies(3).at(0));
    ui->textBrowser->setFontPointSize(20);
    ui->textEdit->setFontPointSize(12);

    // Slots / Signals
    // Menu Actions
    // File
    connect(ui->actionNew, SIGNAL(triggered(bool)), this, SLOT(newFile()));
    connect(ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(open()));
    connect(ui->actionSave, SIGNAL(triggered(bool)), this, SLOT(save()));
    connect(ui->actionSave_As, SIGNAL(triggered(bool)), this, SLOT(saveAs()));
    connect(ui->actionExit, SIGNAL(triggered(bool)), this, SLOT(close()));
    // Export
    connect(ui->actionMIDI, SIGNAL(triggered(bool)), this, SLOT(exportMidi()));
    connect(ui->actionODF, SIGNAL(triggered(bool)), this, SLOT(exportODF()));
    connect(ui->actionPDF, SIGNAL(triggered(bool)), this, SLOT(exportPDF()));
    // Edit
    connect(ui->actionUndo, SIGNAL(triggered(bool)), this, SLOT(undoEdit()));
    connect(ui->actionRedo, SIGNAL(triggered(bool)), this, SLOT(redoEdit()));
    // Other Actions
    connect(ui->textEdit, SIGNAL(textChanged()), this, SLOT(changed()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Override close event
void MainWindow::closeEvent(QCloseEvent *event) {
    // Ask user if they want to close with unsaved changes
    if (!saved) {
        QMessageBox::StandardButton res = QMessageBox::question(this, "Ison Notation",
                                          tr("You have unsaved changes. Are you sure you want to exit?"),
                                          QMessageBox::Cancel | QMessageBox::Yes,
                                          QMessageBox::Cancel);
        if (res == QMessageBox::Cancel) event->ignore();
        else event->accept();
    } else event->accept();
}

void MainWindow::resetTitle() {
    // Change window title to reflect file name and save state
    QString name = QString(m_fileName).remove(0, m_fileName.lastIndexOf('/') + 1);
    if (!this->saved) name.append('*');
    this->topLevelWidget()->setWindowTitle("Ison Notation v1.0 - " + name);
}

void MainWindow::newFile() {
    // Reset to a new file
    m_dataSet = nullptr;
    m_fileName = QString();
    ui->textEdit->clear();
    resetTitle();
}

const QString MainWindow::openFile(const QString& fileName) const {
    // Load a string of characters from file
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly) || !file.exists()) {
        QMessageBox::information(NULL, tr("Unable to open file"), file.errorString());
        return "";
    }
    // Read data as string
    QTextStream in(&file);
    QString output = in.readAll();
    return output;
}

void MainWindow::open() {
    // Open a file
    const QString fileName = QFileDialog::getOpenFileName(this, tr("Open .ison file"), "", tr("Ison Notation files (*.*)"));
    if (fileName.isEmpty()) return;
    const QString input = openFile(fileName);
    this->m_dataSet = parse(input);
    this->m_fileName = fileName;
    ui->statusBar->showMessage("File opened", 5000);
    ui->textEdit->setText(input);
    saved = true;
    resetTitle();
}

void MainWindow::save() {
    if (m_fileName.isEmpty()) {
        saveAs();
    } else {
        saveFile(m_fileName);
    }
}

void MainWindow::saveAs() {
    const QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Ison Notation file (*.ison)"));
    if (fileName.isEmpty()) return;
    saveFile(fileName);
}

void MainWindow::saveFile(const QString &fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadWrite)) {
        QMessageBox::information(this, tr("Unable to open file"), file.errorString());
        return;
    }
    QTextStream out(&file);
    out << ui->textEdit->toPlainText();
    saved = true;
    ui->statusBar->showMessage("File saved", 5000);
    m_fileName = QString(fileName);
    resetTitle();
    file.close();
}

void MainWindow::changed() {
    QString input = ui->textEdit->toPlainText();
    m_dataSet = parse(input);
    saved = false;
    display();
    resetTitle();
}

void MainWindow::undoEdit() {
    ui->textEdit->undo();
    ui->statusBar->showMessage("Edit undone", 5000);
}

void MainWindow::redoEdit() {
    ui->textEdit->redo();
    ui->statusBar->showMessage("Edit redone", 5000);
}

void MainWindow::display() {
    ui->textBrowser->clear();
    auto iter = m_dataSet->iterator();
    for (iter; iter.hasNext(); iter++) {
        // Add item to browser
        QString code = QString::fromStdString(iter.symbol()->getFontCode());
        ui->textBrowser->setText(ui->textBrowser->toPlainText() + code);
    }
}

void MainWindow::exportMidi() {
    // Get file name
    const QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("MIDI (*.mid)"));
    if (fileName.isEmpty()) return;
    // Load base file since I can't manage to create base from scratch
    QMidiFile f;
    f.load(":/midi/Base");
    // Loop through dataset
    auto iter = m_dataSet->iterator();
    int note = m_dataSet->getStart()->getNote();
    for (int i = 0; iter.hasNext(); iter++, i++) {
        int step = iter.symbol()->getStep();
        // Check if it's a standard symbol (i.e. not a modifier)
        if (step > -1) {
            note += (iter.symbol()->isUp()) ? step : -step;
            int mod = note >= 0 ? note % 7 : (7 - abs(note % 7)) % 7;
            IsonNotation::Parallagi current = static_cast<IsonNotation::Parallagi>(mod);
            int octave = (note > -1 ? note : note - 7) / 7 * 12;
            // 60 = Middle C
            int final = 60 + octave + IsonNotation::scaleSteps[current];
            f.createNoteOnEvent(0, i * 490, 0, final, 60);
            f.createNoteOffEvent(0, (i + 1) * 490, 0, final, 60);
        }
    }
    // Save to filename
    f.save(fileName);
    ui->statusBar->showMessage("Exported to MIDI", 5000);
}

void MainWindow::exportODF() {
    // Get file name
    const QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Open Document Format (*.odt)"));
    if (fileName.isEmpty()) return;
    // Get output as text document and write it
    QTextDocumentWriter writer(fileName);
    QTextDocument *doc = ui->textBrowser->document();
    writer.write(doc);
    ui->statusBar->showMessage("Exported to ODF", 5000);
}

void MainWindow::exportPDF() {
    // Get file name
    const QString fileName = QFileDialog::getSaveFileName(this, tr("Save File"), "", tr("Adobe Portable Document Format (*.pdf)"));
    if (fileName.isEmpty()) return;
    // Set up printer for writing pdf file
    QPrinter printer(QPrinter::HighResolution);
    printer.setPageSize(QPrinter::A4);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    // Get document from textBrowser
    QTextDocument *doc = ui->textBrowser->document();
    doc->print(&printer);
    ui->statusBar->showMessage("Exported to PDF", 5000);
}

std::shared_ptr<IsonNotation::DataSet> MainWindow::parse(const QString& input) const {
    return m_parser.parse(input.toStdString());
}
