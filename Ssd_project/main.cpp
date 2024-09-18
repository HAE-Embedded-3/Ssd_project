#include "ssd.h"

int main(void) {
    //Storage ssd = SSD<LogicalBlock<uint32_t>>{};
    SSD<uint32_t>mem1;
    mem1.read(0);
    mem1.write(0,35);

    return (0);
}