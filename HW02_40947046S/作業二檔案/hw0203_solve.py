#! /usr/bin/env python3
from subprocess import check_output, CalledProcessError
import sys
import re

awnser = '''--------------------------
energy: 0
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: QQ
But nothing is good.
Kyoko: QQ
But nothing is good.
No name: Majo is hopeless.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
--------------------------
energy: 0
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: QQ
But nothing is good.
Kyoko: QQ
But nothing is good.
No name: Majo is hopeless.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
--------------------------
energy: 0
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: QQ
But nothing is good.
Kyoko: QQ
But nothing is good.
No name: Majo is hopeless.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
--------------------------
energy: 0
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: QQ
But nothing is good.
Kyoko: QQ
But nothing is good.
No name: Majo is hopeless.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
--------------------------
energy: 0
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: QQ
But nothing is good.
Kyoko: QQ
But nothing is good.
No name: Majo is hopeless.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
Watashii de, hondo baga.
--------------------------
energy: 10000
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: majo is hopeless.
Kyoko: QQ
But nothing is good.
No name: Majo is hopeless.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
--------------------------
energy: 20000
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: majo is hopeless.
No name: Majo is hopeless.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
--------------------------
energy: 30000
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: majo is hopeless.
No name: Majo is hopeless.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
--------------------------
energy: 40000
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: majo is hopeless.
No name: Majo is hopeless.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
--------------------------
energy: 50000
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: majo is hopeless.
No name: Majo is hopeless.
shoujo: shoujo is blessing.
shoujo: shoujo is blessing.
--------------------------
energy: 60000
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: majo is hopeless.
No name: Majo is hopeless.
--------------------------
energy: 70000
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: majo is hopeless.
No name: Majo is hopeless.
--------------------------
energy: 80000
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: majo is hopeless.
No name: Majo is hopeless.
--------------------------
energy: 90000
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: majo is hopeless.
No name: Majo is hopeless.
--------------------------
energy: 100000
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: majo is hopeless.
No name: Majo is hopeless.
--------------------------
energy: 110000
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: majo is hopeless.
No name: Majo is hopeless.
--------------------------
energy: 120000
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: majo is hopeless.
No name: Majo is hopeless.
--------------------------
energy: 130000
--------------
Madoka: OAO
Homura: Madoka..
But nothing is good.
Sayaka: majo is hopeless.
No name: Majo is hopeless.
This round is hopeless, Homura go to next round.'''
score = 0


def compare(a, b):
    return re.sub(r'[: ,.\n]', '', a).lower() == re.sub(r'[: ,.\n]', '',
                                                        b).lower()


try:
    result = check_output(f'{sys.path[0]}/hw0203', shell=True).decode("utf-8")
except CalledProcessError as c:
    result = f'錯誤：{c}'

while '\n\n' in result:
    result = result.replace('\n\n', '\n')
if result[0] == '\n':
    result = result[1:]
if result[-1] == '\n':
    result = result[:-1]

if compare(
        awnser.split('energy')[-1].split('\n')[0],
        result.split('energy')[-1].split('\n')[0]):
    score += 5
if compare(awnser.split('\n')[-1], result.split('\n')[-1]):
    score += 10
if compare('\n'.join(awnser.split('--------------\n')[-1].split('\n')[:-1]),
           '\n'.join(result.split('--------------\n')[-1].split('\n')[:-1])):
    score += 5

print(f'第三題分數：{score}')
