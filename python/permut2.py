def merge (v, begin, end):
	middle = (begin + end) // 2
	i = begin
	j = middle + 1
	vs = []
	while i <= middle and j <= end:
		if (v[i][0] < v[j][0]):
			vs.append (v[i])
			i += 1
		else:
			vs.append (v[j])
			j += 1
	while i <= middle:
		vs.append (v[i])
		i += 1
	while j <= end:
		vs.append (v[j])
		j += 1
	for i in range (begin, end + 1):
		v[i] = vs[i - begin]


def sort (v, begin, end):
	if (end > begin):
		middle = (begin + end) // 2
		sort (v, begin, middle)
		sort (v, middle + 1, end)
		merge (v, begin, end)


while True:
	n = int (raw_input())
	if not n:
		break
	else:
		arr = [[int (x), 1] for x in (raw_input()).split()]
		for i in range (1, n+1):
			arr[i-1][1] = i
		arr2 = arr[:]
		sort (arr2, 0, n-1)
		ambiguous = True
		for i in range (n):
			if arr[i][0] != arr2[i][1]:
				ambiguous = False
				break
		if ambiguous:
			print "ambiguous"
		else:
			print "not ambiguous"
