# 哈希表储存键值对
$stu = @{name = "小明"; age=12; sex="男"}
$stu
$stu["name"]

# 可以储存列表
$stu = @{name = "小明"; age=12; sex="男"; books="三国演义", "平凡的世界", "三体"; sports="乒乓球"}
$stu

# 键值的增删查改
$stu.age = 20
$stu.English = "CET-6"
$stu.Remove("sprots")
$stu.name
$stu
