// lexer.cpp
#include "lexer.h"
#include <cctype>

Lexer::Lexer(const std::string& code) : source_code(code) {}

void Lexer::processWord(const std::string& word) {
    if (keywords.count(word)) {
        tokens.push_back({word, "KEYWORD"});
    } else {
        tokens.push_back({word, "IDENTIFIER"});
    }
}

std::vector<Token> Lexer::tokenize() {
    std::string word = "";
    for (size_t i = 0; i < source_code.size(); ++i) {
        char c = source_code[i];

        if (std::isspace(c)) {
            if (!word.empty()) {
                processWord(word);
                word.clear();
            }
        } else if (operators.count(c)) {
            if (!word.empty()) {
                processWord(word);
                word.clear();
            }
            tokens.push_back({std::string(1, c), "OPERATOR"});
        } else if (delimiters.count(c)) {
            if (!word.empty()) {
                processWord(word);
                word.clear();
            }
            tokens.push_back({std::string(1, c), "DELIMITER"});
        } else {
            word += c;
        }
    }
    if (!word.empty()) {
        processWord(word);
    }
    return tokens;
}
