2024.5.22



写了一个shell脚本来批量修改文件名

for file in *; do  

​	new_file=$(echo "$file" | sed 's/要删除的字符串//g')  

​	if [ "$file" != "$new_file" ]; then    

​		mv "$file" "$new_file"  

​	fi 

done



`|` 是管道符（pipe）的用法。它的作用是将前一个命令的输出作为后一个命令的输入。这里，`echo "$file"` 命令的输出被传递给了 `sed` 命令。

`s` 命令告诉 `sed` 要进行替换操作。`要去除的字符串` 是我们希望从文件名中移除的部分，而紧跟着的第二个 `/` 后面的空字符串 `''` 表示我们想要用空字符串替换匹配到的 `要去除的字符串`，实际上就是删除它。

最后的 `g` 标志是全局标志，它告诉 `sed` 对每一行进行尽可能多的替换，而不是只替换第一次出现。



运行命令

linux： ./test.sh

windows : 在gitbash sh test.sh