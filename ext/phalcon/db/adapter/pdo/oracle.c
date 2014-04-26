
#ifdef HAVE_CONFIG_H
#include "../../../../ext_config.h"
#endif

#include <php.h>
#include "../../../../php_ext.h"
#include "../../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/concat.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
 |          Marcio Paiva <mpaivabarbosa@gmail.com>                        |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Db\Adapter\Pdo\Oracle
 *
 * Specific functions for the Oracle database system
 * <code>
 *
 * $config = array(
 *  "dbname" => "//localhost/dbname",
 *  "username" => "oracle",
 *  "password" => "oracle"
 * );
 *
 * $connection = new \Phalcon\Db\Adapter\Pdo\Oracle($config);
 *
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Oracle) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Oracle, phalcon, db_adapter_pdo_oracle, phalcon_db_adapter_pdo_ce, phalcon_db_adapter_pdo_oracle_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_oracle_ce, SL("_type"), "oci", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_db_adapter_pdo_oracle_ce, SL("_dialectType"), "oracle", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_adapter_pdo_oracle_ce TSRMLS_CC, 1, phalcon_db_adapterinterface_ce);
	return SUCCESS;

}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection.
 *
 * @param array descriptor
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, connect) {

	zephir_fcall_cache_entry *_4 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_0 = NULL;
	zval *descriptor = NULL, *startup, *value = NULL, *status = NULL, **_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &descriptor);

	if (!descriptor) {
		ZEPHIR_CPY_WRT(descriptor, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(descriptor);
	}


	if (!(zephir_is_true(descriptor))) {
		ZEPHIR_OBS_NVAR(descriptor);
		zephir_read_property_this(&descriptor, this_ptr, SL("_descriptor"), PH_NOISY_CC);
	}
	ZEPHIR_CALL_PARENT(&status, phalcon_db_adapter_pdo_oracle_ce, this_ptr, "connect", &_0, descriptor);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(startup);
	if (zephir_array_isset_string_fetch(&startup, descriptor, SS("startup"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(startup) == IS_ARRAY) {
			zephir_is_iterable(startup, &_2, &_1, 0, 0);
			for (
			  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(value, _3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", &_4, value);
				zephir_check_call_status();
			}
		}
	}
	RETURN_CCTOR(status);

}

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 *
 * <code>print_r($connection->describeColumns("posts")); ?></code>
 *
 * @param string table
 * @param string schema
 * @return Phalcon\Db\Column[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, describeColumns) {

	zephir_fcall_cache_entry *_12 = NULL;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema = NULL, *columns, *oldColumn = NULL, *field = NULL, *definition = NULL, *columnSize = NULL, *columnPrecision = NULL, *columnScale = NULL, *columnType = NULL, *columnName, *_0 = NULL, *_1, *_2 = NULL, *_3 = NULL, **_6, *_7 = NULL, *_8 = NULL, *_9, *_10, *_11 = NULL;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (unlikely(Z_TYPE_P(table_param) == IS_STRING)) {
		table = table_param;
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema) {
		schema = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(columns);
	array_init(columns);
	ZEPHIR_INIT_VAR(oldColumn);
	ZVAL_NULL(oldColumn);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "describecolumns", NULL, table, schema);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(field, _6);
		ZEPHIR_INIT_NVAR(definition);
		array_init_size(definition, 2);
		add_assoc_long_ex(definition, SS("bindType"), 2);
		ZEPHIR_OBS_NVAR(columnSize);
		zephir_array_fetch_long(&columnSize, field, 2, PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(columnPrecision);
		zephir_array_fetch_long(&columnPrecision, field, 3, PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(columnScale);
		zephir_array_fetch_long(&columnScale, field, 4, PH_NOISY TSRMLS_CC);
		ZEPHIR_OBS_NVAR(columnType);
		zephir_array_fetch_long(&columnType, field, 1, PH_NOISY TSRMLS_CC);
		while (1) {
			if (zephir_memnstr_str(columnType, SL("NUMBER"), "phalcon/db/adapter/pdo/oracle.zep", 113)) {
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_LONG(_3, 3);
				zephir_array_update_string(&definition, SL("type"), &_3, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnPrecision, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("scale"), &columnScale, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("INTEGER"), "phalcon/db/adapter/pdo/oracle.zep", 122)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 0);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnPrecision, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("VARCHAR2"), "phalcon/db/adapter/pdo/oracle.zep", 130)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 2);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("FLOAT"), "phalcon/db/adapter/pdo/oracle.zep", 136)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 7);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnSize, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("scale"), &columnScale, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("TIMESTAMP"), "phalcon/db/adapter/pdo/oracle.zep", 145)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 0);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("RAW"), "phalcon/db/adapter/pdo/oracle.zep", 150)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 6);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("BLOB"), "phalcon/db/adapter/pdo/oracle.zep", 155)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 6);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("CLOB"), "phalcon/db/adapter/pdo/oracle.zep", 160)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 6);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("CHAR"), "phalcon/db/adapter/pdo/oracle.zep", 165)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 5);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnSize, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, 6);
			zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
			break;
		}
		if (Z_TYPE_P(oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_9, field, 6, PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_9, "P")) {
			zephir_array_update_string(&definition, SL("primary"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_10, field, 5, PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_10, "N")) {
			zephir_array_update_string(&definition, SL("notNull"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&columnName, field, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_11);
		object_init_ex(_11, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, _11, "__construct", &_12, columnName, definition);
		zephir_check_call_status();
		zephir_array_append(&columns, _11, PH_SEPARATE);
		ZEPHIR_CPY_WRT(oldColumn, columnName);
	}
	RETURN_CCTOR(columns);

}

/**
 * Returns the insert id for the auto_increment/serial column inserted in the lastest executed SQL statement
 *
 *<code>
 * //Inserting a new robot
 * $success = $connection->insert(
 *     "robots",
 *     array("Astro Boy", 1952),
 *     array("name", "year")
 * );
 *
 * //Getting the generated id
 * $id = $connection->lastInsertId();
 *</code>
 *
 * @param string sequenceName
 * @return int
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, lastInsertId) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sequenceName = NULL, *_0 = NULL, *_1, *_2, *_3;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sequenceName);

	if (!sequenceName) {
		sequenceName = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "SELECT ", sequenceName, ".CURRVAL FROM dual");
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, _1, _2);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, _0, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
	RETURN_CTOR(_3);

}

/**
 * Check whether the database system requires an explicit value for identity columns
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, useExplicitIdValue) {


	RETURN_BOOL(0);

}

/**
 * Return the default identity value to insert in an identity column
 *
 * @return Phalcon\Db\RawValue
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, getDefaultIdValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "default", 0);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, supportSequences) {


	RETURN_BOOL(1);

}

