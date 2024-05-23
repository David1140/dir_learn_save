Ubuntu安装minikube官方文档看这里~

完成Docker十分钟了解Docker（我的Docker学习笔记）和kubectlUbuntu安装kubectl的下载安装后，就可以进行minikube的安装了，它能够帮助我们在本地非常容易的启动和管理k8s集群，适合个人单机学习和测试。
参考博文Minikube - Kubernetes本地实验环境

通过命令curl -Lo minikube https://kubernetes.oss-cn-hangzhou.aliyuncs.com/minikube/releases/v1.23.1/minikube-linux-amd64安装minicube
等待下载完成后可以看到minikube文件

(base) zou@zou-virtual-machine:~/Downloads$ ls
Anaconda3-2019.03-Linux-x86_64.sh
kubectl
minikube
music
photo
pycharm-2020.3.2
tensorflow-1.15.0-cp37-cp37m-manylinux2010_x86_64.whl
wallpaper
1
2
3
4
5
6
7
8
9
对minikube增加可执行权限x，并将其加入/usr/local/bin路径，以便于我们输入minikube可以找到该命令
(base) zou@zou-virtual-machine:~/Downloads$ sudo chmod +x minikube
[sudo] password for zou: 
(base) zou@zou-virtual-machine:~/Downloads$ sudo mv minikube /usr/local/bin
1
2
3
通过命令minikube start启动minikube，可以自带参数，各参数含义：

这里实际采用的启动命令为：
minikube start --image-mirror-country=cn \
--iso-url=https://kubernetes.oss-cn-hangzhou.aliyuncs.com/minikube/iso/minikube-v1.6.0.iso \
--registry-mirror=https://9y59utpb.mirror.aliyuncs.com --driver=docker
1
2
3
但失败了，出现了以下报错（Exiting due to PROVIDER_DOCKER_NEWGRP: “docker version --format -” exit status 1: Got permission denied while trying to connect to the Docker daemon socket at unix😕//var/run/docker.sock: Get “http://%2Fvar%2Frun%2Fdocker.sock/v1.24/version”: dial unix /var/run/docker.sock: connect: permission denied）：

(base) zou@zou-virtual-machine:~/Downloads$  minikube start --image-mirror-country=cn --iso-url=https://kubernetes.oss-cn-hangzhou.aliyuncs.com/minikube/iso/minikube-v1.6.0.iso --registry-mirror=https://9y59utpb.mirror.aliyuncs.com --driver=docker
😄  minikube v1.23.1 on Ubuntu 18.04
🎉  minikube 1.23.2 is available! Download it: https://github.com/kubernetes/minikube/releases/tag/v1.23.2
💡  To disable this notice, run: 'minikube config set WantUpdateNotification false'

✨  Using the docker driver based on user configuration

💣  Exiting due to PROVIDER_DOCKER_NEWGRP: "docker version --format -" exit status 1: **Got permission denied while trying to connect to the Docker daemon socket at unix**:///var/run/docker.sock: Get "http://%2Fvar%2Frun%2Fdocker.sock/v1.24/version": dial unix /var/run/docker.sock: connect: permission denied
💡  Suggestion: Add your user to the 'docker' group: 'sudo usermod -aG docker $USER && newgrp docker'
📘  Documentation: https://docs.docker.com/engine/install/linux-postinstall/
1
2
3
4
5
6
7
8
9
10
根据提示，将当前Linux用户加入docker组后，再次执行启动minikube命令：

(base) zou@zou-virtual-machine:~/Downloads$ sudo usermod -aG docker $USER && newgrp docker
(base) zou@zou-virtual-machine:~/Downloads$ minikube start --image-mirror-country=cn --iso-url=https://kubernetes.oss-cn-hangzhou.aliyuncs.com/minikube/iso/minikube-v1.6.0.iso --registry-mirror=https://9y59utpb.mirror.aliyuncs.com --driver=docker
😄  minikube v1.23.1 on Ubuntu 18.04
✨  Using the docker driver based on user configuration
✅  Using image repository registry.cn-hangzhou.aliyuncs.com/google_containers
👍  Starting control plane node minikube in cluster minikube
🚜  Pulling base image ...
❗  The image 'registry.cn-hangzhou.aliyuncs.com/google_containers/coredns/coredns:v1.8.4' was not found; unable to add it to cache.
    > registry.cn-hangzhou.aliyun...: 355.39 MiB / 355.40 MiB  100.00% 3.39 MiB
