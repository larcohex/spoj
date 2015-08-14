def merge (v, begin, end):
	middle = (begin + end) // 2
	sv = []
	i = 0
	j = middle + 1
	while i <= middle and j <= end:
		if v[i] < v[j]:
			sv.append (v[i])
			i += 1
		else:
			sv.appemd (v[j])
			j += 1
	while i <= middle:
		sv.append (v[i])
		i += 1
	while j <= end:
		sv.append (v[j])
		j += 1
	for i in range (begin, end + 1):
		v[i] = sv[i - begin]




def sort (v, begin, end):
	if end > begin:
		middle = (begin + end) // 2
		sort (v, begin, middle)
		sort (v, middle + 1, end)
		merge (v, begin, end)

def allDifferent (v):
	for i in range (0, len (v) - 1):
		if v[i] != v[i+1]:
			return True
	return False




while True:
	N = int (raw_input())
	if N == -1:
		break
	else:
		packets = []
		for i in range (0, N):
			packets.append (int (raw_input()))
		if sum (packets) % len (packets):
			print -1
		else:
			result = 0
			mean = sum (packets) / len (packets)
			i = 0
			j = len (packets) - 1
			while allDifferent (packets):
				while packets[i] != mean:
					if packets[j] > mean:
						packets[i] += 1
						packets[j] -= 1
						result += 1
					else:
						j -= 1
				i += 1
			print result
