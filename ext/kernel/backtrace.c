/**
 * This file is part of the Zephir.
 *
 * (c) Phalcon Team <team@zephir-lang.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code. If you did not receive
 * a copy of the license it is available through the world-wide-web at the
 * following url: https://docs.zephir-lang.com/en/latest/license
 */

#ifndef ZEPHIR_RELEASE
#if defined(linux) && !defined(ALPINE_LINUX) || defined(DARWIN) || defined(__APPLE__)

#include <execinfo.h>
#include <Zend/zend.h>
#include <ext/standard/php_smart_string.h>
#include <zend_smart_str.h>

/**
 * A buffer for backtrace. It is better to have it allocated statically
 * in order not to face out of memory conditions later
 */
void *backtrace_buf[4096];

void zephir_print_backtrace(void)
{
	int i;
	int stack_size       = backtrace(backtrace_buf, sizeof(backtrace_buf) / sizeof(void*));
	char **stack_symbols = backtrace_symbols(backtrace_buf, stack_size);
	char buf[50];
	smart_str s = {0};

	for (i = 0; i < stack_size; ++i) {
		snprintf(buf, sizeof(buf), "#%d  %p [", i, backtrace_buf[i]);
		smart_str_appends(&s, buf);
		smart_str_appends(&s, stack_symbols[i]);
		smart_str_appends(&s, "]\n");
	}

	smart_str_0(&s);

	fprintf(stderr, "%s\n", ZSTR_VAL(s.s));
	smart_str_free(&s);
}

#else

void zephir_print_backtrace(void)
{
	/**
	 * Not implemented yet for anything other than Linux
	 */
}

#endif
#endif /* ZEPHIR_RELEASE */
