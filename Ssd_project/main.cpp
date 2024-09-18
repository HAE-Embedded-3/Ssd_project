#include "ssd.h"

int main(void) {
    //Storage ssd = SSD<LogicalBlock<uint32_t>>{};
    SSD<uint32_t>mem1;
    mem1.write(0, 1);
    mem1.write(0, 2);
    mem1.write(0, 3);
    mem1.write(0, 4);
    mem1.read(50);
    

    return (0);
}