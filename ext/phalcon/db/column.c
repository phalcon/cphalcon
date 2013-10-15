
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"


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
ZEPHIR_INIT_CLASS(Phalcon_Db_Column) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Column, phalcon, db_column, phalcon_db_column_method_entry, 0);

/**
	 * Column's name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Schema which table related is
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_schemaName"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Column data type
	 *
	 * @var int
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * The column have some numeric type?
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_isNumeric"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Integer column size
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_db_column_ce, SL("_size"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Integer column number scale
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_db_column_ce, SL("_scale"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Integer column unsigned?
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_unsigned"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Column not nullable?
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_notNull"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Column is part of the primary key?
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_primary"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Column is autoIncrement?
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_autoIncrement"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Position is first
	 *
	 * @var boolean
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_first"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Column Position
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_after"), ZEND_ACC_PROTECTED TSRMLS_CC);
/**
	 * Bind Type
	 */
	zend_declare_property_long(phalcon_db_column_ce, SL("_bindType"), 2, ZEND_ACC_PROTECTED TSRMLS_CC);
/**
 * Integer abstract type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_INTEGER"), 0 TSRMLS_CC);
/**
 * Date abstract type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATE"), 1 TSRMLS_CC);
/**
 * Varchar abstract type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_VARCHAR"), 2 TSRMLS_CC);
/**
 * Decimal abstract type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DECIMAL"), 3 TSRMLS_CC);
/**
 * Datetime abstract type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATETIME"), 4 TSRMLS_CC);
/**
 * Char abstract type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_CHAR"), 5 TSRMLS_CC);
/**
 * Text abstract data type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TEXT"), 6 TSRMLS_CC);
/**
 * Float abstract data type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_FLOAT"), 7 TSRMLS_CC);
/**
 * Boolean abstract data type
 *
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BOOLEAN"), 8 TSRMLS_CC);
/**
 * Bind Type Null
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_NULL"), 0 TSRMLS_CC);
/**
 * Bind Type Integer
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_INT"), 1 TSRMLS_CC);
/**
 * Bind Type String
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_STR"), 2 TSRMLS_CC);
/**
 * Bind Type Bool
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_BOOL"), 5 TSRMLS_CC);
/**
 * Bind Type Decimal
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_DECIMAL"), 32 TSRMLS_CC);
/**
 * Skip binding by type
 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_SKIP"), 1024 TSRMLS_CC);

	zend_class_implements(phalcon_db_column_ce TSRMLS_CC, 1, phalcon_db_columninterface_ce);

	return SUCCESS;

}

/**
 * Column's name
 *
 * @var string
 */
PHP_METHOD(Phalcon_Db_Column, getName) {



}

/**
 * Schema which table related is
 *
 * @var string
 */
PHP_METHOD(Phalcon_Db_Column, getSchemaName) {



}

/**
 * Column data type
 *
 * @var int
 */
PHP_METHOD(Phalcon_Db_Column, getType) {



}

/**
 * Integer column size
 *
 * @var int
 */
PHP_METHOD(Phalcon_Db_Column, getSize) {



}

/**
 * Integer column number scale
 *
 * @var int
 */
PHP_METHOD(Phalcon_Db_Column, getScale) {



}

/**
 * Phalcon\Db\Column constructor
 *
 * @param string name
 * @param array definition
 */
