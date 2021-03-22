#include <iostream>
#include <set>
#include <vector>
#include <random>

class Shape;

class Singleton {
public:

	// TODO: implement the following constructor and operator, such that they do not allow copies
	Singleton(Singleton const&) = delete; //delete so there will only be one instance of the copy constructor  and operator occuring
	void operator=(Singleton const&) = delete;
	
	static Singleton& getInstance(void) 
	{
		static Singleton instance;
		return instance;
	}

	void addShape(Shape *s) 
	{
		set.insert(s);
	}

	void removeShape(Shape *s) 
	{
		set.erase(s);
	}

	int numShapes(void) 
	{
		return set.size();
	}

private:
	Singleton() {}
	std::set<Shape *> set;
};

class Shape {
public:
	Shape() 
	{
		Singleton&s = Singleton::getInstance();
		s.addShape(this);
	}

	~Shape() 
	{
		Singleton&s = Singleton::getInstance();
		s.removeShape(this);
	}

	virtual void draw(void) = 0;
};

class Point : public Shape 
{
public:
	Point(int x_, int y_)
		: Shape(), x(x_), y(y_) {}

	void draw(void) 
	{
		std::cout << "point(" << x << "," << y << ")";
	}
	
private:
	int x, y;
};

class Line : public Shape 
{
public:
	Line(int x0_, int y0_, int x1_, int y1_)
		: Shape(), p0(x0_, y0_), p1(x1_, y1_) {}

	void draw(void) 
	{
		std::cout << "line(";
		p0.draw();
		std::cout << ",";
		p1.draw();
		std::cout << ")";
	}
private:
	Point p0, p1;
};


//-------------------------------------------------
// You should not need to edit anything below here
//-------------------------------------------------
int main(int argc, char *argv[])
{
	std::vector<Shape *> draw;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> unif(-100, 100);

	// Randomly generate either Point and Line
	for (auto i = 0; i < 4; ++i) {
		if (unif(gen) > 0) {
			Point *point = new Point(unif(gen), unif(gen));
			draw.push_back(point);
		}
		else {
			Line *line = new Line(unif(gen), unif(gen),
					      unif(gen), unif(gen));
			draw.push_back(line);
		}
	}

	// Draw all randomly generated shapes
	for (auto s : draw) {
		s->draw();
		std::cout << std::endl;
	}

	// Free all randomly generated shapes
	for (auto s : draw) {
		delete s;
	}

	// Print out the number of remaining shapes
	std::cout << "Num shapes: " <<
		Singleton::getInstance().numShapes() <<
		std::endl;
	return EXIT_SUCCESS;
}
