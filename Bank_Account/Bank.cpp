#include "Bank.h"
#include <iostream>


int Bank::usr_number = 1;
///////////////////////////////////////////////////////////////////////default 생성자
Bank::Bank()
{
	std::cout << "---고객" << usr_number << "의 개인정보 입력---\n";
	//문자열 동적할당
	this->usr_name = new char[30];
	this->phone_num = new char[20];
	this->h_address = new char[100];

	std::cout << "이름 : ";
	std::cin.getline(this->usr_name, 30);
	std::cout << "계좌번호 : ";
	std::cin >> this->account_num;
	std::cout << "PIN ( password ) : ";
	std::cin >> this->usr_pin;
	std::cout << "예금 : ";
	std::cin >> this->deposit;
	this->credit_grade = this->set_grade(this->deposit);
	std::cout << "성별( m,f로 입력 가능 ) : ";
	std::cin >> this->gender;
	//m 또는 f를 입력할 때까지 무한루프
	while ((this->gender != 'm') && (this->gender != 'M') && (this->gender != 'F') && (this->gender != 'f'))
	{
		std::cout << "m 이나 f 로 다시 입력해주세요 \n";
		std::cin >> this->gender;
	}
	//cin 후 문자를 입력받을때는 '\n'을 없애줄 get() 사용
	std::cin.get();
	std::cout << "전화번호 : ";
	std::cin.getline(this->phone_num, 20);
	std::cout << "집 주소 : ";
	std::cin.getline(this->h_address, 100);

	++usr_number;
}
/// ///////////////////////////////////////////////////////////////////////////소멸자
Bank::~Bank()
{
	std::cout << "~Bank()" << std::endl;
	delete[] this->usr_name;
	delete[] this->phone_num;
	delete[] this->h_address;
}
/// /////////////////////////////////////////////////////////////////////고객정보 출력
void Bank::get_info()
{
	std::cout << "이름 : " << this->usr_name << std::endl;
	std::cout << "계좌번호 : " << this->account_num << std::endl;
	std::cout << "PIN ( password ) : " << this->usr_pin << std::endl;
	std::cout << "예금 : " << this->deposit << "원" << std::endl;
	std::cout << "신용등급 : " << this->credit_grade << "등급" << std::endl;
	std::cout << "성별 : " << this->gender << std::endl;
	std::cout << "전화번호 : " << this->phone_num << std::endl;
	std::cout << "집 주소 : " << this->h_address << std::endl;
}
/////////////////////////////////////////////////////////////////////////////이름찾기
void Bank::seek_usr_name(Bank* bank, const char* name, int usr_cnt)
{
	//객체배열들의 멤버변수(name)와 인자(usr_cnt) 비교
	int i = 0;
	for (i = 0; i < usr_cnt+1; ++i)
	{
		if (i == usr_cnt) break;
		if (strcmp(bank[i].usr_name, name) == 0)	break;
	}
	//배열 중에 인자가 없으면 출력
	if (usr_cnt == i)
	{
		std::cout << "저희 고객중에 입력하신 이름은 없습니다." << std::endl;
		return;
	}
	bank[i].get_info();
	delete[] name;
}
////////////////////////////////////////////////////////////가장 많은 예금 가진사람 찾기
void Bank::seek_VIP(Bank* bank, int usr_cnt)
{
	int i = 0;
	unsigned long max_deposit = bank[0].deposit;
	int vip_num = 0;
	//객체배열들의 잔고(deposit)중에 가장 큰 값(max_deposit) 및 배열인덱스(vip_num) 추출
	for (int i = 1; i < usr_cnt; ++i)
	{
		if (max_deposit < bank[i].deposit)
			vip_num = i;
	}

	std::cout << "저희 은행의 VIP는 " << std::endl;
	std::cout << bank[vip_num].usr_name<<"님 입니다." << std::endl;
	std::cout<<bank[vip_num].usr_name << "님의 현재 잔고는 " << bank[vip_num].deposit << "원 입니다."  << std::endl;
}
//////////////////////////////////////////////////////////////////////////등급 정하기
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
////////////////////////////////////////////////////////////////////////////입금메소드
void Bank::input_money(Bank* bank, const char* name, int usr_cnt)
{
	int i = 0;
	//객체 배열들의 이름과 인자 비교
	for (i = 0; i < usr_cnt + 1; ++i)
	{
		if (i == usr_cnt) break;
		if (strcmp(bank[i].usr_name, name) == 0)	break;
	}
	if (usr_cnt == i)
	{
		std::cout << "저희 고객중에 입력하신 이름은 없습니다." << std::endl;
		return;
	}
	int i_money = 0;
	std::cout << "입금액 입력 : ";
	std::cin >> i_money;

	while (i_money < 0)
	{
		std::cout << "음수는 입력하실 수 없습니다. 다시 입력 하세요.";
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

	std::cout << bank[i].usr_name << "님의 " << std::endl;
	std::cout <<"현재 잔고 : " << bank[i].deposit << "원" << std::endl;
	std::cout << "현재 등급 : " << bank[i].credit_grade << "등급" << std::endl;

	//bank[i].get_info();

	delete[] name;
}
////////////////////////////////////////////////////////////////////////////출금메소드
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
		std::cout << "저희 고객중에 입력하신 이름은 없습니다." << std::endl;
		return;
	}
	int pass = 0;
	int ans_cnt = 0;
	//3회 오류시 잠금
	for (ans_cnt = 3; ans_cnt > 0; --ans_cnt)
	{
		std::cout << "PASSWORD 입력 (3번 오류시 잠금 / " << ans_cnt << "번 남음) : ";
		std::cin >> pass;
		if (bank[i].usr_pin == pass)
			break;
	}
	if (ans_cnt == 0)
	{
		std::cout << "3회 오류로 출금할 수 없습니다." << std::endl;
		return;
	}

	unsigned long o_money = 0;
	std::cout << "출금할 금액 입력( 현재 잔고 : " << bank[i].deposit << "원 ) : ";
	std::cin >> o_money;
	//음수 입력시 무한루프
	while (o_money < 0)
	{
		std::cout << "음수는 입력하실 수 없습니다. 다시 입력 하세요.";
		std::cin >> o_money;
	}
	//출금>잔액 이면 무한루프
	while (bank[i].deposit < o_money)
	{
		std::cout << "잔액이 부족합니다. 다시 입력해주세요" << std::endl;
		std::cin >> o_money;
	}
	bank[i].deposit -= o_money;
	//신용등급 정하는 조건문
	/*if (bank[i].deposit >= 200'000'000)
		bank[i].credit_grade = 1;
	else if (bank[i].deposit >= 100'000'000)
		bank[i].credit_grade = 2;
	else if (bank[i].deposit >= 50'000'000)
		bank[i].credit_grade = 3;
	else
		bank[i].credit_grade = 4;*/
	bank[i].credit_grade = bank[i].set_grade(bank[i].deposit);

	std::cout << bank[i].usr_name << "님의 " << std::endl;
	std::cout << "현재 잔고 : " << bank[i].deposit << "원" << std::endl;
	std::cout << "현재 등급 : " << bank[i].credit_grade << "등급" << std::endl;
	//등급 떨어지는거 표시

	delete[] name;

}
//////////////////////////////////////////////////////////////////////////////잔액조회
void Bank::bank_balance(Bank* bank, const char* name, int usr_cnt)
{
	int i = 0;
	//객체 멤버이름, 인자 비교
	for (i = 0; i < usr_cnt+1; ++i)
	{
		if (i == usr_cnt) break;
		if (strcmp(bank[i].usr_name, name) == 0)	break;
	}
	if (usr_cnt == i)
	{
		std::cout << "저희 고객중에 입력하신 이름은 없습니다." << std::endl;
		return;
	}

	int pass = 0;
	int ans_cnt = 0;
	for (ans_cnt = 3; ans_cnt > 0; --ans_cnt)
	{
		std::cout << "PASSWORD 입력 (3번 오류시 잠금 / " << ans_cnt << "번 남음) : ";
		std::cin >> pass;
		if (bank[i].usr_pin == pass)
			break;
	}
	if (ans_cnt == 0)
	{
		std::cout << "3회 오류로 조회할 수 없습니다." << std::endl;
		return;
	}
	std::cout << bank[i].usr_name << "님의 현재 잔고는 " << bank[i].deposit << "원 입니다." << std::endl;
	delete[] name;
}
/////////////////////////////////////////////////////////////////계좌번호로 개인정보 조회
void Bank::show_info(Bank* bank, unsigned long long account_num, int usr_cnt)
{
	int i = 0;
	//객체 멤버계좌번호(bank[i].account_num), 인자(account_num) 비교
	for (i = 0; i < usr_cnt+1; ++i)
	{
		if (i == usr_cnt) break;
		if (bank[i].account_num == account_num)	break;
	}
	if (usr_cnt == i)
	{
		std::cout << "저희 고객중에 입력하신 계좌번호는 없습니다." << std::endl;
		return;
	}

	bank[i].get_info();

}

