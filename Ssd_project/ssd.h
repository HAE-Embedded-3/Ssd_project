#pragma once
#include <iostream>
#include <vector>
#include <string>
#include<fstream>


//template <typename T> 
//class LogicalBlock {
//    T data;
//};

//스토리지 인터페이스 생성 -> SSD 클래스 구조
template <typename T> 
class Storage {
  public:
    //write 함수 (저장 위치, 저장할 데이터)
    virtual void write(uint32_t , T) = 0;
    //read 함수(불러올 위치)
    virtual void read(uint32_t) = 0;
    virtual ~Storage() {};
};

//SSD 클래스 생성
template <typename T> 
class SSD : public Storage<T> {
  private:
    //데이터 저장 형태: 벡터
    std::vector<T> ssd_memory;
    //txt파일 위치 주소
    //const std::string ssd_addr; -> 현재 위치에 자동으로 생성되게 만들것 (상대경로)
    
  public:
      //SSD 초기화 txt파일 위치 주소 받아서 생성/저장/불러오기
      SSD() : ssd_memory{} {
        //파일 생성 (만약 기존 파일 존재 한다면 이어서 수정됨
        std::fstream SSD_file("nand.txt", std::ios::in | std::ios::out | std::ios::app);
        std::fstream result_file("result.txt", std::ios::in | std::ios::out | std::ios::app);

        //초기 상태 설정으로 수정할 것
        SSD_file << "HELLO WORLD!!!" << std::endl;
        result_file << "RESULT!!!" << std::endl;
        //파일 종료
        }
    void write(uint32_t index, T data);
    void read(uint32_t index);


};