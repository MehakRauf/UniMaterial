import tkinter
import turtle

t=turtle.Pen()
turtle.bgcolor('dimgrey')
sides = 4
colors=['pink', 'black', 'blue', 'salmon', 'green', 'red']
j = 350

for x in range(j):
     t.pencolor(colors[x%sides])
     t.width(x*sides/200)
     t.forward(x*3/sides +x)
     t.left(j/sides+1)

forward(100)
ts = turtle.getscreen()
ts.getcanvas().postscript(file="NiceHexSpiral.eps")
