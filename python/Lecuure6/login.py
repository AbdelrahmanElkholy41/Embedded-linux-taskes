import tkinter as tk
from tkinter import StringVar
from tkinter import Entry, Label



# Initialize the main window
root = tk.Tk()
root.geometry("500x500")

# Create StringVar instances
value = StringVar()
value1 = StringVar()

def login():
    print(value.get())
    print(value1.get())

# Create a label for the name field
name_label = Label(root, text="Name")
name_label.pack()

# Create Entry widget for the name with textvariable bound to StringVar instance
name = Entry(root, width=30, borderwidth=5, textvariable=value)
name.pack()

# Create a label for the password field
password_label = Label(root, text="Password")
password_label.pack()

# Create Entry widget for the password with textvariable bound to StringVar instance
password = Entry(root, width=30, borderwidth=5, textvariable=value1)
password.pack()

buttom=tk.Button(root,width=30,command=login,text="login")
buttom.pack()
# Run the main event loop
root.mainloop()