/// //////////////////////////////////////옵션에 따라 전화번호, 주소, 이름으로 계좌번호 조회
void Bank::show_account_num(Bank* bank, int option, int usr_cnt)
{
	std::cin.get();
	int i = 0;
	//입력받은 번호(option)로 switch문 사용
	switch (option)
	{
	case 1:
	{
		std::cout << "전화번호로 계좌찾기" << std::endl;
		std::cout << "전화번호를 입력하세요 : " << std::endl;
		char* phonenum = new char[20];
		std::cin >> phonenum;

		for (i = 0; i < usr_cnt; ++i)
		{
			if (strcmp(bank[i].phone_num, phonenum) == 0)
			{
				break;
			}
		}
		std::cout << "계좌번호 : " << bank[i].account_num << std::endl;
		delete[] phonenum;
		break;
	}

	case 2:
	{
		std::cout << "주소로 계좌찾기" << std::endl;
		std::cout << "주소를 입력하세요 : " << std::endl;
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
		std::cout << "계좌번호 : " << bank[i].account_num << std::endl;
		delete[] address;
		break;
	}

	case 3:
	{
		std::cout << "이름으로 계좌찾기" << std::endl;
		std::cout << "이름을 입력하세요 : " << std::endl;
		char* name = new char[30];
		std::cin >> name;
		for (i = 0; i < usr_cnt; ++i)
		{
			if (strcmp(bank[i].usr_name, name) == 0)	break;
		}
		std::cout << "계좌번호 : " << bank[i].account_num << std::endl;
		delete[] name;
		break;
	}
	default:
	{
		std::cout << "잘못된 입력입니다. 작업을 취소합니다.\n";
		break;
	}

	}

}