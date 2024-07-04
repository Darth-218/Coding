#!/bin/python

import curses
from curses import wrapper, newwin

def main(stdscr):
    curses.noecho()
    stdscr.clear()

    main_win_height = 20
    main_win_width  = 40
    main_win_y = 10
    main_win_x = 20
    main_win = newwin(main_win_height, main_win_width, main_win_y, main_win_x)

    main_win.addstr(3, 3, "Test window")
    main_win.refresh()

    stdscr.getkey()

wrapper(main)

