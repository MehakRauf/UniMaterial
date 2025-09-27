m=[[-1000,-600,0,0,0],[5,4,1,0,20],[4,-2,0,1,10]]
def changer():
    for i in range(len(m)):
        for j in range(len(m[0])):
            print("{:.2f}",format(m[i][j]),end='\t')
        print()
for p in m[0]:
    changer()
    if p <0:
        print("------------------------")
        obj=m[0]
        pc=obj.index(min(obj))
##        print(pc)
        rows=len(m)
        cols=len(m[0])
        minr=0
        for k in range (1,rows):
            rhv=m[k][cols-1]
            if not (m[k][pc]>0):
                continue
            ratio=rhv/m[k][pc]
            if not(minr):
                minr=ratio
            if (ratio<=minr):
                minr=ratio
                pr=k
    pe=m[pc][pr]
    for c in range(cols):
        m[pr][c]=m[pr][c]/pe
    for r in range(rows):
        if r==pr:
            continue
        makezero=m[pc][r]
        for c in range(cols):
            m[r][c]=m[r][c]-(makezero*m[pr][c])
            print (m)
