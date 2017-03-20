#ifndef KAMELE_SYMBOL_HPP
#define KAMELE_SYMBOL_HPP
#include "../ISymbol.hpp"

namespace IsonNotation {
    class Kamele : public ISymbol {
    public:
        Kamele() : ISymbol("Kamele", 4, false, "$", "4") {}
    };
}

#endif // KAMELE_SYMBOL_HPP
