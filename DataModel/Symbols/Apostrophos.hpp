#ifndef APOSTROPHOS_SYMBOL_HPP
#define APOSTROPHOS_SYMBOL_HPP
#include "../ISymbol.hpp"

namespace IsonNotation {
    class Apostrophos : public ISymbol {
    public:
        Apostrophos() : ISymbol("Apostrophos", 1, false, "!", "1") {}
    };
}

#endif // APOSTROPHOS_SYMBOL_HPP
