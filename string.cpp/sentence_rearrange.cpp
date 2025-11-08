#include <bits/stdc++.h> 
using namespace std;


// Given a list of sentences, each starting with an identifier followed by words:
// Sentences where the words contain letters are called letter-sentences.
// Sentences where the words contain digits are called number-sentences.
// Reorder the sentences so that:
// All letter-sentences come before number-sentences.
// Letter-sentences are sorted lexicographically by their content (and by identifier if tied).
// Number-sentences keep their original order.

vector<string> reOrderSentences(vector<string> sentences)
{
	stable_sort(sentences.begin(),sentences.end(),[](const string &a,const string &b){
		stringstream sa(a),sb(b);
		string idA,idB,restA,restB;
		sa>>idA;
		sb>>idB;
		getline(sa,restA);
		getline(sb,restB);
		if(!restA.empty() && restA[0]==' ') restA=restA.substr(1);
		if(!restB.empty() && restB[0]==' ') restB=restB.substr(1);
		bool numA=!restA.empty() && isdigit(restA[0]);
		bool numB=!restB.empty() && isdigit(restB[0]);
		if(numA!=numB) return !numA;
		if(!numA && !numB){
			if(restA==restB)
				return idA<idB;
			return restA<restB;
		}
		return false;
	});
	return sentences;
}

int main(){
    int n;
    cout << "Enter number of sentences: ";
    cin >> n;

    vector<string> sentences(n);
    cout << "Enter sentences: ";
    for (int i = 0; i < n; i++) {
        getline(cin, sentences[i]);
    }

    vector<string> result = reOrderSentences(sentences);

    cout << "\nReordered sentences:";
    for (string &s : result)
        cout << s << "\n";
}