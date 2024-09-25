#include "tests_helpers.hpp"

using namespace std;

bool ComparePixels(Pixel a, Pixel b) {
  if (a.r != b.r) return false;
  if (a.g != b.g) return false;
  if (a.b != b.b) return false;
  return true;
}

bool CompareImages(const Image& img,
                   const vector<vector<Pixel>>& ground_truth) {
  if (img.Height() != static_cast<int>(ground_truth.size()) ||
      img.Width() != static_cast<int>(ground_truth[0].size()))
    return false;
  for (int row = 0; row < static_cast<int>(ground_truth.size()); row++) {
    for (int col = 0; col < static_cast<int>(ground_truth[row].size()); col++) {
      if (!ComparePixels(ground_truth[row][col], img.GetPixel(row, col)))
        return false;
    }
  }
  return true;
}

bool CompareImages(const Image& img1, const Image& img2) {
  if (img1.Height() != img2.Height()) return false;
  if (img1.Width() != img2.Width()) return false;

  for (int row = 0; row < img1.Height(); row++) {
    for (int col = 0; col < img1.Width(); col++) {
      if (!ComparePixels(img2.GetPixel(row, col), img1.GetPixel(row, col)))
        return false;
    }
  }
  return true;
}
