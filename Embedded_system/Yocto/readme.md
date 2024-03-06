# Yocto
Yocto is an open-source project that helps to create custom Linux-based systems for embedded systems, regardless of the hardware architecture.

## Poky
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

## Bitbake
BitBake is a build automation tool used to build a Linux distribution.

## Terminology
### Recipe
A recipe is a file with a `.bb` extension that contains metadata and instructions for building a package. This includes where to fetch the source code, how to compile it, any patches to apply, dependencies, and where to install the compiled binaries.
### Layer
- The name of a layer starts with `meta-`
- A layer is a collection of recipes, configuration files, and other metadata that define how to build specific software components.
### IMAGE_INSTALL
IMAGE_INSTALL is a variable to list the packages that should be included in the final image that Yocto builds.
