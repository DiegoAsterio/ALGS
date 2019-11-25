#include "tsp.hpp"

std::list<std::list<Point> > getChains(std::vector<Point> v)
{
  std::list<std::list<Point> > ret = {};
  for(auto& p : v)
    {
      ret.push_back({p});
    }
  return ret;
};

// bool lessT(const std::pair<float,std::pair<Point,Point> >& x,const std::pair<float,std::pair<Point,Point> >& y)
// {
//   return x.first < y.first;
// }

std::pair<float,std::pair<Point,Point> > closestPoints(std::vector<Point> ee1, std::vector<Point> ee2){
  float dist = std::numeric_limits<float>::max();
  std::pair<float,std::pair<Point,Point> > ret ;
  for(auto e1 : ee1)
    {
      for(auto e2 : ee2)
	{
	  float d = e1.distance(e2);
	  if (d < dist)
	    {
	      ret = std::make_pair(d, std::make_pair(e1,e2));
	    }
	}
    }
  return ret;
}

std::pair<Orientation, Orientation> getOrientation(std::pair<Point,Point> ee1, std::pair<Point,Point> ee2, std::pair<Point,Point> choice)
{
  Orientation orient1, orient2;
  Point p1 = choice.first;
  Point p2 = choice.second;
  if (p1 == ee1.first)
    {
      orient1 = Orientation::reverse;
    }
  else
    {
      orient1 = Orientation::direct;
    }
  if (p2 == ee2.first)
    {
      orient2 = Orientation::direct;
    }
  else
    {
      orient2 = Orientation::reverse;
    }
  std::pair<Orientation,Orientation> ret(orient1, orient2);
  return ret;
}

std::list<Point> genNewChain(std::list<Point> c1,std::list<Point> c2,std::pair<Orientation,Orientation> alignment){
  std::list<Point> ret = {};
  if (alignment.first == Orientation::direct)
    {
      for (auto e : c1){
	ret.push_back(e);
      }
    }
  else
    {
      for (auto e : c1){
	ret.push_front(e);
      }
    }
  if (alignment.first == Orientation::direct)
    {
      for(auto e : c2){
	ret.push_back(e);
      }
    }
  else
    {
      for(auto it = c2.rbegin(); it != c2.rend(); it++)
	{
	  ret.push_back(*it);
	}
    }
  return ret;
}

std::list<std::list<Point> > replaceIn(std::list<std::list<Point> > usedList, std::list<Point> choice1, std::list<Point> choice2, std::list<Point> replacement)
{
  std::list<std::list<Point> > ret (usedList);
  ret.remove_if([choice1,choice2](std::list<Point> p){return (p==choice1) || (p==choice2);});
  ret.push_back(replacement);
  return ret;
}

std::list<Point> closestPair(std::vector<Point> v)
{
  const int N = v.size();
  std::list<std::list<Point> > c = getChains(v);
  for(int i = 1; i<N; ++i)
    {
     std::pair<Orientation,Orientation> alignment;
     float dist = std::numeric_limits<float>::max();
     std::list<Point> c1, c2;
     for(auto& l1 : c)
       {
	for(auto& l2 : c)
	  {
	   if (l1 != l2)
	     {
	      Point f1 = l1.front();
	      Point b1 = l1.back();
	      Point f2 = l2.front();
	      Point b2 = l2.back();
	      std::vector<Point> ee1 = {f1, b1};
	      std::vector<Point> ee2 = {f2, b2};
	      std::pair<float,std::pair<Point,Point> > close = closestPoints(ee1, ee2);
	      float d = close.first;
	      if (d < dist)
		{
		 dist = d;
		 std::pair<Orientation,Orientation> align = getOrientation(std::make_pair(f1,b1), std::make_pair(f2,b2), close.second);
		 c1 = l1;
		 c2 = l2;
		 alignment = align;
		}
	     }
	  }
       }
     std::list<Point> newC = genNewChain(c1,c2,alignment);
     c = replaceIn(c,c1,c2,newC);
    }
  return c.front();
}
