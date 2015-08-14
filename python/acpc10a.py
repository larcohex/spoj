while True:
	seq = [int (x) for x in (raw_input()).split()]
	if not seq[0] and not seq[1] and not seq[2]:
		break
	if seq[2] - seq[1] == seq[1] - seq[0]:
		print "AP", seq[2] + (seq[2] - seq[1])
	else:
		print "GP", seq[2] * (seq[2] / seq[1])
