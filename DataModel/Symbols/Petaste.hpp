#ifndef PETASTE_SYMBOL_HPP
#define PETASTE_SYMBOL_HPP
#include "../ISymbol.hpp"

namespace IsonNotation {
    class Petaste : public ISymbol {
    public:
        Petaste() : ISymbol("Petaste", 1, true, "q", "#1") {}
    };
}

#endif // PETASTE_SYMBOL_HPP
