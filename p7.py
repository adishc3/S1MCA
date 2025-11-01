def oe(l1,o,e):
    for i in range(len(l1)):
        if l1[i]%2:o+=1
        else:e+=1
    print("odd=",o,"even=",e)



l1=list(map(int,input("Enter the numbers...").split(",")))
o=e=0
print(oe(l1,o,e))
