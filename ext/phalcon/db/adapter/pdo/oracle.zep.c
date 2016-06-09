
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

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_2 = NULL;
	zval *descriptor = NULL, descriptor_sub, __$null, startup, value, status, *_1$$5;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&descriptor_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&startup);
	ZVAL_UNDEF(&value);
	ZVAL_UNDEF(&status);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &descriptor);

	if (!descriptor) {
		descriptor = &descriptor_sub;
		ZEPHIR_CPY_WRT(descriptor, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(descriptor);
	}


	if (!(zephir_is_true(descriptor))) {
		ZEPHIR_OBS_NVAR(descriptor);
		zephir_read_property(descriptor, this_ptr, SL("_descriptor"), PH_NOISY_CC);
	}
	ZEPHIR_CALL_PARENT(&status, phalcon_db_adapter_pdo_oracle_ce, this_ptr, "connect", &_0, 152, descriptor);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&startup);
	if (zephir_array_isset_string_fetch(&startup, descriptor, SL("startup"), 0)) {
		if (Z_TYPE_P(&startup) == IS_ARRAY) {
			zephir_is_iterable(&startup, 0, "phalcon/db/adapter/pdo/oracle.zep", 76);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&startup), _1$$5)
			{
				ZEPHIR_INIT_NVAR(&value);
				ZVAL_COPY(&value, _1$$5);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", &_2, 0, &value);
				zephir_check_call_status();
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&value);
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

	zephir_fcall_cache_entry *_22 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$true, columns, oldColumn, field, definition, columnSize, columnPrecision, columnScale, columnType, columnName, _0, _1, _2, _3, *_4, _5$$5, _6$$5, _7$$6, _8$$6, _9$$7, _10$$8, _11$$8, _12$$9, _13$$10, _14$$11, _15$$12, _16$$13, _17$$14, _18$$4, _19$$3, _20$$3, _21$$3;
	zval table, schema;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&oldColumn);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&columnSize);
	ZVAL_UNDEF(&columnPrecision);
	ZVAL_UNDEF(&columnScale);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$10);
	ZVAL_UNDEF(&_14$$11);
	ZVAL_UNDEF(&_15$$12);
	ZVAL_UNDEF(&_16$$13);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_18$$4);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_20$$3);
	ZVAL_UNDEF(&_21$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	ZEPHIR_INIT_VAR(&oldColumn);
	ZVAL_NULL(&oldColumn);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describecolumns", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/oracle.zep", 208);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&field);
		ZVAL_COPY(&field, _4);
		ZEPHIR_INIT_NVAR(&definition);
		zephir_create_array(&definition, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(&definition, SL("bindType"), 2);
		ZEPHIR_OBS_NVAR(&columnSize);
		zephir_array_fetch_long(&columnSize, &field, 2, PH_NOISY, "phalcon/db/adapter/pdo/oracle.zep", 102 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&columnPrecision);
		zephir_array_fetch_long(&columnPrecision, &field, 3, PH_NOISY, "phalcon/db/adapter/pdo/oracle.zep", 103 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&columnScale);
		zephir_array_fetch_long(&columnScale, &field, 4, PH_NOISY, "phalcon/db/adapter/pdo/oracle.zep", 104 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&columnType);
		zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/db/adapter/pdo/oracle.zep", 105 TSRMLS_CC);
		while (1) {
			if (zephir_memnstr_str(&columnType, SL("NUMBER"), "phalcon/db/adapter/pdo/oracle.zep", 112)) {
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_LONG(&_5$$5, 3);
				zephir_array_update_string(&definition, SL("type"), &_5$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnPrecision, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("scale"), &columnScale, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZVAL_LONG(&_6$$5, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_6$$5, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("INTEGER"), "phalcon/db/adapter/pdo/oracle.zep", 121)) {
				ZEPHIR_INIT_NVAR(&_7$$6);
				ZVAL_LONG(&_7$$6, 0);
				zephir_array_update_string(&definition, SL("type"), &_7$$6, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnPrecision, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_8$$6);
				ZVAL_LONG(&_8$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_8$$6, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("VARCHAR2"), "phalcon/db/adapter/pdo/oracle.zep", 129)) {
				ZEPHIR_INIT_NVAR(&_9$$7);
				ZVAL_LONG(&_9$$7, 2);
				zephir_array_update_string(&definition, SL("type"), &_9$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("FLOAT"), "phalcon/db/adapter/pdo/oracle.zep", 135)) {
				ZEPHIR_INIT_NVAR(&_10$$8);
				ZVAL_LONG(&_10$$8, 7);
				zephir_array_update_string(&definition, SL("type"), &_10$$8, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnSize, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("scale"), &columnScale, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_11$$8);
				ZVAL_LONG(&_11$$8, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_11$$8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("TIMESTAMP"), "phalcon/db/adapter/pdo/oracle.zep", 144)) {
				ZEPHIR_INIT_NVAR(&_12$$9);
				ZVAL_LONG(&_12$$9, 17);
				zephir_array_update_string(&definition, SL("type"), &_12$$9, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("DATE"), "phalcon/db/adapter/pdo/oracle.zep", 149)) {
				ZEPHIR_INIT_NVAR(&_13$$10);
				ZVAL_LONG(&_13$$10, 1);
				zephir_array_update_string(&definition, SL("type"), &_13$$10, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("RAW"), "phalcon/db/adapter/pdo/oracle.zep", 154)) {
				ZEPHIR_INIT_NVAR(&_14$$11);
				ZVAL_LONG(&_14$$11, 6);
				zephir_array_update_string(&definition, SL("type"), &_14$$11, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("BLOB"), "phalcon/db/adapter/pdo/oracle.zep", 159)) {
				ZEPHIR_INIT_NVAR(&_15$$12);
				ZVAL_LONG(&_15$$12, 6);
				zephir_array_update_string(&definition, SL("type"), &_15$$12, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("CLOB"), "phalcon/db/adapter/pdo/oracle.zep", 164)) {
				ZEPHIR_INIT_NVAR(&_16$$13);
				ZVAL_LONG(&_16$$13, 6);
				zephir_array_update_string(&definition, SL("type"), &_16$$13, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("CHAR"), "phalcon/db/adapter/pdo/oracle.zep", 169)) {
				ZEPHIR_INIT_NVAR(&_17$$14);
				ZVAL_LONG(&_17$$14, 5);
				zephir_array_update_string(&definition, SL("type"), &_17$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &columnSize, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(&_18$$4);
			ZVAL_LONG(&_18$$4, 6);
			zephir_array_update_string(&definition, SL("type"), &_18$$4, PH_COPY | PH_SEPARATE);
			break;
		}
		if (Z_TYPE_P(&oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_19$$3, &field, 6, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/oracle.zep", 188 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_19$$3, "P")) {
			zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_20$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/oracle.zep", 195 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_20$$3, "N")) {
			zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/oracle.zep", 199 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_21$$3);
		object_init_ex(&_21$$3, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, &_21$$3, "__construct", &_22, 151, &columnName, &definition);
		zephir_check_call_status();
		zephir_array_append(&columns, &_21$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/oracle.zep", 204);
		ZEPHIR_CPY_WRT(&oldColumn, &columnName);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&field);
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
	zval *sequenceName_param = NULL, _0, _2, _3;
	zval sequenceName, _1;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&sequenceName);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &sequenceName_param);

	if (!sequenceName_param) {
		ZEPHIR_INIT_VAR(&sequenceName);
		ZVAL_STRING(&sequenceName, "");
	} else {
		zephir_get_strval(&sequenceName, sequenceName_param);
	}


	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVS(&_1, "SELECT ", &sequenceName, ".CURRVAL FROM dual");
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_array_fetch_long(&_3, &_0, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/oracle.zep", 228 TSRMLS_CC);
	RETURN_CTOR(_3);

}

/**
 * Check whether the database system requires an explicit value for identity columns
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, useExplicitIdValue) {

	ZEPHIR_INIT_THIS();


	RETURN_BOOL(0);

}

/**
 * Return the default identity value to insert in an identity column
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, getDefaultIdValue) {

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "default");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 21, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Oracle, supportSequences) {

	ZEPHIR_INIT_THIS();


	RETURN_BOOL(1);

}

