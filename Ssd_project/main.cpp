#include "ssd.h"

int main(void) {
    //Storage ssd = SSD<LogicalBlock<uint32_t>>{};
    //SSD 메모리 생성 (초기화)
    SSD<uint32_t>mem1;
    //SSD 1번칸에 1 대입
    mem1.write(1, 1);
    mem1.write(2, 2);
    mem1.write(3, 3);
    mem1.write(4, 4);
    //SSD 1번칸 불러오기
    mem1.read(1);
    mem1.read(2);
    mem1.read(3);
    mem1.read(4);
    //mem1.read(99);
    

    return (0);
}