
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
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/array.h"
#include "kernel/object.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Request\File
 *
 * Provides OO wrappers to the $_FILES superglobal
 *
 *
 */

/**
 * Phalcon\Request\File constructor
 *
 * @param array $file
 */
PHP_METHOD(Phalcon_Request_File, __construct){

	zval *file = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &file) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (Z_TYPE_P(file) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_request_exception_ce, "Phalcon_Request_File requires a valid uploaded file");
		return;
	}
	eval_int = phalcon_array_isset_string(file, SL("name")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, file, SL("name"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_name"), r0 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(file, SL("tmp_name")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, file, SL("tmp_name"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_tmp"), r1 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(file, SL("size")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, file, SL("size"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_size"), r2 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the file size of the uploaded file
 *
 * @return int
 */
PHP_METHOD(Phalcon_Request_File, getSize){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_size"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Returns the real name of the uploaded file
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request_File, getName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_name"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Returns the temporal name of the uploaded file
 *
 * @return string
 */
PHP_METHOD(Phalcon_Request_File, getTempName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_tmp"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Move the temporary file to a destination
 *
 * @param string $destination
 */
PHP_METHOD(Phalcon_Request_File, moveTo){

	zval *destination = NULL;
	zval *t0 = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &destination) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_tmp"), PH_NOISY_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "move_uploaded_file", t0, destination);
	RETURN_CTOR(r0);
}

