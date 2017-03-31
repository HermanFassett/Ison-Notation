#include "DataModel/Parser.hpp"

using namespace IsonNotation;

Parser::Parser() {

}

std::shared_ptr<DataSet> Parser::parse(const std::string& input) const {
    // Set up variables
    bool up = true, modgroup = false, martyria = false;
    int dot = 0;
    std::string key = "";
    char mod = ' ';
    std::shared_ptr<DataSet> ret = std::make_shared<DataSet>(DataSet());
    std::shared_ptr<ISymbol> symbol;
    // Traverse input for parsing
    for (unsigned int i = 0; i < input.length(); i++) {
        switch(input[i]) {
        // For direction of notes
        case '+':
            up = true;
            break;
        case '-':
            up = false;
            break;
        // For modifiers (as in different ways of showing steps)
        case '#':
        case '&':
            mod = input[i];
            break;
        // For mod groups
        case '{':
            modgroup = true;
            break;
        case '}':
            modgroup = false;
            mod = ' ';
            break;
        // Actual symbols
        case '0':
        case '1':
        case '2':
        case '3':
        case '4':
        case '5':
        case '6':
        case '7':
            if (!up) key += "-";
            if (mod != ' ') {
                 key += mod;
                if (!modgroup) mod = ' ';
            }
            key += input[i];
            symbol = m_factory.create(key);
            if (symbol != nullptr) ret->addSymbol(symbol);
            key = "";
            break;
        // Other symbols
        case '|':
            ret->addSymbol(m_factory.create("bar"));
            break;
        // Duration symbols
        case '.':
            dot++;
            break;
        case '`':
            ret->getSymbol(ret->size() - 1)->setDuration(2.0f);
            ret->addSymbol(m_factory.create("klasma"));
            break;
        // Martyria
        case 'm':
            martyria = true;
            break;
        default:
            break;
        }
        // Case for last char a martyria code
        if (martyria) {
            // If first part of code, assign as first note in dataset
            if (i == 0) {
                ret->setStart(std::make_shared<Martyria>(Martyria(NI, ENHARMONIC)));
            }
            // Get the first note in dataset and extrapolate the current note
            int note = ret->getStart()->getNote();
            Scale scale = ret->getStart()->getScale();
            auto iter = ret->iterator();
            for (; iter.hasNext(); iter++) {
                int step = iter.symbol()->getStep();
                // Check if it's a standard symbol (i.e. not a modifier)
                if (step > -1) {
                    note += (iter.symbol()->isUp()) ? step : -step;
                }
            }
            int mod = note >= 0 ? note % 7 : (7 - abs(note % 7)) % 7;
            Parallagi current = static_cast<Parallagi>(mod);
            // Add martyria based on current note in dataset
            ret->addSymbol(std::make_shared<Martyria>(Martyria(current, scale)));
            // Reset martyria flag
            martyria = false;
        }
        if (dot > 0) {
            for (; i < input.length() - 1 && input[i + 1] == '.'; i++, dot++);
            unsigned int size = ret->size();
            if (dot == 1) {
                ret->getSymbol(size - 2)->setDuration(ret->getSymbol(size - 2)->getDuration() - 0.5f);
                ret->getSymbol(size - 1)->setDuration(ret->getSymbol(size - 1)->getDuration() - 0.5f);
                ret->addSymbol(m_factory.create("gorgon"));
            }
            // These require lookahead duration changes...
            else if (dot == 2) {
                // Change durations here
                ret->addSymbol(m_factory.create("digorgon"));
            }
            else if (dot == 3) {
                // Change durations here
                ret->addSymbol(m_factory.create("trigorgon"));
            }
            dot = 0;
        }
    }
    return ret;
}
