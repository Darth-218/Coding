from tkinter import ttk, Tk, IntVar

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

positions_label = ttk.Label(mainframe, text="Position", padding="5 12 5 12")
positions_box = ttk.Combobox(mainframe, values=("Left", "Down", "Up", "Right"))
position_equiv = {"Right": '--right-of', "Left": '--left-of', "Down": '--below', "Up": '--top'}

confirm_button = ttk.Button(mainframe, text="Save Configuration")
confirm_run_button = ttk.Button(mainframe, text="Save Configuration and Run")
run_button = ttk.Button(mainframe, text="Run Current Configuration")

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
confirm_button.grid(row=4, column=0, columnspan=2)

root.mainloop()

class methods:
    pass
