#include "Bank.h"
#include <iostream>


int Bank::usr_number = 1;
///////////////////////////////////////////////////////////////////////default ������
Bank::Bank()
{
	std::cout << "---��" << usr_number << "�� �������� �Է�---\n";
	//���ڿ� �����Ҵ�
	this->usr_name = new char[30];
	this->phone_num = new char[20];
	this->h_address = new char[100];

	std::cout << "�̸� : ";
	std::cin.getline(this->usr_name, 30);
	std::cout << "���¹�ȣ : ";
	std::cin >> this->account_num;
	std::cout << "PIN ( password ) : ";
	std::cin >> this->usr_pin;
	std::cout << "���� : ";
	std::cin >> this->deposit;
	this->credit_grade = this->set_grade(this->deposit);
	std::cout << "����( m,f�� �Է� ���� ) : ";
	std::cin >> this->gender;
	//m �Ǵ� f�� �Է��� ������ ���ѷ���
	while ((this->gender != 'm') && (this->gender != 'M') && (this->gender != 'F') && (this->gender != 'f'))
	{
		std::cout << "m �̳� f �� �ٽ� �Է����ּ��� \n";
		std::cin >> this->gender;
	}
	//cin �� ���ڸ� �Է¹������� '\n'�� ������ get() ���
	std::cin.get();
	std::cout << "��ȭ��ȣ : ";
	std::cin.getline(this->phone_num, 20);
	std::cout << "�� �ּ� : ";
	std::cin.getline(this->h_address, 100);

	++usr_number;
}
/// ///////////////////////////////////////////////////////////////////////////�Ҹ���
Bank::~Bank()
{
	std::cout << "~Bank()" << std::endl;
	delete[] this->usr_name;
	delete[] this->phone_num;
	delete[] this->h_address;
}
/// /////////////////////////////////////////////////////////////////////������ ���
void Bank::get_info()
{
	std::cout << "�̸� : " << this->usr_name << std::endl;
	std::cout << "���¹�ȣ : " << this->account_num << std::endl;
	std::cout << "PIN ( password ) : " << this->usr_pin << std::endl;
	std::cout << "���� : " << this->deposit << "��" << std::endl;
	std::cout << "�ſ��� : " << this->credit_grade << "���" << std::endl;
	std::cout << "���� : " << this->gender << std::endl;
	std::cout << "��ȭ��ȣ : " << this->phone_num << std::endl;
	std::cout << "�� �ּ� : " << this->h_address << std::endl;
}
/////////////////////////////////////////////////////////////////////////////�̸�ã��
void Bank::seek_usr_name(Bank* bank, const char* name, int usr_cnt)
{
	//��ü�迭���� �������(name)�� ����(usr_cnt) ��
	int i = 0;
	for (i = 0; i < usr_cnt+1; ++i)
	{
		if (i == usr_cnt) break;
		if (strcmp(bank[i].usr_name, name) == 0)	break;
	}
	//�迭 �߿� ���ڰ� ������ ���
	if (usr_cnt == i)
	{
		std::cout << "���� ���߿� �Է��Ͻ� �̸��� �����ϴ�." << std::endl;
		return;
	}
	bank[i].get_info();
	delete[] name;
}
////////////////////////////////////////////////////////////���� ���� ���� ������� ã��
void Bank::seek_VIP(Bank* bank, int usr_cnt)
{
	int i = 0;
	unsigned long max_deposit = bank[0].deposit;
	int vip_num = 0;
	//��ü�迭���� �ܰ�(deposit)�߿� ���� ū ��(max_deposit) �� �迭�ε���(vip_num) ����
	for (int i = 1; i < usr_cnt; ++i)
	{
		if (max_deposit < bank[i].deposit)
			vip_num = i;
	}

	std::cout << "���� ������ VIP�� " << std::endl;
	std::cout << bank[vip_num].usr_name<<"�� �Դϴ�." << std::endl;
	std::cout<<bank[vip_num].usr_name << "���� ���� �ܰ�� " << bank[vip_num].deposit << "�� �Դϴ�."  << std::endl;
}
//////////////////////////////////////////////////////////////////////////��� ���ϱ�
int Bank::set_grade(unsigned long deposit)
{
	if (deposit >= 200'000'000)
		return 1;
	else if (deposit >= 100'000'000)
		return 2;
	else if (deposit >= 50'000'000)
		return 3;
	else
		return 4;
}
////////////////////////////////////////////////////////////////////////////�Աݸ޼ҵ�
void Bank::input_money(Bank* bank, const char* name, int usr_cnt)
{
	int i = 0;
	//��ü �迭���� �̸��� ���� ��
	for (i = 0; i < usr_cnt + 1; ++i)
	{
		if (i == usr_cnt) break;
		if (strcmp(bank[i].usr_name, name) == 0)	break;
	}
	if (usr_cnt == i)
	{
		std::cout << "���� ���߿� �Է��Ͻ� �̸��� �����ϴ�." << std::endl;
		return;
	}
	int i_money = 0;
	std::cout << "�Աݾ� �Է� : ";
	std::cin >> i_money;

	while (i_money < 0)
	{
		std::cout << "������ �Է��Ͻ� �� �����ϴ�. �ٽ� �Է� �ϼ���.";
		std::cin >> i_money;
	}

	bank[i].deposit += i_money;
	/*if (bank[i].deposit >= 200'000'000)
		bank[i].credit_grade = 1;
	else if (bank[i].deposit >= 100'000'000)
		bank[i].credit_grade = 2;
	else if (bank[i].deposit >= 50'000'000)
		bank[i].credit_grade = 3;
	else
		bank[i].credit_grade = 4;*/
	bank[i].credit_grade = bank[i].set_grade(bank[i].deposit);

	std::cout << bank[i].usr_name << "���� " << std::endl;
	std::cout <<"���� �ܰ� : " << bank[i].deposit << "��" << std::endl;
	std::cout << "���� ��� : " << bank[i].credit_grade << "���" << std::endl;

	//bank[i].get_info();

	delete[] name;
}
////////////////////////////////////////////////////////////////////////////��ݸ޼ҵ�
void Bank::output_money(Bank* bank, const char* name, int usr_cnt)
{
	int i = 0;
	for (i = 0; i < usr_cnt+1; ++i)
	{
		if (i == usr_cnt) break;
		if (strcmp(bank[i].usr_name, name) == 0)	break;
	}

	if (usr_cnt == i)
	{
		std::cout << "���� ���߿� �Է��Ͻ� �̸��� �����ϴ�." << std::endl;
		return;
	}
	int pass = 0;
	int ans_cnt = 0;
	//3ȸ ������ ���
	for (ans_cnt = 3; ans_cnt > 0; --ans_cnt)
	{
		std::cout << "PASSWORD �Է� (3�� ������ ��� / " << ans_cnt << "�� ����) : ";
		std::cin >> pass;
		if (bank[i].usr_pin == pass)
			break;
	}
	if (ans_cnt == 0)
	{
		std::cout << "3ȸ ������ ����� �� �����ϴ�." << std::endl;
		return;
	}

	unsigned long o_money = 0;
	std::cout << "����� �ݾ� �Է�( ���� �ܰ� : " << bank[i].deposit << "�� ) : ";
	std::cin >> o_money;
	//���� �Է½� ���ѷ���
	while (o_money < 0)
	{
		std::cout << "������ �Է��Ͻ� �� �����ϴ�. �ٽ� �Է� �ϼ���.";
		std::cin >> o_money;
	}
	//���>�ܾ� �̸� ���ѷ���
	while (bank[i].deposit < o_money)
	{
		std::cout << "�ܾ��� �����մϴ�. �ٽ� �Է����ּ���" << std::endl;
		std::cin >> o_money;
	}
	bank[i].deposit -= o_money;
	//�ſ��� ���ϴ� ���ǹ�
	/*if (bank[i].deposit >= 200'000'000)
		bank[i].credit_grade = 1;
	else if (bank[i].deposit >= 100'000'000)
		bank[i].credit_grade = 2;
	else if (bank[i].deposit >= 50'000'000)
		bank[i].credit_grade = 3;
	else
		bank[i].credit_grade = 4;*/
	bank[i].credit_grade = bank[i].set_grade(bank[i].deposit);

	std::cout << bank[i].usr_name << "���� " << std::endl;
	std::cout << "���� �ܰ� : " << bank[i].deposit << "��" << std::endl;
	std::cout << "���� ��� : " << bank[i].credit_grade << "���" << std::endl;
	//��� �������°� ǥ��

	delete[] name;

}
//////////////////////////////////////////////////////////////////////////////�ܾ���ȸ
void Bank::bank_balance(Bank* bank, const char* name, int usr_cnt)
{
	int i = 0;
	//��ü ����̸�, ���� ��
	for (i = 0; i < usr_cnt+1; ++i)
	{
		if (i == usr_cnt) break;
		if (strcmp(bank[i].usr_name, name) == 0)	break;
	}
	if (usr_cnt == i)
	{
		std::cout << "���� ���߿� �Է��Ͻ� �̸��� �����ϴ�." << std::endl;
		return;
	}

	int pass = 0;
	int ans_cnt = 0;
	for (ans_cnt = 3; ans_cnt > 0; --ans_cnt)
	{
		std::cout << "PASSWORD �Է� (3�� ������ ��� / " << ans_cnt << "�� ����) : ";
		std::cin >> pass;
		if (bank[i].usr_pin == pass)
			break;
	}
	if (ans_cnt == 0)
	{
		std::cout << "3ȸ ������ ��ȸ�� �� �����ϴ�." << std::endl;
		return;
	}
	std::cout << bank[i].usr_name << "���� ���� �ܰ�� " << bank[i].deposit << "�� �Դϴ�." << std::endl;
	delete[] name;
}
/////////////////////////////////////////////////////////////////���¹�ȣ�� �������� ��ȸ
void Bank::show_info(Bank* bank, unsigned long long account_num, int usr_cnt)
{
	int i = 0;
	//��ü ������¹�ȣ(bank[i].account_num), ����(account_num) ��
	for (i = 0; i < usr_cnt+1; ++i)
	{
		if (i == usr_cnt) break;
		if (bank[i].account_num == account_num)	break;
	}
	if (usr_cnt == i)
	{
		std::cout << "���� ���߿� �Է��Ͻ� ���¹�ȣ�� �����ϴ�." << std::endl;
		return;
	}

	bank[i].get_info();

}

