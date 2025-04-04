// compiler.h
#ifndef COMPILER_H
#define COMPILER_H

#include "parser.h"
#include <string>
#include <vector>

// Intermediate Representation (IR) Node Structure
struct IRNode {
    std::string opcode;   // Operation code, e.g., LOAD, ADD, PRINT
    std::string operand;  // Operand associated with the operation
};

// Compiler class that transforms AST into IR
class Compiler {
private:
    std::vector<ASTNode> ast;  // Input Abstract Syntax Tree
    std::vector<IRNode> ir;    // Generated Intermediate Representation

public:
    Compiler(const std::vector<ASTNode>& ast_tree); // Constructor

    // Main function to generate intermediate representation
    std::vector<IRNode> generateIR();
};

#endif // COMPILER_H
