import random
import string


def search4Way(x, y, color):
    global r1
    if r1[x][y] == '1':
        r1[x][y] = color
        # Up
        search4Way(x-1, y, color)
        # Down
        search4Way(x+1, y, color)
        # Left
        search4Way(x, y-1, color)
        # Right
        search4Way(x, y+1, color)
    else:
        return


def search8Way(x, y, color):
    global r2
    if r2[x][y] == '1':
        r2[x][y] = color
        # Up
        search8Way(x-1, y, color)
        # Up-Left
        search8Way(x-1, y-1, color)
        # Up-Right
        search8Way(x-1, y+1, color)
        # Down
        search8Way(x+1, y, color)
        # Down-Left
        search8Way(x+1, y-1, color)
        # Down-Right
        search8Way(x+1, y+1, color)
        # Left
        search8Way(x, y-1, color)
        # Right
        search8Way(x, y+1, color)
    else:
        return


########################################################

# Row
m = int(input("m : "))
# Column
n = int(input("n : "))

colors = list(string.ascii_lowercase)
r1 = [['0']*(n+2) for x in range(m+2)]
r2 = [['0']*(n+2) for y in range(m+2)]

for i in range(0, m+2):
    for j in range(0, n+2):
        if (i == 0 or i == m+1 or j == 0 or j == n+1):
            continue
        else:
            r1[i][j] = str(random.randrange(0, 2))
            r2[i][j] = r1[i][j]
            # r1[i][j] = str(input())

########################################################

# Print Metrix
print("\n/// Before")
for i in range(1, m+1):
    for j in range(1, n+1):
        print(r1[i][j], end=" ")
    print()

########################################################

# 4-Way Connectivity
color_idx = 0
while(True):
    flag = True

    for i in range(1, m+1):
        for j in range(1, n+1):
            if (r1[i][j] == '1'):
                flag = False
                search4Way(i, j, colors[color_idx])
                color_idx += 1

    if(flag):
        break

########################################################

# 8-Way Connectivity
color_idx = 0
while(True):
    flag = True

    for i in range(1, m+1):
        for j in range(1, n+1):
            if (r2[i][j] == '1'):
                flag = False
                search8Way(i, j, colors[color_idx])
                color_idx += 1

    if(flag):
        break

########################################################

# Print Metrix
print("\n/// After (4-Way)")
for i in range(1, m+1):
    for j in range(1, n+1):
        print(r1[i][j], end=" ")
    print()

print("\n/// After (8-Way)")
for i in range(1, m+1):
    for j in range(1, n+1):
        print(r2[i][j], end=" ")
    print()

########################################################
