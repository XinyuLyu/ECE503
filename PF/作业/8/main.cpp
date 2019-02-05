#include<iostream>
#include<iomanip>
using namespace std;
#include<vector>
#include"Circle.h"
#include"Sphere.h"
#include"Tetrahedron.h"
#include"ThreeDimensionalShape.h"
#include"Triangle.h"
#include"TwoDimensionalShape.h"
#include"Shape.h"

void vituralViaPointer(const Shape*);
void Menu();
int main()
{
	int choice = 0;
	int x, y, z = 0;
	double r,l= 0;
	Circle circle;
	Triangle triangle;
	Sphere sphere;
	Tetrahedron tetrahedron;
	vector<Shape*>shapeVector(4);
	shapeVector[0] = &circle;
	shapeVector[1] = &triangle;
	shapeVector[2] = &sphere;
	shapeVector[3] = &tetrahedron;

	Menu();
     do{
		do
		{
			cout << "Choice: ";
			cin >> choice;
			if (choice < 0 || choice>4)
			{
				cout << "Valid choice,input again." << endl;
			}
		} while (choice < 0 || choice>4);
		switch (choice)
		{
		case 1:
			cout << "You have chosen the Circle." << endl;
			cout << "Please enter the radius the Circle." << endl;
			cin >> r;
			circle.setRadius(r);
			cout << "Please enter the center of the Circle (x-coordinate, y-coordinate):" << endl;
			cin >> x >> y;
			circle.setX(x);
			circle.setY(y);
			shapeVector[0]->print();
			cout << fixed << setprecision(4) << "Area of: " << shapeVector[0]->getArea() << endl;
			break;
		case 2:
			cout << "You have chosen the Triangle." << endl;
			cout << "Please enter the edge length of the Triangle." << endl;
			cin >> l;
			triangle.setLength(l);
			cout << "Please enter the center of the Triangle (x-coordinate, y-coordinate):" << endl;
			cin >> x >> y;
			triangle.setX(x);
			triangle.setY(y);
			shapeVector[1]->print();
			cout << fixed << setprecision(4) << "Area of: " << shapeVector[1]->getArea() << endl;
			break;
		case 3:
			cout << "You have chosen the Sphere." << endl;
			cout << "Please enter the radius of the Sphere." << endl;
			cin >> r;
			sphere.setRadius(r);
			cout << "Please enter the center of the Sphere (x-coordinate, y-coordinate, z-coordinate):" << endl;
			cin >> x >> y >> z;
			sphere.setX(x);
			sphere.setY(y);
			sphere.setZ(z);
			shapeVector[2]->print();
			cout << fixed << setprecision(4) << "Surface area of: " << shapeVector[2]->getArea() << endl;
			cout << fixed << setprecision(4) << "Volume of: " << shapeVector[2]->getVolume() << endl;
			break;
		case 4:
			cout << "You have chosen the regular Tetrahedron." << endl;
			cout << "Please enter the edge length of the Tetrahedron." << endl;
			cin >> l;
			tetrahedron.setLength(l);
			cout << "Please enter the center of the regular Tetrahedron (x-coordinate, y-coordinate, z-coordinate):" << endl;
			cin >> x >> y >> z;
			tetrahedron.setX(x);
			tetrahedron.setY(y);
			tetrahedron.setZ(z);
			shapeVector[3]->print();
			cout << fixed << setprecision(4) << "Surface area of: " << shapeVector[3]->getArea() << endl;
			cout << fixed << setprecision(4) << "Volume of: " << shapeVector[3]->getVolume() << endl;
			break;
		case 0:
			break;
		default:
			break;
		}
} while (choice!=0);
	system("pause");
	return 0;
}
void Menu()
{
	cout << "Please choose a shape or 0 to exit:" << endl;
	cout << "1. Circle" << endl;
	cout << "2. Triangle" << endl;
	cout << "3. Sphere" << endl;
	cout << "4. Regular Tetrahedron " << endl;
	cout << "0.Exit" << endl;
}
