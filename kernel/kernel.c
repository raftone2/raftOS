#pragma once

#include "../drivers/display/display.h"
#include "interrupts/idt/idt.h"
#include "interrupts/timer/timer.h"

void main() {

    idt_setup();
    __asm__ __volatile__("sti");
    init_timer(100);

    //clean_screen();
    __asm__ __volatile__("int $0");
    // for (int i = 0; i < 80 * 25; i++) {
    //     print_char((char)('0' + (i/80)%10), WHITE_ON_BLACK, -1, -1);
    // }
    // print_string("Starting\nKernel\nWith NEWLINE Support\n", BLACK_ON_WHITE, 0, 0);
}