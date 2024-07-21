~~~c++
#include <windows.h>
#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <string>

int width;
int height;

void SaveBitmapToFile(HBITMAP hBitmap, const std::wstring& filename, BITMAPINFO& bmi) {
    BITMAP bmp;
    GetObject(hBitmap, sizeof(BITMAP), &bmp);

    BITMAPFILEHEADER bfh;
    bfh.bfType = 0x4D42; // 'BM' for BMP files
    bfh.bfReserved1 = 0;
    bfh.bfReserved2 = 0;
    bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);
    bfh.bfSize = bfh.bfOffBits + (bmp.bmWidth * bmp.bmHeight * 3); // 3 bytes per pixel

    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::wcerr << L"Error opening file for writing: " << filename << std::endl;
        return;
    }

    file.write(reinterpret_cast<const char*>(&bfh), sizeof(BITMAPFILEHEADER));
    file.write(reinterpret_cast<const char*>(&bmi.bmiHeader), sizeof(BITMAPINFOHEADER));

    // Allocate buffer for bitmap data
    std::vector<BYTE> buffer(bmp.bmWidth * bmp.bmHeight * 3);
    GetDIBits(GetDC(NULL), hBitmap, 0, bmp.bmHeight, buffer.data(), &bmi, DIB_RGB_COLORS);
    file.write(reinterpret_cast<const char*>(buffer.data()), buffer.size());

    file.close();
}

void CaptureScreenshot(HDC hdcScreen, HDC hdcMem, HBITMAP hbmScreen, BITMAPINFO& bmi, std::vector<BYTE>& buffer) {
    SelectObject(hdcMem, hbmScreen);
    BitBlt(hdcMem, 0, 0, width, height, hdcScreen, 0, 0, SRCCOPY);
    GetDIBits(hdcMem, hbmScreen, 0, height, buffer.data(), &bmi, DIB_RGB_COLORS);
}

int main() {
    HDC hdcScreen = GetDC(NULL);
    HDC hdcMem = CreateCompatibleDC(hdcScreen);
    // Get the actual screen resolution
    DEVMODE devMode;
    EnumDisplaySettings(NULL, ENUM_CURRENT_SETTINGS, &devMode);
    width = devMode.dmPelsWidth;
    height = devMode.dmPelsHeight;
    HBITMAP hbmScreen = CreateCompatibleBitmap(hdcScreen, width, height);

    BITMAPINFO bmi;
    ZeroMemory(&bmi, sizeof(bmi));
    bmi.bmiHeader.biSize = sizeof(BITMAPINFOHEADER);
    bmi.bmiHeader.biWidth = width;
    bmi.bmiHeader.biHeight = height; // Negative to specify top-down DIB
    bmi.bmiHeader.biPlanes = 1;
    bmi.bmiHeader.biBitCount = 24;
    bmi.bmiHeader.biCompression = BI_RGB;

    int bufferSize = width * height * 3; // 24-bit BMP: 3 bytes per pixel

    std::vector<BYTE> buffer(bufferSize);

    const int numScreenshots = 100;
    auto start = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < numScreenshots; ++i) {
        CaptureScreenshot(hdcScreen, hdcMem, hbmScreen, bmi, buffer);
        //std::wstring filename = L"screenshot.bmp";
        //SaveBitmapToFile(hbmScreen, filename, bmi);
    }

    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = end - start;
    double fps = numScreenshots / elapsed.count();

    std::wcout << L"FPS: " << fps << std::endl;

    DeleteObject(hbmScreen);
    DeleteDC(hdcMem);
    ReleaseDC(NULL, hdcScreen);

    return 0;
}
~~~
