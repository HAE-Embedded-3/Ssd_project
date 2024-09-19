#ifndef __TEST_SCRIPT_H__
#define __TEST_SCRIPT_H__
#include <vector>
#include <string>

class TestScript {
  private:
    // ex) {"write 0 0xAAAABBBB", "read 0"}
    std::vector<std::string&> _commands{};

  public:
 //   TestScript(const std::vector<std::string> &commands) : _commands(commands){};
    TestScript() {};

    void addCommand(const std::string &command);

    std::vector<std::string&>& getCommands() {
        return _commands;
    }
};

#endif