#pragma once
#include "ssd.h"
#include "testScript.h"

<<<<<<< Updated upstream
=======
#include <vector>
#include <string>
#include <sstream>

>>>>>>> Stashed changes
template <typename T>
class TestShellApplication {
private:
    Storage<T> &_storage;
    Storage<T> &_storage_test;

    std::vector<TestScript &> _testScripts{};

	void write();
	void read();
	void exit();
	void help();
	void fullwrite();
	void fullread();
public:
	void start();
    void registerTestScript(TestScript& testScript);
    void executeTestScript(uint32_t index);
	TestShellApplication(Storage<T>& storage);
	TestShellApplication(const TestShellApplication& copy) = delete;
	TestShellApplication operator=(const TestShellApplication& src) = delete;
};