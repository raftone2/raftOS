unsigned char port_byte_in(unsigned short port) {
    unsigned char result_data;
    __asm__("in %%dx, %%al" : "=a" (result_data) : "d" (port));
    return result_data;
}

void port_byte_out(unsigned short port, unsigned char data) {
    __asm__("out %%al, %%dx" : : "a"(data), "d"(port));
}

unsigned short port_word_in(unsigned short port) {
    unsigned short result_data;
    __asm__("in %%dx, %%ax" : "=a"(result_data) : "d"(port));
    return result_data;
}

void port_word_out(unsigned short port, unsigned short data) {
    __asm__("out %%ax, %%dx" : : "a"(data), "d"(port));
}

void io_wait() {
    __asm__("out %%al, $0x80" : : "a"(0)); // writing to "unused" port
}