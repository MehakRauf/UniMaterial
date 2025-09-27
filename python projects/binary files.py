##import struct
##f= open('C:\\Users\\Home\\Desktop\\img.bmp','r')
##intbytes=f.read(1)
##k=struct.unpack("i",intbytes)
##print(intbytes)
##f.close()
import struct
import turtle
fpath="C:\\Users\\Home\\Desktop\\Untitled.bmp"
f=open(fpath,"rb")
print(f.read(1))
print(f.read(1))
print(f.read(4))
f.seek(18,0)
w=f.read(4)
width=struct.unpack("i",w)
wi=width[0]
h=f.read(4)
height=struct.unpack("i",h)
he=height[0]
f.seek(10,0)
o=f.read(4)
offset=struct.unpack("i",o)
f.seek(offset[0],0)
tr=turtle.Turtle()
tr.pensize(1)
sc=turtle.Screen()
sc.setup(width[0],height[0])
sc.colormode(255)
turtle.title(fpath)
turtle.speed(0)
for r in range(0,he,1):
    tr.sety(r)
    for c in range(0,wi,1):
        tr.setx(c)
        b=f.read(1)
        r=f.read(1)
        g=f.read(1)
        b=b[0]
        r=r[0]
        g=g[0]
        tr.color(b,r,g)
        tr.dot(size=2)
turtle.done()
f.close()
