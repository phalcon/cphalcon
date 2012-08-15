
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

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"

/**
 * Phalcon_Db_Column
 *
 * Allows to define columns to be used on create or alter table operations
 *
 *
 *
 */

/**
 * Phalcon\Db\Column constructor
 *
 * @param string $columnName
 * @param array $definition
 */
PHP_METHOD(Phalcon_Db_Column, __construct){

	zval *column_name = NULL, *definition = NULL, *type = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL, *r10 = NULL, *r11 = NULL, *r12 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &column_name, &definition) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_columnName"), column_name TSRMLS_CC);
	eval_int = phalcon_array_isset_string(definition, SL("type")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(type);
		phalcon_array_fetch_string(&type, definition, SL("type"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_type"), type TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column type is required");
		return;
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("notNull")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, definition, SL("notNull"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_notNull"), r0 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("primary")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		phalcon_array_fetch_string(&r1, definition, SL("primary"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_primary"), r1 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("size")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r2);
		phalcon_array_fetch_string(&r2, definition, SL("size"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_size"), r2 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("scale")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 3);
		PHALCON_ALLOC_ZVAL_MM(r3);
		is_equal_function(r3, type, t0 TSRMLS_CC);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 7);
		PHALCON_ALLOC_ZVAL_MM(r4);
		is_equal_function(r4, type, t1 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r5);
		ZVAL_BOOL(r5, zend_is_true(r3) || zend_is_true(r4));
		if (zend_is_true(r5)) {
			PHALCON_ALLOC_ZVAL_MM(r6);
			phalcon_array_fetch_string(&r6, definition, SL("scale"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_scale"), r6 TSRMLS_CC);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column type does not support scale parameter");
			return;
		}
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("unsigned")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r7);
		phalcon_array_fetch_string(&r7, definition, SL("unsigned"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_unsigned"), r7 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("isNumeric")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r8);
		phalcon_array_fetch_string(&r8, definition, SL("isNumeric"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_isNumeric"), r8 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("autoIncrement")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(t2);
		ZVAL_LONG(t2, 0);
		PHALCON_ALLOC_ZVAL_MM(r9);
		is_equal_function(r9, type, t2 TSRMLS_CC);
		if (zend_is_true(r9)) {
			PHALCON_ALLOC_ZVAL_MM(r10);
			phalcon_array_fetch_string(&r10, definition, SL("autoIncrement"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_autoIncrement"), r10 TSRMLS_CC);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column type cannot be auto-increment");
			return;
		}
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("first")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r11);
		phalcon_array_fetch_string(&r11, definition, SL("first"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_first"), r11 TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("after")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r12);
		phalcon_array_fetch_string(&r12, definition, SL("after"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_after"), r12 TSRMLS_CC);
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
	phalcon_read_property(&t0, this_ptr, SL("_schemaName"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, SL("_columnName"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, SL("_type"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, SL("_size"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, SL("_scale"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, SL("_unsigned"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, SL("_notNull"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Column is part of the primary key?
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isPrimary){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_primary"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, SL("_autoIncrement"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

/**
 * Check whether column have an numeric type
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isNumeric){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, SL("_isNumeric"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, SL("_first"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
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
	phalcon_read_property(&t0, this_ptr, SL("_after"), PH_NOISY_CC);
	
	RETURN_CCTOR(t0);
}

PHP_METHOD(Phalcon_Db_Column, __set_state){

	zval *data = NULL, *definition = NULL, *column_name = NULL, *column_type = NULL;
	zval *not_null = NULL, *primary = NULL, *size = NULL, *dunsigned = NULL, *after = NULL;
	zval *is_numeric = NULL, *first = NULL, *column = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &data) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_INIT_VAR(definition);
	array_init(definition);
	eval_int = phalcon_array_isset_string(data, SL("_columnName")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(column_name);
		phalcon_array_fetch_string(&column_name, data, SL("_columnName"), PH_NOISY_CC);
	}
	
	eval_int = phalcon_array_isset_string(data, SL("_type")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(column_type);
		phalcon_array_fetch_string(&column_type, data, SL("_type"), PH_NOISY_CC);
		phalcon_array_update_string(&definition, SL("type"), &column_type, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(data, SL("_notNull")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(not_null);
		phalcon_array_fetch_string(&not_null, data, SL("_notNull"), PH_NOISY_CC);
		phalcon_array_update_string(&definition, SL("notNull"), &not_null, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(data, SL("_primary")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(primary);
		phalcon_array_fetch_string(&primary, data, SL("_primary"), PH_NOISY_CC);
		phalcon_array_update_string(&definition, SL("primary"), &primary, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(data, SL("_size")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(size);
		phalcon_array_fetch_string(&size, data, SL("_size"), PH_NOISY_CC);
		phalcon_array_update_string(&definition, SL("size"), &size, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(data, SL("_unsigned")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(dunsigned);
		phalcon_array_fetch_string(&dunsigned, data, SL("_unsigned"), PH_NOISY_CC);
		phalcon_array_update_string(&definition, SL("unsigned"), &dunsigned, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(data, SL("_after")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(after);
		phalcon_array_fetch_string(&after, data, SL("_after"), PH_NOISY_CC);
		phalcon_array_update_string(&definition, SL("after"), &after, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(data, SL("_isNumeric")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(is_numeric);
		phalcon_array_fetch_string(&is_numeric, data, SL("_isNumeric"), PH_NOISY_CC);
		phalcon_array_update_string(&definition, SL("isNumeric"), &is_numeric, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(data, SL("_first")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(first);
		phalcon_array_fetch_string(&first, data, SL("_first"), PH_NOISY_CC);
		phalcon_array_update_string(&definition, SL("first"), &first, PH_COPY | PH_SEPARATE TSRMLS_CC);
	}
	
	PHALCON_INIT_VAR(column);
	object_init_ex(column, phalcon_db_column_ce);
	PHALCON_CALL_METHOD_PARAMS_2_NORETURN(column, "__construct", column_name, definition, PH_CHECK);
	
	RETURN_CTOR(column);
}

