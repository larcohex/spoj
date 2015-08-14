while True:
	N = int (raw_input())
	if not N:
		break
	else:
		result = 0
		i = 0
		while i <= N:
			result += i**2
			i += 1
		print result
