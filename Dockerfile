FROM ubuntu:focal

# Configuration needed for timezone
ENV TZ=Asia/Tokyo
RUN ln -snf /usr/share/zoneinfo/$TZ /etc/localtime && echo $TZ > /etc/timezone

RUN apt-get update -y && apt-get -y upgrade

# Install packages for xv6
RUN apt-get install git build-essential gdb-multiarch qemu-system-misc gcc-riscv64-linux-gnu binutils-riscv64-linux-gnu -y

# Fix error with qemu by uninstalling current version
RUN apt-get remove qemu-system-misc -y
# And installing a previous version
RUN apt-get install qemu-system-misc=1:4.2-3ubuntu6 -y 

# Fix error with virtualization & qemu
RUN apt install qemu-kvm libvirt-daemon-system libvirt-clients bridge-utils virtinst virt-manager -y

#WORKDIR /usr/src/app/xv6-public
WORKDIR xv6
ENTRYPOINT ["make"]
