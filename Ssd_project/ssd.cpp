#include "ssd.h"

//���ø��� ����� ������ ����??? ���� �ľ� �ʿ� -> ������� ���ø��� ���ļ� ���� �߻�???
//template <typename T>
// 
// ���� ��� �ڵ�
//std::fstream SSD_file("nand.txt", std::ios::in | std::ios::out | std::ios::app);
//std::fstream result_file("result.txt", std::ios::in | std::ios::out | std::ios::app);

void SSD<uint32_t>::write(uint32_t index, uint32_t input_data) {
	//����ó�� ���: index�� 0~100 ���� �ƴ� ���, input data�� ������ �� ����ġ, txt ������ ������ �� �Ǵ� ���
	////�Է°� ������ ��� ���ø����̼ǿ��� ó���ؾ����� ������???
	//if (index < 0 || index>100) {
	//	std::cerr << "Wrong Index" << std::endl;
	//}
	//���� ���� - �б�/���� ���
	//std::fstream SSD_file("nand.txt",std::ios::in|std::ios::out);
	std::ifstream SSD_read_file("nand.txt");
	//������ �б�� string
	std::string read_data;
	//���� txt���� ������ �б� (FULL READ) - ssd_memory�� ����
	if (SSD_read_file.is_open()) {
		//���� ������ ���� ����ϱ� ���� �ʱ�ȭ
		// �Լ� �ҷ��� ������ �ʱ�ȭ�� �ȴ�?
		ssd_memory.clear();
		//���� ������ ����
		while (std::getline(SSD_read_file, read_data)) {
			ssd_memory.push_back(read_data);
			//std::cout << read_data << std::endl;
		}
		std::cout << "READ DATA FIN" << std::endl;
	}
	//���� ���� ����
	else {
		std::cerr << "Failed to open the file." << std::endl;
	}
	SSD_read_file.close();

	std::ofstream SSD_file("nand.txt");
	//������ ����(ssd_memory)
	ssd_memory[index] = std::to_string(input_data);
	//������ ������ txt���� �����

	//0x ���̴°� ������... ���� �ʿ�
	for (auto revised_data : ssd_memory) {
		SSD_file << std::setfill('0') << std::setw(8) << std::hex << revised_data << std::endl;
		std::cout << revised_data << std::endl;
	}
	//���� �ݱ�
	SSD_file.close();
}


//template <typename T> 
void SSD<uint32_t>::read(uint32_t index) {
	//���� ���� result.txt ���� ���� nand.txt�б�����
	std::ofstream result_file("result.txt");
	std::ifstream SSD_file("nand.txt");

	//������ �б�� string
	std::string read_data;
	std::string data_required;
	//���� ������ ssd_memory�� ����
	if (SSD_file.is_open()) {
		//���� ������ ���� ����ϱ� ���� �ʱ�ȭ
		ssd_memory.clear();
		//���� ������ ����
		while (std::getline(SSD_file, read_data)) {
			ssd_memory.push_back(read_data);
		}
	}
	//���� ���� ����
	else {
		std::cerr << "Failed to open the file." << std::endl;
	}
	//���Ϳ��� �ʿ��� ������ ����
	//std::cout << "vect size is " << ssd_memory.size() << std::endl;
	//index ���� üũ
	if (index>=0 && index < 100) {
		//�ʿ��� ������ ssd_memory���� ����
		data_required = ssd_memory[index];
		//result.txt�� �ش� ������ ����(�����)
		if (result_file.is_open()) {
			result_file << std::setfill('0') << std::setw(8) << std::hex << data_required << std::endl;
			std::cout << "Result: "  << "0x" << std::setfill('0') << std::setw(8) << std::hex << data_required << std::endl;
		}
		//���� ���� ����
		else {
			std::cerr << "Failed to open the file." << std::endl;
		}
	}
	//index ���� ��
	else {
		std::cerr << "Index over 100" << std::endl;
	}
	//���� ����
	result_file.close();
	SSD_file.close();
	//std::cout << "READ" << std::endl;
	
}

//read/write ��ɾ� �޴� �Լ��� ���� ����?