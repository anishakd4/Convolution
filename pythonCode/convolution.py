import cv2
import numpy as np
import sys

#read image
image = cv2.imread("../assets/putin_noise.jpg")

if image is None:
    print("can not find the image")
    sys.exit()

#define kernel size = 5
kernelSize = 5

#create a 5x5 kernel with all elements equal to 1. We are use a kernel size of 5x5. To keep things simple, we will 
# also choose a kernel where all elements are the same. This kernel is often called a Box Kernel. Notice, the sum 
# of all the elements of the kernel add up to 1. This ensures that the output image has the same brightness level 
# as the input image. If we do not do this, the output pixels will be approximately 25 times (5x5 = 25) brighter 
# than the input pixels on average.
kernel = np.ones((kernelSize, kernelSize), dtype=np.float32)

#normalize the kernel so that all the sum of all the elements is equal to 1
kernel = kernel / (kernelSize**2)

#apply convolution filter. The third parameter (depth) is set to -1, which means the bit-depth of the output image 
# is the same as the input image. So if the input image is of type CV_8UC3, the output image will also be of the same 
# type. Later we will see certain kinds of kernels where CV_32F or CV_64F should be used.
result = cv2.filter2D(image, -1, kernel, (-1, -1), delta = 0, borderType=cv2.BORDER_DEFAULT)

#create windows to display images
cv2.namedWindow("image", cv2.WINDOW_NORMAL)
cv2.namedWindow("result", cv2.WINDOW_NORMAL)

#display images
cv2.imshow("image", image)
cv2.imshow("result", result)

#press esc to exit the program
cv2.waitKey(0)

#close all the opened windows
cv2.destroyAllWindows()