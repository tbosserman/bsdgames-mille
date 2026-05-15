// A wrapper around the ncurses routines that use stdscr.
// In newer versions of ncurses, stdscr is not a regular "screen".
// Therefore you can't assign a value to it. But mille depends on being
// able to reassign initscr all over the place. So this is an attempt to
// get mille to build and run on newer ncurses implementations.

// Difficult ones:
//   mvprintw - uses varargs so I don't think I can just #define it.

#include <ncurses.h>
#include <stdarg.h>

WINDOW *x_stdscr;

int x_mvprintw(int y, int x, const char *fmt, ...)
{
    va_list	ap;

    wmove(x_stdscr, y, x);
    va_start(ap, fmt);
    vw_printw(x_stdscr, fmt, ap);
    va_end(ap);
}
