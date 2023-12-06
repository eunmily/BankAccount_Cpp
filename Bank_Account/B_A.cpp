#include <iostream>
#include "Bank.h"

int main()
{
	//고객수 입력
	std::cout << "고객 수 입력 : ";
	int usr_cnt = 0;
	std::cin >> usr_cnt;
	std::cin.get();

	//객체 배열 생성
	Bank* bank = new Bank[usr_cnt];

	//////////////////////////////////////////////////////////////////////////////////////////////////////

		////이름찾기 : 함수 입력 이름의 개인정보 출력
		//std::cout << "이름 찾기 : ";
		//char* str = new char[30];
		//std::cin >> str;
		//Bank::seek_usr_name(bank, str, usr_cnt);

		////VIP 찾기
		//Bank::seek_VIP(bank, usr_cnt);

		////입금 메소드
		//std::cout << "입금할 사람 이름 입력 : ";
		//char* u_name = new char[30];
		//std::cin >> u_name;
		//Bank::input_money(bank, u_name, usr_cnt);

		////출금 메소드
		//std::cout << "출금할 사람 이름 입력 : ";
		//char* u_name = new char[30];
		//std::cin >> u_name;
		//Bank::output_money(bank, u_name, usr_cnt);

		////잔액조회
		//std::cout << "잔액 조회할 사람 이름 입력 : ";
		//char* u_name = new char[30];
		//std::cin >> u_name;
		//Bank::bank_balance(bank, u_name, usr_cnt);

		////계좌번호로 개인정보 조회
		//std::cout << "계좌번호 입력 : ";
		//int account_num = 0;
		//std::cin >> account_num;
		//Bank::show_info(bank, account_num, usr_cnt);

	while (1)
	{
		//전화번호, 집주소, 이름으로 계좌번호 조회
		std::cout << "무엇으로 계좌번호를 찾겠습니까? ( [1]전화번호 [2]집 주소 [3]이름 ) : ";
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
