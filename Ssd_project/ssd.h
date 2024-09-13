#include <iostream>
#include <vector>

template <typename T> class LogicalBlock {
    T data;
};

template <typename T> class Storage {
  public:
    // 순수가상함수 선언
    virtual void write(uint32_t index, T data) = 0;
    virtual void read(uint32_t index) = 0;
};

template <typename T> class SSD : public Storage<T> {
  private:
    std::vector<T> 어쩌구;

  public:
    // 가상함수 구현
};