T = int (raw_input())
while T:
	raw_input()
	N = int (raw_input())
	candies = []
	for i in range (0, N):
		candies.append (int (raw_input()))
	result = 0
	for i in range (0, N):
		result = (result + candies[i]) % N
	if result:
		print "NO"
	else:
		print "YES"
	T -= 1
