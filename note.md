# Git 删除所有历史版本

## 1 创建一个新的 orphan branch

```cmd
git checkout --orphan latest_branch
```

## 2 添加所有文件

```cmd
git add -A
```

## 3 提交修改

```cmd
git commit -m 'clear all history'
```

## 4 删除原分支

```cmd
git branch -D main
```

## 5 重命名当前分支

```cmd
git branch -m main
```

## 6 强制更新远程仓库

```cmd
git push -f origin main
```