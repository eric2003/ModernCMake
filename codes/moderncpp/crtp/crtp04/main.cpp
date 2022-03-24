#include <chrono>
#include <iostream>
 
// To store dimensions of an image
class Dimension {
public:
    Dimension(int _X, int _Y)
    {
        mX = _X;
        mY = _Y;
    }
 
private:
    int mX, mY;
};
 
// Base class for all image types
class Image {
public:
    virtual void Draw() = 0;
    virtual Dimension GetDimensionInPixels() = 0;
 
protected:
    int dimensionX;
    int dimensionY;
};
 
// For Tiff Images
class TiffImage : public Image {
public:
    void Draw() {}
    Dimension GetDimensionInPixels()
    {
        return Dimension(dimensionX, dimensionY);
    }
};
 
template <class T>
class CImage {
public:
    void Draw()
    {
        // Dispatch call to exact type
        static_cast<T*>(this)->Draw();
    }
    Dimension GetDimensionInPixels()
    {
        // Dispatch call to exact type
        static_cast<T*>(this)->GetDimensionInPixels();
    }
 
protected:
    int dimensionX, dimensionY;
};
 
// For Tiff Images
class CTiffImage : public CImage<CTiffImage> {
public:
    void Draw()
    {
        // Uncomment this to check method dispatch
        // cout << "CTiffImage::Draw() called" << endl;
    }
    Dimension GetDimensionInPixels()
    {
        return Dimension(dimensionX, dimensionY);
    }
};
 
// There can be more derived classes like PngImage,
// BitmapImage, etc
int main( int argc, char **argv )
{
    {
        typedef std::chrono::high_resolution_clock Clock;
        // An image type
        Image* pImage = new TiffImage;

        // Store time before virtual function calls
        auto then = Clock::now();

        // Call Draw 1000 times to make sure performance
        // is visible
        for ( int i = 0; i < 1000; ++ i )
            pImage->Draw();

        // Store time after virtual function calls
        auto now = Clock::now();

        std::cout << "virtual time taken: "
             << std::chrono::duration_cast<std::chrono::nanoseconds>(now - then).count()
             << " nanoseconds" << std::endl;
        delete pImage;
    }
    {
        typedef std::chrono::high_resolution_clock Clock;

        // An Image type pointer pointing to Tiffimage
        CImage<CTiffImage>* pImage = new CTiffImage;

        // Store time before virtual function calls
        auto then = Clock::now();

        // Call Draw 1000 times to make sure performance
        // is visible
        for ( int i = 0; i < 1000; ++ i )
            pImage->Draw();

        // Store time after virtual function calls
        auto now = Clock::now();

        std::cout << "crtp time taken: "
             << std::chrono::duration_cast<std::chrono::nanoseconds>(now - then).count()
             << " nanoseconds" << std::endl;
        delete pImage;
    }
 
    return 0;
}
