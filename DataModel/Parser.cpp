#include "DataModel/Parser.hpp"
#include "Symbols/Ison.hpp"
#include "Symbols/Oligon.hpp"
#include "Symbols/Kentemata.hpp"
#include "Symbols/Petaste.hpp"
#include "Symbols/Ypporoe.hpp"
#include "Symbols/Apostrophos.hpp"
#include "Symbols/Elaphron.hpp"
#include "Symbols/Bar.hpp"
#include "Modifiers/Martyria.hpp"
#include "Modifiers/Klasma.hpp"
#include "Modifiers/Fthora.hpp"
#include "Modifiers/Gorgon.hpp"
#include <set>
#include <map>

using namespace IsonNotation;

Parser::Parser() {

}

std::shared_ptr<DataSet> Parser::parse(const std::string& input) const {
    // Create map for parsing
    // THESE ARE ALL SAME POINTER
    // Probably should be refactored later
    const std::map<std::string, std::shared_ptr<ISymbol>> map = {
        { std::make_pair("0", std::make_shared<Ison>()) },
        { std::make_pair("-0", std::make_shared<Ison>()) },
        { std::make_pair("1", std::make_shared<Oligon>()) },
        { std::make_pair("-1", std::make_shared<Apostrophos>()) },
        { std::make_pair("#1", std::make_shared<Petaste>()) },
        { std::make_pair("&1", std::make_shared<Kentemata>()) },
        { std::make_pair("-&1", std::make_shared<Ypporoe>()) },
        { std::make_pair("-2", std::make_shared<Elaphron>()) }
    };

    // Set up variables
    bool up = true, modgroup = false;
    std::string key = "";
    char mod = ' ';
    std::shared_ptr<DataSet> ret = std::make_shared<DataSet>();
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
            if (map.find(key) != map.end()) {
                ret->addSymbol(map.at(key));
            }
            key = "";
            break;
        // Other symbols
        case '|':
            ret->addSymbol(std::make_shared<Bar>());
            break;
        case '`':
            ret->addSymbol(std::make_shared<Klasma>());
            break;
        // Martyria
        case 'm':
            if (input[i+1] && input[i+1] == '1') ret->addSymbol(std::make_shared<Martyria>(Martyria(PA, CHROMATIC, PA)));
            else ret->addSymbol(std::make_shared<Martyria>(Martyria(NI, DIATONIC)));
            break;
        default:
            break;
        }
    }
    return ret;
}
