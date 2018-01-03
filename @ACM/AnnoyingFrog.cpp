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
        qsort(plants, n, sizeof(PLANT), myCompare);//ˮ��������
        for ( i = 0; i < n - 2; i++ )//ö�����������ڵ�
            for ( j = i + 1; j < n - 1; j++ ) {
            dX = plants[j].x - plants[i].x;//�����경��
            dY = plants[j].y - plants[i].y;//�����경��
            pX = plants[i].x - dX;//��һ�����ǰһ��
            pY = plants[i].y - dY;
            if ( pX <= r && pX >= 1 && pY <= c && pY >= 1 )//���ڵ�����
                continue;
            if ( plants[i].x + max * dX > r )//��һ�����������max����ȥ��
                break;
            pY = plants[i].y + max * dY;//��һ���������max������û��ȥ���ж���
            if ( pY > c || pY < 1)//��ȥ��
                continue;
            steps = searchPath( plants[j], dX, dY );//Ѱ��·��
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
    p2 = (PLANT*) ele2;//��ȡָ��
    if ( p1->x == p2->x ) return( p1->y - p2->y );//��ͬ�У���������
    return ( p1->x - p2->x );//����ͬ����������
}
int searchPath( PLANT secPlant, int dX, int dY ){
    PLANT plant;
    int steps;
    plant.x = secPlant.x + dX;//��һ��
    plant.y = secPlant.y + dY;
    steps = 2;//��2����
    while ( plant.x <= r && plant.x >= 1 && plant.y <= c && plant.y >= 1 ) {//���ڵ�����
        if ( !bsearch(&plant, plants, n, sizeof(PLANT), myCompare) ) {//�ǿգ��Ǳ���̤����
        steps = 0;
        break;
        }
        plant.x += dX;//����һ��
        plant.y += dY;
        steps++;
    }
    return( steps );
}
