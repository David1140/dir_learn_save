python-docs 官方文档  [python-docx — python-docx 1.1.2 文档](https://python-docx.readthedocs.io/en/latest/)

`pip3 install -i https://pypi.tuna.tsinghua.edu.cn/simple python-docx`。

实例

\# -*- coding: utf-8 -*-

import os

import glob

from docx import Document

def find_string_indocx(file_path,string):

  doc = Document(file_path)

  for paragraph in doc.paragraphs:

​    if string in paragraph.text:

​      print(paragraph.text);

  for table in doc.tables:

​    for row in table.rows:

​      for cell in row.cells:

​        if string in cell.text:

​            for cell2 in row.cells:

​              print(cell2.text, end=' ')

​            print()

​          

​         

folder_path = "/mnt/hgfs/ubuntu_free_dir/dir_work/补充文档/"  #将此处替换为你的.docx文件所在的文件夹路径

'''

old_string = "大师傅打发环境是否开放花萼法务"

new_string = "测试输出新字符"

'''

while True:

  string_find = "测试输出新字符"

  string_find = input("请输入你要寻找的字符串: ")

  print("你要查找的字符串是：",string_find,'\n','3s后开始查找\n')

  sleep(3)

  os.chdir(folder_path)

  for file in glob.glob("*.docx"):

​    find_string_indocx(file,string_find)