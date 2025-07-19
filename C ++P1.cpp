
#include <iostream>
#include <vector>
#include <iomanip>
#include "cls_util.h"
#include "cls_input_validate.h"
#include "cls_login_screen.h"
#include "cls_login_register_screen.h"
#include "cls_user.h"


using namespace std;








int main()
{

	while (bool tf = true) {
		if (!cls_login_screen::show_login_screen()) {
			break;
		}
	}

	return 0;
}

