
palindrome = -1
for i in range(100,1000):
    for j in range(100,1000):
        aux = str(i*j)
        middle = len(aux)//2
        # print(aux, aux[:middle-1:-1] , aux[:middle])
        if aux[:middle-1:-1] == aux[:middle]:
            palindrome = max(palindrome, i*j)

print(palindrome)