pi = 3.1415926535
while True:
	L = float (raw_input())
	if not L:
		break
	else:
		print ("%.2f" % ((L * L) / (2 * pi)))
