t = int (raw_input())
while t:
	raw_input()
	army = [int (x) for x in (raw_input()).split()]
	if army[0] and army[1]:
		godz = [int (x) for x in (raw_input()).split()]
		mgodz = [int (x) for x in (raw_input()).split()]
		if max (godz) < max (mgodz):
			print "MechaGodzilla"
		else:
			print "Godzilla"
	elif army[0]:
		godz = [int (x) for x in (raw_input()).split()] 
		print "Godzilla"
	elif army[1]:
		mgodz = [int (x) for x in (raw_input()).split()]
		print "MechaGodzilla"
	else:
		print "uncertain"
	t -= 1
