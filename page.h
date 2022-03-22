typedef struct {
	char* data;
	unsigned int* columns_size;
	unsigned int columns;
	unsigned int lines;
} page;

void set_line_to_page(page* p, char** line, unsigned int line_to_change);

void get_string_from_page(page* p, unsigned int col, unsigned int line, char* out);
