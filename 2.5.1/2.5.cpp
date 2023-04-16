#include <iostream>
class Figure {
protected:
	int sides;
	std::string name;
public:
	int get_sides() { return sides; }
	std::string get_name() { return name; }
	Figure( int s, std::string n) {
		sides = s;
		name = n;
	}
	Figure() {
		sides = 0;
		name = "Фигура";
	}
};
class Triangle : public Figure {
public:
	Triangle(int s = 3, std::string n = "Треугольник") : Figure(s, n) { ; }
};
class Quadrangle : public Figure {
public:
	Quadrangle(int s = 4, std::string n = "Четырёхугольник") : Figure(s, n) { ; }
};

int main() {
	setlocale(LC_ALL, "Russian");
	Figure f;
	Triangle t;
	Quadrangle q;

	std::cout << "Количество сторон:\n" << f.get_name()<<": " << f.get_sides() << "\n";
	std::cout << t.get_name() << ": " << t.get_sides() << "\n";
	std::cout << q.get_name() << ": " << q.get_sides() << "\n";
}