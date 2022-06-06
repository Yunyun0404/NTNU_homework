#! /usr/bin/env python3
from subprocess import check_output, CalledProcessError
import sys

score = 0

for i in range(1, 7):
    try:
        result = check_output(f'echo {i} | {sys.path[0]}/hw0205',
                              shell=True).decode("utf-8")
        score += int(result.split('分')[-1])
    except CalledProcessError as c:
        result = f'第 {i} 個錯誤：{c}'
    print(result, file=sys.stderr)

print(f'第五題分數：{score}')
