#ifndef EXECUTE_H
#define EXECUTE_H

void mov_execute_copy(unsigned char *dest_reg, unsigned char *src_reg);
void mov_execute_immediate(unsigned char* dest_reg, unsigned char value);
void store_execute(unsigned char *source_reg, unsigned char memory_address);
void load_execute(unsigned char* dest_reg, unsigned char memory_address);
void add_execute(unsigned char* dest_reg, unsigned char* src_reg);
void sub_execute(unsigned char* dest_reg, unsigned char* src_reg);
void jmp_execute(unsigned char dest_reg);
void jeq_execute(unsigned char dest_reg);

#endif //EXECUTE_H
