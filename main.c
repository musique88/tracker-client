#include "interface.h"
#include <string.h>

int main() {
	char c[2000];
	unsigned int cols_size[8];
	memset(c, '0', 2000);	
	for(unsigned int i = 0; i < 31; i++)
		memcpy(&c[i * 64], "Je passe des nuits blanches, chercher quoi faire de mes journees", 64);
	
	cols_size[0] = 2;
	cols_size[1] = 2;
	cols_size[2] = 2;
	cols_size[3] = 2;
	cols_size[4] = 2;
	cols_size[5] = 2;
	cols_size[6] = 2;
	cols_size[7] = 2;

	page p;	
	p.data = c;
	p.columns_size = cols_size;
	p.columns= 8;
	p.lines = 125;

	interface i;
	init_interface(&i);
	i.active_page = &p;
	unsigned int col_pos[8];
	col_pos[0] = 1;
	col_pos[1] = 4;
	col_pos[2] = 7;
	col_pos[3] = 10;
	col_pos[4] = 13;
	col_pos[5] = 16;
	col_pos[6] = 19;
	col_pos[7] = 22;

	i.col_positions = col_pos;
	i.top_bar_size = 4;
	i.right_menu_size = 4;
	i.col = 3;
	i.line = 3;
	update_interface(&i);
	while(1);
}
