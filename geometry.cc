// intersection points of two circles bool
bool intersec2pts(vector<double> c1,vector<double> c2)// vector of type x,y,r
{
	double r1dr2=abs(c1[2]-c2[2]);
	double r1ar2=c1[2]+c2[2];
	double dist=cordist({c1[0],c1[1]},{c2[0],c2[1]});
	bool flag1=(r1dr2<dist and abs(r1dr2-dist)>eps);
	bool flag2=(r1ar2>dist and abs(r1ar2-dist)>eps);
	return flag1 and flag2;
}

// intersection of two line segments
struct Point
{
    int x;
    int y;
};
bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) &&
        q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
  
    return false;
}
int orientation(Point p, Point q, Point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);
  
    if (val == 0) return 0;
  
    return (val > 0)? 1: 2;
}
bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
    if (o1 != o2 && o3 != o4)
        return true;
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
  
    return false;
}