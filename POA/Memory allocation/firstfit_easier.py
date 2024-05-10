memno=int(input("Enter memory number: "))
prono=int(input("Enter process number: "))

pr=[]
mem=[]
prfilled=[]
memfilled=[]


for i in range(memno):
    mem.append(int(input("Memory space")))
    memfilled.append(0)

for i in range(prono):
    pr.append(int(input("Process space")))
    prfilled.append(0)

print(pr)
print(mem)

for i in range(len(pr)):
    for j in range(len(mem)):
        if(pr[i]<=mem[j] and memfilled[j]!=1):
            print("Allocated",pr[i], "at", mem[j])
            memfilled[j]=1
            break

