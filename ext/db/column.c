
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

#include "db/column.h"
#include "db/columninterface.h"
#include "db/exception.h"

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"

#include "internal/arginfo.h"

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
zend_class_entry *phalcon_db_column_ce;

PHP_METHOD(Phalcon_Db_Column, __construct);
PHP_METHOD(Phalcon_Db_Column, getSchemaName);
PHP_METHOD(Phalcon_Db_Column, getName);
PHP_METHOD(Phalcon_Db_Column, getType);
PHP_METHOD(Phalcon_Db_Column, getSize);
PHP_METHOD(Phalcon_Db_Column, getScale);
PHP_METHOD(Phalcon_Db_Column, isUnsigned);
PHP_METHOD(Phalcon_Db_Column, isNotNull);
PHP_METHOD(Phalcon_Db_Column, isPrimary);
PHP_METHOD(Phalcon_Db_Column, isAutoIncrement);
PHP_METHOD(Phalcon_Db_Column, isNumeric);
PHP_METHOD(Phalcon_Db_Column, isFirst);
PHP_METHOD(Phalcon_Db_Column, getAfterPosition);
PHP_METHOD(Phalcon_Db_Column, getBindType);
PHP_METHOD(Phalcon_Db_Column, __set_state);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_db_column___construct, 0, 0, 2)
	ZEND_ARG_INFO(0, columnName)
	ZEND_ARG_INFO(0, definition)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_db_column_method_entry[] = {
	PHP_ME(Phalcon_Db_Column, __construct, arginfo_phalcon_db_column___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Db_Column, getSchemaName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getName, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getSize, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getScale, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isUnsigned, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isNotNull, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isPrimary, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isAutoIncrement, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isNumeric, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, isFirst, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getAfterPosition, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, getBindType, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Db_Column, __set_state, arginfo___set_state, ZEND_ACC_PUBLIC|ZEND_ACC_STATIC)
	PHP_FE_END
};

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
	zval *primary, *size, *scale, *dunsigned, *is_numeric;
	zval *auto_increment, *first, *after, *bind_type;

	phalcon_fetch_params(0, 2, 0, &column_name, &definition);
	
	phalcon_update_property_this(this_ptr, SL("_columnName"), column_name TSRMLS_CC);
	
	/** 
	 * Get the column type, one of the TYPE_* constants
	 */
	if (phalcon_array_isset_string_fetch(&type, definition, SS("type"))) {
		phalcon_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	} else {
		PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Column type is required");
		return;
	}
	
	/** 
	 * Check if the field is nullable
	 */
	if (phalcon_array_isset_string_fetch(&not_null, definition, SS("notNull"))) {
		phalcon_update_property_this(this_ptr, SL("_notNull"), not_null TSRMLS_CC);
	}
	
	/** 
	 * Check if the field is primary key
	 */
	if (phalcon_array_isset_string_fetch(&primary, definition, SS("primary"))) {
		phalcon_update_property_this(this_ptr, SL("_primary"), primary TSRMLS_CC);
	}
	
	if (phalcon_array_isset_string_fetch(&size, definition, SS("size"))) {
		phalcon_update_property_this(this_ptr, SL("_size"), size TSRMLS_CC);
	}
	
	/** 
	 * Check if the column has a decimal scale
	 */
	if (phalcon_array_isset_string_fetch(&scale, definition, SS("scale"))) {
		int i_type     = phalcon_get_intval(type);
		int is_numeric = (i_type == 3 || i_type == 7 || i_type == 9);
	
		if (is_numeric) {
			phalcon_update_property_this(this_ptr, SL("_scale"), scale TSRMLS_CC);
		}
	}
	
	/** 
	 * Check if the field is unsigned (only MySQL)
	 */
	if (phalcon_array_isset_string_fetch(&dunsigned, definition, SS("unsigned"))) {
		phalcon_update_property_this(this_ptr, SL("_unsigned"), dunsigned TSRMLS_CC);
	}
	
	/** 
	 * Check if the field is numeric
	 */
	if (phalcon_array_isset_string_fetch(&is_numeric, definition, SS("isNumeric"))) {
		phalcon_update_property_this(this_ptr, SL("_isNumeric"), is_numeric TSRMLS_CC);
	}
	
	/** 
	 * Check if the field is auto-increment/serial
	 */
	if (phalcon_array_isset_string_fetch(&auto_increment, definition, SS("autoIncrement"))) {
		if (PHALCON_IS_LONG(type, 0)) {
			phalcon_update_property_this(this_ptr, SL("_autoIncrement"), auto_increment TSRMLS_CC);
		} else {
			PHALCON_THROW_EXCEPTION_STRW(phalcon_db_exception_ce, "Column type cannot be auto-increment");
			return;
		}
	}
	
	/** 
	 * Check if the field is placed at the first position of the table
	 */
	if (phalcon_array_isset_string_fetch(&first, definition, SS("first"))) {
		phalcon_update_property_this(this_ptr, SL("_first"), first TSRMLS_CC);
	}
	
	/** 
	 * Name of the column which is placed before the current field
	 */
	if (phalcon_array_isset_string_fetch(&after, definition, SS("after"))) {
		phalcon_update_property_this(this_ptr, SL("_after"), after TSRMLS_CC);
	}
	
	/** 
	 * The bind type to cast the field when passing it to PDO
	 */
	if (phalcon_array_isset_string_fetch(&bind_type, definition, SS("bindType"))) {
		phalcon_update_property_this(this_ptr, SL("_bindType"), bind_type TSRMLS_CC);
	}
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

	zval *data, *definition, *column_name, *column_type = NULL;
	zval *not_null, *primary, *size, *scale, *dunsigned, *after;
	zval *is_numeric, *first, *bind_type;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 0, &data);
	
	if (Z_TYPE_P(data) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column state must be an array");
		return;
	}
	
	if (!phalcon_array_isset_string_fetch(&column_name, data, SS("_columnName"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column name is required");
		return;
	}

	PHALCON_INIT_VAR(definition);
	array_init(definition);

	if (phalcon_array_isset_string_fetch(&column_type, data, SS("_type"))) {
		phalcon_array_update_string(&definition, SL("type"), column_type, PH_COPY);
	}
	
	if (phalcon_array_isset_string_fetch(&not_null, data, SS("_notNull"))) {
		phalcon_array_update_string(&definition, SL("notNull"), not_null, PH_COPY);
	}
	
	if (phalcon_array_isset_string_fetch(&primary, data, SS("_primary"))) {
		phalcon_array_update_string(&definition, SL("primary"), primary, PH_COPY);
	}
	
	if (phalcon_array_isset_string_fetch(&size, data, SS("_size"))) {
		phalcon_array_update_string(&definition, SL("size"), size, PH_COPY);
	}
	
	if (phalcon_array_isset_string_fetch(&scale, data, SS("_scale"))) {
		phalcon_array_update_string(&definition, SL("scale"), scale, PH_COPY);
	}

	if (phalcon_array_isset_string_fetch(&dunsigned, data, SS("_unsigned"))) {
		phalcon_array_update_string(&definition, SL("unsigned"), dunsigned, PH_COPY);
	}
	
	if (phalcon_array_isset_string_fetch(&after, data, SS("_after"))) {
		phalcon_array_update_string(&definition, SL("after"), after, PH_COPY);
	}
	
	if (phalcon_array_isset_string_fetch(&is_numeric, data, SS("_isNumeric"))) {
		phalcon_array_update_string(&definition, SL("isNumeric"), is_numeric, PH_COPY);
	}
	
	if (phalcon_array_isset_string_fetch(&first, data, SS("_first"))) {
		phalcon_array_update_string(&definition, SL("first"), first, PH_COPY);
	}
	
	if (phalcon_array_isset_string_fetch(&bind_type, data, SS("_bindType"))) {
		phalcon_array_update_string(&definition, SL("bindType"), bind_type, PH_COPY);
	}
	
	object_init_ex(return_value, phalcon_db_column_ce);
	PHALCON_CALL_METHOD(NULL, return_value, "__construct", column_name, definition);
	
	RETURN_MM();
}
