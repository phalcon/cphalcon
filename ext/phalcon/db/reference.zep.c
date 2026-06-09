
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
 * Allows to define reference constraints on tables
 *
 *```php
 * $reference = new \Phalcon\Db\Reference(
 *     "field_fk",
 *     [
 *         "referencedSchema"  => "invoicing",
 *         "referencedTable"   => "products",
 *         "columns"           => [
 *             "producttype",
 *             "product_code",
 *         ],
 *         "referencedColumns" => [
 *             "type",
 *             "code",
 *         ],
 *     ]
 * );
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Reference)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Reference, phalcon, db_reference, phalcon_db_reference_method_entry, 0);

	/**
	 * Local reference columns
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("columns"), ZEND_ACC_PROTECTED);
	/**
	 * Constraint name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("name"), ZEND_ACC_PROTECTED);
	/**
	 * Referenced Columns
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("referencedColumns"), ZEND_ACC_PROTECTED);
	/**
	 * Referenced Schema
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("referencedSchema"), ZEND_ACC_PROTECTED);
	/**
	 * Referenced Table
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("referencedTable"), ZEND_ACC_PROTECTED);
	/**
	 * Schema name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("schemaName"), ZEND_ACC_PROTECTED);
	/**
	 * ON DELETE
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("onDelete"), ZEND_ACC_PROTECTED);
	/**
	 * ON UPDATE
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("onUpdate"), ZEND_ACC_PROTECTED);
	zend_class_implements(phalcon_db_reference_ce, 1, phalcon_db_referenceinterface_ce);
	return SUCCESS;
}

/**
 * Phalcon\Db\Reference constructor
 */
PHP_METHOD(Phalcon_Db_Reference, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval name_zv, *definition_param = NULL, columns, schema, referencedTable, referencedSchema, referencedColumns, onDelete, onUpdate, _0$$3, _1$$4, _2$$5, _3$$10;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&referencedTable);
	ZVAL_UNDEF(&referencedSchema);
	ZVAL_UNDEF(&referencedColumns);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$10);
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
	zephir_memory_observe(&referencedTable);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&referencedTable, &definition, SL("referencedTable"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_db_exceptions_referencedtablerequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 446);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Db/Reference.zep", 108);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("referencedTable"), &referencedTable);
	zephir_memory_observe(&columns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0)))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_db_exceptions_foreignkeycolumnsrequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 447);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Db/Reference.zep", 114);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("columns"), &columns);
	zephir_memory_observe(&referencedColumns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&referencedColumns, &definition, SL("referencedColumns"), 0)))) {
		ZEPHIR_INIT_VAR(&_2$$5);
		object_init_ex(&_2$$5, phalcon_db_exceptions_referencedcolumnsrequired_ce);
		ZEPHIR_CALL_METHOD(NULL, &_2$$5, "__construct", NULL, 448);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$5, "phalcon/Db/Reference.zep", 120);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("referencedColumns"), &referencedColumns);
	zephir_memory_observe(&schema);
	if (zephir_array_isset_string_fetch(&schema, &definition, SL("schema"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("schemaName"), &schema);
	}
	zephir_memory_observe(&referencedSchema);
	if (zephir_array_isset_string_fetch(&referencedSchema, &definition, SL("referencedSchema"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("referencedSchema"), &referencedSchema);
	}
	zephir_memory_observe(&onDelete);
	if (zephir_array_isset_string_fetch(&onDelete, &definition, SL("onDelete"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("onDelete"), &onDelete);
	}
	zephir_memory_observe(&onUpdate);
	if (zephir_array_isset_string_fetch(&onUpdate, &definition, SL("onUpdate"), 0)) {
		zephir_update_property_zval(this_ptr, ZEND_STRL("onUpdate"), &onUpdate);
	}
	if (UNEXPECTED(zephir_fast_count_int(&columns) != zephir_fast_count_int(&referencedColumns))) {
		ZEPHIR_INIT_VAR(&_3$$10);
		object_init_ex(&_3$$10, phalcon_db_exceptions_referencedcolumncountmismatch_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$10, "__construct", NULL, 449);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$10, "phalcon/Db/Reference.zep", 142);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Local reference columns
 */
PHP_METHOD(Phalcon_Db_Reference, getColumns)
{

	RETURN_MEMBER_TYPED(getThis(), "columns", IS_ARRAY);
}

/**
 * Constraint name
 */
PHP_METHOD(Phalcon_Db_Reference, getName)
{

	RETURN_MEMBER_TYPED(getThis(), "name", IS_STRING);
}

/**
 * Referenced Columns
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedColumns)
{

	RETURN_MEMBER_TYPED(getThis(), "referencedColumns", IS_ARRAY);
}

/**
 * Referenced Schema
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedSchema)
{

	RETURN_MEMBER(getThis(), "referencedSchema");
}

/**
 * Referenced Table
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedTable)
{

	RETURN_MEMBER_TYPED(getThis(), "referencedTable", IS_STRING);
}

/**
 * Schema name
 */
PHP_METHOD(Phalcon_Db_Reference, getSchemaName)
{

	RETURN_MEMBER(getThis(), "schemaName");
}

/**
 * ON DELETE
 */
PHP_METHOD(Phalcon_Db_Reference, getOnDelete)
{

	RETURN_MEMBER(getThis(), "onDelete");
}

/**
 * ON UPDATE
 */
PHP_METHOD(Phalcon_Db_Reference, getOnUpdate)
{

	RETURN_MEMBER(getThis(), "onUpdate");
}

