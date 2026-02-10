#include <stdio.h> // // standard input/output operations (printf, fopen, fread, fseek, fclose)
#include <stdlib.h> // memory management (malloc, free, abs)
#include <string.h>  // string manipulation
#include <math.h> // mathematical operations

#define LEVELS 256 //8-bit greyscale → 256 levels between 0 and 255

#pragma pack(push, 1)

// BMP File Header (14 bytes)
typedef struct {
    unsigned short bfType;
    unsigned int   bfSize;
    unsigned short bfReserved1;
    unsigned short bfReserved2;
    unsigned int   bfOffBits;
} BITMAPFILEHEADER;

//BMP Info Header (40 bytes)
typedef struct {
    unsigned int   biSize;
    int            biWidth;
    int            biHeight;
    unsigned short biPlanes;
    unsigned short biBitCount;
    unsigned int   biCompression;
    unsigned int   biSizeImage;
    int            biXPelsPerMeter;
    int            biYPelsPerMeter;
    unsigned int   biClrUsed;
    unsigned int   biClrImportant;
} BITMAPINFOHEADER;

#pragma pack(pop)


//Function Declaration

FILE* get_valid_bmp_file(BITMAPFILEHEADER* fh, BITMAPINFOHEADER* ih);
unsigned char rgb_to_gray(unsigned char R, unsigned char G, unsigned char B);
void process_image_and_histogram(FILE* fp, BITMAPFILEHEADER* fh,
                                 BITMAPINFOHEADER* ih, int histogram[]);
double compute_mean(int histogram[], int total_pixels);
double compute_variance(int histogram[], int total_pixels, double mean);
void print_results(int width, int height, int total_pixels,
                   double mean, double variance);


int main(void) {
    BITMAPFILEHEADER fileHeader;
    BITMAPINFOHEADER infoHeader;

    FILE* fp = get_valid_bmp_file(&fileHeader, &infoHeader);
    if (!fp) return 0;

    int histogram[LEVELS] = {0};

    process_image_and_histogram(fp, &fileHeader, &infoHeader, histogram);
    fclose(fp);

    int width  = infoHeader.biWidth;
    int height = abs(infoHeader.biHeight);
    int total_pixels = width * height;

    double mean = compute_mean(histogram, total_pixels);
    double variance = compute_variance(histogram, total_pixels, mean);

    print_results(width, height, total_pixels, mean, variance);

    printf("\nPress Enter for finishing process");
    getchar();
    return 0;
}

//Function Definitions

FILE* get_valid_bmp_file(BITMAPFILEHEADER* fh, BITMAPINFOHEADER* ih) {
    char filename[512];
    FILE* fp;

    while (1) {
        printf("\nEnter BMP image path:\n");
        fflush(stdout);

        if (!fgets(filename, sizeof(filename), stdin))
            continue;

        filename[strcspn(filename, "\n")] = '\0';

        fp = fopen(filename, "rb");
        if (!fp) {
            printf("Failed to open file.\n");
        }
        else if (fread(fh, sizeof(BITMAPFILEHEADER), 1, fp) != 1 ||
                 fread(ih, sizeof(BITMAPINFOHEADER), 1, fp) != 1) {
            printf("Failed to read BMP headers.\n");
            fclose(fp);
        }
        else if (fh->bfType != 0x4D42) { // BMP file signature check ('BM' in little-endian format)
            printf("Not a valid BMP file.\n");
            fclose(fp);
        }
        else if (ih->biBitCount != 24) {
            printf("Only 24-bit BMP images are supported.\n");
            fclose(fp);
        }
        else if (ih->biCompression != 0) {
            printf("Only uncompressed BMP is supported.\n");
            fclose(fp);
        }
        else {
            return fp; 
        }

        printf("Try another file? (Y/N): ");
        char c;
        scanf(" %c", &c);
        getchar();

        if (c == 'N' || c == 'n')
            return NULL;
    }
}

unsigned char rgb_to_gray(unsigned char R, unsigned char G, unsigned char B) {
    return (unsigned char)(0.299 * R + 0.587 * G + 0.114 * B + 0.5);
}

void process_image_and_histogram(FILE* fp, BITMAPFILEHEADER* fh,
                                 BITMAPINFOHEADER* ih, int histogram[]) {
    int width  = ih->biWidth;
    int height = abs(ih->biHeight);

    int row_padded = (width * 3 + 3) & (~3); // Calculate row size including BMP 4-byte alignment (row padding)
    unsigned char* row = (unsigned char*)malloc(row_padded);

    if (!row) {
        printf("Memory allocation failed.\n");
        exit(1);
    }

    fseek(fp, fh->bfOffBits, SEEK_SET); // Jump the file pointer to where the pixel data begins.

    for (int y = 0; y < height; y++) { // Process each pixel in the current row
        fread(row, 1, row_padded, fp);

        for (int x = 0; x < width; x++) {
            unsigned char B = row[x * 3 + 0];
            unsigned char G = row[x * 3 + 1];
            unsigned char R = row[x * 3 + 2];

            unsigned char gray = rgb_to_gray(R, G, B);
            histogram[gray]++;
        }
    }

    free(row);
}

double compute_mean(int histogram[], int total_pixels) {
    double mean = 0.0;
    for (int i = 0; i < LEVELS; i++)
        mean += i * histogram[i];
    return mean / total_pixels;
}

double compute_variance(int histogram[], int total_pixels, double mean) {
    double var = 0.0;
    for (int i = 0; i < LEVELS; i++)
        var += (i - mean) * (i - mean) * histogram[i];
    return var / total_pixels;
}

void print_results(int width, int height, int total_pixels,
                   double mean, double variance) {
    printf("\n Grayscale Image Analysis: \n");
    printf("Image Size   : %d x %d\n", width, height);
    printf("Total Pixels : %d\n", total_pixels);
    printf("Mean         : %.2f\n", mean);
    printf("Variance     : %.2f\n", variance);
}