/// //////////////////////////////////////�ɼǿ� ���� ��ȭ��ȣ, �ּ�, �̸����� ���¹�ȣ ��ȸ
void Bank::show_account_num(Bank* bank, int option, int usr_cnt)
{
	std::cin.get();
	int i = 0;
	//�Է¹��� ��ȣ(option)�� switch�� ���
	switch (option)
	{
	case 1:
	{
		std::cout << "��ȭ��ȣ�� ����ã��" << std::endl;
		std::cout << "��ȭ��ȣ�� �Է��ϼ��� : " << std::endl;
		char* phonenum = new char[20];
		std::cin >> phonenum;

		for (i = 0; i < usr_cnt; ++i)
		{
			if (strcmp(bank[i].phone_num, phonenum) == 0)
			{
				break;
			}
		}
		std::cout << "���¹�ȣ : " << bank[i].account_num << std::endl;
		delete[] phonenum;
		break;
	}

	case 2:
	{
		std::cout << "�ּҷ� ����ã��" << std::endl;
		std::cout << "�ּҸ� �Է��ϼ��� : " << std::endl;
		char* address = new char[100];
		std::cin.getline(address, 100);
		for (i = 0; i < usr_cnt; ++i)
		{
			if (strcmp(bank[i].h_address, address) == 0) {
				//std::cout << bank[i].h_address << std::endl;
				//std::cout << address << std::endl;
				break;
			}
		}
		std::cout << "���¹�ȣ : " << bank[i].account_num << std::endl;
		delete[] address;
		break;
	}

	case 3:
	{
		std::cout << "�̸����� ����ã��" << std::endl;
		std::cout << "�̸��� �Է��ϼ��� : " << std::endl;
		char* name = new char[30];
		std::cin >> name;
		for (i = 0; i < usr_cnt; ++i)
		{
			if (strcmp(bank[i].usr_name, name) == 0)	break;
		}
		std::cout << "���¹�ȣ : " << bank[i].account_num << std::endl;
		delete[] name;
		break;
	}
	default:
	{
		std::cout << "�߸��� �Է��Դϴ�. �۾��� ����մϴ�.\n";
		break;
	}

	}

}