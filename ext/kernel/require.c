
/*
  +------------------------------------------------------------------------+
  | Zephir Language                                                        |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2016 Zephir Team (http://www.zephir-lang.com)       |
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
int zephir_require_ret(zval *return_value_ptr, const char *require_path)
{
	zend_file_handle file_handle;
	int ret;
	zend_op_array *new_op_array;
	zval dummy, local_retval;

	ZVAL_UNDEF(&local_retval);

#ifndef ZEPHIR_RELEASE
	if (return_value_ptr != NULL && Z_TYPE_P(return_value_ptr) > IS_NULL) {
		fprintf(stderr, "%s: *return_value_ptr is expected to be NULL", __func__);
		zephir_print_backtrace();
		abort();
	}
#endif

	/* if (!memcmp(require_path, "", 0)) {
		@TODO, throw an exception here
		return FAILURE;
	} */

	file_handle.filename = require_path;
	file_handle.free_filename = 0;
	file_handle.type = ZEND_HANDLE_FILENAME;
	file_handle.opened_path = NULL;
	file_handle.handle.fp = NULL;

	new_op_array = zend_compile_file(&file_handle, ZEND_REQUIRE);
	if (new_op_array) {

		if (file_handle.handle.stream.handle) {
			ZVAL_NULL(&dummy);
			if (!file_handle.opened_path) {
				file_handle.opened_path = zend_string_init(require_path, strlen(require_path), 0);
			}

			zend_hash_add(&EG(included_files), file_handle.opened_path, &dummy);
			zend_destroy_file_handle(&file_handle);
		}

#if PHP_VERSION_ID >= 70100
		new_op_array->scope = EG(fake_scope);
#else
		new_op_array->scope = EG(scope);
#endif
		zend_execute(new_op_array, &local_retval);

		if (return_value_ptr) {
			zval_ptr_dtor(return_value_ptr);
			ZVAL_COPY_VALUE(return_value_ptr, &local_retval);
		} else {
			zval_ptr_dtor(&local_retval);
		}

		destroy_op_array(new_op_array);
		efree_size(new_op_array, sizeof(zend_op_array));

		if (EG(exception)) {
			ret = FAILURE;
		} else {
			ret = SUCCESS;
		}

		return ret;
	} else {
		zend_destroy_file_handle(&file_handle);
	}

	return FAILURE;
}