PHP_METHOD(Phalcon_Db_Column, __construct) {

	zval *name_param = NULL, *definition, *type, *notNull, *primary, *size, *scale, *dunsigned, *first, *after, *bindType, *isNumeric, *autoIncrement;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition);

		if (Z_TYPE_P(name_param) != IS_STRING) {
				zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
				RETURN_MM_NULL();
		}

		name = name_param;



	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	if (zephir_array_isset_string_fetch(&type, definition, SS("type"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_type"), type TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column type is required");
		return;
	}
	if (zephir_array_isset_string_fetch(&notNull, definition, SS("notNull"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_notNull"), notNull TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&primary, definition, SS("primary"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_primary"), primary TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&size, definition, SS("size"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_size"), size TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&scale, definition, SS("scale"), 1 TSRMLS_CC)) {
		if ((ZEPHIR_IS_LONG(type, 0) || ZEPHIR_IS_LONG(type, 7))) {
			zephir_update_property_this(this_ptr, SL("_scale"), scale TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column type does not support scale parameter");
			return;
		}
	}
	if (zephir_array_isset_string_fetch(&dunsigned, definition, SS("unsigned"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_unsigned"), dunsigned TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&isNumeric, definition, SS("isNumeric"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_isNumeric"), isNumeric TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&autoIncrement, definition, SS("autoIncrement"), 1 TSRMLS_CC)) {
		if (ZEPHIR_IS_LONG(type, 0)) {
			zephir_update_property_this(this_ptr, SL("_autoIncrement"), autoIncrement TSRMLS_CC);
		} else {
			ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column type cannot be auto-increment");
			return;
		}
	}
	if (zephir_array_isset_string_fetch(&first, definition, SS("first"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_first"), first TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&after, definition, SS("after"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_after"), after TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&bindType, definition, SS("bindType"), 1 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_bindType"), bindType TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns true if number column is unsigned
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isUnsigned) {


	RETURN_MEMBER(this_ptr, "_unsigned");

}

/**
 * Not null
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isNotNull) {


	RETURN_MEMBER(this_ptr, "_notNull");

}

/**
 * Column is part of the primary key?
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isPrimary) {


	RETURN_MEMBER(this_ptr, "_primary");

}

/**
 * Auto-Increment
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isAutoIncrement) {


	RETURN_MEMBER(this_ptr, "_autoIncrement");

}

/**
 * Check whether column have an numeric type
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isNumeric) {


	RETURN_MEMBER(this_ptr, "_isNumeric");

}

/**
 * Check whether column have first position in table
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Column, isFirst) {


	RETURN_MEMBER(this_ptr, "_first");

}

/**
 * Check whether field absolute to position in table
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getAfterPosition) {


	RETURN_MEMBER(this_ptr, "_after");

}

/**
 * Returns the type of bind handling
 *
 * @return int
 */
PHP_METHOD(Phalcon_Db_Column, getBindType) {


	RETURN_MEMBER(this_ptr, "_bindType");

}

/**
 * Restores the internal state of a Phalcon\Db\Column object
 *
 * @param array data
 * @return \Phalcon\Db\Column
 */
PHP_METHOD(Phalcon_Db_Column, __set_state) {

	zval *data, *definition, *columnType, *notNull, *size, *dunsigned, *after, *isNumeric, *first, *bindType, *primary, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data);



	if ((Z_TYPE_P(data) != IS_ARRAY)) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column state must be an array");
		return;
	}
	if (!(zephir_array_isset_string(data, SS("_name")))) {
		ZEPHIR_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Column name is required");
		return;
	}
	ZEPHIR_INIT_VAR(definition);
	array_init(definition);
	if (zephir_array_isset_string_fetch(&columnType, data, SS("_type"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("type"), &columnType, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&notNull, data, SS("_notNull"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("_notNull"), &notNull, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&primary, data, SS("_primary"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("primary"), &primary, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&size, data, SS("_size"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("size"), &size, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&dunsigned, data, SS("_unsigned"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("unsigned"), &dunsigned, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&after, data, SS("_after"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("after"), &after, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&isNumeric, data, SS("_isNumeric"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("isNumeric"), &isNumeric, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&first, data, SS("_first"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("first"), &first, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&bindType, data, SS("_bindType"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("bindType"), &bindType, PH_COPY | PH_SEPARATE);
	}
	object_init_ex(return_value, phalcon_db_column_ce);
	zephir_array_fetch_string(&_0, data, SL("_name"), PH_NOISY | PH_READONLY TSRMLS_CC);
	zephir_call_method_p2_noret(return_value, "__construct", _0, definition);
	RETURN_MM();

}

