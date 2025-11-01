#find the factors of given number
a=int(input("Enter the num to find the factors"))
for i in range(1,a+1):
    if a%i==0:
        print(i)