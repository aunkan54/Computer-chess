#include<GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include<math.h>
#include <iostream>
#include <random>
#include <ctime>
#include <chrono>
#include<bits/stdc++.h>
#include <thread>
//#include <chrono>
//#include <dos.h> //for delay
#define ll long long int
#include "BmpLoader.h"
#define s_f second.first
#define s_s second.second



#define PI 3.1416

using namespace std;


ll START = 0;
//float zoom=4;
double Txval=0,Tyval=0,Tzval=0;
double windowHeight=700, windowWidth=700;
GLfloat alpha = 0.0, theta = 0.0, axis_x=0.0, axis_y=0.0;
GLboolean bRotate = false, uRotate = false;
float rot_ang=2,rot_ang2=10,eyex=2.5,eyey=3, eyez=10,camx=0,camy=0,camz=0, up_x=0.0, up_y=1.0, up_z=0.0;
GLfloat beta =0.0,alph = 0.0, thet = 0.0, bet =0.0;


ll p_blackx, p_blacky,p_blackx3, p_blacky3,p_blackx4, p_blacky4;
ll black_step=0;
ll blackpiece =0;
ll bxlen, bylen, tempx, tempy;
ll bx[200] = {7,7,5,8,7,8,6,1,2,3,4,5,6,7,8,7,2,1,3,5,6,2,7,8,1,1,2,2,3,3,5,5,7,7,4,4,6,6,8,8,5,8,7,4,6,8,4,2,3,3,5,5,4,4,6,6,7,7,2,2,8,8,1,1,3,5,6,2,7,6,7,8,5,7,3,5,6,7,8,7,4,5,7,5,5};
ll by[200] = {2,1,3,5,6,2,4,1,1,4,5,4,6,6,5,4,3,4,5,6,7,5,4,3,2,7,8,2,2,3,3,4,4,5,6,7,6,5,7,8,8,7,6,6,2,2,3,3,2,1,1,4,4,6,6,4,4,3,3,2,5,2,7,4,5,7,5,8,1,2,3,4,5,6,7,8,3,6,1,2,3,4,5,6,7,3,2,1,4,5,6,8,2,5,2,4,6,7,8,2,1,3,5,6,2,6,3,2,7,8,1,4,5,6,7,6,8,1};


float st_x=20,st_y=10,st_z=5;
ll step=0;
float view=0.0;

///guti_color
float wr=0.2,wg=0.5,wb=.2;
float br=.2,bg=.2,bb=.5;

unsigned int ID[50];
ll grid[10][10];
ll grid2[10][10];
ll white[10][10];
ll black[10][10];
ll pev_x,pev_y;
ll m_x,m_y;
ll blue_x,blue_y;
bool play=true,guti3d=true,stop=false;
ll win=0,tmp_win=0,win_cnt=0;

///mouse position:
pair<ll,ll>mousex[15][15];
pair<ll,ll>mousey[15][15];

pair<ll,ll>mousex2[15][15];
pair<ll,ll>mousey2[15][15];

///Guti
vector<pair<bool,pair<ll,ll> > >S[2];
vector<pair<bool,pair<ll,ll> > >king[2];
vector<pair<bool,pair<ll,ll> > >queen[2];
vector<pair<bool,pair<ll,ll> > >knight[2];
vector<pair<bool,pair<ll,ll> > >bishop[2];
vector<pair<bool,pair<ll,ll> > >rook[2];
vector<bool>S_first[2];

///LookAt parameter
//float xc=35,yc=35,zc=52,xl=35,yl=-4,zl=40; //2d
//float xc=35.5,yc=35,zc=53,xl=35.5,yl=7.2,zl=40; ///3d real one


float xe=35.5,ye=35,ze=53,xc=35.5,yc=7.2,zc=40, xl=0, yl = 1, zl = 0;

///light1 parameter
bool on_light=false, amb=true,diff=true,spec=true;
//GLfloat no_light[5], light_ambient[5],light_diffuse[5],light_specular[5],light_position[5];
GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
GLfloat light_ambient[]  = {0.3, 0.3, 0.3, 1.0};
GLfloat light_diffuse[]  = { .7, .7, .7, 1.0 };
GLfloat light_specular[] = { .7, .7, .7, 1.0 };
GLfloat light_position[] = { 40, 40, 50, 1.0 };
///0.604, 0.804, .196,

///light2 parameter

bool on_light2=false, amb2=true,diff2=true,spec2=true;
GLfloat light_ambient2[]  = {0.3, 0.3, 0.3, 1.0};
GLfloat light_diffuse2[]  = { .7, .7, 0, 1.0 };
GLfloat light_specular2[] = { .7, .7, 0, 1.0 };
GLfloat light_position2[] = { 40, 40,20, 1.0 };
//GLfloat light_position2[] = { 40, 40,-5, 1.0 };

///light3 parameter

float lgx=45.0,lgz=25.0;
bool on_light3=false, amb3=true,diff3=true,spec3=true;
GLfloat light_ambient3[]  = {0.6, 0.6, 0.6, 1.0};
GLfloat light_diffuse3[]  = { 1, 0, 0, 1.0 };
GLfloat light_specular3[] = { 1, 0, 0, 1.0 };
///GLfloat light_position3[] = { lgx, 25, lgz, 1.0 };

///light4 parameter

float lgx2=45.0,lgz2=25.0;
bool on_light4=false, amb4=true,diff4=true,spec4=true;
GLfloat light_ambient4[]  = {0.6, 0.6, 0.6, 1.0};
GLfloat light_diffuse4[]  = { 1, 0, 0, 1.0 };
GLfloat light_specular4[] = { 1, 0, 0, 1.0 };
///GLfloat light_position4[] = { lgx2, 25, lgz2, 1.0 };

static GLfloat v_cube[8][3] =
{
    {0.0, 0.0, 0.0},
    {1.0, 0.0, 0.0},
    {1.0, 1.0, 0.0},
    {0.0, 1.0, 0.0},


    {0.0, 0.0, 1.0},
    {1.0, 0.0, 1.0},
    {1.0, 1.0, 1.0},
    {0.0, 1.0, 1.0},


};

static GLubyte quadIndices[6][4] =
{
    {1,0,3,2}, ///back

    {4,5,6,7}, ///font

    {0,1,5,4}, ///bottom
    {7,6,2,3}, ///top
    {5,1,2,6}, ///right
    {0,4,7,3} ///left
};

void light()
{
    /*GLfloat no_light[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat light_ambient[]  = {0.6, 0.3, 0.3, 1.0};
    GLfloat light_diffuse[]  = { 1, 1, 0, 1.0 };
    GLfloat light_specular[] = { 1, 1, 0, 1.0 };
    GLfloat light_position[] = { 12, 14, 22, 1.0 };*/

    glEnable( GL_LIGHT0);
    glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv( GL_LIGHT0, GL_POSITION, light_position);
}

void light2()
{

    glEnable( GL_LIGHT2);
    glLightfv( GL_LIGHT2, GL_AMBIENT, light_ambient2);
    glLightfv( GL_LIGHT2, GL_DIFFUSE, light_diffuse2);
    glLightfv( GL_LIGHT2, GL_SPECULAR, light_specular2);
    glLightfv( GL_LIGHT2, GL_POSITION, light_position2);

}

void light3()
{
    ll x,z;
    x=king[0][0].s_s;
    z=king[0][0].s_f;
    if(step==1)
    {
        z=(8-z)+1;
        x=(8-x)+1;
    }
    lgx=st_x+((x-1)*5)+2.5;
    lgz=st_z+(z-1)*5+2.5;
    GLfloat light_position3[] = { lgx, 25, lgz, 1.0 };

    glEnable( GL_LIGHT3);
    glLightfv( GL_LIGHT3, GL_AMBIENT, light_ambient3);
    glLightfv( GL_LIGHT3, GL_DIFFUSE, light_diffuse3);
    glLightfv( GL_LIGHT3, GL_SPECULAR, light_specular3);
    glLightfv( GL_LIGHT3, GL_POSITION, light_position3);

    GLfloat spot_direction[] = {0, -10, 0 };
    glLightfv(GL_LIGHT3, GL_SPOT_DIRECTION, spot_direction);

    if(guti3d)
    {
        glLightf( GL_LIGHT3, GL_SPOT_CUTOFF, 18.0);
    }
    else
    {
        glLightf( GL_LIGHT3, GL_SPOT_CUTOFF, 16.0);
    }
}

void light4()
{
    ll x,z;
    x=king[1][0].s_s;
    z=king[1][0].s_f;
    if(step==1)
    {
        z=(8-z)+1;
        x=(8-x)+1;
    }
    lgx2=st_x+((x-1)*5)+2.5;
    lgz2=st_z+(z-1)*5+2.5;
    GLfloat light_position4[] = { lgx2, 25, lgz2, 1.0 };

    glEnable( GL_LIGHT4);
    glLightfv( GL_LIGHT4, GL_AMBIENT, light_ambient4);
    glLightfv( GL_LIGHT4, GL_DIFFUSE, light_diffuse4);
    glLightfv( GL_LIGHT4, GL_SPECULAR, light_specular4);
    glLightfv( GL_LIGHT4, GL_POSITION, light_position4);

    GLfloat spot_direction[] = {0, -10, 0 };
    glLightfv(GL_LIGHT4, GL_SPOT_DIRECTION, spot_direction);
    if(guti3d)
    {
        glLightf( GL_LIGHT4, GL_SPOT_CUTOFF, 18.0);
    }
    else
    {
        glLightf( GL_LIGHT4, GL_SPOT_CUTOFF, 16.0);
    }
}

void material_property(float r,float g,float b)
{
    GLfloat no_mat[] = { 0.0, 0.0, 0.0, 1.0 };
    GLfloat mat_ambient[] = { r, g, b, 1.0 };
    GLfloat mat_diffuse[] = { r, g, b, 1.0 };
    GLfloat mat_specular[] = { .6, .6, .6, 1.0 };
    GLfloat mat_shininess[] = {70};

    glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient);
    glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse);
    glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular);
    glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess);
    //material_property(1,0,0);
}

static void getNormal3p
(GLfloat x1, GLfloat y1,GLfloat z1, GLfloat x2, GLfloat y2,GLfloat z2, GLfloat x3, GLfloat y3,GLfloat z3)
{
    GLfloat Ux, Uy, Uz, Vx, Vy, Vz, Nx, Ny, Nz;

    Ux = x2-x1;
    Uy = y2-y1;
    Uz = z2-z1;

    Vx = x3-x1;
    Vy = y3-y1;
    Vz = z3-z1;

    Nx = Uy*Vz - Uz*Vy;
    Ny = Uz*Vx - Ux*Vz;
    Nz = Ux*Vy - Uy*Vx;

    glNormal3f(Nx,Ny,Nz);
}

