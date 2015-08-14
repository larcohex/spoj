def merge (arr, begin, end):
	srtd = []
	middle = (begin + end) // 2
	i = begin
	j = middle + 1
	while i <= middle and j <= end:
		if arr[i] < arr[j]:
			srtd.append (arr[i])
			i += 1
		else:
			srtd.append (arr[j])
			j += 1
	while i <= middle:
		srtd.append (arr[i])
		i += 1
	while j <= end:
		srtd.append (arr[j])
		j += 1
	for i in range (begin, end + 1):
		arr[i] = srtd[i - begin]




def sort (arr, begin, end):
	if end > begin:
		middle = (begin + end) // 2
		sort (arr, begin, middle)
		sort (arr, middle + 1, end)
		merge (arr, begin, end)




while True:
	pl = [int(x) for x in (raw_input()).split()]
	if pl[0] == 0 and pl[1] == 0:
		break
	else:
		attack = [int (x) for x in (raw_input()).split()]
		defence = [int (x) for x in (raw_input()).split()]
		sort (attack, 0, len (attack) - 1)
		sort (defence, 0, len (defence) - 1)
		if attack[0] < defence[1]:
			print "Y"
		else:
			print "N"
