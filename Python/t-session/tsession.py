#!/bin/python

import curses
from curses import wrapper, newwin


def main(stdscr):

    curses.cbreak()
    stdscr.clear()

    main_win_height = int(curses.LINES * 0.8)
    main_win_width  = int(curses.COLS * 0.5)
    main_win_y = int((curses.LINES - main_win_height) * 0.5)
    main_win_x = int((curses.COLS - main_win_width) * 0.5)

    sessions_win_height = int(main_win_height * 0.3)
    sessions_win_width  = int(main_win_width * 0.95)
    sessions_win_y = int((curses.LINES - sessions_win_height) * 0.83)
    sessions_win_x = int((curses.COLS - sessions_win_width) * 0.5)

    main_win = newwin(main_win_height, main_win_width, main_win_y, main_win_x)
    main_win.box()

    sessions_win = newwin(sessions_win_height, sessions_win_width, sessions_win_y, sessions_win_x)
    sessions_win.box()

    stdscr.refresh()
    main_win.refresh()
    sessions_win.refresh()

    while 1:
        keypress = stdscr.getkey()  # noqa: E701
        if keypress == curses.KEY_ENTER:
            pass

wrapper(main)

def createSession(starting_directory: str):
    new_session_command = ["tmux", "new-session", "-c", starting_directory, "-s", starting_directory.split()[-1]]
