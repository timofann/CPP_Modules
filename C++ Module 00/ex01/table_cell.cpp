#include "table_cell.h"

std::string	table_cell(std::string src, std::string *dst) {
	size_t start_index = (10 - src.length()) * (src.length() < 10);
	*dst = std::string(10, ' ');
	dst->replace(start_index, 10 - start_index, src, 0, 10 - start_index);
	if (src.length() > 10)
		dst->replace(9, 1, ".");
	return *dst;
}
