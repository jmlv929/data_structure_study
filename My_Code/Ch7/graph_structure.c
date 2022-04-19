/*

图的数据结构存储

*/

typedef char VertexType;  // 顶点类型
typedef int EdgeType ;

#define MAXVEX 100
#define INFINITY 65535

//临接矩阵
typedef struct {
    VertexType vexs [MAXVEX]; //顶点表 
    EdgeType edge[MAXVEX] [MAXVEX];
    int numNode, numEdge;
} MGraph;

//邻接表

typedef char VertexType; //顶点类型
typedef int EdgeType; //边上权值的类型

//边
typedef struct EdgeNode {
    int adjvex;
    EdgeType info; //权值信息
    struct EdgeNode *Next;
}EdgeNode;

//顶点表结点
typedef struct 
{
    VertexType data;
    EdgeNode *firstedge;

}VertexNode, AdjList[MAXVEX];

typedef struct 
{
    AdjList adjList;
    int numNodes, numNodes;
    
}Graph;


