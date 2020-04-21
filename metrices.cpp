#include"metrices.h"
using namespace std;


void Metrices::set(int r, int c, int value=0)
{
     r--; c--;
    switch(matrix_type)
    {
    case 1:  a[r*5+c] = value;
        break;
    case 2:  if(r==c) a[r] = value;
        break;
    case 3: if(r>=c) a[(r+1)*r/2 + c+1] = value;
        break;
    case 4: if(r<=c) a[r*dim +r*(r-1)/2 +c-r] = value ;
        break;
    case 5: if(r>=c)
            a[(r+1)*r/2 + c] = value;
            else
            a[(c+1)*c/2 + r] = value;
        break;
    case 6: if(r == c-1)
            a[r] = value;
            else if(r == c)
            a[dim+r-1] = value;
            else if(r == c+1)
            a[2*dim+c-1] = value;
        break;
    case 7: if(c>=r)
            a[c-r] = value;
            else
            a[dim -1 + r-c] = value;
        break;
    default:
        cout<<"its default type set";
    }
}
int Metrices::get(int r, int c)
{
    r--; c--;
    switch(matrix_type)
    {
    case 1: return a[r*5 + c];
    case 2: return r==c ? a[r] : 0;
    case 3: return r>=c ? a[(r+1)*r/2 + c+1] : 0;
    case 4: return r<=c ? a[r*dim + (r-1)*r/2 +c-r] : 0;
    case 5: return r>=c ? a[(r+1)*r/2 + c] : a[(c+1)*c/2 + r];
    case 6: if(r == c-1)
            return a[r];
            else if(r == c)
            return a[dim+r-1];
            else if(r == c+1)
            return a[2*dim+c-1];
            return 0;
    case 7: return c>=r ? a[c-r] : a[dim-1 + r-c];
    default:
        cout<<"its default type get";
    }
}
void Metrices::display()
{
    cout<<"display: \n";
    for(int i(1); i<=dim; i++)
    {
        for(int j(1); j<=dim; j++)
            cout<<get(i,j)<<" ";
        cout<<'\n';
    }
}

