
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
#include "kernel/memory.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/fcall.h"


/**
 * Phalcon\Db\Column
 *
 * Allows to define columns to be used on create or alter table operations
 *
 *<code>
 * use Phalcon\Db\Column as Column;
 *
 * // Column definition
 * $column = new Column(
 *     "id",
 *     [
 *         "type"          => Column::TYPE_INTEGER,
 *         "size"          => 10,
 *         "unsigned"      => true,
 *         "notNull"       => true,
 *         "autoIncrement" => true,
 *         "first"         => true,
 *     ]
 * );
 *
 * // Add column to existing table
 * $connection->addColumn("robots", null, $column);
 *</code>
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
	 * @var int|string
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Column data type reference
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_db_column_ce, SL("_typeReference"), -1, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Column data type values
	 *
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_typeValues"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
	 * Default column value
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_default"), ZEND_ACC_PROTECTED TSRMLS_CC);

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
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_INTEGER"), 0 TSRMLS_CC);

	/**
	 * Date abstract type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATE"), 1 TSRMLS_CC);

	/**
	 * Varchar abstract type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_VARCHAR"), 2 TSRMLS_CC);

	/**
	 * Decimal abstract type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DECIMAL"), 3 TSRMLS_CC);

	/**
	 * Datetime abstract type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATETIME"), 4 TSRMLS_CC);

	/**
	 * Char abstract type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_CHAR"), 5 TSRMLS_CC);

	/**
	 * Text abstract data type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TEXT"), 6 TSRMLS_CC);

	/**
	 * Float abstract data type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_FLOAT"), 7 TSRMLS_CC);

	/**
	 * Boolean abstract data type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BOOLEAN"), 8 TSRMLS_CC);

	/**
	 * Double abstract data type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DOUBLE"), 9 TSRMLS_CC);

	/**
	 * Tinyblob abstract data type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TINYBLOB"), 10 TSRMLS_CC);

	/**
	 * Blob abstract data type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BLOB"), 11 TSRMLS_CC);

	/**
	 * Mediumblob abstract data type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_MEDIUMBLOB"), 12 TSRMLS_CC);

	/**
	 * Longblob abstract data type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_LONGBLOB"), 13 TSRMLS_CC);

	/**
	 * Big integer abstract data type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BIGINTEGER"), 14 TSRMLS_CC);

	/**
	 * Json abstract type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_JSON"), 15 TSRMLS_CC);

	/**
	 * Jsonb abstract type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_JSONB"), 16 TSRMLS_CC);

	/**
	 * Datetime abstract type
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TIMESTAMP"), 17 TSRMLS_CC);

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
	 * Bind Type Blob
	 */
	zend_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_BLOB"), 3 TSRMLS_CC);

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
 */
PHP_METHOD(Phalcon_Db_Column, getName) {

	

	RETURN_MEMBER(getThis(), "_name");

}

/**
 * Schema which table related is
 */
PHP_METHOD(Phalcon_Db_Column, getSchemaName) {

	

	RETURN_MEMBER(getThis(), "_schemaName");

}

/**
 * Column data type
 */
PHP_METHOD(Phalcon_Db_Column, getType) {

	

	RETURN_MEMBER(getThis(), "_type");

}

/**
 * Column data type reference
 */
PHP_METHOD(Phalcon_Db_Column, getTypeReference) {

	

	RETURN_MEMBER(getThis(), "_typeReference");

}

/**
 * Column data type values
 */
PHP_METHOD(Phalcon_Db_Column, getTypeValues) {

	

	RETURN_MEMBER(getThis(), "_typeValues");

}

/**
 * Integer column size
 */
PHP_METHOD(Phalcon_Db_Column, getSize) {

	

	RETURN_MEMBER(getThis(), "_size");

}

/**
 * Integer column number scale
 */
PHP_METHOD(Phalcon_Db_Column, getScale) {

	

	RETURN_MEMBER(getThis(), "_scale");

}

/**
 * Default column value
 */
PHP_METHOD(Phalcon_Db_Column, getDefault) {

	

	RETURN_MEMBER(getThis(), "_default");

}

/**
 * Phalcon\Db\Column constructor
 */
