// ATM system.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#pragma warning (disable : 4996)
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "Lab.h";

using namespace std;
string ClientDataBase = "../../DataBase/Clients.txt";
void MainSystemPrint();
void Login();

// Extntion Functios
void GoBackToMainScreen() {
	cout << "Please type any key to go back ... \n";
	system("pause>0");
	MainSystemPrint();
}
bool CheakAcc() {
	if (TempInfo.Status == "Disabled")
		return 0;
	return 1;
}
void PrintDisabledAccount() {
	system("cls");
	cout << "================================\n";
	cout << "\t Your account is disabled\n\tPleas contact the Support \n";
	cout << "================================\n";
	cout << "\n Press any key to go back... ";
	system("pause>0");
	Login();
}


// ATMMain PagesFunctionScreens
void FastWithdrawScreen() {
	system("cls");
	cout << "\n------------------------------------------\n";
	cout << "\t\t Fast Withdraw ";
	cout << "\n------------------------------------------\n";
	cout << "[1] 20     [2] 50\n";
	cout << "[3] 100    [4] 200\n";
	cout << "[5] 400    [6] 600\n";
	cout << "[7] 800    [8] 1000\n";
	cout << "[9] Exite\n";
	cout << "\n------------------------------------------\n";

}
void FastWithDraw() {
	FastWithdrawScreen();
	short Ammount = ReadeNum("Enter the amount [1 | 8 ]: ");
	switch (Ammount)
	{
	        case 1: 
			Withdraw(20, TempInfo.AccountNumber);
			break;
			case 2: 
			Withdraw(50, TempInfo.AccountNumber);
			break;
			case 3: 
			Withdraw(100, TempInfo.AccountNumber);
			break;
			case 4: 
				Withdraw(200, TempInfo.AccountNumber);
			    break;
			case 5: 
			Withdraw(400, TempInfo.AccountNumber);
			break;
			case 6: 
			Withdraw(600, TempInfo.AccountNumber);
			break;
			case 7: 
			Withdraw(800, TempInfo.AccountNumber);
			break;
			case 8: 
			Withdraw(1000, TempInfo.AccountNumber);
			break;
			case 9:
			MainSystemPrint();
	default:
		FastWithDraw();
		break;
	}
	GoBackToMainScreen();
}
void NormalWithDrawScreen() {
	short amoun = 0;
	do {
		system("cls");
		cout << "-----------------------------------\n";
		cout << "\t\t Normal withdraw \n";
		cout << "-----------------------------------\n";
		short amoun = ReadeNum("Enter the amount (should be 5'): ");
	} while (amoun % 5 != 0);

	Withdraw(amoun, TempInfo.AccountNumber);
	GoBackToMainScreen();
}
void DepositeScreen() {
	system("cls");
	cout << "-----------------------------------\n";
	cout << "\t\t Deposite (-0.30$ as Fee)\n";
	cout << "-----------------------------------\n";
	short amoun = ReadeNum("Enter the amount to deposite: ");
	Deposite(amoun, TempInfo.AccountNumber);
	GoBackToMainScreen();
}
void CheackBalanceScreen() {
	system("cls");
	cout << "------------------------------\n";
	cout << "\t\t Cheack Balance \n";
	cout << "------------------------------\n";
	cout << "\nYour balance is: " << TempInfo.Balance << "\n\n";
	GoBackToMainScreen();
}
// Profile Functions
void SeeClientInfo() {
	cout << "---------------------------------\n";
	cout << " \t Account Inforamtion \n";
	cout << "---------------------------------\n";
	cout << "Name: " << TempInfo.Name << endl;
	cout << "PinCode: " << TempInfo.PinCode << endl;
	cout << "PhoneNumber: " << TempInfo.PhoneNumber << endl;
	cout << "Date Creation: " << FormateDate(TempInfo.DateCreating, "dd | mm | yyyy ") << endl;
	cout << "Status: " << TempInfo.Status << ", Date: " << NullDateCheak(TempInfo.DateDisabled) << endl;
	cout << "---------------------------------\n";


}
void ChangeInfo() {
	system("cls");
	cout << "-----------------------------------\n";
	cout << "\t\t Change Account information \n";
	cout << "-----------------------------------\n";

	char ToChange = 'y';
	cout << "Do tou wanna change your PinCode: ";
	cin >> ToChange;
	if (tolower(ToChange) == 'y') {
		TempInfo.PinCode = ReadText("Enter a new PinCode: ");
		
	}
	cout << "Do tou wanna change your PhoneNumber: ";
	cin >> ToChange;
	if (tolower(ToChange) == 'y') {
		TempInfo.PhoneNumber = ReadText("Enter a new PhoneNumber: ");
		/*vector <stBankInfo> vClients = FetchingFromTheFile(ClientDataBase);
		for (stBankInfo &client : vClients) {
			if (client.AccountNumber == TempInfo.AccountNumber) {

			}
		}*/
	}
	vector <stBankInfo> vClients = FetchingFromTheFile(ClientDataBase);
		for (stBankInfo &client : vClients) {
			if (client.AccountNumber == TempInfo.AccountNumber) {
				client = TempInfo;
				break;
			}
		}
	    UpdateTheFile(vClients);
		cout << "Sucessfuly updated your account Legali ... \n\n";
		GoBackToMainScreen();
}
void ReportIngPage() {
	system("cls");
	cout << "=======================================\n";
	cout << "\t\t Do you have an Issue? \n";
	cout << "=======================================\n";

	string text = ReadText("Type you Problem please: \n");
	cout << "Success!, your message sent to the Admin, We will answer soon, <Thank you for your Paisent>";
}

