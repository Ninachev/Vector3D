#include "Vector3D.h"

Vector3D::Vector3D()
{
	x = 0;
	y = 0;
	z = 0;
}
Vector3D::Vector3D(double x, double y, double z) //  ����������� �� �������� ������ ( *this ) ������� ����������� �������� ���� ���������;
{
	this->x = x;
	this->y = y;
	this->z = z;
}
Vector3D Vector3D::operator+(const Vector3D & secondVector) const
{
	Vector3D newVector;
	newVector.x = this->x + secondVector.x;				// ��������� ��� ������ ����� �� ������ ����������� �� �������� ������( *this ) � ����������� �� 
	newVector.y = this->y + secondVector.y;				//��������� ���� ��������� ��� ���� ��������� � const(�� ���� �� ��������� ����������� �� �������� ������(*this));
	newVector.z = this->z + secondVector.z;						// ������� ����� ������;
	return newVector;
}
Vector3D Vector3D::operator-(const Vector3D & secondVector) const
{
	Vector3D newVector;
	newVector.x = this->x - secondVector.x;				// ��������� ��� ������ ����� �� ������ ����������� �� �������� ������( *this ) ����� ����������� �� 
	newVector.y = this->y - secondVector.y;				//��������� ���� ��������� ��� ���� ��������� � const(�� ���� �� ��������� ����������� �� �������� ������(*this));
	newVector.z = this->z - secondVector.z;						// ������� ����� ������;
	return newVector;
}
Vector3D Vector3D::operator-() const
{
	Vector3D newVector;									//��� ������ ����� ������ ����������� �� �������� �� - 1;
	newVector.x = this->x * -1;
	newVector.y = this->y * -1;
	newVector.z = this->z * -1;							// ������� ����� ������;
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
std::istream & operator>>(std::istream & input, Vector3D & vector)			// ����� ��������� �� ������� (����� x,y,z) �� ������� 4 char;
{
	char one, two, three, four;
	input >> one >> vector.x >> two >> vector.y >> three >> vector.z >> four;
	if (one == '(' && two == ',' && three == ',' && four == ')')
	{
		return input;
	}
}
std::ostream & operator<<(std::ostream & output, const Vector3D & vector) // ��� ����������� �������� ���� �������;
{
	output << "(" << vector.getX() << "," << vector.getY() << "," << vector.getZ() << ") "; // ���� ����� ������ ��� ������ ������������;
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
Vector3D::~Vector3D()	// � ������������ �� ��� �������� ��������� �����;
{
}
