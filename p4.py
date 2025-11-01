def ev(l1):
    for i in range(len(l1)):
        if l1[i]==237:break
        elif not l1[i]%2:
            print(l1[i])
l1=list(map(int,input("Enter the numbers:").split(",")))
print(ev(l1))