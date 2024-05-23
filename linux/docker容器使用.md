<div align="center">Docker镜像和容器学习使用</div>

# 一、Docker容器配置环境和增删改查

Docker容器是一种**轻量级、可移植的软件打包方式**，它将应用程序及其所有依赖项打包到一个独立的运行环境中，包括文件系统、系统工具、库等，确保应用程序在任何环境中都能一致运行。 以下是使用Docker容器的基本步骤： 

1.**安装Docker：**首先，你需要在你的系统上安装Docker引擎。你可以从Docker官方网站下载适用于你系统的安装包，并按照指南进行安装。 

2.**拉取镜像：**Docker容器是基于镜像构建的。你可以使用docker pull命令从Docker Hub或其他镜像仓库中拉取镜像到本地系统。例如，要拉取官方的Ubuntu镜像，你可以运行以下命令： **docker pull ubuntu** 

3.**运行容器：**一旦你有了镜像，你就可以使用**docker run**命令来创建并运行容器。例如，要在后台运行一个基于Ubuntu镜像的容器，你可以运行以下命令： **docker run -d ubuntu** 这将创建一个后台运行的Ubuntu容器，并输出容器的ID。

​	运行容器参数： -i-t-d 分别代表交互，终端，分离

​	--name 容器命名 --net（=host）网络模式 （镜像版本 交互脚本：/bin/bash）

​	-v 挂载数据卷（volumes）

4.**进入容器：**你可以使用docker exec命令进入运行中的容器并在其中执行命令。例如，要进入刚才创建的Ubuntu容器，你可以运行以下命令：

- **docker attach**

-  **docker exec -it <容器ID> /bin/bash** 这会在容器内打开一个新的bash会话，允许你执行命令。 (-i表示交互。-t表示打开终端)
- 两者的区别在于前者退出会结束容器，后者则不会

5.**管理容器：**你可以使用**docker ps**命令查看运行中的容器列表，使用**docker stop**命令停止容器，使用**docker start**命令启动已停止的容器，使用**docker rm**命令删除容器等。 这些是使用Docker容器的基本步骤。随着你的使用和了解的加深，你会发现Docker有更多强大的功能和用法。如果你有具体的问题或需要更多帮助，请随时提问！

导出和导入容器

**导出容器**

如果要导出本地某个容器，可以使用 **docker export** 命令。

```
$ docker export 1e560fca3906 > ubuntu.tar
```

导出容器 1e560fca3906 快照到本地文件 ubuntu.tar。

