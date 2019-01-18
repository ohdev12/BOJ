string = input()
charAt = []
for i in range(0, 26):
    charAt.append(string.find(chr(i+97)))
for i in range(0, 26):
    print(charAt[i], end=' ')
