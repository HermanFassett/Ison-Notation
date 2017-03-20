#ifndef OLIGON_SYMBOL_HPP
#define OLIGON_SYMBOL_HPP
#include "../ISymbol.hpp"

namespace IsonNotation {
    class Oligon : public ISymbol {
    public:
        Oligon() : ISymbol("Oligon", 1, true, "1", "1") {}
    };
}

#endif // OLIGON_SYMBOL_HPP
