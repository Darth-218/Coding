from tkinter import ttk, Tk, IntVar
import os

root = Tk()
root.title("VNC Configuration")
root.attributes("-type", "dialog")

mainframe = ttk.Frame(root, padding="5 5 5 5")
mainframe.grid(row=0, column=0)

dimensions_label = ttk.Labelframe(mainframe, text="Dimensions", padding="5 5 5 5")

width = height = refresh_rate = IntVar()

width_label = ttk.Label(dimensions_label, text="Width:")
height_label = ttk.Label(dimensions_label, text="Height:")
refresh_rate_label = ttk.Label(dimensions_label, text="Refresh Rate:")

width_entry = ttk.Entry(dimensions_label, textvariable=width)
height_entry = ttk.Entry(dimensions_label, textvariable=height)
refresh_rate_entry = ttk.Entry(dimensions_label, textvariable=refresh_rate)

positions_label = ttk.Label(mainframe, text="Position", padding="5 10 5 10")
positions_box = ttk.Combobox(mainframe, values=("Left", "Down", "Up", "Right"))
position_equiv = {"Right": '--right-of', "Left": '--left-of', "Down": '--below', "Up": '--top'}

confirm_button = ttk.Button(mainframe, text="Save Configuration")
confirm_run_button = ttk.Button(mainframe, text="Save Configuration and Run")
run_button = ttk.Button(mainframe, text="Run Saved Configuration")

dimensions_label.grid(row=0, column=0, columnspan=2)

width_label.grid(row=1, column=0)
height_label.grid(row=1, column=1)
refresh_rate_label.grid(row=1, column=2)

width_entry.grid(row=2, column=0)
height_entry.grid(row=2, column=1)
refresh_rate_entry.grid(row=2, column=2)

positions_label.grid(row=2, column=0)
positions_box.grid(row=2, column=1)

run_button.grid(row=3, column=0)
confirm_run_button.grid(row=3, column=1)
confirm_button.grid(row=4, column=0, columnspan=2, pady=10)

root.mainloop()

# f"notify-send --app-name=\"Use Android as Monitor\" \"Details For VNC\" \"1) IP Address: `ifconfig | grep inet | grep broadcast | awk 'NR==1{{print $2}}' | tr -d \\n`\\n2) VNC Password: {confirm_pass}\\n3) Port (optional): 5900\\n Please run 'Close VNC' to turn the monitor off.\"",

def writeScript(width, height, rate, position):
    modeline = os.popen(f'cvt {width} {height} {refresh_rate} | grep "Modeline" | cut -d " " -f2-').read()
    resolution = modeline.split('"')[1]
    current_output = os.popen("xrandr --listmonitors | awk '{print $4}'").read().split()[0]
    output = os.popen("xrandr | grep 'disconnected' | awk 'NR==1{print $1; exit}'").read().split()[0]

    lines = [
        "#!/bin/bash",
        f'xrandr --newmode {modeline}',
        f"xrandr --addmode {output} {resolution}",
        f"xrandr --output {output} --mode {resolution} {position} {current_output}",
        "adb reverse tcp:5900 tcp:5900",
        f"x11vnc -rfbauth ~/.vnc/passwd -clip xinerama1"
    ]

    with open("~/.local/bin/vnc", "w") as file:
        file.writelines(lines)
