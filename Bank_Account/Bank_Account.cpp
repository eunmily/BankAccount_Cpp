#include <iostream>
#include <typeinfo>
#include <cstdlib>
#include "Bank.h"

int main()
{
	std::cout << "고객 수 입력 : ";
	int usr_cnt = 0;
	
	if (std::cin >> usr_cnt)
	{
		while (usr_cnt <= 0)
		{
			std::cout << "잘못된 입력입니다. 다시 입력하세요 \n";
			std::cout << "고객 수 입력 : ";
			std::cin >> usr_cnt;
		}		
	}
	//고객수가 5명 미만이면 무한루프
	/*while (usr_cnt < 5)
	{
		std::cout << "고객이 너무 적습니다. 다시 입력하세요 \n";
		std::cin >> usr_cnt;
	}*/

	std::cin.get();
	system("cls");

	//객체 배열 생성
	Bank* bank = new Bank[usr_cnt];

	

	while (1) {
		system("cls");

		std::cout << "-----------------------------------------------------\n";
		std::cout << "           원하시는 작업을 선택하여 주십시오 :             \n";
		std::cout << "[1] 이름을 입력해서 개인정보 조회                         \n";
		std::cout << "[2] 가장 많은 예금을 가진 고객의 이름, 잔고 조회            \n";
		std::cout << "[3] 입금                                               \n";
		std::cout << "[4] 출금                                               \n";
		std::cout << "[5] 잔액 조회                                           \n";
		std::cout << "[6] 계좌번호를 입력해서 개인정보 조회                       \n";
		std::cout << "[7] 옵션(전화번호, 주소, 이름)에 따라 계좌번호 조회          \n";
		std::cout << "-----------------------------------------------------\n";
		int select_number = 0;
		std::cin >> select_number;

		switch (select_number)
		{
		case 1:
		{
			system("cls");
			std::cout << "-----------------------------------------------------\n";
			std::cout << "             [1] 이름을 입력해서 개인정보 조회           \n";
			std::cout << "-----------------------------------------------------\n";
			std::cout << "이름을 입력해 주십시오 : ";
			char* str = new char[30];
			std::cin >> str;
			Bank::seek_usr_name(bank, str, usr_cnt);
			std::cin.get();
			break;
		}
		case 2:
		{
			system("cls");
			std::cout << "-----------------------------------------------------\n";
			std::cout << "       [2] 가장 많은 예금을 가진 고객의 이름, 잔고 조회    \n";
			std::cout << "-----------------------------------------------------\n";
			Bank::seek_VIP(bank, usr_cnt);
			std::cin.get();
			break;
		}
		case 3:
		{
			system("cls");
			std::cout << "-----------------------------------------------------\n";
			std::cout << "                     [3] 입금                        \n";
			std::cout << "-----------------------------------------------------\n";

			std::cout << "입금할 사람 이름 입력 : ";
			char* u_name = new char[30];
			std::cin >> u_name;
			Bank::input_money(bank, u_name, usr_cnt);

			std::cin.get();
			break;
		}
		case 4:
		{
			system("cls");
			std::cout << "-----------------------------------------------------\n";
			std::cout << "                     [4] 출금                        \n";
			std::cout << "-----------------------------------------------------\n";

			std::cout << "출금할 사람 이름 입력 : ";
			char* u_name = new char[30];
			std::cin >> u_name;
			Bank::output_money(bank, u_name, usr_cnt);

			std::cin.get();
			break;
		}
		case 5:
		{
			system("cls");
			std::cout << "-----------------------------------------------------\n";
			std::cout << "                    [5] 잔액 조회                      \n";
			std::cout << "-----------------------------------------------------\n";

			std::cout << "잔액 조회할 사람 이름 입력 : ";
			char* u_name = new char[30];
			std::cin >> u_name;
			Bank::bank_balance(bank, u_name, usr_cnt);

			std::cin.get();
			break;
		}
		case 6:
		{
			system("cls");
			std::cout << "-----------------------------------------------------\n";
			std::cout << "          [6] 계좌번호를 입력해서 개인정보 조회           \n";
			std::cout << "-----------------------------------------------------\n";

			std::cout << "계좌번호 입력 : ";
			int account_num = 0;
			std::cin >> account_num;
			Bank::show_info(bank, account_num, usr_cnt);

			std::cin.get();
			break;
		}
		case 7:
		{
			system("cls");
			std::cout << "-----------------------------------------------------\n";
			std::cout << "     [7] 옵션(전화번호, 주소, 이름)에 따라 계좌번호 조회    \n";
			std::cout << "-----------------------------------------------------\n";

			std::cout << "무엇으로 계좌번호를 찾겠습니까? ( [1]전화번호 [2]집 주소 [3]이름 ) : ";
			int option = 0;
			std::cin >> option;
			Bank::show_account_num(bank, option, usr_cnt);

			std::cin.get();
			break;
		}
		//1~7 이외의 키를 누르면 프로그램 종료
		default:
			std::cout << "저희 은행을 이용해주셔서 감사합니다." << std::endl;
			exit(1);
			
		}
		//case 들이 끝난 후 바로 반복되지않게 get()로 막아줌
		std::cout << "작업을 계속하시려면 Enter키를 눌러주십시오\n";
		std::cin.get();
	}

	delete[] bank;
	return 0;
}
