n=int(input("Enter the number to find factorial"))
fact=1
if n==0:
    print(1)
elif n==1:
    print(1)
elif n<0:
    print("Negative number...")
else:
    for i in range(2,n+1):
        fact=fact*i
    print(fact)
