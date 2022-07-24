#ifndef QUESTION_H_INCLUDED
#define QUESTION_H_INCLUDED



using namespace Ask {
class Question {
private:
    int question_id;
	// To support thread. Each question look to a parent question
	// -1 No parent (first question in the thread)
	int parent_question_id;
	int from_user_id;
	int to_user_id;
	int is_anonymous_questions;	// 0 or 1
	string question_text;
	string answer_text;			// empty = not answered
public:
    Question();

    Question(const string &line);

    string ToString() const;
    // Printing
    void PrintToQuestion() const;
    void PrintFromQuestion() const;
    void PrintFeedQuestion() const
    // Setters and Getters
    const string& GetAnswerText() const;
    void SetAnswerText(const string& answerText);
    int GetFromUserId() const;
    void SetFromUserId(int fromUserId);
    int GetIsAnonymousQuestions() const;
    void SetIsAnonymousQuestions(int isAnonymousQuestions);
    int GetParentQuestionId() const;
    void SetParentQuestionId(int parentQuestionId);
    int GetQuestionId() const ;
    void SetQuestionId(int questionId) ;
    const string& GetQuestionText() const;
    void SetQuestionText(const string& questionText);
    int GetToUserId() const;
    void SetToUserId(int toUserId);

};

}

#endif // QUESTION_H_INCLUDED
