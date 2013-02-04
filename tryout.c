#include <check.h>
#include <stdlib.h>

START_TEST(this_is_a_test_case)
{
	fail_unless(1);
}
END_TEST

Suite *test_suite()
{
	Suite *s = suite_create("Test");
	TCase *tc_core = tcase_create("Core");
	tcase_add_test(tc_core, this_is_a_test_case);

	suite_add_tcase(s, tc_core);
	return s;
}

int main()
{
	Suite *suite = test_suite();
	SRunner *sr = srunner_create(suite);
	srunner_set_xml(sr, "xml_log.txt");
	srunner_run_all(sr, CK_NORMAL);
	int tests_failed = srunner_ntests_failed(sr);
	srunner_free(sr);
	return (tests_failed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}