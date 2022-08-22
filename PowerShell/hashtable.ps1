# 哈希表储存键值对
$stu = @{name = "小明"; age=12; sex="男"}
write-host '哈希表：'
$stu

# 可以储存列表
$stu = @{name = "小明"; age=12; sex="男";
books="三国演义", "平凡的世界", "三体"; sports="乒乓球"}
write-host '哈希表-包含列表：'
$stu

# 键值的增删查改
# 增加
$stu.English = "CET-6"
$stu["ID"] = "1234567"
$stu.Add("married", $false)
# 删除
$stu.Remove("sprots")
# 查找
write-host('查找键值：')
$stu.name
$stu["name"]
# 修改
$stu.age = 20

write-host '增删查改后的结果：'
$stu
