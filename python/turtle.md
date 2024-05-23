## 海龟库API调用方法

## 屏幕类（Screen）API 

1. **bye()**: 关闭画布并结束绘图程序。
2. **mainloop()**: 开始 Turtle 图形的主事件循环。
3. **exitonclick()**: 等待直到用户点击关闭按钮后关闭画布。
4. **bgcolor(\*args)**: 设置背景颜色。`*args` 是一个表示颜色的元组，例如 `(red, green, blue)`，每个分量的范围是 0 到 1。
5. **title(titlestring)**: 设置窗口的标题。
6. **setup(width=0.8, height=0.8, startx=None, starty=None)**: 设置窗口的大小和位置。
7. **screensize(canvwidth=None, canvheight=None, bg=None)**: 设置画布的大小。
8. **tracer(n=0, delay=0)**: 开启或关闭动画效果。
9. **listen()**: 打开或关闭窗口的监听模式。
10. **mode(modename)**: 切换绘图模式。
11. **bgpic(picname=None, filename=None)**: 设置背景图片。
12. **register_shape(name, shape)**: 注册一个新的形状。
13. **getcanvas()**: 返回当前画布对象。
14. **getscreen()**: 返回当前屏幕对象。
15. **getworldcoordinates()**: 返回当前坐标轴的范围。
16. **getwindow()**: 返回当前窗口对象。
17. **reset()**: 重置当前窗口的位置和大小。

海龟库（Turtle）的屏幕类 API 主要通过 `Screen` 类提供，这个类用于控制和设置画布窗口的各种属性。以下是 `Screen` 类的一些常用方法和它们的调用方法：

1. **初始化 Screen 对象**:

   ```
   import turtle
   screen = turtle.Screen()
   
       
   ```

2. **设置窗口标题**:

   ```
   screen.title("My Turtle Drawing")
   
       
   ```

3. **设置窗口大小**:

   ```
   screen.setup(width=800, height=600)  # 设置窗口宽为800像素，高为600像素
   
       
   ```

4. **设置窗口背景颜色**:

   ```
   screen.bgcolor(0, 0, 0)  # 设置背景颜色为黑色
   
       
   ```

5. **设置画布大小**:

   ```
   screen.setcanvassize(800, 600, 90)  # 设置画布宽为800像素，高为600像素，分辨率为90
   
       
   ```

6. **设置画布位置**:

   ```
   screen.setcanvasposition(-100, -100)  # 将画布左上角移动到指定的位置
   
       
   ```

7. **设置画笔速度**:

   ```
   screen.tracer(1)  # 打开动画效果，数字参数表示刷新频率
   
       
   ```

8. **关闭窗口**:

   ```
   screen.bye()
   
       
   ```

9. **监听鼠标事件**:

   ```
   screen.listen()
   
       
   ```

10. **设置画笔形状**:

    ```
    screen.register_shape("my_shape.gif")  # 注册一个新形状
    
        
    ```

11. **设置画笔形状**:

    ```
    screen.register_shape("my_shape.gif")  # 注册一个新形状
    
        
    ```

12. **获取当前画笔**:

    ```
    pen = screen.getcanvas().find_pen()
    
        
    ```

13. **获取当前画笔坐标**:

    ```
    x, y = pen.position()
    
        
    ```

14. **获取当前画笔颜色**:

    ```
    color = pen.color()
    
        
    ```

15. **获取当前画笔宽度**:

    ```
    width = pen.width()
    
        
    ```

16. **获取当前画笔角度**:

    ```
    angle = pen.angle()
    
        
    ```

17. **获取当前画笔状态**:

    ```
    isdown = pen.isdown()
    
        
    ```

18. **获取当前画笔形状**:

    ```
    shape = pen.shape()
    
        
    ```

19. **获取当前画笔轮廓**:

    ```
    outline = pen.outline()
    
        
    ```

20. **获取当前画笔填充颜色**:

    ```
    fill = pen.fillcolor()
    
        
    ```

21. **获取当前画笔填充状态**:

    ```
    isfilled = pen.isvisible()
    
        
    ```

22. **获取当前画笔速度**:

    ```
    speed = pen.speed()
    
        
    ```

23. **获取当前画笔字体**:

    ```
    font = pen.writefont()
    ```

## 画笔类（Turtle）API 