void LoadTexture(const char*filename,int idx)
{
    glGenTextures(idx, &ID[idx]);
    glBindTexture(GL_TEXTURE_2D, ID[idx]);
    glPixelStorei(GL_UNPACK_ALIGNMENT, ID[idx]);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    BmpLoader bl(filename);
    gluBuild2DMipmaps(GL_TEXTURE_2D, GL_RGB, bl.iWidth, bl.iHeight, GL_RGB, GL_UNSIGNED_BYTE, bl.textureData );
}


void drawcube()
{
    //material_property(1,0,0);
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {

        getNormal3p(v_cube[quadIndices[i][0]][0], v_cube[quadIndices[i][0]][1], v_cube[quadIndices[i][0]][2],
                    v_cube[quadIndices[i][1]][0], v_cube[quadIndices[i][1]][1], v_cube[quadIndices[i][1]][2],
                    v_cube[quadIndices[i][2]][0], v_cube[quadIndices[i][2]][1], v_cube[quadIndices[i][2]][2]);


        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
        glTexCoord2f(1,1);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
        glTexCoord2f(1,0);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
        glTexCoord2f(0,0);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
        glTexCoord2f(0,1);
    }
    glEnd();
}


void drawcube1()
{
    //material_property(1,0,0);
    glBegin(GL_QUADS);
    for (GLint i = 0; i <6; i++)
    {

        getNormal3p(v_cube[quadIndices[i][0]][0], v_cube[quadIndices[i][0]][1], v_cube[quadIndices[i][0]][2],
                    v_cube[quadIndices[i][1]][0], v_cube[quadIndices[i][1]][1], v_cube[quadIndices[i][1]][2],
                    v_cube[quadIndices[i][2]][0], v_cube[quadIndices[i][2]][1], v_cube[quadIndices[i][2]][2]);


        glVertex3fv(&v_cube[quadIndices[i][0]][0]);
        glTexCoord2f(1,1);
        glVertex3fv(&v_cube[quadIndices[i][1]][0]);
        glTexCoord2f(0,1);
        glVertex3fv(&v_cube[quadIndices[i][2]][0]);
        glTexCoord2f(0,0);
        glVertex3fv(&v_cube[quadIndices[i][3]][0]);
        glTexCoord2f(1,0);
    }
    glEnd();
}

void initialize()
{

    ///Grid
    for(ll i=1; i<=8; i++)
    {
        for(ll j=1; j<=8; j++)
        {
            if((i+j)%2)
            {
                grid[i][j]=1;
            }
            else
            {
                grid[i][j]=0;
            }
        }
    }

    for(ll i=1; i<=8; i++)
    {
        white[7][i]=white[8][i]=1;
        black[1][i]=black[2][i]=1;
    }

    /// pawn
    for(ll i=1; i<=8; i++)
    {
        S[0].push_back({true,{7,i}});
        S[1].push_back({true,{2,i}});
        S_first[0].push_back(true);
        S_first[1].push_back(true);
    }

    ///king
    king[0].push_back({true,{8,5}});
    king[1].push_back({true,{1,5}});

    ///queen
    queen[0].push_back({true,{8,4}});
    queen[1].push_back({true,{1,4}});

    ///rook
    rook[0].push_back({true,{8,1}});
    rook[0].push_back({true,{8,8}});
    rook[1].push_back({true,{1,1}});
    rook[1].push_back({true,{1,8}});

    ///knight
    knight[0].push_back({true,{8,2}});
    knight[0].push_back({true,{8,7}});
    knight[1].push_back({true,{1,2}});
    knight[1].push_back({true,{1,7}});

    ///bishop
    bishop[0].push_back({true,{8,3}});
    bishop[0].push_back({true,{8,6}});
    bishop[1].push_back({true,{1,3}});
    bishop[1].push_back({true,{1,6}});

}

void mouse_position()
{
    ll i,j;

    mousex[1][0].second=207;
    for(i=1; i<=8; i++)
    {
        mousex[1][i].first=mousex[1][i-1].second;
        mousex[1][i].second=mousex[1][i].first+78;
    }

    mousex[2][0].second=193;
    for(i=1; i<=8; i++)
    {
        mousex[2][i].first=mousex[2][i-1].second;
        mousex[2][i].second=mousex[2][i].first+83;
    }

    mousex[3][0].second=177;
    for(i=1; i<=8; i++)
    {
        mousex[3][i].first=mousex[3][i-1].second;
        mousex[3][i].second=mousex[3][i].first+88;
    }

    mousex[4][0].second=161;
    for(i=1; i<=8; i++)
    {
        mousex[4][i].first=mousex[4][i-1].second;
        mousex[4][i].second=mousex[4][i].first+93;
    }

    mousex[5][0].second=139;
    for(i=1; i<=8; i++)
    {
        mousex[5][i].first=mousex[5][i-1].second;
        mousex[5][i].second=mousex[5][i].first+100;
    }

    mousex[6][0].second=115;
    for(i=1; i<=8; i++)
    {
        mousex[6][i].first=mousex[6][i-1].second;
        mousex[6][i].second=mousex[6][i].first+108;
    }

    mousex[7][0].second=87;
    for(i=1; i<=8; i++)
    {
        mousex[7][i].first=mousex[7][i-1].second;
        mousex[7][i].second=mousex[7][i].first+117;
    }

    mousex[8][0].second=55;
    for(i=1; i<=8; i++)
    {
        mousex[8][i].first=mousex[8][i-1].second;
        mousex[8][i].second=mousex[8][i].first+127;
    }



    for(i=1; i<=8; i++)
    {
        mousey[1][i].first=147;
        mousey[1][i].second=176;
    }

    for(i=1; i<=8; i++)
    {
        mousey[2][i].first=176;
        mousey[2][i].second=208;
    }

    for(i=1; i<=8; i++)
    {
        mousey[3][i].first=208;
        mousey[3][i].second=243;
    }

    for(i=1; i<=8; i++)
    {
        mousey[4][i].first=243;
        mousey[4][i].second=286;
    }

    for(i=1; i<=8; i++)
    {
        mousey[5][i].first=286;
        mousey[5][i].second=334;
    }

    for(i=1; i<=8; i++)
    {
        mousey[6][i].first=334;
        mousey[6][i].second=388;
    }

    for(i=1; i<=8; i++)
    {
        mousey[7][i].first=388;
        mousey[7][i].second=453;
    }

    for(i=1; i<=8; i++)
    {
        mousey[8][i].first=453;
        mousey[8][i].second=527;
    }
}

void mouse_position2()
{
    ll i,j;

    mousex2[1][0].second=178;
    for(i=1; i<=8; i++)
    {
        mousex2[1][i].first=mousex2[1][i-1].second;
        mousex2[1][i].second=mousex2[1][i].first+90;
    }

    mousex2[2][0].second=165;
    for(i=1; i<=8; i++)
    {
        mousex2[2][i].first=mousex2[2][i-1].second;
        mousex2[2][i].second=mousex2[2][i].first+95;
    }

    mousex2[3][0].second=152;
    for(i=1; i<=8; i++)
    {
        mousex2[3][i].first=mousex2[3][i-1].second;
        mousex2[3][i].second=mousex2[3][i].first+99;
    }

    mousex2[4][0].second=136;
    for(i=1; i<=8; i++)
    {
        mousex2[4][i].first=mousex2[4][i-1].second;
        mousex2[4][i].second=mousex2[4][i].first+105;
    }

    mousex2[5][0].second=119;
    for(i=1; i<=8; i++)
    {
        mousex2[5][i].first=mousex2[5][i-1].second;
        mousex2[5][i].second=mousex2[5][i].first+110;
    }

    mousex2[6][0].second=101;
    for(i=1; i<=8; i++)
    {
        mousex2[6][i].first=mousex2[6][i-1].second;
        mousex2[6][i].second=mousex2[6][i].first+115;
    }

    mousex2[7][0].second=80;
    for(i=1; i<=8; i++)
    {
        mousex2[7][i].first=mousex2[7][i-1].second;
        mousex2[7][i].second=mousex2[7][i].first+123;
    }

    mousex2[8][0].second=55;
    for(i=1; i<=8; i++)
    {
        mousex2[8][i].first=mousex2[8][i-1].second;
        mousex2[8][i].second=mousex2[8][i].first+132;
    }



    for(i=1; i<=8; i++)
    {
        mousey2[1][i].first=42;
        mousey2[1][i].second=80;
    }

    for(i=1; i<=8; i++)
    {
        mousey2[2][i].first=81;
        mousey2[2][i].second=122;
    }

    for(i=1; i<=8; i++)
    {
        mousey2[3][i].first=123;
        mousey2[3][i].second=168;
    }

    for(i=1; i<=8; i++)
    {
        mousey2[4][i].first=169;
        mousey2[4][i].second=219;
    }

    for(i=1; i<=8; i++)
    {
        mousey2[5][i].first=220;
        mousey2[5][i].second=274;
    }

    for(i=1; i<=8; i++)
    {
        mousey2[6][i].first=275;
        mousey2[6][i].second=337;
    }

    for(i=1; i<=8; i++)
    {
        mousey2[7][i].first=338;
        mousey2[7][i].second=408;
    }

    for(i=1; i<=8; i++)
    {
        mousey2[8][i].first=409;
        mousey2[8][i].second=490;
    }
}

void clear_grid()
{
    ///Grid
    for(ll i=1; i<=8; i++)
    {
        for(ll j=1; j<=8; j++)
        {
            if((i+j)%2)
            {
                grid[i][j]=1;
            }
            else
            {
                grid[i][j]=0;
            }
        }
    }

}

