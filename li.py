#finding sum of elements in a list..
a=list(map(int,input("Enter the list of elements").split(" ")))
sum=0
for x in a:
    sum+=x
print("sum =",sum)