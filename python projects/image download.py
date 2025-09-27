from urllib.request import urlopen
baseurl="http://olympus.realpython.org/profiles/dionysus"
conn=urlopen(baseurl)
htmlbytes=conn.read()
try:
    f=open("HELLO.html","w")
    html=htmlbytes.decode("cp1252")
except:
    html=html.bytes.decode()
html=html.replace("","")
a=html.find("<img")
while a!=0:
    b=html.find("src= ",a)+len('src=""')
    c=html.find("",b)
    link=html[b:c]
    if not link.startswith("src="):
        link=baseurl+link
        f.write(link+"\n")
        print(link)
        a=html.find("<img",c)
        webconn=urlopen(link)
        img=webconn.read()
        f=open("C:\\Users\\Home\\Downloads\\images.jpeg","wb")
        f.write(img)
        f.close()
