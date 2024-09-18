#include "ssd.h"

int main(void) {
    //Storage ssd = SSD<LogicalBlock<uint32_t>>{};
    SSD<uint32_t>mem1;
    mem1.read(5);
    mem1.write(0,365);

    return (0);
}