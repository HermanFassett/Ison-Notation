#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFontDatabase>
#include <QCloseEvent>
#include "DataModel/ISymbol.hpp"
#include "DataModel/DataSet.hpp"
#include "DataModel/Parser.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    std::shared_ptr<IsonNotation::DataSet> parse(const QString& input) const;

private:
    // For overriding close event
    void closeEvent(QCloseEvent*);
    const QString openFile(const QString& file) const;
    void saveFile(const QString& file);
    void resetTitle();
    void display();
    bool saved = true;

    Ui::MainWindow *ui;
    std::shared_ptr<IsonNotation::DataSet> m_dataSet;
    IsonNotation::Parser m_parser;
    QFontDatabase m_fonts;

    QString m_fileName;

private slots:
    void newFile();
    void open();
    void save();
    void saveAs();
    void changed();
    void undoEdit();
    void redoEdit();
    void exportODF();
    void exportPDF();
};

#endif // MAINWINDOW_H
