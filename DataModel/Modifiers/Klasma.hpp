#ifndef KLASMA_HPP
#define KLASMA_HPP
#include "../IModifier.hpp"

namespace IsonNotation {
    class Klasma : public IModifier {
    public:
        Klasma() : IModifier("Klasma", "a", "`") {}
    };
}

#endif // KLASMA_HPP
