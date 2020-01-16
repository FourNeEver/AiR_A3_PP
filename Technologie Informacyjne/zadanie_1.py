file = open('urodzenia.txt', 'r')

for line in file:
    data = line.split('@')
    time = data[2].split(':')
    date = data[1].split('/')
    if int(time[0])<12:
        print(data[0],'urodzony przed południem w dniu',date[2],'-',date[1],'-',date[0])
    else:
        print(data[0],'urodzony po południu w dniu',date[2],'-',date[1],'-',date[0])

