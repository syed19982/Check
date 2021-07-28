//Syed Hamza Hassan
// 19i-0428

#include<iostream>
using namespace std; 


class Accountinfo {

protected: 
	int accountno; 
	int PIN;
	float accountbalance; 

public:
	Accountinfo(int accountno = 1003 , int PIN = 1234 , int accountbalance = 00 ) {
		this->accountno = accountno;
		this->accountbalance = accountbalance;
		this->PIN = PIN;
	}

	void setaccountno() {
		accountno = accountno; 
	}
	int getaccountno() {
		return accountno;
	}

	int getPIN() {
		return PIN;
	}

	void setaccountbalance() {
		accountbalance = accountbalance;
	}
	float getaccountbalance() {
		return accountbalance;
	}

	
	void setPIN() {
		PIN = PIN;
	}

	void Display() {

		cout << "Your Account Number :" << getaccountno() << endl;
		cout << "Your Account Balance :" << getaccountbalance() << endl;

	}

		
};

class Deposit :public Accountinfo  {
private:
	double Damount;
public:
	Deposit() {
		Damount = 0;
	}
	Deposit(int accountno, int PIN, int accountbalance, double Damount = 0) : Accountinfo(accountno, PIN, accountbalance) {
		while (1) {

			if (Damount > 0) {
				this->Damount = Damount;
				this->accountbalance = accountbalance + Damount;
			}
			else
				cout << "Wrong input try again" << endl;
		}
	}


	void setDamount(double Dcash) {
		Damount = Dcash;
	}

	double getDamount() {
		return Damount; 
	}
	
	void Display(){ 
	
		cout << "Your Account Number :"  << getaccountno() << endl ; 
		cout << "Your Account Balance :" << getaccountbalance() <<endl;
	
	}


};


class Withdraw : public Accountinfo {

private:
	int Wamount;
public:
	Withdraw() {
		Wamount = 0;
	}

	Withdraw(int accountno , int PIN, int accountbalance, int Wamount = 0) : Accountinfo(accountno, PIN, accountbalance) {
		this->Wamount = Wamount;
		this->accountbalance = accountbalance - Wamount; 

	}

	void setWithdraw(int Wcash) {
		Wcash = Wamount;
	}
	int getWithdraw() {
		return Wamount; 
	}


	bool Balancelimit() {
		if (Wamount > getaccountbalance()) {
			cout << "Withdraw amount is greater than account balance: " << endl;
			return false;
		}
		else
			return true;
	}

	void Display() {

		cout << "Your Account Number :" << getaccountno() << endl;
		cout << "Your Account Balance :" << getaccountbalance() << endl;

	}


};

/*
class ATMlimit : public Withdraw, Accountinfo {

};
*/





class Menu : public Accountinfo , public Withdraw , public Deposit {
private:
	int select;
public:
	Menu(int select = 0) {
		this->select = select;
	}

	
	int Display() {
		cout << "If you want to know your Account Info then please press 1: " << endl <<
			"If you want to Deposit in your Account please press 2: " << endl <<
			"If you want to Withdraw cash then please press 3: " << endl <<
			"If you want to Exit please press 0 " << endl;

		int select = 0;
		cin >> select;

		return select;
	}

};


int main() {
	int select = 0;

	while (1) {
		
		int Acc;
		cout << "Please Enter your account no. and the pin respectively: " << endl;
		cin >> Acc;
		//file handling 

		//check account and pin here
		Menu m(select); 
		select = m.Display();

		if (select == 0) {
			cout << "Goodbye" << endl;
			break;
		}

		else if (select == 1) {
			cout << "You selected account info : " << endl;
			Accountinfo A(Acc,1234, 50000);
			A.Display();
		
		}

		
		else if (select == 2) {
			cout << "You selected deposit : " << endl;
			Deposit D(Acc, 1234, 50000, 500); 
			D.Display();

		}

		else if (select == 3) {
			bool check = false;

			Withdraw W(Acc, 1234, 50000, 400);
			check = W.Balancelimit();
			if (check == true) {
				W.Display();

			}
			else {}

		}

		//cout << endl <<D.getDamount();

	}



	
	return 0;
}