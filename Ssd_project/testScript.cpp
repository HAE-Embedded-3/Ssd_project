#include "testScript.h"

void TestScript::addCommand(const std::string &command) {
    _commands.push_back(command);
}

std::vector<std::string>& TestScript::getCommands() {
    return _commands;
}