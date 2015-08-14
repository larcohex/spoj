temp = [x for x in range (32000)]
temp[1] = 0
for i in range (2, 32000):
	if temp[i]:
		j = 0
		while (i**2 + j) < 32000:
			temp[i**2 + j] = 0
			j += i

prime = [x for x in temp if x]

def f (n):
	if n != 1:
		result = True
		for i in prime:
			if i >= n:
				break
			elif not (n % i):
				result = False
				break
		if result:
			print n


t = int (raw_input())
while t:
	line = raw_input()
	line = line.split()
	num1 = int (line[0])
	num2 = int (line[1])
	i = num1
	while i < num2 + 1:
		f (i)
		i += 1
	print 
	t -= 1
