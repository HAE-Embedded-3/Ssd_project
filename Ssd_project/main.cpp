#include "ssd.h"

int main(void) {
    //Storage ssd = SSD<LogicalBlock<uint32_t>>{};
    //SSD �޸� ���� (�ʱ�ȭ)
    SSD<uint32_t>mem1;
    //SSD 1��ĭ�� 1 ����
    mem1.write(1, 1);
    mem1.write(2, 2);
    mem1.write(3, 3);
    mem1.write(4, 4);
    //SSD 1��ĭ �ҷ�����
    mem1.read(1);
    mem1.read(2);
    mem1.read(3);
    mem1.read(4);
    //mem1.read(99);
    

    return (0);
}