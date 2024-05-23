## 一、基本语法

在Shell脚本中，井号（#）和井号感叹号（#!）具有不同的含义和用途。具体分析如下：

- **井号（#）**：在Shell脚本中，井号（#）主要用作注释符号。它用来表示该行代码是注释，不会被Shell解释器执行。这对于解释代码功能、提供提示信息或者临时禁用某段代码非常有用。
- **井号感叹号（#!）**：井号感叹号（#!）在Shell脚本中有特殊的意义，它位于脚本文件的第一行，被称为shebang。Shebang指示了用于执行该脚本的解释器路径。当一个脚本被当作可执行程序运行时，操作系统会根据shebang里的内容来选择使用哪个解释器来运行该脚本。例如，`#!/bin/bash` 指定了使用Bash shell来执行脚本。

### 1.变量初始化

​	xx=xx 使用时$(变量名)

### 2.分支语句

#### （1）if语句

​		if [判断条件]；then

​			执行语句

​		fi

​		if [[判断条件]]；then适用于更复杂的判断条件

​			执行语句

​		fi

### 3.循环语句

#### 	(1)for循环

​		for NNADAPTER_DEVICE_NAME in ${NNADAPTER_DEVICE_NAMES_LIST[@]}

​		do

 			export LD_LIBRARY_PATH=./libs/PaddleLite/$TARGET_OS/$TARGET_ABI/lib/$NNADAPTER_DEVICE_NAME:$LD_LIBRARY_PATH

​		done

### 4.参数替换功能

​	${变量//,/_} 用于将变量中的，全部不替换成“\”(下划线)的参数替换功能



## 二、关键词使用

### 1.设置运行参数

- `set -x`： 运行shell脚本时输出运行结果

- `set -o`：用来开启或关闭Shell的特殊功能。
- `set -e`：当命令返回非零状态时，终止脚本的执行。
- `set -u`：在使用未定义的变量时，产生错误信息。
- `set -v`：在执行前输出所有命令。

### 2.引入环境变量

​	export  xxx=xxx

### 3.终端输出

​	echo

### 4.退出程序

​	exit 