# 目录

### 第一章：Linux目录结构

#### 第一节：基本介绍

linux 的文件系统是采用级层式的树状目录结构，在此结构中的最上层是根目录“/”，然后在此目录下再创建其他的目录。
**`在 Linux 世界里，一切皆文件。`**

例如：随着人工智能的不断发展，机器学习这门技术也越来越重要，很多人都开启了学习机器学习，本文就介绍了机器学习的基础内容。

#### 第二节：Linux具体目录结构

● /lib
系统开机所需要最基本的动态链接共享库，其作用类似于Windows里的DLL文件。几乎所有的应用程序都需要用到这些共享库。
● /lost+found
一般情况下是空的，当系统非法关机后，这里就存放了一些文件。
● /etc [重点]
所有系统管理所需要的配置文件和子目录。my.conf
● /usr
用户的很多应用程序和文件都放在这个目录下。类似于Windows下的program.files目录
● /bin (usr/bin、/usr/local/bin) [usr:Unix System Resource，即Unix系统资源的缩写]
是Binary的缩写，这个目录存放着经常使用的命令
● /sbin (usr/sbin、/usr/local/sbin)
s就是per user的意思，这里存放的是系统管理员使用的系统管理程序
● /home [重点]
存放普通用户的主目录，在Linux中的每个用户都有一个自己的目录，一般该目录一用户的账号名命名
● /root [重点]
该目录为系统管理员，超级权限者的用户目录
● /boot
存放的启动Linux时使用的一些核心文件，包括一些链接文件和镜像文件
● /proc
虚拟目录，是系统内存的映射，访问这个目录来获取系统信息。
● /srv
service 的缩写，该目录是存放一些服务启动之后需要提取的数据
● /sys
Linux2.6内核的一个很大变化，该目录安装了2.6内核中新出现的一个文件系统
● /tmp
存放临时文件
● /dev
类似于 windows的设备管理器,把所有的硬件用文件的形式存储
● /media [重点]
Linux系统会自动识别一些设备,例如U盘、光驱等等,当识别后,Linux 会把识别的设备挂载到这个目录下。
● /mnt [重点]
系统提供该目录是为了让用户临时挂载别的文件系统的,我们可以将外部的存储挂载在/mnt/上,然后进入该目录就可以查看里的内容了。d:/ myshare
● /opt
这是给主机额外安装软件所摆放的目录。如安装 ORACLE数据库就可放到该目录下。默认为空。
● /usr/local [重点]
这是另个给主机额外安装软件所安装的目录。一般是通过编译源码方式安装的程序。
● /var [重点]
这个目录中存放着在不断扩充着的东西,习惯将经常被修改的目录放在这个目录下。包括各种日志文件。
● /selinux [security-enhanced linux] 类似 360
Selinux是一种安全子系统,它能控制程序只能访同特定文件。

### 第二章：Linux常用命令

#### 第一节：目录处理命令

##### 2.1.1 命令格式

命令格式 ：命令 [-选项] [参数]

##### 2.1.2 列出目录的内容：ls 命令

##### 2.1.3 创建目录：mkdir 命令

##### 2.1.4 切换工作目录：cd 命令

##### 2.1.5 显示当前路径：pwd 命令 

##### 2.1.6 删除空目录：rmdir 命令

##### 2.1.7 拷贝文件：cp 命令

##### 2.1.8 删除文件：rm 命令

##### 2.1.9 查看cpu信息： lscpu

#### 第二节：文件处理命令

##### 2.2.1 创建文件：touch 命令

##### 2.2.2 显示文件内容：cat 命令

##### 2.2.3 分屏显示：more 命令

命令名称：more 

命令所在路径：/bin/more 
执行权限：所有用户 
语法：more  [文件名]                  
   (空格) 或f           翻页               
   (Enter)             换行                 
   q或Q                退出 
功能描述：分页显示文件内容 

范例：   
$ more  /etc/services

##### 2.2.4 分屏显示：less 命令

命令名称：less 

命令所在路径：/usr/bin/less 
执行权限：所有用户 
语法：less  [文件名] 
功能描述：分页显示文件内容（可向上翻页） 

范例：  
$  less  /etc/services
tips: 按下 / 后可以搜索 会反显高亮  按q退出（more也可以


##### 2.2.5 取首n行：head 命令

