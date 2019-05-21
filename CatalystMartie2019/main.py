import math
import sys


def checkRadius(x1, y1, x2, y2, radius):
    x = x2 - x1
    y = y2 - y1
    return math.sqrt(math.pow(x, 2) + math.pow(y, 2)) < radius


with open("data.in") as f:
    content = f.readlines()
# you may also want to remove whitespace characters like `\n` at the end of each line
content = [x.strip().split(" ") for x in content]
# print(content)
w, h = int(content[0][0]), int(content[0][1])
x, y = int(content[1][0]), int(content[1][1])
index = 0
plusx, plusy, status = 0, 0, 0
steps = [[x, y]]
while(index < len(content[2])):
    com = content[2][index]
    step = int(content[2][index+1])
    index += 2
    if com == "T":
        status = (status+step) % 4
    else:
        if status == 0:
            plusx = 1
            plusy = 0
        elif status == 1:
            plusx = 0
            plusy = 1
        elif status == 1:
            plusx = -1
            plusy = 0
        elif status == 1:
            plusx = 0
            plusy = -1
        for st in range(0, step):
            x = x + plusx
            y = y + plusy
            steps.append([x, y])

health = float(content[3][0])
speed = float(content[3][1])
n = int(content[4][0])
spawnTime = []
for i in range(0, n):
    spawnTime.append(int(content[i+5][0]))
fromWhere = n + 5
damage = float(content[fromWhere][0])
radius = float(content[fromWhere][1])
fromWhere += 1
t = int(content[fromWhere][0])
fromWhere += 1
towers = []
for i in range(0, t):
    xt = int(content[fromWhere+i][0])
    yt = int(content[fromWhere+i][1])
    towers.append([-1, xt, yt])
aliveAliens = []
tick = 0
while(True):
    toDelete = []
    for alien in aliveAliens:
        distanceTrav = round((tick-alien[2])*speed)
        if distanceTrav == len(steps)-1:
            print(tick, "\nLOSE")
            sys.exit()
    for ind in range(len(spawnTime)):
        if spawnTime[ind] == tick:
            aliveAliens.append([i, health, tick])
    if tick != 0:
        for ind in range(len(towers)):
            for i in range(len(aliveAliens)):
                distanceTrav = round((tick-aliveAliens[i][2])*speed)
                alx = steps[distanceTrav][0]
                aly = steps[distanceTrav][1]
                if(aliveAliens[i][0] == towers[0] and checkRadius(towers[ind][1], towers[ind][2], alx, aly, radius)):
                    aliveAliens[i][1] -= damage
                elif (aliveAliens[i][1] <= 0):
                    toDelete.append(i)
                    towers[ind][0] = -1
                elif (not checkRadius(towers[ind][1], towers[ind][2], alx, aly, radius)):
                    towers[ind][0] = -1

    for i in range(len(toDelete)):
        aliveAliens.pop(toDelete[i]-i)

    for ind in range(len(towers)):
        for i in range(len(aliveAliens)):
            if(towers[ind][0] == -1):
                distanceTrav = round((tick-aliveAliens[i][2])*speed)
                alx = steps[distanceTrav][0]
                aly = steps[distanceTrav][1]
                if(checkRadius(towers[ind][1], towers[ind][2], alx, aly, radius)):
                    if(towers[ind][0] < aliveAliens[i][0]):
                        towers[ind][0] = aliveAliens[i][0]

    re = True
    for spawn in spawnTime:
        if spawn > tick:
            re = False

    if(len(aliveAliens) == 0 and re):
        print(tick, "\nWIN")
        sys.exit()
    tick += 1
