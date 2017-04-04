#ifndef SYMBOL_FACTORY_HPP
#define SYMBOL_FACTORY_HPP
#include <memory>
#include <cctype>
#include <algorithm>
#include "ISymbol.hpp"
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

namespace IsonNotation {

    class SymbolFactory {
    public:
        SymbolFactory() {}
        std::shared_ptr<ISymbol> create(std::string name) const;
    };

}

#endif // SYMBOL_FACTORY_HPP
