#search operations

#search 1&2-
#2&6

def linear_search(arr,n,key):
    for i in range (n):
        if arr[i]==key:
            print("value found at -")
            return i
    print("not found")


def fib_search(arr,n,key):
    n=len(arr)
    fib2=0
    fib1=1
    fib=fib1+fib2
    while fib<n:
        fib2=fib1
        fib1=fib
        fib=fib1+fib2

    i=0
    offset=-1
    while fib>1:
        i=min(offset+fib2,n-1)
        if key<arr[i]:
           fib=fib2
           fib1=fib1-fib2
           fib2=fib-fib1
        elif key>arr[i]:
            fib=fib1
            fib1=fib2
            fib2=fib-fib1
            offset=i
        else:
            print("value found at ")
            return i
    return False
    print("not found")

def sentinal_search(arr2,n,key):
    arr2.append(key)
    i=0
    while arr2[i]!=key:#MENTION i
        i+=1
    if i<n:
       print(f"Value found at position {i + 1}")
       return i+1
    else :
        return -1

def binary_search(arr,n,key):
    f,l=0,n-1
    while f<=l:
        mid=(f+l)//2
        if arr[mid]==key:
            mid=mid+1
            return mid
            print("found")
        elif arr[mid]<key:
            f=mid+1
        else:
            l=mid-1
    print("not found")
    return -1 

n=int(input("enter the no. of students in training program "))
arr=eval(input("enter the list of roll nos of students"))
#key=int(input("enter the rollno to be searched "))

while True:
    print("1.Linear Search")
    print("2. fibonacci  Search")
    print("3. sentinal  Search")
    print("4. binary  Search")
    print("5. exit Search")
    
    key=int(input("enter the rollno to be searched "))
    option=int(input("enter the search algorithm you wish to use "))
    
    if option==1:
       print(linear_search(arr,n,key))
    elif option==2:
       print(fib_search(arr,n,key))
    elif option==3:
       print(sentinal_search(arr,n,key))
    elif option==4:
       print(binary_search(arr,n,key))
    else:
        print("bye")
        break 

    
