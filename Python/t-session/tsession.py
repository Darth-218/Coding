#!/bin/python

# TODO: Command exit codes

import curses, os, subprocess
from curses import wrapper, newwin

def main(stdscr):

    curses.cbreak() 
    curses.curs_set(0)
    stdscr.clear()

    main_win_height = int(curses.LINES * 0.5)
    main_win_width  = int(curses.COLS * 0.5)
    main_win_y = int(curses.LINES * 0.5) - int(main_win_height * 0.5)
    main_win_x = int(curses.COLS * 0.5) - int(main_win_width * 0.5)

    commands_win_height = int(main_win_height * 0.2)
    commands_win_width  = main_win_width
    commands_win_y = int(main_win_y + (main_win_height - main_win_height * 0.2)) + 1
    commands_win_x = int(curses.COLS * 0.5) - int(commands_win_width * 0.5)

    commands_win = newwin(commands_win_height, commands_win_width, commands_win_y, commands_win_x)
    commands_win.box()

    main_win = newwin(main_win_height, main_win_width, main_win_y, main_win_x)
    main_win.box()

    printBinds(commands_win, commands_win_width)

    sessions = getSessions()

    # session_x = int((len(max(sessions)) - main_win_width) / 2)
    session_y = 1
    session_x = 1

    for i in sessions:
        main_win.addstr(session_y, session_x, i)
        session_y += 2

    stdscr.refresh()
    main_win.refresh()
    commands_win.refresh()

    while 1:
        keypress = stdscr.getkey()
        if keypress == "q":
            quit()

def printBinds(window, width) -> None:
    bindings = ["q: Quit", "n: New session", "c: Create session", "k: Kill session"]
    y = int(width * 0.55)
    window.addstr(1, int(y * 0.35), bindings[0])
    window.addstr(1, y, bindings[1])
    window.addstr(2, int(y * 0.35), bindings[2])
    window.addstr(2, y, bindings[3])


def getSessions() -> list[str]:
    list_command = ["tmux", "list-sessions"]
    sessions = subprocess.check_output(list_command, shell = False)
    sessions = sessions.decode()
    sessions = sessions.split("\n")
    return sessions


def createSession(starting_directory: str, session_name = None) -> None:
    session_name = starting_directory.split()[-1] if session_name == None else session_name
    new_session_command = ["tmux", "new-session", "-c", starting_directory, "-s", session_name]

    try:
        os.system(" ".join(new_session_command))

    except: # FIX: Better error handling
        print("Error creating session")


def killSession(session_name: str) -> None:
    kill_session_command = ["tmux", "kill-session", "-t", session_name]
    os.system(" ".join(kill_session_command))

wrapper(main)
