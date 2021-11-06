#pragma once
#include <string>
#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

class user {
	protected:
		string  gen_random(int len) {
			string s;
			static const char alphanum[] =
				"0123456789"
				"ABCDEF";

			for (int i = 0; i < len; ++i) {
				s += alphanum[rand() % (sizeof(alphanum) - 1)];
			}

			return s;
		}

		string  gen_randomForName(int len) {
			string s;
			static const char alphanum[] =
				"ABCDEFGHIJKLMNOPQRSTUVWXYZ"
				"abcdefghijklmnopqrstuvwxyz";

			for (int i = 0; i < len; ++i) {
				s += alphanum[rand() % (sizeof(alphanum) - 1)];
			}

			return s;
		}

		string generatePublicKey() {
			string publicKey;

			publicKey = gen_random(16);

			return publicKey;
		}

		string generatePrivateKey() {
			string privateKey;

			privateKey = gen_random(32);

			return privateKey;
		}

		string generateName() {
			string name;

			name = gen_randomForName(8);

			return name;
		}

		void setPrivateKey(string input) { privateKey = input; }
		void setPublicKey(string input) { publicKey = input; }
		void setName(string input) { name = input; }
		void setBalance(int balance) { balance = fabs(rand() % 1000); }
	private:
		string publicKey = "";
		string name = "";
		string privateKey="";
		string getPrivateKey() { return privateKey; }
	public:
		user() {
			setPrivateKey(generatePrivateKey());
			setPublicKey(generatePublicKey());
			setName(generateName());
			setBalance(balance);
		}
		int balance;
		string getPublicKey() {
			return publicKey;
		};
		string getName() {
			return name;
		}
};

void transaction(user user1, user user2, int amountTraded, string timestamp ) {
	user1.balance= user1.balance - amountTraded;
	user2.balance = user2.balance + amountTraded;
	time_t now = time(0);
	timestamp = time(&now);
}

vector<user> generateUsers() {
	vector<user> generatedUsers;
	generatedUsers.resize(1000);
	return generatedUsers;
}