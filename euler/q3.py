target = 600851475143
isPrime = [1]*int(target**0.5+100)
biggest_prime = -1
for i in range(2, int(target**0.5)+10):
    if not isPrime[i]:
        continue
    if target%i==0: biggest_prime=i
    for j in range(2*i, int(target**0.5)+10, i):
        isPrime[j] = 0



print(biggest_prime)
