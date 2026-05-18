n=input("Enter the value of n: ")
for i in range(n):
    print("|"+" "*(n-1)+"/"+" "*(i*2)+"\\"+" "*(n-1)+"|")
    n-=1