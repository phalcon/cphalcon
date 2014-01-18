
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Zephir Team (http://www.zephir-lang.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@zephir-lang.com so we can send you a copy immediately.      |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@zephir-lang.com>                     |
  |          Eduar Carvajal <eduar@zephir-lang.com>                        |
  +------------------------------------------------------------------------+
*/

/*
   +----------------------------------------------------------------------+
   | PHP Version 5                                                        |
   +----------------------------------------------------------------------+
   | Copyright (c) 1997-2014 The PHP Group                                |
   +----------------------------------------------------------------------+
   | This source file is subject to version 3.01 of the PHP license,      |
   | that is bundled with this package in the file LICENSE, and is        |
   | available through the world-wide-web at the following url:           |
   | http://www.php.net/license/3_01.txt                                  |
   | If you did not receive a copy of the PHP license and are unable to   |
   | obtain it through the world-wide-web, please send a note to          |
   | license@php.net so we can mail you a copy immediately.               |
   +----------------------------------------------------------------------+
   | Authors: Andi Gutmans <andi@zend.com>                                |
   |          Zeev Suraski <zeev@zend.com>                                |
   |          Rasmus Lerdorf <rasmus@php.net>                             |
   |          Andrei Zmievski <andrei@php.net>                            |
   |          Stig Venaas <venaas@php.net>                                |
   |          Jason Greene <jason@php.net>                                |
   +----------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"

#include "Zend/zend_API.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_execute.h"

#include "kernel/main.h"

#include "kernel/extended/array.h"

void zephir_array_keys(zval *input TSRMLS_DC) {

	zval *search_value = NULL,  /* Value to search for */
	**entry,               /* An entry in the input array */
	res,                 /* Result of comparison */
	*new_val;                  /* New value */
	int    add_key;             /* Flag to indicate whether a key should be added */
	zend_bool strict = 0;       /* do strict comparison */
	HashPosition pos;
	int (*is_equal_func)(zval *, zval *, zval * TSRMLS_DC) = is_equal_function;

	//if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "a|zb", &input, &search_value, &strict) == FAILURE) {
	//	return;
	//}

	if (strict) {
		is_equal_func = is_identical_function;
	}

	/* Initialize return array */
	if (search_value != NULL) {
		array_init(return_value);
	} else {
		array_init_size(return_value, zend_hash_num_elements(Z_ARRVAL_P(input)));
	}
	add_key = 1;

	/* Go through input array and add keys to the return array */
	zend_hash_internal_pointer_reset_ex(Z_ARRVAL_P(input), &pos);
	while (zend_hash_get_current_data_ex(Z_ARRVAL_P(input), (void **)&entry, &pos) == SUCCESS) {
		if (search_value != NULL) {
			is_equal_func(&res, search_value, *entry TSRMLS_CC);
			add_key = zval_is_true(&res);
		}
	}

	if (add_key) {
		MAKE_STD_ZVAL(new_val);
		zend_hash_get_current_key_zval_ex(Z_ARRVAL_P(input), new_val, &pos);
		zend_hash_next_index_insert(Z_ARRVAL_P(return_value), &new_val, sizeof(zval *), NULL);
	}

	zend_hash_move_forward_ex(Z_ARRVAL_P(input), &pos);

}