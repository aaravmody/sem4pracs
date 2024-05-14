#bhavya mehta ne kiya hai

def FIFO(frames, pages):
        f = [-1] * frames
        hits = 0 
        miss = 0
        k = 0
        for page in pages:
            if page in f:
                hits += 1
            else:
                miss += 1
                f[k] = page
                k = (k + 1) % frames
            print(f"Frames:{f}")
        return hits, miss

def LRU(frames, pages):
        f = [-1] * frames
        hits = 0 
        miss = 0
        recent = []
        for page in pages:
            if page in f:
                hits += 1
                recent.remove(page)
                recent.append(page)
            else:
                miss += 1
                if -1 in f:
                    index = f.index(-1)
                    f[index] = page
                    recent.append(page)
                else:
                    lru_page = recent[0]
                    lru_index = f.index(lru_page)
                    f[lru_index] = page
                    recent.remove(lru_page)
                    recent.append(page)
            print(f"Frames:{f}")
        return hits, miss

def farthest_index(f,pages, startindex):
        farthest_index = -1
        farthest_dist = -1
        for i, page in enumerate(f):
            if page not in pages[startindex:]:
                return i
            else:
                distance = pages[startindex:].index(page)
                if distance > farthest_dist:
                    farthest_dist = distance
                    farthest_index = i
        return farthest_index

def Optimal(frames, pages):
        f = [-1]*frames
        hits = 0
        miss = 0
        for i, page in enumerate(pages):
            if page in f:
                hits += 1
            else:
                miss += 1
                if -1 in f:
                    index = f.index(-1)
                    f[index] = page
                else:
                    replace_index = farthest_index(f,pages,i)
                    f[replace_index] = page
            print(f"Frames:{f}")
        return hits, miss

frames = int(input("Enter the number of frames: "))
pages = input("Enter pages separated by commas: ").split(',')
pages = [int(x) for x in pages]
hits, miss = FIFO(frames, pages)
print("FIFO\n")
print(f"Hits: {hits}, Miss: {miss}")
print("LRU\n")
hits1, miss1 = LRU(frames, pages)
print(f"Hits: {hits1}, Miss: {miss1}")
print("Optimal\n")
hits2, miss2 = Optimal(frames, pages)
print(f"Hits: {hits2}, Miss: {miss2}")