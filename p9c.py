l1=list(input("Enter the words").split(","))
for i in l1:
    w=lambda l1:l1 if len(l1[i])<5 else print("")
print(w)
