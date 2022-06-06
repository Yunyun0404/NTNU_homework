#! /usr/bin/env python3
from subprocess import check_output, CalledProcessError
import sys

inputs = [
    '\\frac{1}{2}+1\\frac{5}{6}*2\\frac{3}{10}',
    '\\frac{2}{3}-1\\frac{1}{2}',
    '2\\frac{2}{5}*\\frac{1}{3}-1',
    '3/8*\\frac{2}{7}-1\\frac{3}{28}',
    '\\frac{7}{8}-\\frac{3}{8}-\\frac{1}{2}',
]
outputs = [
    '4\\frac{43}{60}',
    '\\frac{-5}{6}',
    '\\frac{-1}{5}',
    '-1',
    '0',
]
score = 0

for i in range(len(inputs)):
    try:
        result = check_output(
            f'printf %s "{inputs[i]}\n" | {sys.path[0]}/hw0204',
            shell=True).decode("utf-8")
    except CalledProcessError as c:
        result = f'第 {i} 個錯誤：{c}'
    print(result, file=sys.stderr)

    if outputs[i] in result:
        score += 4

print(f'第四題分數：{score}')

code = check_output(f'cat {sys.path[0]}/hw0204.c', shell=True).decode("utf-8")
required = ['sMixedNumber', 'mixed_add', 'mixed_sub', 'mixed_mul', 'mixed_div']
print(f'有需要的程式碼：{all(item in code for item in required)}')