1. 命令名称：head
2.  
3. 命令所在路径：/usr/bin/head 
4. 执行权限：所有用户 
5. 语法：head  [文件名] 
6. 功能描述：显示文件前面几行    
7. ​    -n 指定行数 
8.  
9. 范例：  
10. $ head -n 20 /etc/services

##### 2.2.6 取尾n行：tail 命令

命令名称：tail 

命令所在路径：/usr/bin/tail 
执行权限：所有用户 
语法：tail  [文件名] 
功能描述：显示文件后面几行    
    -n 指定行数    
    -f  动态显示文件末尾内容 

范例：   
$ tail -n 18 /etc/services

#### 第三节 链接命令

##### 2.3.1 建立链接文件：ln 命令

命令名称：ln 

命令所在路径：/bin/ln 
执行权限：所有用户 
语法：ln  -s  [原文件]  [目标文件]                 
 -s  创建软链接 
功能描述：生成链接文件

范例：        
$ ln -s  /etc/issue  /tmp/issue.soft        
 创建文件/etc/issue的软链接/tmp/issue.soft        
$ ln  /etc/issue  /tmp/issue.hard        
 创建文件/etc/issue的硬链接/tmp/issue.hard

#### 第四节 权限管理命令

##### 2.4.1 修改文件权限：chmod 命令 

##### 2.4.2 修改文件所有者：chown 命令

##### 2.4.3 修改文件所属组：chgrp 命令

##### 2.4.4 默认权限：umask 命令

#### 第五节 文件搜索命令

##### 2.5.1 查找文件：find 命令

find –type f –size 0 –exec rm –rf'{}'\;删除所有大小为0的文件，exec用“   \;   "结尾

区别：
find基本上相当于 linux下的 “搜索” , 相当于windows下的搜索功能! 它是用来搜索文件的。
grep是用来搜索文本的, 用来在standard input或文件内部的内容中, 来搜索文字 内容的!
find 是完全匹配（通配符），而grep是包含匹配（正则表达式）
find命令：
基本格式：find path expression

选项	说明
-name<文件名>	匹配文件名称
-user<用户名>	匹配文件的所有者
-perm<权限>	匹配文件的权限
-type<文件类型>	匹配文件类型查找
-size n[ckmg]	匹配文件的大小（+50k表示超过50k的文件）
-exec { } \	后面可直接对搜索到的结果进一步处理的命令
!	所有
-and(-a)	并且
-or(-o)	或者
例题
按文件名称
在/etc目录下查找文件 aaa.conf
find /etc -name aaa.conf

查找/etc目录下以名字中包含“conf”的文件
find /etc -name "*conf*" -type f

在当前目录下查找文件名含有字符串‘conf’的文件
find . -name '*conf*'

按文件特征查找
查找在系统中最后10分钟访问的文件 (access time)
find / -amin -10
查找在系统中最后48小时访问的文件
find / -atime -2
查找在系统中为空的文件或者文件夹
find / -empty
查找在系统中属于 group为cat的文件
find / -group cat
查找在系统中最后5分钟里修改过的文件 (modify time)
find / -mmin -5
查找在系统中最后24小时里修改过的普通文件，并删除
find / -mtime -1 -exec rm { } \
查找在系统中属于fred这个用户的文件
find / -user fred
查找出大于10000000字节的文件 (c:字节，w:双字，k:KB，M:MB，G:GB)
find / -size +10000c
查找出大于1000KB，并且小于10MB的文件
find / -size +1000k -a -size -10M
混合查找文件
在/tmp目录下查找大于10000字节并在最后2分钟内修改的文件
find /tmp -size +10000c -and -mtime +2
在/目录下查找用户是fred或者george的文件文件
find / -user fred -or -user george
在/tmp目录中查找所有不属于panda用户的文件
find /tmp ! -user panda


##### 2.5.2 文件资料库查找：locate 命令

##### 2.5.3 查看命令位置：which 命令

##### 2.5.4 查看命令位置：whereis 命令

##### 2.5.5 文本搜索：grep 命令

