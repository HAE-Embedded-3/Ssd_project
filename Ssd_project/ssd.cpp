#include "ssd.h"

//템플릿을 썼더니 오류가 난다??? 원인 파악 필요 -> 헤더파일 템플릿과 겹쳐서 문제 발생???
//template <typename T>
// 
// 파일 사용 코드
//std::fstream SSD_file("nand.txt", std::ios::in | std::ios::out | std::ios::app);
//std::fstream result_file("result.txt", std::ios::in | std::ios::out | std::ios::app);

void SSD<uint32_t>::write(uint32_t index, uint32_t input_data) {
	//예외처리 요소: index가 0~100 범위 아닌 경우, input data의 데이터 형 불일치, txt 파일이 접근이 안 되는 경우
	////입력값 오류의 경우 애플리케이션에서 처리해야하지 않은가???
	//if (index < 0 || index>100) {
	//	std::cerr << "Wrong Index" << std::endl;
	//}
	//파일 열기 - 읽기/쓰기 모드
	//std::fstream SSD_file("nand.txt",std::ios::in|std::ios::out);
	std::ifstream SSD_read_file("nand.txt");
	//데이터 읽기용 string
	std::string read_data;
	//현재 txt파일 데이터 읽기 (FULL READ) - ssd_memory에 저장
	if (SSD_read_file.is_open()) {
		//읽은 데이터 새로 기록하기 위해 초기화
		// 함수 불러올 떄마다 초기화가 된다?
		ssd_memory.clear();
		//읽은 데이터 저장
		while (std::getline(SSD_read_file, read_data)) {
			ssd_memory.push_back(read_data);
			//std::cout << read_data << std::endl;
		}
		std::cout << "READ DATA FIN" << std::endl;
	}
	//파일 열기 실패
	else {
		std::cerr << "Failed to open the file." << std::endl;
	}
	SSD_read_file.close();

	std::ofstream SSD_file("nand.txt");
	//데이터 수정(ssd_memory)
	ssd_memory[index] = std::to_string(input_data);
	//수정된 데이터 txt파일 덮어쓰기

	//0x 붙이는거 빡세네... 수정 필요
	for (auto revised_data : ssd_memory) {
		SSD_file << std::setfill('0') << std::setw(8) << std::hex << revised_data << std::endl;
		std::cout << revised_data << std::endl;
	}
	//파일 닫기
	SSD_file.close();
}


//template <typename T> 
void SSD<uint32_t>::read(uint32_t index) {
	//파일 열기 result.txt 쓰기 전용 nand.txt읽기전용
	std::ofstream result_file("result.txt");
	std::ifstream SSD_file("nand.txt");

	//데이터 읽기용 string
	std::string read_data;
	std::string data_required;
	//읽은 데이터 ssd_memory에 저장
	if (SSD_file.is_open()) {
		//읽은 데이터 새로 기록하기 위해 초기화
		ssd_memory.clear();
		//읽은 데이터 저장
		while (std::getline(SSD_file, read_data)) {
			ssd_memory.push_back(read_data);
		}
	}
	//파일 열기 실패
	else {
		std::cerr << "Failed to open the file." << std::endl;
	}
	//벡터에서 필요한 데이터 추출
	//std::cout << "vect size is " << ssd_memory.size() << std::endl;
	//index 범위 체크
	if (index>=0 && index < 100) {
		//필요한 데이터 ssd_memory에서 추출
		data_required = ssd_memory[index];
		//result.txt에 해당 데이터 저장(덮어쓰기)
		if (result_file.is_open()) {
			result_file << std::setfill('0') << std::setw(8) << std::hex << data_required << std::endl;
			std::cout << "Result: "  << "0x" << std::setfill('0') << std::setw(8) << std::hex << data_required << std::endl;
		}
		//파일 열기 실패
		else {
			std::cerr << "Failed to open the file." << std::endl;
		}
	}
	//index 범위 밖
	else {
		std::cerr << "Index over 100" << std::endl;
	}
	//파일 종료
	result_file.close();
	SSD_file.close();
	//std::cout << "READ" << std::endl;
	
}

//read/write 명령어 받는 함수는 앱의 영역?