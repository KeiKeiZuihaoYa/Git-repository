def DC_sort(a,l,r):
    if l >= r:
        return

    left = l
    right = r
    mid = a[l]

    while left < right:
        while left < right and a[right] >= mid:
            right -= 1
        a[left] = a[right]
        while left < right and a[left] <= mid:
            left += 1
        a[right] = a[left]

    a[left] = mid
    DC_sort(a,l,left-1)
    DC_sort(a,right+1,r)

num = int(input())
a = []
for i in range(num):
    a.append(int(input()))

DC_sort(a, 0, num - 1)
print(f"max1={a[num - 1]} max2={a[num - 2]}")