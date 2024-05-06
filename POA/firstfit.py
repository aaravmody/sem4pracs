space = []
insert = []
n=0

n=int(input("N"))
for i in range(n):
    space.append(int(input("Enter space: ")))
for i in range(n):
    insert.append(int(input("Enter space: ")))

for i in insert:
    for j in range(space):
        if(i<space[j]):
            print("inserted",i,"at",space[j])
        space[j]-=i
        break
    if j==len(space)-1:
        print("cannot insert")
