
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

	HashTable *_2$$5;
	HashPosition _1$$5;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_4 = NULL;
	zval *descriptor = NULL, *startup = NULL, *value = NULL, *status = NULL, **_3$$5;

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
	ZEPHIR_CALL_PARENT(&status, phalcon_db_adapter_pdo_oracle_ce, this_ptr, "connect", &_0, 138, descriptor);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(startup);
	if (zephir_array_isset_string_fetch(&startup, descriptor, SS("startup"), 0 TSRMLS_CC)) {
		if (Z_TYPE_P(startup) == IS_ARRAY) {
			zephir_is_iterable(startup, &_2$$5, &_1$$5, 0, 0, "phalcon/db/adapter/pdo/oracle.zep", 76);
			for (
			  ; zephir_hash_get_current_data_ex(_2$$5, (void**) &_3$$5, &_1$$5) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2$$5, &_1$$5)
			) {
				ZEPHIR_GET_HVALUE(value, _3$$5);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", &_4, 0, value);
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
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, describeColumns) {

	HashTable *_5;
	HashPosition _4;
	zephir_fcall_cache_entry *_24 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *columns = NULL, *oldColumn = NULL, *field = NULL, *definition = NULL, *columnSize = NULL, *columnPrecision = NULL, *columnScale = NULL, *columnType = NULL, *columnName = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, *_7$$5 = NULL, *_8$$5 = NULL, *_9$$6 = NULL, *_10$$6 = NULL, *_11$$7 = NULL, *_12$$8 = NULL, *_13$$8 = NULL, *_14$$9 = NULL, *_15$$10 = NULL, *_16$$11 = NULL, *_17$$12 = NULL, *_18$$13 = NULL, *_19$$14 = NULL, *_20$$4 = NULL, *_21$$3, *_22$$3, *_23$$3 = NULL;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}


	ZEPHIR_INIT_VAR(columns);
	array_init(columns);
	ZEPHIR_INIT_VAR(oldColumn);
	ZVAL_NULL(oldColumn);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "describecolumns", NULL, 0, table, schema);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/oracle.zep", 208);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(field, _6);
		ZEPHIR_INIT_NVAR(definition);
		zephir_create_array(definition, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(definition, SS("bindType"), 2);
		ZEPHIR_OBS_NVAR(columnSize);
		zephir_array_fetch_long(&columnSize, field, 2, PH_NOISY, "phalcon/db/adapter/pdo/oracle.zep", 102 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(columnPrecision);
		zephir_array_fetch_long(&columnPrecision, field, 3, PH_NOISY, "phalcon/db/adapter/pdo/oracle.zep", 103 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(columnScale);
		zephir_array_fetch_long(&columnScale, field, 4, PH_NOISY, "phalcon/db/adapter/pdo/oracle.zep", 104 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(columnType);
		zephir_array_fetch_long(&columnType, field, 1, PH_NOISY, "phalcon/db/adapter/pdo/oracle.zep", 105 TSRMLS_CC);
		while (1) {
			if (zephir_memnstr_str(columnType, SL("NUMBER"), "phalcon/db/adapter/pdo/oracle.zep", 112)) {
				ZEPHIR_INIT_NVAR(_7$$5);
				ZVAL_LONG(_7$$5, 3);
				zephir_array_update_string(&definition, SL("type"), &_7$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnPrecision, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("scale"), &columnScale, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8$$5);
				ZVAL_LONG(_8$$5, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_8$$5, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("INTEGER"), "phalcon/db/adapter/pdo/oracle.zep", 121)) {
				ZEPHIR_INIT_NVAR(_9$$6);
				ZVAL_LONG(_9$$6, 0);
				zephir_array_update_string(&definition, SL("type"), &_9$$6, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnPrecision, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_10$$6);
				ZVAL_LONG(_10$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_10$$6, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("VARCHAR2"), "phalcon/db/adapter/pdo/oracle.zep", 129)) {
				ZEPHIR_INIT_NVAR(_11$$7);
				ZVAL_LONG(_11$$7, 2);
				zephir_array_update_string(&definition, SL("type"), &_11$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("FLOAT"), "phalcon/db/adapter/pdo/oracle.zep", 135)) {
				ZEPHIR_INIT_NVAR(_12$$8);
				ZVAL_LONG(_12$$8, 7);
				zephir_array_update_string(&definition, SL("type"), &_12$$8, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnSize, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("scale"), &columnScale, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_13$$8);
				ZVAL_LONG(_13$$8, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_13$$8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("TIMESTAMP"), "phalcon/db/adapter/pdo/oracle.zep", 144)) {
				ZEPHIR_INIT_NVAR(_14$$9);
				ZVAL_LONG(_14$$9, 17);
				zephir_array_update_string(&definition, SL("type"), &_14$$9, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("DATE"), "phalcon/db/adapter/pdo/oracle.zep", 149)) {
				ZEPHIR_INIT_NVAR(_15$$10);
				ZVAL_LONG(_15$$10, 1);
				zephir_array_update_string(&definition, SL("type"), &_15$$10, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("RAW"), "phalcon/db/adapter/pdo/oracle.zep", 154)) {
				ZEPHIR_INIT_NVAR(_16$$11);
				ZVAL_LONG(_16$$11, 6);
				zephir_array_update_string(&definition, SL("type"), &_16$$11, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("BLOB"), "phalcon/db/adapter/pdo/oracle.zep", 159)) {
				ZEPHIR_INIT_NVAR(_17$$12);
				ZVAL_LONG(_17$$12, 6);
				zephir_array_update_string(&definition, SL("type"), &_17$$12, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("CLOB"), "phalcon/db/adapter/pdo/oracle.zep", 164)) {
				ZEPHIR_INIT_NVAR(_18$$13);
				ZVAL_LONG(_18$$13, 6);
				zephir_array_update_string(&definition, SL("type"), &_18$$13, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("CHAR"), "phalcon/db/adapter/pdo/oracle.zep", 169)) {
				ZEPHIR_INIT_NVAR(_19$$14);
				ZVAL_LONG(_19$$14, 5);
				zephir_array_update_string(&definition, SL("type"), &_19$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnSize, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(_20$$4);
			ZVAL_LONG(_20$$4, 6);
			zephir_array_update_string(&definition, SL("type"), &_20$$4, PH_COPY | PH_SEPARATE);
			break;
		}
		if (Z_TYPE_P(oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_21$$3, field, 6, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/oracle.zep", 188 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_21$$3, "P")) {
			zephir_array_update_string(&definition, SL("primary"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_22$$3, field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/oracle.zep", 195 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_22$$3, "N")) {
			zephir_array_update_string(&definition, SL("notNull"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&columnName, field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/oracle.zep", 199 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_23$$3);
		object_init_ex(_23$$3, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, _23$$3, "__construct", &_24, 137, columnName, definition);
		zephir_check_call_status();
		zephir_array_append(&columns, _23$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/oracle.zep", 204);
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
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, lastInsertId) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *sequenceName_param = NULL, *_0 = NULL, *_2, *_3;
	zval *sequenceName = NULL, *_1;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sequenceName_param);

	if (!sequenceName_param) {
		ZEPHIR_INIT_VAR(sequenceName);
		ZVAL_EMPTY_STRING(sequenceName);
	} else {
		zephir_get_strval(sequenceName, sequenceName_param);
	}


	ZEPHIR_INIT_VAR(_1);
	ZEPHIR_CONCAT_SVS(_1, "SELECT ", sequenceName, ".CURRVAL FROM dual");
	ZEPHIR_INIT_VAR(_2);
	ZVAL_LONG(_2, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _1, _2);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, _0, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/oracle.zep", 228 TSRMLS_CC);
	RETURN_CTOR(_3);

}

/**
 * Check whether the database system requires an explicit value for identity columns
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, useExplicitIdValue) {

	

	RETURN_BOOL(0);

}

/**
 * Return the default identity value to insert in an identity column
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, getDefaultIdValue) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "default", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 17, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, supportSequences) {

	

	RETURN_BOOL(1);

}

