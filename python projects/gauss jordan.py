nr=int(input("Enter the number of rows: "))
nc=int(input("Enter th number of columns: "))
matrix=[]
for r in range (nr):
    a=[]
    for c in range(nc):
        num=int(input("Enter the number of elements row wise: "))
        a.append(num)
    matrix.append(a)
print("X1\tX2\tX3\tRHV")
for i in (matrix):
    for j in (i):
        print (j,end='        ')
##FOR NEW LINE
    print()
r=0
c=0
while r<nr and c<nc:
    pv=matrix[r][c]
    for j in range(nr):
        matrix[j][c]=matrix[j][c]/pv
    for o in range(nc):
        makezero=matrix[c][o]
        if o==r:
            continue
        for k in range(nr-1):
            matrix[k][o]=matrix[k][o]-makezero*matrix[r][k]
    c=c+1
    r=r+1
for c in (matrix):
    for h in c:
        print(format(h,".1f"),end="\t")
    print()
