
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "php_main.h"
#include "kernel/main.h"
#include "kernel/require.h"
#include "kernel/memory.h"
#include "kernel/debug.h"
#include "Zend/zend_exceptions.h"

/**
 * Do an internal require to a plain php file
 *
 */
int PHALCON_FASTCALL phalcon_require(zval *require_path TSRMLS_DC){

	int ret;
	char *file_path;
	int file_path_length;
	zend_file_handle file_handle;
	zval *result = NULL;
	int status = SUCCESS;
	int dummy = 0;

	zval **original_return_value = EG(return_value_ptr_ptr);
	zend_op **original_opline_ptr = EG(opline_ptr);
	zend_op_array *original_active_op_array = EG(active_op_array);

	zend_op_array *new_op_array = NULL;

	if (Z_TYPE_P(require_path) != IS_STRING) {
		php_error_docref(NULL TSRMLS_CC, E_ERROR, "Invalid require path value");
		status = FAILURE;
	} else {

		file_path = Z_STRVAL_P(require_path);
		file_path_length = Z_STRLEN_P(require_path);

		ret = php_stream_open_for_zend_ex(file_path, &file_handle, ENFORCE_SAFE_MODE|USE_PATH|STREAM_OPEN_FOR_INCLUDE TSRMLS_CC);
		if (ret == SUCCESS) {

			if(!file_handle.opened_path){
				file_handle.opened_path = estrndup(file_path, file_path_length);
			}

			EG(exit_status) = 0;
			PG(during_request_startup) = 0;

			if (file_handle.filename){
				if ((file_handle.filename[0] != '-' || file_handle.filename[1] != 0) && file_handle.opened_path == NULL && file_handle.type != ZEND_HANDLE_FILENAME) {
					char realfile[MAXPATHLEN];
					int realfile_len;
					dummy = 1;
					if(expand_filepath(file_handle.filename, realfile TSRMLS_CC)){
						realfile_len =  strlen(realfile);
						zend_hash_add(&EG(included_files), realfile, realfile_len+1, (void *)&dummy, sizeof(int), NULL);
						file_handle.opened_path = estrndup(realfile, realfile_len);
					}
				}
			}

			if (!dummy) {
				if (file_handle.opened_path) {
					zend_hash_add(&EG(included_files), file_handle.opened_path, strlen(file_handle.opened_path) + 1, (void *)&dummy, sizeof(int), NULL);
				}
			}

			new_op_array = zend_compile_file(&file_handle, ZEND_REQUIRE TSRMLS_CC);
			zend_destroy_file_handle(&file_handle TSRMLS_CC);

			if (new_op_array) {

				EG(return_value_ptr_ptr) = &result;
				EG(active_op_array) = new_op_array;
				if (!EG(active_symbol_table)) {
					zend_rebuild_symbol_table(TSRMLS_C);
				}

				zend_execute(new_op_array TSRMLS_CC);
				zend_exception_restore(TSRMLS_C);

				destroy_op_array(new_op_array TSRMLS_CC);
				efree(new_op_array);
				if (!EG(exception)) {
					if (EG(return_value_ptr_ptr)) {
						zval_ptr_dtor(EG(return_value_ptr_ptr));
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

	if (status == FAILURE){
		phalcon_memory_restore_stack(TSRMLS_C);
	}

	return status;
}
