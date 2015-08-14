table = {}

def optimize (N):
	if not N:
		return 0
	else:
		try:
			result = table [N]
			return result
		except (KeyError):
			temp = optimize (N//2) + optimize (N//3) + optimize (N//4)
			if temp > N:
				table[N] = temp
				return temp
			else:
				table[N] = N
				return N

while True:
	try:
		N = int (raw_input ())
		print optimize (N)
	except (ValueError, EOFError):
		break