enum enProfileMenue {eSeeInfo = 1, eChangePin = 2, eReport = 3, eTransctionHis = 4, eCloseAccount= 5};
void PerformProfileFun(enProfileMenue Choice) {
	switch (Choice )
	{
	case eSeeInfo:
		system("cls");
		SeeClientInfo();
		break;
	case eChangePin:
		ChangeInfo();
		break;
	case eReport:
		ReportIngPage();
		break;
	case eTransctionHis:
		break;
	case eCloseAccount:
		break;
	default:
		break;
	}
}
void Profile() {
	system("cls");
	cout << "-----------------------------------\n";
	cout << "\t\t Profile \n";
	cout << "-----------------------------------\n";
	cout << "[1] Account INFO\n";
	cout << "[2] Change Account Information\n";
	cout << "[3] Report a problem/spam\n";
	cout << "[4] Transaction History\n";
	cout << "[5] Close the account\n";
	cout << "------------------------------------\n";
	PerformProfileFun(enProfileMenue(ReadeNum("Enter the choice: ")));
}


enum enATMchoices {eFastWithDraw = 1, eNormalWithdraw = 2, eDeposite = 3, eCheackBalance = 4, eProfile = 5, eLogOut = 6};
void HandlUserInputFn(enATMchoices choice) {
	switch (choice)
	{
	case eFastWithDraw:
		FastWithDraw();
		break;
	case eNormalWithdraw:
		NormalWithDrawScreen();
		break;
	case eDeposite:
		DepositeScreen();
		break;
	case eCheackBalance:
		CheackBalanceScreen();
		break;
	case eProfile:
		Profile();
		break;
	case eLogOut:
		break;
	default:
		break;
	}
}
short ReadeNum() {
	short num;
	cout << "Enter Your choice please: ";
	cin >> num;
	return num;
}
void MainSystemPrint() {
	system("cls");
	cout << "_________________________________________________\n";
	cout << "\n\t\t Main menue page \t\t";
	cout << "\n_________________________________________________\n\n";
	cout << "\t\t [1] Fast Withdraw.\n";
	cout << "\t\t [2] Normal Withdraw.\n";
	cout << "\t\t [3] Deposite.\n";
	cout << "\t\t [4] Cheack Balance.\n";
	cout << "\t\t [5] Profile.\n";
	cout << "\t\t [6] Logout.\n";
	cout << "\n_________________________________________________\n\n";
	HandlUserInputFn(enATMchoices(ReadeNum()));
}
bool HandlLogin() {
	string AccountNum = ReadText("Enter account number: ");
	string PinCode = ReadText("Enter PinCode: ");
	vector <stBankInfo> vClients = FetchingFromTheFile(ClientDataBase);
	for (stBankInfo client : vClients) {
		if (client.AccountNumber == AccountNum && client.PinCode == PinCode) {
			TempInfo = client;
			return 1;
		}
			
	}
	return 0;
}
void Login() {
	bool HandlingStaus = true;
	do
	{
		
		system("cls");
		cout << "\n-----------------------------------\n";
		cout << "\t\t Login \n";
		cout << "-----------------------------------\n";

		
		if (!HandlingStaus) {
			
			cout << "\nInvalid Account! \n";
		}
        HandlingStaus = HandlLogin();
	} while (!HandlingStaus);
	if (CheakAcc()) {
	  MainSystemPrint();
	} else {
		PrintDisabledAccount();
	}
	
}

int main()
{
	Login();
	system("pause>0");
}
