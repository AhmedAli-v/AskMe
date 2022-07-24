#include "Question.h"
#include "helper.h"
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#define endl "\n"
using std::cout;
using std::cin;
using std::vector;
using std::string;
using std::ostringstream;

namespace Ask{

Question::Question():
         question_id(-1), parent_question_id(-1), from_user_id(-1), to_user_id(-1), is_anonymous_questions(1){}


Question::Question(const string &line){


vector<string> substrs = Helper::SplitString(line);
		assert(substrs.size() == 7);

		question_id = Helper::ToInt(substrs[0]);
		parent_question_id = Helper::ToInt(substrs[1]);
		from_user_id = Helper::ToInt(substrs[2]);
		to_user_id = Helper::ToInt(substrs[3]);
		is_anonymous_questions = Helper::ToInt(substrs[4]);
		question_text = substrs[5];
		answer_text = substrs[6];

}
    string Question::ToString() const {
    ostringstream oss;

    oss << question_id << "," << parent_question_id << "," << from_user_id << "," << to_user_id << "," << is_anonymous_questions << "," << question_text << "," << answer_text;

		return oss.str();

    }


void Question::PrintFromQuestion() const {
		cout << "Question Id (" << question_id << ")";
		if (!is_anonymous_questions)
			cout << " !AQ";

		cout << " to user id(" << to_user_id << ")";
		cout << "\t Question: " << question_text;

		if (answer_text != "")
			cout << "\tAnswer: " << answer_text << "\n";
		else
			cout << "\tNOT Answered YET\n";
	}
	void Question::PrintToQuestion() const {
		string prefix = "";

		if (parent_question_id != -1)
			prefix = "\tThread: ";

		cout << prefix << "Question Id (" << question_id << ")";
		if (!is_anonymous_questions)
			cout << " from user id(" << from_user_id << ")";
		cout << "\t Question: " << question_text << "\n";

		if (answer_text != "")
			cout << prefix << "\tAnswer: " << answer_text << "\n";
		cout << "\n";
	}
	void Question::PrintFeedQuestion() const {
		if (parent_question_id != -1)
			cout << "Thread Parent Question ID (" << parent_question_id << ") ";

		cout << "Question Id (" << question_id << ")";
		if (!is_anonymous_questions)
			cout << " from user id(" << from_user_id << ")";

		cout << " To user id(" << to_user_id << ")";

		cout << "\t Question: " << question_text << "\n";
		if (answer_text != "")
			cout << "\tAnswer: " << answer_text << "\n";
	}

// Setters & Getters

	const string & Question::GetAnswerText() const {
		return answer_text;
	}

	void Question::SetAnswerText(const string& answerText) {
		answer_text = answerText;
	}

	int Question::GetFromUserId() const {
		return from_user_id;
	}

	void Question::SetFromUserId(int fromUserId) {
		from_user_id = fromUserId;
	}

	int Question::GetIsAnonymousQuestions() const {
		return is_anonymous_questions;
	}

	void Question::SetIsAnonymousQuestions(int isAnonymousQuestions) {
		is_anonymous_questions = isAnonymousQuestions;
	}

	int Question::GetParentQuestionId() const {
		return parent_question_id;
	}

	void Question::SetParentQuestionId(int parentQuestionId) {
		parent_question_id = parentQuestionId;
	}

	int Question::GetQuestionId() const {
		return question_id;
	}

	void Question::SetQuestionId(int questionId) {
		question_id = questionId;
	}

	const string& Question::GetQuestionText() {
		return question_text;
	}

	void Question::SetQuestionText(const string& questionText) {
		question_text = questionText;
	}

	int Question::GetToUserId() const {
		return to_user_id;
	}

	void Question::SetToUserId(int toUserId) {
		to_user_id = toUserId;
	}

}
