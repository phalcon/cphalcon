
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
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Allows to define indexes to be used on tables. Indexes are a common way
 * to enhance database performance. An index allows the database server to find
 * and retrieve specific rows much faster than it could do without an index.
 *
 * The constructor accepts either the legacy positional form (a plain array
 * of column names) or a definition-array form (an associative array with a
 * `columns` key); the latter is the path used by features such as
 * `invisible` (MySQL 8.0+) and is the form that future per-index modifiers
 * will extend.
 *
 *```php
 * // Legacy positional form
 * $unique = new \Phalcon\Db\Index(
 *     'column_UNIQUE',
 *     [
 *         'column',
 *     ],
 *     'UNIQUE'
 * );
 *
 * $primary = new \Phalcon\Db\Index(
 *     'PRIMARY',
 *     [
 *         'column',
 *     ]
 * );
 *
 * // Definition-array form (MySQL 8.0+ invisible index)
 * $hidden = new \Phalcon\Db\Index(
 *     'idx_hidden',
 *     [
 *         'columns'   => ['col1'],
 *         'type'      => '',
 *         'invisible' => true,
 *     ]
 * );
 *
 * $connection->addIndex("robots", null, $unique);
 * $connection->addIndex("robots", null, $primary);
 * $connection->addIndex("robots", null, $hidden);
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Index)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Index, phalcon, db_index, phalcon_db_index_method_entry, 0);

	/**
	 * Index columns
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_index_ce, SL("columns"), ZEND_ACC_PROTECTED);
	/**
	 * Whether to build the index without taking a strong lock that blocks
	 * writes - emits `CONCURRENTLY` between `INDEX` and the index name on
	 * PostgreSQL (`CREATE INDEX CONCURRENTLY name ON ...`). MySQL and
	 * SQLite have no equivalent and ignore the flag.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_index_ce, SL("concurrent"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Per-column sort directions (`ASC` / `DESC`). Empty array means
	 * "emit no per-column direction" - preserves the legacy plain
	 * `(col1, col2)` rendering. When populated, entries shorter than
	 * the columns list default to `ASC` for the missing positions.
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_index_ce, SL("directions"), ZEND_ACC_PROTECTED);
	/**
	 * Whether the index is declared `INVISIBLE` (MySQL 8.0+). Invisible
	 * indexes are ignored by the optimizer - useful for testing what
	 * happens when an index is removed before actually dropping it.
	 * PostgreSQL and SQLite have no equivalent and ignore the flag.
	 *
	 * @var bool
	 */
	zend_declare_property_bool(phalcon_db_index_ce, SL("invisible"), 0, ZEND_ACC_PROTECTED);
	/**
	 * Index name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_index_ce, SL("name"), ZEND_ACC_PROTECTED);
	/**
	 * Index type
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_index_ce, SL("type"), "", ZEND_ACC_PROTECTED);
	/**
	 * Optional partial-index `WHERE` predicate. Supported by PostgreSQL and
	 * SQLite (`CREATE INDEX ... WHERE <expr>`); MySQL has no partial-index
	 * concept and its dialect ignores this value. Empty string means no
	 * predicate.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_index_ce, SL("where"), "", ZEND_ACC_PROTECTED);
	phalcon_db_index_ce->create_object = zephir_init_properties_Phalcon_Db_Index;

	zend_class_implements(phalcon_db_index_ce, 1, phalcon_db_indexinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Db\Index constructor.
 *
 * Accepts either the legacy positional form `(name, columns, type)` or a
 * definition-array form `(name, ["columns" => [...], "type" => "...",
 * "invisible" => true, ...])`. Detection is based on the presence of a
 * `columns` key in the second argument; when present, the third
 * positional `type` argument is ignored in favor of the definition.
 */
PHP_METHOD(Phalcon_Db_Index, __construct)
{
	zval _3$$5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval columnsOrDefinition;
	zval name_zv, *columnsOrDefinition_param = NULL, type_zv, __$true, __$false, definitionType, invisible, directions, where, concurrent, _0$$3, _2$$3, _1$$4, _4$$8, _5$$10;
	zend_string *name = NULL, *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&type_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&definitionType);
	ZVAL_UNDEF(&invisible);
	ZVAL_UNDEF(&directions);
	ZVAL_UNDEF(&where);
	ZVAL_UNDEF(&concurrent);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&columnsOrDefinition);
	ZVAL_UNDEF(&_3$$5);
	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_STR(name)
		ZEPHIR_Z_PARAM_ARRAY(columnsOrDefinition, columnsOrDefinition_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	columnsOrDefinition_param = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	ZEPHIR_OBS_COPY_OR_DUP(&columnsOrDefinition, columnsOrDefinition_param);
	if (!type) {
		type = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&type_zv);
		ZVAL_STR(&type_zv, type);
	} else {
		zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("name"), &name_zv);
	if (zephir_array_isset_value_string(&columnsOrDefinition, SL("columns"))) {
		zephir_memory_observe(&_0$$3);
		zephir_array_fetch_string(&_0$$3, &columnsOrDefinition, SL("columns"), PH_NOISY, "phalcon/Db/Index.zep", 139);
		if (UNEXPECTED(Z_TYPE_P(&_0$$3) != IS_ARRAY)) {
			ZEPHIR_INIT_VAR(&_1$$4);
			object_init_ex(&_1$$4, phalcon_db_exceptions_invalidindexcolumns_ce);
			ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 439);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_1$$4, "phalcon/Db/Index.zep", 140);
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_fetch_string(&_2$$3, &columnsOrDefinition, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/Db/Index.zep", 143);
		zephir_update_property_zval(this_ptr, ZEND_STRL("columns"), &_2$$3);
		zephir_memory_observe(&definitionType);
		if (zephir_array_isset_string_fetch(&definitionType, &columnsOrDefinition, SL("type"), 0)) {
			zephir_cast_to_string(&_3$$5, &definitionType);
			zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &_3$$5);
		}
		zephir_memory_observe(&invisible);
		if (zephir_array_isset_string_fetch(&invisible, &columnsOrDefinition, SL("invisible"), 0)) {
			if (zephir_get_boolval(&invisible)) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("invisible"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("invisible"), &__$false);
			}
		}
		zephir_memory_observe(&directions);
		if (zephir_array_isset_string_fetch(&directions, &columnsOrDefinition, SL("directions"), 0)) {
			if (UNEXPECTED(Z_TYPE_P(&directions) != IS_ARRAY)) {
				ZEPHIR_INIT_VAR(&_4$$8);
				object_init_ex(&_4$$8, phalcon_db_exceptions_invalidindexdirections_ce);
				ZEPHIR_CALL_METHOD(NULL, &_4$$8, "__construct", NULL, 440);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_4$$8, "phalcon/Db/Index.zep", 155);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("directions"), &directions);
		}
		zephir_memory_observe(&where);
		if (zephir_array_isset_string_fetch(&where, &columnsOrDefinition, SL("where"), 0)) {
			if (UNEXPECTED(Z_TYPE_P(&where) != IS_STRING)) {
				ZEPHIR_INIT_VAR(&_5$$10);
				object_init_ex(&_5$$10, phalcon_db_exceptions_invalidindexwhere_ce);
				ZEPHIR_CALL_METHOD(NULL, &_5$$10, "__construct", NULL, 441);
				zephir_check_call_status();
				zephir_throw_exception_debug(&_5$$10, "phalcon/Db/Index.zep", 163);
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_update_property_zval(this_ptr, ZEND_STRL("where"), &where);
		}
		if (zephir_array_isset_string_fetch(&concurrent, &columnsOrDefinition, SL("concurrently"), 1)) {
			if (zephir_get_boolval(&concurrent)) {
				zephir_update_property_zval(this_ptr, ZEND_STRL("concurrent"), &__$true);
			} else {
				zephir_update_property_zval(this_ptr, ZEND_STRL("concurrent"), &__$false);
			}
		}
	} else {
		zephir_update_property_zval(this_ptr, ZEND_STRL("columns"), &columnsOrDefinition);
		zephir_update_property_zval(this_ptr, ZEND_STRL("type"), &type_zv);
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Index columns
 */
PHP_METHOD(Phalcon_Db_Index, getColumns)
{

	RETURN_MEMBER_TYPED(getThis(), "columns", IS_ARRAY);
}

/**
 * Returns the per-column sort directions array (`ASC` / `DESC`).
 * Empty array means the index was declared without explicit per-column
 * directions and dialects emit the columns plainly. When populated,
 * entries are aligned with `getColumns()`; missing trailing positions
 * default to `ASC` at emission time.
 */
PHP_METHOD(Phalcon_Db_Index, getDirections)
{

	RETURN_MEMBER_TYPED(getThis(), "directions", IS_ARRAY);
}

/**
 * Index name
 */
PHP_METHOD(Phalcon_Db_Index, getName)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

/**
 * Index type
 */
PHP_METHOD(Phalcon_Db_Index, getType)
{

	RETURN_MEMBER_TYPED(getThis(), "type", IS_STRING);
}

/**
 * Returns the partial-index `WHERE` predicate, or an empty string when
 * the index has none. Supported by PostgreSQL and SQLite; ignored by
 * the MySQL dialect (MySQL has no partial-index feature).
 */
PHP_METHOD(Phalcon_Db_Index, getWhere)
{

	RETURN_MEMBER_TYPED(getThis(), "where", IS_STRING);
}

/**
 * Whether the index is built `CONCURRENTLY` (PostgreSQL only). MySQL
 * and SQLite have no equivalent and ignore the flag.
 */
PHP_METHOD(Phalcon_Db_Index, isConcurrent)
{

	RETURN_MEMBER(getThis(), "concurrent");
}

/**
 * Whether the index is declared `INVISIBLE` (MySQL 8.0+). Invisible
 * indexes are ignored by the optimizer but still maintained, so they
 * can be flipped back to visible without a rebuild.
 */
PHP_METHOD(Phalcon_Db_Index, isInvisible)
{

	RETURN_MEMBER(getThis(), "invisible");
}

zend_object *zephir_init_properties_Phalcon_Db_Index(zend_class_entry *class_type)
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
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("directions"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("directions"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

