#include "ssd.h"

//템플릿을 썼더니 오류가 난다??? 원인 파악 필요 -> 헤더파일 템플릿과 겹쳐서 문제 발생???
//template <typename T>
// 
// 파일 사용 코드
//std::fstream SSD_file("nand.txt", std::ios::in | std::ios::out | std::ios::app);
//std::fstream result_file("result.txt", std::ios::in | std::ios::out | std::ios::app);


//void SSD<uint32_t>::write(uint32_t index, uint32_t input_data) {
//	
//}

void SSD<uint32_t>::write(uint32_t index, uint32_t input_data) {
	std::fstream SSD_file("nand.txt", std::ios::in | std::ios::out);
	std::string read_data;
	if (SSD_file.is_open()) {
		while (std::getline(SSD_file, read_data)) {
			ssd_memory.push_back(read_data);
		}
	}
	ssd_memory[index] = std::to_string(input_data);
	
	for (auto revised_data : ssd_memory) {
		SSD_file << "0x" << std::setfill('0') << std::setw(8) << std::hex << revised_data << std::endl;
	}
	SSD_file.close();
}


//template <typename T> 
void SSD<uint32_t>::read(uint32_t index) {
	//파일 열기 result.txt 쓰기 전용 nand.txt읽기전용
	std::ofstream result_file("result.txt");
	std::ifstream SSD_file("nand.txt");

	//데이터 읽기
	std::string read_data;
	std::string data_required;
	//벡터에 저장
	if (SSD_file.is_open()) {
		while (std::getline(SSD_file, read_data)) {
			ssd_memory.push_back(read_data);
		}
	}
	else {
		std::cerr << "Failed to open the file." << std::endl;
	}
	//벡터에서 필요한 데이터 추출
	//std::cout << "vect size is " << ssd_memory.size() << std::endl;
	if (index < 100) {
		data_required = ssd_memory[index];
		//result.txt에 해당 데이터 저장22
		if (result_file.is_open()) {
			result_file << "0x" << std::setfill('0') << std::setw(8) << std::hex << data_required << std::endl;
			std::cout << "Result: " << "0x" << std::setfill('0') << std::setw(8) << std::hex << data_required << std::endl;
		}
		else {
			std::cerr << "Failed to open the file." << std::endl;
		}
	}
	else {
		std::cerr << "Index over 100" << std::endl;
	}
	
	result_file.close();
	SSD_file.close();
	//std::cout << "READ" << std::endl;
	
}

//read/write 명령어 받는 함수는 앱의 영역?