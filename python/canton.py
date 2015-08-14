from math import *
from sys import *
t = int (raw_input ())
while t:
	n = int (raw_input())
	row = (sqrt (8 * n + 1) - 1) // 2
	start = int ((row ** 2) / 2.0 + row / 2.0)
	if n == 1:
		dif = n - start
		if row % 2:
			stdout.write ("TERM ")
			stdout.write (str (n))
			stdout.write (" IS ")
			stdout.write (str (row - dif))
			stdout.write ("/")
			stdout.write (str (1 + dif))
			stdout.flush()
		else:
			stdout.write ("TERM ")
			stdout.write (str (n))
			stdout.write (" IS ")
			stdout.write (str (1 + dif))
			stdout.write ("/")
			stdout.write (str (row - dif))
			stdout.flush()
	elif n == start:
		start = int (((row - 1) * (row - 1)) / 2.0 + (row - 1) / 2.0)
		dif = n - start - 1
		if row % 2:
			stdout.write ("TERM ")
			stdout.write (str (n))
			stdout.write (" IS ")
			stdout.write (str (int (row - dif)))
			stdout.write ("/")
			stdout.write (str (int (1 + dif)))
			stdout.flush()
		else:
			stdout.write ("TERM ")
			stdout.write (str (n))
			stdout.write (" IS ")
			stdout.write (str (int (1 + dif)))
			stdout.write ("/")
			stdout.write (str (int (row - dif)))
			stdout.flush()
	else:
		row += 1
		dif = n - start - 1
		if row % 2:
			stdout.write ("TERM ")
			stdout.write (str (n))
			stdout.write (" IS ")
			stdout.write (str (int (row - dif)))
			stdout.write ("/")
			stdout.write (str (int (1 + dif)))
			stdout.flush()
		else:
			stdout.write ("TERM ")
			stdout.write (str (n))
			stdout.write (" IS ")
			stdout.write (str (int (1 + dif)))
			stdout.write ("/")
			stdout.write (str (int (row - dif)))
			stdout.flush()
	print
	t -= 1
