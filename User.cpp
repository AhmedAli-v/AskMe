#include "User.h"

using std::cin;
using std::cout;
using namespace Ask{

	User::User() :
			user_id(-1), allow_anonymous_questions(-1) {
	}

	User::User(const string &line) {
		vector<string> substrs = SplitString(line);
		assert(substrs.size() == 6);

		user_id = ToInt(substrs[0]);
		user_name = substrs[1];
		password = substrs[2];
		name = substrs[3];
		email = substrs[4];
		allow_anonymous_questions = ToInt(substrs[5]);
	}

	string User::ToString() const {
		ostringstream oss;
		oss << user_id << "," << user_name << "," << password << "," << name << "," << email << "," << allow_anonymous_questions;

		return oss.str();
	}

	void User::Print() const {
		cout << "User " << user_id << ", " << user_name << " " << password << ", " << name << ", " << email << "\n";
	}

	void User::ResetToQuestions(const vector<int> &to_questions) {
		questions_id_from_me.clear();

		for (const auto & question_id : to_questions)
			questions_id_from_me.push_back(question_id);
	}
	void User::ResetFromQuestions(const vector<pair<int, int>> &to_questions) {
		questionid_questionidsThead_to_map.clear();

		for (const auto & id_pair : to_questions)
			questionid_questionidsThead_to_map[id_pair.first].push_back(id_pair.second);
	}

	void User::ReadUser(const string &user_name, int id) {
		SetUserName(user_name);
		SetUserId(id);

		string str;

		cout << "Enter password: ";
		cin >> str;
		SetPassword(str);

		cout << "Enter name: ";
		cin >> str;
		SetName(str);

		cout << "Enter email: ";
		cin >> str;
		SetEmail(str);

		cout << "Allow anonymous questions? (0 or 1): ";
		int st;
		cin >> st;
		SetAllowAnonymousQuestions(st);
	}

	int User::IsAllowAnonymousQuestions() const {
		return allow_anonymous_questions;
	}

	void User::SetAllowAnonymousQuestions(int allowAnonymousQuestions) {
		allow_anonymous_questions = allowAnonymousQuestions;
	}

	const string& User::GetEmail() const {
		return email;
	}

	void User::SetEmail(const string& email) {
		this->email = email;
	}

	const string& User::GetName() const {
		return name;
	}

	void User::SetName(const string& name) {
		this->name = name;
	}

	const string& User::GetPassword() const {
		return password;
	}

	void User::SetPassword(const string& password) {
		this->password = password;
	}

	int User::GetUserId() const {
		return user_id;
	}

	void User::SetUserId(int userId) {
		user_id = userId;
	}

	const string& User::GetUserName() const {
		return user_name;
	}

	void User::SetUserName(const string& userName) {
		user_name = userName;
	}

	const map<int, vector<int> >& User::GetQuestionidQuestionidsTheadToMap() const {
		return questionid_questionidsThead_to_map;
		// Note no setter is provided / returned as const &
	}

	const vector<int>& User::GetQuestionsIdFromMe() const {
		return questions_id_from_me;
		// Note no setter is provided
	}



}
