def quicksort(arr):
    if len(arr) <= 1:
        return arr
    pivot = arr[len(arr) // 2]  # Choose the middle element as the pivot

    # Using a for loop to filter elements less than the pivot
    left = []
    for x in arr:
        if x < pivot:
            left.append(x)

    # Using a for loop to filter elements equal to the pivot
    middle = []
    for x in arr:
        if x == pivot:
            middle.append(x)

    # Using a for loop to filter elements greater than the pivot
    right = []
    for x in arr:
        if x > pivot:
            right.append(x)
            
    ##print(f"Pivot: {pivot}")
    #print(f"Array after partitioning: {left + middle + right}\n")
    
    # Recursively sort the left and right subarrays and combine them
    sorted_left = quicksort(left)
    sorted_right = quicksort(right)
    
    # Show the array after sorting the left and right subarrays
    #print(f"Sorted left part: {sorted_left}")
    #print(f"Sorted right part: {sorted_right}")
    
    # Return the combined sorted array
    return sorted_left + middle + sorted_right

def display_top_five(arr):
    arr_sorted = quicksort(arr)
    top_five = arr_sorted[-5:][::-1] 
    print("Top 5 scores:", top_five)



arr = eval(input("enter the unsorted array "))
sorted_arr = quicksort(arr)
print("Sorted array:", sorted_arr)
display_top_five(arr)
