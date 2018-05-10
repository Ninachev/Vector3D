#include <iostream>

#ifndef Vector3D_h
#define Vector3D_h
class Vector3D
{
private:
	double x;
	double y;
	double z;
public:
	Vector3D();
	Vector3D(double x, double y, double z);
	~Vector3D();
	double getX() const;
	double getY() const;
	double getZ() const;
	Vector3D operator+(const Vector3D & secondVector) const;
	Vector3D operator-(const Vector3D & secondVector) const;
	Vector3D operator-() const;
	Vector3D operator*(double number) const;
	friend Vector3D operator*(double number, const Vector3D & vector);
	friend std::istream & operator>>(std::istream & iStream, Vector3D & vector);
	friend std::ostream & operator<<(std::ostream & oStream, const Vector3D & vector);
};

#endif  /* Vector3D_H */