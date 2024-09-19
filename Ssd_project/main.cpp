#include "ssd.h"

int main(void) {
    //Storage ssd = SSD<LogicalBlock<uint32_t>>{};
    SSD<uint32_t>mem1;
    mem1.write(1, 1);
    mem1.write(2, 2);
    mem1.write(3, 3);
    mem1.write(4, 4);
    mem1.read(1);
    mem1.read(2);
    mem1.read(3);
    mem1.read(4);
    mem1.read(10);
    

    return (0);
}