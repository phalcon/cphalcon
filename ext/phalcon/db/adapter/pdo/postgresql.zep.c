
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
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/hash.h"


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
 |          Rack Lin <racklin@gmail.com>                                  |
 +------------------------------------------------------------------------+
*/
/**
 * Phalcon\Db\Adapter\Pdo\Postgresql
 *
 * Specific functions for the Postgresql database system
 * <code>
 *
 * $config = array(
 *  "host" => "192.168.0.11",
 *  "dbname" => "blog",
 *  "username" => "postgres",
 *  "password" => ""
 * );
 *
 * $connection = new \Phalcon\Db\Adapter\Pdo\Postgresql($config);
 *
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Postgresql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Postgresql, phalcon, db_adapter_pdo_postgresql, phalcon_db_adapter_pdo_ce, phalcon_db_adapter_pdo_postgresql_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("_type"), "pgsql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("_dialectType"), "postgresql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_adapter_pdo_postgresql_ce TSRMLS_CC, 1, phalcon_db_adapterinterface_ce);
	return SUCCESS;

}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection.
 *
 * @param array $descriptor
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, connect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_nts_static zephir_fcall_cache_entry *_3 = NULL;
	zend_bool _1;
	zval *descriptor = NULL, *schema = NULL, *sql, *_0, *_2;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &descriptor);

	if (!descriptor) {
		ZEPHIR_CPY_WRT(descriptor, ZEPHIR_GLOBAL(global_null));
	} else {
		ZEPHIR_SEPARATE_PARAM(descriptor);
	}


	if (Z_TYPE_P(descriptor) == IS_NULL) {
		ZEPHIR_OBS_NVAR(descriptor);
		zephir_read_property_this(&descriptor, this_ptr, SL("_descriptor"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(schema);
	if (zephir_array_isset_string_fetch(&schema, descriptor, SS("schema"), 0 TSRMLS_CC)) {
		zephir_array_unset_string(&descriptor, SS("schema"), PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(schema);
		ZVAL_STRING(schema, "", 1);
	}
	if (zephir_array_isset_string(descriptor, SS("password"))) {
		ZEPHIR_OBS_VAR(_0);
		zephir_array_fetch_string(&_0, descriptor, SL("password"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 71 TSRMLS_CC);
		_1 = Z_TYPE_P(_0) == IS_STRING;
		if (_1) {
			zephir_array_fetch_string(&_2, descriptor, SL("password"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 71 TSRMLS_CC);
			_1 = zephir_fast_strlen_ev(_2) == 0;
		}
		if (_1) {
			zephir_array_update_string(&descriptor, SL("password"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_postgresql_ce, this_ptr, "connect", &_3, descriptor);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(schema))) {
		ZEPHIR_INIT_VAR(sql);
		ZEPHIR_CONCAT_SVS(sql, "SET search_path TO '", schema, "'");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, sql);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 *
 * <code>
 * print_r($connection->describeColumns("posts"));
 * </code>
 *
 * @param string table
 * @param string schema
 * @return Phalcon\Db\Column[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns) {

	zephir_fcall_cache_entry *_22 = NULL;
	zephir_nts_static zephir_fcall_cache_entry *_16 = NULL, *_20 = NULL;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *columns, *columnType = NULL, *field = NULL, *definition = NULL, *oldColumn = NULL, *columnName, *charSize = NULL, *numericSize = NULL, *numericScale = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3 = NULL, **_6, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10, *_11, *_12, *_13 = NULL, *_14, *_15 = NULL, *_17, _18 = zval_used_for_init, *_19 = NULL, *_21 = NULL;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	zephir_get_strval(table, table_param);
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}


	ZEPHIR_INIT_VAR(oldColumn);
	ZVAL_NULL(oldColumn);
	ZEPHIR_INIT_VAR(columns);
	array_init(columns);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "describecolumns", NULL, table, schema);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 292);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(field, _6);
		ZEPHIR_INIT_NVAR(definition);
		array_init_size(definition, 2);
		add_assoc_long_ex(definition, SS("bindType"), 2);
		ZEPHIR_OBS_NVAR(columnType);
		zephir_array_fetch_long(&columnType, field, 1, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 116 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(charSize);
		zephir_array_fetch_long(&charSize, field, 2, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 117 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(numericSize);
		zephir_array_fetch_long(&numericSize, field, 3, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 118 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(numericScale);
		zephir_array_fetch_long(&numericScale, field, 4, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 119 TSRMLS_CC);
		while (1) {
			if (zephir_memnstr_str(columnType, SL("smallint(1)"), "phalcon/db/adapter/pdo/postgresql.zep", 126)) {
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_LONG(_3, 8);
				zephir_array_update_string(&definition, SL("type"), &_3, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("int"), "phalcon/db/adapter/pdo/postgresql.zep", 135)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 0);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("varying"), "phalcon/db/adapter/pdo/postgresql.zep", 146)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 2);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("date"), "phalcon/db/adapter/pdo/postgresql.zep", 155)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 1);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 0);
				zephir_array_update_string(&definition, SL("size"), &_8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("numeric"), "phalcon/db/adapter/pdo/postgresql.zep", 164)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 3);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("scale"), &numericScale, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("char"), "phalcon/db/adapter/pdo/postgresql.zep", 176)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 5);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("timestamp"), "phalcon/db/adapter/pdo/postgresql.zep", 185)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 4);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 0);
				zephir_array_update_string(&definition, SL("size"), &_8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("text"), "phalcon/db/adapter/pdo/postgresql.zep", 194)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 6);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("float"), "phalcon/db/adapter/pdo/postgresql.zep", 203)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 7);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("bool"), "phalcon/db/adapter/pdo/postgresql.zep", 214)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 8);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 0);
				zephir_array_update_string(&definition, SL("size"), &_8, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_LONG(_9, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_9, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("uuid"), "phalcon/db/adapter/pdo/postgresql.zep", 224)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 5);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 36);
				zephir_array_update_string(&definition, SL("size"), &_8, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, 2);
			zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
			break;
		}
		if (zephir_memnstr_str(columnType, SL("unsigned"), "phalcon/db/adapter/pdo/postgresql.zep", 240)) {
			zephir_array_update_string(&definition, SL("unsigned"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_10, field, 6, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 256 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_10, "PRI")) {
			zephir_array_update_string(&definition, SL("primary"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_11, field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 263 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_11, "NO")) {
			zephir_array_update_string(&definition, SL("notNull"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_12, field, 7, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 270 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_12, "auto_increment")) {
			zephir_array_update_string(&definition, SL("autoIncrement"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_NVAR(_13);
		zephir_array_fetch_long(&_13, field, 9, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 277 TSRMLS_CC);
		if (Z_TYPE_P(_13) != IS_NULL) {
			zephir_array_fetch_long(&_14, field, 9, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 278 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_8);
			ZVAL_STRING(_8, "/^'|'?::[[:alnum:][:space:]]+$/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_9);
			ZVAL_STRING(_9, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_15, "preg_replace", &_16, _8, _9, _14);
			zephir_check_temp_parameter(_8);
			zephir_check_temp_parameter(_9);
			zephir_check_call_status();
			zephir_array_update_string(&definition, SL("default"), &_15, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_17, definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 279 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_18);
			ZVAL_STRING(&_18, "null", 0);
			ZEPHIR_CALL_FUNCTION(&_19, "strcasecmp", &_20, _17, &_18);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(_19, 0)) {
				zephir_array_update_string(&definition, SL("default"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
			}
		}
		zephir_array_fetch_long(&columnName, field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 287 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_21);
		object_init_ex(_21, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, _21, "__construct", &_22, columnName, definition);
		zephir_check_call_status();
		zephir_array_append(&columns, _21, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 288);
		ZEPHIR_CPY_WRT(oldColumn, columnName);
	}
	RETURN_CCTOR(columns);

}

/**
 * Check whether the database system requires an explicit value for identity columns
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, useExplicitIdValue) {


	RETURN_BOOL(1);

}

/**
 * Returns the default identity value to be inserted in an identity column
 *
 *<code>
 * //Inserting a new robot with a valid default value for the column 'id'
 * $success = $connection->insert(
 *     "robots",
 *     array($connection->getDefaultIdValue(), "Astro Boy", 1952),
 *     array("id", "name", "year")
 * );
 *</code>
 *
 * @return Phalcon\Db\RawValue
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "default", ZEPHIR_TEMP_PARAM_COPY);
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences) {


	RETURN_BOOL(1);

}

