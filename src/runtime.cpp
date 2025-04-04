// runtime.cpp
#include "runtime.h"
#include "compiler.h"
#include <iostream>

// Constructor for Runtime: stores the IR code
Runtime::Runtime(const std::vector<IRNode>& ir_code) : ir(ir_code) {}

// Execute function to interpret and run the IR code
void Runtime::execute() {
    for (const auto& instr : ir) {
        if (instr.opcode == "KW") {
            std::cout << "[Keyword] " << instr.operand << std::endl;
        } else if (instr.opcode == "ID") {
            std::cout << "[Identifier] " << instr.operand << std::endl;
        } else if (instr.opcode == "OP") {
            std::cout << "[Operator] " << instr.operand << std::endl;
        } else if (instr.opcode == "DEL") {
            std::cout << "[Delimiter] " << instr.operand << std::endl;
        } else if (instr.opcode == "UNK") {
            std::cout << "[Unknown] " << instr.operand << std::endl;
        } else {
            std::cout << "[Unrecognized IR] " << instr.opcode << ": " << instr.operand << std::endl;
        }
    }
}