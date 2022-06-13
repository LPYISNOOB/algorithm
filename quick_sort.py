def quick_sort(lst, left, right):
    if left >= right:
        return
    l, r, key = left, right, lst[left]
    while l < r:
        while l < r and lst[r] >= key:
            r -= 1
        lst[l] = lst[r]
        while l < r and lst[l] < key:
            l += 1
        lst[r] = lst[l]
    lst[l] = key
    quick_sort(lst, left, l - 1)
    quick_sort(lst, l + 1, right)
    return lst

a = input("shuru")
arr = [int(n) for n in a.split()]
quick_sort(arr,0,len(arr)-1)
print(arr)
