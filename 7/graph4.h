//图类结构体定义与相关操作graph4.h
typedef struct
{char *data;
 int *visited;
 float **edge;
 int max,size;
}Graph;
//初始化图
void SetGraph(Graph *G,int n)
{int i,j;
 G->data=new char[n];
 G->visited=new int[n];
 G->edge=(float **)malloc(n*sizeof(float *));
 for(i=0;i<n;i++)
  G->edge[i]=(float *)malloc(n*sizeof(float));
 for(i=0;i<n;i++) G->visited[i]=0;
 for(i=0;i<n;i++)
  for(j=0;j<n;j++) G->edge[i][j]=0;
 G->max=n;
 G->size=0;
}
//构造图
void MakeGraph(Graph *G,RCW r[],int n,int e)
{int m=0;
 while(m<n)
  {if(G->size==G->max)
   {cout<<"Graph is full!\n";
    exit(1);}
   G->data[G->size]='a'+m;
   G->size++;m++;}
  //插入弧
  for(int p=0;p<e;p++)
  {int i,j,k;
   for(k=0;k<n;k++)
    {if(r[p].w1==G->data[k]) i=k;
     if(r[p].w2==G->data[k]) j=k;}
   G->edge[i][j]=r[p].w;}
}





