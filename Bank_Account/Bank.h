#pragma once
#include <iostream>
class Bank
{
private:
	/*char usr_name[50];*/
	char* usr_name;					//고객이름
	unsigned long long account_num;	//계좌번호
	unsigned int usr_pin;			//PIN	
	unsigned long deposit;			//잔고
	int credit_grade;				//신용등급
	char gender;					//성별
	char* phone_num;				//전화번호
	char* h_address;				//주소
	static int usr_number;			//인원 수

public:
	//디폴트 생성자
	Bank();
	//소멸자
	~Bank();
	
	//정보 조회
	void get_info();
	//이름 찾기 기능
	static void seek_usr_name(Bank* bank, const char* name,int usr_cnt);
	//예금 가장 많은사람 찾는 기능
	static void seek_VIP(Bank* bank, int usr_cnt);
	//등급 정하기
	int set_grade(unsigned long);
	//입금
	static void input_money(Bank* bank, const char* name, int usr_cnt);
	//출금
	static void output_money(Bank* bank, const char* name, int usr_cnt);
	//잔고 조회
	static void bank_balance(Bank* bank, const char* name, int usr_cnt);
	//계좌번호로 개인정보 조회
	static void show_info(Bank* bank, unsigned long long account_num, int usr_cnt);
	//옵션(전화번호, 집주소, 이름)에 따라서 계좌번호 조회
	static void show_account_num(Bank* bank, int option, int usr_cnt);
};

