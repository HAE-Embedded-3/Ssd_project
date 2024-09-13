#pragma once
#include "ssd.h"

#include <vector>
#include <string>

template <typename T>
class TestShellApplication {
private:
	Storage<T>& _storage;

	void write();
	void read();
	void exit();
	void help();
	void fullwrite();
	void fullread();
public:
	void start();
	TestShellApplication(Storage<T>& storage);
	TestShellApplication(const TestShellApplication& copy) = delete;
	TestShellApplication operator=(const TestShellApplication& src) = delete;
};

std::vector<std::string> split(std::string str, char Delimiter);