#ifndef DISPLAY_MEMORY_STATE_H
#define DISPLAY_MEMORY_STATE_H

void draw_memory_view();
void draw_register_view(int, int);
void dec_to_bin(char* bin_str, unsigned char dec);
void ncurse_init();

#endif //DISPLAY_MEMORY_STATE_H
