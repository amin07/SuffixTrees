#include "Suffix.h"


TN buildTree(string str){
	TN *root = new TN();
	root->addChild(new TN(0,str));	// adding full suffix

	for(int i=1;i<str.size();i++){

	}

	return root;
}

int main(){
	string str = "hello world here";
	str.append("#");

	cout<<str<<endl;
	return 0;
}