void chess_board()
{
    float w=4;
    float sz=40;
    float szz=sz/2;

    ///back
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,ID[1]);
    glTranslatef(st_x-w,st_y,st_z-w);

    glTranslatef(szz+w,0,szz+w);
    glRotatef(-view,0,1,0);
    glTranslatef(-(szz+w),0,-(szz+w));

    glScalef(sz+w+w,w,w);
    material_property(1,1,1);
    drawcube1();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    ///front
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,ID[1]);
    glTranslatef(st_x-w,st_y,st_z+sz);

    glTranslatef(szz+w,0,-szz);
    glRotatef(-view,0,1,0);
    glTranslatef(-(szz+w),0,szz);

    glScalef(sz+w+w,w,w);
    material_property(1,1,1);
    drawcube1();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    ///left
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,ID[1]);
    glTranslatef(st_x-w,st_y,st_z);

    glTranslatef(szz+w,0,szz);
    glRotatef(-view,0,1,0);
    glTranslatef(-(szz+w),0,-szz);

    glScalef(w,w,sz);
    material_property(1,1,1);
    drawcube();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    ///right
    glPushMatrix();
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D,ID[1]);
    glTranslatef(st_x+sz,st_y,st_z);

    glTranslatef(-szz,0,szz);
    glRotatef(-view,0,1,0);
    glTranslatef(szz,0,-szz);

    glScalef(w,w,sz);
    material_property(1,1,1);
    drawcube();
    glDisable(GL_TEXTURE_2D);
    glPopMatrix();

    ///top

    float x,y=st_y,z=st_z,ww=5.0;
    float xx,yy,zz;

    for(int i=1; i<=8; i++)
    {
        x=st_x;
        for(int j=1; j<=8; j++)
        {
            glPushMatrix();
            glEnable(GL_TEXTURE_2D);
            if(grid[i][j]==3)
            {
                glDisable(GL_TEXTURE_2D);
                material_property(.7,0,0);
            }
            else if(grid2[i][j]==4)
            {
                glDisable(GL_TEXTURE_2D);
                material_property(0,0,.7);
            }
            else if(grid[i][j]==0)
            {
                glBindTexture(GL_TEXTURE_2D,ID[2]);
                material_property(1,1,1);
            }
            else if(grid[i][j]==1)
            {
                glBindTexture(GL_TEXTURE_2D,ID[3]);
                material_property(1,1,1);
            }
            else if(grid[i][j]==2)
            {
                //glDisable(GL_TEXTURE_2D);
                //material_property(0,.6,0);
                if((i+j)%2==0)
                {
                    glBindTexture(GL_TEXTURE_2D,ID[2]);
                    material_property(1,1,1);
                }
                else
                {
                    glBindTexture(GL_TEXTURE_2D,ID[3]);
                    material_property(1,1,1);
                }
            }
            glTranslatef(x,y,z);

            xx=(st_x+szz)-x;
            zz=(st_z+szz)-z;
            glTranslatef(xx,0,zz);
            glRotatef(-view,0,1,0);
            glTranslatef(-xx,0,-zz);

            glScalef(ww,w,ww);
            drawcube();
            glDisable(GL_TEXTURE_2D);
            glPopMatrix();

            if(grid[i][j]==2)
            {
                GLUquadricObj *quad;
                quad = gluNewQuadric();
                //cout<<i<<"  "<<j<<endl;
                glPushMatrix();
                material_property(0,.9,0);
                glTranslatef(x+2.5,y+w+.005,z+2.5);

                xx=(st_x+szz)-(x+2.5);
                zz=(st_z+szz)-(z+2.5);
                glTranslatef(xx,0,zz);
                glRotatef(-view,0,1,0);
                glTranslatef(-xx,0,-zz);

                glRotatef(90,1,0,0);

                //glScalef(0,3,0);
                //drawcube();
                gluDisk(quad,0,1.25,32,32);
                glPopMatrix();
            }

            x+=ww;
        }
        z+=ww;
    }

}

void draw_guti(ll r,ll c,ll t,ll idx)
{
    if(step==1)
    {
        r=(8-r)+1;
        c=(8-c)+1;
    }

    float rr,gg,bb;
    if(t==0)
    {
        rr=.56;
        gg=.73;
        bb=.56;
    }
    else
    {
        rr=gg=bb=.7;
    }

    float x,y,z,w,xx,yy,zz;
    z=st_z+((r-1)*5.0);
    x=st_x+((c-1)*5.0);
    y=st_y+4.0;
    w=.5;
    yy=.4;


    /// back
    glPushMatrix();
    glTranslatef(x+w,y,z+w);
    glScalef(5-(2*w),yy,.1);
    material_property(.184,.31,.31);
    drawcube();
    glPopMatrix();

    /// left
    glPushMatrix();
    glTranslatef(x+w,y,z+w+.1);
    glScalef(.1,yy,5.0-(2*w)-.1);
    material_property(.184,.31,.31);
    drawcube();
    glPopMatrix();

    ///front
    z=st_z+((r)*5.0);
    x=st_x+((c-1)*5.0);
    glPushMatrix();
    glTranslatef(x+w,y,z-w);
    glScalef(5-(2*w),yy,-.1);
    material_property(.184,.31,.31);
    drawcube();
    glPopMatrix();


    /// right
    z=st_z+((r-1)*5.0);
    x=st_x+((c)*5.0);

    glPushMatrix();
    glTranslatef(x-w,y,z+w+.1);
    glScalef(-.1,yy,5.0-(2*w)-.1);
    material_property(.184,.31,.31);
    drawcube();
    glPopMatrix();



    ///top

    if(step==0)
    {
        z=st_z+((r-1)*5.0);
        x=st_x+((c-1)*5.0);

        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glEnable(GL_TEXTURE_GEN_S);
         glEnable(GL_TEXTURE_GEN_T);
        glBindTexture(GL_TEXTURE_2D,ID[idx]);
//        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
//        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTranslatef(x+w,y+yy,z+w);

        glTranslatef((2.5-w),0,(2.5-w));
        glRotatef(-180,0,1,0);
        glTranslatef(-(2.5-w),0,-(2.5-w));

        glScalef(5-(2*w),.001,5-(2*w));
        material_property(rr,gg,bb);
        drawcube();
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
    if(step==1)
    {
        z=st_z+((r-1)*5.0);
        x=st_x+((c-1)*5.0);

        glPushMatrix();
        glEnable(GL_TEXTURE_2D);
        glBindTexture(GL_TEXTURE_2D,ID[idx]);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
        glTranslatef(x+w,y+yy,z+w);

        glTranslatef((2.5-w),0,(2.5-w));
        glRotatef(-180,0,1,0);
        glTranslatef(-(2.5-w),0,-(2.5-w));

        glScalef(5-(2*w),.001,5-(2*w));
        material_property(rr,gg,bb);
        drawcube();
        glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }

}

void draw_pawn(ll r,ll c,ll t)
{
    if(step==1)
    {
        r=(8-r)+1;
        c=(8-c)+1;
    }

    float rr,gg,bb;
    if(t==0)
    {
        rr=.96;
        gg=.87;
        bb=.7;
        /*rr=.82;  gg=.7;  bb=.55;*/

    }
    else
    {
        rr=gg=bb=.45;
        /*rr=.82; gg=.41; bb=.11;*/
    }

    float x,y,z,w,xx,yy,zz;
    z=st_z+((r-1)*5.0)+2.5;
    x=st_x+((c-1)*5.0)+2.5;
    y=st_y+4.0;
    yy=0.0;

    GLUquadricObj *quad;
    quad = gluNewQuadric();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 2, 2, .5, 32, 32);
    glPopMatrix();
    yy+=.5;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,2,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1.6, .9, .8, 32, 32);
    glPopMatrix();
    yy+=.8;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.4,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1.4, 1.4, .15, 32, 32);
    glPopMatrix();
    yy+=.15;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.4,32,32);
    glPopMatrix();


    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, .9, .7, 1.5, 32, 32);
    glPopMatrix();
    yy+=1.5;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.3,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1.3, 1.3, .2, 32, 32);
    glPopMatrix();
    yy+=.2;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.3,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy+.55,z);
    glutSolidSphere(1.1,32,32);
    glPopMatrix();

}

void draw_queen(ll r,ll c,ll t)
{
    if(step==1)
    {
        r=(8-r)+1;
        c=(8-c)+1;
    }

    float rr,gg,bb;
    if(t==0)
    {
        rr=.96;
        gg=.87;
        bb=.7;
        //rr=.73;  gg=.56;  bb=.56;
        //rr=gg=bb=1;
    }
    else
    {
        rr=gg=bb=.45;
        /*rr=.82; gg=.41; bb=.11;*/
    }

    float x,y,z,w,xx,yy,zz;
    z=st_z+((r-1)*5.0)+2.5;
    x=st_x+((c-1)*5.0)+2.5;
    y=st_y+4.0;
    yy=0.0;

    GLUquadricObj *quad;
    quad = gluNewQuadric();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 2, 2, .5, 32, 32);
    glPopMatrix();
    yy+=.5;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,2,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1.5, 1, 3.5, 32, 32);
    glPopMatrix();
    yy+=3.5;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1, 1, 1.2, 32, 32);
    glPopMatrix();
    yy+=1.2;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.3,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1.3, 1.3, .15, 32, 32);
    glPopMatrix();
    yy+=.15;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.3,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, .7, 1.2, 1.5, 32, 32);
    glPopMatrix();
    yy+=1.5;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.2,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1.2, .3, .7, 32, 32);
    glPopMatrix();
    yy+=.7;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy+.15,z);
    glutSolidSphere(.35,32,32);
    glPopMatrix();


}

void draw_king(ll r,ll c,ll t)
{
    if(step==1)
    {
        r=(8-r)+1;
        c=(8-c)+1;
    }

    float rr,gg,bb;
    if(t==0)
    {
        rr=.96;
        gg=.87;
        bb=.7;
        //rr=.73;  gg=.56;  bb=.56;
        //rr=gg=bb=1;
    }
    else
    {
        rr=gg=bb=.45;
        /*rr=.82; gg=.41; bb=.11;*/
    }

    float x,y,z,w,xx,yy,zz;
    z=st_z+((r-1)*5.0)+2.5;
    x=st_x+((c-1)*5.0)+2.5;
    y=st_y+4.0;
    yy=0.0;

    GLUquadricObj *quad;
    quad = gluNewQuadric();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 2, 2, .5, 32, 32);
    glPopMatrix();
    yy+=.5;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,2,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1.5, 1, 3.5, 32, 32);
    glPopMatrix();
    yy+=3.5;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1, 1, 1.2, 32, 32);
    glPopMatrix();
    yy+=1.2;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.3,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1.3, 1.3, .15, 32, 32);
    glPopMatrix();
    yy+=.15;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.3,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, .7, 1.2, 1.5, 32, 32);
    glPopMatrix();
    yy+=1.5;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.2,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, .8, .8, .25, 32, 32);
    glPopMatrix();
    yy+=.25;


    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x-.25,y+yy,z-.25);
    //glRotatef(-90,1,0,0);
    glScalef(.5,1.75,.5);
    drawcube();
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x+.25,y+yy+.625,z-.25);
    //glRotatef(-90,1,0,0);
    glScalef(.75,.5,.5);
    drawcube();
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x-1,y+yy+.625,z-.25);
    //glRotatef(-90,1,0,0);
    glScalef(.75,.5,.5);
    drawcube();
    glPopMatrix();

}

