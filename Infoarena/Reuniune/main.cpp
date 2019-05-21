#include <fstream>
#include <algorithm>

using namespace std;

ifstream fin("reuniune.in");
ofstream fout("reuniune.out");

struct dreptunghi {long long x1,y1,x2,y2;};

dreptunghi d1,d2,d3,in1,in2,in3,in4;

void intersectiee (dreptunghi A, dreptunghi B, dreptunghi &C){
    C.x1=max(A.x1,B.x1);
    C.y1=max(A.y1,B.y1);
    C.x2=min(A.x2,B.x2);
    C.y2=min(A.y2,B.y2);
        if (C.x1>C.x2 || C.y1>C.y2)
    {
        C.x1=0; C.x2=0;
        C.y1=0; C.y2=0;
    }
}

long long arie (dreptunghi A)
{
    return ((A.x2-A.x1)*(A.y2-A.y1));
}

long long perimetru (dreptunghi A)
{
    return (2*(A.x2-A.x1)+2*(A.y2-A.y1));
}

int main(){
           fin>>d1.x1>>d1.y1>>d1.x2>>d1.y2;
           fin>>d2.x1>>d2.y1>>d2.x2>>d2.y2;
           fin>>d3.x1>>d3.y1>>d3.x2>>d3.y2;
    intersectiee(d1,d2,in1);
    intersectiee(d1,d3,in2);
    intersectiee(d2,d3,in3);
    intersectiee(in1,d3,in4);
    fout<<arie(d1)+arie(d2)+arie(d3)-arie(in1)-arie(in3)-arie(in2)+arie(in4)<<" ";
    fout<<perimetru(d1)+perimetru(d2)+perimetru(d3)-perimetru(in1)-perimetru(in2)-perimetru(in3)+perimetru(in4)<<'\n';;
    return 0;
}
