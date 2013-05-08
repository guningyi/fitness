#include<vector>
#include<list>
#include<utility>
#include<map>
#include<iostream>

using namespace std;

int main(int argc, char **argv)
{
    map< vector<int>::iterator, int > imap1;
    map< list<int>::iterator, int > imap2;
    map< pair<int, string>, int > imap3;
    return 0;
} 
