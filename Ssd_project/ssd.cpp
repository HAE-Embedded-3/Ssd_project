#include "ssd.h"

//템플릿을 썼더니 오류가 난다??? 원인 파악 필요 -> 헤더파일 템플릿과 겹쳐서 문제 발생???
//template <typename T>
// 
// 파일 사용 코드
//std::fstream SSD_file("nand.txt", std::ios::in | std::ios::out | std::ios::app);
//std::fstream result_file("result.txt", std::ios::in | std::ios::out | std::ios::app);


void SSD<uint32_t>::write(uint32_t index, uint32_t input_data) {
	std::fstream SSD_file("nand.txt", std::ios::in | std::ios::out | std::ios::app);
	if (SSD_file.is_open()) {
		SSD_file << input_data << std::endl;
	}
	else {
		std::cerr << "Failed to open the file." << std::endl;
	}
	SSD_file.close();
	std::cout << "WRITE" << std::endl;
}

//template <typename T> 
void SSD<uint32_t>::read(uint32_t index) {
	std::ofstream result_file("result.txt");
	std::ifstream SSD_file("nand.txt");
	std::string data_required;
	if (SSD_file.is_open()) {
		std::getline(SSD_file, data_required);
		std::cout << data_required << std::endl;
	}
	else {
		std::cerr << "Failed to open the file." << std::endl;
	}
	if (result_file.is_open()) {
		result_file << data_required << std::endl;
		std::cout << "Result: " << data_required << std::endl;
	}
	else {
		std::cerr << "Failed to open the file." << std::endl;
	}

	std::cout << "READ" << std::endl;
}