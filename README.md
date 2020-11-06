# xv6
- The idea of this repository is to learn about operating systems.
- By adding more files to the inside xv6-public, the kernel gets robust.
- Original code is not my property, is taken from: https://pdos.csail.mit.edu/6.828/2020/

## Environment
- Docker 19.03.0
- Ubuntu 16.04 LTS
- gcc 5.4.0 20160609 (Ubuntu 5.4.0-6ubuntu1~16.04.12)

## How this works?



## Running locally
1. Create/Update the Dockerfile
2. Build the image
3. Create a container. Inside the container, a emulation of xv6 will run

### Dockerfile
I strongly recommend not to edit the Dockerfile, except for the line 4.
Timezone environmental variable is needed.


### Building the image
Start by modifying the image name if necesssary
``` bash
# build.sh
IMAGE_NAME=xv6 # The image name we want to create
sudo docker build -t $IMAGE_NAME .
```

To build the image, place yourself on the folder where the Dockerfile exists and run:
``` bash
$ source build.sh
```

### Running a container
Modify the necessary environmental variables inside run.sh
``` bash
# run.sh
IMAGE_NAME=xv6 # The same image name we created previously
IMAGE_TAG=latest # The tag to use. If we did not specify anything before, use 'latest'
LOCAL_DIR=$(pwd)/xv6-public # Path where xv6 source code exists
CONTAINER_DIR=/xv6 # Directory in the docker to be used as volume
sudo docker run -v $LOCAL_DIR:$CONTAINER_DIR -it $IMAGE_NAME:$IMAGE_TAG qemu-nox
```
Then run:
``` bash
$ source run.sh
```
## FAQs

### **How I close the emulation?**
- To quit qemu type: Ctrl-a x
- Another option is to pres: Ctrl-a c. Then in the qemu console type: q or quit, then press Enter
