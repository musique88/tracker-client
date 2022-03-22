#include "interface.h"
#include <string.h>
#include <stdio.h>

void key_callback(unsigned int input, interface* interf, void* args) {
	switch(input) {
		case 'j':
			interf->line++;
			break;
		case 'k':
			interf->line--;
			break;
		case 'h':
			interf->col--;
			break;
		case 'l':
			interf->col++;
			break;
	}
}

int main() {
	char c[2000];
	unsigned int cols_size[8];
	memset(c, '0', 2000);	
	
	for(unsigned int i = 0; i < 8; i++)
		cols_size[i] = 2;

	page p;	
	p.data = c;
	p.columns_size = cols_size;
	p.columns= 8;
	p.lines = 125;
	char in[10];
	
	for(unsigned int i = 0; i < p.lines; i++) {
		sprintf(in, "%02X", i);
		set_chars_to_page(&p, 0, i, in);
	}

	set_chars_to_page(&p, 0, 0, "DE");
	set_chars_to_page(&p, 1, 1, "AD");
	set_chars_to_page(&p, 2, 2, "BE");
	set_chars_to_page(&p, 3, 3, "EF");

	interface interf;
	init_interface(&interf);
	interf.active_page = &p;
	unsigned int col_pos[8];
	col_pos[0] = 1;
	col_pos[1] = 5;
	col_pos[2] = 8;
	col_pos[3] = 11;
	col_pos[4] = 14;
	col_pos[5] = 17;
	col_pos[6] = 20;
	col_pos[7] = 23;

	interf.col_positions = col_pos;
	interf.top_bar_size = 4;
	interf.right_menu_size = 4;
	interf.col = 3;
	interf.line = 3;
	interf.callback = key_callback; 
	while(1)
		update_interface(&interf);
}
