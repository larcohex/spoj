import string



def convertToJava (line):
	i = 0
	while i < len (line):
		if line[i] == '_':
			newLine = line[0:i] + line[i + 1].upper() + line[i + 2:]
			line = newLine[:]
		i += 1
	return line



def convertToC (line):
	i = 0
	while i < len (line):
		if line[i].isupper():
			newLine = line[0:i] + '_' + line[i].lower() + line[i + 1:]
			line = newLine[:]
		i +=1
	return line



def hasUppercase (line):
	for i in range (0, len (line)):
		if line[i].isupper():
			return True
	return False


while True:
	try:
		line = raw_input()
		if line.find ('_') != -1:
			if line[0] == '_' or line[len (line) - 1] == '_':
				print "Error!"
			else:
				if (line.find ('__') != -1):
					print "Error!"
				else:
					if hasUppercase (line):
						print "Error!"
					else:
						print convertToJava (line)
		else:
			if line[0].isupper():
				print "Error!"
			else:
				print convertToC (line)
	except (EOFError):
		break
