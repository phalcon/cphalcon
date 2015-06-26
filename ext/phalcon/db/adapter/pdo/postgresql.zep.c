
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


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
	zephir_fcall_cache_entry *_3 = NULL;
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
		zephir_array_fetch_string(&_0, descriptor, SL("password"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 75 TSRMLS_CC);
		_1 = Z_TYPE_P(_0) == IS_STRING;
		if (_1) {
			zephir_array_fetch_string(&_2, descriptor, SL("password"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 75 TSRMLS_CC);
			_1 = zephir_fast_strlen_ev(_2) == 0;
		}
		if (_1) {
			zephir_array_update_string(&descriptor, SL("password"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_postgresql_ce, this_ptr, "connect", &_3, 84, descriptor);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(schema))) {
		ZEPHIR_INIT_VAR(sql);
		ZEPHIR_CONCAT_SVS(sql, "SET search_path TO '", schema, "'");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, sql);
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
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns) {

	zephir_fcall_cache_entry *_16 = NULL, *_20 = NULL, *_21 = NULL;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *columns, *columnType = NULL, *field = NULL, *definition = NULL, *oldColumn = NULL, *columnName, *charSize = NULL, *numericSize = NULL, *numericScale = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3 = NULL, **_6, *_7 = NULL, *_8 = NULL, *_9 = NULL, *_10, *_11, *_12, *_13 = NULL, *_14, *_15 = NULL, *_17, _18 = zval_used_for_init, *_19 = NULL;
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
	ZEPHIR_CALL_METHOD(&_2, _1, "describecolumns", NULL, 0, table, schema);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 292);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(field, _6);
		ZEPHIR_INIT_NVAR(definition);
		zephir_create_array(definition, 1, 0 TSRMLS_CC);
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
			ZEPHIR_CALL_FUNCTION(&_15, "preg_replace", &_16, 82, _8, _9, _14);
			zephir_check_temp_parameter(_8);
			zephir_check_temp_parameter(_9);
			zephir_check_call_status();
			zephir_array_update_string(&definition, SL("default"), &_15, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_17, definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 279 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_18);
			ZVAL_STRING(&_18, "null", 0);
			ZEPHIR_CALL_FUNCTION(&_19, "strcasecmp", &_20, 85, _17, &_18);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(_19, 0)) {
				zephir_array_update_string(&definition, SL("default"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
			}
		}
		zephir_array_fetch_long(&columnName, field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 287 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_7);
		object_init_ex(_7, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, _7, "__construct", &_21, 83, columnName, definition);
		zephir_check_call_status();
		zephir_array_append(&columns, _7, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 288);
		ZEPHIR_CPY_WRT(oldColumn, columnName);
	}
	RETURN_CCTOR(columns);

}

/**
 * Creates a table
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, createTable) {

	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *definition = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, *sql = NULL, *queries, *query = NULL, *exception = NULL, *columns, *_0, **_3, *_4 = NULL, *_6;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	definition = definition_param;



	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter/pdo/postgresql.zep", 303);
		return;
	}
	if (!(zephir_fast_count_int(columns TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter/pdo/postgresql.zep", 307);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&sql, _0, "createtable", NULL, 0, tableName, schemaName, definition);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(queries);
	zephir_fast_explode_str(queries, SL(";"), sql, LONG_MAX TSRMLS_CC);
	if (zephir_fast_count_int(queries TSRMLS_CC) > 1) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(NULL, this_ptr, "begin", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_is_iterable(queries, &_2, &_1, 0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 323);
			for (
			  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(query, _3);
				if (ZEPHIR_IS_EMPTY(query)) {
					continue;
				}
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_VS(_4, query, ";");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_5, 0, _4);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "commit", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(exception, EG(exception));
			if (zephir_instance_of_ev(exception, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(exception, "phalcon/db/adapter/pdo/postgresql.zep", 327 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		zephir_array_fetch_long(&_6, queries, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 331 TSRMLS_CC);
		ZEPHIR_INIT_LNVAR(_4);
		ZEPHIR_CONCAT_VS(_4, _6, ";");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _4);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Modifies a table column based on a definition
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, modifyColumn) {

	zephir_fcall_cache_entry *_5 = NULL;
	HashTable *_2;
	HashPosition _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *currentColumn = NULL, *sql = NULL, *queries, *query = NULL, *exception = NULL, *_0, **_3, *_4 = NULL, *_6 = NULL, *_7;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &tableName_param, &schemaName_param, &column, &currentColumn);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}

	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (!currentColumn) {
		currentColumn = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&sql, _0, "modifycolumn", NULL, 0, tableName, schemaName, column, currentColumn);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(queries);
	zephir_fast_explode_str(queries, SL(";"), sql, LONG_MAX TSRMLS_CC);
	if (zephir_fast_count_int(queries TSRMLS_CC) > 1) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(NULL, this_ptr, "begin", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_is_iterable(queries, &_2, &_1, 0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 355);
			for (
			  ; zephir_hash_get_current_data_ex(_2, (void**) &_3, &_1) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2, &_1)
			) {
				ZEPHIR_GET_HVALUE(query, _3);
				if (ZEPHIR_IS_EMPTY(query)) {
					continue;
				}
				ZEPHIR_INIT_LNVAR(_4);
				ZEPHIR_CONCAT_VS(_4, query, ";");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_5, 0, _4);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "commit", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_CPY_WRT(exception, EG(exception));
			if (zephir_instance_of_ev(exception, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(exception, "phalcon/db/adapter/pdo/postgresql.zep", 359 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		ZEPHIR_INIT_VAR(_6);
		if (!(ZEPHIR_IS_EMPTY(sql))) {
			zephir_array_fetch_long(&_7, queries, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 363 TSRMLS_CC);
			ZEPHIR_INIT_LNVAR(_4);
			ZEPHIR_CONCAT_VS(_4, _7, ";");
			ZEPHIR_CALL_METHOD(&_6, this_ptr, "execute", NULL, 0, _4);
			zephir_check_call_status();
		} else {
			ZVAL_BOOL(_6, 1);
		}
		RETURN_CCTOR(_6);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Check whether the database system requires an explicit value for identity columns
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
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *_0;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "default", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 78, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences) {


	RETURN_BOOL(1);

}