PHP_METHOD(Phalcon_Db_Column, __construct) {

	zval *definition = NULL;
	zval *name_param = NULL, *definition_param = NULL, *type = NULL, *notNull = NULL, *primary = NULL, *size = NULL, *scale = NULL, *dunsigned = NULL, *first = NULL, *after = NULL, *bindType = NULL, *isNumeric = NULL, *autoIncrement = NULL, *defaultValue = NULL, *typeReference = NULL, *typeValues = NULL;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	definition = definition_param;


	zephir_update_property_this(getThis(), SL("_name"), name TSRMLS_CC);
	ZEPHIR_OBS_VAR(type);
	if (zephir_array_isset_string_fetch(&type, definition, SS("type"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_type"), type TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Column type is required", "phalcon/db/column.zep", 299);
		return;
	}
	ZEPHIR_OBS_VAR(typeReference);
	if (zephir_array_isset_string_fetch(&typeReference, definition, SS("typeReference"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_typeReference"), typeReference TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(typeValues);
	if (zephir_array_isset_string_fetch(&typeValues, definition, SS("typeValues"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_typeValues"), typeValues TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(notNull);
	if (zephir_array_isset_string_fetch(&notNull, definition, SS("notNull"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_notNull"), notNull TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(primary);
	if (zephir_array_isset_string_fetch(&primary, definition, SS("primary"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_primary"), primary TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(size);
	if (zephir_array_isset_string_fetch(&size, definition, SS("size"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_size"), size TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(scale);
	if (zephir_array_isset_string_fetch(&scale, definition, SS("scale"), 0 TSRMLS_CC)) {
		do {
			if (ZEPHIR_IS_LONG(type, 0) || ZEPHIR_IS_LONG(type, 7) || ZEPHIR_IS_LONG(type, 3) || ZEPHIR_IS_LONG(type, 9) || ZEPHIR_IS_LONG(type, 14)) {
				zephir_update_property_this(getThis(), SL("_scale"), scale TSRMLS_CC);
				break;
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Column type does not support scale parameter", "phalcon/db/column.zep", 343);
			return;
		} while(0);

	}
	ZEPHIR_OBS_VAR(defaultValue);
	if (zephir_array_isset_string_fetch(&defaultValue, definition, SS("default"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_default"), defaultValue TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(dunsigned);
	if (zephir_array_isset_string_fetch(&dunsigned, definition, SS("unsigned"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_unsigned"), dunsigned TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(isNumeric);
	if (zephir_array_isset_string_fetch(&isNumeric, definition, SS("isNumeric"), 0 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_isNumeric"), isNumeric TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(autoIncrement);
	if (zephir_array_isset_string_fetch(&autoIncrement, definition, SS("autoIncrement"), 0 TSRMLS_CC)) {
		if (!(zephir_is_true(autoIncrement))) {
			if (0) {
				zephir_update_property_this(getThis(), SL("_autoIncrement"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
			} else {
				zephir_update_property_this(getThis(), SL("_autoIncrement"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
			}
		} else {
			do {
				if (ZEPHIR_IS_LONG(type, 0) || ZEPHIR_IS_LONG(type, 14)) {
					if (1) {
						zephir_update_property_this(getThis(), SL("_autoIncrement"), ZEPHIR_GLOBAL(global_true) TSRMLS_CC);
					} else {
						zephir_update_property_this(getThis(), SL("_autoIncrement"), ZEPHIR_GLOBAL(global_false) TSRMLS_CC);
					}
					break;
				}
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Column type cannot be auto-increment", "phalcon/db/column.zep", 383);
				return;
			} while(0);

		}
	}
	if (zephir_array_isset_string_fetch(&first, definition, SS("first"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_first"), first TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&after, definition, SS("after"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_after"), after TSRMLS_CC);
	}
	if (zephir_array_isset_string_fetch(&bindType, definition, SS("bindType"), 1 TSRMLS_CC)) {
		zephir_update_property_this(getThis(), SL("_bindType"), bindType TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns true if number column is unsigned
 */
PHP_METHOD(Phalcon_Db_Column, isUnsigned) {

	

	RETURN_MEMBER(getThis(), "_unsigned");

}

/**
 * Not null
 */
PHP_METHOD(Phalcon_Db_Column, isNotNull) {

	

	RETURN_MEMBER(getThis(), "_notNull");

}

/**
 * Column is part of the primary key?
 */
PHP_METHOD(Phalcon_Db_Column, isPrimary) {

	

	RETURN_MEMBER(getThis(), "_primary");

}

/**
 * Auto-Increment
 */
PHP_METHOD(Phalcon_Db_Column, isAutoIncrement) {

	

	RETURN_MEMBER(getThis(), "_autoIncrement");

}

/**
 * Check whether column have an numeric type
 */
PHP_METHOD(Phalcon_Db_Column, isNumeric) {

	

	RETURN_MEMBER(getThis(), "_isNumeric");

}

/**
 * Check whether column have first position in table
 */
PHP_METHOD(Phalcon_Db_Column, isFirst) {

	

	RETURN_MEMBER(getThis(), "_first");

}

/**
 * Check whether field absolute to position in table
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getAfterPosition) {

	

	RETURN_MEMBER(getThis(), "_after");

}

/**
 * Returns the type of bind handling
 */
PHP_METHOD(Phalcon_Db_Column, getBindType) {

	

	RETURN_MEMBER(getThis(), "_bindType");

}

/**
 * Restores the internal state of a Phalcon\Db\Column object
 */
PHP_METHOD(Phalcon_Db_Column, __set_state) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *definition = NULL, *columnType = NULL, *notNull = NULL, *size = NULL, *dunsigned = NULL, *after = NULL, *isNumeric = NULL, *first = NULL, *bindType = NULL, *primary = NULL, *columnName = NULL, *scale = NULL, *defaultValue = NULL, *autoIncrement = NULL, *columnTypeReference = NULL, *columnTypeValues = NULL, *_0$$7, *_1$$12;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	data = data_param;


	ZEPHIR_OBS_VAR(columnName);
	if (!(zephir_array_isset_string_fetch(&columnName, data, SS("_columnName"), 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(columnName);
		if (!(zephir_array_isset_string_fetch(&columnName, data, SS("_name"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Column name is required", "phalcon/db/column.zep", 489);
			return;
		}
	}
	ZEPHIR_INIT_VAR(definition);
	array_init(definition);
	if (zephir_array_isset_string_fetch(&columnType, data, SS("_type"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("type"), &columnType, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&columnTypeReference, data, SS("_typeReference"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("typeReference"), &columnTypeReference, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(_0$$7);
		ZVAL_LONG(_0$$7, -1);
		zephir_array_update_string(&definition, SL("typeReference"), &_0$$7, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&columnTypeValues, data, SS("_typeValues"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("typeValues"), &columnTypeValues, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&notNull, data, SS("_notNull"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("notNull"), &notNull, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&primary, data, SS("_primary"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("primary"), &primary, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&size, data, SS("_size"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("size"), &size, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&scale, data, SS("_scale"), 1 TSRMLS_CC)) {
		zephir_array_fetch_string(&_1$$12, definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/column.zep", 523 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(_1$$12, 0) || ZEPHIR_IS_LONG(_1$$12, 7) || ZEPHIR_IS_LONG(_1$$12, 3) || ZEPHIR_IS_LONG(_1$$12, 9) || ZEPHIR_IS_LONG(_1$$12, 14)) {
				zephir_array_update_string(&definition, SL("scale"), &scale, PH_COPY | PH_SEPARATE);
				break;
			}
		} while(0);

	}
	if (zephir_array_isset_string_fetch(&defaultValue, data, SS("_default"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("default"), &defaultValue, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&dunsigned, data, SS("_unsigned"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("unsigned"), &dunsigned, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&autoIncrement, data, SS("_autoIncrement"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("autoIncrement"), &autoIncrement, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&isNumeric, data, SS("_isNumeric"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("isNumeric"), &isNumeric, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&first, data, SS("_first"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("first"), &first, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&after, data, SS("_after"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("after"), &after, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&bindType, data, SS("_bindType"), 1 TSRMLS_CC)) {
		zephir_array_update_string(&definition, SL("bindType"), &bindType, PH_COPY | PH_SEPARATE);
	}
	object_init_ex(return_value, phalcon_db_column_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 167, columnName, definition);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether column has default value
 */
PHP_METHOD(Phalcon_Db_Column, hasDefault) {

	zval *_0 = NULL, *_1;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isautoincrement", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(_0)) {
		RETURN_MM_BOOL(0);
	}
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_default"), PH_NOISY_CC);
	RETURN_MM_BOOL(Z_TYPE_P(_1) != IS_NULL);

}

