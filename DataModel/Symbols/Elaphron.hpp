#ifndef ELAPHRON_SYMBOL_HPP
#define ELAPHRON_SYMBOL_HPP
#include "../ISymbol.hpp"

namespace IsonNotation {
    class Elaphron : public ISymbol {
    public:
        Elaphron() : ISymbol("Elaphron", 2, false, "@", "2") {}
    };
}

#endif // ELAPHRON_SYMBOL_HPP
