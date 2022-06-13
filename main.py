# def merge_sort(array):
#     if len(array) == 1:
#         return array
#     left_array = merge_sort(array[:len(array)//2])
#     right_array = merge_sort(array[len(array)//2:])
#     merge_array = merge(left_array, right_array)
#     return merge_array
#
#
# def merge(left_array,right_array):
#     left_index,right_index = 0 , 0
#     result = list()
#     while left_index <= len(left_array) and right_index <= len(right_array):
#         if left_array(left_index) <= right_array(right_index):
#             result.append(left_array[right_index])
#             left_index += 1
#         else :
#             result.append(right_array[right_index])
#             right_index += 1
#     result += left_array[left_index:]
#     result += right_array[right_index:]
#     return result
#
# a = input("\n归并排序\n输入待排序数组：")
# array = [int(n) for n in a.split()]
# print(merge_sort(array))
def merge(left_arr, right_arr):

    left_index, right_index = 0, 0
    result = []
    while left_index < len(left_arr) and right_index < len(right_arr):
        if left_arr[left_index] < right_arr[right_index]:
            result.append(left_arr[left_index])
            left_index += 1
        else:
            result.append(right_arr[right_index])
            right_index += 1
    result += (left_arr[left_index:])
    result += (right_arr[right_index:])
    return result


def merge_sort(arr):
    if len(arr) <= 1:
        return arr

    mid = len(arr) // 2
    left_arr = merge_sort(arr[:mid])
    right_arr = merge_sort(arr[mid:])
    merge_arr = merge(left_arr, right_arr)
    return merge_arr

a = input("\n归并排序\n输入待排序数组：")
array = [int(n) for n in a.split()]
print(merge_sort(array))
