#include "Suffix.h"

int numOfMatchedChar(string str, int start_pos, string str2)
{
	int ret=0;
	for(int i=0;i<str2.length();i++){
		if(str2[i]!=str[i+start_pos]) break;
		ret++;
	}
	return ret;
}

void addSuffix(string str, int start_pos, int suffix_label, TN *currNode){

	// checking matching child node

	bool matchedFlag = false;
	for(int i=0 ;i<currNode->childs.size(); i++){
		TN *n = currNode->childs[i];

		if(str.at(start_pos)==n->edge_label.at(0)){
			int matchedLen = numOfMatchedChar(str, start_pos, n->edge_label);
			if(matchedLen==n->edge_label.length()){
				addSuffix(str, start_pos+matchedLen, suffix_label, n);
			}
			else
			{
				// breaking the edge
				TN *newRoot = new TN(-1, str.substr(start_pos, matchedLen));
				//TN *newRoot = new TN(-1, "dummy");
				//n->updateLabel(n->edge_label.substr(start_pos+matchedLen));
				n->updateLabel(n->edge_label.substr(matchedLen));
				TN *modifiedChild = n;
				TN *newChild = new TN(suffix_label, str.substr(start_pos+matchedLen));

				newRoot->addChild(modifiedChild);
				newRoot->addChild(newChild);

				// deleting previous link and adding new link
				swap(currNode->childs[i], currNode->childs.back());
				currNode->childs.pop_back();
				currNode->addChild(newRoot);
			}
			matchedFlag = true;
			break;
		}
	}

	if(matchedFlag==false){
		currNode->addChild(new TN(suffix_label, str.substr(start_pos)));
	}

}


TN * buildTree(string str){
	TN *root = new TN();
	root->addChild(new TN(0,str));	// adding full suffix

	for(int i=1;i<str.size();i++){
		addSuffix(str, i,i,root);
	}

	return root;
}


void printSuffixes(TN *nd, string runString){
	if(nd->nodeMark>=0){
		cout<<runString<<" "<<nd->nodeMark<<endl;
	}
	for(auto n : nd->childs){
		//cout<<"This is an edge label: "<<n->edge_label<<endl;
		printSuffixes(n, runString+n->edge_label);
	}

}


int main(){
	string str = "axybxyc";
	str.append("#");

	TN *tree = buildTree(str);
	printSuffixes(tree, "");


	return 0;
}
