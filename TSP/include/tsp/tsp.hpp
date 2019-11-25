#include <vector>
#include <utility>
#include <list>
#include <cmath>
#include <algorithm>
#include <limits>
// #include <gsl/gsl>

enum class Orientation {direct, reverse};

class Point
{
  float x, y;
public:
  Point() : x(0), y(0) {   }
  Point (float x, float y){
    this->x = x;
    this->y = y;
  }
  Point (const Point& p) : x(p.x), y(p.y) {   }
  Point& operator= (const Point& p)
  {
    x = p.x;
    y = p.y;
    return *this;
  }
  float getX() const
  {
    return this->x;
  }
  float getY() const
  {
    return this->y;
  }
  float distance(Point p) const
  {
    float dx, dy;
    dx = p.x - x;
    dy = p.y - y;
    return std::sqrt(dx*dx + dy*dy);
  }
};

inline bool operator==(const Point& lhs, const Point& rhs){ return (lhs.getX() == rhs.getX()) && (lhs.getY()==rhs.getY()); }
inline bool operator!=(const Point& lhs, const Point& rhs){ return !(lhs == rhs); }

std::list<Point> closestPair(std::vector<Point>);

