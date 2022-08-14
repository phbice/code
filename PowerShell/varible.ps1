# 注释
# 弱类型变量
$demo = "Hello"
# 强类型变量
[DateTime]$data = "2021-10-02 09:34:21"
$data.DayofWeek

<#
支持的.net类型如下：
array, bool, byte, char, datetime, decimal, double, guid,
hashtable, int16, int32, int, int64, long, nullable, psobject
regex, sbyte, scriptblock, single, float, string, switch,
timespan, type, uint16, uint32, uint64, xml
#>

# Get-Variable 获取变量的更多信息
Get-Variable data | Format-List *