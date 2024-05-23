一、工作流程

1. 创建 Paddle Lite 模型

   准备模型-》模型优化

2.  运行推断

​		下载或编译：Paddle Lite 提供了 `Android/IOS/ArmLinux/Windows/MacOS/Ubuntu` 平台的官方 Release 预测库下载，我们优先推荐您直接下载 [Paddle Lite 预编译库](https://www.paddlepaddle.org.cn/lite/v2.12/quick_start/release_lib.html)。您也可以根据目标平台选择对应的 [源码编译](https://www.paddlepaddle.org.cn/lite/v2.12/source_compile/compile_env.html)。Paddle Lite 提供了源码编译脚本，位于 `lite/tools/` 文件夹下，只需要 [准备环境](https://www.paddlepaddle.org.cn/lite/v2.12/source_compile/docker_env.html) 和 `lite/tools/` 文件夹 [脚本](https://github.com/PaddlePaddle/Paddle-Lite/tree/release/v2.12/lite/tools) 两个步骤即可一键编译得到目标平台的 Paddle Lite 预测库。

开发应用程序

- 使用 Paddle Lite API，在多个平台和语言中均受支持（如 [Java](https://www.paddlepaddle.org.cn/lite/v2.12/user_guides/java_demo.html)、[C++](https://www.paddlepaddle.org.cn/lite/v2.12/user_guides/cpp_demo.html)、[Python](https://www.paddlepaddle.org.cn/lite/v2.12/user_guides/python_demo.html)）
- 配置参数（`MobileConfig`），设置模型来源等
- 创建推理器（Predictor），调用 `CreatePaddlePredictor` 接口即可创建
- 设置模型输入，通过 `predictor->GetInput(i)` 获取输入变量，并为其指定大小和数值
- 执行预测，只需要调用 `predictor->Run()`
- 获得输出，使用 `predictor->GetOutput(i)` 获取输出变量，并通过 `data<T>` 取得输出值
- 在有 GPU 的设备上，您可以使用 [OpenCL](https://www.paddlepaddle.org.cn/lite/v2.12/demo_guides/opencl.html) 加速来提升性能。



二、准备步骤

​	1.搭建docker容器环境

​	

```
# 方式一：从 Dockerhub 直接拉取 Docker 镜像
docker pull paddlepaddle/paddle-lite:2.0.0_beta

# 方式二：本地源码编译 Docker 镜像
git clone https://github.com/PaddlePaddle/Paddle-Lite.git
cd Paddle-Lite/lite/tools
mkdir mobile_image
cp Dockerfile.mobile mobile_image/Dockerfile
cd mobile_image
docker build -t paddlepaddle/paddle-lite .

# 镜像编译成功后，可用 docker images 命令，看到 paddlepaddle/paddle-lite 镜像。

启动 Docker 容器
启动 Docker 容器，在拉取 Paddle Lite 仓库代码的上层目录，执行如下代码，进入 Docker 容器：

docker run -it \
  --name paddlelite_docker \
  -v $PWD/Paddle-Lite:/Paddle-Lite \
  --net=host \
  paddlepaddle/paddle-lite /bin/bash该命令的含义：将容器命名为paddlelite_docker即<container-name>，将当前目录下的Paddle-Lite文件夹挂载到容器中的/Paddle-Lite这个根目录下，并进入容器中。
```

2.下载 [Paddle Lite 预编译库](https://www.paddlepaddle.org.cn/lite/v2.12/quick_start/release_lib.html)。

运行图像分类示例程序[¶](https://www.paddlepaddle.org.cn/lite/v2.12/demo_guides/x86.html#yunxingtuxiangfenleishilichengxu)

- 下载示例程序[ PaddleLite-generic-demo.tar.gz ](https://paddlelite-demo.bj.bcebos.com/devices/generic/PaddleLite-generic-demo_v2_12_0.tar.gz)，解压后清单如下：

- 进入 `PaddleLite-generic-demo/image_classification_demo/shell/`；

- 执行以下命令观察 mobilenet_v1_int8_224_per_layer 模型的性能和结果；

- 

- ```
  运行 mobilenet_v1_int8_224_per_layer 模型
  
  For linux amd64
  本地执行
  $ ./run.sh mobilenet_v1_int8_224_per_layer imagenet_224.txt test linux amd64 cpu
  通过 SSH 远程执行
  $ ./run_with_ssh.sh mobilenet_v1_int8_224_per_layer imagenet_224.txt test linux amd64 cpu <IP地址> 22 <用户名> <密码>
  
    Top1 Egyptian cat - 0.500662
    Top2 tabby, tabby cat - 0.407661
    Top3 tiger cat - 0.074697
    Top4 lynx, catamount - 0.013188
    Top5 ping-pong ball - 0.000638
    Preprocess time: 27.854000 ms, avg 27.854000 ms, max 27.854000 ms, min 27.854000 ms
    Prediction time: 55.152000 ms, avg 55.152000 ms, max 55.152000 ms, min 55.152000 ms
    Postprocess time: 6.212000 ms, avg 6.212000 ms, max 6.212000 ms, min 6.212000 ms
  ```

- 如果需要更改测试模型为 resnet50，执行命令修改为如下：

  ```
  本地执行
  $ ./run.sh resnet50_fp32_224 imagenet_224.txt test linux amd64 cpu
  通过 SSH 远程执行
  $ ./run_with_ssh.sh resnet50_fp32_224 imagenet_224.txt test linux amd64 cpu <IP地址>22<用户名><密码>
  ```

- 如果需要更改测试图片，可将图片拷贝到 `PaddleLite-generic-demo/image_classification_demo/assets/datasets/test/inputs` 目录下，同时将图片文件名添加到 `PaddleLite-generic-demo/image_classification_demo/assets/datasets/test/list.txt` 中；

- 如果需要重新编译示例程序，直接运

- ```
  For linux amd64
  $ ./build.sh linux amd64
  ```