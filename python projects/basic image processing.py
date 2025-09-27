import struct
def getnew(value):
    if value >255:
        returnvalue= 255
    if value<0:
        returnvalue= 1
    else:
        returnvalue= value
    return returnvalue
file=open("img.bmp", "rb")
ofile=open("imgcopy.bmp","r+b")
file.seek(18,0)
w=file.read(4)
width=struct.unpack("i",w)
h=file.read(4)
height=struct.unpack("i",h)
print("The width of the image is: ",width)
print("The height of the image is: ",height)
file.seek(10,0)
o=file.read(4)
offset=struct.unpack("i",o)
ofile.seek(offset[0],0)
brightness=100
for y in range(0,height[0],1):
    for x in range (0,width[0],1):
        b=file.read(1)
        b=b[0]
        value=b+brightness
        b=getnew(value)
        r=file.read(1)
        r=r[0]
        value=r+brightness
        r=getnew(value)
        g=file.read(1)
        g=g[0]
        value=g+brightness
        g=getnew(value)
        bout=int.to_bytes(b,1,"little")
        gout=int.to_bytes(g,1,"little")
        rout=int.to_bytes(r,1,"little")
        ofile.write(bout)
        ofile.write(gout)
        ofile.write(rout)
outfile.close()
file.close()
print("process")
