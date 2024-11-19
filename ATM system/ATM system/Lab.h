#pragma once

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;	
string FileName = "../../DataBase/Clients.txt";

namespace std {
	struct stDate {
		short Year;
		short Mounth;
		short Day;
	};
	stDate DateOfNow() {
		stDate date;
		time_t t = time(0);
		tm* now = localtime(&t);
		date.Year = now->tm_year + 1900;
		date.Mounth = now->tm_mon + 1;
		date.Day = now->tm_mday;
		return date;
	}
	string ReadText(string textDef) {
		string text = "";
		cout << "\n" << textDef;
		getline(cin >> ws, text);
		return text;
	}
	int ReadeNum(string text) {
		int num = 0;
		cout << "\n" << text;
		cin >> num;
		return num;
	}
	struct stBankInfo {
		string AccountNumber;
		string Name;
		string PinCode;
		string PhoneNumber;
		double Balance;
		stDate DateCreating;
		stDate DateDisabled;
		string Status;
		string authkey;
	};
	stBankInfo TempInfo;

	void PrintTheRecord(stBankInfo ClientInfo) {
		cout << " Account number     :  " << ClientInfo.AccountNumber << "\n";
		cout << " The name           :  " << ClientInfo.Name << "\n";
		cout << " The Pincode        :  " << ClientInfo.PinCode << "\n";
		cout << " The PhoneNumber    :  " << ClientInfo.PhoneNumber << "\n";
		cout << " Account Balance    :  " << int(ClientInfo.Balance) << "\n";
	}
	void PrintTheInfos(stBankInfo Client) {
		cout << "| " << setw(16) << left << Client.AccountNumber;
		cout << "| " << setw(15) << left << Client.PinCode;
		cout << "| " << setw(35) << left << Client.Name;
		cout << "| " << setw(15) << left << Client.PhoneNumber;
		cout << "| " << Client.Balance << setw(15) << left << "$";
	}

