#include <iostream>
#include "Bank.h"

int main()
{
	//���� �Է�
	std::cout << "�� �� �Է� : ";
	int usr_cnt = 0;
	std::cin >> usr_cnt;
	std::cin.get();

	//��ü �迭 ����
	Bank* bank = new Bank[usr_cnt];

	//////////////////////////////////////////////////////////////////////////////////////////////////////

		////�̸�ã�� : �Լ� �Է� �̸��� �������� ���
		//std::cout << "�̸� ã�� : ";
		//char* str = new char[30];
		//std::cin >> str;
		//Bank::seek_usr_name(bank, str, usr_cnt);

		////VIP ã��
		//Bank::seek_VIP(bank, usr_cnt);

		////�Ա� �޼ҵ�
		//std::cout << "�Ա��� ��� �̸� �Է� : ";
		//char* u_name = new char[30];
		//std::cin >> u_name;
		//Bank::input_money(bank, u_name, usr_cnt);

		////��� �޼ҵ�
		//std::cout << "����� ��� �̸� �Է� : ";
		//char* u_name = new char[30];
		//std::cin >> u_name;
		//Bank::output_money(bank, u_name, usr_cnt);

		////�ܾ���ȸ
		//std::cout << "�ܾ� ��ȸ�� ��� �̸� �Է� : ";
		//char* u_name = new char[30];
		//std::cin >> u_name;
		//Bank::bank_balance(bank, u_name, usr_cnt);

		////���¹�ȣ�� �������� ��ȸ
		//std::cout << "���¹�ȣ �Է� : ";
		//int account_num = 0;
		//std::cin >> account_num;
		//Bank::show_info(bank, account_num, usr_cnt);

	while (1)
	{
		//��ȭ��ȣ, ���ּ�, �̸����� ���¹�ȣ ��ȸ
		std::cout << "�������� ���¹�ȣ�� ã�ڽ��ϱ�? ( [1]��ȭ��ȣ [2]�� �ּ� [3]�̸� ) : ";
		int option = 0;
		std::cin >> option;
		Bank::show_account_num(bank, option, usr_cnt);
	}


	//////////////////////////////////////////////////////////////////////////////////////////////////////



	char* phonenum = new char[20];
	std::cin >> phonenum;
	char str[20] = { "Hello" };




	delete[] bank;
	return 0;
}
