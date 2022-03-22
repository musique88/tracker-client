#include "interface.h"
#include <ncurses.h>

void init_interface(interface* interf) {
	initscr();
	noecho();
	interf->line = 0;
	interf->col = 0;
}

void kill_interface(interface* interf) {
	endwin();
}

void update_page_interface(interface* interf) {
	int rows;
	int cols;
	getmaxyx(stdscr, rows, cols);

	int disp_lines = rows - interf->top_bar_size;
	int disp_cols = cols - interf->right_menu_size;

	unsigned int first_line = (interf->line / disp_lines) * disp_lines;
	
	for(unsigned int i = 0; i < disp_lines; i++) {
		for(unsigned int j = 0; j < interf->active_page->columns; j++) {
			if(interf->col_positions[j] + interf->active_page->columns_size[j] > disp_cols) 
				break;
			char str[20];
			get_string_from_page(interf->active_page, j, i, str);
			for(unsigned int k = 0; k < interf->active_page->columns_size[j]; k++)
				mvaddch(i + interf->top_bar_size, interf->col_positions[j] + k, str[k]);
		}
	}
	move(interf->line + interf->top_bar_size, interf->col_positions[interf->col]);	
}

void update_interface(interface* interf) {
	update_page_interface(interf);
	refresh();
}

