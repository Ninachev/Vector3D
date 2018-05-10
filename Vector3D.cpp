#include "Vector3D.h"

Vector3D::Vector3D()
{
	x = 0;
	y = 0;
	z = 0;
}
Vector3D::Vector3D(double x, double y, double z) //  Стойностите на сегашния вектор ( *this ) приемат стойностите подадени като параметри;
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Vector3D Vector3D::operator+(const Vector3D & secondVector) const
{
	Vector3D newVector;
	newVector.x = this->x + secondVector.x;				// Създаваме нов вектор които да приеме стойностите на сегашния вектор( *this ) и стойностите на 
	newVector.y = this->y + secondVector.y;				//подадения като параметър тъй като функцията е const(не може да променяме стойностите на сегашния вектор(*this));
	newVector.z = this->z + secondVector.z;						// Връщаме новия вектор;
	return newVector;
}
Vector3D Vector3D::operator-(const Vector3D & secondVector) const
{
	Vector3D newVector;
	newVector.x = this->x - secondVector.x;				// Създаваме нов вектор които да приеме стойностите на сегашния вектор( *this ) минус стойностите на 
	newVector.y = this->y - secondVector.y;				//подадения като параметър тъй като функцията е const(не може да променяме стойностите на сегашния вектор(*this));
	newVector.z = this->z - secondVector.z;						// Връщаме новия вектор;
	return newVector;
}
Vector3D Vector3D::operator-() const
{
	Vector3D newVector;									//Нов вектор който приема стойностите на сегашния по - 1;
	newVector.x = this->x * -1;
	newVector.y = this->y * -1;
	newVector.z = this->z * -1;							// Връщаме новия вектор;
	return newVector;
}
Vector3D Vector3D::operator*(double number) const
{
	Vector3D newVector;
	newVector.x = this->x * number;						
	newVector.y = this->y * number;
	newVector.z = this->z * number;
	return newVector;
}
Vector3D operator*(double number, const Vector3D & vector)
{
	Vector3D newVector;
	newVector.x = vector.x * number;
	newVector.y = vector.y * number;
	newVector.z = vector.z * number;
	return newVector;
}
std::istream & operator>>(std::istream & input, Vector3D & vector)			// Имаме въвеждане на символи (освен x,y,z) ни трябват 4 char;
{
	char one, two, three, four;
	input >> one >> vector.x >> two >> vector.y >> three >> vector.z >> four;
	if (one == '(' && two == ',' && three == ',' && four == ')')
	{
		return input;
	}
}
std::ostream & operator<<(std::ostream & output, const Vector3D & vector) // При извеждането запазвам тези символи;
{
	output << "(" << vector.getX() << "," << vector.getY() << "," << vector.getZ() << ") "; // След всеки вектор има празно пространство;
	return output;
}
double Vector3D::getX() const
{
	return x;
}
double Vector3D::getY() const
{
	return y;
}
double Vector3D::getZ() const
{
	return z;
}
Vector3D::~Vector3D()	// В конструктора не сме заделяли динамична памет;
{
}
