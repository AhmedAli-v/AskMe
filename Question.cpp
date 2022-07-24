#include "Question.h"
#include <iostream>
#include <sstream>
#include <string>

using namespace Ask{

Question::Question():
         question_id(-1), parent_question_id(-1), from_user_id(-1), to_user_id(-1), is_anonymous_questions(1){}


Question::Question(const string &line){


vector<string> substrs = SplitString(line);
		assert(substrs.size() == 7);

		question_id = ToInt(substrs[0]);
		parent_question_id = ToInt(substrs[1]);
		from_user_id = ToInt(substrs[2]);
		to_user_id = ToInt(substrs[3]);
		is_anonymous_questions = ToInt(substrs[4]);
		question_text = substrs[5];
		answer_text = substrs[6];

}
          string Question::ToString() const {
    ostringstream oss;

    sprintf(oss,"%d , %d , %d , %d , %d , %s ,%s",GetQuestionId(),GetParentQuestionId(),GetFromUserId(),GetToUserId(),GetIsAnonymousQuestions(),GetQuestionText(),GetAnswerText());

    return oss.str();

    }


void Question::PrintFromQuestion() const {
		cout << "Question Id (" << GetQuestionId() << ")";
		if (!is_anonymous_questions)
			cout << " !AQ";

		cout << " to user id(" << GetToUserId() << ")";
		cout << "\t Question: " << GetQuestionText();

		if (answer_text != "")
			cout << "\tAnswer: " << GetAnswerText() << "\n";
		else
			cout << "\tNOT Answered YET\n";
	}
	void Question::PrintToQuestion() const {
		string prefix = "";

		if (GetParentQuestionId() != -1)
			prefix = "\tThread: ";

		cout << prefix << "Question Id (" << GetQuestionId() << ")";
		if (!GetIsAnonymousQuestions())
			cout << " from user id(" << GetFromUserId() << ")";
		cout << "\t Question: " << GetQuestionText() << "\n";

		if (answer_text != "")
			cout << prefix << "\tAnswer: " << GetAnswerText() << "\n";
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

	const string& Question::GetAnswerText() const {
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

	const string& Question::GetQuestionText() const {
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
