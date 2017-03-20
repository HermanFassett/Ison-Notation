#include "DataModel/Parser.hpp"
#include "Symbols/Ison.hpp"
#include "Symbols/Oligon.hpp"
#include "Symbols/Apostrophos.hpp"
#include "Symbols/Elaphron.hpp"

using namespace IsonNotation;

Parser::Parser() {

}

std::shared_ptr<DataSet> Parser::parse(const std::string& input) const {
    bool up = true;
    char mod = ' ';
    std::shared_ptr<DataSet> ret = std::make_shared<DataSet>();
    for (unsigned int i = 0; i < input.length(); i++) {
        switch(input[i]) {
        case '+':
            up = true;
            break;
        case '-':
            up = false;
            break;
        case '0':
            ret->addSymbol(std::make_shared<Ison>());
            break;
        case '1':
            if (up) ret->addSymbol(std::make_shared<Oligon>());
            else if (!up) ret->addSymbol(std::make_shared<Apostrophos>());
            break;
        case '2':
            if (!up) ret->addSymbol(std::make_shared<Elaphron>());
            break;
        default:
            mod = input[i];
            break;
        }
    }
    return ret;
}
