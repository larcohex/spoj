from sys import stdout


def merge (v, begin, end):
	middle = (begin + end) // 2
	i = begin
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


def check (total, stamps):
	i = 0
	while i < len (stamps):
		if total <= 0:
			return i
		else:
			total -= stamps[len(stamps) - 1 - i]
		i += 1
	if total <= 0:
		return i
	else:
		return 0


t = int (raw_input())
for i in range (0, t):
	task = [int (x) for x in (raw_input()).split()]
	stamps = [int (x) for x in (raw_input()).split()]
	sort (stamps, 0, task[1] - 1)
	result = check (task[0], stamps)
	stdout.write ("Scenario #");
	stdout.write (str (t));
	stdout.write (":");
	stdout.flush()
	print
	if result:
		print result
	else:
		print "impossible"
	if i < t:
		print
