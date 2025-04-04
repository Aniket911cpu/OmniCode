// lexer.h
#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include <unordered_set>

struct Token {
    std::string value;
    std::string type;
};

class Lexer {
private:
    std::string source_code;
    std::vector<Token> tokens;
    std::unordered_set<std::string> keywords = {
        "def", "class", "if", "else", "return", "while", "for", "break", "continue", "import", "from"
    };
    std::unordered_set<char> operators = {
        '+', '-', '*', '/', '=', '>', '<', '!', '&', '|'
    };
    std::unordered_set<char> delimiters = {
        '(', ')', '{', '}', '[', ']', ',', ':', ';'
    };

    void processWord(const std::string& word);

public:
    Lexer(const std::string& code);
    std::vector<Token> tokenize();
};

#endif // LEXER_H
