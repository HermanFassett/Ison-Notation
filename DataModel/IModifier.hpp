#ifndef I_MODIFIER_HPP
#define I_MODIFIER_HPP
#include "ISymbol.hpp"

namespace IsonNotation {
    class IModifier : public ISymbol {
    public:
        IModifier(const std::string n, const std::string f = "0", const std::string c = "0") : ISymbol(n, -1, true, f, c) {}
    };
}

#endif // I_MODIFIER_HPP
