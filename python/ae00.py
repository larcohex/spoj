from math import sqrt

N = int (raw_input())
result = 0
for i in range (1, N + 1):
	for j in range (1, int (sqrt (i) + 1)):
		if not i % j:
			result += 1
print result
