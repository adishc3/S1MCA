def rev(l):
    if not len(l):return''
    else:return l[-1]+" "+rev(l[:-1])

l=input("Enter the name")
print(rev(l))