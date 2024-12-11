#include <check.h>
#include "wordle.h"

void check_arr_eq(const int* ans, const int* guess)
{
	for(int i = 0; i < LEN_WORDS; ++i)
	{
		ck_assert_int_eq(ans[i], guess[i]);
	}
}

#suite WordsComparison
#tcase ZeroCommonLetter
#test True_aaaaa_Guess_fffff

	int answer_num[LEN_WORDS], guess_num[LEN_WORDS];
	int answer_num_true[LEN_WORDS] = {BLACK_LETTER, BLACK_LETTER, BLACK_LETTER, BLACK_LETTER, BLACK_LETTER};
	int guess_num_true[LEN_WORDS] = {BLACK_LETTER, BLACK_LETTER, BLACK_LETTER, BLACK_LETTER, BLACK_LETTER};
	char answer[LEN_WORDS + 1] = "aaaaa", guess[LEN_WORDS + 1] = "fffff";

	Fill_difference(answer, guess, answer_num, guess_num);

	check_arr_eq(answer_num, answer_num_true);
	check_arr_eq(guess_num, guess_num_true);

#tcase OneCommonLetterGreen
#test True_aafaa_Guess_fffff

	int answer_num[LEN_WORDS], guess_num[LEN_WORDS];
	int answer_num_true[LEN_WORDS] = {BLACK_LETTER, BLACK_LETTER, GREEN_LETTER, BLACK_LETTER, BLACK_LETTER};
	int guess_num_true[LEN_WORDS] = {BLACK_LETTER, BLACK_LETTER, GREEN_LETTER, BLACK_LETTER, BLACK_LETTER};
	char answer[LEN_WORDS + 1] = "aafaa", guess[LEN_WORDS + 1] = "fffff";

	Fill_difference(answer, guess, answer_num, guess_num);

	check_arr_eq(answer_num, answer_num_true);
	check_arr_eq(guess_num, guess_num_true);

#tcase OneCommonLetterYellow
#test True_apaaa_Guess_fffpf

	int answer_num[LEN_WORDS], guess_num[LEN_WORDS];
	int answer_num_true[LEN_WORDS] = {BLACK_LETTER, YELLOW_LETTER, BLACK_LETTER, BLACK_LETTER, BLACK_LETTER};
	int guess_num_true[LEN_WORDS] = {BLACK_LETTER, BLACK_LETTER, BLACK_LETTER, YELLOW_LETTER, BLACK_LETTER};
	char answer[LEN_WORDS + 1] = "apaaa", guess[LEN_WORDS + 1] = "fffpf";

	Fill_difference(answer, guess, answer_num, guess_num);

	check_arr_eq(answer_num, answer_num_true);
	check_arr_eq(guess_num, guess_num_true);

#tcase MoreCommonLetter
#test True_apapa_Guess_pffpf

	int answer_num[LEN_WORDS], guess_num[LEN_WORDS];
	int answer_num_true[LEN_WORDS] = {BLACK_LETTER, YELLOW_LETTER, BLACK_LETTER, GREEN_LETTER, BLACK_LETTER};
	int guess_num_true[LEN_WORDS] = {YELLOW_LETTER, BLACK_LETTER, BLACK_LETTER, GREEN_LETTER, BLACK_LETTER};
	char answer[LEN_WORDS + 1] = "apapa", guess[LEN_WORDS + 1] = "pffpf";

	Fill_difference(answer, guess, answer_num, guess_num);

	check_arr_eq(answer_num, answer_num_true);
	check_arr_eq(guess_num, guess_num_true);
