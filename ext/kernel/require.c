
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  +------------------------------------------------------------------------+
*/

#include "kernel/require.h"
#include "kernel/backtrace.h"

#include <main/php_main.h>
#include <Zend/zend_exceptions.h>

#ifndef ENFORCE_SAFE_MODE
#define ENFORCE_SAFE_MODE    0
#endif

/**
 * Do an internal require to a plain php file taking care of the value returned by the file
 */
int phalcon_require_ret(zval **return_value_ptr, const char *require_path TSRMLS_DC)
{
	zend_file_handle file_handle;
	int ret;

#ifndef PHALCON_RELEASE
	if (return_value_ptr && *return_value_ptr) {
		fprintf(stderr, "%s: *return_value_ptr is expected to be NULL", __func__);
		phalcon_print_backtrace();
		abort();
	}
#endif

	ret = php_stream_open_for_zend_ex(require_path, &file_handle, ENFORCE_SAFE_MODE | USE_PATH | STREAM_OPEN_FOR_INCLUDE | IGNORE_URL TSRMLS_CC);
	if (ret == SUCCESS) {
		int dummy = 1;
		zend_op_array *new_op_array;

		if (!file_handle.opened_path) {
			file_handle.opened_path = estrdup(require_path);
		}

		zend_hash_add(&EG(included_files), file_handle.opened_path, strlen(file_handle.opened_path)+1, (void *)&dummy, sizeof(int), NULL);
		new_op_array = zend_compile_file(&file_handle, ZEND_REQUIRE TSRMLS_CC);
		zend_destroy_file_handle(&file_handle TSRMLS_CC);

		if (new_op_array) {
			zval **original_return_value            = EG(return_value_ptr_ptr);
			zend_op_array *original_active_op_array = EG(active_op_array);
			zend_op **original_opline_ptr           = EG(opline_ptr);

			EG(return_value_ptr_ptr) = return_value_ptr;
			EG(active_op_array)      = new_op_array;

			zend_execute(new_op_array TSRMLS_CC);
			zend_exception_restore(TSRMLS_C);
			destroy_op_array(new_op_array TSRMLS_CC);
			efree(new_op_array);

			if (EG(exception)) {
				assert(!return_value_ptr || !*return_value_ptr);
				ret = FAILURE;
			}
			else {
				ret = SUCCESS;
			}

			EG(return_value_ptr_ptr) = original_return_value;
			EG(active_op_array)      = original_active_op_array;
			EG(opline_ptr)           = original_opline_ptr;
			return ret;
		}
	}
	else {
		zend_destroy_file_handle(&file_handle TSRMLS_CC);
	}

	return FAILURE;
}
