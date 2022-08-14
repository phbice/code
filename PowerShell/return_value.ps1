# 命令的返回值为.net对象，若返回值包含多个对象则以数组返回

$dirlist = ls
$dirlist.Count
$dirlist[0] | fl * # fl = Format-List