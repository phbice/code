cals_list = (
    ('+2', '+8'),
    ('*2', '*5'),
    ('+4', '+7'),
    ('+3', '+12'),
    ('-5', '-17'),
    ('+2', '+9')
)
target = 30

def cal(cal_list):
    result = 0
    for cal in cal_list:
        operator = cal[0]
        number = int(cal[1:])
        if operator == '+':
            result += number
        elif operator == '-':
            result -= number
        elif operator == '*':
            result *= number
        else:
            raise Exception(f'Unexpected Operator {operator}')
    return result

for index in range(1 << len(cals_list)):
    indices = tuple(0 if i == '0' else 1 for i in format(index, '06b'))
    if cal(cals[i] for i, cals in zip(indices, cals_list)) == target:
        print(indices)
        print(*(cals[i] for i, cals in zip(indices, cals_list)))
