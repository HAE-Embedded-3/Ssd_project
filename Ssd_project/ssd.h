#pragma once
#include <iostream>
#include <vector>
#include <string>
#include<fstream>


//template <typename T> 
//class LogicalBlock {
//    T data;
//};

//���丮�� �������̽� ���� -> SSD Ŭ���� ����
template <typename T> 
class Storage {
  public:
    //write �Լ� (���� ��ġ, ������ ������)
    virtual void write(uint32_t , T) = 0;
    //read �Լ�(�ҷ��� ��ġ)
    virtual void read(uint32_t) = 0;
    virtual ~Storage() {};
};

//SSD Ŭ���� ����
template <typename T> 
class SSD : public Storage<T> {
  private:
    //������ ���� ����: ����
    std::vector<T> ssd_memory;
    //txt���� ��ġ �ּ�
    //const std::string ssd_addr; -> ���� ��ġ�� �ڵ����� �����ǰ� ����� (�����)
    
  public:
      //SSD �ʱ�ȭ txt���� ��ġ �ּ� �޾Ƽ� ����/����/�ҷ�����
      SSD() : ssd_memory{} {
        //���� ���� (���� ���� ���� ���� �Ѵٸ� �̾ ������
        std::fstream SSD_file("nand.txt", std::ios::in | std::ios::out | std::ios::app);
        std::fstream result_file("result.txt", std::ios::in | std::ios::out | std::ios::app);

        //�ʱ� ���� �������� ������ ��
        SSD_file << "HELLO WORLD!!!" << std::endl;
        result_file << "RESULT!!!" << std::endl;
        //���� ����
        }
    void write(uint32_t index, T data);
    void read(uint32_t index);


};