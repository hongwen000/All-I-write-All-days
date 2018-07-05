#define KEY_LF          0xE4
#define KEY_RT          0xE5
#define MAX_BUF         512
#define TTY_MOVE_CURSOR_BACK      "\033[D"
#define TTY_MOVE_CURSOR_FORWARD   "\033[C"
#include <cstdio>
#include <cstring>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <curses.h>
#include <unistd.h>
using namespace std;
char buf[MAX_BUF];
int main()
{
    puts("Please enter file name: ");
    char fn [13];
    scanf("%s", fn);
    int fd;
    fd = open(fn, O_CREAT);
    if(fd == -1)
    {
        puts("Can not open or create file\n");
        return -1;
    }
    size_t pos = 0;
    int ch;
    struct stat fst;
    fstat(fd, &fst);
    size_t sz = fst.st_size;
    read(fd, buf, sz);
    puts(buf);
    while (true)
    {
        if (getch() == '\033') { // if the first value is esc
            getch(); // skip the [
            switch(getch()) { // the real value
                case 'C':
                    ch = KEY_RT;
                    break;
                case 'D':
                    ch = KEY_LF;
                    // code for arrow left
                    break;
            }
        }
        if(ch == 27)
            break;
        else if(ch == KEY_LF)
        {
            if(pos > 0)
            {
                pos--;
                puts(TTY_MOVE_CURSOR_BACK);
            }
        }
        else if(ch == KEY_RT)
        {
            if(pos < sz)
            {
                pos++;
                puts(TTY_MOVE_CURSOR_FORWARD);
            }
        }
        else if (ch == '\b')
        {
            if(pos)
            {
                sz--;
                pos--;
                memmove(buf+pos, buf+pos + 1, MAX_BUF - pos);
//                putchar(ch);
            }
        }
        else
        {
            if(pos == sz)
            {
                buf[sz++] = ch;
                putchar(ch);
            }
            else
            {
                buf[pos] = ch;
                putchar(ch);
            }
            lseek(fd, pos, SEEK_SET);
            write(fd, buf, sz);
        }
    }
}
