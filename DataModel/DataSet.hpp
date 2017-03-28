#ifndef DATA_SET_HPP
#define DATA_SET_HPP
#include "ISymbol.hpp"
#include "Modifiers/Martyria.hpp"
#include <vector>
#include <memory>

namespace IsonNotation {
    class DataSet {
    public:
        class Iterator {
        public:
            Iterator& operator++ (int);
            bool hasNext() const;
            std::shared_ptr<ISymbol> symbol();
            unsigned int tone() const;
            unsigned int modifiers() const;

        protected:
            friend class DataSet;
            Iterator(const DataSet* dataSet);
            const DataSet* m_dataSet;
            unsigned int m_tone;
            unsigned int m_index;
        };

        Iterator iterator() const;
        std::shared_ptr<ISymbol> getSymbol(unsigned int index);
        std::shared_ptr<ISymbol> operator [] (unsigned int index);

        DataSet(std::shared_ptr<Martyria> m = std::make_shared<Martyria>(Martyria(NI, DIATONIC)));

        void addSymbol(std::shared_ptr<ISymbol> symbol, unsigned int index = -1);
        void setStart(std::shared_ptr<Martyria> m);
        std::shared_ptr<Martyria> getStart();

    private:
        std::vector<std::shared_ptr<ISymbol>> m_symbols;
        std::shared_ptr<Martyria> m_startNote;
    };
}

#endif // DATA_SET_HPP
