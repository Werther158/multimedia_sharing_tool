# HPC Project

Share video, screen, camera and audio with a RTSP stream through Lan or Wan supporting CUDA computations in a High Performance embedded environment (Nvidia Jetson Nano), applying real-time AI techiques of Intrusion Detection with bounding boxes localization and frames manipulations.

## External Dependencies:

Before installing dependencies:  
`$ sudo apt-get update`  
`$ sudo apt-get upgrade`  
`$ sudo apt-get install gcc`  
`$ sudo apt-get install cmake`  
`$ sudo apt-get install git`  

### QT Creator
[QT Home Page](https://www.qt.io/)

### CUDA  
[CUDA Installation Guide](https://docs.nvidia.com/cuda/cuda-installation-guide-linux/index.html)

### cURL
`$ sudo apt-get install curl`  

### NVIDIA TensorRT (for systems different than Jetson Nano)
[TensorRT Installation Guide](https://docs.nvidia.com/deeplearning/sdk/tensorrt-install-guide/index.html)

### Jetson-inference library
[Jetson-inference GitHub page](https://github.com/dusty-nv/jetson-inference)

### FFmpeg  
`$ sudo apt-get install ffmpeg`

### CUDA Enabled OpenCV with Contrib  
1. Remove any previous installations of x264  
```sh
$ sudo apt-get remove x264 libx264-dev
```  

2. Install OpenCV dependencies  
```sh
$ sudo apt-get install build-essential checkinstall cmake pkg-config yasm  
$ sudo apt-get install git gfortran  
$ sudo apt-get install libjpeg8-dev libjasper-dev libpng12-dev  
$ sudo apt-get install libtiff5-dev  
$ sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev  
$ sudo apt-get install libxine2-dev libv4l-dev  
$ sudo apt-get install libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev  
$ sudo apt-get install libqt4-dev libgtk2.0-dev libtbb-dev  
$ sudo apt-get install libatlas-base-dev  
$ sudo apt-get install libfaac-dev libmp3lame-dev libtheora-dev  
$ sudo apt-get install libvorbis-dev libxvidcore-dev  
$ sudo apt-get install libopencore-amrnb-dev libopencore-amrwb-dev  
$ sudo apt-get install x264 v4l-utils
```

3. Clone `opencv` and `opencv_contrib` version 3.4.7 repository
```sh
$ git clone -b 3.4.7 https://github.com/opencv/opencv
$ git clone -b 3.4.7 https://github.com/opencv/opencv_contrib
```

4. Make a directory i.e. `build` inside `opencv` directory  
```sh
$ mkdir build
$ cd build
$ cmake -D CMAKE_BUILD_TYPE=RELEASE \
 -D CMAKE_INSTALL_PREFIX=/usr/local \
 -D WITH_CUDA=ON \
 -D ENABLE_FAST_MATH=1 \
 -D CUDA_FAST_MATH=1 \
 -D WITH_CUBLAS=1 \
 -D INSTALL_PYTHON_EXAMPLES=ON \
 -D INSTALL_C_EXAMPLES=OFF \
 -D OPENCV_EXTRA_MODULES_PATH=../../opencv_contrib/modules \
 -D PYTHON_EXECUTABLE=~/.virtualenvs/cv/bin/python \
 -D WITH_GTK=ON \
 -D ENABLE_PRECOMPILED_HEADERS=OFF \
 -D BUILD_opencv_cudacodec=OFF \
 -D BUILD_EXAMPLES=ON ..
$ nproc
# use the number that nproc returns which is the number of cores of your processor. Let's say it returns 4.
$ make -j4 
$ sudo make install
```
