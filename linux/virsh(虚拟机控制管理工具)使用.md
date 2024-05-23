# 一、virsh介绍

`virsh` 是一种命令行工具，用于管理和控制基于 KVM（Kernel-based Virtual Machine）的虚拟机。KVM 是 Linux 内核的一个模块，允许 Linux 主机作为虚拟化平台来运行多个虚拟机。

通过 `virsh` 命令，用户可以执行各种操作，包括但不限于：

1. **创建虚拟机**：可以使用 `virsh` 命令来创建新的虚拟机，并指定虚拟机的配置参数和硬件资源。
2. **管理虚拟机**：可以启动、停止、暂停、恢复、重启虚拟机，以及查看虚拟机的状态信息。
3. **配置虚拟机**：可以修改虚拟机的配置，如内存大小、CPU 核数、磁盘容量等。
4. **管理虚拟网络**：可以创建、删除和管理虚拟网络，以及配置虚拟网络的参数。
5. **迁移虚拟机**：可以迁移虚拟机到不同的主机上，实现负载均衡或故障转移。
6. **管理存储**：可以管理虚拟机的存储，包括创建、删除、挂载和卸载磁盘镜像等操作。
7. **监控虚拟机**：可以查看虚拟机的性能指标和监控信息，如 CPU 使用率、内存使用情况等。

总的来说，`virsh` 是一种强大的虚拟机管理工具，提供了丰富的命令和功能，方便用户管理和控制基于 KVM 的虚拟化环境。

# 二、virsh指令

1. **创建虚拟机**：

```
virt-install --virt-type=kvm --name=2024.4.17.pm_try --memory=2048 --vcpus=2 --os-type linux --disk path=/home/cx/pm_try.qcow2,size=20,format=qcow2 --network bridge=br0 --graphics none --extra-args='console=ttyS0' --force --location /home/iso/Kylin-Server-V10-SP3-General-Release-2303-ARM64.iso
```

你提供的命令是用于通过`virt-install`工具创建一个KVM虚拟机，参数说明如下：

- `--virt-type=kvm`: 指定虚拟化类型为KVM。
- `--name=kylin03`: 指定虚拟机的名称为kylin03。
- `--memory=8096`: 指定虚拟机的内存大小为8096 MB。
- `--vcpus=8`: 指定虚拟机的虚拟CPU核心数量为8。
- `--os-type linux`: 指定虚拟机的操作系统类型为Linux。
- `--disk path=/home/cx/kylin03.qcow2,,size=100,format=qcow2`: 指定虚拟机的磁盘路径为`/home/cx/kylin03.qcow2`，大小为100 GB，格式为qcow2。
- `--network bridge=br0`: 指定虚拟机的网络配置为桥接模式，使用网桥`br0`。
- `--graphics none`: 禁用图形界面。
- `--extra-args='console=ttyS0'`: 指定额外的启动参数，将控制台输出重定向到串口`ttyS0`。
- `--force`: 强制执行操作，如果虚拟机已存在，则覆盖它。
- `--location /home/iso/Kylin-Server-V10-SP3-General-Release-2303-ARM64.iso`: 指定虚拟机安装所需的ISO镜像文件路径。

该命令的作用是创建一个名为`kylin03`的虚拟机，该虚拟机配置了8GB内存、8个CPU核心，使用了100GB大小的qcow2格式磁盘，网络配置为桥接模式，操作系统类型为Linux，安装过程从指定的ISO镜像文件中进行。

1. **启动虚拟机**：

```
 start myvm
```

这个命令将启动名为 `myvm` 的虚拟机。

1. **停止虚拟机**：

```
 shutdown myvm
```

这个命令将向名为 `myvm` 的虚拟机发送关闭信号。

1. **查看虚拟机状态**：

```
 dominfo myvm
```

这个命令将显示名为 `myvm` 的虚拟机的状态信息，包括内存使用情况、虚拟 CPU 信息等。

1. **修改虚拟机配置**：

```
 edit myvm
```

这个命令将打开一个文本编辑器，允许用户编辑名为 `myvm` 的虚拟机的 XML 配置文件，可以在其中修改虚拟机的各种配置参数。

1. **迁移虚拟机**：

```
 migrate myvm qemu+ssh://remotehost/system
```

这个命令将把名为 `myvm` 的虚拟机迁移到远程主机 `remotehost` 上。

1. **监控虚拟机性能**：

```
 domstats myvm
```

这个命令将显示名为 `myvm` 的虚拟机的性能指标，如 CPU 使用率、内存使用情况等。

请注意，在执行这些命令之前，请确保您有适当的权限，并将命令中的虚拟机名称和参数替换为您实际使用的值。

1. 确定要进入的虚拟机，使用 `virsh console <虚拟机名称>` 命令进入该虚拟机的控制台。
2. 在控制台中，您可以像在物理计算机上一样进行操作。要退出虚拟机的控制台，通常可以按下 `Ctrl` + `]` 组合键，然后输入 `quit`。

改用virt-install \
--virt-type=kvm \
--name=k8s_master_test \
--memory=8096 \
--vcpus=8 \
--os-type linux \
--disk path=/home/yb/k8s_master_test.qcow2,size=50,format=qcow2 \
--network bridge=br0 \
--graphics none \
--extra-args='console=ttyS0' \
--location /home/iso/Kylin-Server-V10-SP3-General-Release-2303-ARM64.iso \
--boot cdrom,hd \
--force

设置ip vi /etc/sysconfig/network-scripts/ifcfg-enp1s0 修改ip 然后重启系统 reboot

sudo ip route del default via 192.168.5.1 dev enp1s0

 sudo ip route add default via 192.168.5.120 dev enp1s设置ip路由
