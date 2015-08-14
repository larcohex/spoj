t = int (raw_input())
while t:
	n = [int(x) for x in (raw_input()).split()]
	r = n[0] % 10
	if not n[1]:
		print 1
	elif not r:
		print 0
	elif r == 1 or r == 5 or r == 6:
		print r
	elif r == 2 or r == 3 or r == 7 or r == 8:
		l = n[1] % 4
		if not l:
			l = 4
		for i in range (1, l):
			r = (r * n[0]) % 10
		print r
	else:
		l = n[1] % 2
		if not l:
			l = 2
		for i in range (1, l):
			r = (r * n[0]) % 10	
		print r
	t -= 1
