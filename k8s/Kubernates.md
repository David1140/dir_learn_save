隐藏页面特效

# 

***1\***|***0\*****K8S**

***1\***|***1\*****1.1 Kubernetes简介**

[![img](https://images2017.cnblogs.com/blog/1190037/201802/1190037-20180203175245328-1183720416.png)](https://images2017.cnblogs.com/blog/1190037/201802/1190037-20180203175245328-1183720416.png)

### 1.1.1 什么是Kubernetes

Kubernetes (通常称为K8s，K8s是将8个字母“ubernete”替换为“8”的缩写) 是用于**自动部署、扩展和管理容器化（****containerized****）应用程序的开源系统**。Google设计并捐赠给Cloud Native Computing Foundation（今属Linux基金会）来使用的。

它旨在提供“跨主机集群的自动部署、扩展以及运行应用程序容器的平台”。它支持一系列容器工具, 包括Docker等。CNCF于2017年宣布首批Kubernetes认证服务提供商（KCSPs），包含IBM、MIRANTIS、华为、inwinSTACK迎栈科技等服务商。

### 1.1.2 Kubernetes发展史

Kubernetes (希腊语"舵手" 或 "飞行员") 由Joe Beda，Brendan Burns和Craig McLuckie创立，并由其他谷歌工程师，包括Brian Grant和Tim Hockin进行加盟创作，并由谷歌在2014年首次对外宣布 。它的开发和设计都深受谷歌的Borg系统的影响，它的许多顶级贡献者之前也是Borg系统的开发者。在谷歌内部，Kubernetes的原始代号曾经是Seven，即星际迷航中友好的Borg(博格人)角色。Kubernetes标识中舵轮有七个轮辐就是对该项目代号的致意。

Kubernetes v1.0于2015年7月21日发布。随着v1.0版本发布，谷歌与Linux 基金会合作组建了Cloud Native Computing Foundation (CNCF)并把Kubernetes作为种子技术来提供。

Rancher Labs在其Rancher容器管理平台中包含了Kubernetes的发布版。Kubernetes也在很多其他公司的产品中被使用，比如Red Hat在OpenShift产品中，CoreOS的Tectonic产品中， 以及IBM的IBM云私有产品中。

### 1.1.3 Kubernetes 特点

1、可移植: 支持公有云，私有云，混合云，多重云（multi-cloud）

2、可扩展: 模块化, 插件化, 可挂载, 可组合

3、自动化: 自动部署，自动重启，自动复制，自动伸缩/扩展

4、快速部署应用，快速扩展应用

5、无缝对接新的应用功能

6、节省资源，优化硬件资源的使用

### 1.1.4 Kubernetes规划组件

参考文档：http://docs.kubernetes.org.cn/249.html

Kubernetes定义了一组构建块，它们可以共同提供部署、维护和扩展应用程序的机制。组成Kubernetes的组件设计为松耦合和可扩展的，这样可以满足多种不同的工作负载。可扩展性在很大程度上由**Kubernetes API**提供——它被作为扩展的内部组件以及Kubernetes上运行的容器等使用。

**Pod**

Kubernetes的基本调度单元称为“pod”。它可以把更高级别的抽象内容增加到容器化组件。一个pod一般包含一个或多个容器，这样可以保证它们一直位于主机上，并且可以共享资源。Kubernetes中的每个pod都被分配一个唯一的（在集群内的）IP地址这样就可以允许应用程序使用端口，而不会有冲突的风险。

Pod可以定义一个卷，例如本地磁盘目录或网络磁盘，并将其暴露在pod中的一个容器之中。pod可以通过Kubernetes API手动管理，也可以委托给控制器来管理。

**标签和选择器**

Kubernetes使客户端（用户或内部组件）将称为“标签”的键值对附加到系统中的任何API对象，如pod和节点。相应地，“标签选择器”是针对匹配对象的标签的查询。

标签和选择器是Kubernetes中的主要分组机制，用于确定操作适用的组件。

例如，如果应用程序的Pods具有系统的标签 tier ("front-end", "back-end", for example) 和一个 release_track ("canary", "production", for example)，那么对所有"back-end" 和 "canary" 节点的操作可以使用如下所示的标签选择器：

 tier=back-end AND release_track=canary 

**控制器**

控制器是将实际集群状态转移到所需集群状态的对帐循环。它通过管理一组**pod**来实现。一种控制器是一个“复制控制器”，它通过在集群中运行指定数量的pod副本来处理复制和缩放。如果基础节点出现故障，它还可以处理创建替换pod。

其它控制器，是核心Kubernetes系统的一部分包括一个“DaemonSet控制器”为每一台机器（或机器的一些子集）上运行的恰好一个pod，和一个“作业控制器”用于运行pod运行到完成，例如作为批处理作业的一部分。控制器管理的一组pod由作为控制器定义的一部分的标签选择器确定。

**服务**

Kubernetes服务是一组协同工作的pod，就像多层架构应用中的一层。构成服务的pod组通过标签选择器来定义。

Kubernetes通过给服务分配静态IP地址和域名来提供服务发现机制，并且以轮询调度的方式将流量负载均衡到能与选择器匹配的pod的IP地址的网络连接上（即使是故障导致pod从一台机器移动到另一台机器）。默认情况下，一个服务会暴露在集群中（例如，多个后端pod可能被分组成一个服务，前端pod的请求在它们之间负载平衡）；但是，一个服务也可以暴露在集群外部（例如，从客户端访问前端pod）。

### 1.1.5 Kubernetes核心组件

Kubernetes遵循*master-slave architecture*。Kubernetes的组件可以分为管理单个的 node 组件和控制平面的一部分的组件。

Kubernetes Master是集群的主要控制单元，用于管理其工作负载并指导整个系统的通信。Kubernetes控制平面由各自的进程组成，每个组件都可以在单个主节点上运行，也可以在支持*high-availability clusters*的多个主节点上运行。

Kubernetes主要由以下几个核心组件组成：

| **组件名称**           | **说明**                                                     |
| ---------------------- | ------------------------------------------------------------ |
| **etcd**               | 保存了整个集群的状态；                                       |
| **apiserver**          | 提供了资源操作的唯一入口，并提供认证、授权、访问控制、API注册和发现等机制； |
| **controller manager** | 负责维护集群的状态，比如故障检测、自动扩展、滚动更新等；     |
| **scheduler**          | 负责资源的调度，按照预定的调度策略将Pod调度到相应的机器上；  |
| **kubelet**            | 负责维护容器的生命周期，同时也负责Volume（CVI）和网络（CNI）的管理； |
| **Container runtime**  | 负责镜像管理以及Pod和容器的真正运行（CRI）；                 |
| **kube-proxy**         | 负责为Service提供cluster内部的服务发现和负载均衡；           |

核心组件结构图

[![img](https://images2017.cnblogs.com/blog/1190037/201802/1190037-20180203175259843-780547270.png)](https://images2017.cnblogs.com/blog/1190037/201802/1190037-20180203175259843-780547270.png) 

除了核心组件，还有一些推荐的Add-ons：

| **组件名称**              | **说明**                     |
| ------------------------- | ---------------------------- |
| **kube-dns**              | 负责为整个集群提供DNS服务    |
| **Ingress Controller**    | 为服务提供外网入口           |
| **Heapster**              | 提供资源监控                 |
| **Dashboard**             | 提供GUI                      |
| **Federation**            | 提供跨可用区的集群           |
| **Fluentd-elasticsearch** | 提供集群日志采集、存储与查询 |

### 1.1.6 分层架构

Kubernetes设计理念和功能其实就是一个类似Linux的分层架构，如下图所示：

[![img](https://images2017.cnblogs.com/blog/1190037/201802/1190037-20180203175310937-357350103.png)](https://images2017.cnblogs.com/blog/1190037/201802/1190037-20180203175310937-357350103.png) 

分层说明：

| **分层结构**           | **说明**                                                     |
| ---------------------- | ------------------------------------------------------------ |
| **核心层**             | Kubernetes最核心的功能，对外提供API构建高层的应用，对内提供插件式应用执行环境 |
| **应用层**             | 部署（无状态应用、有状态应用、批处理任务、集群应用等）和路由（服务发现、DNS解析等） |
| **管理层**             | 系统度量（如基础设施、容器和网络的度量），自动化（如自动扩展、动态Provision等）以及策略管理（RBAC、Quota、PSP、NetworkPolicy等） |
| **接口层**             | kubectl命令行工具、客户端SDK以及集群联邦                     |
| **生态系统**           | 在接口层之上的庞大容器集群管理调度的生态系统，可以划分为两个范畴 |
| **Kubernetes****外部** | 日志、监控、配置管理、CI、CD、Workflow、FaaS、OTS应用、ChatOps等 |
| **Kubernetes****内部** | CRI、CNI、CVI、镜像仓库、Cloud Provider、集群自身的配置和管理等 |

***1\***|***2\*****1.2 部署Kubernetes集群**

### 1.2.1 主机环境说明

系统版本说明



```
[root@k8s-master ~]# cat /etc/redhat-release 
CentOS Linux release 7.2.1511 (Core) 
[root@k8s-master ~]# uname -r 
3.10.0-327.el7.x86_64
[root@k8s-master ~]# getenforce 
Disabled
[root@k8s-master ~]# systemctl status  firewalld.service 
● firewalld.service - firewalld - dynamic firewall daemon
   Loaded: loaded (/usr/lib/systemd/system/firewalld.service; disabled; vendor preset: enabled)
   Active: inactive (dead)
```

主机IP规划

| **主机名**     | **IP**                | **功能**               |
| -------------- | --------------------- | ---------------------- |
| **k8s-master** | 10.0.0.11/172.16.1.11 | Master、etcd、registry |
| **k8s-node-1** | 10.0.0.12/172.16.1.12 | node1                  |
| **k8s-node-2** | 10.0.0.13/172.16.1.13 | node2                  |

设置hosts解析



```
[root@k8s-master ~]# cat /etc/hosts
127.0.0.1   localhost localhost.localdomain localhost4 localhost4.localdomain4
::1         localhost localhost.localdomain localhost6 localhost6.localdomain6
10.0.0.11   k8s-master
10.0.0.12   k8s-node-1
10.0.0.13   k8s-node-2
```

### 1.2.2 安装软件包

在三个节点上分别操作



```
[root@k8s-master ~]# yum install etcd docker kubernetes flannel  -y 
[root@k8s-node-1 ~]# yum install docker kubernetes flannel  -y 
[root@k8s-node-2 ~]# yum install docker kubernetes flannel  -y
```

安装的软件版本说明



```
[root@k8s-master ~]# rpm -qa  etcd docker kubernetes flannel
flannel-0.7.1-2.el7.x86_64
docker-1.12.6-71.git3e8e77d.el7.centos.1.x86_64
kubernetes-1.5.2-0.7.git269f928.el7.x86_64
etcd-3.2.11-1.el7.x86_64
```

### 1.2.3 修改配置etcd

  yum安装的etcd默认配置文件在/etc/etcd/etcd.conf。

最终配置文件



```
[root@k8s-master ~]# grep -Ev '^$|#' /etc/etcd/etcd.conf
ETCD_DATA_DIR="/var/lib/etcd/default.etcd"
ETCD_LISTEN_CLIENT_URLS="http://0.0.0.0:2379"
ETCD_NAME="default"
ETCD_ADVERTISE_CLIENT_URLS="http://10.0.0.11:2379"
```

启动etcd



```
[root@k8s-master ~]# systemctl enable etcd
[root@k8s-master ~]# systemctl start etcd
```

测试etcd



```
etcdctl set testdir/testkey0 0
etcdctl set testdir/testkey0 0
[root@k8s-master ~]# etcdctl -C http://10.0.0.11:2379 cluster-health
member 8e9e05c52164694d is healthy: got healthy result from http://10.0.0.11:2379
cluster is healthy
```

### 1.2.4 配置并启动kubernetes

/etc/kubernetes/apiserver配置文件内容



```
[root@k8s-master ~]#  grep -Ev '^$|#'  /etc/kubernetes/apiserver
KUBE_API_ADDRESS="--insecure-bind-address=0.0.0.0"
KUBE_API_PORT="--port=8080"
KUBE_ETCD_SERVERS="--etcd-servers=http://10.0.0.11:2379"
KUBE_SERVICE_ADDRESSES="--service-cluster-ip-range=10.254.0.0/16"
KUBE_ADMISSION_CONTROL="--admission-control=NamespaceLifecycle,NamespaceExists,LimitRanger,SecurityContextDeny,ResourceQuota"
KUBE_API_ARGS=""
```

/etc/kubernetes/config配置文件



```
[root@k8s-master ~]#  grep -Ev '^$|#' /etc/kubernetes/config
KUBE_LOGTOSTDERR="--logtostderr=true"
KUBE_LOG_LEVEL="--v=0"
KUBE_ALLOW_PRIV="--allow-privileged=false"
KUBE_MASTER="--master=http://10.0.0.11:8080"
```

启动服务



```
systemctl enable kube-apiserver.service
systemctl start kube-apiserver.service
systemctl enable kube-controller-manager.service
systemctl start kube-controller-manager.service
systemctl enable kube-scheduler.service
systemctl start kube-scheduler.service
```

### 1.2.5 部署配置node

/etc/kubernetes/config配置文件



```
[root@k8s-node-1 ~]# grep -Ev '^$|#'  /etc/kubernetes/config
KUBE_LOGTOSTDERR="--logtostderr=true"
KUBE_LOG_LEVEL="--v=0"
KUBE_ALLOW_PRIV="--allow-privileged=false"
KUBE_MASTER="--master=http://10.0.0.11:8080"
[root@k8s-node-1 ~]# grep -Ev '^$|#'  /etc/kubernetes/kubelet
KUBELET_ADDRESS="--address=0.0.0.0"
KUBELET_HOSTNAME="--hostname-override=10.0.0.12"
KUBELET_API_SERVER="--api-servers=http://10.0.0.11:8080"
KUBELET_POD_INFRA_CONTAINER="--pod-infra-container-image=registry.access.redhat.com/rhel7/pod-infrastructure:latest"
KUBELET_ARGS=""
```

/etc/kubernetes/config配置文件



```
[root@k8s-node-2 ~]# grep -Ev '^$|#'  /etc/kubernetes/config
KUBE_LOGTOSTDERR="--logtostderr=true"
KUBE_LOG_LEVEL="--v=0"
KUBE_ALLOW_PRIV="--allow-privileged=false"
KUBE_MASTER="--master=http://10.0.0.11:8080"
[root@k8s-node-2 ~]# grep -Ev '^$|#'  /etc/kubernetes/kubelet
KUBELET_ADDRESS="--address=0.0.0.0"
KUBELET_HOSTNAME="--hostname-override=10.0.0.13"
KUBELET_API_SERVER="--api-servers=http://10.0.0.11:8080"
KUBELET_POD_INFRA_CONTAINER="--pod-infra-container-image=registry.access.redhat.com/rhel7/pod-infrastructure:latest"
KUBELET_ARGS=""
```

启动



```
systemctl enable kubelet.service
systemctl start kubelet.service
systemctl enable kube-proxy.service
systemctl start kube-proxy.service
```

在master上查看集群中节点及节点状态



```
# kubectl -s http://10.0.0.11:8080 get node
[root@k8s-master ~]# kubectl -s http://10.0.0.11:8080 get node
NAME        STATUS    AGE
10.0.0.12   Ready     49s
10.0.0.13   Ready     56s
[root@k8s-master ~]# kubectl get nodes
NAME        STATUS    AGE
10.0.0.12   Ready     1m
10.0.0.13   Ready     1m
```

  至此Kubernetes基础部署完成

### 1.2.6 Kubernetes其他安装方法

>    二进制安装
>
>    kubuadm 安装
>
>    minikube 安装
>
>    ansible部署：https://github.com/gjmzj/kubeasz

***1\***|***3\*****1.3 创建覆盖网络--Flannel**

### 1.3.1 配置Flannel（所有节点操作）

安装软件包



```
yum install flannel -y
```

修改配置文件



```
[root@k8s-master ~]# grep "^[a-Z]" /etc/sysconfig/flanneld
FLANNEL_ETCD_ENDPOINTS="http://10.0.0.11:2379"
FLANNEL_ETCD_PREFIX="/atomic.io/network"
```

### 1.3.2 配置etcd中关于flannel的key

Flannel使用Etcd进行配置，来保证多个Flannel实例之间的配置一致性，所以需要在etcd上进行如下配置：（‘/atomic.io/network/config’这个key与上文/etc/sysconfig/flannel中的配置项FLANNEL_ETCD_PREFIX是相对应的，错误的话启动就会出错）

配置网络范围



```
etcdctl mk  /atomic.io/network/config '{ "Network": "172.16.0.0/16" }'
```

操作创建网络



```
[root@k8s-master ~]# etcdctl mk /atomic.io/network/config '{ "Network": "172.16.0.0/16" }'
{ "Network": "172.16.0.0/16" }
```

master节点操作



```
    systemctl enable flanneld.service 
    systemctl start flanneld.service 
    service docker restart
    systemctl restart kube-apiserver.service
    systemctl restart kube-controller-manager.service
    systemctl restart kube-scheduler.service
```

node节点操作



```
    systemctl enable flanneld.service 
    systemctl start flanneld.service 
    service docker restart
    systemctl restart kubelet.service
    systemctl restart kube-proxy.service 
    
```

修改配置文件



```
[root@k8s-master ~]# cat  /etc/kubernetes/apiserver 
KUBE_API_ADDRESS="--insecure-bind-address=0.0.0.0"
KUBE_API_PORT="--port=8080"
KUBE_ETCD_SERVERS="--etcd-servers=http://10.0.0.11:2379"
KUBE_SERVICE_ADDRESSES="--service-cluster-ip-range=10.254.0.0/16"
KUBE_ADMISSION_CONTROL="--admission-control=NamespaceLifecycle,NamespaceExists,LimitRanger,SecurityContextDeny,ResourceQuota"
KUBE_API_ARGS=""
```

  **至此Flannel****网络配置完成**

***1\***|***4\*****1.4 创建一个简单的pod**

Pod是K8s集群中所有业务类型的基础

Pod是在K8s集群中运行部署应用或服务的最小单元，它是可以支持多容器的。

Pod的设计理念是支持多个容器在一个Pod中共享网络地址和文件系统。

POD控制器Deployment、Job、DaemonSet和PetSet

### 1.4.1 写一个编排yaml格式

kubenetes里面的创建service、rc、pod都是这种形式(另外一种是json)

关于yaml参考：http://t.cn/RK0Jlwu



```
[root@k8s-master ~]# cat  /etc/kubernetes/apiserver 
KUBE_API_ADDRESS="--insecure-bind-address=0.0.0.0"
KUBE_API_PORT="--port=8080"
KUBE_ETCD_SERVERS="--etcd-servers=http://10.0.0.11:2379"
KUBE_SERVICE_ADDRESSES="--service-cluster-ip-range=10.254.0.0/16"
KUBE_ADMISSION_CONTROL="--admission-control=NamespaceLifecycle,NamespaceExists,LimitRanger,SecurityContextDeny,ResourceQuota"
KUBE_API_ARGS=""
```

### 1.4.2 启动一个pod



```
[root@k8s-master ~]# kubectl create -f hello.yaml 
pod "hello-world" created
```

查看默认namespace下的pods



```
[root@k8s-master ~]# kubectl get pods
NAME          READY     STATUS              RESTARTS   AGE
hello-world   0/1       ContainerCreating   0          8s
```

查看pod的详细信息



```
[root@k8s-master ~]# kubectl  describe pod  hello-world 
Events:
  FirstSeen    LastSeen    Count    From            SubObjectPath    Type       Reason        Message
  ---------    --------    -----    ----            -------------    --------   ------        -------
  4m        4m        1    {default-scheduler}      Normal         Scheduled    Successfully assigned hello-world to 10.0.0.13
  4m        1m        5    {kubelet 10.0.0.13}      Warning        FailedSync    Error syncing pod, skipping: failed to "StartContainer" for "POD" with ErrImagePull: "image pull failed for registry.access.redhat.com/rhel7/pod-infrastructure:latest, this may be because there are no credentials on this request.  details: (open /etc/docker/certs.d/registry.access.redhat.com/redhat-ca.crt: no such file or directory)"
  3m        14s       13   {kubelet 10.0.0.13}      Warning        FailedSync    Error syncing pod, skipping: failed to "StartContainer" for "POD" with ImagePullBackOff: "Back-off pulling image \"registry.access.redhat.com/rhel7/pod-infrastructure:latest\""
```

  该错误的解决方法： yum install python-rhsm* -y 

获取指定pods详细信息



```
kubectl describe pods yourpodname
```

获取已运行pod状态



```
kubectl get pods -o wide
```

下载pod-infrastructure镜像包



```
docker tag docker.io/tianyebj/pod-infrastructure:latest registry.access.redhat.com/rhel7/pod-infrastructure:lates
```

### 1.4.3 pod其他操作

删除pod，重新创建



```
[root@k8s-master ~]# kubectl delete -f hello.yaml 
pod "hello-world" deleted
[root@k8s-master ~]# kubectl create -f hello.yaml 
pod "hello-world" created
```

查看状态



```
[root@k8s-master ~]# kubectl get pods -o wide
NAME        READY     STATUS             RESTARTS   AGE       IP            NODE
nginx-web   1/1       ImagePullBackOff   0          1m        172.16.53.2   10.0.0.13
```

***1\***|***5\*****1.5 Replication Controller**

  RC是K8s集群中最早的保证Pod高可用的API对象。通过监控运行中的Pod来保证集群中运行指定数目的Pod副本。指定的数目可以是多个也可以是1个；少于指定数目，RC就会启动运行新的Pod副本；多于指定数目，RC就会杀死多余的Pod副本。

  即使在指定数目为1的情况下，通过RC运行Pod也比直接运行Pod更明智，因为RC也可以发挥它高可用的能力，保证永远有1个Pod在运行。

### 1.5.1 简单rc配置



```
[root@k8s-master ~]# kubectl get  rc
```

始终保证有一个在活着

更新rc文件



```
[root@k8s-master ~]# kubectl replace -f  nginx.yml
```

  nginx.yml文件信息



```
[root@k8s-master ~]# vim nginx.yml
apiVersion: v1
kind: Pod
metadata:
  name: nginx-2
spec:
  restartPolicy: Never
  containers:
  - name: nginx
    image: "docker.io/nginx:latest"
```

对现有已创建资源直进行修改



```
[root@k8s-master ~]# kubectl edit rc nginx
```

  可以调整数量即使生效

### 1.5.2 rs实现灰度发布

RS是新一代RC，提供同样的高可用能力，区别主要在于RS后来居上，能支持更多中的匹配模式。副本集对象一般不单独使用，而是作为部署的理想状态参数使用。

是K8S 1.2中出现的概念，是RC的升级。一般和Deployment共同使用。

>  部署表示用户对K8s集群的一次更新操作。部署是一个比RS应用模式更广的API对象，可以是创建一个新的服务，更新一个新的服务，也可以是滚动升级一个服务。滚动升级一个服务，实际是创建一个新的RS，然后逐渐将新RS中副本数增加到理想状态，将旧RS中的副本数减小到0的复合操作；
>
>  　这样一个复合操作用一个RS是不太好描述的，所以用一个更通用的Deployment来描述。
>
> 　　以K8s的发展方向，未来对所有长期伺服型的的业务的管理，都会通过Deployment来管理。
>
>  　Deployment是对RC的升级，与RC的相似度超过90%。

web-rc.yaml文件内容



```
[root@k8s-master ~]# cat web-rc.yaml 
apiVersion: v1
kind: ReplicationController
metadata:
  name: myweb
spec:
  replicas: 3
  selector:
    app: myweb
  template:
    metadata:
      labels:
        app: myweb
    spec:
      containers:
      - name: myweb
        image: kubeguide/tomcat-app:v1
        ports:
        - containerPort: 8080
        env:
        - name: MYSQL_SERVICE_HOST
          value: 'mysql'
        - name: MYSQL_SERVICE_PORT
          value: '3306'
```

**创建集群**



```
[root@k8s-master ~]# kubectl create -f web-rc.yaml
```

**对集群进行升级操作**

  将集群内容器自动升级到新版本的容器



```
[root@k8s-master ~]# kubectl rolling-update  myweb  -f web-rc2.yaml 
```

web-rc2.yaml配置文件内容



```
[root@k8s-master ~]# cat web-rc2.yaml 
apiVersion: v1
kind: ReplicationController
metadata:
  name: myweb-2
spec:
  replicas: 3
  selector:
    app: myweb-2
  template:
    metadata:
      labels:
        app: myweb-2
    spec:
      containers:
      - name: myweb-2
        image: kubeguide/tomcat-app:v2
        ports:
        - containerPort: 8080
        env:
        - name: MYSQL_SERVICE_HOST
          value: 'mysql'
        - name: MYSQL_SERVICE_PORT
          value: '3306'
```

**升级后的回滚**

  使用新的文件，进行升级操作可达到回滚的目的，参考：https://github.com/kubeguide/samplecode



```
[root@k8s-master ~]# kubectl rolling-update  myweb-2  -f web-rc.yaml 
```

### 1.5.3 rc小结

🍢 RC里包括完整的POD定义模板

🍢 RC通过Label Selector机制实现对POD副本的自动控制。

🍢 通过改变RC里的POD副本以实现POD的扩容和缩容

🍢 通过改变RC里POD模块中的镜像版本，可以实现POD的滚动升级。

### 1.5.4 Deployment

 Deployment同样也是Kubernetes系统的一个核心概念，主要职责和RC|RS一样的都是保证Pod的数量和健康，二者大部分功能都是完全一致的，我们可以看成是一个升级版的RC|RS控制器.

 *Deployment新特性
RC|RS的全部功能：Deployment具备上面描述的RC|RS的全部功能
事件和状态查看：可以查看Deployment的升级详细进度和状态
回滚：当升级Pod的时候如果出现问题，可以使用回滚操作回滚到之前的任一版本
版本记录：每一次对Deployment的操作，都能够保存下来，这也是保证可以回滚到任一版本的基础
暂停和启动：对于每一次升级都能够随时暂停和启动*

 

*作为对比，我们知道`Deployment`作为新一代的`RC|RS`，不仅在功能上更为丰富了，同时我们也说过现在官方也都是推荐使用`Deployment`来管理`Pod`的，比如一些官方组件`kube-dns`、`kube-proxy`也都是使用的`Deployment`来管理的，所以当大家在使用的使用也最好使用`Deployment`来管理`Pod`。*

***1\***|***6\*****1.6 服务（Service）**

### 1.6.1 Service作用

RC、RS和Deployment只是保证了支撑服务的POD的数量，但是没有解决如何访问这些服务的问题。一个Pod只是一个运行服务的实例，随时可能在一个节点上停止，在另一个节点以一个新的IP启动一个新的Pod，因此不能以确定的IP和端口号提供服务。

要稳定地提供服务需要服务发现和负载均衡能力。服务发现完成的工作，是针对客户端访问的服务，找到对应的的后端服务实例。

在K8集群中，客户端需要访问的服务就是Service对象。每个Service会对应一个集群内部有效的**虚拟****IP**，集群内部通过虚拟IP访问一个服务。

在K8s集群中微服务的负载均衡是由Kube-proxy实现的。Kube-proxy是K8s集群内部的负载均衡器。它是一个分布式代理服务器，在K8s的每个节点上都有一个；这一设计体现了它的***伸缩性\***优势，需要访问服务的节点越多，提供负载均衡能力的Kube-proxy就越多，高可用节点也随之增多。

### 1.6.2 测试service



```
[root@k8s-master ~]# vim myweb-svc.yaml 
apiVersion: v1
kind: Service
metadata:
  name: myweb
spec:
  type: NodePort
  ports:
    - port: 8080
      nodePort: 30001
  selector:
    app: myweb
```

启动集群



```
[root@k8s-master ~]# kubectl create -f myweb-svc.yaml 
service "myweb" created
[root@k8s-master ~]# kubectl get svc
NAME         CLUSTER-IP      EXTERNAL-IP   PORT(S)          AGE
kubernetes   10.254.0.1      <none>        443/TCP          6h
myweb        10.254.247.21   <nodes>       8080:30001/TCP   12s
```

在本地服务器的host文件中加入服务器ip加端口192.168.60.129:30001

浏览器访问测试

[![img](https://images2017.cnblogs.com/blog/1190037/201802/1190037-20180203175348406-53755867.png)](https://images2017.cnblogs.com/blog/1190037/201802/1190037-20180203175348406-53755867.png) 

### 1.6.3 service原理图

 [![img](https://images2017.cnblogs.com/blog/1190037/201802/1190037-20180203175356062-1640106637.png)](https://images2017.cnblogs.com/blog/1190037/201802/1190037-20180203175356062-1640106637.png)

网访问node ip 转到cluster ip上 在进行pod 分发 rr轮询



```
kubectl create -f web-svc.yaml
    [root@k8s-master ~]# kubectl get service
    
    NAME         CLUSTER-IP      EXTERNAL-IP   PORT(S)          AGE
    kubernetes   10.254.0.1      <none>        443/TCP          4h
    myweb        10.254.168.71   <nodes>       8080:30001/TCP   15s
```

### 1.6.4 K8S三种IP

| **类型**       | **说明**                                                     |
| -------------- | ------------------------------------------------------------ |
| **Node IP**    | 节点设备的IP，如物理机，虚拟机等容器宿主的实际IP。           |
| **Pod IP**     | Pod 的IP地址，是根据docker0网格IP段进行分配的。              |
| **Cluster IP** | Service的IP，是一个虚拟IP，仅作用于service对象，由k8s管理和分配，需要结合service port才能使用，单独的IP没有通信功能，集群外访问需要一些修改。 |

***1\***|***7\*****1.7 部署DashBoard**

参考文档：http://www.cnblogs.com/zhenyuyaodidiao/p/6500897.html

### 1.7.1 修改配置文件

编辑dashboard.yaml，注意或更改以下部分：



```
    image: index.tenxcloud.com/google_containers/kubernetes-dashboard-amd64:v1.4.1
            args:
         -  --apiserver-host=http://10.0.0.11:8080
```

编辑dashboardsvc.yaml文件：



```
apiVersion: v1
kind: Service
metadata:
  name: kubernetes-dashboard
  namespace: kube-system
  labels:
    k8s-app: kubernetes-dashboard
    kubernetes.io/cluster-service: "true"
spec:
  selector:
    k8s-app: kubernetes-dashboard
  ports:
  - port: 80
targetPort: 9090
```

### 1.7.2 镜像准备

> 在dashboard.yaml中定义了dashboard所用的镜像
>
> gcr.io/google_containers/kubernetes-dashboard-amd64:v1.5.1（当然你可以选择其他的版本）

下载地址



```
docker pull registry.cn-hangzhou.aliyuncs.com/google-containers/kubernetes-dashboard-amd64:v1.4.1
```

### 1.7.3 启动dashboard

在master执行如下命令：



```
kubectl create -f dashboard.yaml
kubectl create -f dashboardsvc.yaml
```

**到此dashboard****搭建完成**

### 1.7.4 验证

　　命令验证，master上执行如下命令：



```
[root@k8s-master ~]# kubectl get deployment --all-namespaces
NAMESPACE     NAME                          DESIRED   CURRENT   UP-TO-DATE   AVAILABLE   AGE
kube-system   kubernetes-dashboard-latest   1         1         1            1           42m
[root@k8s-master ~]# kubectl get svc  --all-namespaces
NAMESPACE     NAME                   CLUSTER-IP      EXTERNAL-IP   PORT(S)          AGE
default       kubernetes             10.254.0.1      <none>        443/TCP          5h
default       myweb                  10.254.168.71   <nodes>       8080:30001/TCP   1h
kube-system   kubernetes-dashboard   10.254.90.78    <none>        80/TCP           41m
    [root@k8s-master ~]# kubectl get pod  -o wide  --all-namespaces
    NAMESPACE     NAME                                           READY     STATUS    RESTARTS   AGE       IP            NODE
    default       myweb-c2dfj                                    1/1       Running   0          1h        172.16.57.2   10.0.0.13
    default       myweb-h7rkb                                    1/1       Running   0          1h        172.16.76.2   10.0.0.12
    default       myweb-l48b3                                    1/1       Running   0          1h        172.16.57.3   10.0.0.13
    kube-system   kubernetes-dashboard-latest-1395490986-1t37v   1/1       Running   0          43m       172.16.76.3   10.0.0.12
```

### 1.7.5 浏览器访问：http://10.0.0.11:8080/ui

[![img](https://images2017.cnblogs.com/blog/1190037/201802/1190037-20180203175411906-1279802068.png)](https://images2017.cnblogs.com/blog/1190037/201802/1190037-20180203175411906-1279802068.png) 

### 1.7.6 销毁应用（测试）

在master上执行：



```
kubectl delete deployment kubernetes-dashboard-latest --namespace=kube-system
kubectl delete svc  kubernetes-dashboard --namespace=kube-system
```

***1\***|***8\*****1.8 参考文献**

>  [1] https://www.cnblogs.com/gaoyuechen/p/8685771.html

 

 

 

__EOF__

![img](https://pic.cnblogs.com/avatar/1468064/20180907120100.png)

**本文作者**：**[不忘初心](https://www.cnblogs.com/xy51/p/12744956.html)**
**本文链接**：https://www.cnblogs.com/xy51/p/12744956.html
**关于博主**：评论和私信会在第一时间回复。或者[直接私信](https://msg.cnblogs.com/msg/send/xy51)我。
**版权声明**：本博客所有文章除特别声明外，均采用 [BY-NC-SA](https://creativecommons.org/licenses/by-nc-nd/4.0/) 许可协议。转载请注明出处！
**声援博主**：如果您觉得文章对您有帮助，可以点击文章右下角**【[推荐](javascript:void(0);)】**一下。您的鼓励是博主的最大动力！

[好文要顶](javascript:void(0);) [关注我](javascript:void(0);) [收藏该文](javascript:void(0);) [微信分享](javascript:void(0);)

[![img](https://pic.cnblogs.com/face/1468064/20180907120100.png)](https://home.cnblogs.com/u/xy51/)

[不忘初心--学](https://home.cnblogs.com/u/xy51/)
[粉丝 - 22](https://home.cnblogs.com/u/xy51/followers/) [关注 - 2](https://home.cnblogs.com/u/xy51/followees/)

[+加关注](javascript:void(0);)

9

0

[« ](https://www.cnblogs.com/xy51/p/12673981.html)上一篇： [nginx相关知识](https://www.cnblogs.com/xy51/p/12673981.html)
[» ](https://www.cnblogs.com/xy51/p/12744965.html)下一篇： [k8s遇见的问题](https://www.cnblogs.com/xy51/p/12744965.html)

posted @ 2020-04-21 15:29 [不忘初心--学](https://www.cnblogs.com/xy51) 阅读(6946) 评论(0) [编辑](https://i.cnblogs.com/EditPosts.aspx?postid=12744956) [收藏](javascript:void(0)) [举报](javascript:void(0))





[刷新评论](javascript:void(0);)[刷新页面](https://www.cnblogs.com/xy51/p/12744956.html#)[返回顶部](https://www.cnblogs.com/xy51/p/12744956.html#top)

发表评论 [升级成为园子VIP会员](https://cnblogs.vip/)



编辑预览



 自动补全

 [退出](javascript:void(0);) [订阅评论](javascript:void(0);)

[Ctrl+Enter快捷键提交]

[【推荐】博客园商业化之路-商业模式：帮助开发者用代码改变口袋](https://www.cnblogs.com/cmt/p/18148611)
[【推荐】园子周边第二季：更大的鼠标垫，没有logo的鼠标垫](https://www.cnblogs.com/cmt/p/18094172)
[【推荐】阿里云云市场联合博客园推出开发者商店，欢迎关注](https://market.cnblogs.com/)
[【推荐】会员力量，点亮园子希望，期待您升级成为园子会员](https://cnblogs.vip/buy)

**编辑推荐：**
· [［Nano Framework ESP32篇］使用 LCD 屏幕](https://www.cnblogs.com/tcjiaan/p/18163320)
· [记录一个 HttpClient 超时连接配置不生效的问题排查过程](https://www.cnblogs.com/enjoyall/p/18159220)
· [Git 版本控制：构建高效协作和开发流程的最佳实践](https://www.cnblogs.com/mazey/p/18156657)
· [安全机密管理：Asp.Net Core 中的本地敏感数据保护技巧](https://www.cnblogs.com/ruipeng/p/18154605)
· [日志架构演进：从集中式到分布式的Kubernetes日志策略](https://www.cnblogs.com/crossoverJie/p/18150585)

**阅读排行：**
· [一个库帮你轻松的创建漂亮的.NET控制台应用程序](https://www.cnblogs.com/Can-daydayup/p/18162360)
· [《HelloGitHub》第 97 期](https://www.cnblogs.com/xueweihan/p/18162468)
· [程序员想通过产品挣钱，首先你产品的目标客户得不差钱 （在线客服系统外传1）](https://www.cnblogs.com/sheng_chao/p/18163373)
· [一键启动的AI离线知识库，无需复杂环境依赖，小白都能上手了](https://www.cnblogs.com/xuzeyu/p/18161896)
· [Util 应用框架 UI 全新升级](https://www.cnblogs.com/xiadao521/p/18163513)

# k8s



发表于 2020-04-21 15:29阅读次数：6946评论次数：0





This blog has running : 2082 d 1 h 13 m 23 sღゝ◡╹)ノ♡

Copyright © 2024 不忘初心--学 Powered by .NET 8.0 on Kubernetes

Theme version: [v1.2.6](https://github.com/BNDong/Cnblogs-Theme-SimpleMemory/tree/v1.2.6) / Loading theme version: [v1.2.6](https://github.com/BNDong/Cnblogs-Theme-SimpleMemory/tree/v1.2.6)