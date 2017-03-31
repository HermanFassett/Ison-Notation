#ifndef GORGON_HPP
#define GORGON_HPP
#include "../IModifier.hpp"

namespace IsonNotation {
    class Gorgon : public IModifier {
    public:
        Gorgon() : IModifier("Gorgon", "s", ".") {}
    };
}

#endif // GORGON_HPP
