#include "DataModel/Parser.hpp"
#include "Symbols/Ison.hpp"
#include "Symbols/Oligon.hpp"
#include "Symbols/Kentemata.hpp"
#include "Symbols/Petaste.hpp"
#include "Symbols/Kamele.hpp"
#include "Symbols/Ypporoe.hpp"
#include "Symbols/Apostrophos.hpp"
#include "Symbols/Elaphron.hpp"
#include "Symbols/Bar.hpp"
#include "Symbols/SymbolGroup.hpp"
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
        { "0", std::make_shared<Ison>(Ison()) },
        { "-0", std::make_shared<Ison>(Ison()) },
        { "1", std::make_shared<Oligon>(Oligon()) },
        { "-1", std::make_shared<Apostrophos>(Apostrophos()) },
        { "#1", std::make_shared<Petaste>(Petaste()) },
        { "-#1", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::ApostrophosPetaste)) },
        { "&1", std::make_shared<Kentemata>(Kentemata()) },
        { "-&1", std::make_shared<Ypporoe>(Ypporoe()) },
        { "2", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::OligonKentema)) },
        { "-2", std::make_shared<Elaphron>(Elaphron()) },
        { "#2", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::OligonPetaste)) },
        { "-#2", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::ElaphronPetaste)) },
        { "3", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KentemaOligon)) },
        { "-3", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::ElaphronApostrophos)) },
        { "#3", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KentemaPetaste)) },
        { "4", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::OligonYpsele)) },
        { "-4", std::make_shared<Kamele>(Kamele()) },
        { "#4", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::PetasteYpsele)) },
        { "-#4", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::ElpahronApsotrophosPetaste)) },
        { "5", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::YpseleOligon)) },
        { "-5", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KameleApostrophos)) },
        { "#5", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::YpselePetaste)) },
        { "6", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KentemaOligonYpsele)) },
        { "-6", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KameleElaphron)) },
        { "#6", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KentemaPetasteYpsele)) },
        { "7", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::YpseleKentemaOligon)) },
        { "-7", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::KameleElaphronApostrophos)) },
        { "#7", std::make_shared<SymbolGroup>(SymbolGroup(SymbolGroups::YpseleKentemaPetaste)) }
    };

    // Set up variables
    bool up = true, modgroup = false, martyria = false;
    std::string key = "";
    char mod = ' ';
    std::shared_ptr<DataSet> ret = std::make_shared<DataSet>(DataSet());
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
    }
    return ret;
}
