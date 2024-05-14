nf = int(input("Enter no of frames:\n"))
np = int(input("Enter no of page references:\n"))
pages = []
print("Enter page references:")
for i in range(np):
    pages.append(int(input()))

def fifo(nf,np,pages):
    frames = [-1] * nf
    hit = 0
    fault = 0

    def print_frame():
        for k in range(nf):
            if frames[k] == -1:
                print("-\t", end="")
            else:
                print("%d\t" % frames[k], end="")
        print()

    # printing header
    for i in range(nf):
        print("F%d\t" % (i+1), end="")
    print()

    for i in range(np):
        if pages[i] in frames:
            hit += 1
            print_frame()
        else:
            for j in range(nf):
                if frames[j] == -1:
                    fault += 1
                    frames[j] = pages[i]
                    print_frame()
                    break
            else:
                fault += 1
                frames.pop(0)
                frames.append(pages[i])
                print_frame()

    print("Number of Page Faults:%d" % fault)
    print("Number of Page Hits:%d" % hit)
    re1=hit/(fault+hit)
    print(re1*100)
    
    
def LRU(nf,np,pages):
    frames = [-1] * nf
    hit = 0
    fault = 0
    

    def find_lru(i):
        point=[-1]*nf
        for j in range(nf):
            for k in range(i):
                if(frames[j]==pages[k]):
                    point[j]=k
        lru = pages[min(point)]
        return lru

    def print_frame():
        for k in range(nf):
            if frames[k] == -1:
                print("-\t", end="")
            else:
                print("%d\t" % frames[k], end="")
        print()

    # printing header
    for i in range(np):
        if pages[i] in frames:
            hit += 1
            print_frame()
        else:
            if pages[i] not in frames:
                fault += 1
                for j in range(nf):
                    if frames[j] == -1:
                        frames[j] = pages[i]
                        break
                else:
                    lru = find_lru(i)
                    frames[frames.index(lru)] = pages[i]
                    
                print_frame()
            else:
                print_frame()

    print("Number of Page Faults:%d" % fault)
    print("Number of Page Hits:%d" % hit)
    re2=hit/(fault+hit) 
    print(re2*100)



def opt(nf, np, pages):
    fr = []
    count = []
    fault = 0
    hit = 0
    dist = 0
    k = 0
    for i in range(nf):
        count.append(0)
        fr.append(-1)

    for i in range(np):
        flag = 0
        temp = pages[i]
        for j in range(nf):
            if temp == fr[j]:
                flag = 1
                hit += 1  # Increment hit if page is found in frame
                break
        if flag == 0 and k < nf:
            fault += 1
            fr[k] = temp
            k += 1
        elif flag == 0 and k == nf:
            fault += 1
            for cnt in range(nf):
                current = fr[cnt]
                for c in range(i, np):
                    if current != pages[c]:
                        count[cnt] += 1
                    else:
                        break
            max_count = 0
            for m in range(nf):
                if count[m] > max_count:
                    max_count = count[m]
                    p = m
            fr[p] = temp
        print("\npage  %d  frame\t" % pages[i], end="")
        for x in range(nf):
            print("%d\t" % fr[x], end="")
    
    print("\nNumber of Page Faults:", fault)
    print("Number of Page Hits:", hit)
    re3=hit/(fault+hit)
    print(re3*100)

print("FIFO")           
fifo(nf,np,pages)
print("LRU")
LRU(nf,np,pages)
print("OPTIMAL")
opt(nf, np, pages)