// parser.h
#ifndef PARSER_H
#define PARSER_H

#include "lexer.h"
#include <string>
#include <vector>

// Abstract Syntax Tree (AST) Node Structure
struct ASTNode {
    std::string node_type;
    std::string value;
};

class Parser {
private:
    std::vector<Token> tokens;
    std::vector<ASTNode> ast;

public:
    Parser(const std::vector<Token>& token_list);
    std::vector<ASTNode> parse();
};

#endif // PARSER_H
