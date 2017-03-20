#ifndef YPPOROE_SYMBOL_HPP
#define YPPOROE_SYMBOL_HPP
#include "../ISymbol.hpp"

namespace IsonNotation {
    class Ypporoe : public ISymbol {
    public:
        Ypporoe() : ISymbol("Ypporoe", 2, false, ")", "/1") {}
    };
}

#endif // YPPOROE_SYMBOL_HPP
