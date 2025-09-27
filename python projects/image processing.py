import struct
from copy import deepcopy

def tokeepinrange(x):
    if x>255:
        return 255
    if x<0:
        return o
    else:
        return x
inputimg=open("img.bmp", "rb")
outputimg=open("imgcopy.bmp","rb+")
inputimg.seek(18,0)
w=inputimg.read(4)
width=struct.unpack("i",w)
print("the width of the image is: ",width)
h=inputimg.read(4)
height=struct.unpack("i",h)
print ("the height of the image is: ",h)
inputimg.seek(10,0)
o=inputimg.read(4)
offset=struct.unpack("i",o)
inputimg.seek(offset[0],0)
outputimg.seek(offset[0],0)
matrix=[[],[],[]]
for y in range (height[0]):
    smatrix=[[],[],[]]
    for x in range (width[0]):
        for i in range (3):
            pix=inputimg.read(1)[0]
            smatrix.append[i](pix)
    for i in range (3):
        matrix[i].append(smatrix[i])
def conkernel(matrix1):
     kernel=[[1/9,1/9,1/9],[1/9,1/9,1/9],[1/9,1/9,1/9]]#BLUR
##    kernel=[[-1,-1,-1],[-1,8,-1],[-1,-1,-1]]#EDGE DETECTION CORNER DIAGONAL COUNTEd
##    kernel=[[0,-1,0],[-1,4,-1],[0,-1,-1]]#EDGE DETECTION
##    kernel=[[1/16,2/16,1/16],[2/16,4/16,2/16],[1/16,2/16,1/16]]#GAUSSIA BLUR
##    kernel=[[0,0,0],[0,1,0],[0,0,0]]#IDENTITY
##    kernel=[[0,-1,0],[-1,5,-1],[0,-1,0]]#SHARP
##    kernel=[[-1,0,0],[0,0,0],[0,0,1]]#EMBOSSING
    
     Kernel = [[0,0,0],[0,1,0],[0,0,0]]
     CopyMatrix = deepcopy(matrix1)
     for y in range(height[0]):
        for x in range(width[0]):
            sum = 0
            for i in range(3):
                for j in range(3):
                   if ((y+i-1) < 0) or ((y+i-1) > height[0]-1) or ((x+j-1) < 0) or ((x+j-1) > width[0] -1 ):
                       sum += 0
                   else :
                        sum += CopyMatrix[y+i-1][x+j-1]*kernel[i][j]
            matrix1[y][x]= keepinrange(sum)
        return matrix1

def grey(x):
    x = x//3
    return x

def bright(x):
    x = keepinrange(int(x+50))
    return x

def changeContrast(x):
    cont = 22
    x = ((((x/255)-0.5)*cont)+0.5)*255
    return keepinrange(int(x))

def grey(x):
    return(x//3)

def negative(x):
    return(255-x)

for i in range(1):

    BlueMatrix =ConvoK(matrix[0])
    GreenMatrix= ConvoK(matrix[1])
    RedMatrix= ConvoK(matrix[2])

for y in range(height[0]):
    for x in range(width[0]):

        BlueElements = BlueMatrix[y][x]
        GreenElements = GreenMatrix[y][x]
        RedElements = RedMatrix[y][x]

        # BlueElements = grey(BlueMatrix[y][x])
        # GreenElements = grey(GreenMatrix[y][x])
        # RedElements = grey(RedMatrix[y][x])

        # BlueElements = bright(BlueMatrix[y][x])
        # GreenElements = bright(GreenMatrix[y][x])
        # RedElements = bright(RedMatrix[y][x])
    
        # BlueElements = changeContrast(BlueMatrix[y][x])
        # GreenElements = changeContrast(GreenMatrix[y][x])
        # RedElements = changeContrast(RedMatrix[y][x])

        # BlueElements = negative(BlueMatrix[y][x])
        # GreenElements = negative(GreenMatrix[y][x])
        # RedElements = negative(RedMatrix[y][x])

        BlueBytes = int(BlueElements).to_bytes(1,'little')
        GreenBytes = int(GreenElements).to_bytes(1,"little")
        RedBytes = int(RedElements).to_bytes(1,"little")

        Out_file.write(BlueBytes)
        Out_file.write(GreenBytes)
        Out_file.write(RedBytes)
print("IMAGE HAS BEEN FILTERED....")
inputimg.close()
uotputimg.close()
   

   
