#ifndef TRIGORGON_HPP
#define TRIGORGON_HPP
#include "../IModifier.hpp"

namespace IsonNotation {
    class Trigorgon : public IModifier {
    public:
        Trigorgon() : IModifier("Trigorgon", "f", "...") {}
    };
}

#endif // TRIGORGON_HPP
