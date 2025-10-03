n = 0
l = [i for i in range(2, 21)]
flag = True
while flag:
    n+=1
    print(n)
    if sum([n%i for i in l]) == 0:
        flag = False
        print(n)
        
