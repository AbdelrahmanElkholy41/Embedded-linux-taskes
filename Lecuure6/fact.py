from tkinter import *
root=Tk()
def fact():
    r=1
    n=value.get()
    for i in range(1,n+1):
        r*=i
    print(r)

root.geometry("500x500")
value=IntVar()

t=Entry(root,width=30,borderwidth=5, textvariable=value)
t.pack()

name_label = Label(root, text="Number")
name_label.pack()

Button=Button(root,width=30,command=fact,text="fact")
Button.pack()

root.mainloop()