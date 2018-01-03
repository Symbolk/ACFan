#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int r, c, n;
struct PLANT {
int x, y;
};
PLANT plants[5001];
PLANT plant;
int myCompare( const void *ele1, const void *ele2 );
int searchPath(PLANT secPlant, int dX, int dY);

int  main( )
{
        int i, j, dX, dY, pX, pY, steps, max = 2;
        scanf("%d%d", &r, &c);
        scanf("%d", &n);
        for ( i = 0; i < n; i++ )
            scanf("%d %d", &plants[i].x, &plants[i].y);
        qsort(plants, n, sizeof(PLANT), myCompare);//水稻点排序
        for ( i = 0; i < n - 2; i++ )//枚举任意两相邻点
            for ( j = i + 1; j < n - 1; j++ ) {
            dX = plants[j].x - plants[i].x;//横坐标步长
            dY = plants[j].y - plants[i].y;//纵坐标步长
            pX = plants[i].x - dX;//第一个点的前一步
            pY = plants[i].y - dY;
            if ( pX <= r && pX >= 1 && pY <= c && pY >= 1 )//还在稻田内
                continue;
            if ( plants[i].x + max * dX > r )//第一个点出发再跳max步出去了
                break;
            pY = plants[i].y + max * dY;//第一个点出发跳max步。行没出去，判断列
            if ( pY > c || pY < 1)//出去了
                continue;
            steps = searchPath( plants[j], dX, dY );//寻找路径
            if ( steps > max )  max = steps;
            }
        if ( max == 2 ) max = 0;
            cout<<max<<endl;
    return 0;
}

int myCompare( const void *ele1, const void *ele2 )
{
    PLANT *p1, *p2;
    p1 = (PLANT*) ele1;
    p2 = (PLANT*) ele2;//获取指针
    if ( p1->x == p2->x ) return( p1->y - p2->y );//若同行，按列升序
    return ( p1->x - p2->x );//若不同，按行升序
}
int searchPath( PLANT secPlant, int dX, int dY ){
    PLANT plant;
    int steps;
    plant.x = secPlant.x + dX;//跳一步
    plant.y = secPlant.y + dY;
    steps = 2;//共2步了
    while ( plant.x <= r && plant.x >= 1 && plant.y <= c && plant.y >= 1 ) {//还在稻田内
        if ( !bsearch(&plant, plants, n, sizeof(PLANT), myCompare) ) {//非空，是被踩踏过的
        steps = 0;
        break;
        }
        plant.x += dX;//再跳一步
        plant.y += dY;
        steps++;
    }
    return( steps );
}
