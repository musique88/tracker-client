#include "page.h"

void set_line_to_page(page* p, char** line, unsigned int line_to_change) {
	char* current_cell = &p->data[line_to_change];
	unsigned int line_size = 0;
	
	for(unsigned int i = 0; i < p->columns; i++)
		line_size += p->columns_size[i];
	for(unsigned int i = 0; i < line_size; i++)
		current_cell[i] = ' ';

	for(unsigned int i = 0; i < p->columns; i++) {
		for(unsigned int j = 0; j < p->columns_size[i] && line[i][j] != '\0'; j++)
			current_cell[j] = line[i][j];
		current_cell = &current_cell[p->columns_size[i]];
	}
}

void get_string_from_page(page* p, unsigned int col, unsigned int line, char* out) {
	unsigned int line_size = 0;
	for(unsigned int i = 0; i < p->columns; i++)
		line_size += p->columns_size[i];

	char* current_cell = &p->data[line_size * line];
	
	for(unsigned int i = 0; i < col; i++)
		current_cell = &current_cell[p->columns_size[i]];
	for(unsigned int i = 0; i < p->columns_size[col]; i++)
		out[i] = current_cell[i];
}
