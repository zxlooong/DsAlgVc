// 变长参数表的应用VLArgument.cpp
#include <iostream.h>
#include <iomanip.h>
#include <stdarg.h>
double average( int, ...);
void main()
{double w=36.5,x=21.5,y=1.9,z=10.1;
 cout<<"VLArgument.cpp运行结果:\n";
 cout<<setiosflags(ios::fixed|ios::showpoint)
     <<setprecision(1)<<"w = "<<w<<"\nx = "<<x
     <<"\ny = "<<y<<"\nz = "<<z<<endl;
 cout<<setprecision(3)<<"The average of w and x is "
     <<average(2,w,x)
     <<"\nThe average of w, x, and y is "
     <<average(3,w,x,y)
     <<"\nThe average of w, x, y, and z is "
     <<average(4,w,x,y,z)<<endl;cin.get();
}
double average(int i, ...)
{double total=0;
 va_list ap;
 va_start( ap, i );
 for(int j=1;j<=i;j++)
  total+=va_arg(ap,double);
 va_end( ap );
 return total/i;}

