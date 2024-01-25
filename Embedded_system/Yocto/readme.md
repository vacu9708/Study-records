# Yocto
Yocto is an open-source project that helps to create custom Linux-based systems for embedded systems, regardless of the hardware architecture.

# Poky
"Poky" is a reference distribution of the Yocto Project that utilizes OpenEmbedded at its core. It serves as a starting point for building custom Linux distributions for embedded systems.
## How to set the build environment
### Download dependenies
~~~bash
sudo apt-get update
sudo apt-get install gawk wget git-core diffstat unzip texinfo gcc-multilib build-essential chrpath socat cpio python3 python3-pip python3-pexpect xz-utils debianutils iputils-ping python3-git python3-jinja2 libegl1-mesa libsdl1.2-dev xterm python3-subunit
mesa-common-dev lz4
~~~
### Download poky
~~~bash
git clone -b kirkstone git://git.yoctoproject.org/poky.git
~~~
### Set the build environment
~~~bash
source poky/oe-init-build-env
~~~

# Bitbake
BitBake is a build automation tool used to build a Linux distribution.
