IMAGE_NAME=xv6
IMAGE_TAG=latest
LOCAL_DIR=$(pwd)/xv6-public
CONTAINER_DIR=/xv6
CONTAINER_NAME=/xv6-practice
sudo docker run --rm \
		--name $CONTAINER_NAME \
		-v $LOCAL_DIR:$CONTAINER_DIR \
		-it $IMAGE_NAME:$IMAGE_TAG \
		qemu-nox
