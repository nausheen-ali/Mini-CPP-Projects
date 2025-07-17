#include <iostream>
#include <iomanip>

using namespace std;

void square()
{
    float side, area;
    do{
        cout << "Enter side:";
        cin>> side;

        if (side<=0)
        {
            cout << "Side length must be >= 1";
        }
    }while(side<=0);

    area = side * side;
    cout << "Area of the square is:" << fixed << setprecision(2) << area << "sq. units" << endl;
}

void rectangle()
{
    float length, width, area;

    do{
        cout << "Enter length:";
        cin >> length;

        if(length<=0)
            cout << "Length must be >= 1" << endl;

    }while(length<=0);

    do{
        cout << "Enter width:";
        cin >> width;

        if(width<=0)
            cout << "Width must be >= 1" << endl;

    }while(width <=0);

    area = length * width;
    cout << "Area of the rectangle is:" << fixed << setprecision(2) << area << "sq. units" << endl;
}

void triangle()
{
    float base, height, area;

    do{
        cout << "Enter base:";
        cin >> base;

        if(base<=0)
            cout << "Base must be >= 1" << endl;

    }while(base<=0);

    do{
        cout << "Enter height:";
        cin >> height;

        if(height<=0)
            cout << "Height must be >= 1" << endl;

    }while(height <=0);

    area = 0.5 * base * height;
    cout << "Area of the triangle is:" << fixed << setprecision(2) << area << "sq. units" << endl;
}

void circle()
{
    float radius, area;
    do{
        cout << "Enter radius:";
        cin>> radius;

        if (radius<=0)
        {
            cout << "Radius must be >= 1";
        }
    }while(radius<=0);

    area = 3.14 * radius * radius;
    cout << "Area of the circle is:" << fixed << setprecision(2) << area << "sq. units" << endl;
}

int main()
{
    int choice;

    cout << "1. Square" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Triangle" << endl;
    cout << "4. Circle" << endl;
    cout << "Enter choice:";

    cin >> choice;

    switch(choice)
    {
    case 1:
        square();
        break;
    case 2:
        rectangle();
        break;
    case 3:
        triangle();
        break;
    case 4:
        circle();
        break;
    default:
        cout << "Invalid choice. Try again.";
    }

    return 0;
}
