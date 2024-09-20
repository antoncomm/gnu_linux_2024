#include <ncurses.h>
#include <stdio.h>
#include <locale.h>
#include <stdlib.h>

#define DX 3

int main (int argc, char* argv[])
{
    if (argc < 2)
    {
        fprintf(stderr, "The file name was not given!\n");
        exit(1);
    }
    else if (argc > 2)
    {
        fprintf(stderr, "More than one file name was given!\n");
        exit(1);
    }

    setlocale(LC_ALL, "");

    FILE *fp = fopen(argv[1], "r"); 
    if (fp == NULL)
    {
        fprintf(stderr, "The file does not open!\n");
        exit(1);
    }

    fseek(fp, 0L, SEEK_END);
    int file_size = ftell(fp);
    fseek(fp, 0L, SEEK_SET);

    int num_lines = 100;
    int *lines_beg = calloc(num_lines, sizeof(int));
    char *buf = calloc(file_size, sizeof(char));
    
    lines_beg[0] = 0;
    int count_lines = 0, i = 0, curr_line = 0, c = 0;
    for (c = getc(fp); c != EOF; c = getc(fp)){
        
        buf[i] = c;
        ++i;
        if (c == '\n')
        {
            lines_beg[count_lines+1] = lines_beg[count_lines] + curr_line + 1;
            ++count_lines;
            curr_line = 0;
            if (count_lines >= num_lines)
            {
                num_lines *= 2;
                lines_beg = realloc(lines_beg, num_lines * sizeof(int));
            }
        }
        else
        {
            ++curr_line;
        } 
    }

    num_lines = count_lines;
    
    fclose(fp);

    initscr();
    curs_set(0);
    move(0, 0);
    printw("File name: %s", argv[1]);
    refresh();
    
    WINDOW *win = newwin(LINES-2*DX, COLS-2*DX, DX, DX);
    keypad(win, TRUE);
    box(win, 0, 0);
    wmove(win, 1, 1); 
   
    int win_line_num = 0;
    for(;;)
    {
        curr_line = 0;
        for (; curr_line < LINES-2*DX && curr_line < num_lines; ++curr_line)
        {
            wmove(win, curr_line + 1, 1);
            wprintw(win, " %5d : ", curr_line + win_line_num);
            wmove(win, curr_line + 1, 10);
            waddnstr(win, buf + lines_beg[curr_line + win_line_num], 
                    lines_beg[curr_line + win_line_num + 1] - lines_beg[curr_line + win_line_num]);
        }
        box(win, 0, 0);
        wrefresh(win);
        
        switch (c = wgetch(win))
        {
            case 27:
                endwin();
                free(buf);
                free(lines_beg);
                return 0;
            case ' ':
            case KEY_DOWN:
                if (win_line_num + LINES-2*DX < num_lines + 2)
                {
                    ++win_line_num;
                }
                break;
            case KEY_UP:
                if (win_line_num > 0)
                {
                    --win_line_num;
                }
                break;
            default:
                break;
        }
        
    }

    return 0;
}
