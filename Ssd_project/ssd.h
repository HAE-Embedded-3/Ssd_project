//#pragma once
#ifndef __SSD_H__
#define __SSD_H__
#include"common.h"

//template <typename T> 
//class LogicalBlock {
//    T data;
//};

//���丮�� �������̽� ���� -> SSD Ŭ���� ����
template <typename T>
class Storage {
public:
    //write �Լ� (���� ��ġ, ������ ������)
    virtual void write(uint32_t, T) = 0;
    //read �Լ�(�ҷ��� ��ġ)
    virtual void read(uint32_t) = 0;
    virtual ~Storage() {};
};

//SSD Ŭ���� ����
template <typename T>
class SSD : public Storage<T> {
private:
    //������ ���� ����: ����
    std::vector<std::string> ssd_memory;
    //txt���� ��ġ �ּ�
    //const std::string ssd_addr; -> ���� ��ġ�� �ڵ����� �����ǰ� ����� (�����)

public:
    //SSD �ʱ�ȭ txt���� ��ġ �ּ� �޾Ƽ� ����/����/�ҷ�����
    SSD() : ssd_memory{} {
        //std::fstream SSD_file("nand.txt", std::ios::in | std::ios::out | std::ios::app);
        //std::fstream result_file("result.txt", std::ios::in | std::ios::out | std::ios::app);

        //������ ���� 
        std::ofstream SSD_file("nand.txt");
        std::ofstream result_file("result.txt");

        //�ʱ� ���� �������� ������ �� 0x00000
        for (int i = 0; i < 100; i++) {

            if (SSD_file.is_open()) {
                SSD_file << "0x" << std::setfill('0') << std::setw(8) << std::hex << 0x00000000 << std::endl;
            }
            else {
                std::cerr << "Failed to open the file." << std::endl;
            }

        }
        //���� ����
        SSD_file.close();
        result_file.close();
    }
    //input �������� ��...�ʿ��ϴ� -> ���ø� Ȱ��
    void write(uint32_t index, uint32_t input_data);
    void read(uint32_t index);


};
#endif // !__SSD_H__

