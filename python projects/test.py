##def chksum(A,size,x):
A=[1,3,5,7,9]
x=12
size=len(A)
for i in range(0,size-1):
    for j in range (i+1,size):
        if (A[i]+A[j]==x):
            print(A[i],A[j])
##matrix=[[5,21,1,2],[2,30,1,5],[1,10,3,1]]
##nr=3
##nc=4
##r=0
##c=0
##while r<nr and c<nc:
##    pv=matrix[r][c]
##    for j in range(nr):
##        matrix[j][c]=matrix[j][c]/pv
##        for o in range(nc):
##            makezero=matrix[c][o]
##            if o==r:
##                continue
##            for k in range(nr):
##                matrix[k][o]=matrix[k][o]-makezero*matrix[r][k]
##    c=c+1
##    r=r+1
##print(matrix)
# Python3 Implementation for Gauss-Jordan
# Elimination Method
M = 10
 
# Function to print the matrix
def PrintMatrix(a, n):
    for i in range(n):
        print(*a[i])
 
# function to reduce matrix to reduced
# row echelon form.
def PerformOperation(a, n):
    i = 0
    j = 0
    k = 0
    c = 0
    flag = 0
    m = 0
    pro = 0
 
    # Performing elementary operations
    for i in range(n):
        if (a[i][i] == 0):
 
            c = 1
            while ((i + c) < n and a[i + c][i] == 0):
                c += 1
            if ((i + c) == n):
 
                flag = 1
                break
 
            j = i
            for k in range(1 + n):
 
                temp = a[j][k]
                a[j][k] = a[j+c][k]
                a[j+c][k] = temp
 
        for j in range(n):
 
            # Excluding all i == j
            if (i != j):
                # Converting Matrix to reduced row
                # echelon form(diagonal matrix)
                p = a[j][i] / a[i][i]
 
                k = 0
                for k in range(n + 1):
                    a[j][k] = a[j][k] - (a[i][k]) * p
 
    return flag
 
# Function to print the desired result
# if unique solutions exists, otherwise
# prints no solution or infinite solutions
# depending upon the input given.
def PrintResult(a, n, flag):
 
    print("Result is : ")
 
    if (flag == 2):
        print("Infinite Solutions Exists<br>")
    elif (flag == 3):
        print("No Solution Exists<br>")
 
    # Printing the solution by dividing constants by
    # their respective diagonal elements
    else:
        for i in range(n):
            print(a[i][n] / a[i][i], end=" ")
 
# To check whether infinite solutions
# exists or no solution exists
def CheckConsistency(a, n, flag):
 
    # flag == 2 for infinite solution
    # flag == 3 for No solution
    flag = 3
    for i in range(n):
        sum = 0
        for j in range(n):
            sum = sum + a[i][j]
        if (sum == a[i][j]):
            flag = 2
 
    return flag
 
# Driver code
a = [[3,1,1,10],  [1,5,2,21],   [1,2,5,30]]
 
# Order of Matrix(n)
n = 3
flag = 0
 
# Performing Matrix transformation
flag = PerformOperation(a, n)
 
if (flag == 1):
    flag = CheckConsistency(a, n, flag)
 
# Printing Final Matrix
print("Final Augmented Matrix is : ")
PrintMatrix(a, n)
print()
 
# Printing Solutions(if exist)
PrintResult(a, n, flag)
 
# This code is contributed by phasing17
M=[[3,1,1,10],[1,5,2,21],[1,2,5,30]]
nr=3
nc=4
pr=0
pc=0
while pr>=0 and pc>=0:
    pr=int(input("Enter pivot row: "))
    pc=int(input("Enter: "))
    pe=M[pr][pc]
    for c in range(nc):
        M[pr][c]=M[pr][c]/pe
    for r in range (nr):
        makezero=M[pc][r]
        if r==pr:
            continue
        for c in range(nc):
            M[r][c]=M[r][c]-makezero*M[pr][c]
print(M)
    
    



