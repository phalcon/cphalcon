
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"


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
	 * Whether the column is an array of its base type. Recognized by the
	 * PostgreSQL dialect (e.g. `INTEGER[]`, `TEXT[]`). MySQL and SQLite
	 * ignore the flag.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("isArray"), 0, ZEND_ACC_PROTECTED);
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
	 * Generation expression for `GENERATED ALWAYS AS (...)`. Null when the
	 * column is not a generated/computed column.
	 *
	 * @var string|null
	 */
	zend_declare_property_null(phalcon_db_column_ce, SL("generated"), ZEND_ACC_PROTECTED);
	/**
	 * Whether a generated column is `STORED` (true) or `VIRTUAL` (false).
	 * Ignored when the column is not generated. PostgreSQL only supports
	 * `STORED` and emits it regardless of this flag.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("generationStored"), 0, ZEND_ACC_PROTECTED);
	/**
	 * The column have some numeric type?
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("isNumeric"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Whether the column is `INVISIBLE` (MySQL 8.0.23+). Invisible columns
	 * are excluded from `SELECT *` expansion but can still be referenced
	 * explicitly.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_column_ce, SL("invisible"), 0, ZEND_ACC_PROTECTED);
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
	phalcon_db_column_ce->create_object = zephir_init_properties_Phalcon_Db_Column;
	/**
	 * Bind Type Blob
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_BLOB"), 3);

	/**
	 * Bind Type Bool
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_BOOL"), 5);

	/**
	 * Bind Type Decimal
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_DECIMAL"), 32);

	/**
	 * Bind Type Integer
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_INT"), 1);

	/**
	 * Bind Type Null
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_NULL"), 0);

	/**
	 * Bind Type String
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_PARAM_STR"), 2);

	/**
	 * Skip binding by type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("BIND_SKIP"), 1024);

	/**
	 * Big integer abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BIGINTEGER"), 14);

	/**
	 * Bit abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BIT"), 19);

	/**
	 * Binary abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BINARY"), 27);

	/**
	 * Blob abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BLOB"), 11);

	/**
	 * Bool abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BOOLEAN"), 8);

	/**
	 * Char abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_CHAR"), 5);

	/**
	 * Date abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATE"), 1);

	/**
	 * Datetime abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATETIME"), 4);

	/**
	 * Decimal abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DECIMAL"), 3);

	/**
	 * Double abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DOUBLE"), 9);

	/**
	 * Enum abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_ENUM"), 18);

	/**
	 * Float abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_FLOAT"), 7);

	/**
	 * Int abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_INTEGER"), 0);

	/**
	 * Json abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_JSON"), 15);

	/**
	 * Jsonb abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_JSONB"), 16);

	/**
	 * Longblob abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_LONGBLOB"), 13);

	/**
	 * Longtext abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_LONGTEXT"), 24);

	/**
	 * Mediumblob abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_MEDIUMBLOB"), 12);

	/**
	 * Mediumintegerr abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_MEDIUMINTEGER"), 21);

	/**
	 * Mediumtext abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_MEDIUMTEXT"), 23);

	/**
	 * Smallint abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_SMALLINTEGER"), 22);

	/**
	 * Text abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TEXT"), 6);

	/**
	 * Time abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TIME"), 20);

	/**
	 * Timestamp abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TIMESTAMP"), 17);

	/**
	 * Tinyblob abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TINYBLOB"), 10);

	/**
	 * Tinyint abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TINYINTEGER"), 26);

	/**
	 * Tinytext abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TINYTEXT"), 25);

	/**
	 * UUID abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_UUID"), 29);

	/**
	 * Varbinary abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_VARBINARY"), 28);

	/**
	 * Varchar abstract data type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_VARCHAR"), 2);

	/**
	 * PostgreSQL `BYTEA` binary type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_BYTEA"), 30);

	/**
	 * PostgreSQL `INET` IPv4/IPv6 address type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_INET"), 31);

	/**
	 * PostgreSQL `CIDR` network-address type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_CIDR"), 32);

	/**
	 * PostgreSQL `MACADDR` MAC-address type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_MACADDR"), 33);

	/**
	 * PostgreSQL `INT4RANGE` range-of-integer type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_INT4RANGE"), 34);

	/**
	 * PostgreSQL `INT8RANGE` range-of-bigint type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_INT8RANGE"), 35);

	/**
	 * PostgreSQL `NUMRANGE` range-of-numeric type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_NUMRANGE"), 36);

	/**
	 * PostgreSQL `TSRANGE` range-of-timestamp (without time zone) type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TSRANGE"), 37);

	/**
	 * PostgreSQL `TSTZRANGE` range-of-timestamp (with time zone) type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_TSTZRANGE"), 38);

	/**
	 * PostgreSQL `DATERANGE` range-of-date type
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_DATERANGE"), 39);

	/**
	 * Spatial `GEOMETRY` base type (MySQL 5.7+; PostgreSQL + PostGIS)
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_GEOMETRY"), 40);

	/**
	 * Spatial `POINT` type (MySQL; PostgreSQL + PostGIS)
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_POINT"), 41);

	/**
	 * Spatial `LINESTRING` type (MySQL; PostgreSQL + PostGIS)
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_LINESTRING"), 42);

	/**
	 * Spatial `POLYGON` type (MySQL; PostgreSQL + PostGIS)
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_POLYGON"), 43);

	/**
	 * Spatial `MULTIPOINT` type (MySQL; PostgreSQL + PostGIS)
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_MULTIPOINT"), 44);

	/**
	 * Spatial `MULTILINESTRING` type (MySQL; PostgreSQL + PostGIS)
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_MULTILINESTRING"), 45);

	/**
	 * Spatial `MULTIPOLYGON` type (MySQL; PostgreSQL + PostGIS)
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_MULTIPOLYGON"), 46);

	/**
	 * Spatial `GEOMETRYCOLLECTION` type (MySQL; PostgreSQL + PostGIS)
	 *
	 * @var int
	 */
	zephir_declare_class_constant_long(phalcon_db_column_ce, SL("TYPE_GEOMETRYCOLLECTION"), 47);

	zend_class_implements(phalcon_db_column_ce, 1, phalcon_db_columninterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Db\Column constructor
 */
PHP_METHOD(Phalcon_Db_Column, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval name_zv, *definition_param = NULL, __$true, __$false, type, notNull, primary, size, scale, dunsigned, first, after, bindType, isNumeric, autoIncrement, defaultValue, typeReference, typeValues, comment, generated, generationStored, invisible, isArray, _0$$3, _1$$11, _2$$19, _3$$26, _4$$25, _6$$25, _5$$27, _7$$28;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
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
	ZVAL_UNDEF(&generated);
	ZVAL_UNDEF(&generationStored);
	ZVAL_UNDEF(&invisible);
	ZVAL_UNDEF(&isArray);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$11);
	ZVAL_UNDEF(&_2$$19);
	ZVAL_UNDEF(&_3$$26);
	ZVAL_UNDEF(&_4$$25);
	ZVAL_UNDEF(&_6$$25);
	ZVAL_UNDEF(&_5$$27);
	ZVAL_UNDEF(&_7$$28);
	ZVAL_UNDEF(&definition);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		ZEPHIR_Z_PARAM_ARRAY(definition, definition_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name_zv);
	zephir_memory_observe(&type);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&type, &definition, SL("type"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_db_exceptions_columntyperequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 419);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Db/Column.zep", 595);
		ZEPHIR_MM_RESTORE();
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
			ZEPHIR_INIT_VAR(&_1$$11);
			object_init_ex(&_1$$11, phalcon_db_exceptions_columntyperejectsscale_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$11, "__construct", NULL, 420);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$11, "phalcon/Db/Column.zep", 643);
			ZEPHIR_MM_RESTORE();
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
				ZEPHIR_INIT_VAR(&_2$$19);
				object_init_ex(&_2$$19, phalcon_db_exceptions_columntyperejectsautoincrement_ce);
				ZEPHIR_CALL_METHOD(NULL, &_2$$19, "__construct", NULL, 421);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_2$$19, "phalcon/Db/Column.zep", 685);
				ZEPHIR_MM_RESTORE();
				return;
			} while(0);

		}
	}
	zephir_memory_observe(&first);
	if (zephir_array_isset_string_fetch(&first, &definition, SL("first"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("first"), &first);
	}
	zephir_memory_observe(&after);
	if (zephir_array_isset_string_fetch(&after, &definition, SL("after"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("after"), &after);
	}
	zephir_memory_observe(&bindType);
	if (zephir_array_isset_string_fetch(&bindType, &definition, SL("bindType"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("bindType"), &bindType);
	}
	zephir_memory_observe(&comment);
	if (zephir_array_isset_string_fetch(&comment, &definition, SL("comment"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("comment"), &comment);
	}
	zephir_memory_observe(&generated);
	if (zephir_array_isset_string_fetch(&generated, &definition, SL("generated"), 0)) {
		if (Z_TYPE_P(&generated) != IS_NULL) {
			if (UNEXPECTED(Z_TYPE_P(&generated) != IS_STRING)) {
				ZEPHIR_INIT_VAR(&_3$$26);
				object_init_ex(&_3$$26, phalcon_db_exceptions_invalidgenerationexpression_ce);
				ZEPHIR_CALL_METHOD(NULL, &_3$$26, "__construct", NULL, 422);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_3$$26, "phalcon/Db/Column.zep", 726);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property(&_4$$25, this_ptr, ZEND_STRL("autoIncrement"), PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(zephir_is_true(&_4$$25))) {
				ZEPHIR_INIT_VAR(&_5$$27);
				object_init_ex(&_5$$27, phalcon_db_exceptions_generatedautoincrementconflict_ce);
				ZEPHIR_CALL_METHOD(NULL, &_5$$27, "__construct", NULL, 423);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$27, "phalcon/Db/Column.zep", 730);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property(&_6$$25, this_ptr, ZEND_STRL("defaultValue"), PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(Z_TYPE_P(&_6$$25) != IS_NULL)) {
				ZEPHIR_INIT_VAR(&_7$$28);
				object_init_ex(&_7$$28, phalcon_db_exceptions_generateddefaultconflict_ce);
				ZEPHIR_CALL_METHOD(NULL, &_7$$28, "__construct", NULL, 424);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_7$$28, "phalcon/Db/Column.zep", 734);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("generated"), &generated);
		}
	}
	if (zephir_array_isset_string_fetch(&generationStored, &definition, SL("generationStored"), 1)) {
		if (zephir_get_boolval(&generationStored)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("generationStored"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("generationStored"), &__$false);
		}
	}
	if (zephir_array_isset_string_fetch(&invisible, &definition, SL("invisible"), 1)) {
		if (zephir_get_boolval(&invisible)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("invisible"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("invisible"), &__$false);
		}
	}
	if (zephir_array_isset_string_fetch(&isArray, &definition, SL("array"), 1)) {
		if (zephir_get_boolval(&isArray)) {
			zephir_update_property_zval(this_ptr, ZEND_STRL("isArray"), &__$true);
		} else {
			zephir_update_property_zval(this_ptr, ZEND_STRL("isArray"), &__$false);
		}
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

	RETURN_MEMBER_TYPED(getThis(), "bindType", IS_LONG);
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
 * Returns the generation expression for a generated/computed column.
 * Returns `null` when the column is not generated.
 */
PHP_METHOD(Phalcon_Db_Column, getGenerationExpression)
{

	RETURN_MEMBER(getThis(), "generated");
}

/**
 * Column's name
 */
PHP_METHOD(Phalcon_Db_Column, getName)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

/**
 * Integer column number scale
 */
PHP_METHOD(Phalcon_Db_Column, getScale)
{

	RETURN_MEMBER_TYPED(getThis(), "scale", IS_LONG);
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

	RETURN_MEMBER_TYPED(getThis(), "typeReference", IS_LONG);
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
 * Whether the column is an array of its base type. Recognized by the
 * PostgreSQL dialect (e.g. `INTEGER[]`, `TEXT[]`); MySQL and SQLite
 * ignore the flag.
 */
PHP_METHOD(Phalcon_Db_Column, isArray)
{

	RETURN_MEMBER(getThis(), "isArray");
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
 * Whether the column is a generated/computed column.
 */
PHP_METHOD(Phalcon_Db_Column, isGenerated)
{
	zval _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("generated"), PH_NOISY_CC | PH_READONLY);
	RETURN_BOOL(Z_TYPE_P(&_0) != IS_NULL);
}

/**
 * Whether a generated column is `STORED`. `false` means `VIRTUAL`.
 * Always meaningful only when `isGenerated()` is `true`.
 */
PHP_METHOD(Phalcon_Db_Column, isGenerationStored)
{

	RETURN_MEMBER(getThis(), "generationStored");
}

/**
 * Whether the column is declared `INVISIBLE` (MySQL 8.0.23+). Invisible
 * columns are excluded from `SELECT *` expansion but can still be
 * referenced explicitly. PostgreSQL and SQLite have no equivalent and
 * dialects targeting them ignore the flag.
 */
PHP_METHOD(Phalcon_Db_Column, isInvisible)
{

	RETURN_MEMBER(getThis(), "invisible");
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

zend_object *zephir_init_properties_Phalcon_Db_Column(zend_class_entry *class_type)
{
		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("typeValues"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("typeValues"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

