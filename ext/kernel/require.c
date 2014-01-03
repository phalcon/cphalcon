
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_ext.h"
#include "php_main.h"
#include "kernel/main.h"
#include "kernel/require.h"
#include "kernel/memory.h"
#include "kernel/debug.h"
#include "Zend/zend_exceptions.h"

int ZEPHIR_FASTCALL zephir_internal_require(zval *return_value, const zval *require_path TSRMLS_DC){

	int ret;
	char *file_path;
	unsigned int file_path_length;
	zend_file_handle file_handle;
	zval *result = NULL;
	int status = SUCCESS;
	int dummy = 0;

	zval **original_return_value = EG(return_value_ptr_ptr);
	zend_op **original_opline_ptr = EG(opline_ptr);
	zend_op_array *original_active_op_array = EG(active_op_array);

	zend_op_array *new_op_array = NULL;

	if (unlikely(Z_TYPE_P(require_path) != IS_STRING)) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid require path value");
		status = FAILURE;
	} else {

		file_path = Z_STRVAL_P(require_path);

		#if PHP_VERSION_ID < 50400
		ret = php_stream_open_for_zend_ex(file_path, &file_handle, ENFORCE_SAFE_MODE|USE_PATH|STREAM_OPEN_FOR_INCLUDE|IGNORE_URL TSRMLS_CC);
		#else
		ret = php_stream_open_for_zend_ex(file_path, &file_handle, USE_PATH|STREAM_OPEN_FOR_INCLUDE|IGNORE_URL TSRMLS_CC);
		#endif

		if (likely(ret == SUCCESS)) {

			if (!file_handle.opened_path) {
				file_path_length = Z_STRLEN_P(require_path);
				file_handle.opened_path = estrndup(file_path, file_path_length);
			}

			EG(exit_status) = 0;
			PG(during_request_startup) = 0;

			if (file_handle.filename) {
				if ((file_handle.filename[0] != '-' || file_handle.filename[1] != 0) && file_handle.opened_path == NULL && file_handle.type != ZEND_HANDLE_FILENAME) {
					char realfile[MAXPATHLEN];
					int realfile_len;
					dummy = 1;
					if (expand_filepath(file_handle.filename, realfile TSRMLS_CC)) {
						realfile_len =  strlen(realfile);
						zend_hash_add(&EG(included_files), realfile, realfile_len + 1, (void *)&dummy, sizeof(int), NULL);
						file_handle.opened_path = estrndup(realfile, realfile_len);
					}
				}
			}

			if (!dummy) {
				if (file_handle.opened_path) {
					file_path_length = strlen(file_handle.opened_path);
					zend_hash_add(&EG(included_files), file_handle.opened_path, file_path_length + 1, (void *)&dummy, sizeof(int), NULL);
				}
			}

			new_op_array = zend_compile_file(&file_handle, ZEND_REQUIRE TSRMLS_CC);
			zend_destroy_file_handle(&file_handle TSRMLS_CC);

			if (likely(new_op_array != NULL)) {

				EG(return_value_ptr_ptr) = &result;
				EG(active_op_array) = new_op_array;
				if (!EG(active_symbol_table)) {
					zend_rebuild_symbol_table(TSRMLS_C);
				}

				/** This provides compatibility with AOP extension */
				new_op_array->type = ZEND_EVAL_CODE;

				zend_execute(new_op_array TSRMLS_CC);
				zend_exception_restore(TSRMLS_C);

				destroy_op_array(new_op_array TSRMLS_CC);
				efree(new_op_array);

				if (!EG(exception)) {
					if (EG(return_value_ptr_ptr)) {
						ASSUME(result != NULL);
						if (return_value) {
							COPY_PZVAL_TO_ZVAL(*return_value, result);
						} else {
							zval_ptr_dtor(EG(return_value_ptr_ptr));
						}
					}
				}

			}

			EG(return_value_ptr_ptr) = original_return_value;
			EG(opline_ptr) = original_opline_ptr;
			EG(active_op_array) = original_active_op_array;

			if (EG(exception) || EG(exit_status) == 255) {
				status = FAILURE;
			}

		} else {
			zend_destroy_file_handle(&file_handle TSRMLS_CC);
			status = FAILURE;
		}

	}

	return status;
}

/**
 * Do an internal require to a plain php file without taking care of the value returned by the file
 */
int ZEPHIR_FASTCALL zephir_require(const zval *require_path TSRMLS_DC){
	return zephir_internal_require(NULL, require_path TSRMLS_CC);
}

/**
 * Do an internal require to a plain php file taking care of the value returned by the file
 */
int ZEPHIR_FASTCALL zephir_require_ret(zval *return_value, const zval *require_path TSRMLS_DC){
	return zephir_internal_require(return_value, require_path TSRMLS_CC);
}
