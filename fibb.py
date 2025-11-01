n=int(input("Enter the number : "))
x=0
y=1
for i in range(2,n):
    x,y=y,x+y
print("nth element is ",y)
print("series is ....")
a=0
b=1
print(a,end=" ")
print(b,end=" ")
for i in range(2,n):
    a,b=b,a+b
    print(b,end=" ")