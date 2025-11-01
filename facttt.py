def fact(n):
    if n==0:return 0
    elif n==1:return 1
    else:return n*fact(n-1)

n=int(input("Enter the value to find the factorial"))
print("the factrial is .....",fact(n))