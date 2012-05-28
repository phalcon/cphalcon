
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

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

/**
 * Phalcon_Db_Column
 *
 * Allows to define columns to be used on create or alter table operations
 *
 *
 *
 */

/**
 * Phalcon_Db_Column constructor
 *
 * @param string $columnName
 * @param array $definition
 */
PHP_METHOD(Phalcon_Db_Column, __construct){

	zval *column_name = NULL, *definition = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *i0 = NULL, *i1 = NULL, *i2 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &column_name, &definition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, "_columnName", strlen("_columnName"), column_name TSRMLS_CC);
	eval_int = phalcon_array_isset_string(definition, "type", strlen("type")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, definition, "type", strlen("type"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_type", strlen("_type"), r0 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_db_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Column type is required", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	eval_int = phalcon_array_isset_string(definition, "notNull", strlen("notNull")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, definition, "notNull", strlen("notNull"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_notNull", strlen("_notNull"), r1 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, "size", strlen("size")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, definition, "size", strlen("size"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_size", strlen("_size"), r2 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, "scale", strlen("scale")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, "_type", sizeof("_type")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 3);
		PHALCON_ALLOC_ZVAL_MM(r3);
		is_equal_function(r3, t0, t1 TSRMLS_CC);
		if (zend_is_true(r3)) {
			PHALCON_ALLOC_ZVAL_MM(r4);
			phalcon_array_fetch_string(&r4, definition, "scale", strlen("scale"), PHALCON_NOISY TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_scale", strlen("_scale"), r4 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(i1);
			object_init_ex(i1, phalcon_db_exception_ce);
			PHALCON_INIT_VAR(c1);
			ZVAL_STRING(c1, "Column type does not support scale parameter", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i1, "__construct", c1, PHALCON_CHECK);
			phalcon_throw_exception(i1 TSRMLS_CC);
			return;
		}
	}
	
	eval_int = phalcon_array_isset_string(definition, "unsigned", strlen("unsigned")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r5);
		phalcon_array_fetch_string(&r5, definition, "unsigned", strlen("unsigned"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_unsigned", strlen("_unsigned"), r5 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, "autoIncrement", strlen("autoIncrement")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_type", sizeof("_type")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_INIT_VAR(t3);
		ZVAL_LONG(t3, 0);
		PHALCON_ALLOC_ZVAL_MM(r6);
		is_equal_function(r6, t2, t3 TSRMLS_CC);
		if (zend_is_true(r6)) {
			PHALCON_ALLOC_ZVAL_MM(r7);
			phalcon_array_fetch_string(&r7, definition, "autoIncrement", strlen("autoIncrement"), PHALCON_NOISY TSRMLS_CC);
			phalcon_update_property_zval(this_ptr, "_autoIncrement", strlen("_autoIncrement"), r7 TSRMLS_CC);
		} else {
			PHALCON_ALLOC_ZVAL_MM(i2);
			object_init_ex(i2, phalcon_db_exception_ce);
			PHALCON_INIT_VAR(c2);
			ZVAL_STRING(c2, "Column type cannot be auto-increment", 1);
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i2, "__construct", c2, PHALCON_CHECK);
			phalcon_throw_exception(i2 TSRMLS_CC);
			return;
		}
	}
	
	eval_int = phalcon_array_isset_string(definition, "first", strlen("first")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_string(&r8, definition, "first", strlen("first"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_first", strlen("_first"), r8 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, "after", strlen("after")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r9);
		phalcon_array_fetch_string(&r9, definition, "after", strlen("after"), PHALCON_NOISY TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_after", strlen("_after"), r9 TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns schema's table related to column
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getSchemaName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_schemaName", sizeof("_schemaName")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns column name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getName){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_columnName", sizeof("_columnName")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns column type
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getType){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_type", sizeof("_type")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns column size
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getSize){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_size", sizeof("_size")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns column scale
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getScale){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_scale", sizeof("_scale")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns true if number column is unsigned
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isUnsigned){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_unsigned", sizeof("_unsigned")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Not null
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isNotNull){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_notNull", sizeof("_notNull")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Auto-Increment
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isAutoIncrement){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_autoIncrement", sizeof("_autoIncrement")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Check whether column have first position in table
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isFirst){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_first", sizeof("_first")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Check whether field absolute to position in table
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getAfterPosition){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_after", sizeof("_after")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

