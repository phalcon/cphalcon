
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
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
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
	 * Column Position
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_after"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Column is autoIncrement?
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_autoIncrement"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Bind Type
	 */
	zend_declare_property_long(phalcon_db_column_ce, SL("_bindType"), 2, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Default column value
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_default"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Position is first
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_first"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * The column have some numeric type?
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_isNumeric"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Column's name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Column not nullable?
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_notNull"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Column is part of the primary key?
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_primary"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Integer column number scale
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_db_column_ce, SL("_scale"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Schema which table related is
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("_schemaName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Integer column size
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_db_column_ce, SL("_size"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Column data type
	 *
	 * @var int
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
	 * Integer column unsigned?
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("_unsigned"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Bind Type Blob
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_BLOB"), 3);

	/**
	 * Bind Type Bool
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_BOOL"), 5);

	/**
	 * Bind Type Decimal
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_DECIMAL"), 32);

	/**
	 * Bind Type Integer
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_INT"), 1);

	/**
	 * Bind Type Null
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_NULL"), 0);

	/**
	 * Bind Type String
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_STR"), 2);

	/**
	 * Skip binding by type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_SKIP"), 1024);

	/**
	 * Big integer abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BIGINTEGER"), 14);

	/**
	 * Bit abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BIT"), 19);

	/**
	 * Blob abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BLOB"), 11);

	/**
	 * Bool abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BOOLEAN"), 8);

	/**
	 * Char abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_CHAR"), 5);

	/**
	 * Date abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATE"), 1);

	/**
	 * Datetime abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATETIME"), 4);

	/**
	 * Decimal abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DECIMAL"), 3);

	/**
	 * Double abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DOUBLE"), 9);

	/**
	 * Enum abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_ENUM"), 18);

	/**
	 * Float abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_FLOAT"), 7);

	/**
	 * Int abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_INTEGER"), 0);

	/**
	 * Json abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_JSON"), 15);

	/**
	 * Jsonb abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_JSONB"), 16);

	/**
	 * Longblob abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_LONGBLOB"), 13);

	/**
	 * Longtext abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_LONGTEXT"), 24);

	/**
	 * Mediumblob abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_MEDIUMBLOB"), 12);

	/**
	 * Mediumintegerr abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_MEDIUMINTEGER"), 21);

	/**
	 * Mediumtext abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_MEDIUMTEXT"), 23);

	/**
	 * Smallint abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_SMALLINTEGER"), 22);

	/**
	 * Text abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TEXT"), 6);

	/**
	 * Time abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TIME"), 20);

	/**
	 * Timestamp abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TIMESTAMP"), 17);

	/**
	 * Tinyblob abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TINYBLOB"), 10);

	/**
	 * Tinyint abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TINYINTEGER"), 26);

	/**
	 * Tinytext abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TINYTEXT"), 25);

	/**
	 * Varchar abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_VARCHAR"), 2);

	zend_class_implements(phalcon_db_column_ce TSRMLS_CC, 1, phalcon_db_columninterface_ce);
	return SUCCESS;

}

/**
 * Default column value
 */
PHP_METHOD(Phalcon_Db_Column, getDefault) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_default");

}

/**
 * Column's name
 */
PHP_METHOD(Phalcon_Db_Column, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_name");

}

/**
 * Integer column number scale
 */
PHP_METHOD(Phalcon_Db_Column, getScale) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_scale");

}

/**
 * Schema which table related is
 */
PHP_METHOD(Phalcon_Db_Column, getSchemaName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_schemaName");

}

/**
 * Integer column size
 */
PHP_METHOD(Phalcon_Db_Column, getSize) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_size");

}

/**
 * Column data type
 */
PHP_METHOD(Phalcon_Db_Column, getType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_type");

}

/**
 * Column data type reference
 */
PHP_METHOD(Phalcon_Db_Column, getTypeReference) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_typeReference");

}

/**
 * Column data type values
 */
PHP_METHOD(Phalcon_Db_Column, getTypeValues) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_typeValues");

}

/**
 * Phalcon\Db\Column constructor
 */
