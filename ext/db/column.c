
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
 * Phalcon\Db\Column initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Column){

	PHALCON_REGISTER_CLASS(Phalcon\\Db, Column, db_column, phalcon_db_column_method_entry, 0);

	zend_declare_property_null(phalcon_db_column_ce, SL("_columnName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, SL("_schemaName"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_isNumeric"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_column_ce, SL("_size"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_column_ce, SL("_scale"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_unsigned"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_notNull"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_primary"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_autoIncrement"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_db_column_ce, SL("_first"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_column_ce, SL("_after"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_column_ce, SL("_bindType"), 2, ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_INTEGER"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATE"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_VARCHAR"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DECIMAL"), 3 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATETIME"), 4 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_CHAR"), 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TEXT"), 6 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_FLOAT"), 7 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BOOLEAN"), 8 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DOUBLE"), 9 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_NULL"), 0 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_INT"), 1 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_STR"), 2 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_BOOL"), 5 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_DECIMAL"), 32 TSRMLS_CC);
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_SKIP"), 1024 TSRMLS_CC);

	zend_class_implements(phalcon_db_column_ce TSRMLS_CC, 1, phalcon_db_columninterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Db\Column constructor
 *
 * @param string $columnName
 * @param array $definition
 */
PHP_METHOD(Phalcon_Db_Column, __construct){

	zval *column_name, *definition, *type, *not_null;
	zval *primary, *size, *is_numeric = NULL, *scale, *dunsigned;
	zval *auto_increment, *first, *after, *bind_type;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 0, &column_name, &definition);
	
	phalcon_update_property_this(this_ptr, SL("_columnName"), column_name TSRMLS_CC);
	
	/** 
	 * Get the column type, one of the TYPE_* constants
	 */
	if (phalcon_array_isset_string(definition, SS("type"))) {
		PHALCON_OBS_VAR(type);
		phalcon_array_fetch_string(&type, definition, SL("type"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column type is required");
		return;
	}
	
	/** 
	 * Check if the field is nullable
	 */
	if (phalcon_array_isset_string(definition, SS("notNull"))) {
		PHALCON_OBS_VAR(not_null);
		phalcon_array_fetch_string(&not_null, definition, SL("notNull"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_notNull"), not_null TSRMLS_CC);
	}
	
	/** 
	 * Check if the field is primary key
	 */
	if (phalcon_array_isset_string(definition, SS("primary"))) {
		PHALCON_OBS_VAR(primary);
		phalcon_array_fetch_string(&primary, definition, SL("primary"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_primary"), primary TSRMLS_CC);
	}
	
	if (phalcon_array_isset_string(definition, SS("size"))) {
		PHALCON_OBS_VAR(size);
		phalcon_array_fetch_string(&size, definition, SL("size"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_size"), size TSRMLS_CC);
	}
	
	/** 
	 * Check if the column has a decimal scale
	 */
	if (phalcon_array_isset_string(definition, SS("scale"))) {
	
		PHALCON_INIT_VAR(t0);
		ZVAL_LONG(t0, 3);
		PHALCON_INIT_VAR(is_numeric);
		is_equal_function(is_numeric, type, t0 TSRMLS_CC);
		if (PHALCON_IS_NOT_TRUE(is_numeric)) {
			PHALCON_INIT_VAR(t1);
			ZVAL_LONG(t1, 7);
			is_equal_function(is_numeric, type, t1 TSRMLS_CC);
		}

		if (PHALCON_IS_NOT_TRUE(is_numeric)) {
			PHALCON_INIT_NVAR(t1);
			ZVAL_LONG(t1, 9);
			is_equal_function(is_numeric, type, t1 TSRMLS_CC);
		}
	
		if (PHALCON_IS_TRUE(is_numeric)) {
			PHALCON_OBS_VAR(scale);
			phalcon_array_fetch_string(&scale, definition, SL("scale"), PH_NOISY);
			phalcon_update_property_this(this_ptr, SL("_scale"), scale TSRMLS_CC);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column type does not support scale parameter");
			return;
		}
	}

	/** 
	 * Check if the field is unsigned (only MySQL)
	 */
	if (phalcon_array_isset_string(definition, SS("unsigned"))) {
		PHALCON_OBS_VAR(dunsigned);
		phalcon_array_fetch_string(&dunsigned, definition, SL("unsigned"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_unsigned"), dunsigned TSRMLS_CC);
	}

	/** 
	 * Check if the field is numeric
	 */
	if (phalcon_array_isset_string(definition, SS("isNumeric"))) {
		PHALCON_OBS_NVAR(is_numeric);
		phalcon_array_fetch_string(&is_numeric, definition, SL("isNumeric"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_isNumeric"), is_numeric TSRMLS_CC);
	}
	
	/** 
	 * Check if the field is auto-increment/serial
	 */
	if (phalcon_array_isset_string(definition, SS("autoIncrement"))) {
		if (PHALCON_IS_LONG(type, 0)) {
			PHALCON_OBS_VAR(auto_increment);
			phalcon_array_fetch_string(&auto_increment, definition, SL("autoIncrement"), PH_NOISY);
			phalcon_update_property_this(this_ptr, SL("_autoIncrement"), auto_increment TSRMLS_CC);
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column type cannot be auto-increment");
			return;
		}
	}
	
	/** 
	 * Check if the field is placed at the first position of the table
	 */
	if (phalcon_array_isset_string(definition, SS("first"))) {
		PHALCON_OBS_VAR(first);
		phalcon_array_fetch_string(&first, definition, SL("first"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_first"), first TSRMLS_CC);
	}
	
	/** 
	 * Name of the column which is placed before the current field
	 */
	if (phalcon_array_isset_string(definition, SS("after"))) {
		PHALCON_OBS_VAR(after);
		phalcon_array_fetch_string(&after, definition, SL("after"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_after"), after TSRMLS_CC);
	}
	
	/** 
	 * The bind type to cast the field when passing it to PDO
	 */
	if (phalcon_array_isset_string(definition, SS("bindType"))) {
		PHALCON_OBS_VAR(bind_type);
		phalcon_array_fetch_string(&bind_type, definition, SL("bindType"), PH_NOISY);
		phalcon_update_property_this(this_ptr, SL("_bindType"), bind_type TSRMLS_CC);
	}
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns schema's table related to column
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getSchemaName){


	RETURN_MEMBER(this_ptr, "_schemaName");
}

/**
 * Returns column name
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getName){


	RETURN_MEMBER(this_ptr, "_columnName");
}

/**
 * Returns column type
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Returns column size
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getSize){


	RETURN_MEMBER(this_ptr, "_size");
}

/**
 * Returns column scale
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getScale){


	RETURN_MEMBER(this_ptr, "_scale");
}

/**
 * Returns true if number column is unsigned
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isUnsigned){


	RETURN_MEMBER(this_ptr, "_unsigned");
}

/**
 * Not null
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isNotNull){


	RETURN_MEMBER(this_ptr, "_notNull");
}

/**
 * Column is part of the primary key?
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isPrimary){


	RETURN_MEMBER(this_ptr, "_primary");
}

/**
 * Auto-Increment
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isAutoIncrement){


	RETURN_MEMBER(this_ptr, "_autoIncrement");
}

/**
 * Check whether column have an numeric type
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isNumeric){


	RETURN_MEMBER(this_ptr, "_isNumeric");
}

/**
 * Check whether column have first position in table
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isFirst){


	RETURN_MEMBER(this_ptr, "_first");
}

/**
 * Check whether field absolute to position in table
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getAfterPosition){


	RETURN_MEMBER(this_ptr, "_after");
}

/**
 * Returns the type of bind handling
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getBindType){


	RETURN_MEMBER(this_ptr, "_bindType");
}

/**
 * Restores the internal state of a Phalcon\Db\Column object
 *
 * @param array $data
 * @return \Phalcon\Db\Column
 */
PHP_METHOD(Phalcon_Db_Column, __set_state){

	zval *data, *definition, *column_name, *column_type;
	zval *not_null, *primary, *size, *scale, *dunsigned, *after;
	zval *is_numeric = NULL, *first, *bind_type;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);
	
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column state must be an array");
		return;
	}
	
	PHALCON_INIT_VAR(definition);
	array_init(definition);
	if (!phalcon_array_isset_string(data, SS("_columnName"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column name is required");
		return;
	}
	
	PHALCON_OBS_VAR(column_name);
	phalcon_array_fetch_string(&column_name, data, SL("_columnName"), PH_NOISY);
	if (phalcon_array_isset_string(data, SS("_type"))) {
		PHALCON_OBS_VAR(column_type);
		phalcon_array_fetch_string(&column_type, data, SL("_type"), PH_NOISY);
		phalcon_array_update_string(&definition, SL("type"), &column_type, PH_COPY | PH_SEPARATE);
	}
	
	if (phalcon_array_isset_string(data, SS("_notNull"))) {
		PHALCON_OBS_VAR(not_null);
		phalcon_array_fetch_string(&not_null, data, SL("_notNull"), PH_NOISY);
		phalcon_array_update_string(&definition, SL("notNull"), &not_null, PH_COPY | PH_SEPARATE);
	}
	
	if (phalcon_array_isset_string(data, SS("_primary"))) {
		PHALCON_OBS_VAR(primary);
		phalcon_array_fetch_string(&primary, data, SL("_primary"), PH_NOISY);
		phalcon_array_update_string(&definition, SL("primary"), &primary, PH_COPY | PH_SEPARATE);
	}
	
	if (phalcon_array_isset_string(data, SS("_size"))) {
		PHALCON_OBS_VAR(size);
		phalcon_array_fetch_string(&size, data, SL("_size"), PH_NOISY);
		phalcon_array_update_string(&definition, SL("size"), &size, PH_COPY | PH_SEPARATE);
	}

        if (phalcon_array_isset_string(data, SS("_scale"))) {
                PHALCON_INIT_VAR(t0);
                ZVAL_LONG(t0, 3);
                PHALCON_INIT_VAR(is_numeric);
                is_equal_function(is_numeric, column_type, t0 TSRMLS_CC);
                if (PHALCON_IS_NOT_TRUE(is_numeric)) {
                        PHALCON_INIT_VAR(t1);
                        ZVAL_LONG(t1, 7);
                        is_equal_function(is_numeric, column_type, t1 TSRMLS_CC);
                }

                if (PHALCON_IS_TRUE(is_numeric)) {
                        PHALCON_OBS_VAR(scale);
                        phalcon_array_fetch_string(&scale, data, SL("_scale"), PH_NOISY);
                        phalcon_array_update_string(&definition, SL("scale"), &scale, PH_COPY | PH_SEPARATE);
                }
        }
	
	if (phalcon_array_isset_string(data, SS("_unsigned"))) {
		PHALCON_OBS_VAR(dunsigned);
		phalcon_array_fetch_string(&dunsigned, data, SL("_unsigned"), PH_NOISY);
		phalcon_array_update_string(&definition, SL("unsigned"), &dunsigned, PH_COPY | PH_SEPARATE);
	}
	
	if (phalcon_array_isset_string(data, SS("_after"))) {
		PHALCON_OBS_VAR(after);
		phalcon_array_fetch_string(&after, data, SL("_after"), PH_NOISY);
		phalcon_array_update_string(&definition, SL("after"), &after, PH_COPY | PH_SEPARATE);
	}
	
	if (phalcon_array_isset_string(data, SS("_isNumeric"))) {
		PHALCON_OBS_NVAR(is_numeric);
		phalcon_array_fetch_string(&is_numeric, data, SL("_isNumeric"), PH_NOISY);
		phalcon_array_update_string(&definition, SL("isNumeric"), &is_numeric, PH_COPY | PH_SEPARATE);
	}
	
	if (phalcon_array_isset_string(data, SS("_first"))) {
		PHALCON_OBS_VAR(first);
		phalcon_array_fetch_string(&first, data, SL("_first"), PH_NOISY);
		phalcon_array_update_string(&definition, SL("first"), &first, PH_COPY | PH_SEPARATE);
	}
	
	if (phalcon_array_isset_string(data, SS("_bindType"))) {
		PHALCON_OBS_VAR(bind_type);
		phalcon_array_fetch_string(&bind_type, data, SL("_bindType"), PH_NOISY);
		phalcon_array_update_string(&definition, SL("bindType"), &bind_type, PH_COPY | PH_SEPARATE);
	}
	
	object_init_ex(return_value, phalcon_db_column_ce);
	phalcon_call_method_p2_noret(return_value, "__construct", column_name, definition);
	
	RETURN_MM();
}

