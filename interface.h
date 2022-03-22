#include "page.h"

/*
for this interface, i'd like something like this

+---------------------------------+
| topbar                          |
+-----------------------+---------+
| active_page           | sidebar |
|						|		  |
|						|		  |
|						|		  |
|						|		  |
|						|		  |
|						|		  |
+-----------------------+---------+

*/

typedef struct struct_interface {
	page* active_page;
	unsigned int line;
	unsigned int col;
	unsigned int* col_positions;
	void (*callback)(unsigned int, struct struct_interface*, void*);

	unsigned int top_bar_size;
	unsigned int right_menu_size;
} interface;

void init_interface(interface* interf);
void kill_interface(interface* interf);
void update_interface(interface* interf);
