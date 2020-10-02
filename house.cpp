#include <iostream>
#include <time.h>
using namespace std;
//
//class Iworker;
//class Team;
//class Worker;
//class Leader;

class House
{
public:
	void Draw_myself()
	{
		cout<<"\n"<<endl;
		cout<<"        *"<<endl;
		cout<<"       ***"<<endl;
		cout<<"      *   *"<<endl;
		cout<<"     *     *"<<endl;
		cout<<"    *       *"<<endl;
		cout<<"   *         *"<<endl;
		cout<<"  *           *"<<endl;
		cout<<"  * ***   *** *"<<endl;
		cout<<"  * ***   *** *"<<endl;
		cout<<"  *       *** *"<<endl;
		cout<<"  *************"<<endl;
	}
};
class IPart
{
public:
	IPart(){}
	int building_steps;
	int done;
	virtual ~IPart()=0;
};
IPart::~IPart(){}

class Basement:public IPart
{
public:
	Basement(){building_steps=5;done=0;}
	friend void Basement_building(Basement &B);
	friend int Basement_complete(Basement &B);
};
class Wall:public IPart
{
public:
	Wall(){building_steps=5;done=0;}
	friend void Wall_building(Wall &W1,Wall &W2,Wall &W3,Wall &W4);
	friend int Wall_complete(Wall &W1,Wall &W2,Wall &W3,Wall &W4);
};
class Door:public IPart
{
public:
	Door(){building_steps=5;done=0;}
	friend void Door_building(Door &D);
	friend int Door_complete(Door &D);
};
class Window:public IPart
{
public:
	Window(){building_steps=5;done=0;}
	friend void Window_building(Window &W);
	friend int Window_complete(Window &W);
};
class Roof:public IPart
{
public:
	Roof(){building_steps=5;done=0;}
	friend void Roof_building(Roof &R);
	friend int Roof_complete(Roof &R);
};

class IWorker
{
public:
	virtual ~IWorker()=0;
protected:
	friend void Basement_building();
	friend int Basement_Complete();
	friend void Wall_building();
	friend int Wall_complete();
	friend void Door_building();
	friend int Door_complete();
	friend void Window_building();
	friend int Window_complete();
	friend void Roof_building();
	friend int Roof_complete();
	int Check(Basement &B,Wall &W1,Wall &W2,Wall &W3,Wall &W4,Door &D,Window &W,Roof &R)
	{
		int complete=0;
		if (Basement_complete(B)==1)
			complete++;
		if (Wall_complete(W1,W2,W3,W4)==1)
			complete++;
		if (Door_complete(D)==1)
			complete++;
		if (Window_complete(W)==1)
			complete++;
		if (Roof_complete(R)==1)
			complete++;
		return complete;
	}
	void Doing(int Team_name,Basement &B,Wall &W1,Wall &W2,Wall &W3,Wall &W4,Door &D,Window &W,Roof &R)
	{
		switch (Team_name)
		{
		case 1:{Basement_building(B);}break;
		case 2:{Wall_building(W1,W2,W3,W4);}break;
		case 3:{Door_building(D);}break;
		case 4:{Window_building(W);}break;
		case 5:{Roof_building(R);}break;
		}
	}
};
IWorker::~IWorker(){}
class Worker:protected IWorker
{
protected:
public:
	void Get_job(int Team_name,Basement &B,Wall &W1,Wall &W2,Wall &W3,Wall &W4,Door &D,Window &W,Roof &R)
	{
		Team_name=Team_name;
		Doing(Team_name,B,W1,W2,W3,W4,D,W,R);
	}
};
class Team:protected Worker
{
public:
	void Team_cmd(int Team_name,Worker &Wr1,Worker&Wr2,Worker &Wr3,Worker &Wr4,Worker &Wr5,Basement &B,Wall &W1,Wall &W2,Wall &W3,Wall &W4,Door &D,Window &W,Roof &R)
	{
		Wr1.Get_job(Team_name,B,W1,W2,W3,W4,D,W,R);
		Wr2.Get_job(Team_name,B,W1,W2,W3,W4,D,W,R);
		Wr3.Get_job(Team_name,B,W1,W2,W3,W4,D,W,R);
		Wr4.Get_job(Team_name,B,W1,W2,W3,W4,D,W,R);
		Wr5.Get_job(Team_name,B,W1,W2,W3,W4,D,W,R);
	}
};
class Leader:protected IWorker
{
public:
	Leader(House &H)
	{
		Basement B;
		Wall W1,W2,W3,W4;
		Door D;
		Window W;
		Roof R;
		Worker Wr1;
		Worker Wr2;
		Worker Wr3;
		Worker Wr4;
		Worker Wr5;
		Team T;
		int Team_name;
		for (int i=1;i<=5;i++)
		{
			for (;;)
			{
				Team_name=rand()%5+1;
				if (Team_name==i)
				{
					T.Team_cmd(Team_name,Wr1,Wr2,Wr3,Wr4,Wr5,B,W1,W2,W3,W4,D,W,R);
					break;
				}
				else
					continue;
			}
		}
		if (Check(B,W1,W2,W3,W4,D,W,R)==5)
			H.Draw_myself();
	}
};


void Basement_building(Basement &B)
{
	B.done++;
}
int Basement_complete(Basement &B)
{
	if (B.done==B.building_steps)
		return 1;
	return 0;
}
void Wall_building(Wall &W1,Wall &W2,Wall &W3,Wall &W4)
{W1.done++;W2.done++;W3.done++;W4.done++;}
int Wall_complete(Wall &W1,Wall &W2,Wall &W3,Wall &W4)
{
	if (W1.done==W1.building_steps&&W2.done==W2.building_steps&&W3.done==W3.building_steps&&W4.done==W4.building_steps)
		return 1;
	return 0;
}
void Door_building(Door &D)
{
	D.done++;
}
int Door_complete(Door &D)
{
	if (D.done==D.building_steps)
		return 1;
	return 0;
}
void Window_building(Window &W)
{
	W.done++;
}
int Window_complete(Window &W)
{
	if (W.done==W.building_steps)
		return 1;
	return 0;
}
void Roof_building(Roof &R)
{
	R.done++;
}
int Roof_complete(Roof &R)
{
	if (R.done==R.building_steps)
		return 1;
	return 0;
}

int main()
{
	House H;
	Leader L(H);
	return 0;
}