	vector <string> SplitTheWords(string text, string dilmet) {
		vector <string> vTokens;
		short pos = 0;
		string sWord = "";
		while ((pos = text.find(dilmet)) != std::string::npos) {
			sWord = text.substr(0, pos);
			//cout << sWord << "\n";
			if (sWord != "") {


				vTokens.push_back(sWord);

			}
			text.erase(0, pos + dilmet.length());
		}
		if (text != "") {


			vTokens.push_back(text);

		}
		return vTokens;
	}
	stDate ConvetStringDateToStruct(string text) {
		vector <string> vDate = SplitTheWords(text, "/");
		stDate d;
		d.Day = stoi(vDate[0]);
		d.Mounth = stoi(vDate.at(1));
		d.Year = stoi(vDate.at(2));
		return d;
	}
	string ReplaceRecoredInStringS(string s, string toRplace, string replacment) {
		short pos = s.find(toRplace);
		while (pos != std::string::npos) {
			s.replace(pos, toRplace.length(), replacment);
			pos = s.find(toRplace);
		}
		return s;
	}
	string FormateDate(stDate d, string date = "dd/mm/yyyy") {
		string StringDateFormated = "";
		StringDateFormated = ReplaceRecoredInStringS(date, "dd", to_string(d.Day));
		StringDateFormated = ReplaceRecoredInStringS(StringDateFormated, "mm", to_string(d.Mounth));
		StringDateFormated = ReplaceRecoredInStringS(StringDateFormated, "yyyy", to_string(d.Year));
		return StringDateFormated;
	}
	stDate NullDate() {
		stDate date;
		date.Day = NULL;
		date.Mounth = NULL;
		date.Year = NULL;
		return date;
	}
	string NullDateCheak(stDate date) {
		if (date.Year == NULL)
			return "NotDisabled";
		else
			return FormateDate(date);
	}
	stDate NullDateCheak(string Condition) {
		if (Condition == "NotDisabled")
			return NullDate();
		else
			return ConvetStringDateToStruct(Condition);
	}
	string HashingClientRecord(stBankInfo BankClinet, string seprator = "#//#") {
		return BankClinet.AccountNumber + seprator + BankClinet.Name + seprator + BankClinet.PinCode + seprator + BankClinet.PhoneNumber + seprator + to_string(BankClinet.Balance) + seprator + FormateDate(BankClinet.DateCreating) + seprator + BankClinet.Status + seprator + NullDateCheak(BankClinet.DateDisabled) + seprator + BankClinet.authkey;
	}
	stBankInfo UnHashingClientRecord(string text, string Sperator = "#//#") {
		vector <string> vClientInfo = SplitTheWords(text, Sperator);
		stBankInfo ClintInfo;
		ClintInfo.AccountNumber = vClientInfo.at(0);
		ClintInfo.Name = vClientInfo.at(1);
		ClintInfo.PinCode = vClientInfo.at(2);
		ClintInfo.PhoneNumber = vClientInfo.at(3);
		ClintInfo.Balance = stoi(vClientInfo.at(4));
		ClintInfo.DateCreating = ConvetStringDateToStruct(vClientInfo[5]);
		ClintInfo.Status = vClientInfo[6];
		ClintInfo.DateDisabled = NullDateCheak(vClientInfo[7]);
		ClintInfo.authkey = vClientInfo[8];
		return ClintInfo;
	}
	vector <stBankInfo> FetchingFromTheFile(string CFileName) {
		vector <stBankInfo> vClients;
		//vClients.clear();
		fstream ClientFile;
		ClientFile.open(CFileName, ios::in);
		if (ClientFile.is_open()) {
			string line = "";
			while (getline(ClientFile, line)) {
				stBankInfo ClientInfo = UnHashingClientRecord(line);
				vClients.push_back(ClientInfo);
			}
		}
		return vClients;
	}
	void ShowTheClientsData() {
		vector <stBankInfo> vOfBanks = FetchingFromTheFile(FileName);
		//vOfBanks.clear();
		cout << "\t\t\t\tClient List : (" << vOfBanks.size() << ") Client(s) \t\t\t\t " << setw(14) << endl;
		cout << "--------------------------------------------------------------------------------------------\n";
		cout << "| " << setw(16) << left << " Account Number ";
		cout << "| " << setw(15) << left << " PIN Code";
		cout << "| " << setw(35) << left << " Client Name";
		cout << "| " << setw(15) << left << " Phone Number";
		cout << "| " << setw(15) << left << " Date Existe";
		cout << "| " << setw(15) << left << " Balance";
		cout << "\n--------------------------------------------------------------------------------------------\n";
		for (stBankInfo Client : vOfBanks) {
			PrintTheInfos(Client);
			cout << endl;
		}
		cout << "\n--------------------------------------------------------------------------------------------\n";

	}
	bool SearchForCLient(string AN, stBankInfo& sClient) {
		vector <stBankInfo> AllClients = FetchingFromTheFile(FileName);
		for (stBankInfo Client : AllClients) {
			if (Client.AccountNumber == AN) {
				sClient = Client;
				return true;
			}
		}
		return false;
	}
	void UpdateTheFile(vector <stBankInfo> AllClients) {
		fstream FileCLient;
		FileCLient.open(FileName, ios::out);
		if (FileCLient.is_open()) {
			string line = "";
			for (stBankInfo Client : AllClients) {
				if (Client.AccountNumber != "") {
					line = HashingClientRecord(Client);
					FileCLient << line << endl;
				}
			}

		}

	}
	bool FindTheClient(string& AN) {
		stBankInfo sClient;
		AN = ReadText("Please enter the account number for search: ");

		if (SearchForCLient(AN, sClient)) {
			cout << "\n The Client you search about: \n\n";
			PrintTheRecord(sClient);
			return true;
		}
		else {
			cout << "\nSorry we couldn't finde the Client with Account number (" << AN << ").\n";
			return false;
		}
		cout << "\nPress any key to go back to menu page...";

		system("pause");

	}
	void FindAClient() {

		stBankInfo sClient;
		string AN = ReadText("Please enter the account number for search: ");

		if (SearchForCLient(AN, sClient)) {
			cout << "\n The Client you search about: \n\n";
			PrintTheRecord(sClient);
			//return true;
		}
		else {
			cout << "\nSorry we couldn't finde the Client with Account number (" << AN << ").\n";
			//return false;
		}

	}
	void DeletTheClient() {
		cout << "_________________________________________________\n";
		cout << "\n\t\t Delete CLIENT page \t\t";
		cout << "\n_________________________________________________\n\n";
		string AN;
		if (FindTheClient(AN)) {
			vector <stBankInfo> AllClients = FetchingFromTheFile(FileName);
			cout << "\n\nAre you sure u wanna delete this client y/n: ";
			char Access = 'n';
			cin >> Access;
			if (tolower(Access) == 'y') {
				for (stBankInfo& Client : AllClients) {
					if (Client.AccountNumber == AN)
						Client.AccountNumber = "";
				}
				UpdateTheFile(AllClients);
				cout << "\nDeleted successfly!\n\n";
			}
		}

	}
	stBankInfo UpdateInfo(string AN) {
		stBankInfo BanksInfo;
		BanksInfo.AccountNumber = AN;
		BanksInfo.Name = ReadText("Please enter ur name: ");
		BanksInfo.PinCode = ReadText("Please enter ur PIN: ");
		BanksInfo.PhoneNumber = ReadText("Please enter ur Phone Nnumber: ");
		BanksInfo.Balance = ReadeNum("PLease enter how much u wanna Diposite: ");
		return BanksInfo;
	}
	void UpdateTheClientByAN(string AN) {
		vector <stBankInfo> vAllClients = FetchingFromTheFile(FileName);
		for (stBankInfo& Client : vAllClients) {
			if (AN == Client.AccountNumber) {

				Client = UpdateInfo(AN);
				break;
			}
		}
		UpdateTheFile(vAllClients);
		cout << "\nThe client updated succesfly!\n";
	}
	void UpdateTheClient() {
		cout << "_________________________________________________\n";
		cout << "\n\t\t Update CLIENT page \t\t";
		cout << "\n_________________________________________________\n\n";
		string AN;
		if (FindTheClient(AN)) {
			cout << "\n\nAre u sure u wanna update the client : ";
			char Access = 'n';
			cin >> Access;
			if (tolower(Access) == 'y') {
				UpdateTheClientByAN(AN);
			}
		}

	}
	int MoneyTransfer(string& AN) {

		int amount = 0;
		if (FindTheClient(AN)) {
			cout << "PLease enter the Amount: ";
			cin >> amount;
			return amount;
		}
	}
	void Deposite(int amount,string AN) {
		vector <stBankInfo> vClients = FetchingFromTheFile(FileName);
		for (stBankInfo& Client : vClients) {

			if (Client.AccountNumber == AN) {
				Client.Balance = Client.Balance + (amount-0.30);
				TempInfo = Client;
				break;
			}
		}
		cout << "\nSuccesfly!, Deposite " << (amount - 0.30) << "$ to your account.";
		UpdateTheFile(vClients);
	}
	void Withdraw(int amount, string AN) {
		vector <stBankInfo> vClients = FetchingFromTheFile(FileName);
		for (stBankInfo& Client : vClients) {
			if (Client.AccountNumber == AN) {

				if (Client.Balance > amount) {
					Client.Balance = Client.Balance - (amount + 0.30);
					cout << "\nSuccesfly!, Withdraw " << amount << "$ + (0.30$ as fee) from your account .";
					TempInfo = Client;
					break;
				}
				else {
					cout << "Sorry, your account is insult, max to withdrwa is " << Client.Balance << "$.";
				}
			}
		}
		UpdateTheFile(vClients);

	}
}
