#pragma once
#include "User.h"

using namespace std;

class blockGenesis {
	private:
	string blockHash;
	string timeStamp;
	int nonce;
	int version;
	int difficultyTarget;
    vector<transaction> transactionList;
	protected:

	public:
	blockGenesis() {
		nonce = fabs(rand());
		blockHash = sha256(to_string(nonce));
		time_t now = time(0);
		timeStamp = ctime(&now);
		version = 0.1;
		difficultyTarget = 0;
	}
	string getBlockHash() {
		return blockHash;
	}
	string getTimeStamp() {
		return timeStamp;
	}
	int getVersion() {
		return version;
	}
    void getTransaction(int index){
        cout << "user1: " << transactionList.at(index).getUser1PubKey() << endl;
        cout << "user2: " << transactionList.at(index).getUser2PubKey() << endl;
        cout << "amount sent from user1 to user2" << transactionList.at(index).getAmountTraded() << endl;
        cout << "time tranaction occured at: " << transactionList.at(index).getTimestamp() << endl;
    }

    vector<transaction> addTransactionToBlock(transaction transaction){
        this->transactionList.push_back(transaction);
        return this->transactionList;
    }
};

blockGenesis genesis;

class block: public blockGenesis{
    private:
    string prevBlockHash;
    protected:
    string takePrevBlockHash(block block){
        this->prevBlockHash = block.getBlockHash();
        return this->prevBlockHash;
        }
    public:
    string getPrevBlockHash(){return this->prevBlockHash;}
};
