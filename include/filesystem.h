//
// Created by 진민우 on 2025. 2. 5..
//

#ifndef FILESYSTEM_H
#define FILESYSTEM_H

int create_new_file(char* path);
int open_existing_file(char* path);
void save_file_and_quit(int fd);
void write_command_to_file(char* command_by_user, int fd);
int get_current_fd();
void show_files();

#endif //FILESYSTEM_H
