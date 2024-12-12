#set operations

#2
#set A cricket students
#set B badminton students
#set C football students

#intersection
def S1NS2(S1,S2):
    N=[]
    for i in S2:
        if (i in S1):
            N.append(i)
    return N

#union
def S1US2(S1,S2):
    U=[]
    for i in S1:
        U.append(i)
    for i in S2:
        if (i not in S1):
            U.append(i)
    return U

#difference 
def S1DS2(S1,S2):
    D=[]
    for i in S1:
        if (i not in S2):
            D.append(i)
    return D


tstudents=int(input("Enter the total no. of students in computer engineering class "))
a=eval(input("Enter the rollnos of students who play cricket"))
b=eval(input("Enter the rollnos of students who play badminton"))
c=eval(input("Enter the rollnos of students who play football"))


#list of students who play both cricket and badminton
print("students who play both cricket and badminton")
print(S1NS2(a,b))

#list of students who play either cricket or badminton but not both
print("either cricket or badminton but not both")
print(S1DS2(S1US2(a,b),S1NS2(a,b)))


print("no of students who play neither cricket nor badminton ")
print(tstudents-len(S1US2(a,b)))

print("no of students who play cricket and football but not badminton")
print(len(S1DS2(S1NS2(a,c),b)))

print("no of students who dont play any game ")
print(tstudents-len(S1US2(a ,S1US2(b,c))))


print("no of students who play atleast one game ")
print(S1US2(a,S1US2(b,c)))

print("no of students who playall three games")
print(S1NS2(a,S1NS2(b,c)))
      
        
