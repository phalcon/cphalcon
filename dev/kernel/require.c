
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
#include "kernel/debug.h"

/**
 * Do an internal require to a plain php file
 *
 */
int phalcon_require(zval *require_path TSRMLS_DC){

	int ret;
	char *file_path;
	int file_path_length;
	zend_file_handle file_handle;
	zval *result = NULL;
	zend_op_array *orig_op_array;
	zval **orig_retval_ptr_ptr;

	switch(Z_TYPE_P(require_path)){
		case IS_ARRAY:
		case IS_OBJECT:
		case IS_RESOURCE:
			zend_error_noreturn(E_ERROR, "Invalid require path value");
			return FAILURE;
	}

	if(Z_TYPE_P(require_path)!=IS_STRING){
		convert_to_string(require_path);
	}

	file_path = Z_STRVAL_P(require_path);
	file_path_length = Z_STRLEN_P(require_path);

	ret = php_stream_open_for_zend_ex(file_path, &file_handle, ENFORCE_SAFE_MODE|USE_PATH|STREAM_OPEN_FOR_INCLUDE TSRMLS_CC);
	if(ret==SUCCESS){

		if(!file_handle.opened_path){
			file_handle.opened_path = estrndup(file_path, file_path_length);
		}

		EG(exit_status) = 0;
		PG(during_request_startup) = 0;

		if(file_handle.filename && (file_handle.filename[0] != '-' || file_handle.filename[1] != 0) && file_handle.opened_path == NULL && file_handle.type != ZEND_HANDLE_FILENAME){
			char realfile[MAXPATHLEN];
			int realfile_len;
			int dummy = 1;
			if(expand_filepath(file_handle.filename, realfile TSRMLS_CC)){
				realfile_len =  strlen(realfile);
				zend_hash_add(&EG(included_files), realfile, realfile_len+1, (void *)&dummy, sizeof(int), NULL);
				file_handle.opened_path = estrndup(realfile, realfile_len);
			}
		}

		orig_op_array = EG(active_op_array);
		orig_retval_ptr_ptr = EG(return_value_ptr_ptr);

		EG(active_op_array) = zend_compile_file(&file_handle, ZEND_REQUIRE TSRMLS_CC);
		if(EG(active_op_array) && file_handle.handle.stream.handle){
			EG(return_value_ptr_ptr) = NULL;
			zend_execute(EG(active_op_array) TSRMLS_CC);
			destroy_op_array(EG(active_op_array) TSRMLS_CC);
			efree(EG(active_op_array));
		} else {
			EG(active_op_array) = orig_op_array;
			EG(return_value_ptr_ptr) = orig_retval_ptr_ptr;
			return FAILURE;
		}

		EG(active_op_array) = orig_op_array;
		EG(return_value_ptr_ptr) = orig_retval_ptr_ptr;

		return SUCCESS;
	}

	return FAILURE;

}
