frameno = int(input("Enter total number of frames: "))
pageno = int(input("Enter total number of pages: "))
pages = []
frames = [-1] * frameno
hit = 0
miss = 0

for i in range(pageno):
    pages.append(int(input("Enter page: ")))

print("Pages:", pages)

def find_lru(i):
        point=[-1]*frameno
        for j in range(frameno):
            for k in range(i):
                if(frames[j]==pages[k]):
                    point[j]=k
        lru = pages[min(point)]
        return lru

def print_frame():
    for k in range(frameno):
        if frames[k] == -1:
            print("-\t", end="")
        else:
            print("%d\t" % frames[k], end="")
    print()

for i in range(pageno):
        if pages[i] in frames:
            hit += 1
            print_frame()
        else:
            if pages[i] not in frames:
                miss += 1
                for j in range(frameno):
                    if frames[j] == -1:
                        frames[j] = pages[i]
                        break
                else:
                    lru = find_lru(i)
                    frames[frames.index(lru)] = pages[i]
                    
                print_frame()
            else:
                print_frame()

print("Number of Page Faults:%d" % miss)
print("Number of Page Hits:%d" % hit)
re2=hit/(miss+hit) 
print(re2*100)
