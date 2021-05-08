IMAGE_NAME=xv6
IMAGE_TAG=latest
LOCAL_DIR=$(pwd)/xv6-public
CONTAINER_DIR=/xv6
sudo docker run --rm -v $LOCAL_DIR:$CONTAINER_DIR -it $IMAGE_NAME:$IMAGE_TAG qemu-nox
