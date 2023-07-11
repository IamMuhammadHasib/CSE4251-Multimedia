import numpy as np
import matplotlib.pyplot as plt
import cv2


def applyIDCT(image):
    height, width = image.shape
    decompressedImage = np.zeros((height, width))

    for i in range(0, height, 16):
        for j in range(0, width, 16):
            block = image[i:i+16, j:j+16]
            idctBlock = cv2.idct(block.astype(np.float32))
            decompressedImage[i:i+16, j:j+16] = idctBlock

    return decompressedImage


image = cv2.imread('transformed-image.jpg', cv2.IMREAD_GRAYSCALE)

decompressedImage = applyIDCT(image)

plt.subplot(1,2,1)
plt.imshow(image, cmap='gray')
plt.title('Transformed Image')

plt.subplot(1,2,2)
plt.imshow(decompressedImage, cmap='gray')
plt.title('Reconstructed Image')

plt.show()