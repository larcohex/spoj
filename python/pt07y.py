nodes = {}
isGraph = False
VE = [int (x) for x in (raw_input()).split()]
V = VE[0]
E = VE[1]
if V - 1 != E:
	isGraph = True
while E:
	n = [int (x) for x in (raw_input()).split()]
	if not isGraph:
		if not nodes:
			nodes[n[0]] = n[0]
			nodes[n[1]] = n[1]
		else:
			if n[0] in nodes:
				if n[1] in nodes:
					isGraph = True
				else:
					nodes[n[1]] = n[1]
			else:
				if n[1] in nodes:
					nodes[n[0]] = n[0]
				else:
					isGraph = True
	E -= 1
if isGraph:
	print "NO"
else:
	print "YES"
