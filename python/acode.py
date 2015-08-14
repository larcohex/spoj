while True:
	code = raw_input()
	if code == "0":
		break
	else:
		first = 1
		next = 1
		for i in range (0, len (code) - 1):
			if not int (code[i+1]):
				temp = next - (next - first)
				first = next
				next = temp
			elif not int (code[i]):
				first = next
			elif int (code[i:i+2]) <= 26:
				temp = first + next
				first = next
				next = temp
			else:
				first = next
		print next
