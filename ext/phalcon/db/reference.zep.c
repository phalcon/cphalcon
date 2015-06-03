
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
 * Phalcon\Db\Reference
 *
 * Allows to define reference constraints on tables
 *
 *<code>
 *	$reference = new \Phalcon\Db\Reference("field_fk", array(
 *		'referencedSchema' => "invoicing",
 *		'referencedTable' => "products",
 *		'columns' => array("product_type", "product_code"),
 *		'referencedColumns' => array("type", "code")
 *	));
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Reference) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Reference, phalcon, db_reference, phalcon_db_reference_method_entry, 0);

	/**
	 * Constraint name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_db_reference_ce, SL("_schemaName"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_db_reference_ce, SL("_referencedSchema"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Referenced Table
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referencedTable"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Local reference columns
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("_columns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Referenced Columns
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("_referencedColumns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * ON DELETE
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("_onDelete"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * ON UPDATE
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_reference_ce, SL("_onUpdate"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_reference_ce TSRMLS_CC, 1, phalcon_db_referenceinterface_ce);
	return SUCCESS;

}

/**
 * Constraint name
 *
 * @var string
 */
PHP_METHOD(Phalcon_Db_Reference, getName) {


	RETURN_MEMBER(this_ptr, "_name");

}

PHP_METHOD(Phalcon_Db_Reference, getSchemaName) {


	RETURN_MEMBER(this_ptr, "_schemaName");

}

PHP_METHOD(Phalcon_Db_Reference, getReferencedSchema) {


	RETURN_MEMBER(this_ptr, "_referencedSchema");

}

/**
 * Referenced Table
 *
 * @var string
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedTable) {


	RETURN_MEMBER(this_ptr, "_referencedTable");

}

/**
 * Local reference columns
 *
 * @var array
 */
PHP_METHOD(Phalcon_Db_Reference, getColumns) {


	RETURN_MEMBER(this_ptr, "_columns");

}

/**
 * Referenced Columns
 *
 * @var array
 */
PHP_METHOD(Phalcon_Db_Reference, getReferencedColumns) {


	RETURN_MEMBER(this_ptr, "_referencedColumns");

}

/**
 * ON DELETE
 *
 * @var array
 */
PHP_METHOD(Phalcon_Db_Reference, getOnDelete) {


	RETURN_MEMBER(this_ptr, "_onDelete");

}

/**
 * ON UPDATE
 *
 * @var array
 */
PHP_METHOD(Phalcon_Db_Reference, getOnUpdate) {


	RETURN_MEMBER(this_ptr, "_onUpdate");

}

/**
 * Phalcon\Db\Reference constructor
 */
PHP_METHOD(Phalcon_Db_Reference, __construct) {

	zval *definition = NULL;
	zval *name_param = NULL, *definition_param = NULL, *columns, *schema, *referencedTable, *referencedSchema, *referencedColumns, *onDelete, *onUpdate;
	zval *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &name_param, &definition_param);

	if (unlikely(Z_TYPE_P(name_param) != IS_STRING && Z_TYPE_P(name_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'name' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(name_param) == IS_STRING)) {
		zephir_get_strval(name, name_param);
	} else {
		ZEPHIR_INIT_VAR(name);
		ZVAL_EMPTY_STRING(name);
	}
	definition = definition_param;



	zephir_update_property_this(this_ptr, SL("_name"), name TSRMLS_CC);
	ZEPHIR_OBS_VAR(referencedTable);
	if (zephir_array_isset_string_fetch(&referencedTable, definition, SS("referencedTable"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_referencedTable"), referencedTable TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Referenced table is required", "phalcon/db/reference.zep", 99);
		return;
	}
	ZEPHIR_OBS_VAR(columns);
	if (zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_columns"), columns TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Foreign key columns are required", "phalcon/db/reference.zep", 105);
		return;
	}
	ZEPHIR_OBS_VAR(referencedColumns);
	if (zephir_array_isset_string_fetch(&referencedColumns, definition, SS("referencedColumns"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_referencedColumns"), referencedColumns TSRMLS_CC);
	} else {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Referenced columns of the foreign key are required", "phalcon/db/reference.zep", 111);
		return;
	}
	ZEPHIR_OBS_VAR(schema);
	if (zephir_array_isset_string_fetch(&schema, definition, SS("schema"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_schemaName"), schema TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(referencedSchema);
	if (zephir_array_isset_string_fetch(&referencedSchema, definition, SS("referencedSchema"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_referencedSchema"), referencedSchema TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(onDelete);
	if (zephir_array_isset_string_fetch(&onDelete, definition, SS("onDelete"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_onDelete"), onDelete TSRMLS_CC);
	}
	ZEPHIR_OBS_VAR(onUpdate);
	if (zephir_array_isset_string_fetch(&onUpdate, definition, SS("onUpdate"), 0 TSRMLS_CC)) {
		zephir_update_property_this(this_ptr, SL("_onUpdate"), onUpdate TSRMLS_CC);
	}
	if (zephir_fast_count_int(columns TSRMLS_CC) != zephir_fast_count_int(referencedColumns TSRMLS_CC)) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "Number of columns is not equals than the number of columns referenced", "phalcon/db/reference.zep", 131);
		return;
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Restore a Phalcon\Db\Reference object from export
 */
PHP_METHOD(Phalcon_Db_Reference, __set_state) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *referencedSchema, *referencedTable, *columns, *referencedColumns, *constraintName = NULL, *onDelete, *onUpdate;
	zval *data = NULL, *_0;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	data = data_param;



	ZEPHIR_OBS_VAR(constraintName);
	if (!(zephir_array_isset_string_fetch(&constraintName, data, SS("_referenceName"), 0 TSRMLS_CC))) {
		ZEPHIR_OBS_NVAR(constraintName);
		if (!(zephir_array_isset_string_fetch(&constraintName, data, SS("_name"), 0 TSRMLS_CC))) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "_name parameter is required", "phalcon/db/reference.zep", 146);
			return;
		}
	}
	zephir_array_isset_string_fetch(&referencedSchema, data, SS("_referencedSchema"), 1 TSRMLS_CC);
	zephir_array_isset_string_fetch(&referencedTable, data, SS("_referencedTable"), 1 TSRMLS_CC);
	zephir_array_isset_string_fetch(&columns, data, SS("_columns"), 1 TSRMLS_CC);
	zephir_array_isset_string_fetch(&referencedColumns, data, SS("_referencedColumns"), 1 TSRMLS_CC);
	zephir_array_isset_string_fetch(&onDelete, data, SS("_onDelete"), 1 TSRMLS_CC);
	zephir_array_isset_string_fetch(&onUpdate, data, SS("_onUpdate"), 1 TSRMLS_CC);
	object_init_ex(return_value, phalcon_db_reference_ce);
	ZEPHIR_INIT_VAR(_0);
	zephir_create_array(_0, 6, 0 TSRMLS_CC);
	zephir_array_update_string(&_0, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("onDelete"), &onDelete, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&_0, SL("onUpdate"), &onUpdate, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 77, constraintName, _0);
	zephir_check_call_status();
	RETURN_MM();

}

