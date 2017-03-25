#ifndef BAR_HPP
#define BAR_HPP
#include "../ISymbol.hpp"

namespace IsonNotation {
    class Bar : public ISymbol {
    public:
        Bar() : ISymbol("Bar", -1, true, "J", "|") {}
    };
}

#endif // BAR_HPP