void draw_rook(ll r,ll c,ll t)
{
    if(step==1)
    {
        r=(8-r)+1;
        c=(8-c)+1;
    }

    float rr,gg,bb;
    if(t==0)
    {
        rr=.96;
        gg=.87;
        bb=.7;
        //rr=.73;  gg=.56;  bb=.56;
        //rr=gg=bb=1;
    }
    else
    {
        rr=gg=bb=.45;
        /*rr=.82; gg=.41; bb=.11;*/
    }

    float x,y,z,w,xx,yy,zz;
    z=st_z+((r-1)*5.0)+2.5;
    x=st_x+((c-1)*5.0)+2.5;
    y=st_y+4.0;
    yy=0.0;

    GLUquadricObj *quad;
    quad = gluNewQuadric();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 2, 2, .5, 32, 32);
    glPopMatrix();
    yy+=.5;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,2,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1.7, 1, .8, 32, 32);
    glPopMatrix();
    yy+=.8;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.5,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1.5, 1.5, .15, 32, 32);
    glPopMatrix();
    yy+=.15;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.5,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1, 1, 2.05, 32, 32);
    glPopMatrix();
    yy+=2.05;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1, 1.5, .7, 32, 32);
    glPopMatrix();
    yy+=.7;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.5,32,32);
    glPopMatrix();

    float kon=0.0;

    z=z+1.4;
    x=x-.3;
    for(int i=0; i<10; i++)
    {
        glPushMatrix();
        glTranslatef(x,y+yy,z);
        material_property(rr,gg,bb);

        glTranslatef(.3,0,-1.4);
        glRotatef(kon,0,1,0);
        glTranslatef(-.3,0,1.4);

        glScalef(.6,.6,.1);
        drawcube();
        glPopMatrix();
        kon+=36.0;
    }

}

void draw_bishop(ll r,ll c,ll t)
{
    if(step==1)
    {
        r=(8-r)+1;
        c=(8-c)+1;
    }

    float rr,gg,bb;
    if(t==0)
    {
        rr=.96;
        gg=.87;
        bb=.7;
        //rr=.73;  gg=.56;  bb=.56;
        //rr=gg=bb=1;
    }
    else
    {
        rr=gg=bb=.45;
        /*rr=.82; gg=.41; bb=.11;*/
    }

    float x,y,z,w,xx,yy,zz;
    z=st_z+((r-1)*5.0)+2.5;
    x=st_x+((c-1)*5.0)+2.5;
    y=st_y+4.0;
    yy=0.0;

    GLUquadricObj *quad;
    quad = gluNewQuadric();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1.6, 1.6, .5, 32, 32);
    glPopMatrix();
    yy+=.5;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.6,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1.3, 0.8, .8, 32, 32);
    glPopMatrix();
    yy+=.8;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1.3,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 0.8, 0.8, .15, 32, 32);
    glPopMatrix();
    yy+=.15;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,0.8,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 0.8, 0.6, 2.6, 32, 32);
    glPopMatrix();
    yy+=2.6;


    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, .6, 1, 1, 32, 32);
    glPopMatrix();
    yy+=1;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,1,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1, .3, .7, 32, 32);
    glPopMatrix();
    yy+=.7;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy+.15,z);
    glutSolidSphere(.35,32,32);
    glPopMatrix();



//    glPushMatrix();
//    material_property(rr,gg,bb);
//    glTranslatef(x,y+yy,z);
//    glRotatef(-90,1,0,0);
//    glutSolidCone(1.2, 1.55,32, 32);
//    //gluCylinder(quad, 1.5, .2, 1.5, 32, 32);
//    glPopMatrix();
//    yy+=1.55;
//
//    glPushMatrix();
//    material_property(rr,gg,bb);
//    glTranslatef(x,y+yy+.1,z);
//    glutSolidSphere(.3,32,32);
//    glPopMatrix();

}

void draw_knight(ll r,ll c,ll t)
{
    if(step==1)
    {
        r=(8-r)+1;
        c=(8-c)+1;
    }

    float rr,gg,bb;
    if(t==0)
    {
        rr=.96;
        gg=.87;
        bb=.7;
        //rr=.73;  gg=.56;  bb=.56;
        //rr=gg=bb=1;
    }
    else
    {
        rr=gg=bb=.45;
        /*rr=.82; gg=.41; bb=.11;*/
    }

    float x,y,z,w,xx,yy,zz;
    z=st_z+((r-1)*5.0)+2.5;
    x=st_x+((c-1)*5.0)+2.5;
    y=st_y+4.0;
    yy=0.0;

    GLUquadricObj *quad;
    quad = gluNewQuadric();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 2, 2, .5, 32, 32);
    glPopMatrix();
    yy+=.5;

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(90,1,0,0);
    gluDisk(quad,0,2,32,32);
    glPopMatrix();

    glPushMatrix();
    material_property(rr,gg,bb);
    glTranslatef(x,y+yy,z);
    glRotatef(-90,1,0,0);
    gluCylinder(quad, 1.7, 1, .8, 32, 32);
    glPopMatrix();
    yy+=.8;



    glPushMatrix(); /// below neck
    glTranslatef(x,y+yy-0.4,z);
    glRotatef(90,0,1,0);
    glRotatef(160,1,0,0);
    glRotatef(90,1,0,0);

    gluCylinder(quad, 1, 0.8, 3.8, 20, 1);
    glRotatef(180, 1,0,0);
    gluDisk(quad, 0.0f, 1, 20, 1);
    glRotatef(180, 1,0,0);
    glTranslatef(0.0f, 0.0f, 3.8);
    gluDisk(quad, 0.0f, 0.8, 20, 1);
    glTranslatef(0.0f, 0.0f, -3.8);
    glPopMatrix();
    yy+=3;


    glPushMatrix(); /// neck
    glTranslatef(x-1.2,y+yy+0.1,z);
    glRotatef(90,0,1,0);
    glRotatef(180,1,0,0);
    glRotatef(90,1,0,0);

    gluCylinder(quad, .9, .6, .8, 20, 1);
    glRotatef(180, 1,0,0);
    gluDisk(quad, 0.0f, .9, 20, 1);
    glRotatef(180, 1,0,0);
    glTranslatef(0.0f, 0.0f, .8);
    gluDisk(quad, 0.0f, .6, 20, 1);
    glTranslatef(0.0f, 0.0f, -.8);
    glPopMatrix();


//
//    glPushMatrix();
//    material_property(rr,gg,bb);
//    glTranslatef(x-1.23,y+yy+.3,z);
//    glutSolidSphere(0.9,32,32);
//    glPopMatrix();


    glPushMatrix(); /// mouth
    glTranslatef(x-1,y+yy+0.2,z);
    glRotatef(90,0,1,0);
    glRotatef(-75,1,0,0);
    glRotatef(90,1,0,0);

    gluCylinder(quad, .8, .06, 1.7, 20, 1);
    glRotatef(180, 1,0,0);
    gluDisk(quad, 0.0f, .8, 20, 1);
    glRotatef(180, 1,0,0);
    glTranslatef(0.0f, 0.0f, 1.7);
    gluDisk(quad, 0.0f, .06, 20, 1);
    glTranslatef(0.0f, 0.0f, -1.7);
    glPopMatrix();
    yy+=.8;


    glPushMatrix(); ///
    glTranslatef(x-1.25,y+yy,z);
    glRotatef(90,0,1,0);
    glRotatef(180,1,0,0);
    glRotatef(90,1,0,0);

    gluCylinder(quad, .7, .1, .5, 20, 1);
    glRotatef(180, 1,0,0);
    gluDisk(quad, 0.0f, .7, 20, 1);
    glRotatef(180, 1,0,0);
    glTranslatef(0.0f, 0.0f, .5);
    gluDisk(quad, 0.0f, .1, 20, 1);
    glTranslatef(0.0f, 0.0f, -.5);
    glPopMatrix();



}

void guti()
{
    ///pawn
    ll n=S[0].size();
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<2; j++)
        {
            if(S[j][i].first)
            {
                if(guti3d)
                {
                    draw_pawn(S[j][i].s_f,S[j][i].s_s,j);
                }
                else
                {
                    draw_guti(S[j][i].s_f,S[j][i].s_s,j,7+j);
                }
            }
        }
    }

    ///king
    n=king[0].size();
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<2; j++)
        {
            if(king[j][i].first)
            {
                if(guti3d)
                {
                    draw_king(king[j][i].s_f,king[j][i].s_s,j);
                }
                else
                {
                    draw_guti(king[j][i].s_f,king[j][i].s_s,j,9+j);
                }
            }
        }
    }

    ///Queen
    n=queen[0].size();
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<2; j++)
        {
            if(queen[j][i].first)
            {
                if(guti3d)
                {
                    draw_queen(queen[j][i].s_f,queen[j][i].s_s,j);
                }
                else
                {
                    draw_guti(queen[j][i].s_f,queen[j][i].s_s,j,11+j);
                }

            }
        }
    }

    ///Rook
    n=rook[0].size();
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<2; j++)
        {
            if(rook[j][i].first)
            {
                if(guti3d)
                {
                    draw_rook(rook[j][i].s_f,rook[j][i].s_s,j);
                }
                else
                {
                    draw_guti(rook[j][i].s_f,rook[j][i].s_s,j,13+j);
                }
            }
        }
    }

    ///Knight
    n=knight[0].size();
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<2; j++)
        {
            if(knight[j][i].first)
            {
                if(guti3d)
                {
                    draw_knight(knight[j][i].s_f,knight[j][i].s_s,j);
                }
                else
                {
                    draw_guti(knight[j][i].s_f,knight[j][i].s_s,j,15+j);
                }
            }
        }
    }

    ///Bishop
    n=bishop[0].size();
    for(ll i=0; i<n; i++)
    {
        for(ll j=0; j<2; j++)
        {
            if(bishop[j][i].first)
            {
                if(guti3d)
                {
                    draw_bishop(bishop[j][i].s_f,bishop[j][i].s_s,j);
                }
                else
                {
                    draw_guti(bishop[j][i].s_f,bishop[j][i].s_s,j,17+j);
                }
            }
        }
    }

}


