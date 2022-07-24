#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include <string>
#include <vector>
#include <map>

using namespace Ask{
Class User {
private:
    int user_id;		// internal system ID
	string user_name;
	string password;
	string name;
	string email;
	int allow_anonymous_questions;	// 0 or 1
   vector<int> questions_id_from_me;
	// From question id to list of questions IDS on this question (thread questions) - For this user
	map<int, vector<int>> questionid_questionidsThead_to_map;

public:
    User();
    User(const string &line);
    string ToString() const;
    void Print() const;
    void ResetToQuestions(const vector<int> &to_questions);
    void ResetFromQuestions(const vector<pair<int, int>> &to_questions) ;
    void ReadUser(const string &user_name, int id);
    int IsAllowAnonymousQuestions() const;
    void SetAllowAnonymousQuestions(int allowAnonymousQuestions);
    const string& GetEmail() const;
    void SetEmail(const string& email;
    const string& GetName() const ;
	void SetName(const string& name) ;
	const string& GetPassword() const ;
	void SetPassword(const string& password) ;
	int GetUserId() const ;
	void SetUserId(int userId);
	const string& GetUserName() const ;
	void SetUserName(const string& userName);
	const map<int, vector<int> >& GetQuestionidQuestionidsTheadToMap() const;
	const vector<int>& GetQuestionsIdFromMe() const;


};

}
#endif // USER_H_INCLUDED