选项	说明
－c	只输出匹配行的计数。
－i	不区分大小写
－h	查询多文件时不显示文件名。
－l	查询多文件时只输出包含匹配字符的文件名。
－n	显示匹配行及行号。
－s	不显示不存在或无匹配文本的错误信息。
－v	反转查找，显示不包含匹配文本的所有行。
例题
将/etc/passwd，有出现 root 的行取出来，同时显示这些行在/etc/passwd的行号
grep -n root /etc/passwd
显示所有以d开头的文件中包含 test的行
grep 'test' d*
显示在aa，bb，cc文件中包含test的行
grep ‘test’ aa bb cc
显示所有包含每行字符串至少有5个连续小写字符的字符串的行
grep ‘[a-z]\{5\}’ aa
显示/usr/src目录下的文件(不含子目录)包含magic的行
grep magic /usr/src
显示/usr/src目录下的文件(包含子目录)包含magic的行
grep -r magic /usr/src
只匹配整个单词，而不是字符串的一部分(如匹配’magic’，而不是’magical’)
grep -w pattern files

#### 第六节 帮助命令

##### 2.6.1 帮助：man 命令

##### 2.6.2 获取简介：whatis 命令

##### 2.6.3 获取帮助：help 命令

#### 第七节 用户管理命令

##### 2.7.1 添加用户：useradd 命令

##### 2.7.2 修改密码：passwd 命令

##### 2.7.3 查看登录用户：who 命令

##### 2.7.4  w 命令

##### 2.7.5 切换用户：su 命令

#### 第八节 压缩解压缩命令

##### 2.8.1 压缩：gzip 命令

##### 2.8.2 解压缩：gunzip 命令

##### 2.8.3 归档管理：tar 命令

##### 2.8.4 zip 命令

##### 2.8.5 unzip 命令

#### 第九节 网络命令

##### 2.9.1 write 命令

##### 2.9.2 wall 命令

##### 2.9.3 测试网络连通性：ping 命令

##### 2.9.4 查看和设置网卡信息：ifconfig 通过文件查看cat /etc/resolv.conf 

##### 2.9.5 查看发送电子邮件：mail 命令

##### 2.9.6 查看登录用户历史信息：last 命令

##### 2.9.7 显示网络相关信息：netstat 命令

##### 2.9.8 配置网络：setup 命令

##### 2.9.9 挂载：mount 命令

#### 第十节 关机重启命令

##### 2.10.1 关机：shutdown 命令

##### 2.10.2 退出登录：logout 命令

查看 查看进程按内存从大到小排序

ps –e –o “%C:%p:%z:%a”|sort –k5 –nr

