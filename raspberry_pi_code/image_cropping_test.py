import cv2

# Load the image
image_path = 'path/to/your/image.jpg'
image_output_path_test = 
image = cv2.imread(image_path)

# Check if the image was successfully loaded
if image is None:
    print(f"Error: Unable to load image at {image_path}")
    exit()

# Define the cropping region
# (startY, endY, startX, endX)
startY, endY = 50, 200  # Crop vertically from 50 to 200 pixels
startX, endX = 100, 300  # Crop horizontally from 100 to 300 pixels

# Crop the image
cropped_image = image[startY:endY, startX:endX]

# Save the cropped image, overwriting the original file
cv2.imwrite(image_path, cropped_image)