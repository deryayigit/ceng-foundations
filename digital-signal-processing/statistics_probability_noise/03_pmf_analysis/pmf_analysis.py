import matplotlib
matplotlib.use("Agg") # Use a non-interactive Matplotlib backend to allow plotting without a display.

import os              # File and directory operations
import glob            # File pattern matching
import numpy as np     # Numerical computations
from PIL import Image  # Image loading, conversion, and saving
import matplotlib.pyplot as plt  # Plotting PMFs

# Parameters
TARGET_WIDTH = 256
TARGET_HEIGHT = 256
NUM_IMAGES = 10
INPUT_DIR = "imagesDSP"
OUTPUT_DIR = "outputs"


def ensure_dir(path):
    os.makedirs(path, exist_ok=True)


def load_and_preprocess_image(path):
    img = Image.open(path) # Open image file (PIL automatically detects the format)

    #Convert the image to 8-bit grayscale ('L' mode, 0–255) if it is not already grayscale.
    if img.mode != "L":
        img = img.convert("L") 

    # Resize image to the target resolution if necessary
    if img.size != (TARGET_WIDTH, TARGET_HEIGHT):
        img = img.resize((TARGET_WIDTH, TARGET_HEIGHT), Image.BILINEAR)

    return np.array(img, dtype=np.uint8) ## Convert the image to a numpy array for numerical processing


def save_grayscale_image(image_array, filename):
    img = Image.fromarray(image_array, mode="L")
    img.save(filename)


def compute_pmf(image_array, max_value):
    flat = image_array.flatten()
    histogram = np.bincount(flat, minlength=max_value + 1)
    pmf = histogram / flat.size
    return pmf


def plot_pmf(pmf, title, filename):
    x = np.arange(len(pmf))  # Pixel value axis

    plt.figure()
    plt.plot(x, pmf)
    plt.xlabel("Pixel Value")
    plt.ylabel("PMF")
    plt.title(title)
    plt.grid(True)
    plt.tight_layout()
    plt.savefig(filename, dpi=200)
    plt.close()


def save_summed_image(summed_image, max_value, filename): # Normalize summed image to 0–255 before saving
    normalized = (summed_image / max_value) * 255.0
    normalized = normalized.astype(np.uint8)

    img = Image.fromarray(normalized, mode="L")
    img.save(filename)


def main():
    ensure_dir(OUTPUT_DIR)

    image_paths = []
    for ext in ("*.png", "*.jpg", "*.jpeg"):
        image_paths.extend(glob.glob(os.path.join(INPUT_DIR, ext)))

    image_paths = sorted(image_paths)

    if len(image_paths) < NUM_IMAGES:
        raise RuntimeError("At least 10 images are required.")

    image_paths = image_paths[:NUM_IMAGES]

    images = [load_and_preprocess_image(p) for p in image_paths]

    # Individual grayscale images and PMFs 
    for idx, img in enumerate(images, start=1):

        gray_path = os.path.join(OUTPUT_DIR, f"gray_image_{idx}.png")
        save_grayscale_image(img, gray_path)

        pmf = compute_pmf(img, 255)
        pmf_path = os.path.join(OUTPUT_DIR, f"pmf_image_{idx}.png")

        plot_pmf(
            pmf,
            f"PMF of Image {idx}",
            pmf_path
        )

    for K in (4, 8, 10): # Summed images and PMFs (4, 8, 10)

        summed_image = np.zeros(
            (TARGET_HEIGHT, TARGET_WIDTH),
            dtype=np.uint32
        )

        for i in range(K):
            summed_image += images[i].astype(np.uint32)

        max_value = 255 * K

        summed_img_path = os.path.join(
            OUTPUT_DIR, f"summed_image_{K}.png"
        )
        save_summed_image(
            summed_image, max_value, summed_img_path
        )

        pmf_sum = compute_pmf(summed_image, max_value)
        pmf_sum_path = os.path.join(
            OUTPUT_DIR, f"pmf_sum_{K}.png"
        )

        plot_pmf(
            pmf_sum,
            f"PMF of Summed Image (K={K})",
            pmf_sum_path
        )

    print("PMF analysis completed. Results saved in:", OUTPUT_DIR)


if __name__ == "__main__":
    main()
