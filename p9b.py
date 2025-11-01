a=int(input("Enter the number to check:"))
w=lambda a:print("yes") if not a%5 else print("no")
print(w(a))