#sorting
#7&16

def selection_sort(arr):
    n=len(arr)
    for i in range(n-1):
        min=i
        for j in range(i+1,n):
            if (arr[j]<arr[min]):
                min=j
    
        arr[i],arr[min]=arr[min],arr[i]
                
        print(f"Iteration {i + 1}: {arr}")
    #return arr

def bubble_sort(arr):
    n=len(arr)
    for i in range(n-1):
        for j in range(n-1-i):
            if(arr[j]>arr[j+1]):
                arr[j],arr[j+1]=arr[j+1],arr[j]
        print(f"Iteration {i + 1}: {arr}")
    return arr

def insertion_sort(arr):
    n = len(arr)
    for i in range(1, n):
        key = arr[i]
        j = i - 1
        while j >= 0 and arr[j] > key:
             arr[j + 1] = arr[j]
             j -= 1
        arr[j + 1] = key
        print(f"Iteration {i + 1}: {arr}")

def shell_sort(arr2,n):
    gap=n//2
    iteration=0
    while gap>0:
        j=gap
        while j<n:
            i=j-gap
            while i>=0:
                if arr2[i+gap]>arr2[i]:
                    break
                else:
                    arr2[i+gap],arr2[i]=arr2[i],arr2[i+gap]
                i=i-gap
            j+=1
        iteration += 1
        print(f"Iteration {i + 1}: {arr}")
        gap//=2
    

n=int(input("enter the no of students "))
arr=eval(input("enter the marks of students "))

print("og arr")
print(arr)
shell_sort(arr,n)
print("sorted array")
print(arr)








      
         