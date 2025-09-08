#ifndef POINT_HH
#define POINT_HH

class Point {
private:
    int x, y;      
public:
    Point();     
    Point(int xx, int yy); 
    void nhap();    
    void xuat();    
    int getX() const;
    int getY() const;
};

#endif
