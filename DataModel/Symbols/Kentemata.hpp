#ifndef KENTEMATA_SYMBOL_HPP
#define KENTEMATA_SYMBOL_HPP
#include "../ISymbol.hpp"

namespace IsonNotation {
    class Kentemata : public ISymbol {
    public:
        Kentemata() : ISymbol("Kentemata", 1, true, "`", "*1") {}
    };
}

#endif // KENTEMATA_SYMBOL_HPP
