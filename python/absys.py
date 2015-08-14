from string import find
t = int (raw_input())
while t:
	raw_input()
	strings = (raw_input()).split()
	if find (strings[0], "machula") != -1:
		print (int (strings[4]) - int (strings[2])), "+", strings[2], "=", strings[4]
	elif find (strings[2], "machula") != -1:
		print strings[0], "+", (int (strings[4]) - int (strings[0])), "=", strings[4]
	elif find (strings[4], "machula") != -1:
		print strings[0], "+", strings[2], "=", (int (strings[0]) + int (strings[2]))
	else:
		print strings[0], "+", strings[2], "=", strings[4]		
	t -= 1