bool pawn_movement(ll x,ll y,ll idx)
{
    if(step==0)
    {
        ll c=0;
        if(!white[x-1][y] && !black[x-1][y])
        {
            c++;
            grid[x-1][y]=2;
//            p_blackx = x-1;
//            p_blacky = y;
//            printf("p1 %llu, %llu\n",p_blackx,p_blacky);
        }
        if(S_first[0][idx])
        {
            if(!white[x-2][y] && !black[x-2][y])
            {
                c++;
                grid[x-2][y]=2;
//                p_blackx = x-2;
//                p_blacky = y;
//                printf("p2 %llu, %llu\n",p_blackx,p_blacky);
            }
        }
        if(black[x-1][y-1])
        {
            c++;
            grid[x-1][y-1]=3;
//            p_blackx = x-1;
//            p_blacky = y-1;
//            printf("p3 %llu, %llu\n",p_blackx,p_blacky);
        }
        if(black[x-1][y+1])
        {
            c++;
            grid[x-1][y+1]=3;
//            p_blackx = x-1;
//            p_blacky = y+1;
//            printf("p4 %llu, %llu\n",p_blackx,p_blacky);

        }
        if(c>0)
        {
            return true;
        }
        return false;

    }
    else
    {
        ll c=0;
        if(!white[x+1][y] && !black[x+1][y])
        {
            c++;
            grid[x+1][y]=2;
            p_blackx = x+1;
            p_blacky = y;
            //printf("p1 %llu, %llu\n",p_blackx,p_blacky);
        }
        if(S_first[1][idx])
        {
            if(!white[x+2][y] && !black[x+2][y])
            {
                c++;
                grid[x+2][y]=2;
                p_blackx = x+2;
                p_blacky = y;
                //printf("p2 %llu, %llu\n",p_blackx,p_blacky);
            }
        }
        if(white[x+1][y-1])
        {
            c++;
            grid[x+1][y-1]=3;
            p_blackx = x+1;
            p_blacky = y-1;
            //printf("p3 %llu, %llu\n",p_blackx3,p_blacky3);
        }
        if(white[x+1][y+1])
        {
            c++;
            grid[x+1][y+1]=3;
            p_blackx = x+1;
            p_blacky = y+1;
            //printf("p4 %llu, %llu\n",p_blackx4,p_blacky4);

        }
        if(c>0)
        {
            blackpiece = 1;
            return true;
        }
        return false;
    }
}


bool knight_movement(ll x,ll y)
{
    ll a,b,c;
    c=0;
    ll xx[]= {2,2,-2,-2,1,-1,1,-1};
    ll yy[]= {1,-1,1,-1,2,2,-2,-2};
    if(step==0)
    {
        for(ll i=0; i<8; i++)
        {
            a=x+xx[i];
            b=y+yy[i];
            if((a>=1 && a<=8) && (b>=1 && b<=8))
            {
                if(white[a][b])
                {
                    continue;
                }
                else if(black[a][b])
                {
                    grid[a][b]=3;
                    c++;
                }
                else
                {
                    grid[a][b]=2;
                    c++;
                }
            }
        }
    }
    else
    {
        //cout<<x<<"  "<<y<<endl;
        for(ll i=0; i<8; i++)
        {
            a=x+xx[i];
            b=y+yy[i];
            if((a>=1 && a<=8) && (b>=1 && b<=8))
            {
                if(black[a][b])
                {
                    continue;
                }
                else if(white[a][b])
                {
                    grid[a][b]=3;
                    p_blackx = a;
                    p_blacky = b;
                    //printf("p3 %llu, %llu\n",p_blackx3,p_blacky3);
                    //cout<<"red: "<<a<<" "<<b<<endl;
                    c++;
                }
                else
                {
                    grid[a][b]=2;
                    p_blackx = a;
                    p_blacky = b;
                    //printf("p %llu, %llu\n",p_blackx,p_blacky);
                    //cout<<"green: "<<a<<" "<<b<<endl;
                    c++;
                }
            }
        }
    }

    if(c>0)
    {
        blackpiece = 3;
        return true;
    }
    return false;
}

bool bishop_movement(ll x,ll y)
{
    ll a,b,c=0;
    ll dx[]= {1,1,-1,-1};
    ll dy[]= {1,-1,1,-1};
    if(step==0)
    {
        for(ll i=0; i<4; i++)
        {
            a=x+dx[i];
            b=y+dy[i];
            while((a>=1 && a<=8) && (b>=1 && b<=8))
            {
                if(white[a][b])
                {
                    break;
                }
                else if(black[a][b])
                {
                    grid[a][b]=3;
                    c++;
                    break;
                }
                else
                {
                    grid[a][b]=2;
                    c++;
                }
                a+=dx[i];
                b+=dy[i];
            }
        }
    }
    else
    {
        for(ll i=0; i<4; i++)
        {
            a=x+dx[i];
            b=y+dy[i];
            while((a>=1 && a<=8) && (b>=1 && b<=8))
            {
                if(black[a][b])
                {
                    break;
                }
                else if(white[a][b])
                {
                    grid[a][b]=3;
                    c++;
                    p_blackx = a;
                    p_blacky = b;
                    //printf("p3 %llu, %llu\n",p_blackx3,p_blacky3);
                    break;
                }
                else
                {
                    grid[a][b]=2;
                    c++;
                    p_blackx = a;
                    p_blacky = b;
                    //printf("p %llu, %llu\n",p_blackx,p_blacky);
                }
                a+=dx[i];
                b+=dy[i];
            }
        }
    }

    if(c>0)
    {
        blackpiece = 4;
        return true;
    }
    false;
}

bool rook_movement(ll x,ll y)
{
    ll a,b,c=0;
    ll dx[]= {1,-1,0,0};
    ll dy[]= {0,0,1,-1};
    if(step==0)
    {
        for(ll i=0; i<4; i++)
        {
            a=x+dx[i];
            b=y+dy[i];
            while((a>=1 && a<=8) && (b>=1 && b<=8))
            {
                if(white[a][b])
                {
                    break;
                }
                else if(black[a][b])
                {
                    grid[a][b]=3;
                    c++;
                    break;
                }
                else
                {
                    grid[a][b]=2;
                    c++;
                }
                a+=dx[i];
                b+=dy[i];
            }
        }
    }
    else
    {
        for(ll i=0; i<4; i++)
        {
            a=x+dx[i];
            b=y+dy[i];
            while((a>=1 && a<=8) && (b>=1 && b<=8))
            {
                if(black[a][b])
                {
                    break;
                }
                else if(white[a][b])
                {
                    grid[a][b]=3;
                    c++;
                    p_blackx = a;
                    p_blacky = b;
                    //printf("p3 %llu, %llu\n",p_blackx3,p_blacky3);
                    break;
                }
                else
                {
                    grid[a][b]=2;
                    p_blackx = a;
                    p_blacky = b;
                    //printf("p %llu, %llu\n",p_blackx,p_blacky);
                    c++;
                }
                a+=dx[i];
                b+=dy[i];
            }
        }
    }

    if(c>0)
    {
        blackpiece = 2;
        return true;
    }
    false;
}

bool king_movement(ll x,ll y)
{
    ll a,b,c=0;
    ll dx[]= {1,-1,0,0,1,1,-1,-1};
    ll dy[]= {0,0,1,-1,1,-1,1,-1};
    if(step==0)
    {
        for(ll i=0; i<8; i++)
        {
            a=x+dx[i];
            b=y+dy[i];
            if((a>=1 && a<=8) && (b>=1 && b<=8))
            {
                if(white[a][b])
                {
                    continue;
                }
                else if(black[a][b])
                {
                    grid[a][b]=3;
                    c++;
                }
                else
                {
                    grid[a][b]=2;
                    c++;
                }
            }
        }
    }
    else
    {
        for(ll i=0; i<8; i++)
        {
            a=x+dx[i];
            b=y+dy[i];
            if((a>=1 && a<=8) && (b>=1 && b<=8))
            {
                if(black[a][b])
                {
                    continue;
                }
                else if(white[a][b])
                {
                    grid[a][b]=3;
                    c++;
                    p_blackx = a;
                    p_blacky = b;
                    //printf("p3 %llu, %llu\n",p_blackx3,p_blacky3);
                }
                else
                {
                    grid[a][b]=2;
                    c++;
                    p_blackx = a;
                    p_blacky = b;
                    //printf("p3 %llu, %llu\n",p_blackx3,p_blacky3);
                }
            }
        }
    }
    if(c>0)
    {
        blackpiece = 5;
        return true;
    }
    return false;

}

bool queen_movement(ll x,ll y)
{
    ll a,b,c=0;
    ll dx[]= {1,-1,0,0,1,1,-1,-1};
    ll dy[]= {0,0,1,-1,1,-1,1,-1};
    if(step==0)
    {
        for(ll i=0; i<8; i++)
        {
            a=x+dx[i];
            b=y+dy[i];
            while((a>=1 && a<=8) && (b>=1 && b<=8))
            {
                if(white[a][b])
                {
                    break;
                }
                else if(black[a][b])
                {
                    grid[a][b]=3;
                    c++;
                    break;
                }
                else if(king[1][0].s_f==a && king[1][0].s_s==b){
                    grid[a][b]=5;
                    c++;
                    break;
                }
                else
                {
                    grid[a][b]=2;
                    c++;
                }
                a+=dx[i];
                b+=dy[i];
            }
        }
    }
    else
    {
        for(ll i=0; i<8; i++)
        {
            a=x+dx[i];
            b=y+dy[i];
            while((a>=1 && a<=8) && (b>=1 && b<=8))
            {
                if(black[a][b])
                {
                    break;
                }
                else if(white[a][b])
                {
                    grid[a][b]=3;
                    c++;
                    p_blackx = a;
                    p_blacky = b;
                    //printf("p3 %llu, %llu\n",p_blackx3,p_blacky3);
                    break;
                }
                else if(king[1][0].s_f==a && king[1][0].s_s==b){
                    grid[a][b]=5;
                    p_blackx = a;
                    p_blacky = b;
                    c++;
                    break;
                }
                else
                {
                    grid[a][b]=2;
                    c++;
                    p_blackx = a;
                    p_blacky = b;
                    //printf("p3 %llu, %llu\n",p_blackx3,p_blacky3);
                }
                a+=dx[i];
                b+=dy[i];
            }
        }
    }

    if(c>0)
    {
        blackpiece = 6;
        return true;
    }
    false;
}

void move_white(ll x,ll y,ll r,ll c)
{
    white[x][y]=false;
    white[r][c]=true;

    ///pawn
    ll n=S[0].size();
    for(ll i=0; i<n; i++)
    {
        if(S[0][i].s_f==x && S[0][i].s_s==y)
        {
            if(r==1)
            {
                S[0][i].first=false;
                queen[0].push_back({true,{r,c}});
            }
            else
            {
                S[0][i].s_f=r;
                S[0][i].s_s=c;
            }
            S_first[0][i]=false;
            return;
        }
    }

    ///king
    n=king[0].size();
    for(ll i=0; i<n; i++)
    {
        if(king[0][i].s_f==x && king[0][i].s_s==y)
        {
            king[0][i].s_f=r;
            king[0][i].s_s=c;
            return;
        }
    }

    ///Queen
    n=queen[0].size();
    for(ll i=0; i<n; i++)
    {
        if(queen[0][i].s_f==x && queen[0][i].s_s==y)
        {
            queen[0][i].s_f=r;
            queen[0][i].s_s=c;
            return;
        }
    }

    ///Rook
    n=rook[0].size();
    for(ll i=0; i<n; i++)
    {
        if(rook[0][i].s_f==x && rook[0][i].s_s==y)
        {
            rook[0][i].s_f=r;
            rook[0][i].s_s=c;
            return;
        }
    }

    ///Knight
    n=knight[0].size();
    for(ll i=0; i<n; i++)
    {
        if(knight[0][i].s_f==x && knight[0][i].s_s==y)
        {
            knight[0][i].s_f=r;
            knight[0][i].s_s=c;
            return;
        }
    }

    ///Bishop
    n=bishop[0].size();
    for(ll i=0; i<n; i++)
    {
        if(bishop[0][i].s_f==x && bishop[0][i].s_s==y)
        {
            bishop[0][i].s_f=r;
            bishop[0][i].s_s=c;
            return;
        }
    }

}


