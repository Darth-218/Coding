#!/bin/python

# TODO: Command exit codes

import curses, subprocess
from curses import wrapper, newpad


def main(stdscr):

    curses.cbreak()
    curses.curs_set(0)
    stdscr.clear()

    main_win_height = int(curses.LINES * 0.5)
    main_win_width = int(curses.COLS * 0.5)
    main_win_y = int(curses.LINES * 0.5) - int(main_win_height * 0.5)
    main_win_x = int(curses.COLS * 0.5) - int(main_win_width * 0.5)

    commands_win_height = int(main_win_height * 0.2)
    commands_win_width = main_win_width
    commands_win_y = int(curses.LINES - main_win_height + commands_win_height) - 1
    commands_win_x = int(curses.COLS * 0.5) - int(commands_win_width * 0.5)

    commands_win = newpad(commands_win_height, commands_win_width)
    main_win = newpad(main_win_height, main_win_width)

    selected = 0
    printBinds(
        commands_win,
        commands_win_width,
        commands_win_height,
        commands_win_x,
        commands_win_y,
    )
    printSessions(
        main_win, main_win_width, main_win_height, main_win_x, main_win_y, selected
    )

    stdscr.refresh()
    main_win.refresh(
        0,
        0,
        main_win_y,
        main_win_x,
        main_win_y + main_win_height,
        main_win_x + main_win_width,
    )
    commands_win.refresh(
        0,
        0,
        commands_win_y,
        commands_win_x,
        commands_win_y + commands_win_height,
        commands_win_x + commands_win_width,
    )

    while 1:

        commands = {
            "q": "quit()",
            "n": "pass",
            "c": "createSession(subprocess.check_output('pwd', shell=False).decode())",
            "K": "killSession(getSessions()[selected].split(':')[0])",
        }

        keypress = stdscr.getkey()
        if keypress in commands:
            exec(commands[keypress])
        elif keypress == "j":
            selected += 1
            if selected >= len(getSessions()):
                selected = 0
        elif keypress == "k":
            selected -= 1
            if selected < 0:
                selected = len(getSessions()) - 1
        elif keypress == "l":
            switchSession(getSessions()[selected].split(":")[0])
        else:
            print(keypress)

        printSessions(
            main_win,
            main_win_width,
            main_win_height,
            main_win_x,
            main_win_y,
            selected,
        )
        main_win.refresh(
            0,
            0,
            main_win_y,
            main_win_x,
            main_win_y + main_win_height,
            main_win_x + main_win_width,
        )
        commands_win.refresh(
            0,
            0,
            commands_win_y,
            commands_win_x,
            commands_win_y + commands_win_height,
            commands_win_x + commands_win_width,
        )


def updateSelected(selected: int, x: int):
    selected += x
    return selected


def printSessions(window, width, height, x, y, selected) -> None:
    sessions = getSessions()
    for i in range(len(sessions)):
        sessions[i] = sessions[i][: sessions[i].find("(")]
    session_x = int(width / 2)
    session_y = 1
    middle_diff = getMaxlen(sessions)
    for i in range(len(sessions)):
        if i == selected:
            window.addstr(
                session_y,
                session_x - int(0.5 * middle_diff),
                sessions[i],
                curses.A_UNDERLINE,
            )
        else:
            window.addstr(session_y, session_x - int(0.5 * middle_diff), sessions[i])
        session_y += 2


def printBinds(window, width, height, x, y) -> None:
    bindings = ["q: Quit", "n: New session", "c: Create session", "K: Kill session"]
    x = width // 2 - len(" - ".join(bindings)) // 2
    window.addstr(0, x, " - ".join(bindings))
    window.refresh(
        0,
        0,
        y,
        x,
        y + height,
        x + width,
    )


# FIX: remove or find a use
def getMaxlen(sessions: list[str]) -> int:
    maxlen = 0
    for i in sessions:
        maxlen = maxlen if len(i) < maxlen else len(i)
    return maxlen


def getSessions() -> list[str]:
    list_command = ["tmux", "ls"]
    sessions = subprocess.check_output(list_command, shell=False)
    sessions = sessions.decode()
    sessions = sessions.split("\n")
    return sessions


def createSession(starting_directory: str, session_name=None) -> None:
    session_name = (
        starting_directory.split("/")[-1].strip()
        if session_name == None
        else session_name
    )
    if session_name + ":" in " ".join(getSessions()):
        return

    new_session_command = [
        "tmux",
        "new-session",
        "-A",
        "-c",
        starting_directory,
        "-s",
        session_name,
        "-d",
    ]
    attach_session_command = [
        "tmux",
        "switch-client",
        "-t",
        session_name,
    ]
    try:
        subprocess.run(new_session_command, shell=False)
        subprocess.run(attach_session_command, shell=False)
        quit()

    except subprocess.CalledProcessError:
        pass


def switchSession(session_name: str) -> None:
    switch_session_command = [
        "tmux",
        "switch-client",
        "-t",
        session_name,
    ]
    try:
        subprocess.run(switch_session_command, shell=False)
        quit()
    except subprocess.CalledProcessError:
        pass


def killSession(session_name: str) -> None:
    kill_session_command = ["tmux", "kill-session", "-t", session_name]
    subprocess.run(kill_session_command)


wrapper(main)
