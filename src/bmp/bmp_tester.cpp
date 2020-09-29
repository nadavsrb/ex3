#include "bmp_tester.hpp"

using namespace bmp;

void testing::bmp::rotate_image(const std::string& imagePath, const std::string& outputPath){
    string imageString = files::readFileContent(imagePath);
    auto bmpParser = make_unique<BMPParser>(imageString);
    bmpParser->rotateImage();
    files::writeFileContent(outputPath, bmpParser->getBMP());
}

void testing::bmp::convert_to_grayscale(const std::string& imagePath,
                        const std::string& outputPath){
    string imageString = files::readFileContent(imagePath);
    auto bmpParser = make_unique<BMPParser>(imageString);
    bmpParser->imageToGray();
    files::writeFileContent(outputPath, bmpParser->getBMP());
}