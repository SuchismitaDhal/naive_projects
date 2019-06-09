from tkinter import *
import parser

######################### BASIC FUNCTIONALITY #########################

i = 0


def get_variables(num):
    #get the user input and place in the text field
    global i
    display.insert(i, num)
    i += 1
    #If a function contains any assignments to a variable,
    #it is treated by default as a local variable. Thus we have to declare
    # i as a global variable


def get_operator(op):
    global i
    l = len(op)
    display.insert(i, op)
    i += l


def clear_all():
    display.delete(0, END)
    # first index is deleted and last is kept


def clear_last():
    inpt = display.get()
    l = len(inpt)
    if (l > 0):
        display.delete(l - 1, l)


######################### MATHEMATICAL FUNCTIONALITY #########################


def calc():
    expxn = display.get()
    try:
        a = parser.expr(expxn).compile()
        result = eval(a)
        clear_all()
        display.insert(0, result)

    except Exception:
        clear_all()
        display.insert(0, "ERROR")


######################### INTERFACE #########################

root = Tk()
root.title('Calculator')

#adding the input field
display = Entry(root)
display.grid(row=1, columnspan=6, sticky=W + E)

#adding buttons to the calculator
Button(root, text="1", command=lambda: get_variables(1)).grid(row=2, column=0)
Button(root, text="2", command=lambda: get_variables(2)).grid(row=2, column=1)
Button(root, text="3", command=lambda: get_variables(3)).grid(row=2, column=2)

Button(root, text="4", command=lambda: get_variables(4)).grid(row=3, column=0)
Button(root, text="5", command=lambda: get_variables(5)).grid(row=3, column=1)
Button(root, text="6", command=lambda: get_variables(6)).grid(row=3, column=2)

Button(root, text="7", command=lambda: get_variables(7)).grid(row=4, column=0)
Button(root, text="8", command=lambda: get_variables(8)).grid(row=4, column=1)
Button(root, text="9", command=lambda: get_variables(9)).grid(row=4, column=2)

Button(root, text="AC", command=clear_all).grid(row=5, column=0)
Button(root, text="0", command=lambda: get_variables(0)).grid(row=5, column=1)
Button(root, text="=", command=calc).grid(row=5, column=2)

Button(root, text="+", command=lambda: get_operator('+')).grid(row=2, column=3)
Button(root, text="-", command=lambda: get_operator('-')).grid(row=3, column=3)
Button(root, text="*", command=lambda: get_operator('*')).grid(row=4, column=3)
Button(root, text="/", command=lambda: get_operator('/')).grid(row=5, column=3)

Button(root, text="pi", command=lambda: get_operator('3.1416')).grid(row=2,
                                                                     column=4)
Button(root, text="%", command=lambda: get_operator('%')).grid(row=3, column=4)
Button(root, text="(", command=lambda: get_operator('(')).grid(row=4, column=4)
Button(root, text="exp", command=lambda: get_operator('**')).grid(row=5,
                                                                  column=4)
# operator should be as used in python

Button(root, text="<-", command=clear_last).grid(row=2, column=5)
Button(root, text=".", command=lambda: get_operator('.')).grid(row=3, column=5)
Button(root, text=")", command=lambda: get_operator(')')).grid(row=4, column=5)
Button(root, text="^2", command=lambda: get_operator('**2')).grid(row=5,
                                                                  column=5)

root.mainloop()
