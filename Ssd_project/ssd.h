//#pragma once
#ifndef __SSD_H__
#define __SSD_H__
#include"common.h"

//template <typename T> 
//class LogicalBlock {
//    T data;
//};

//스토리지 인터페이스 생성 -> SSD 클래스 구조
template <typename T>
class Storage {
public:
    //write 함수 (저장 위치, 저장할 데이터)
    virtual void write(uint32_t, T) = 0;
    //read 함수(불러올 위치)
    virtual void read(uint32_t) = 0;
    virtual ~Storage() {};
};

//SSD 클래스 생성
template <typename T>
class SSD : public Storage<T> {
private:
    //데이터 저장 형태: 벡터
    std::vector<std::string> ssd_memory;
    //txt파일 위치 주소
    //const std::string ssd_addr; -> 현재 위치에 자동으로 생성되게 만들것 (상대경로)

public:
    //SSD 초기화 txt파일 위치 주소 받아서 생성/저장/불러오기
    SSD() : ssd_memory{} {
        //std::fstream SSD_file("nand.txt", std::ios::in | std::ios::out | std::ios::app);
        //std::fstream result_file("result.txt", std::ios::in | std::ios::out | std::ios::app);

        //덮어쓰기식 생성 
        std::ofstream SSD_file("nand.txt");
        std::ofstream result_file("result.txt");

        //초기 상태 설정으로 수정할 것 0x00000
        for (int i = 0; i < 100; i++) {

            if (SSD_file.is_open()) {
                SSD_file << "0x" << std::setfill('0') << std::setw(8) << std::hex << 0x00000000 << std::endl;
            }
            else {
                std::cerr << "Failed to open the file." << std::endl;
            }

        }
        //파일 종료
        SSD_file.close();
        result_file.close();
    }
    //input 자유도가 음...필요하다 -> 탬플릿 활용
    void write(uint32_t index, uint32_t input_data);
    void read(uint32_t index);


};
#endif // !__SSD_H__

