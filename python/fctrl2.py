t = int (raw_input())
while t:
	n = int (raw_input())
	result = 1
	for i in range (2, n+1):
		result *= i
	print result
	t -= 1
