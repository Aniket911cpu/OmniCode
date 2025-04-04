// runtime.h
#ifndef RUNTIME_H
#define RUNTIME_H

#include "compiler.h"
#include <vector>
#include <string>

class Runtime {
private:
    std::vector<IRNode> ir;

public:
    Runtime(const std::vector<IRNode>& ir_code);
    void execute();
};

#endif // RUNTIME_H
