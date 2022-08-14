# 创建数组可以使用逗号
$nums = 2, 0, 2, 1
$nums
# 连续数字数组的简化写法
$nums = 1..5
$nums
# 空数组
$empty = @()
$empty -is [array]
# 单个元素的数组
$one = ,"single"
$one.Count

# 弱类型数组可以储存不同类型的值
$arr1 = @()
$arr1 += 2021
$arr1 += "Hello world!"
$arr1 += ipconfig
$arr1

# 强类型数组
[int[]] $arr2 = @()
$arr2 += 2021
$arr2 += 13.56
$arr2 += "Hello world!"
$arr2