PHP_METHOD(Phalcon_Db_Column, __construct) {

	zval definition;
	zval *name_param = NULL, *definition_param = NULL, __$true, __$false, type, notNull, primary, size, scale, dunsigned, first, after, bindType, isNumeric, autoIncrement, defaultValue, typeReference, typeValues;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&notNull);
	ZVAL_UNDEF(&primary);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&scale);
	ZVAL_UNDEF(&dunsigned);
	ZVAL_UNDEF(&first);
	ZVAL_UNDEF(&after);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&isNumeric);
	ZVAL_UNDEF(&autoIncrement);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&typeReference);
	ZVAL_UNDEF(&typeValues);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition_param);

	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
		ZVAL_EMPTY_STRING(&name);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	zephir_update_property_zval(this_ptr, SL("_name"), &name);
	ZEPHIR_OBS_VAR(&type);
	if (zephir_array_isset_string_fetch(&type, &definition, SL("type"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_type"), &type);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Column type is required", "phalcon/db/column.zep", 335);
		return;
	}
	ZEPHIR_OBS_VAR(&typeReference);
	if (zephir_array_isset_string_fetch(&typeReference, &definition, SL("typeReference"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_typeReference"), &typeReference);
	}
	ZEPHIR_OBS_VAR(&typeValues);
	if (zephir_array_isset_string_fetch(&typeValues, &definition, SL("typeValues"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_typeValues"), &typeValues);
	}
	ZEPHIR_OBS_VAR(&notNull);
	if (zephir_array_isset_string_fetch(&notNull, &definition, SL("notNull"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_notNull"), &notNull);
	}
	ZEPHIR_OBS_VAR(&primary);
	if (zephir_array_isset_string_fetch(&primary, &definition, SL("primary"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_primary"), &primary);
	}
	ZEPHIR_OBS_VAR(&size);
	if (zephir_array_isset_string_fetch(&size, &definition, SL("size"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_size"), &size);
	}
	ZEPHIR_OBS_VAR(&scale);
	if (zephir_array_isset_string_fetch(&scale, &definition, SL("scale"), 0)) {
		do {
			if (ZEPHIR_IS_LONG(&type, 0) || ZEPHIR_IS_LONG(&type, 7) || ZEPHIR_IS_LONG(&type, 3) || ZEPHIR_IS_LONG(&type, 9) || ZEPHIR_IS_LONG(&type, 14)) {
				zephir_update_property_zval(this_ptr, SL("_scale"), &scale);
				break;
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Column type does not support scale parameter", "phalcon/db/column.zep", 379);
			return;
		} while(0);

	}
	ZEPHIR_OBS_VAR(&defaultValue);
	if (zephir_array_isset_string_fetch(&defaultValue, &definition, SL("default"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_default"), &defaultValue);
	}
	ZEPHIR_OBS_VAR(&dunsigned);
	if (zephir_array_isset_string_fetch(&dunsigned, &definition, SL("unsigned"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_unsigned"), &dunsigned);
	}
	ZEPHIR_OBS_VAR(&isNumeric);
	if (zephir_array_isset_string_fetch(&isNumeric, &definition, SL("isNumeric"), 0)) {
		zephir_update_property_zval(this_ptr, SL("_isNumeric"), &isNumeric);
	}
	ZEPHIR_OBS_VAR(&autoIncrement);
	if (zephir_array_isset_string_fetch(&autoIncrement, &definition, SL("autoIncrement"), 0)) {
		if (!(zephir_is_true(&autoIncrement))) {
			if (0) {
				zephir_update_property_zval(this_ptr, SL("_autoIncrement"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, SL("_autoIncrement"), &__$false);
			}
		} else {
			do {
				if (ZEPHIR_IS_LONG(&type, 0) || ZEPHIR_IS_LONG(&type, 14)) {
					if (1) {
						zephir_update_property_zval(this_ptr, SL("_autoIncrement"), &__$true);
					} else {
						zephir_update_property_zval(this_ptr, SL("_autoIncrement"), &__$false);
					}
					break;
				}
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Column type cannot be auto-increment", "phalcon/db/column.zep", 419);
				return;
			} while(0);

		}
	}
	if (zephir_array_isset_string_fetch(&first, &definition, SL("first"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_first"), &first);
	}
	if (zephir_array_isset_string_fetch(&after, &definition, SL("after"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_after"), &after);
	}
	if (zephir_array_isset_string_fetch(&bindType, &definition, SL("bindType"), 1)) {
		zephir_update_property_zval(this_ptr, SL("_bindType"), &bindType);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Restores the internal state of a Phalcon\Db\Column object
 */
PHP_METHOD(Phalcon_Db_Column, __set_state) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, definition, columnType, notNull, size, dunsigned, after, isNumeric, first, bindType, primary, columnName, scale, defaultValue, autoIncrement, columnTypeReference, columnTypeValues, _0$$7, _1$$12;
	zval data;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&notNull);
	ZVAL_UNDEF(&size);
	ZVAL_UNDEF(&dunsigned);
	ZVAL_UNDEF(&after);
	ZVAL_UNDEF(&isNumeric);
	ZVAL_UNDEF(&first);
	ZVAL_UNDEF(&bindType);
	ZVAL_UNDEF(&primary);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&scale);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&autoIncrement);
	ZVAL_UNDEF(&columnTypeReference);
	ZVAL_UNDEF(&columnTypeValues);
	ZVAL_UNDEF(&_0$$7);
	ZVAL_UNDEF(&_1$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);


	ZEPHIR_OBS_VAR(&columnName);
	if (!(zephir_array_isset_string_fetch(&columnName, &data, SL("_columnName"), 0))) {
		ZEPHIR_OBS_NVAR(&columnName);
		if (!(zephir_array_isset_string_fetch(&columnName, &data, SL("_name"), 0))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Column name is required", "phalcon/db/column.zep", 459);
			return;
		}
	}
	ZEPHIR_INIT_VAR(&definition);
	array_init(&definition);
	if (zephir_array_isset_string_fetch(&columnType, &data, SL("_type"), 1)) {
		zephir_array_update_string(&definition, SL("type"), &columnType, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&columnTypeReference, &data, SL("_typeReference"), 1)) {
		zephir_array_update_string(&definition, SL("typeReference"), &columnTypeReference, PH_COPY | PH_SEPARATE);
	} else {
		ZEPHIR_INIT_VAR(&_0$$7);
		ZVAL_LONG(&_0$$7, -1);
		zephir_array_update_string(&definition, SL("typeReference"), &_0$$7, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&columnTypeValues, &data, SL("_typeValues"), 1)) {
		zephir_array_update_string(&definition, SL("typeValues"), &columnTypeValues, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&notNull, &data, SL("_notNull"), 1)) {
		zephir_array_update_string(&definition, SL("notNull"), &notNull, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&primary, &data, SL("_primary"), 1)) {
		zephir_array_update_string(&definition, SL("primary"), &primary, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&size, &data, SL("_size"), 1)) {
		zephir_array_update_string(&definition, SL("size"), &size, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&scale, &data, SL("_scale"), 1)) {
		zephir_array_fetch_string(&_1$$12, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/column.zep", 493 TSRMLS_CC);
		do {
			if (ZEPHIR_IS_LONG(&_1$$12, 0) || ZEPHIR_IS_LONG(&_1$$12, 7) || ZEPHIR_IS_LONG(&_1$$12, 3) || ZEPHIR_IS_LONG(&_1$$12, 9) || ZEPHIR_IS_LONG(&_1$$12, 14)) {
				zephir_array_update_string(&definition, SL("scale"), &scale, PH_COPY | PH_SEPARATE);
				break;
			}
		} while(0);

	}
	if (zephir_array_isset_string_fetch(&defaultValue, &data, SL("_default"), 1)) {
		zephir_array_update_string(&definition, SL("default"), &defaultValue, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&dunsigned, &data, SL("_unsigned"), 1)) {
		zephir_array_update_string(&definition, SL("unsigned"), &dunsigned, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&autoIncrement, &data, SL("_autoIncrement"), 1)) {
		zephir_array_update_string(&definition, SL("autoIncrement"), &autoIncrement, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&isNumeric, &data, SL("_isNumeric"), 1)) {
		zephir_array_update_string(&definition, SL("isNumeric"), &isNumeric, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&first, &data, SL("_first"), 1)) {
		zephir_array_update_string(&definition, SL("first"), &first, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&after, &data, SL("_after"), 1)) {
		zephir_array_update_string(&definition, SL("after"), &after, PH_COPY | PH_SEPARATE);
	}
	if (zephir_array_isset_string_fetch(&bindType, &data, SL("_bindType"), 1)) {
		zephir_array_update_string(&definition, SL("bindType"), &bindType, PH_COPY | PH_SEPARATE);
	}
	object_init_ex(return_value, phalcon_db_column_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 142, &columnName, &definition);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether field absolute to position in table
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Column, getAfterPosition) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_after");

}

/**
 * Returns the type of bind handling
 */
PHP_METHOD(Phalcon_Db_Column, getBindType) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_bindType");

}

/**
 * Check whether column has default value
 */
PHP_METHOD(Phalcon_Db_Column, hasDefault) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isautoincrement", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_1, this_ptr, SL("_default"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(Z_TYPE_P(&_1) != IS_NULL);

}

/**
 * Auto-Increment
 */
PHP_METHOD(Phalcon_Db_Column, isAutoIncrement) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_autoIncrement");

}

/**
 * Check whether column have first position in table
 */
PHP_METHOD(Phalcon_Db_Column, isFirst) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_first");

}

/**
 * Not null
 */
PHP_METHOD(Phalcon_Db_Column, isNotNull) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_notNull");

}

/**
 * Check whether column have an numeric type
 */
PHP_METHOD(Phalcon_Db_Column, isNumeric) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_isNumeric");

}

/**
 * Column is part of the primary key?
 */
PHP_METHOD(Phalcon_Db_Column, isPrimary) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_primary");

}

/**
 * Returns true if number column is unsigned
 */
PHP_METHOD(Phalcon_Db_Column, isUnsigned) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "_unsigned");

}

