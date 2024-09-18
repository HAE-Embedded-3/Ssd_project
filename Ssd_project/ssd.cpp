#include "ssd.h"

//템플릿을 썼더니 오류가 난다??? 원인 파악 필요 -> 헤더파일 템플릿과 겹쳐서 문제 발생???
//template <typename T>
void SSD<uint32_t>::write(uint32_t index, uint32_t input_data) {
	std::cout << "WRITE" << std::endl;
}

//template <typename T> 
void SSD<uint32_t>::read(uint32_t index) {
	std::cout << "READ" << std::endl;

}