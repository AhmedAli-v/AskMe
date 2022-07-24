#ifndef QUESTIONS-MANAGER_H_INCLUDED
#define QUESTIONS-MANAGER_H_INCLUDED

#include <string>
#include <vector>
#include <map>
using namespace Ask{

class QuestionsManager {

private:
	// From question id to list of questions IDS on this question (thread questions) - All users
	map<int, vector<int>> questionid_questionidsThead_to_map;

	// Map the question id to question object. Let's keep one place ONLY with the object
	// When you study pointers, easier handling
	map<int, Question> questionid_questionobject_map;

	int last_id;
public:
	QuestionsManager();

	void LoadDatabase();

	vector<int> GetUserToQuestions(const User &user) const ;

	vector<pair<int, int>> GetUserFromQuestions(const User &user) const ;
	void PrintUserToQuestions(const User &user) const ;

	void PrintUserFromQuestions(const User &user) const;
	// Used in Answering a question for YOU.
	// It can be any of your questions (thread or not)
	int ReadQuestionIdAny(const User &user) const ;

	// Used to ask a question on a specific thread for whatever user
	int ReadQuestionIdThread(const User &user) const ;

	void AnswerQuestion(const User &user) ;

	void DeleteQuestion(const User &user);

	void AskQuestion(const User &user, const pair<int, int> &to_user_pair) ;

	void ListFeed() const;

	void UpdateDatabase() ;




};



}

#endif // QUESTIONS-MANAGER_H_INCLUDED
