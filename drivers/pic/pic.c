#include "pic.h"

void pic_remap(unsigned int offset1, unsigned int offset2){
    unsigned char m1, m2;
    m1 = port_byte_in(MASTER_PIC_DATA);
    m2 = port_byte_in(SLAVE_PIC_DATA);

    port_byte_out(MASTER_PIC_CMD, 0x11); // start in cascade mode
    io_wait();
    port_byte_out(SLAVE_PIC_CMD, 0x11); // start in cascade mode
    io_wait();
    port_byte_out(MASTER_PIC_DATA, offset1);
    io_wait();
    port_byte_out(SLAVE_PIC_DATA, offset2);
    io_wait();
    port_byte_out(MASTER_PIC_DATA, 4); // 0000 0100 - use irq2 in cascade
    io_wait();
    port_byte_out(SLAVE_PIC_DATA, 2); // cascade identity
    io_wait();

    port_byte_out(MASTER_PIC_DATA, ICW4_8086);
	io_wait();
	port_byte_out(SLAVE_PIC_DATA, ICW4_8086);
	io_wait();
    port_byte_out(MASTER_PIC_DATA, m1);
    port_byte_out(SLAVE_PIC_DATA, m2);
}