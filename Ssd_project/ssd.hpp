#include <iostream>
#include <fstream>
#include <vector>
#include <string>

template <typename T> class LogicalBlock {
public:
    T data;

    LogicalBlock() : data(0) {}
    LogicalBlock(T value) : data(value) {}

    std::string toString() const {
        return std::to_string(data);
    }
    friend std::ostream& operator<<(std::ostream& os, const LogicalBlock<T>& block) {
        os << block.data; // T의 데이터를 출력
        return os;
    }
};

template <typename T> class Storage {
public:
    // 순수가상함수 선언
    virtual void write(uint32_t index, T data) = 0;
    virtual void read(uint32_t index) = 0;
};

template <typename T> class SSD : public Storage<T> {
public:
    std::vector<T> ssd;
    void init(); // 파일 생성

public:
    void write(uint32_t index, T data);
    void read(uint32_t index);

    SSD() {
        std::cout << "SSD init" << std::endl;
        init();
    }
};