#ifndef PARSER_HPP
#define PARSER_HPP
#include "SymbolFactory.hpp"
#include "DataSet.hpp"
#include <string>
#include <memory>
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
#include "Modifiers/Digorgon.hpp"
#include "Modifiers/Trigorgon.hpp"
#include <set>
#include <map>

namespace IsonNotation {
    class Parser {
    public:
        Parser();
        std::shared_ptr<IsonNotation::DataSet> parse(const std::string& input) const;
    private:
        SymbolFactory m_factory;
    };
}

#endif // PARSER_HPP
