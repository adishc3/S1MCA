a=int(input("Enter the first num:"))
b=int(input("enter the second number"))
max=lambda a,b:a if a>b else b
print("largest is",max(a,b))