// parser.cpp
#include "parser.h"

Parser::Parser(const std::vector<Token>& token_list) : tokens(token_list) {}

std::vector<ASTNode> Parser::parse() {
    for (const auto& token : tokens) {
        ASTNode node;
        if (token.type == "KEYWORD") {
            node.node_type = "KEYWORD";
            node.value = token.value;
        } else if (token.type == "IDENTIFIER") {
            node.node_type = "IDENTIFIER";
            node.value = token.value;
        } else if (token.type == "OPERATOR") {
            node.node_type = "OPERATOR";
            node.value = token.value;
        } else if (token.type == "DELIMITER") {
            node.node_type = "DELIMITER";
            node.value = token.value;
        } else {
            node.node_type = "UNKNOWN";
            node.value = token.value;
        }
        ast.push_back(node);
    }
    return ast;
}
