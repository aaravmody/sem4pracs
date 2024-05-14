frameno = int(input("Enter total number of frames: "))
pageno = int(input("Enter total number of pages: "))
pages = []
frames = [-1] * frameno
hit = 0
miss = 0

for i in range(pageno):
    pages.append(int(input("Enter page: ")))

print("Pages:", pages)

k = 0
for i in range(len(pages)):
    if pages[i] in frames:
        hit += 1
        print(f"Page {pages[i]}: Hit")
    else:
        miss += 1
        frames[k] = pages[i]
        print(f"Page {pages[i]} loaded into frame {k}")
        k = (k + 1) % frameno

print("Final frames:", frames)
print("Total hits:", hit)
print("Total misses:", miss)
