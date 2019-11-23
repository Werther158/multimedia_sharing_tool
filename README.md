# High Performance Computing Project

Share video, screen, camera and audio with an RTSP stream through Lan or Wan supporting CUDA computations in a High Performance embedded environment (Nvidia Jetson Nano), applying real-time AI techiques of Intrusion Detection with bounding boxes localization and frames manipulations.

A demonstration video can be found here: https://www.youtube.com/watch?v=4hzk5qf74mc

## External Dependencies:

Before installing dependencies:  
```sh
$ sudo apt-get update
$ sudo apt-get upgrade
$ sudo apt-get install gcc
$ sudo apt-get install cmake
$ sudo apt-get install git
$ sudo apt-get install libgtk2.0-dev
```

### QT Creator
On ARM architectures: `sudo apt-get install qt5-default qtcreator -y`  
Other architectures: [QT Home Page](https://www.qt.io/)

### CUDA  (Jetson users)
Add the CUDA directory to $PATH
```sh
$ export PATH=${PATH}:/usr/local/cuda/bin
$ export LD_LIBRARY_PATH=${LD_LIBRARY_PATH}:/usr/local/cuda/lib64
```

### CUDA  (Non Jetson users)
1. Update your Nvidia GPU driver with the latest Nvidia proprietary one 
2. Install CUDA Toolkit following the [CUDA Installation Guide](https://docs.nvidia.com/cuda/cuda-installation-guide-linux/index.html)

### cURL development library
`$ sudo apt-get install libcurl4-openssl-dev`  

### NVIDIA TensorRT (if not already installed or preinstalled)
[TensorRT Installation Guide](https://docs.nvidia.com/deeplearning/sdk/tensorrt-install-guide/index.html)

### Jetson-inference library
1. (Non Jetson users only) Copy `glibconfig.h` header to `/usr/include/glib-2.0/`  
```sh
$ sudo cp /usr/lib/x86_64-linux-gnu/glib-2.0/include/glibconfig.h /usr/include/glib-2.0/glibconfig.h
```
2. Follow the Build instructions from the [Jetson-inference GitHub page](https://github.com/dusty-nv/jetson-inference).  
N.B. (Non Jetson users only)  
Once downloaded the Jetson-inference library and before building the project, check that inside CMakeLists.txt your GPU architecture is specified (e.g. `-gencode arch=compute_62,code=sm_62`). Otherwise add it.  
A list of Nvidia GPU architectures could be found [here](https://github.com/Werther158/multimedia_sharing_tool/wiki/Nvidia-GPU-architectures-compatibility)

### FFmpeg  
`$ sudo apt-get install ffmpeg`

### CUDA Enabled OpenCV with Contrib  
1. Remove any previous installations of x264  
```sh
$ sudo apt-get remove x264 libx264-dev
```  

2. (Jetson Nano only) Set a swap file to allow the system to use more than 4 GB of RAM  
A swap file installer could be found [here](https://github.com/JetsonHacksNano/installSwapfile)

3. Install OpenCV dependencies  
```sh
$ sudo apt-get install build-essential checkinstall cmake pkg-config yasm
$ sudo apt-get install git gfortran
$ sudo apt-get install libjpeg8-dev libjasper-dev libpng12-dev
$ sudo apt-get install libtiff5-dev
$ sudo apt-get install libavcodec-dev libavformat-dev libswscale-dev libdc1394-22-dev
$ sudo apt-get install libxine2-dev libv4l-dev
$ sudo apt-get install libgstreamer0.10-dev libgstreamer-plugins-base0.10-dev
$ sudo apt-get install libqt4-dev libtbb-dev
$ sudo apt-get install libatlas-base-dev
$ sudo apt-get install libfaac-dev libmp3lame-dev libtheora-dev
$ sudo apt-get install libvorbis-dev libxvidcore-dev
$ sudo apt-get install libopencore-amrnb-dev libopencore-amrwb-dev
$ sudo apt-get install x264 v4l-utils
```

4. Clone `opencv` and `opencv_contrib` version 3.4.7 repository
```sh
$ git clone -b 3.4.7 https://github.com/opencv/opencv
$ git clone -b 3.4.7 https://github.com/opencv/opencv_contrib
```

5. Make a directory i.e. `build` inside `opencv` directory, compile and install the library  
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

## Building the project:  
1. Clone the project
```
$ git clone https://github.com/Werther158/multimedia_sharing_tool
```
2. Open the `.pro` file with QT Creator
3. Set `multimedia_sharing_tool/build/debug` and `multimedia_sharing_tool/build/release` as debug and release directories
4. Build the project
