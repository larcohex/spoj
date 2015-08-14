table = {0: 0.0}

def f(n):
	result = 0
	length = 0.0
	i = 2
	while length < n:
		try:
			length = table[i-1]
		except (KeyError):
			length = 0.0
			for j in range (2, i+1):
				length += 1.0/j
			table[i-1] = length
		result += 1
		i += 1
	return result

while True:
	n = float (raw_input())
	if not n:
		break
	else:
		print f(n), "card(s)"
