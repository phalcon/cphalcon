
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
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the
 * LICENSE.txt file that was distributed with this source code.
 */
/**
 * Allows to define columns to be used on create or alter table operations
 *
 *```php
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
 *         "comment"       => "",
 *     ]
 * );
 *
 * // Add column to existing table
 * $connection->addColumn("robots", null, $column);
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Column)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Column, phalcon, db_column, phalcon_db_column_method_entry, 0);

	/**
	 * Column Position
	 *
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("after"), ZEND_ACC_PROTECTED);
	/**
	 * Column is autoIncrement?
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("autoIncrement"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Bind Type
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_db_column_ce, SL("bindType"), 2, ZEND_ACC_PROTECTED);
	/**
	 * Column's comment
	 *
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("comment"), ZEND_ACC_PROTECTED);
	/**
	 * Default column value
	 *
	 * @var mixed|null
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("defaultValue"), ZEND_ACC_PROTECTED);
	/**
	 * Position is first
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("first"), 0, ZEND_ACC_PROTECTED);
	/**
	 * The column have some numeric type?
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("isNumeric"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Column's name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("name"), ZEND_ACC_PROTECTED);
	/**
	 * Column not nullable?
	 *
	 * Default SQL definition is NOT NULL.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("notNull"), 1, ZEND_ACC_PROTECTED);
	/**
	 * Column is part of the primary key?
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("primary"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Integer column number scale
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_db_column_ce, SL("scale"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Integer column size
	 *
	 * @var int|string
	 */
	zend_declare_property_long(phalcon_db_column_ce, SL("size"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Column data type
	 *
	 * @var int
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("type"), ZEND_ACC_PROTECTED);
	/**
	 * Column data type reference
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_db_column_ce, SL("typeReference"), -1, ZEND_ACC_PROTECTED);
	/**
	 * Column data type values
	 *
	 * @var array|string
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("typeValues"), ZEND_ACC_PROTECTED);
	/**
	 * Integer column unsigned?
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("unsigned"), 0, ZEND_ACC_PROTECTED);
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
	 * Binary abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BINARY"), 27);

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
	 * Varbinary abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_VARBINARY"), 28);

	/**
	 * Varchar abstract data type
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_VARCHAR"), 2);

	zend_class_implements(phalcon_db_column_ce, 1, phalcon_db_columninterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Db\Column constructor
 */
PHP_METHOD(Phalcon_Db_Column, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval definition;
	zval *name_param = NULL, *definition_param = NULL, __$true, __$false, type, notNull, primary, size, scale, dunsigned, first, after, bindType, isNumeric, autoIncrement, defaultValue, typeReference, typeValues, comment;
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
	ZVAL_UNDEF(&comment);
	ZVAL_UNDEF(&definition);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ARRAY(definition)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 2, 0, &name_param, &definition_param);
	if (UNEXPECTED(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(&name, name_param);
	} else {
		ZEPHIR_INIT_VAR(&name);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name);
	zephir_memory_observe(&type);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&type, &definition, SL("type"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Column type is required", "phalcon/Db/Column.zep", 348);
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type);
	zephir_memory_observe(&typeReference);
	if (zephir_array_isset_string_fetch(&typeReference, &definition, SL("typeReference"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("typeReference"), &typeReference);
	}
	zephir_memory_observe(&typeValues);
	if (zephir_array_isset_string_fetch(&typeValues, &definition, SL("typeValues"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("typeValues"), &typeValues);
	}
	zephir_memory_observe(&notNull);
	if (zephir_array_isset_string_fetch(&notNull, &definition, SL("notNull"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("notNull"), &notNull);
	}
	zephir_memory_observe(&primary);
	if (zephir_array_isset_string_fetch(&primary, &definition, SL("primary"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("primary"), &primary);
	}
	zephir_memory_observe(&size);
	if (zephir_array_isset_string_fetch(&size, &definition, SL("size"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("size"), &size);
	}
	zephir_memory_observe(&scale);
	if (zephir_array_isset_string_fetch(&scale, &definition, SL("scale"), 0)) {
		do {
			if (ZEPHIR_IS_LONG(&type, 14) || ZEPHIR_IS_LONG(&type, 3) || ZEPHIR_IS_LONG(&type, 9) || ZEPHIR_IS_LONG(&type, 7) || ZEPHIR_IS_LONG(&type, 0) || ZEPHIR_IS_LONG(&type, 21) || ZEPHIR_IS_LONG(&type, 22) || ZEPHIR_IS_LONG(&type, 26)) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("scale"), &scale);
				break;
			}
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Column type does not support scale parameter", "phalcon/Db/Column.zep", 398);
			return;
		} while(0);

	}
	zephir_memory_observe(&defaultValue);
	if (zephir_array_isset_string_fetch(&defaultValue, &definition, SL("default"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("defaultValue"), &defaultValue);
	}
	zephir_memory_observe(&dunsigned);
	if (zephir_array_isset_string_fetch(&dunsigned, &definition, SL("unsigned"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("unsigned"), &dunsigned);
	}
	zephir_memory_observe(&isNumeric);
	if (zephir_array_isset_string_fetch(&isNumeric, &definition, SL("isNumeric"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("isNumeric"), &isNumeric);
	}
	zephir_memory_observe(&autoIncrement);
	if (zephir_array_isset_string_fetch(&autoIncrement, &definition, SL("autoIncrement"), 0)) {
		if (!(zephir_is_true(&autoIncrement))) {
			if (0) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("autoIncrement"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("autoIncrement"), &__$false);
			}
		} else {
			do {
				if (ZEPHIR_IS_LONG(&type, 14) || ZEPHIR_IS_LONG(&type, 0) || ZEPHIR_IS_LONG(&type, 21) || ZEPHIR_IS_LONG(&type, 22) || ZEPHIR_IS_LONG(&type, 26)) {
					if (1) {
						zephir_update_property_zval(this_ptr, ZEND_STRL("autoIncrement"), &__$true);
					} else {
						zephir_update_property_zval(this_ptr, ZEND_STRL("autoIncrement"), &__$false);
					}
					break;
				}
				ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Column type cannot be auto-increment", "phalcon/Db/Column.zep", 442);
				return;
			} while(0);

		}
	}
	if (zephir_array_isset_string_fetch(&first, &definition, SL("first"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("first"), &first);
	}
	if (zephir_array_isset_string_fetch(&after, &definition, SL("after"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("after"), &after);
	}
	if (zephir_array_isset_string_fetch(&bindType, &definition, SL("bindType"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("bindType"), &bindType);
	}
	if (zephir_array_isset_string_fetch(&comment, &definition, SL("comment"), 1)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("comment"), &comment);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Check whether field absolute to position in table
 */
PHP_METHOD(Phalcon_Db_Column, getAfterPosition)
{

	RETURN_MEMBER(getThis(), "after");
}

/**
 * Returns the type of bind handling
 */
PHP_METHOD(Phalcon_Db_Column, getBindType)
{

	RETURN_MEMBER(getThis(), "bindType");
}

/**
 * Column's comment
 */
PHP_METHOD(Phalcon_Db_Column, getComment)
{

	RETURN_MEMBER(getThis(), "comment");
}

/**
 * Default column value
 */
PHP_METHOD(Phalcon_Db_Column, getDefault)
{

	RETURN_MEMBER(getThis(), "defaultValue");
}

/**
 * Column's name
 */
PHP_METHOD(Phalcon_Db_Column, getName)
{

	RETURN_MEMBER(getThis(), "name");
}

/**
 * Integer column number scale
 */
PHP_METHOD(Phalcon_Db_Column, getScale)
{

	RETURN_MEMBER(getThis(), "scale");
}

/**
 * Integer column size
 */
PHP_METHOD(Phalcon_Db_Column, getSize)
{

	RETURN_MEMBER(getThis(), "size");
}

/**
 * Column data type
 */
PHP_METHOD(Phalcon_Db_Column, getType)
{

	RETURN_MEMBER(getThis(), "type");
}

/**
 * Column data type reference
 */
PHP_METHOD(Phalcon_Db_Column, getTypeReference)
{

	RETURN_MEMBER(getThis(), "typeReference");
}

/**
 * Column data type values
 */
PHP_METHOD(Phalcon_Db_Column, getTypeValues)
{

	RETURN_MEMBER(getThis(), "typeValues");
}

/**
 * Check whether column has default value
 */
PHP_METHOD(Phalcon_Db_Column, hasDefault)
{
	zval _0, _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_METHOD(&_0, this_ptr, "isautoincrement", NULL, 0);
	zephir_check_call_status();
	if (zephir_is_true(&_0)) {
		RETURN_MM_BOOL(0);
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("defaultValue"), PH_NOISY_CC | PH_READONLY);
	RETURN_MM_BOOL(Z_TYPE_P(&_1) != IS_NULL);
}

/**
 * Auto-Increment
 */
PHP_METHOD(Phalcon_Db_Column, isAutoIncrement)
{

	RETURN_MEMBER(getThis(), "autoIncrement");
}

/**
 * Check whether column have first position in table
 */
PHP_METHOD(Phalcon_Db_Column, isFirst)
{

	RETURN_MEMBER(getThis(), "first");
}

/**
 * Not null
 */
PHP_METHOD(Phalcon_Db_Column, isNotNull)
{

	RETURN_MEMBER(getThis(), "notNull");
}

/**
 * Check whether column have an numeric type
 */
PHP_METHOD(Phalcon_Db_Column, isNumeric)
{

	RETURN_MEMBER(getThis(), "isNumeric");
}

/**
 * Column is part of the primary key?
 */
PHP_METHOD(Phalcon_Db_Column, isPrimary)
{

	RETURN_MEMBER(getThis(), "primary");
}

/**
 * Returns true if number column is unsigned
 */
PHP_METHOD(Phalcon_Db_Column, isUnsigned)
{

	RETURN_MEMBER(getThis(), "unsigned");
}