void remove_white(ll x,ll y)
{
    white[x][y]=false;

    ///pawn
    ll n=S[0].size();
    for(ll i=0; i<n; i++)
    {
        if(S[0][i].s_f==x && S[0][i].s_s==y)
        {
            S[0][i].first=false;
            return;
        }
    }

    ///king
    n=king[0].size();
    for(ll i=0; i<n; i++)
    {
        if(king[0][i].s_f==x && king[0][i].s_s==y)
        {
            king[0][i].first=false;
            tmp_win=1;
            return;
        }
    }

    ///Queen
    n=queen[0].size();
    for(ll i=0; i<n; i++)
    {
        if(queen[0][i].s_f==x && queen[0][i].s_s==y)
        {
            queen[0][i].first=false;
            return;
        }
    }

    ///Rook
    n=rook[0].size();
    for(ll i=0; i<n; i++)
    {
        if(rook[0][i].s_f==x && rook[0][i].s_s==y)
        {
            rook[0][i].first=false;
            return;
        }
    }

    ///Knight
    n=knight[0].size();
    for(ll i=0; i<n; i++)
    {
        if(knight[0][i].s_f==x && knight[0][i].s_s==y)
        {
            knight[0][i].first=false;
            return;
        }
    }

    ///Bishop
    n=bishop[0].size();
    for(ll i=0; i<n; i++)
    {
        if(bishop[0][i].s_f==x && bishop[0][i].s_s==y)
        {
            bishop[0][i].first=false;
            return;
        }
    }

}

void move_black(ll x,ll y,ll r,ll c)
{
    black[x][y]=false;
    black[r][c]=true;

    ///pawn
    ll n=S[1].size();
    for(ll i=0; i<n; i++)
    {
        if(S[1][i].s_f==x && S[1][i].s_s==y)
        {
            if(r==8)
            {
                S[1][i].first=false;
                queen[1].push_back({true,{r,c}});
            }
            else
            {
                S[1][i].s_f=r;
                S[1][i].s_s=c;
            }
            S_first[1][i]=false;
            return;
        }
    }

    ///king
    n=king[1].size();
    for(ll i=0; i<n; i++)
    {
        if(king[1][i].s_f==x && king[1][i].s_s==y)
        {
            king[1][i].s_f=r;
            king[1][i].s_s=c;
            return;
        }
    }

    ///Queen
    n=queen[1].size();
    for(ll i=0; i<n; i++)
    {
        if(queen[1][i].s_f==x && queen[1][i].s_s==y)
        {
            queen[1][i].s_f=r;
            queen[1][i].s_s=c;
            return;
        }
    }

    ///Rook
    n=rook[1].size();
    for(ll i=0; i<n; i++)
    {
        if(rook[1][i].s_f==x && rook[1][i].s_s==y)
        {
            rook[1][i].s_f=r;
            rook[1][i].s_s=c;
            return;
        }
    }

    ///Knight
    n=knight[1].size();
    for(ll i=0; i<n; i++)
    {
        if(knight[1][i].s_f==x && knight[1][i].s_s==y)
        {
            knight[1][i].s_f=r;
            knight[1][i].s_s=c;
            return;
        }
    }

    ///Bishop
    n=bishop[1].size();
    for(ll i=0; i<n; i++)
    {
        if(bishop[1][i].s_f==x && bishop[1][i].s_s==y)
        {
            bishop[1][i].s_f=r;
            bishop[1][i].s_s=c;
            return;
        }
    }

}


void remove_black(ll x,ll y)
{
    black[x][y]=false;

    ///pawn
    ll n=S[1].size();
    for(ll i=0; i<n; i++)
    {
        if(S[1][i].s_f==x && S[1][i].s_s==y)
        {
            S[1][i].first=false;
            return;
        }
    }

    ///king
    n=king[1].size();
    for(ll i=0; i<n; i++)
    {
        if(king[1][i].s_f==x && king[1][i].s_s==y)
        {
            king[1][i].first=false;
            tmp_win=2;
            return;
        }
    }

    ///Queen
    n=queen[1].size();
    for(ll i=0; i<n; i++)
    {
        if(queen[1][i].s_f==x && queen[1][i].s_s==y)
        {
            queen[1][i].first=false;
            return;
        }
    }

    ///Rook
    n=rook[1].size();
    for(ll i=0; i<n; i++)
    {
        if(rook[1][i].s_f==x && rook[1][i].s_s==y)
        {
            rook[1][i].first=false;
            return;
        }
    }

    ///Knight
    n=knight[1].size();
    for(ll i=0; i<n; i++)
    {
        if(knight[1][i].s_f==x && knight[1][i].s_s==y)
        {
            knight[1][i].first=false;
            return;
        }
    }

    ///Bishop
    n=bishop[1].size();
    for(ll i=0; i<n; i++)
    {
        if(bishop[1][i].s_f==x && bishop[1][i].s_s==y)
        {
            bishop[1][i].first=false;
            return;
        }
    }

}

void cell_pos(ll x,ll y)
{
    ll i,j,c=0;
    m_x=m_y=-1;
    for(i=1; i<=8; i++)
    {
        for(j=1; j<=8; j++)
        {
            if((mousex[i][j].first<=x && x<=mousex[i][j].second) && (mousey[i][j].first<=y && y<=mousey[i][j].second))
            {
                m_x=i;
                m_y=j;

//                if(step==0){
//                    m_x=i;
//                    m_y=j;
//                } else if(step==1) {
//                    while(black[m_x][m_y]==0) {
//                        m_x = rand() % 8 + 1;
//                        m_y = rand() % 8 + 1;
//
//                     }
//                }
                //grid[i][j]=2;
                c=1;
                break;
            }
        }
        if(c==1)
        {
            break;
        }
    }
}


void select_pos(ll x,ll y,ll r,ll c)
{

    play=false;
    grid2[blue_x][blue_y]=0;
    grid2[r][c]=4;
    blue_x=r;
    blue_y=c;

    if(step==0)
    {
        if(grid[r][c]==2)
        {
            move_white(x,y,r,c);
        }
        else if(grid[r][c]==3)
        {
            remove_black(r,c);
            move_white(x,y,r,c);
        }
    }
    else
    {
        if(grid[r][c]==2)
        {
            move_black(x,y,r,c);
            printf("move successful\n");
        }
        else if(grid[r][c]==3)
        {
            remove_white(r,c);
            move_black(x,y,r,c);
            printf("remove successful\n");
        }
    }
    win=tmp_win;
}

bool check_guti(ll r,ll c)
{
    if(step==0)
    {
        ll x,y;
        x=(8-r)+1;
        y=c;

        ///pawn
        ll n=S[0].size();
        for(ll i=0; i<n; i++)
        {
            if(S[0][i].second.first==x && S[0][i].second.second==y && S[0][i].first==true)
            {
                if(pawn_movement(x,y,i))
                {
                    pev_x=x;
                    pev_y=y;
                    return true;
                }
                return false;
            }
        }

        ///Knight
        n=knight[0].size();
        for(ll i=0; i<n; i++)
        {
            if(knight[0][i].second.first==x && knight[0][i].second.second==y && knight[0][i].first==true)
            {
                if(knight_movement(x,y))
                {
                    pev_x=x;
                    pev_y=y;
                    return true;
                }
                return false;
            }
        }

        ///bishop
        n=bishop[0].size();
        for(ll i=0; i<n; i++)
        {
            if(bishop[0][i].second.first==x && bishop[0][i].second.second==y && bishop[0][i].first==true)
            {
                if(bishop_movement(x,y))
                {
                    pev_x=x;
                    pev_y=y;
                    return true;
                }
                return false;
            }
        }

        ///rook
        n=rook[0].size();
        for(ll i=0; i<n; i++)
        {
            if(rook[0][i].second.first==x && rook[0][i].second.second==y && rook[0][i].first==true)
            {
                if(rook_movement(x,y))
                {
                    pev_x=x;
                    pev_y=y;
                    return true;
                }
                return false;
            }
        }

        ///king
        n=king[0].size();
        for(ll i=0; i<n; i++)
        {
            if(king[0][i].second.first==x && king[0][i].second.second==y && king[0][i].first==true)
            {
                if(king_movement(x,y))
                {
                    pev_x=x;
                    pev_y=y;
                    return true;
                }
                return false;
            }
        }

        ///Queen
        n=queen[0].size();
        for(ll i=0; i<n; i++)
        {
            if(queen[0][i].second.first==x && queen[0][i].second.second==y && queen[0][i].first==true)
            {
                if(queen_movement(x,y))
                {
                    pev_x=x;
                    pev_y=y;
                    return true;
                }
                return false;
            }
        }

        return false;
    }
    else
    {
        ll x,y;
        x=r;
        y=(8-c)+1;

        ///pawn
        ll n=S[1].size();
        for(ll i=0; i<n; i++)
        {
            if(S[1][i].second.first==x && S[1][i].second.second==y && S[1][i].first==true)
            {
                if(pawn_movement(x,y,i))
                {
                    pev_x=x;
                    pev_y=y;
                    printf("pev %llu, %llu\n",pev_x,pev_y);
                    return true;
                }
                return false;
            }
        }

        ///Knight
        n=knight[1].size();
        for(ll i=0; i<n; i++)
        {
            if(knight[1][i].second.first==x && knight[1][i].second.second==y && knight[1][i].first==true)
            {
                if(knight_movement(x,y))
                {
                    pev_x=x;
                    pev_y=y;
                    return true;
                }
                return false;
            }
        }

        ///bishop
        n=bishop[1].size();
        for(ll i=0; i<n; i++)
        {
            if(bishop[1][i].second.first==x && bishop[1][i].second.second==y && bishop[1][i].first==true)
            {
                if(bishop_movement(x,y))
                {
                    pev_x=x;
                    pev_y=y;
                    return true;
                }
                return false;
            }
        }

        ///rook
        n=rook[1].size();
        for(ll i=0; i<n; i++)
        {
            if(rook[1][i].second.first==x && rook[1][i].second.second==y && rook[1][i].first==true)
            {
                if(rook_movement(x,y))
                {
                    pev_x=x;
                    pev_y=y;
                    return true;
                }
                return false;
            }
        }

        ///king
        n=king[1].size();
        for(ll i=0; i<n; i++)
        {
            if(king[1][i].second.first==x && king[1][i].second.second==y && king[1][i].first==true)
            {
                if(king_movement(x,y))
                {
                    pev_x=x;
                    pev_y=y;
                    return true;
                }
                return false;
            }
        }

        ///Queen
        n=queen[1].size();
        for(ll i=0; i<n; i++)
        {
            if(queen[1][i].second.first==x && queen[1][i].second.second==y && queen[1][i].first==true)
            {
                if(queen_movement(x,y))
                {
                    pev_x=x;
                    pev_y=y;
                    return true;
                }
                return false;
            }
        }

        return false;
    }
}


