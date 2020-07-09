nm = input().split()
N = int(nm[0])
M = int(nm[1])
Aset=[]
for i in range(N):
    Aset.append(input())
Bset=[]
for i in range(M):
    Bset.append(input())
Cset=Aset+Bset
Dset=list(set(Cset))

print(len(Cset)-len(Dset))