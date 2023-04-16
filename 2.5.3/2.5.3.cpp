#include <iostream>
class Figure {
protected:
	std::string name;
	int a;
	int b;
	int c;
	int A;
	int B;
	int C;
	int sides;
public: 
	int get_sides() { return sides;}
	std::string get_name() { return name; }
	Figure() {
		name = "Фигура";
		a = 0;
		b = 0;
		c = 0;
		A = 0;
		B = 0;
		C = 0;
		sides = 0;
	}
	virtual bool check () { 
		int sides = this->sides;
		if (sides == 0) return true; else false; }
};
class Triangle : public Figure {
public:
	bool check () override { 
		int sides = this->sides;
		int A = this->A;
		int B = this->B;
		int C = this->C;
		if (sides == 3 && A+B+C==180) return true; else false; }
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
};
class right_t : public Triangle {
public:
	right_t(std::string n, int a, int b, int c, int A, int B, int C) : Triangle(n, a, b, c, A, B, C) {
		n = "прямоугольный треугольник";
		C = 90;
		set(n, a, b, c, A, B, C);
	}
	right_t() : right_t("прямоугольный треугольник", 10, 20, 30, 50, 60, 70) { ; }
	bool check() override {
		int A = this->A;
		int B = this->B;
		int C = this->C;
		if (C == 90 && A+B+C==180) return true;
		else return false;
	}
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
	bool check() override {
		int A = this->A;
		int B = this->B;
		int C = this->C;
		int a = this->a;
		int c = this->c;
		if (A == C && a == c && (A+B+C==180))
			return true;
		else return false;
	}
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
	bool check() override {
		int A = this->A;
		int B = this->B;
		int C = this->C;
		int a = this->a;
		int b = this->b;
		int c = this->c;
		if (a == b && a == c && A == B && A == C && A == 60)
			return true;
		else false;
	}
};

class Quadrangle : public Figure {
protected:
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
	bool check() override {
		int A = this->A;
		int B = this->B;
		int C = this->C;
		int D = this->D;
		if (A + B + C + D == 360)
			return true;
		else return false;
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
	bool check() override {
		int A = this->A;
		int B = this->B;
		int C = this->C;
		int D = this->D;
		int a = this->a;
		int b = this->b;
		int c = this->c;
		int d = this->d;
		if (A + B + C + D == 360 && A == C && a == c && B == D && b == d)
			return true;
		else return false;
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
	bool check() override {
		int A = this->A;
		int B = this->B;
		int C = this->C;
		int D = this->D;
		int a = this->a;
		int b = this->b;
		int c = this->c;
		int d = this->d;
		if (A + B + C + D == 360 && A == C && a == c && B == D && b == d && A == B && A == 90)
			return true;
		else return false;
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
	bool check() override {
		int A = this->A;
		int B = this->B;
		int C = this->C;
		int D = this->D;
		int a = this->a;
		int b = this->b;
		int c = this->c;
		int d = this->d;
		if (A + B + C + D == 360 && A == C && a == c && B == D && b == d && A == B && A == 90 && a == b)
			return true;
		else return false;
	}
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
	bool check() override {
		int A = this->A;
		int B = this->B;
		int C = this->C;
		int D = this->D;
		int a = this->a;
		int b = this->b;
		int c = this->c;
		int d = this->d;
		if (A + B + C + D == 360 && A == C && a == c && B == D && b == d)
			return true;
		else return false;
	}
};
void print(Figure* adress) {
	std::cout << adress->get_name() << ":\n";
	if (adress->check()) std::cout << "Правильная\n";
	else std::cout << "Неправильная\n";
	std::cout << "Количество сторон: " << adress->get_sides() << "\n";
	std::cout << "\n\n";
}
void print1(Triangle* adress) {
	std::cout << adress->get_name() << ":\n" << "Стороны: a=" << adress->get_a() << "    b=" << adress->get_b() << "   c=" << adress->get_c();
	std::cout << "\n" << "Углы: A=" << adress->get_A() << "   B=" << adress->get_B() << "   C=" << adress->get_C() << "\n";
	if (adress->check()) std::cout << "Правильная\n";
	else std::cout << "Неправильная\n";
	std::cout << "\n\n";
}
void print2(Quadrangle* adress) {
	std::cout << adress->get_name() << ":\n" << "Стороны: a=" << adress->get_a() << "    b=" << adress->get_b() << "   c=" << adress->get_c();
	std::cout << "   d=" << adress->get_d();
	std::cout << "\n" << "Углы: A=" << adress->get_A() << "   B=" << adress->get_B() << "   C=" << adress->get_C();
	std::cout << "   D=" << adress->get_D() << "\n";
	if (adress->check()) std::cout << "Правильная\n";
	else std::cout << "Неправильная\n";
	std::cout << "\n\n";
}
int main() {
	setlocale(LC_ALL, "Russian");
	Figure fig;
	Figure* fig_q = &fig;
	print(fig_q);
	Triangle tri;
	Triangle* tri_q = &tri;
	print1(tri_q);
	right_t rig;
	Triangle* rig_q = &rig;
	print1(rig_q);
	isosceles_t iso;
	Triangle* iso_q = &iso;
	print1(iso_q);
	equilateral_t equ;
	Triangle* equ_q = &equ;
	print1(equ_q);
	Quadrangle qua;
	Quadrangle* qua_q = &qua;
	print2(qua_q);
	parallelogram par;
	Quadrangle* par_q = &par;
	print2(par_q);
	rectangle rec;
	Quadrangle* rec_q = &rec;
	print2(rec_q);
	square sq;
	Quadrangle* sq_q = &sq;
	print2(sq_q);
	rhombus rho;
	Quadrangle* rho_q = &rho;
	print2(rho_q);

}