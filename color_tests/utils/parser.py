import re

with open("colors.txt") as f:
    colors = [c.strip() for c in f.read().split(",")]
    matcher = re.compile("(.+) =(.+)")
    names = []
    hexes = []
    for color in colors:
        res = matcher.match(color)
        names.append(res[1])
        hexes.append(res[2])
    print(len(names))

with open("names.txt", "w") as f1, open("hexes.txt", "w") as f2:
    for name, hex in zip(names, hexes):
        f1.write("{}\n".format(name))
        f2.write("{}\n".format(hex))