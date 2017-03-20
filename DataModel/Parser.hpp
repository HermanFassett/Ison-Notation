#ifndef PARSER_HPP
#define PARSER_HPP
#include "DataSet.hpp"
#include <string>
#include <memory>

namespace IsonNotation {
    class Parser {
    public:
        Parser();
        std::shared_ptr<IsonNotation::DataSet> parse(const std::string& input) const;
    };
}

#endif // PARSER_HPP
