#include "testShellApplication.h"
#include <sstream>

template <typename T> void TestShellApplication<T>::write() {
}

template <typename T> void TestShellApplication<T>::read() {
}

template <typename T> void TestShellApplication<T>::exit() {
}

template <typename T> void TestShellApplication<T>::help() {
}

template <typename T> void TestShellApplication<T>::fullwrite() {
}

template <typename T> void TestShellApplication<T>::fullread() {
}

template <typename T> void TestShellApplication<T>::start() {
    while (1) {
        std::string test;

        getline(std::cin, test);

        if (test == "end") {
            break;
        }

        std::vector<std::string> input = split(test, ' ');

    }
}

template <typename T>
TestShellApplication<T>::TestShellApplication(Storage<T> &storage) : _storage(storage) {
}

std::vector<std::string> split(std::string str, char Delimiter) {
    std::istringstream iss(str);
    std::string buffer;

    std::vector<std::string> result;

    while (getline(iss, buffer, Delimiter)) {
        result.push_back(buffer);
    }

    return result;
}