from urllib import request
##def downloadimg(completeurl,path):
##    img=request.urlopen(completeurl)
##    imgasbytes=img.read()
##    imgfile=open(path,"wb")
##    imgfile.write(imgasbytes)
##    imgfile.close()
URL="http://olympus.realpython.org/profiles/dionysus"
conn=request.urlopen(URL)
asbytes=conn.read()
html=asbytes.decode("cp1252")
f=open("HELLO.html","w")
f.write(html)
f.close()
ep=-1
p=html.find("<img",ep+1)
i=1
print(html)
while (p>0) :
    sp=html.find('"',p+1)+1
    ep=html.find('"',sp+1)
    compurl=html[sp:ep]
    p=html.find("<img",ep+1)
    offsite=compurl.startswith("http")
    if offsite:
        completeurl=compurl
    else:
        bep=URL.find("/",8)
        url=URL[:bep]
        completeurl=url+compurl
        print(completeurl)
##        path="C:\Users\Home\Downloads\images"+str(i)+"jpg"
##        downloadimg (completeurl,path)
##    i=1+1



