#include "../drivers/display/display.c"

void main() {
    clean_screen();
    for (int i = 0; i < 80 * 25; i++) {
        //print_char((char)('0' + (i/80)%10), WHITE_ON_BLACK, -1, -1);
    }
}