#include <iostream>
#include <vector>
#include "ssd.hpp"
#include <string>

template <typename T>
void SSD<T>::init() {
	ssd.resize(100, T{ 0 });

	std::fstream writeFile;
	writeFile.open("nand.txt", std::ios::out | std::ios::app);
	if (writeFile.is_open())
	{
		for (const auto& str : ssd) {
			writeFile << str << std::endl;
		}
	}
	writeFile.close();
}

template <typename T>
void SSD<T>::write(uint32_t index, T data) {

	if (index >= 0 && index < 100) ssd[index] = data;

	std::fstream readFile;
	readFile.open("nand.txt", std::ios::in | std::ios::out | std::ios::app);
	if (readFile.is_open())
	{
		std::vector<std::string> tmp;
		std::string line;
		while (std::getline(readFile, line)) {
			tmp.push_back(line);
		}

		if (index < tmp.size()) tmp[index] = data.toString();
		readFile.close();
		readFile.open("nand.txt", std::ios::out | std::ios::trunc);

		for (const auto& str : tmp) {
			readFile << str << std::endl;
		}
	}
	else {
		std::cout << "can't open the file \n";
	}
}

template <typename T>
void SSD<T>::read(uint32_t index) {

}

//int main(void) {
//	SSD<LogicalBlock<uint32_t>> ssd;
//	ssd.write(3, LogicalBlock<uint32_t>(8));
//}