[![img](https://www.runoob.com/wp-content/uploads/2016/05/docker-export.png)](https://www.runoob.com/wp-content/uploads/2016/05/docker-export.png)

这样将导出容器快照到本地文件。

**导入容器快照**

可以使用 docker import 从容器快照文件中再导入为镜像，以下实例将快照文件 ubuntu.tar 导入到镜像 test/ubuntu:v1:

```
$ cat docker/ubuntu.tar | docker import - test/ubuntu:v1
```

[![img](https://www.runoob.com/wp-content/uploads/2016/05/docker-import.png)](https://www.runoob.com/wp-content/uploads/2016/05/docker-import.png)

此外，也可以通过指定 URL 或者某个目录来导入，例如：

```
$ docker import http://example.com/exampleimage.tgz example/imagerepo
```

删除容器

删除容器使用 **docker rm** 命令：

```
$ docker rm -f 1e560fca3906
```

[![img](https://www.runoob.com/wp-content/uploads/2016/05/docker-container-rmi.png)](https://www.runoob.com/wp-content/uploads/2016/05/docker-container-rmi.png)

下面的命令可以清理掉所有处于终止状态的容器。

$ docker container prune

# 二、创建docker镜像流程

1.在终端命令行新建文件dockerfile 写好后保存

2.docker build -t  <容器代号>  <dockerfile文件路径>       // *创建docker镜像*

3.docker run (-d) <容器代号>                                               //运行容器 -d代表是否设置成分离属性

编写Dockefile->Dockefile范例

```dockerfile
#使用ubuntu作为基础镜像
FROM ubuntu
# 设置工作目录为 /app
WORKDIR /work_dir

# 复制当前目录下的所有文件到容器的 /app 目录中
COPY . /work_dir
#运行指令 
CMD ["./1"] #执行该可执行文件
```

# 三、Dockerfile 中常用的指令和语法：

Dockerfile 是用来定义 Docker 镜像的构建步骤和配置的文件，它包含了一系列的指令来描述镜像的构建过程。以下是 Dockerfile 中常用的指令和语法：

1. **FROM：** 指定基础镜像，用于构建当前镜像的基础。

   ```
   FROM <image>
   ```

2. **RUN：** 在镜像中执行命令，用于安装软件包、配置环境等。

   ```
   RUN <command>
   ```

3. **CMD：** 指定容器启动时要执行的命令。如果在 Dockerfile 中有多个 CMD 指令，只有最后一个 CMD 指令会生效。

   ```
   CMD ["executable","param1","param2"]
   ```

4. **ENTRYPOINT：** 设置容器启动时执行的可执行文件。

   ```
   ENTRYPOINT ["executable", "param1", "param2"]
   ```

5. **WORKDIR：** 设置工作目录，后续命令将在这个目录下执行。

   ```
   WORKDIR /path/to/directory
   ```

6. **COPY：** 将文件从宿主机复制到镜像中。

   ```
   COPY <src> <dest>
   ```

7. **ADD：** 类似于 COPY，但功能更强大，可以处理 URL 和解压缩文件。

   ```
   ADD <src> <dest>
   ```

8. **EXPOSE：** 指定容器运行时监听的端口。

   ```
   EXPOSE <port>
   ```

9. **ENV：** 设置环境变量。

   ```
   ENV <key> <value>
   ```

10. **ARG：** 定义构建时的参数，类似于变量，可以在构建时传递给 Docker。

    ```
    ARG <name>[=<default value>]
    ```

11. **VOLUME：** 创建挂载点，用于持久化数据。

    ```
    VOLUME /path/to/volume
    ```

12. **USER：** 指定运行容器时的用户。

    ```
    USER <username>
    ```

13. **LABEL：** 为镜像添加元数据，如版本信息、维护者等。

    ```
    LABEL <key>=<value>
    ```

14. **HEALTHCHECK：** 定义容器健康检查。

    ```
    HEALTHCHECK [options] CMD command
    ```

15. **SHELL：** 指定默认的 shell 环境。

    ```
    SHELL ["executable", "parameters"]
    ```

这些是 Dockerfile 中常用的指令和语法，你可以根据自己的需求组合和使用它们来构建自定义的 Docker 镜像。

# 四、镜像仓库下载

## 1.拉取镜像失败添加国内镜像地址

国外的不让用，国内的镜像地址：[https://registry.docker-cn.com](https://registry.docker-cn.com/)，修改完之后重启应该就可以了

“uses outdated schema1 manifest format. Please upgrade to a schema2 image for better future compatibility. More information at https://docs.docker.com/registry/spec/deprecated-schema-v1/”报错

### 1）sudo nano /etc/docker/daemon.json//执行指令写入

```json
{
  "debug": true,
  "registry-mirrors": [ //add
   "https://registry.docker-cn.com"
  ],
}
```

### 2）保存并关闭文件然后重启服务sudo systemctl restart docker

镜像仓库有以下几个，提供给大家，供大家参考：**

Docker Hub官方库：

[https://hub.Docker.com/](https://link.zhihu.com/?target=https%3A//hub.Docker.com/)

云厂商：

UCloud [https://docs.ucloud.cn/compute/uhub/index](https://link.zhihu.com/?target=https%3A//docs.ucloud.cn/compute/uhub/index)

Daocloud [https://hub.daocloud.io/](https://link.zhihu.com/?target=https%3A//hub.daocloud.io/)

# 五、仓库搭建

私有库：

基于harbor搭建[https://goharbor.io/](https://link.zhihu.com/?target=https%3A//goharbor.io/)

**如何使用？**

登录

docker login –u xxx@ucloud.cn –p xxxxxx [http://uhub.service.ucloud.cn](https://link.zhihu.com/?target=http%3A//uhub.service.ucloud.cn)

Push镜像

docker push [http://uhub.service.ucloud.cn/bucket/helloworld:v1](https://link.zhihu.com/?target=http%3A//uhub.service.ucloud.cn/bucket/helloworld%3Av1)

Pull镜像

docker pull [http://uhub.service.ucloud.cn/bucket/helloworld:v1](https://link.zhihu.com/?target=http%3A//uhub.service.ucloud.cn/bucket/helloworld%3Av1)

# **六、我们如何进行容器的运行和容器的服务暴露？**

## 1.运行容器服务

docker run helloworld:v1

## 2.暴露端口

docker run -p :8000 helloworld:v1

## 3.暴露端口&映射端口

docker run -p 80:8000 helloworld:v1

## 4.多端口

docker run -p 80:8000 –p 443:8000 helloworld:v1

容器运行了，那么我们新的问题又来了，容器是一个在容器镜像最上层构建的一个层级，对它修改它都不能持久化，那我们如何对容器应用进行业务文件收集、日志收集呢？

**我们可以通过容器挂载目录的形式将我们需要做持久化的文件生命周期从容器中独立出来，例如：**



## 5.数据卷挂载

docker run -p 80:8000 –v vol:/data helloworld:v1

vol 是主机目录 data是容器内目标目录 后面是docker 镜像名称

## 6.宿主目录挂载

docker run -p 80:8000 –v /data/my-app:/data helloworld:v1

这样我们就可以对容器中我们需要做持久化存储的文件进行管理了。

在 Docker 容器中查看已挂载的数据卷，你可以使用 `docker inspect` 命令或者进入容器内部查看。以下是具体的方法：

1. **使用 `docker inspect` 命令**:

   使用 `docker inspect` 命令可以查看容器的详细信息，包括挂载的数据卷。运行以下命令并替换 `container_id_or_name` 为你的容器ID或名称：

   ```
           sh复制代码运行docker inspect container_id_or_name
   
       
   ```

   输出的信息中，会有一个 `Mounts` 部分，展示了所有挂载到该容器的卷和绑定挂载点。

2. **进入容器内部查看**:

   如果你想要直接在容器内部查看挂载的文件或目录，可以先进入容器：

   ```
           sh复制代码运行docker exec -it container_id_or_name /bin/bash
   
       
   ```

   然后，你可以在容器内使用 `ls` 命令或其他shell命令来查看挂载的文件系统。

3. **使用 `docker volume ls` 查看数据卷**:

   如果你想要查看与容器关联的特定数据卷，可以使用 `docker volume ls` 命令列出所有数据卷，并使用 `docker volume inspect` 查看特定卷的详细信息：

   ```
           sh复制代码运行docker volume ls
   docker volume inspect volume_name_or_id
   
       
   ```

4. **使用 `docker compose ps` 命令** (如果你使用 Docker Compose):

   如果你使用的是 Docker Compose，可以使用 `docker compose ps` 命令查看服务的状态，它会显示每个服务的容器名称。然后，你可以使用 `docker inspect` 查看这些容器的挂载信息。

通过以上方法，你可以轻松地查看 Docker 容器中的已挂载数据卷。

### （2）绑定挂载

​	 --mount type=bind,source=/new/host/path,target=/container/path \