void input(ll x,ll y)
{

    cell_pos(x,y);


    printf("actual %llu, %llu\n",m_x,m_y);
    if(step==1) {

        if(black_step==0) {
//            std::random_device rd;
//            std::uniform_int_distribution<int> dist(4,8);

//            m_x = dist(rd) -1;
//            m_y = dist(rd) - 1;

////            srand(time(NULL));
////            m_x = rand()% 8;
////            m_y = rand()% 8;

            srand(time(0));
            int temp1 = tempx + ((rand()%8));
            int temp2 = tempy + ((rand()%8));

            printf(" temp %llu, %llu\n",temp1, temp2);
            printf(" bx %llu, %llu\n",bx[temp1], bx[temp2]);
            //printf(" condition %d", black[8-bx[temp1]+1][by[temp2]]);

            //printf("printf if true : %s\n", black[8-bx[temp1]+1][by[temp2]] ? "true" : "false");



            int tr =0;
            int rc = 8-bx[temp1]+1, cr = temp2;

            //printf("printf check guti : %s\n", check_guti(rc,cr) ? "true" : "false");



            while ((black[rc][cr]==false)) {
                temp1 = tempx + ((rand()%8));
                temp2 = tempy + ((rand()%8));
                rc = 8-bx[temp1]+1;
                cr = temp2;
                printf(" temp %llu, %llu\n",temp1, temp2);
                printf("printf if true : %s\n", black[8-bx[temp1]+1][by[temp2]] ? "true" : "false");
                printf(" bx %llu, %llu\n",bx[temp1], bx[temp2]);

            }
            m_x = bx[temp1];
            m_y = by[temp2];
            printf(" tr %d black step %llu : %llu, %llu\n",tr,black_step,m_x,m_y);
            black_step = 1;

        }



        else if(black_step==1) {

                m_x = 8 - p_blackx + 1;
                m_y = 8 - p_blacky + 1;

                printf(" black step %llu : %llu, %llu\n",black_step,m_x,m_y);
                black_step = 0;

        }


    }



    if(m_x==-1 || m_y==-1)
    {
        return;
    }
    ll r,c,rr,cc;
    r=(8-m_x)+1;
    c=m_y;
    if(step==0)
    {
        rr=(8-r)+1;
        cc=c;
        if(grid[rr][cc]==2 || grid[rr][cc]==3)
        {
            //printf("inside %llu, %llu\n",m_x,m_y);
            select_pos(pev_x,pev_y,rr,cc);
            tempx = rr;
            tempy = cc;
            //printf("tempx,tempy : %llu, %llu\n",tempx, tempy);
            clear_grid();
        }
        else
        {
            clear_grid();
            check_guti(r,c);
            //printf("in in side %llu, %llu\n",m_x,m_y);
        }
    }
    else
    {
        rr=r;
        cc=(8-c)+1;
        if(grid[rr][cc]==2 || grid[rr][cc]==3)
        {
            select_pos(pev_x,pev_y,rr,cc);
            printf("select pos rr, cc : %llu, %llu\n",rr,cc);
            clear_grid();
        }
        else
        {
            clear_grid();
            printf("in in side %llu, %llu\n",r,c);
            check_guti(r,c);
            printf("check guti r,c : %llu, %llu\n",r,c);
        }
    }

}

void output(char *str)
{
    glPushMatrix();
    material_property(0.51,   0.51,   0.01);
    glPopMatrix();
    if(guti3d)
    {
        glRasterPos3f(35, 31, 40);
    }

    int len = strlen(str);

    for(int i = 0; i < len; i++)
    {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, str[i]);
    }
    //GLUT_BITMAP_TIMES_ROMAN_24
    //GLUT_BITMAP_HELVETICA_12
}

void winner()
{
    if(win==1)
    {
        output("Black Player Wins!!!");
    }
    else
    {
        output("White Payer Wins!!!");
    }
}

void finish_game()
{
    if(guti3d)
    {
        if(win_cnt>25)
        {
            stop=true;
            winner();
            if(win_cnt>25 && win_cnt<=250)
            {
                ze+=0.14;
            }
        }
    }

}

void find_lookat()
{
    if(guti3d)
    {
        xe=35.5,ye=35,ze=53,xc=35.5,yc=7.2,zc=40;
    }
    else
    {
        xe=35,ye=35,ze=52,xc=35,yc=-4,zc=40;
    }
}





void Pitch(bool clock = true) {
    // Translate to origin
    if(clock)bet+=5;
    else bet-=5;
    //if(beta>270)beta = 270;
    //if(beta<-270)beta = -270;

    GLfloat dx = 0;//look_x - eye_x;
    GLfloat dy = 0;//look_y - eye_y;
    GLfloat dz = -ze;
    //GLfloat dz = 0;

    GLfloat new_x = dx;
    GLfloat new_y = dy*cos(bet*PI/180.0)-dz*sin(bet*PI/180.0);
    GLfloat new_z = dy*sin(bet*PI/180.0) +dz*cos(bet*PI/180.0);

    xc = new_x;
    yc = new_y;
    zc = new_z;


    zl = sin(PI*bet/180.0);
    yl = cos(PI*bet/180);

}

void Roll(bool clock = true) {
    if(clock)alph+=5;
    else alph-=5;
    xl = -sin(PI*alph/180.0);
    yl = cos(PI*alph/180);
}
void Yaw(bool clock = true)
{
    if(clock) thet+=5;
    else thet-=5;
    GLfloat dx = 0;     //look_x - eye_x;
    GLfloat dy = 0;     //look_y - eye_y;
    GLfloat dz = -ze;
    //GLfloat dz = 0;

    GLfloat new_x = dx*cos(thet*PI/180.0)+dz*sin(thet*PI/180.0);
    GLfloat new_y = dy;
    GLfloat new_z = -dx*sin(thet*PI/180.0) +dz*cos(thet*PI/180.0);

    xc = new_x;
    yc = new_y;
    zc = new_z;
}




void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity();
    glFrustum(-3,5,-2,5, 4, 500);
    //gluPerspective(60,1,5,100);
    //glOrtho(-5,5,-5,5, 4, 50);

    glMatrixMode( GL_MODELVIEW );
    glLoadIdentity();

    gluLookAt(xe,ye,ze, xc,yc,zc, xl,yl,zl);

    glViewport(0, 0, 1200, 700);
    //glScalef(0.2,0.2,0.2);

//    chess_board();
//    guti();
//
//    finish_game();







    if(START== 0)
    {

        glPushMatrix();

            glPushMatrix();
            glTranslatef(0.5,0,0);
            output("Press G to Start");
            glPopMatrix();

            glPushMatrix();
            glTranslatef(0.8,-2,0);
            output("Submitted by :");
            glPopMatrix();


            glPushMatrix();
            glTranslatef(-0.4,-3,0);
            output("Charles Aunkan Gomes");
            glPopMatrix();


            glPushMatrix();
            glTranslatef(0.5,-4,0);
            output("Roll : 1707054");
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-0.35,-5,0);
            output("Dept. of CSE, KUET");
            glPopMatrix();


            glPushMatrix();
            glTranslatef(0.8,-9,0);
            output("Submitted by :");
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-10,-14,0);
            output("Dr. Sk. Md. Masudul Ahsan");
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-8,-18,0);
            output("Professor");
            glPopMatrix();

            glPushMatrix();
            glTranslatef(-12,-23,0);
            output("Dept. of CSE, KUET");
            glPopMatrix();



            glPushMatrix();
            glTranslatef(8,-14,0);
            output("S. M. Taslim Uddin Raju");
            glPopMatrix();

            glPushMatrix();
            glTranslatef(12.5,-18,0);
            output("Lecturer");
            glPopMatrix();

            glPushMatrix();
            glTranslatef(11.5,-23,0);
            output("Dept. of CSE, KUET");
            glPopMatrix();

            glPushMatrix();
            glTranslatef(5,-2,0);
            draw_king(0,0,0);
            glPopMatrix();


            glPushMatrix();
            glTranslatef(40,-2,0);
            draw_queen(0,0,0);
            glPopMatrix();

        glPopMatrix();


        //drawStrokeText2("Plane Game",-2,0,0);
    }
    else if (START==1){
        glPushMatrix();
        chess_board();
        guti();

        finish_game();

        glPopMatrix();
    }
//    if(START==1){
//
//        glPushMatrix();
//            glTranslated(0,3,0);
//            //glRotated(0,0,1,0);
//            glScaled(1.5,1.5,1.5);
//            //plane();
//            //car();
//        glPopMatrix();
//
//        output("Press G to Start");
//        glTranslatef(0,10,0);
//        output("Racing Car Game");
////            glMaterialfv( GL_FRONT, GL_AMBIENT, mat_ambient16);
////            glMaterialfv( GL_FRONT, GL_DIFFUSE, mat_diffuse16);
////            glMaterialfv( GL_FRONT, GL_SPECULAR, mat_specular16);
////            glMaterialfv( GL_FRONT, GL_SHININESS, mat_shininess16);
////        drawStrokeText2("Submitted By :",-10,3.5,3);
////        drawStrokeText2("________",-10,3,3);
////        drawStrokeText2("Md. Mushfiqur Rahman Fakir",-10,2,3);
////        drawStrokeText2("Roll: 1607116",-10,1,3);
////        drawStrokeText2("Dept. of CSE",-10,0,3);
////
////        drawStrokeText2("Submitted To :",8,3.5,3);
////        drawStrokeText2("________",8,3,3);
////        drawStrokeText2("Dr. Sk. Md. Masudul Ahsan",8,2,3);
////        drawStrokeText2("Professor",8,1,3);
////        drawStrokeText2("Dept. of CSE",8,0,3);
////        drawStrokeText2("Kazi Saeed Alam",8,-1,3);
////        drawStrokeText2("Lecturer",8,-2,3);
////        drawStrokeText2("Dept. of CSE",8,-3,3);
//    }

    glFlush();
    glutSwapBuffers();
}



void special(int key, int x, int y)
{
    if (key==27)
        exit(0);

    if (key == GLUT_KEY_RIGHT)
    {
        if(step==1){
                input(120,480);
        }

    }
}


