#ifndef DIGORGON_HPP
#define DIGORGON_HPP
#include "../IModifier.hpp"

namespace IsonNotation {
    class Digorgon : public IModifier {
    public:
        Digorgon() : IModifier("Digorgon", "d", "..") {}
    };
}

#endif // DIGORGON_HPP
