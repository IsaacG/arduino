/* Pattern Config */
// The pattern.
char pattern[][50] = {"Purl", "Knit", "Knit"};
// Screen rotation. 0: vertical, 1: horizontal, 2: vert upside down, 3: etc
int rotation = 0;
// Text size. Try 1, 2 or 3.
int text_size = 2;
// Current row color
int cur_color = BLUE;
// Other row color
int other_color = WHITE;
// Background color
int bg_color = BLACK;
// Format used to print the current row.
char *cur_line_format = ">%s\n";
// Format used to print the other rows.
char *other_line_format = " %s\n";