🔥  Creating docker container (CPUs=2, Memory=2200MB) ...

🧯  Docker is nearly out of disk space, which may cause deployments to fail! (90% of capacity)
💡  Suggestion: 

    Try one or more of the following to free up space on the device:
    
    1. Run "docker system prune" to remove unused Docker data (optionally with "-a")
    2. Increase the storage allocated to Docker for Desktop by clicking on:
    Docker icon > Preferences > Resources > Disk Image Size
    3. Run "minikube ssh -- docker system prune" if using the Docker container runtime
🍿  Related issue: https://github.com/kubernetes/minikube/issues/9024

🐳  Preparing Kubernetes v1.22.1 on Docker 20.10.8 ...
❌  Unable to load cached images: loading cached images: stat /home/zou/.minikube/cache/images/registry.cn-hangzhou.aliyuncs.com/google_containers/coredns/coredns_v1.8.4: no such file or directory
    > kubeadm.sha256: 64 B / 64 B [--------------------------] 100.00% ? p/s 0s
    > kubelet.sha256: 64 B / 64 B [--------------------------] 100.00% ? p/s 0s
    > kubectl.sha256: 64 B / 64 B [--------------------------] 100.00% ? p/s 0s
    > kubectl: 44.73 MiB / 44.73 MiB [---------------] 100.00% 3.50 MiB p/s 13s
    > kubeadm: 43.71 MiB / 43.71 MiB [---------------] 100.00% 2.42 MiB p/s 18s
    > kubelet: 146.25 MiB / 146.25 MiB [-------------] 100.00% 5.64 MiB p/s 26s
    ▪ Generating certificates and keys ...
    ▪ Booting up control plane ...
    ▪ Configuring RBAC rules ...
🔎  Verifying Kubernetes components...
    ▪ Using image registry.cn-hangzhou.aliyuncs.com/google_containers/storage-provisioner:v5
🌟  Enabled addons: default-storageclass, storage-provisioner
🏄  Done! kubectl is now configured to use "minikube" cluster and "default" namespace by default
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
这次启动成功，并且可以从输出中看到下载了k8s组件kubeadm、kubectl、kubelet，根据最后一行的one! kubectl is now configured to use "minikube" cluster and "default" namespace by default可以知道现在已经有了minikube集群。

通过执行minikube status检查状态：

(base) zou@zou-virtual-machine:~/Downloads$ minikube status
minikube
type: Control Plane
host: Running
kubelet: Running
apiserver: Running
kubeconfig: Configured
1
2
3
4
5
6
7
minikube的输出好可爱啊。

命令测试：
命令行方式创建pod然后查看其状态：

(base) zou@zou-virtual-machine:~$ kubectl run test-pod --image=nginx --port=6379
pod/test-pod created
(base) zou@zou-virtual-machine:~$ kubectl get po
NAME       READY   STATUS              RESTARTS   AGE
test-pod   0/1     ContainerCreating   0          12s
(base) zou@zou-virtual-machine:~$ kubectl get pods
NAME       READY   STATUS              RESTARTS   AGE
test-pod   0/1     ContainerCreating   0          15s
(base) zou@zou-virtual-machine:~$ kubectl get pods -o wide
NAME       READY   STATUS    RESTARTS   AGE   IP           NODE       NOMINATED NODE   READINESS GATES
test-pod   1/1     Running   0          57s   172.17.0.3   minikube   <none>           <none>
1
2
3
4
5
6
7
8
9
10
11
实际是运行了一个deployment，还可以看到test-pod经历了ContainerCreating， Running两种运行时状态，属于minikube节点。

删除pods：

(base) zou@zou-virtual-machine:~$ kubectl delete pod test-pod
pod "test-pod" deleted
1
2
对了，长时间不操作再使用kubecrl命令可能会出现以下报错Unable to connect to the server: dial tcp 192.168.49.2:8443: connect: no route to host，这时需要重新启动minikube。

完结撒花★,°:.☆(￣▽￣)/$:.°★ 
————————————————

                            版权声明：本文为博主原创文章，遵循 CC 4.0 BY-SA 版权协议，转载请附上原文出处链接和本声明。

原文链接：https://blog.csdn.net/qq_40486952/article/details/120490950