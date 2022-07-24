#ifndef ASKME-SYSTEM_H_INCLUDED
#define ASKME-SYSTEM_H_INCLUDED
#include "users-manager.h"
#include "questions-manager.h"

namespace Ask {

class AskMeSystem{

private:
	UsersManager users_manager;
	QuestionsManager questions_manager;

	void LoadDatabase(bool fill_user_questions = false); //internal
    void ResetCurrentUserQuestions();

public:
    void Run();



};

}


#endif // ASKME-SYSTEM_H_INCLUDED
