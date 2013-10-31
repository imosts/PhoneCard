#include<iostream>
using namespace std;

class PhoneCard{
public:
	double balance;
	void performDial();
};
class Card_201:public PhoneCard{

	
public:
	void performDial();
	double balance;
	long cardNumber;
	static long connectNumber;
	static double additoryFee;
	bool connected;
	double getBalance();
	void performConnect(long cn,int pw);
	Card_201(long cn,int pw,double b){
		this->cardNumber=cn;
		this->password=pw;
		this->balance=b;
		this->connected=false;
	};
private:
	int password;

};

long Card_201::connectNumber=201;
double Card_201::additoryFee=0.03;

double Card_201::getBalance(){
	if(!connected)
		return 0;
	else
		return balance;
}

void Card_201::performDial(){
	if(connected)
	balance=balance-0.3-additoryFee;
}

void Card_201::performConnect(long cn,int pw){
	if(cardNumber==cn||password==pw)
		connected=1;
}

int main(){
	long cn;
	int pw;
	double b;
	int a;
	cout<<"��ʼ����Ϣ"<<endl;
	cout<<"��������"<<endl;
	cin>>cn;
	cout<<"����������"<<endl;
	cin>>pw;
	cout<<"��ʼ�����"<<endl;
	cin>>b;
	Card_201  card(cn,pw,b);
	do{ 
	cout<<"1������"<<endl;
	cout<<"2������绰"<<endl;
	cout<<"3: ��ʾ���"<<endl;
	cout<<"4: �˳�"<<endl;
	cout<<"������Ҫ�����Ĳ���"<<endl;
	cin>>a;
	switch (a){
		case 1:
			long cn1;
			int pw1;
			cout<<"�����뿨��"<<endl;
			cin>>cn1;
			cout<<"����������"<<endl;
			cin>>pw1;
			card.performConnect(cn1,pw1);
			break;
		case 2:
			card.performDial();
			break;
		case 3:
			cout<<card.getBalance()<<endl;
			break;
		case 4:
			return 0;
		
	default:
		break;
	}
	}while(1);
}