- `ps`: 是Linux中的一个命令行工具，用于展示系统的进程信息[1](https://blog.csdn.net/zxcsd11/article/details/137033716)[2](https://blog.csdn.net/qq_33681891/article/details/132977673)[3](https://www.jianshu.com/p/91646a282f27)。

- `-e`: 表示选择所有的进程，包括那些没有终端关联的用户进程[1](https://blog.csdn.net/zxcsd11/article/details/137033716)[2](https://blog.csdn.net/qq_33681891/article/details/132977673)[3](https://www.jianshu.com/p/91646a282f27)。

- `-o`: 用于指定输出的列，这里使用了自定义的格式`"%C:%p:%z:%a"`，其中：
  - `%C`: 表示CPU使用率。
  - `%p`: 表示父进程ID。
  - `%z`: 表示虚拟内存的大小。
  - `%a`: 表示进程的状态。

`sort`: 是Linux中的一个命令行工具，用于对输入的数据进行排序[1](https://blog.csdn.net/zxcsd11/article/details/137033716)[2](https://blog.csdn.net/qq_33681891/article/details/132977673)[3](https://www.jianshu.com/p/91646a282f27)。`-k5`: 表示按照第五列进行排序，在这里就是按照虚拟内存的大小进行排序[1](https://blog.csdn.net/zxcsd11/article/details/137033716)[2](https://blog.csdn.net/qq_33681891/article/details/132977673)[3](https://www.jianshu.com/p/91646a282f27)。`-nr`: 表示按照数值大小进行降序排序，也就是虚拟内存越大的进程会被排在前面[1](https://blog.csdn.net/zxcsd11/article/details/137033716)[2](https://blog.csdn.net/qq_33681891/article/details/132977673)[3](https://www.jianshu.com/p/91646a282f27)。

#### 第十一节 杂项

​	uname （显示内核版本信息）-r（-release） 查看内核版本信息

​	getenforce 显示执行安全策略状态SELinux 

​	systemctl status  firewalld.service 

- `systemctl` 是一个系统管理命令，用于控制 `systemd` 系统和服务管理器。
- `status` 是 `systemctl` 的一个子命令，用于显示指定服务的状态信息。
- `firewalld.service` 是 `firewalld` 服务的服务单元文件名。

### 第三章 文本编辑器vim

第一节 Vim常用操作

3.1.1 插入命令

3.1.2 定位命令 

3.1.3 删除命令

3.1.4 复制和剪切命令

3.1.5 保存和退出命令

第四章 软件安装

第一节 软件包管理简介

4.1.1 软件分类

第二节 rpm命令管理

4.2.1 包命名与依赖性

4.2.2 安装升级与卸载

第三节 yum在线管理

4.3.1 yum 命令

4.3.2 yum软件组管理命令

第五章 shell 基础

第一节 shell 概述

5.1.1 shell 是什么

5.1.2 shell 的分类

第二节 shell 脚本的执行方式

5.2.1 echo 输出命令

5.2.2 编写脚本 

5.2.3 执行脚本

第三节 Bash的基本功能

5.3.1 历史命令与命令补全

5.3.2 命名别名与常用快捷键

5.3.3 输入输出重定向

5.3.4 多命令执行与管道符

5.3.5 通配符与其他特殊符号

第四节 Bash 变量

5.4.1 用户自定义变量

5.4.2 环境变量

5.4.3 位置参数变量

5.4.4 预定义变量

 第五节 Bash运算符

5.5.1 数值运算与运算符

第六节 环境变量配置文件

5.6.1 配置文件简介

5.6.2 环境变量配置文件作用

5.6.3 其他配置文件和登录信息

第六章 Shell 编程

第一节 正则表达式

6.1.1 正则表达式与通配符

第二节 字符串截取命令

6.2.1 cut 字段提取命令

6.2.2 printf 命令

6.2.3 awk 命令

6.2.4 sed 命令

第三节 字符处理命令

6.3.1 排序命令 sort

6.3.2 wc 统计命令

**3、查看磁盘和分区信息**

\# mount | column -t  # 查看挂接的分区状态

\# fdisk -l                  # 查看所有分区

\# swapon -s             # 查看所有交换分区

\# hdparm -i /dev/hda  # 查看磁盘参数(仅适用于IDE设备)

\# dmesg | grep IDE  # 查看启动时IDE设备检测状况

**4、 打开文件数目：检查打开文件总数是否过多**

lsof |wc –l

**5、 查看网络信息**

ifconfig        # 查看所有网络接口的属性

iptables -L     # 查看防火墙设置

route -n        # 查看路由表

netstat -lntp   # 查看所有监听端口

netstat -antp   # 查看所有已经建立的连接

netstat -s      # 查看网络统计信息

**6、 核心日志：检查是否有异常错误记录**

dmesg

**7、 系统日志：检查是否有异常错误记录**

cat /var/log/rflogview/*errors

也可以搜索一些异常关键字：比如

grep –i error /var/log/messages

grep –i fail /var/log/messages

**8、查看服务**

chkconfig –list           # 列出所有系统服务

chkconfig –list | grep on # 列出所有启动的系统服务

**9、 检查是否有异常进程出现**

top –id 1

**10、 检查是否有分区使用率过高**

df –h

\#找出占用空间最多的文件或目录

du –cks * | sort –rn |head –n 10

**11、 磁盘I/O负载：检查I/O使用率是否超过100%**

Iostat –x 1 2

**12、 检查进程个数**

ps aux |wc –l

**13、tar解压命令**

参数说明：-x: 解压，-z:有gzip属性，-v:显示所有过程，-f:文件名，c:创建压缩文档

tar -xzvf file.tar #解压

tar -czvf /home/ccc.tar ccc/ #压缩

tar tfz ccc.tgz #查看压缩包内容

tar -zxvf ccc.tgz mylog.txt #解压压缩包中指定的文件

**14、 检查网络负载(网络流量是否过高)**

sar –n DEV

**15、 检查是否有网络错误**

netstat –i 或者cat /proc/net/dev

**16、 杀掉80端口相关的进程**

lsof –i :80|grep –v ”ID”|awk’{print “kill -9”,$2}’|sh

**17、 tcpdump抓包**

tcpdump –c 10000 –I eth0 –n dst port 80>/root/zhuabao

**18、 检查登录用户是否过多**

who |wc –l 或者uptime

**19、 按cpu利用率从大到小排序**

ps –e –o “%C:%p:%z:%a”|sort –nr

**20、 检查内存空间**

free 或者cat/proc/meminfo