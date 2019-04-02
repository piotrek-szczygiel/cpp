#ifndef LAB3_PIXEL_H
#define LAB3_PIXEL_H


class Pixel {
private:
    int x;
    int y;

public:
    Pixel() : x(0), y(0) {}

    Pixel(int x, int y) : x(x), y(y) {}

    void debug() {
        std::cout << "(" << x << ", " << y << ")";
    }
};


#endif //LAB3_PIXEL_H
