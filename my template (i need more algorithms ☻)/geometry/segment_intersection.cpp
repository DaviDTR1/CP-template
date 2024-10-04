using namespace std;
#define dd long double

const dd EPS=1e-12;

struct point{
   dd x;
   dd y;
   point operator-(point b){
      return point{this->x-b.x,this->y-b.y};
   }
};

dd CrossProduct(point p1, point p2){
   return p1.x*p2.y-p2.x*p1.y;
}
/*
   >0 implies that p0 is at the LEFT of p1 ----> p2
   <0 implies that p0 is at the RIGHT of p1 ----> p2
   ==0 implies that p0 is ON p1 ----> p2
*/
dd Direction(point p0, point p1, point p2){
   return CrossProduct(p1-p0,p2-p0);
}
/*
   Assuming that p0, p1 and p2 are collinears,
   Returns TRUE if p0 lies in the segment p1 |---| p2
*/
bool OnSegment(point p0, point p1, point p2){
   if(min(p1.x,p2.x)<=p0.x && max(p1.x,p2.x)>=p0.x && min(p1.y,p2.y)<=p0.y && max(p1.y,p2.y)>=p0.y)
      return true;
   return false;
}


/*
   True if the segments p1----p2 and p3----p4 intersect
   False otherwise
*/
bool SegmentIntersect(point p1, point p2, point p3, point p4){
   dd d1=Direction(p3,p1,p2);
   dd d2=Direction(p4,p1,p2);
   dd d3=Direction(p1,p3,p4);
   dd d4=Direction(p2,p3,p4);
   if( ( (d1>0 && d2<0) or (d1<0 && d2>0) ) && ( (d3>0 && d4<0) or (d3<0 && d4>0) ) ){
      return true;
   }
   if(fabs(d1)<=EPS && OnSegment(p3,p1,p2))return true;
   if(fabs(d2)<=EPS && OnSegment(p4,p1,p2))return true;
   if(fabs(d3)<=EPS && OnSegment(p1,p3,p4))return true;
   if(fabs(d4)<=EPS && OnSegment(p2,p3,p4))return true;
   return false;
}

