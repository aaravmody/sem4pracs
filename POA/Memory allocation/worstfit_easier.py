memno=int(input("Enter memory number: "))
prono=int(input("Enter process number: "))

pr=[]
mem=[]


for i in range(memno):
    mem.append(int(input("Memory space")))


for i in range(prono):
    pr.append(int(input("Process space")))

mem.sort(reverse=True)
print(pr)
print(mem)

for i in range(len(pr)):
    for j in range(len(mem)):
        if(pr[i]<=mem[j]):
            print("Allocated",pr[i], "at", mem[j])
            mem[j]=0
            break

