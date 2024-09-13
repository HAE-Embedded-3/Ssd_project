#include "testShellApplication.h"

template<typename T>
void TestShellApplication<T>::write() {}

template<typename T>
void TestShellApplication<T>::read() {}

template<typename T>
void TestShellApplication<T>::exit() {}

template<typename T>
void TestShellApplication<T>::help() {}

template<typename T>
void TestShellApplication<T>::fullwrite() {}

template<typename T>
void TestShellApplication<T>::fullread() {}

template<typename T>
TestShellApplication<T>::TestShellApplication(Storage<T>& storage) : _storage(storage) {}