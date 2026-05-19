### BSD Mille Bornes Game

This repository has a (very hacked up) copy of the ancient mille game
from the original BSD source code distributions. It has been modified
to build with modern ncurses libraries.

The basic difference is this: in the old (Old, OLD!) days, the global
variable initscr was an actual variable that you could reassign to
point to a different curses window. Somewhere along the line, that changed.

The original mille game took advantage of the fact that you could modify
the default window that functions like addstr, mvaddstr, etc. would write to.

I renamed all those calls to have a prefix "x_". Then I created some
#defines in mille.h to have those calls write to a window named
x_stdscr. And in all the places that stdscr was referenced, I changed those
references to be x_stdscr instead.

### NOTES
1. I've only tested this on Linux distributions. My bad. I should, at a
minimum, at least make sure it still builds on FreeBSD and NetBSD. But
I've tested it on several recent Linux distros (Ubuntu 24.04, Mint 22.3,
Debian Bookworm, Zorin 18, probably some others I've forgotten now....)
It probably builds on MacOS, but I don't have a working Mac anymore so I
don't have any way to test that.

2. It's now been tested building under cygwin on Windows 11.
3. Now tested on FreeBSD 15.

### KOWN BUGS

1. At the conclusion of each "hand", the "Milestones Played" of the player
who lost that hand will not be displayed.
    - Fixed as of 2026-05-26.

