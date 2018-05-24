
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
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"


/**
 * Phalcon\Db\Index
 *
 * Allows to define indexes to be used on tables. Indexes are a common way
 * to enhance database performance. An index allows the database server to find
 * and retrieve specific rows much faster than it could do without an index
 *
 *<code>
 * // Define new unique index
 * $index_unique = new \Phalcon\Db\Index(
 *     'column_UNIQUE',
 *     [
 *         'column',
 *         'column'
 *     ],
 *     'UNIQUE'
 * );
 * 
 * // Define new primary index
 * $index_primary = new \Phalcon\Db\Index(
 *     'PRIMARY',
 *     [
 *         'column'
 *     ]
 * );
 * 
 * // Add index to existing table
 * $connection->addIndex("robots", null, $index_unique);
 * $connection->addIndex("robots", null, $index_primary);
 *</code> 
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Index) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Db, Index, phalcon, db_index, phalcon_db_index_method_entry, 0);

	/**
	 * Index name
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_index_ce, SL("_name"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Index columns
	 *
	 * @var array
	 */
	zend_declare_property_null(phalcon_db_index_ce, SL("_columns"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Index type
	 *
	 * @var string
	 */
	zend_declare_property_null(phalcon_db_index_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_index_ce TSRMLS_CC, 1, phalcon_db_indexinterface_ce);
	return SUCCESS;

}

/**
 * Index name
 */
PHP_METHOD(Phalcon_Db_Index, getName) {

	

	RETURN_MEMBER(getThis(), "_name");

}

/**
 * Index columns
 */
PHP_METHOD(Phalcon_Db_Index, getColumns) {

	

	RETURN_MEMBER(getThis(), "_columns");

}

/**
 * Index type
 */
PHP_METHOD(Phalcon_Db_Index, getType) {

	

	RETURN_MEMBER(getThis(), "_type");

}

/**
 * Phalcon\Db\Index constructor
 */
PHP_METHOD(Phalcon_Db_Index, __construct) {

	zval *columns = NULL;
	zval *name_param = NULL, *columns_param = NULL, *type = NULL;
	zval *name = NULL, *_0 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &name_param, &columns_param, &type);

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
	columns = columns_param;
	if (!type) {
		type = ZEPHIR_GLOBAL(global_null);
	}


	zephir_update_property_this(getThis(), SL("_name"), name TSRMLS_CC);
	zephir_update_property_this(getThis(), SL("_columns"), columns TSRMLS_CC);
	zephir_get_strval(_0, type);
	zephir_update_property_this(getThis(), SL("_type"), _0 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

/**
 * Restore a Phalcon\Db\Index object from export
 */
PHP_METHOD(Phalcon_Db_Index, __set_state) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, *indexName = NULL, *columns = NULL, *type = NULL;
	zval *data = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	data = data_param;


	ZEPHIR_OBS_VAR(indexName);
	if (!(zephir_array_isset_string_fetch(&indexName, data, SS("_name"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "_name parameter is required", "phalcon/db/index.zep", 95);
		return;
	}
	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, data, SS("_columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "_columns parameter is required", "phalcon/db/index.zep", 99);
		return;
	}
	ZEPHIR_OBS_VAR(type);
	if (!(zephir_array_isset_string_fetch(&type, data, SS("_type"), 0 TSRMLS_CC))) {
		ZEPHIR_INIT_NVAR(type);
		ZVAL_STRING(type, "", 1);
	}
	object_init_ex(return_value, phalcon_db_index_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 24, indexName, columns, type);
	zephir_check_call_status();
	RETURN_MM();

}

