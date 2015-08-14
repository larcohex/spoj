def merge (v, begin, end):
	middle = (begin + end) // 2
	i = 0
	j = middle + 1
	vs = []
	while i <= middle and j <= end:
		if v[i] < v[j]:
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


t = int (raw_input())
while t:
	N = int (raw_input())
	male = [int (x) for x in (raw_input()).split()]
	female = [int (x) for x in (raw_input()).split()]
	sort (male, 0, N-1)
	sort (female, 0, N-1)
	total = 0
	for i in range (0, N):
		total += male[i] * female[i]
	print total
	t -= 1
