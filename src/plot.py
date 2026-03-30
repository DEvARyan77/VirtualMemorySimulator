import matplotlib.pyplot as plt

frames = []
fifo = []
lru = []
optimal = []

with open("results.txt") as f:
    for line in f:
        fsize, f, l, o = map(int, line.split())
        frames.append(fsize)
        fifo.append(f)
        lru.append(l)
        optimal.append(o)

plt.plot(frames, fifo, label="FIFO")
plt.plot(frames, lru, label="LRU")
plt.plot(frames, optimal, label="Optimal")

plt.xlabel("Frame Size")
plt.ylabel("Page Faults")
plt.title("Page Faults vs Frame Size")

plt.legend()
plt.show()