l = [14, 17, 53, 35, 9, 37, 68, 21, 46]
N = len(l)
for i in range(N - 1):
    for j in range(N - i -1):
        if l[j + 1] < l[j]:
            l[j+1], l[j] = l[j], l[j+1]
    print(l)



