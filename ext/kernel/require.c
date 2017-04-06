
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2017 Zephir Team (http://www.zephir-lang.com)       |
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
  |          Vladimir Kolesnikov <vladimir@extrememember.com>              |
  +------------------------------------------------------------------------+
*/

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
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
int zephir_require_ret(zval **return_value_ptr, const char *require_path TSRMLS_DC)
{
	zend_file_handle file_handle;
	int ret;
	zend_op_array *new_op_array;

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr && *return_value_ptr) {
		fprintf(stderr, "%s: *return_value_ptr is expected to be NULL", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	if (!require_path) {
		/* @TODO, throw an exception here */
		return FAILURE;
	}

	file_handle.filename = require_path;
	file_handle.free_filename = 0;
	file_handle.type = ZEND_HANDLE_FILENAME;
	file_handle.opened_path = NULL;
	file_handle.handle.fp = NULL;
	new_op_array = zend_compile_file(&file_handle, ZEND_REQUIRE TSRMLS_CC);
	if (new_op_array) {
		if (file_handle.handle.stream.handle) {
			int dummy = 1;

			if (!file_handle.opened_path) {
				file_handle.opened_path = estrdup(require_path);
			}

			zend_hash_add(&EG(included_files), file_handle.opened_path, strlen(file_handle.opened_path) + 1, (void *)&dummy, sizeof(int), NULL);
			zend_destroy_file_handle(&file_handle TSRMLS_CC);
		}
		{
			zval **original_return_value = EG(return_value_ptr_ptr);
			zend_op_array *original_active_op_array = EG(active_op_array);
			zend_op **original_opline_ptr = EG(opline_ptr);

			EG(return_value_ptr_ptr) = return_value_ptr;
			EG(active_op_array) = new_op_array;

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
			EG(active_op_array) = original_active_op_array;
			EG(opline_ptr) = original_opline_ptr;
			return ret;
		}
	}
	else {
		zend_destroy_file_handle(&file_handle TSRMLS_CC);
	}

	return FAILURE;
}
