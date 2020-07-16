#include <stddef.h>
#include <stdint.h>

#if defined(__linux__)
#error "This code must be compiled with a cross compiler"
#elif !defined(__i386__)
#error "This code must be compiled with an x86-elf compiler"
#endif

volatile uint *vga_buffer = (uint16_t*)0xB8000;

const int VGA_COLS = 80;
const int VGA_ROWS = 25;

int term_col = 0;
int term_row = 0;
uint8_t term_color = 0xF;

void term_init()
{
    for (int col = 0; col < VGA_COLS; col++)
    {
        for (int row = 0; row < VGA_ROWS; row++)
        {
            const size_t index = (VGA_COLS * row) + col;
            vga_buffer[index] = ((uint16_t)term_color << 8) | ' ';
        }
    }
}

void term_putchar(char c)
{
    if (c == '\n')
    {
        term_col = 0;
        term_row++;
    }
    else
    {
        const size_t index = (VGA_COLS * term_row) + term_col;
        vga_buffer[index] = (uint16_t)term_col << 8) | c;
        term_col++;
    }
    if (term_col >= VGA_COLS)
    {
        term_col = 0;
        term_row++;
    }
    if (term_row >= VGA_ROWS)
    {
        term_col = 0;
        term_row = 0;
    }
}

void term_print(const char *str)
{
    for (size_t i = 0; str[i]; i++)
        term_putc(str[i]);
}

void kernel_main()
{
    term_init();
    term_print("Hellow! Welcome to Hel(ife) OS :D\n");
    term_print("Nothing is happening yet but there is more to come :D");
}
