#ifndef YPSELE_SYMBOL_HPP
#define YPSELE_SYMBOL_HPP
#include "../ISymbol.hpp"

namespace IsonNotation {
    class Ypsele : public ISymbol {
    public:
        Ypsele() : ISymbol("Ypsele", 4, true, "4", "4") {}
    };
}

#endif // YPSELE_SYMBOL_HPP
