#pragma once
#include <iostream>
class Bank
{
private:
	/*char usr_name[50];*/
	char* usr_name;					//���̸�
	unsigned long long account_num;	//���¹�ȣ
	unsigned int usr_pin;			//PIN	
	unsigned long deposit;			//�ܰ�
	int credit_grade;				//�ſ���
	char gender;					//����
	char* phone_num;				//��ȭ��ȣ
	char* h_address;				//�ּ�
	static int usr_number;			//�ο� ��

public:
	//����Ʈ ������
	Bank();
	//�Ҹ���
	~Bank();
	
	//���� ��ȸ
	void get_info();
	//�̸� ã�� ���
	static void seek_usr_name(Bank* bank, const char* name,int usr_cnt);
	//���� ���� ������� ã�� ���
	static void seek_VIP(Bank* bank, int usr_cnt);
	//��� ���ϱ�
	int set_grade(unsigned long);
	//�Ա�
	static void input_money(Bank* bank, const char* name, int usr_cnt);
	//���
	static void output_money(Bank* bank, const char* name, int usr_cnt);
	//�ܰ� ��ȸ
	static void bank_balance(Bank* bank, const char* name, int usr_cnt);
	//���¹�ȣ�� �������� ��ȸ
	static void show_info(Bank* bank, unsigned long long account_num, int usr_cnt);
	//�ɼ�(��ȭ��ȣ, ���ּ�, �̸�)�� ���� ���¹�ȣ ��ȸ
	static void show_account_num(Bank* bank, int option, int usr_cnt);
};

