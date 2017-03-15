#ifndef DATA_SET_HPP
#define DATA_SET_HPP
#include "ISymbol.hpp"
#include <vector>

namespace IsonNotation {
    class DataSet {
    public:
        class Iterator {
        public:
            Iterator& operator++ (int);
            bool hasNext() const;
            const Symbol& symbol();
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
        Symbol& getSymbol(unsigned int index);
        const Symbol& getSymbol(unsigned int index) const;
        Symbol& operator [] (unsigned int index);
        const Symbol& operator [] (unsigned int index) const;

        DataSet();

        void addSymbol(const Symbol& symbol, unsigned int index = -1);

    private:
        std::vector<Symbol> m_symbols;
    };
}

#endif // DATA_SET_HPP
