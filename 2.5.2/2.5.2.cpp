#include <iostream>
class Figure {
protected:
	std::string name;
	int sides;
public:
	int get_sides() { return sides; }
	std::string get_name() { return name; }
	Figure() {
		name = "Фигура";
		sides = 0;
	}
	virtual void print() {
		std::cout << get_name() << ":\n";
		std::cout << "\n\n";
	}
};
class Triangle : public Figure {
protected:
	int a;
	int b;
	int c;
	int A;
	int B;
	int C;
public:
	Triangle(int a, int b, int c, int A, int B, int C) {
		this->name = "треугольник";
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		sides = 3;
	}
	Triangle() : Triangle(10, 20, 30, 50, 60, 70) { ; }
	std::string get_name() { return name; }
	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	void print() override {
		std::cout << name << ":\n";
		std::cout << "Стороны: a=" << get_a() << "    b=" << get_b() << "   c=" << get_c();
		std::cout << "\n" << "Углы: A=" << get_A() << "   B=" << get_B() << "   C=" << get_C() << "\n";
		std::cout << "\n\n";
	}
};
class right_t : public Triangle {
public:
	right_t(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
		name = "прямоугольный треугольник";
	}
	right_t() : right_t(10, 20, 30, 50, 60) { ; }
};
class isosceles_t : public Triangle {
public:
	isosceles_t(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
		name = "равнобедренный треугольник";
	}
	isosceles_t() : isosceles_t(10, 20, 50, 60) { ; }
};
class equilateral_t : public isosceles_t {
public:
	equilateral_t(int a) : isosceles_t(a, a, 60, 60) {
		name = "равносторонний треугольник";
	}
	equilateral_t() : equilateral_t(10) { ; }
};

class Quadrangle : public Figure {
protected:
	int a;
	int b;
	int c;
	int A;
	int B;
	int C;
	int d;
	int D;
public:
	Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) {
		this->name = "четырехугольник";
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
		this->sides = 4;
	}
	Quadrangle() : Quadrangle(10, 20, 30, 40, 50, 60, 70, 80) { ; }
	std::string get_name() { return name; }
	int get_a() { return a; }
	int get_b() { return b; }
	int get_c() { return c; }
	int get_d() { return d; }
	int get_A() { return A; }
	int get_B() { return B; }
	int get_C() { return C; }
	int get_D() { return D; }

	void print() override {
		std::cout << get_name() << ":\n";
		std::cout << "Стороны: a=" << get_a() << "    b=" << get_b() << "   c=" << get_c();
		std::cout << "   d=" << get_d();
		std::cout << "\n" << "Углы: A=" << get_A() << "   B=" << get_B() << "   C=" << get_C();
		std::cout << "   D=" << get_D() << "\n";
		std::cout << "\n\n";
	}
};
class parallelogram : public Quadrangle {
public:
	parallelogram() : parallelogram(10, 20, 50, 60) { ; }
	parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
		name = "параллелограмм";
	}
};
class rectangle : public parallelogram {
public:
	rectangle() : rectangle(10, 20) { ; }
	rectangle(int a, int b) : parallelogram(a, b, 90, 90) {
		name = "прямоугольник";
	}
};
class square : public rectangle {
public:

	square(int a) : rectangle(a, a) {
		name = "квадрат";
	}

	square() : square(10) { ; }
};
class rhombus : public parallelogram {
public:
	rhombus(int a, int A, int B) : parallelogram(a, a, A, B) {
		name = "ромб";
	}
	rhombus() : rhombus(10, 60, 70) { ; }
};
void print(Figure* adress) {
	adress->print();
}
int main() {
	setlocale(LC_ALL, "Russian");
	Triangle tri;
	Triangle* tri_q = &tri;
	print(tri_q);
	right_t rig;
	Triangle* rig_q = &rig;
	print(rig_q);
	isosceles_t iso;
	Triangle* iso_q = &iso;
	print(iso_q);
	equilateral_t equ;
	Triangle* equ_q = &equ;
	print(equ_q);
	Quadrangle qua;
	Quadrangle* qua_q = &qua;
	print(qua_q);
	parallelogram par;
	Quadrangle* par_q = &par;
	print(par_q);
	rectangle rec;
	Quadrangle* rec_q = &rec;
	print(rec_q);
	square sq;
	Quadrangle* sq_q = &sq;
	print(sq_q);
	rhombus rho;
	Quadrangle* rho_q = &rho;
	print(rho_q);
}