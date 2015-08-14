T = int (raw_input())
while T:
	N = int (raw_input())
	a = 0
	i = 1
	while 5 ** i < N:
		a += N // (5 ** i)
		i += 1
	print a
	T -= 1