void MyMouseFunc(int button, int state, int x, int y)
{
    if(play && !stop)
    {
        if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
        {
            ;
        }
        else if(button==GLUT_LEFT_BUTTON && state==GLUT_UP)
        {
            //clear_grid();
            //input(x,y);

            if(step==0){
                input(x,y);
            }


        }
    }


    if(!play && !stop){
        if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
        {
            ;
        }
        else if(button==GLUT_RIGHT_BUTTON && state==GLUT_UP)
        {
            step=(step+1)%2;
            play=true;
        }
    }


}

void myKeyboardFunc( unsigned char key, int x, int y )
{
    switch ( key )
    {
//    case 'a' :
//        if(!play && !stop)
//        {
//            step=(step+1)%2;
//            play=true;
//        }
//        break;
//    case 'g' :
//        if(!stop)
//        {
//            guti3d = !guti3d;
//            if(win==0)
//            {
//                find_lookat();
//            }
//        }

    case 'g':
        if(START==0){
            START = 1 ;
        }
        else if(START==1){
            START = 0 ;
        }


    case 'd':
        xe--;
        xc--;
        break;
    case 'a':
        xe++;
        xc++;
        break;

    case 's':
        ye++;
        yc++;
        break;
    case 'w':
        ye--;
        yc--;
        break;


    case 'z': //zoom out
        ze++;
        zc++;
        break;

    case 'c':  //zoom in
        ze--;
        zc--;
        break;

    case 'y':
        Yaw(false);
        break;
    case 'Y':
        Yaw(true);
        break;

    case 'p':
        Pitch(true);
        break;
    case 'P':
        Pitch(false);
        break;

    case 'r':
        Roll(false);
        break;

    case 'R':
        Roll(true);
        break;

    case 'u':
        yc++;
        break;
    case 'U':
        yc--;
        break;
    case 'L':
        xc--;
        break;
    case 'l':
        xc++;
        break;
    case '+':
        zc--;
        break;
    case '-':
        zc++;
        break;
//    case 't':
//        yl++;
//        break;
//    case 'b':
//        yl--;
//        break;
//    case 'e':
//        xl++;
//        break;
//    case 'w':
//        xl--;
//        break;
//    case 'p':
//        zl++;
//        break;
//    case 'q':
//        zl--;
//        break;

    case 'x':
        on_light= !on_light;
        if(on_light)
        {
            amb=diff=spec=true;
        }
        break;
    case 'v':
        on_light2 = !on_light2;
        if(on_light2)
        {
            amb2=diff2=spec2=true;
        }
        break;
    case 'X':
        on_light3 = !on_light3;
        //on_light4 = !on_light4;
        if(on_light3)
        {
            amb3=diff3=spec3=true;
            //amb4=diff4=spec4=true;
        }
        break;
    case '1':
        amb = !amb;
        break;
    case '2':
        diff = !diff;
        break;
    case '3':
        spec = !spec;
        break;
    case '4':
        amb2 = !amb2;
        break;
    case '5':
        diff2 = !diff2;
        break;
    case '6':
        spec2 = !spec2;
        break;
    case '7':
        amb3 = !amb3;
        //amb4 = !amb4;
        break;
    case '8':
        diff3 = !diff3;
        //diff4 = !diff4;
        break;
    case '9':
        spec3 = !spec3;
        //spec4 = !spec4;
        break;



//    case 's':
//        bRotate = !bRotate;
//        uRotate = false;
//        axis_x=0.0;
//        axis_y=1.0;
//        break;
//
//    case 'S':
//        uRotate = !uRotate;
//        bRotate = false;
//        axis_x=1.0;
//        axis_y=0.0;
//        break;

    case 27:	// Escape key
        exit(1);
    }
}

void animate()
{
    if(step==1)
    {
        view=180.0;
    }
    else
    {
        view=0.0;
    }
    if(win!=0)
    {
        win_cnt++;
        if(guti3d)
        {
            if(win_cnt>400)
            {
                exit(1);
            }
        }
        else
        {
            if(win_cnt>2000)
            {
                exit(1);
            }
        }
    }

    if(on_light)
    {
        light();
    }
    else
    {
        glDisable( GL_LIGHT0);
    }

    if(on_light2)
    {
        light2();
    }
    else
    {
        glDisable( GL_LIGHT2);
    }

    if(on_light3)
    {
        light3();
        light4();
    }
    else
    {
        glDisable( GL_LIGHT3);
        glDisable( GL_LIGHT4);
    }

    if(amb)
    {
        glLightfv( GL_LIGHT0, GL_AMBIENT, light_ambient);
    }
    else
    {
        glLightfv( GL_LIGHT0, GL_AMBIENT, no_light);
    }

    if(amb2)
    {
        glLightfv( GL_LIGHT2, GL_AMBIENT, light_ambient2);
    }
    else
    {
        glLightfv( GL_LIGHT2, GL_AMBIENT, no_light);
    }

    if(amb3)
    {
        glLightfv( GL_LIGHT3, GL_AMBIENT, light_ambient3);
        glLightfv( GL_LIGHT4, GL_AMBIENT, light_ambient4);
    }
    else
    {
        glLightfv( GL_LIGHT3, GL_AMBIENT, no_light);
        glLightfv( GL_LIGHT4, GL_AMBIENT, no_light);
    }

    if(diff)
    {
        glLightfv( GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    }
    else
    {
        glLightfv( GL_LIGHT0, GL_DIFFUSE, no_light);
    }

    if(diff2)
    {
        glLightfv( GL_LIGHT2, GL_DIFFUSE, light_diffuse2);
    }
    else
    {
        glLightfv( GL_LIGHT2, GL_DIFFUSE, no_light);
    }

    if(diff3)
    {
        glLightfv( GL_LIGHT3, GL_DIFFUSE, light_diffuse3);
        glLightfv( GL_LIGHT4, GL_DIFFUSE, light_diffuse4);
    }
    else
    {
        glLightfv( GL_LIGHT3, GL_DIFFUSE, no_light);
        glLightfv( GL_LIGHT4, GL_DIFFUSE, no_light);
    }

    if(spec)
    {
        glLightfv( GL_LIGHT0, GL_SPECULAR, light_specular);
    }
    else
    {
        glLightfv( GL_LIGHT0, GL_SPECULAR, no_light);
    }

    if(spec2)
    {
        glLightfv( GL_LIGHT2, GL_SPECULAR, light_specular2);
    }
    else
    {
        glLightfv( GL_LIGHT2, GL_SPECULAR, no_light);
    }

    if(spec3)
    {
        glLightfv( GL_LIGHT3, GL_SPECULAR, light_specular3);
        glLightfv( GL_LIGHT4, GL_SPECULAR, light_specular4);
    }
    else
    {
        glLightfv( GL_LIGHT3, GL_SPECULAR, no_light);
        glLightfv( GL_LIGHT4, GL_SPECULAR, no_light);
    }

    glutPostRedisplay();
}

void control_key()
{
    printf("\n\n------  Control Key List: ------\n\n");

    printf("a-> alter the turn.\n");
    printf("g-> alter the guti from 2d to 3d or vice versa\n\n");

    printf("u -> moves the camera position up.\n");
    printf("d -> moves the camera position down.\n");
    printf("l -> moves the camera position left.\n");
    printf("r -> moves the camera position right.\n");
    printf("+ -> moves the camera position close/zoom in.\n");
    printf("- -> moves the camera position far/zoom out.\n\n");

    printf("t -> moves the look at position up.\n");
    printf("b -> moves the look at position down.\n");
    printf("w -> moves the look at position left.\n");
    printf("e -> moves the look at position right.\n");
    printf("p -> moves the look at position close.\n");
    printf("q -> moves the look at position far.\n\n");

    //printf("f -> on/off first fan.\n");
    //printf("F -> o/off second fan.\n\n");

    printf("x -> on/off first light.\n");
    printf("y -> on/off second light.\n");
    printf("z -> on/off spot light.\n\n");

    printf("1 -> on/off ambient effect of first light.\n");
    printf("2 -> on/off diffuse effect of first light.\n");
    printf("3 -> on/off specular effect of first light.\n\n");

    printf("4 -> on/off ambient effect of second light.\n");
    printf("5 -> on/off diffuse effect of second light.\n");
    printf("6 -> on/off specular effect of second light.\n\n");

    printf("7 -> on/off ambient effect of spot light.\n");
    printf("8 -> on/off diffuse effect of spot light.\n");
    printf("9 -> on/off specular effect of spot light.\n\n");


    printf("%llu, %llu",m_x,m_y);
}

int main (int argc, char **argv)
{
    control_key();
    initialize();
    mouse_position();
    mouse_position2();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);

    glutInitWindowPosition(100,100);
    glutInitWindowSize(1200, 700);
    glutCreateWindow("Chess Game");

    //glClearColor(0.75,0.78,0.815,0.7);
    glClearColor(0.85,0.9,0.85,0.4);
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);

    glShadeModel( GL_SMOOTH );
    glEnable( GL_DEPTH_TEST );
    glEnable(GL_NORMALIZE);

    glEnable(GL_LIGHTING);
    //light();
    LoadTexture("C:/Users/Dell/Desktop/4-2/Graphics lab/CHESS/w6.bmp",1);
    LoadTexture("C:/Users/Dell/Desktop/4-2/Graphics lab/CHESS/w3.bmp",2);
    LoadTexture("C:/Users/Dell/Desktop/4-2/Graphics lab/CHESS/w4.bmp",3);
//    //LoadTexture("F://Graphics Lab//image//green.bmp",4);
//    //LoadTexture("F://Graphics Lab//image//red.bmp",5);
//    //LoadTexture("F://Graphics Lab//image//guti_border.bmp",6);
//
    LoadTexture("C:/Users/Dell/Desktop/4-2/Graphics lab/CHESS/w4.bmp",7);  //pawn white
//    LoadTexture("F://Graphics Lab//image//pawn_black.bmp",8);
//
//    LoadTexture("F://Graphics Lab//image//king_white.bmp",9);
//    LoadTexture("F://Graphics Lab//image//king_black.bmp",10);
//
//    LoadTexture("F://Graphics Lab//image//queen_white.bmp",11);
//    LoadTexture("F://Graphics Lab//image//queen_black.bmp",12);
//
//    LoadTexture("F://Graphics Lab//image//rook_white.bmp",13);
//    LoadTexture("F://Graphics Lab//image//rook_black.bmp",14);
//
//    LoadTexture("F://Graphics Lab//image//knight_white.bmp",15);
//    LoadTexture("F://Graphics Lab//image//knight_black.bmp",16);
//
//    LoadTexture("F://Graphics Lab//image//bishop_white.bmp",17);
//    LoadTexture("F://Graphics Lab//image//bishop_black.bmp",18);


    glutKeyboardFunc(myKeyboardFunc);
    glutSpecialFunc(special);
    glutMouseFunc(MyMouseFunc);
    glutDisplayFunc(display);
    glutIdleFunc(animate);
    glutMainLoop();

    return 0;
}
