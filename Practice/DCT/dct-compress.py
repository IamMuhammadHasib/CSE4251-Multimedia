import numpy as np
import matplotlib.pyplot as plt
import cv2


def applyDCT(image):

    height, width = image.shape
    transformedImage = np.zeros((height, width))

    for i in range(0, height, 16):
        for j in range(0, width, 16):
            block = image[i:i+16, j:j+16]
            dctBlock = cv2.dct(block.astype(np.float32))
            transformedImage[i:i+16, j:j+16] = dctBlock

    return transformedImage


def applyIDCT(image):
    height, width = image.shape
    decompressedImage = np.zeros((height, width))

    for i in range(0, height, 16):
        for j in range(0, width, 16):
            block = image[i:i+16, j:j+16]
            idctBlock = cv2.idct(block.astype(np.float32))
            decompressedImage[i:i+16, j:j+16] = idctBlock

    return decompressedImage


image = cv2.imread('img.jpg', cv2.IMREAD_GRAYSCALE)
print(image.shape[0]*image.shape[1])
transformedImage = applyDCT(image)
print(np.count_nonzero(transformedImage))
decompressedImage = applyIDCT(transformedImage)

plt.subplot(2,2,1)
plt.imshow(image, cmap='gray')
plt.title('Main')
# print("Here")
plt.subplot(2,2,2)
plt.imshow(transformedImage, cmap='gray')
plt.title('Transformed')
plt.subplot(2,2,3)
plt.imshow(decompressedImage, cmap='gray')
plt.title('Reconstructed')

cv2.imwrite('original-gray-image.jpg', image)
cv2.imwrite('transformed-image.jpg', transformedImage)
cv2.imwrite('reconstructed-image.jpg', decompressedImage)

plt.show()
