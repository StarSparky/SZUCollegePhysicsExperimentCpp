#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
using namespace std;
struct Data
{
	double origin;//ԭʼ��������
	double deal;//������̶����
	double error;//�������
	 
};
int main()
{
	fstream input("D:\\PhysicsExperiment\\Input.txt");
 
	int times;//��������
	double L0;//�������
	double average = 0;//����ƽ��ֵ����������
	double stdVarience = 0;//��׼��
	double uA = 0;//A���׼��ȷ���ȣ�����ƽ��ֵ�ı�׼��
	double uB = 0;//B���׼��ȷ����
	double u = 0;//��ȷ����
	double tp = 0;//tp����
	double x = 0;//��ȷ��С�����xλ
	string measure;//�������ݵĵ�λ 
	string s;//���ֻ���
	input >> s >> times;
	input >> s >> L0;
	input >> s >> tp;
	input >> s >> uB;
	input >> s >> x ;
	input >> s >> measure >> s;
	Data *data = new Data[times];
	int i;
	for (i = 0; i < times; ++i)
	{
		input >> data[i].origin;
		data[i].deal = data[i].origin - L0;
		average += data[i].deal;
	}
	average /= times;
	for (int i = 0; i < times; ++i)
	{
		data[i].error = fabs(data[i].deal - average);
		stdVarience += powf(data[i].error, 2);
	}
	stdVarience = sqrtf(stdVarience / (times - 1));
	uA = stdVarience / sqrtf(times);
	uB = uB / sqrtf(3);
	u = sqrtf(powf(tp*uA, 2) + powf(uB, 2));
	cout << "|���|   ��������   | ������error��|"<<endl;
	for (int i = 0; i < times; ++i)
	{
		cout << setiosflags(ios::fixed) << setiosflags(ios::right) <<"| " << setw(2) <<i+1<<setprecision(x) << " |  " << setw(7) << data[i].deal << "mm   |    " << setprecision(x)<< data[i].error << "mm    |"<<endl;
	}
	cout << setiosflags(ios::fixed) << setprecision(x);
	cout << "����ƽ��ֵ�� " << average <<" "<< measure << endl;
	cout << "��׼� " << stdVarience << endl;
	cout << "A���׼��ȷ����uA�� " << uA <<" "<< measure <<endl;
	cout << "B���׼��ȷ����uB�� " << uB <<" "<< measure << endl;
	cout << "���Բ�ȷ����u: " << u <<" "<< measure << endl;
	cout << "��Բ�ȷ����ur�� " << u * 100 / average << "%" << endl;
	cout << "�������X�� " << average << "��" << u<<" "<< measure <<endl;
	
	input.close();
	char closingApp;
	cout << "������ɣ��밴������˳���" << endl; 
	cin.get();
	
}
