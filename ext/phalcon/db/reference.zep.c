
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
#include "ext/spl/spl_exceptions.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Db\Reference
 *
 * Allows to define reference constraints on tables
 *
 *<code>
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
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Reference) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Reference, phalcon, db_reference, phalcon_db_reference_method_entry, 0);

	/**
	 * Local reference columns
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("columns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Constraint name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Referenced Columns
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("referencedColumns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Referenced Schema
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("referencedSchema"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Referenced Table
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("referencedTable"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Schema name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("schemaName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * ON DELETE
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("onDelete"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * ON UPDATE
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("onUpdate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_reference_ce TSRMLS_CC, 1, phalcon_db_referenceinterface_ce);
	return SUCCESS;

}

/**
 * Local reference columns
 */
PHP_METHOD(Phalcon_Db_Reference, getColumns) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "columns");

}

/**
 * Constraint name
 */
PHP_METHOD(Phalcon_Db_Reference, getName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "name");

}

/**
 * Referenced Columns
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedColumns) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "referencedColumns");

}

/**
 * Referenced Schema
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedSchema) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "referencedSchema");

}

/**
 * Referenced Table
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedTable) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "referencedTable");

}

/**
 * Schema name
 */
PHP_METHOD(Phalcon_Db_Reference, getSchemaName) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "schemaName");

}

/**
 * ON DELETE
 */
PHP_METHOD(Phalcon_Db_Reference, getOnDelete) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "onDelete");

}

/**
 * ON UPDATE
 */
PHP_METHOD(Phalcon_Db_Reference, getOnUpdate) {

	zval *this_ptr = getThis();


	RETURN_MEMBER(getThis(), "onUpdate");

}

/**
 * Phalcon\Db\Reference constructor
 */
PHP_METHOD(Phalcon_Db_Reference, __construct) {

	zval definition;
	zval *name_param = NULL, *definition_param = NULL, columns, schema, referencedTable, referencedSchema, referencedColumns, onDelete, onUpdate;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&referencedTable);
	ZVAL_UNDEF(&referencedSchema);
	ZVAL_UNDEF(&referencedColumns);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);
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


	zephir_update_property_zval(this_ptr, SL("name"), &name);
	ZEPHIR_OBS_VAR(&referencedTable);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&referencedTable, &definition, SL("referencedTable"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Referenced table is required", "phalcon/Db/Reference.zep", 105);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("referencedTable"), &referencedTable);
	ZEPHIR_OBS_VAR(&columns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Foreign key columns are required", "phalcon/Db/Reference.zep", 111);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("columns"), &columns);
	ZEPHIR_OBS_VAR(&referencedColumns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&referencedColumns, &definition, SL("referencedColumns"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Referenced columns of the foreign key are required", "phalcon/Db/Reference.zep", 119);
		return;
	}
	zephir_update_property_zval(this_ptr, SL("referencedColumns"), &referencedColumns);
	ZEPHIR_OBS_VAR(&schema);
	if (zephir_array_isset_string_fetch(&schema, &definition, SL("schema"), 0)) {
		zephir_update_property_zval(this_ptr, SL("schemaName"), &schema);
	}
	ZEPHIR_OBS_VAR(&referencedSchema);
	if (zephir_array_isset_string_fetch(&referencedSchema, &definition, SL("referencedSchema"), 0)) {
		zephir_update_property_zval(this_ptr, SL("referencedSchema"), &referencedSchema);
	}
	ZEPHIR_OBS_VAR(&onDelete);
	if (zephir_array_isset_string_fetch(&onDelete, &definition, SL("onDelete"), 0)) {
		zephir_update_property_zval(this_ptr, SL("onDelete"), &onDelete);
	}
	ZEPHIR_OBS_VAR(&onUpdate);
	if (zephir_array_isset_string_fetch(&onUpdate, &definition, SL("onUpdate"), 0)) {
		zephir_update_property_zval(this_ptr, SL("onUpdate"), &onUpdate);
	}
	if (UNEXPECTED(zephir_fast_count_int(&columns TSRMLS_CC) != zephir_fast_count_int(&referencedColumns TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Number of columns is not equals than the number of columns referenced", "phalcon/Db/Reference.zep", 143);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Restore a Phalcon\Db\Reference object from export
 */
PHP_METHOD(Phalcon_Db_Reference, __set_state) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, referencedSchema, referencedTable, columns, referencedColumns, constraintName, onDelete, onUpdate;
	zval data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&referencedSchema);
	ZVAL_UNDEF(&referencedTable);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&referencedColumns);
	ZVAL_UNDEF(&constraintName);
	ZVAL_UNDEF(&onDelete);
	ZVAL_UNDEF(&onUpdate);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	ZEPHIR_OBS_COPY_OR_DUP(&data, data_param);


	ZEPHIR_OBS_VAR(&constraintName);
	if (!(zephir_array_isset_string_fetch(&constraintName, &data, SL("referenceName"), 0))) {
		ZEPHIR_OBS_NVAR(&constraintName);
		if (UNEXPECTED(!(zephir_array_isset_string_fetch(&constraintName, &data, SL("name"), 0)))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "name parameter is required", "phalcon/Db/Reference.zep", 157);
			return;
		}
	}
	zephir_array_isset_string_fetch(&referencedSchema, &data, SL("referencedSchema"), 1);
	zephir_array_isset_string_fetch(&referencedTable, &data, SL("referencedTable"), 1);
	zephir_array_isset_string_fetch(&columns, &data, SL("columns"), 1);
	zephir_array_isset_string_fetch(&referencedColumns, &data, SL("referencedColumns"), 1);
	zephir_array_isset_string_fetch(&onDelete, &data, SL("onDelete"), 1);
	zephir_array_isset_string_fetch(&onUpdate, &data, SL("onUpdate"), 1);
	object_init_ex(return_value, phalcon_db_reference_ce);
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 6, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("onDelete"), &onDelete, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("onUpdate"), &onUpdate, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 22, &constraintName, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

