#include <iostream>
using namespace std;

class Figure {
protected:
	int sides_count = 0;
	string name;
public:
	Figure() = default;
	Figure(const string& new_name) : name(new_name)	{}
	string get_name() { return name; }
	const bool check() {
		if (sides_count == 0)return true;
		else return false;
	}
	virtual void print_info() {
		const bool &correct = check();
		cout << get_name() << "\n";
		if (correct == 1) cout << "Правильная\n";
		else cout << "Неправильная\n";
		cout << "Количество сторон: " << sides_count << "\n\n";
	}
};

class Triangle :public Figure {
protected:
	int a, b, c, A, B, C;	
public:
	Triangle(const string &name1, int new_a, int new_b, int new_c, int new_A, int new_B, int new_C) {
		name = name1;
		a = new_a;
		b = new_b;
		c = new_c;
		A = new_A;
		B = new_B;
		C = new_C;
		sides_count = 3;
	}
	const virtual bool check() {
		if (sides_count == 3 && A + B + C == 180)return true;
		else return false;
	}
	void print_info() override {
		const bool correct =check();
		cout << get_name() << endl;
		if (correct == 1) cout << "Правильная\n";
		else cout << "Неправильная\n";
		cout << "Количество сторон: " << sides_count << endl;
		cout << "Стороны: a=" << a << " b=" << b << " c=" << c << endl;
		cout << "Углы: A=" << A << " B=" << B << " C=" << C << "\n\n";
	}
};

class Right_Triangle :public Triangle {
public:
	Right_Triangle(const string &name1, int new_a, int new_b, int new_c, int new_A, int new_B) :Triangle(name1, new_a, new_b, new_c, new_A, new_B, 90) {}
	const bool check() override {
		if (sides_count == 3 && A + B + C == 180 && C==90)return 1;
		else return 0;
	}
};

class Isosceles_Triangle :public Triangle {
public:
	Isosceles_Triangle(const string &name1, int new_a, int new_b, int new_A, int new_B) :Triangle(name1, new_a, new_b, new_a, new_A, new_B, new_A) {}
	const bool check() override {
		if (sides_count == 3 && A + B + C == 180 && A == C && a == c)return 1;
		else return 0;
	}
};

class Equilateral_Triangle :public Triangle {
public:
	Equilateral_Triangle(const string& name1, int new_a) :Triangle(name1, new_a, new_a, new_a, 60, 60, 60) {}
	const bool check() override {
		if (sides_count == 3 && A + B + C == 180 && A == B && B == C && a == b && b == c)return 1;
		else return 0;
	}
};

class Quadrangle :public Figure {
protected:
	int a, b, c, d, A, B, C, D;
public:
	Quadrangle(const string& name1, int new_a, int new_b, int new_c, int new_d, int new_A, int new_B, int new_C, int new_D) {
		name = name1;
		a = new_a;
		b = new_b;
		c = new_c;
		d = new_d;
		A = new_A;
		B = new_B;
		C = new_C;
		D = new_D;
		sides_count = 4;
	}
	const virtual bool check() {
		if (sides_count == 4 && A + B + C +D== 360)return true;
		else return false;
	}
	void print_info() override {
		const bool correct = check();
		cout << get_name() << endl;
		if (correct == 1) cout << "Правильная\n";
		else cout << "Неправильная\n";
		cout << "Количество сторон: " << sides_count << endl;
		cout << "Стороны: a=" << a << " b=" << b << " c=" << c << " d=" << d << endl;
		cout << "Углы: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n\n";
	}
};

class Parallelogram :public Quadrangle {
public:
	Parallelogram(const string& name1, int new_a, int new_b, int new_A, int new_B) :Quadrangle(name1, new_a, new_b, new_a, new_b, new_A, new_B, new_A, new_B) {}
	const bool check() {
		if (sides_count == 4 && A + B + C + D == 360 && A == C && B == D && a == c && b == d)return true;
		else return false;
	}
};

class Rectangle :public Parallelogram {
public:
	Rectangle(const string& name1, int new_a, int new_b) :Parallelogram(name1, new_a, new_b, 90, 90) {}
	const bool check() {
		if (sides_count == 4 && A + B + C + D == 360 && A == 90 && B == 90 && A == C && B == D && a == c && b == d)return true;
		else return false;
	}
};

class Rhombus :public Parallelogram {
public:
	Rhombus(const string& name1, int new_a, int new_A, int new_B) :Parallelogram(name1, new_a, new_a, new_A, new_B) {}
	const virtual bool check() {
		if (sides_count == 4 && A + B + C + D == 360 && A == C && B == D && a==b && a == c && b == d)return true;
		else return false;
	}
};

class Square :public Rhombus {
public:
	Square(const string& name1, int new_a) :Rhombus(name1, new_a, 90, 90) {}
	const virtual bool check() {
		if (sides_count == 4 && A + B + C + D == 360 && A==90 && A == B && A == C && B == D && a == b && a == c && b == d)return true;
		else return false;
	}
};

void print(Figure* figure) {
	figure->print_info();
}

int main() {
	setlocale(LC_ALL, "rus");
	Figure figure("Фигура");
	Triangle triangle("Треугольник", 10, 20, 30, 50, 60, 70);
	Right_Triangle r_t("Прямоугольный треугольник", 10, 20, 30, 50, 60);
	Isosceles_Triangle i_t("Равнобедренный треугольник", 10, 20, 50, 60);
	Equilateral_Triangle e_t("Равносторонний треугольник", 30);
	Quadrangle quadrangle("Четырёхугольник", 10, 20, 30, 40, 50, 60, 70, 80);
	Parallelogram parallelogram("Параллелограмм", 20, 30, 30, 40);
	Rectangle rectangle("Прямоугольник", 10, 20);
	Rhombus rhombus("Ромб", 30, 30, 40);
	Square square("Квадрат", 20);

	print(&figure);
	print(&triangle);
	print(&r_t);
	print(&i_t);
	print(&e_t);
	print(&quadrangle);
	print(&rectangle);
	print(&square);
	print(&parallelogram);
	print(&rhombus);
	return 0;
}