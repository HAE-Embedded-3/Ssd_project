#include "ssd.h"

//���ø��� ����� ������ ����??? ���� �ľ� �ʿ� -> ������� ���ø��� ���ļ� ���� �߻�???
//template <typename T>
// 
// ���� ��� �ڵ�
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
	//���� ���� result.txt ���� ���� nand.txt�б�����
	std::ofstream result_file("result.txt");
	std::ifstream SSD_file("nand.txt");

	//������ �б�
	std::string read_data;
	std::string data_required;
	//���Ϳ� ����
	if (SSD_file.is_open()) {
		while (std::getline(SSD_file, read_data)) {
			ssd_memory.push_back(read_data);
		}
	}
	else {
		std::cerr << "Failed to open the file." << std::endl;
	}
	//���Ϳ��� �ʿ��� ������ ����
	//std::cout << "vect size is " << ssd_memory.size() << std::endl;
	if (index < 100) {
		data_required = ssd_memory[index];
		//result.txt�� �ش� ������ ����22
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

//read/write ��ɾ� �޴� �Լ��� ���� ����?