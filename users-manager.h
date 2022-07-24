#ifndef USERS-MANAGER_H_INCLUDED
#define USERS-MANAGER_H_INCLUDED
#include "User.h"
#include "Question.h"
#include <map>
#include <vector>
namespace Ask {

class UsersManager{

private:
	map<string, User> userame_userobject_map;
	User current_user;
	int last_id;
public:
	UsersManager() ;

	void LoadDatabase() ;

	void AccessSystem() ;

	void DoLogin() ;

	void DoSignUp() ;

	void ResetToQuestions(const vector<int> &to_questions);
	void ResetFromQuestions(const vector<pair<int, int>> &to_questions);

	void ListUsersNamesIds() const ;

	pair<int, int> ReadUserId() const;

	void UpdateDatabase(const User &user);

	const User& GetCurrentUser() const;



};


}

#endif // USERS-MANAGER_H_INCLUDED
