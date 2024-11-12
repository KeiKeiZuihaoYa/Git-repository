def DC_sum(a, l, r):
    tot = 0
    if l >= r:
        return a[l]
    
    mid = (l+r)//2
    tot += DC_sum(a, l, mid)
    tot += DC_sum(a, mid+1, r)

    return tot

num = int(input())
a = []
for i in range(num):
    a.append(int(input()))

print(f"求和为:{DC_sum(a, 0, num-1)}")