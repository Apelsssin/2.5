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
	virtual void print() { ; }
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
	void set(std::string name, int a, int b, int c, int A, int B, int C) {
		this->name = name;
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
	}
	Triangle(std::string name, int a, int b, int c, int A, int B, int C) {
		this->name = "треугольник";
		this->a = a;
		this->b = b;
		this->c = c;
		this->A = A;
		this->B = B;
		this->C = C;
		sides = 3;
	}
	Triangle() : Triangle("треугольник", 10, 20, 30, 50, 60, 70) { ; }
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
	right_t(std::string n, int a, int b, int c, int A, int B, int C) : Triangle(n, a, b, c, A, B, C) {
		n = "прямоугольный треугольник";
		C = 90;
		set(n, a, b, c, A, B, C);
	}
	right_t() : right_t("прямоугольный треугольник", 10, 20, 30, 50, 60, 70) { ; }
};
class isosceles_t : public Triangle {
public:
	isosceles_t(std::string n, int a, int b, int c, int A, int B, int C) : Triangle(n, a, b, c, A, B, C) {
		n = "равнобедренный треугольник";
		A = C;
		a = c;
		set(n, a, b, c, A, B, C);
	}
	isosceles_t() : isosceles_t("равнобедренный треугольник", 10, 20, 30, 50, 60, 70) { ; }
};
class equilateral_t : public isosceles_t {
public:
	equilateral_t(std::string n, int a, int b, int c, int A, int B, int C) : isosceles_t(n, a, b, c, A, B, C) {
		n = "равносторонний треугольник";
		A = 60;
		B = A;
		C = A;
		a = b;
		c = b;
		set(n, a, b, c, A, B, C);
	}
	equilateral_t() : equilateral_t("равносторонний треугольник", 10, 20, 30, 50, 60, 70) { ; }
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
	Quadrangle(std::string name, int a, int b, int c, int d, int A, int B, int C, int D) {
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
	Quadrangle() : Quadrangle("четырехугольник", 10, 20, 30, 40, 50, 60, 70, 80) { ; }
	void set(std::string name, int a, int b, int c, int d, int A, int B, int C, int D) {
		this->name = name;
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->A = A;
		this->B = B;
		this->C = C;
		this->D = D;
	}
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
	parallelogram() : parallelogram("параллелограмм", 10, 20, 30, 40, 50, 60, 70, 80) { ; }
	parallelogram(std::string n, int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(n, a, b, c, d, A, B, C, D) {
		n = "параллелограмм";
		a = c;
		b = d;
		A = C;
		B = D;
		set(n, a, b, c, d, A, B, C, D);
	}
};
class rectangle : public parallelogram {
public:
	rectangle() : rectangle("прямоугольник", 10, 20, 30, 40, 50, 60, 70, 80) { ; }
	rectangle(std::string n, int a, int b, int c, int d, int A, int B, int C, int D) : parallelogram(n, a, b, c, d, A, B, C, D) {
		n = "прямоугольник";
		A = 90;
		B = A;
		C = A;
		D = A;
		a = c;
		b = d;
		set(n, a, b, c, d, A, B, C, D);
	}
};
class square : public rectangle {
public:

	square(std::string n, int a, int b, int c, int d, int A, int B, int C, int D) : rectangle(n, a, b, c, d, A, B, C, D) {
		n = "квадрат";
		b = a;
		c = a;
		d = a;
		A = 90;
		B = A;
		C = A;
		D = A;
		set(n, a, b, c, d, A, B, C, D);
	}

	square() : square("квадрат", 10, 20, 30, 40, 50, 60, 70, 80) { ; }
};
class rhombus : public parallelogram {
public:
	rhombus(std::string n, int a, int b, int c, int d, int A, int B, int C, int D) : parallelogram(n, a, b, c, d, A, B, C, D) {
		n = "ромб";
		a = c;
		b = c;
		d = c;
		C = A;
		D = B;
		set(n, a, b, c, d, A, B, C, D);
	}
	rhombus() : rhombus("ромб", 10, 20, 30, 40, 50, 60, 70, 80) { ; }
	
};
void print(Figure* adress) {
	adress->print();
}
int main() {
	setlocale(LC_ALL, "Russian");
	Figure fig;
	Figure* fig_q = &fig;
	print(fig_q);
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