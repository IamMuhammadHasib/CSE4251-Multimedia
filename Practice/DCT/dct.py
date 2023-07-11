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


def applyIDCT(transformedImage):
    height, width = transformedImage.shape
    reconstructedImage = np.zeros((height, width))

    for i in range(0, height, 16):
        for j in range(0, width, 16):
            block = transformedImage[i:i+16, j:j+16]
            idctBlock = cv2.idct(block.astype(np.float32))
            reconstructedImage[i:i+16, j:j+16] = idctBlock

    return reconstructedImage


# Load the image
image = cv2.imread('img.jpg', cv2.IMREAD_GRAYSCALE)

# Apply DCT compression
compressedImage = applyDCT(image)

# Apply inverse DCT to reconstruct the image
reconstructedImage = applyIDCT(compressedImage)

# Calculate compression ratio
originalSize = image.shape[0] * image.shape[1]
print(originalSize)
compressedSize = np.count_nonzero(compressedImage)
print(compressedSize)
compressionRatio = compressedSize / originalSize

print(f"Compression ratio: {compressionRatio}")

# Plotting the images
plt.subplot(1, 2, 1)
plt.imshow(image, cmap='gray')
plt.title('Original Image')

plt.subplot(1, 2, 2)
plt.imshow(reconstructedImage, cmap='gray')
plt.title('Reconstructed Image')

plt.show()
