#include "DataModel/DataSet.hpp"

using namespace IsonNotation;

DataSet::DataSet() {

}

void DataSet::addSymbol(const Symbol &symbol, unsigned int index) {
    if (index == -1) {
        m_symbols.push_back(symbol);
    } else {
        m_symbols.insert(symbol, index);
    }
}

Symbol& DataSet::getSymbol(unsigned int index) {
    return m_symbols[index];
}

const Symbol& DataSet::getSymbol(unsigned int index) const {
    return m_symbols[index];
}

Symbol& DataSet::operator [] (unsigned int index) {
    return getSymbol(index);
}

const Symbol& DataSet::operator [] (unsigned int index) const {
    return getSymbol(index);
}

DataSet::Iterator DataSet::iterator() const {
    return Iterator(this);
}

// For Iterator

DataSet::Iterator::Iterator(const DataSet *dataSet) : m_dataSet(dataSet), m_index(0) {

}

bool DataSet::Iterator::hasNext() const {
    return m_index < m_dataSet->m_symbols.size();
}

DataSet::Iterator& DataSet::Iterator::operator ++ (int) {
    m_index++;
    return *this;
}

const Symbol& DataSet::Iterator::symbol() {
    return m_dataSet->m_symbols[m_index];
}
