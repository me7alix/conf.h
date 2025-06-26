#define CONF_IMPLEMENTATION
#include "../src/conf.h"

int main() {
	Conf conf = conf_parse("./demo/test.conf");

	char *question, *answer;
	float float_num;
	int int_num;

	for (size_t i = 0; i < conf.count; i++) {
		if (!strcmp(conf.keys[i], "QUESTION")) {
			question = conf.values[i];
		} else if (!strcmp(conf.keys[i], "ANSWER")) {
			answer = conf.values[i];
		} else if (!strcmp(conf.keys[i], "INTEGER_NUM")) {
			int_num = atoi(conf.values[i]);
		} else if (!strcmp(conf.keys[i], "FLOAT_NUM")) {
			float_num = atof(conf.values[i]);
		}
	}

	printf("QUESTION = %s\n", question);
	printf("ANSWER = %s\n", answer);
	printf("INTEGER_NUM = %i\n", int_num);
	printf("FLOAT_NUM = %f\n", float_num);

	conf_free(conf);
	return 0;
}
