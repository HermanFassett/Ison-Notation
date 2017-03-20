#ifndef ISON_SYMBOL_HPP
#define ISON_SYMBOL_HPP
#include "../ISymbol.hpp"

namespace IsonNotation {
    class Ison : public ISymbol {
    public:
        Ison() : ISymbol("Ison", 0) {}
    };
}

#endif // ISON_SYMBOL_HPP
