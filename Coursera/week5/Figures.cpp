#include <bits/stdc++.h>

using namespace std;

class Figure
{
    public:
    virtual string Name()=0;
    virtual double Perimeter()=0;
    virtual double Area()=0;
    Figure(){}
};

class Triangle : public Figure
{
    public:
        double perimeter, area;
    Triangle(double a, double b, double c)
    {
        perimeter = (a + b + c) / 2;
        area = sqrt(perimeter * (perimeter - a) * (perimeter - b) * (perimeter - c));
        perimeter *= 2;
    }

    string Name()
    {
        return "TRIANGLE";
    }
    double Area()
    {
        return area;
    }
    double Perimeter()
    {
        return perimeter;
    }
};

class Rect : public Figure
{
    public:
        double perimeter, area;
    Rect(double a, double b)
    {
        perimeter = (a + b) * 2;
        area = a * b;
    }

    string Name()
    {
        return "RECT";
    }
    double Area()
    {
        return area;
    }
    double Perimeter()
    {
        return perimeter;
    }
};

class Circle : public Figure
{
    public:
        double perimeter, area;
    Circle(double a)
    {
        perimeter = a * 6.28;
        area = a * a * 3.14;
    }

    string Name()
    {
        return "CIRCLE";
    }
    double Area()
    {
        return area;
    }
    double Perimeter()
    {
        return perimeter;
    }
};

shared_ptr<Figure> CreateFigure(istringstream &in)
{
    string s;
    double a, b, c;
    in >> s;

    if (s == "CIRCLE")
    {
        in >> a;
        return make_shared<Circle>(a);
    }
    else if (s == "RECT")
    {
        in >> a >> b;
        return make_shared<Rect>(a,b);
    }
    else if (s == "TRIANGLE")
    {
        in >> a >> b >> c;
        return make_shared<Triangle>(a,b,c);
    }
}

int main() {
  /*vector<shared_ptr<Figure>> figures;
  for (string line; getline(cin, line); ) {
    istringstream is(line);

    string command;
    is >> command;
    if (command == "ADD") {
      figures.push_back(CreateFigure(is));
    } else if (command == "PRINT") {
      for (const auto& current_figure : figures) {
        cout << fixed << setprecision(3)
             << current_figure->Name() << " "
             << current_figure->Perimeter() << " "
             << current_figure->Area() << endl;
      }
    }
  }*/
  return 0;
}