1. **penup()**: 抬起画笔，移动时不绘制线条。
2. **pendown()**: 放下画笔，移动时绘制线条。
3. **forward(distance)**: 向前移动指定的距离。
4. **backward(distance)**: 向后移动指定的距离。
5. **right(angle)**: 向右转指定的角度。
6. **left(angle)**: 向左转指定的角度。
7. **goto(x, y)**: 移动到指定的坐标位置。
8. **circle(radius, extent)**: 画一个圆或圆弧。
9. **color(\*args)**: 设置画笔的颜色。`*args` 是一个表示颜色的元组，例如 `(red, green, blue)`，每个分量的范围是 0 到 1。
10. **fillcolor(\*args)**: 设置填充颜色。`*args` 是一个表示颜色的元组。
11. **begin_fill()**: 开始填充图形。
12. **end_fill()**: 结束填充图形。
13. **width(width)**: 设置线条宽度。
14. **speed(speed)**: 设置海龟的移动速度。
15. **hideturtle()**: 隐藏海龟图标。
16. **showturtle()**: 显示海龟图标。
17. **home()**: 将海龟移回原点。
18. **shape(name=None)**: 设置海龟的形状。
19. **shapesize(stretch_wid=1.0, stretch_len=1.0, outline=1)**: 设置海龟的大小和轮廓宽度。
20. **seth(to_angle)**: 设置海龟的朝向。
21. **tilt(angle)**: 旋转画笔的角度。
22. **pencolor(color)**: 设置画笔颜色。
23. **write(arg, align='left', font=('Arial', 8, 'normal'))**: 在当前位置写文本。
24. **dot(size)**: 画一个点。
25. **clear()**: 清除当前图形。
26. **update()**: 更新画布以显示当前的绘图。

这些方法可以用来控制海龟的移动、转向、颜色、形状等，以及进行基本的绘图操作。使用这些方法时，通常需要先导入 turtle 模块，然后创建一个 Turtle 对象来访问这些方法。

海龟库（Turtle）的画笔类 API 主要通过 `Turtle` 类提供，这个类用于控制和设置一个单独的海龟（即画笔）的各种属性和行为。以下是 `Turtle` 类的一些常用方法和它们的调用方法：

1. **初始化 Turtle 对象**:

   ```
           import turtle
   pen = turtle.Turtle()
   
       
   ```

2. **移动海龟**:

   ```
           pen.forward(100)  # 向前移动100像素
   pen.backward(50)  # 向后移动50像素
   pen.right(90)  # 向右转90度
   pen.left(45)  # 向左转45度
   pen.goto(x, y)  # 移动到指定的坐标位置
   
       
   ```

3. **控制画笔状态**:

   ```
           pen.penup()  # 抬起画笔，移动时不绘制线条
   pen.pendown()  # 放下画笔，移动时绘制线条
   
       
   ```

4. **设置画笔颜色**:

   ```
           pen.color("red")  # 设置画笔颜色为红色
   pen.color(255, 0, 0)  # 设置画笔颜色为RGB值(255, 0, 0)
   
       
   ```

5. **设置画笔填充颜色**:

   ```
           pen.fillcolor("blue")  # 设置填充颜色为蓝色
   
       
   ```

6. **开始填充图形**:

   ```
           pen.begin_fill()  # 开始填充图形
   
       
   ```

7. **结束填充图形**:

   ```
           pen.end_fill()  # 结束填充图形
   
       
   ```

8. **设置画笔宽度**:

   ```
           pen.width(5)  # 设置画笔宽度为5像素
   
       
   ```

9. **设置画笔速度**:

   ```
           pen.speed(1)  # 设置画笔速度，1是最慢的速度，0是最快的速度
   
       
   ```

10. **隐藏或显示海龟**:

    ```
            pen.hideturtle()  # 隐藏海龟
    pen.showturtle()  # 显示海龟
    
        
    ```

11. **设置画笔形状**:

    ```
            pen.shape("turtle")  # 设置海龟形状为默认的乌龟形状
    
        
    ```

12. **设置画笔轮廓**:

    ```
            pen.pensize(3)  # 设置画笔轮廓宽度为3像素
    
        
    ```

13. **设置画笔字体**:

    ```
            pen.writefont(("Arial", 24, "normal"))  # 设置字体为Arial，大小为24，样式为正常
    
        
    ```

14. **在当前位置写文本**:

    ```
            pen.write("Hello, World!")  # 在当前位置写文本
    
        
    ```

15. **清空画布**:

    ```
            pen.clear()  # 清空画布上的内容
    
        
    ```

16. **重置海龟状态**:

    ```
    
    pen.reset()  # 重置海龟到初始状态
    ```