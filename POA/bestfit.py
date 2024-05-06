space = []
insert = []
n=0

n=int(input("N"))
for i in range(n):
    space.append(int(input("Enter space: ")))
for i in range(n):
    insert.append(int(input("Enter space: ")))

for i in insert:
    j=0
    while(j < len(space)):
        if(i<space[j]):
            break
        j+=1
    if j==len(space)-1:
        print("cannot insert")
    elif i<space[j]:
        print("inserted",i,"at",space[j])
        space[j]-=i
        space.sort()
