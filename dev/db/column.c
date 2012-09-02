
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
#include "kernel/operators.h"
#include "kernel/fcall.h"

/**
 * Phalcon\Db\Column
 *
 * Allows to define columns to be used on create or alter table operations
 *
 *<code>
 *	use Phalcon\Db\Column as Column;
 *
 * //column definition
 * $column = new Column("id", array(
 *   "type" => Column::TYPE_INTEGER,
 *   "size" => 10,
 *   "unsigned" => true,
 *   "notNull" => true,
 *   "autoIncrement" => true,
 *   "first" => true
 * ));
 *
 * //add column to existing table
 * $connection->addColumn("robots", null, $column);
 *</code>
 *
 */

/**
 * Phalcon\Db\Column constructor
 *
 * @param string $columnName
 * @param array $definition
 */
PHP_METHOD(Phalcon_Db_Column, __construct){

	zval *column_name = NULL, *definition = NULL, *type = NULL, *not_null = NULL;
	zval *primary = NULL, *size = NULL, *is_numeric = NULL, *scale = NULL, *dunsigned = NULL;
	zval *auto_increment = NULL, *first = NULL, *after = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *r0 = NULL, *r1 = NULL;
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
		PHALCON_INIT_VAR(not_null);
		phalcon_array_fetch_string(&not_null, definition, SL("notNull"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_notNull"), not_null TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("primary")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(primary);
		phalcon_array_fetch_string(&primary, definition, SL("primary"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_primary"), primary TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("size")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(size);
		phalcon_array_fetch_string(&size, definition, SL("size"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_size"), size TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("scale")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 3);
		PHALCON_ALLOC_ZVAL_MM(r0);
		is_equal_function(r0, type, t0 TSRMLS_CC);
		PHALCON_INIT_VAR(t1);
		ZVAL_LONG(t1, 7);
		PHALCON_ALLOC_ZVAL_MM(r1);
		is_equal_function(r1, type, t1 TSRMLS_CC);
		PHALCON_INIT_VAR(is_numeric);
		ZVAL_BOOL(is_numeric, zend_is_true(r0) || zend_is_true(r1));
		if (Z_TYPE_P(is_numeric) == IS_BOOL && Z_BVAL_P(is_numeric)) {
			PHALCON_INIT_VAR(scale);
			phalcon_array_fetch_string(&scale, definition, SL("scale"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_scale"), scale TSRMLS_CC);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column type does not support scale parameter");
			return;
		}
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("unsigned")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(dunsigned);
		phalcon_array_fetch_string(&dunsigned, definition, SL("unsigned"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_unsigned"), dunsigned TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("isNumeric")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(is_numeric);
		phalcon_array_fetch_string(&is_numeric, definition, SL("isNumeric"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_isNumeric"), is_numeric TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("autoIncrement")+1);
	if (eval_int) {
		if (phalcon_compare_strict_long(type, 0 TSRMLS_CC)) {
			PHALCON_INIT_VAR(auto_increment);
			phalcon_array_fetch_string(&auto_increment, definition, SL("autoIncrement"), PH_NOISY_CC);
			phalcon_update_property_zval(this_ptr, SL("_autoIncrement"), auto_increment TSRMLS_CC);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column type cannot be auto-increment");
			return;
		}
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("first")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(first);
		phalcon_array_fetch_string(&first, definition, SL("first"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_first"), first TSRMLS_CC);
	}
	
	eval_int = phalcon_array_isset_string(definition, SL("after")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(after);
		phalcon_array_fetch_string(&after, definition, SL("after"), PH_NOISY_CC);
		phalcon_update_property_zval(this_ptr, SL("_after"), after TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns schema's table related to column
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getSchemaName){

	zval *schema_name = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(schema_name);
	phalcon_read_property(&schema_name, this_ptr, SL("_schemaName"), PH_NOISY_CC);
	
	RETURN_CCTOR(schema_name);
}

/**
 * Returns column name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getName){

	zval *column_name = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(column_name);
	phalcon_read_property(&column_name, this_ptr, SL("_columnName"), PH_NOISY_CC);
	
	RETURN_CCTOR(column_name);
}

/**
 * Returns column type
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getType){

	zval *type = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(type);
	phalcon_read_property(&type, this_ptr, SL("_type"), PH_NOISY_CC);
	
	RETURN_CCTOR(type);
}

/**
 * Returns column size
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getSize){

	zval *size = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(size);
	phalcon_read_property(&size, this_ptr, SL("_size"), PH_NOISY_CC);
	
	RETURN_CCTOR(size);
}

/**
 * Returns column scale
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getScale){

	zval *scale = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(scale);
	phalcon_read_property(&scale, this_ptr, SL("_scale"), PH_NOISY_CC);
	
	RETURN_CCTOR(scale);
}

/**
 * Returns true if number column is unsigned
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isUnsigned){

	zval *dunsigned = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(dunsigned);
	phalcon_read_property(&dunsigned, this_ptr, SL("_unsigned"), PH_NOISY_CC);
	
	RETURN_CCTOR(dunsigned);
}

/**
 * Not null
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isNotNull){

	zval *not_null = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(not_null);
	phalcon_read_property(&not_null, this_ptr, SL("_notNull"), PH_NOISY_CC);
	
	RETURN_CCTOR(not_null);
}

/**
 * Column is part of the primary key?
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isPrimary){

	zval *primary = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(primary);
	phalcon_read_property(&primary, this_ptr, SL("_primary"), PH_NOISY_CC);
	
	RETURN_CCTOR(primary);
}

/**
 * Auto-Increment
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isAutoIncrement){

	zval *auto_increment = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(auto_increment);
	phalcon_read_property(&auto_increment, this_ptr, SL("_autoIncrement"), PH_NOISY_CC);
	
	RETURN_CCTOR(auto_increment);
}

/**
 * Check whether column have an numeric type
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isNumeric){

	zval *is_numeric = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(is_numeric);
	phalcon_read_property(&is_numeric, this_ptr, SL("_isNumeric"), PH_NOISY_CC);
	
	RETURN_CCTOR(is_numeric);
}

/**
 * Check whether column have first position in table
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isFirst){

	zval *first = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(first);
	phalcon_read_property(&first, this_ptr, SL("_first"), PH_NOISY_CC);
	
	RETURN_CCTOR(first);
}

/**
 * Check whether field absolute to position in table
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getAfterPosition){

	zval *after = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(after);
	phalcon_read_property(&after, this_ptr, SL("_after"), PH_NOISY_CC);
	
	RETURN_CCTOR(after);
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

