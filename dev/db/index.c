
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Db_Index
 *
 * Allows to define indexes to be used on tables
 *
 */

/**
 * Phalcon_Db_Index constructor
 *
 * @param string $indexName
 * @param array $columns
 */
PHP_METHOD(Phalcon_Db_Index, __construct){

	zval *index_name = NULL, *columns = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &index_name, &columns) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_indexName", strlen("_indexName"), index_name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_columns", strlen("_columns"), columns TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Gets the index name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Index, getName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_indexName", sizeof("_indexName")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Gets the columns that comprends the index
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Index, getColumns){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_columns", sizeof("_columns")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Restore a Phalcon_Db_Index object from export
 *
 * @param array $data
 * @return Phalcon_Db_Index
 */
PHP_METHOD(Phalcon_Db_Index, __set_state){

	zval *data = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	eval_int = phalcon_array_isset_string(data, "_indexName", strlen("_indexName")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "_indexName parameter is required", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	eval_int = phalcon_array_isset_string(data, "_columns", strlen("_columns")+1);
	if (!eval_int) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c1);
		ZVAL_STRING(c1, "_columns parameter is required", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c1, PHALCON_CHECK);
		phalcon_throw_exception(i1 TSRMLS_CC);
		return;
	}
	
	
	PHALCON_ALLOC_ZVAL_MM(i2);
	object_init_ex(i2, phalcon_db_index_ce);
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	phalcon_array_fetch_string(&r0, data, "_indexName", strlen("_indexName"), PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	phalcon_array_fetch_string(&r1, data, "_columns", strlen("_columns"), PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(i2, "__construct", r0, r1, PHALCON_CHECK);
	
	PHALCON_RETURN_CTOR(i2);
}

