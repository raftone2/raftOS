#define VIDEO_MEMORY 0xb8000
#define VIDEO_ADDRESS 0xb8000
#define MAX_ROWS 25
#define MAX_COLS 80

#define WHITE_ON_BLACK 0x0f
#define BLACK_ON_WHITE 0xf0
#define RED_ON_WHITE 0xf4

#define REG_SCREEN_CTRL 0x3d4
#define REG_SCREEN_DATA 0x3d5

#define TRUE 1
#define FALSE 0

typedef char bool;
typedef unsigned int u_int;

void print_char(char symbol, unsigned char color, int col, int row);
void print_string(const char* string, unsigned char color, int col, int row);
void clean_screen();
void scroll(unsigned char lines);
bool col_in_field(int col);
bool row_in_field(int row);
