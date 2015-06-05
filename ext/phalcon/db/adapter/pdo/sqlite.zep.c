
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
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/hash.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * Phalcon\Db\Adapter\Pdo\Sqlite
 *
 * Specific functions for the Sqlite database system
 * <code>
 *
 * $config = array(
 *  "dbname" => "/tmp/test.sqlite"
 * );
 *
 * $connection = new \Phalcon\Db\Adapter\Pdo\Sqlite($config);
 *
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Sqlite) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Sqlite, phalcon, db_adapter_pdo_sqlite, phalcon_db_adapter_pdo_ce, phalcon_db_adapter_pdo_sqlite_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_sqlite_ce, SL("_type"), "sqlite", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_db_adapter_pdo_sqlite_ce, SL("_dialectType"), "sqlite", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_adapter_pdo_sqlite_ce TSRMLS_CC, 1, phalcon_db_adapterinterface_ce);
	return SUCCESS;

}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection.
 *
 * @param array $descriptor
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, connect) {

	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *descriptor = NULL, *dbname;

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
	ZEPHIR_OBS_VAR(dbname);
	if (!(zephir_array_isset_string_fetch(&dbname, descriptor, SS("dbname"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "dbname must be specified", "phalcon/db/adapter/pdo/sqlite.zep", 70);
		return;
	}
	zephir_array_update_string(&descriptor, SL("dsn"), &dbname, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_sqlite_ce, this_ptr, "connect", &_0, 84, descriptor);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 *
 * <code>
 * print_r($connection->describeColumns("posts"));
 * </code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeColumns) {

	zephir_fcall_cache_entry *_16 = NULL, *_20 = NULL, *_21 = NULL;
	zend_bool _8;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *columns, *columnType = NULL, *field = NULL, *definition = NULL, *oldColumn = NULL, *sizePattern, *matches = NULL, *matchOne = NULL, *matchTwo = NULL, *columnName, *_0 = NULL, *_1, *_2 = NULL, *_3 = NULL, **_6, *_7 = NULL, *_9 = NULL, *_10, *_11 = NULL, *_12, *_13, _14 = zval_used_for_init, *_15 = NULL, *_17, *_18, *_19 = NULL;
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
	ZEPHIR_INIT_VAR(sizePattern);
	ZVAL_STRING(sizePattern, "#\\(([0-9]+)(?:,\\s*([0-9]+))*\\)#", 1);
	ZEPHIR_INIT_VAR(columns);
	array_init(columns);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "describecolumns", NULL, 0, table, schema);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 281);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(field, _6);
		ZEPHIR_INIT_NVAR(definition);
		zephir_create_array(definition, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(definition, SS("bindType"), 2);
		ZEPHIR_OBS_NVAR(columnType);
		zephir_array_fetch_long(&columnType, field, 2, PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 108 TSRMLS_CC);
		while (1) {
			if (zephir_memnstr_str(columnType, SL("tinyint(1)"), "phalcon/db/adapter/pdo/sqlite.zep", 115)) {
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_LONG(_3, 8);
				zephir_array_update_string(&definition, SL("type"), &_3, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_7, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(columnType);
				ZVAL_STRING(columnType, "boolean", 1);
				break;
			}
			_8 = zephir_memnstr_str(columnType, SL("int"), "phalcon/db/adapter/pdo/sqlite.zep", 125);
			if (!(_8)) {
				_8 = zephir_memnstr_str(columnType, SL("INT"), "phalcon/db/adapter/pdo/sqlite.zep", 125);
			}
			if (_8) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 0);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_LONG(_9, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_9, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_long(&_10, field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 131 TSRMLS_CC);
				if (zephir_is_true(_10)) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				}
				break;
			}
			if (zephir_memnstr_str(columnType, SL("varchar"), "phalcon/db/adapter/pdo/sqlite.zep", 140)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 2);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("date"), "phalcon/db/adapter/pdo/sqlite.zep", 148)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 1);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("timestamp"), "phalcon/db/adapter/pdo/sqlite.zep", 156)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 1);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("decimal"), "phalcon/db/adapter/pdo/sqlite.zep", 164)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 3);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_LONG(_9, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_9, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("char"), "phalcon/db/adapter/pdo/sqlite.zep", 174)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 5);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("datetime"), "phalcon/db/adapter/pdo/sqlite.zep", 182)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 4);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("text"), "phalcon/db/adapter/pdo/sqlite.zep", 190)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 6);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("float"), "phalcon/db/adapter/pdo/sqlite.zep", 198)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 7);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_9);
				ZVAL_LONG(_9, 3);
				zephir_array_update_string(&definition, SL("bindType"), &_9, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("enum"), "phalcon/db/adapter/pdo/sqlite.zep", 208)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 5);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, 2);
			zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
			break;
		}
		if (zephir_memnstr_str(columnType, SL("("), "phalcon/db/adapter/pdo/sqlite.zep", 223)) {
			ZEPHIR_INIT_NVAR(matches);
			ZVAL_NULL(matches);
			ZEPHIR_INIT_NVAR(_9);
			zephir_preg_match(_9, sizePattern, columnType, matches, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(_9)) {
				ZEPHIR_OBS_NVAR(matchOne);
				if (zephir_array_isset_long_fetch(&matchOne, matches, 1, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_11);
					ZVAL_LONG(_11, zephir_get_intval(matchOne));
					zephir_array_update_string(&definition, SL("size"), &_11, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(matchTwo);
				if (zephir_array_isset_long_fetch(&matchTwo, matches, 2, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_11);
					ZVAL_LONG(_11, zephir_get_intval(matchTwo));
					zephir_array_update_string(&definition, SL("scale"), &_11, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_memnstr_str(columnType, SL("unsigned"), "phalcon/db/adapter/pdo/sqlite.zep", 238)) {
			zephir_array_update_string(&definition, SL("unsigned"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_10, field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 254 TSRMLS_CC);
		if (zephir_is_true(_10)) {
			zephir_array_update_string(&definition, SL("primary"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_12, field, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 261 TSRMLS_CC);
		if (zephir_is_true(_12)) {
			zephir_array_update_string(&definition, SL("notNull"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_13, field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 269 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_14);
		ZVAL_STRING(&_14, "null", 0);
		ZEPHIR_CALL_FUNCTION(&_15, "strcasecmp", &_16, 85, _13, &_14);
		zephir_check_call_status();
		_8 = !ZEPHIR_IS_LONG(_15, 0);
		if (_8) {
			zephir_array_fetch_long(&_17, field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 269 TSRMLS_CC);
			_8 = !ZEPHIR_IS_STRING(_17, "");
		}
		if (_8) {
			zephir_array_fetch_long(&_18, field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 270 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_STRING(_7, "/^'|'$/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_9);
			ZVAL_STRING(_9, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_19, "preg_replace", &_20, 82, _7, _9, _18);
			zephir_check_temp_parameter(_7);
			zephir_check_temp_parameter(_9);
			zephir_check_call_status();
			zephir_array_update_string(&definition, SL("default"), &_19, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&columnName, field, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 276 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_7);
		object_init_ex(_7, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, _7, "__construct", &_21, 83, columnName, definition);
		zephir_check_call_status();
		zephir_array_append(&columns, _7, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 277);
		ZEPHIR_CPY_WRT(oldColumn, columnName);
	}
	RETURN_CCTOR(columns);

}

/**
 * Lists table indexes
 *
 * @param	string table
 * @param	string schema
 * @return	Phalcon\Db\IndexInterface[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes) {

	zephir_fcall_cache_entry *_17 = NULL;
	HashTable *_5, *_11, *_15;
	HashPosition _4, _10, _14;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table, *schema = NULL, *indexes, *index = NULL, *keyName = NULL, *indexObjects, *name = NULL, *indexColumns = NULL, *columns = NULL, *describe_index = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3 = NULL, **_6, *_7 = NULL, *_8, *_9 = NULL, **_12, *_13, **_16;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &schema);

	if (!schema) {
		schema = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(indexes);
	array_init(indexes);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "describeindexes", NULL, 0, table, schema);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 313);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(index, _6);
		ZEPHIR_OBS_NVAR(keyName);
		zephir_array_fetch_long(&keyName, index, 1, PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 299 TSRMLS_CC);
		if (!(zephir_array_isset(indexes, keyName))) {
			ZEPHIR_INIT_NVAR(columns);
			array_init(columns);
		} else {
			ZEPHIR_OBS_NVAR(columns);
			zephir_array_fetch(&columns, indexes, keyName, PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 303 TSRMLS_CC);
		}
		_8 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_9, _8, "describeindex", NULL, 0, keyName);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_3);
		ZVAL_LONG(_3, 3);
		ZEPHIR_CALL_METHOD(&_7, this_ptr, "fetchall", NULL, 0, _9, _3);
		zephir_check_call_status();
		zephir_is_iterable(_7, &_11, &_10, 0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 310);
		for (
		  ; zephir_hash_get_current_data_ex(_11, (void**) &_12, &_10) == SUCCESS
		  ; zephir_hash_move_forward_ex(_11, &_10)
		) {
			ZEPHIR_GET_HVALUE(describe_index, _12);
			zephir_array_fetch_long(&_13, describe_index, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 307 TSRMLS_CC);
			zephir_array_append(&columns, _13, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 307);
		}
		zephir_array_update_zval(&indexes, keyName, &columns, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(indexObjects);
	array_init(indexObjects);
	zephir_is_iterable(indexes, &_15, &_14, 0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 318);
	for (
	  ; zephir_hash_get_current_data_ex(_15, (void**) &_16, &_14) == SUCCESS
	  ; zephir_hash_move_forward_ex(_15, &_14)
	) {
		ZEPHIR_GET_HMKEY(name, _15, _14);
		ZEPHIR_GET_HVALUE(indexColumns, _16);
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, phalcon_db_index_ce);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_17, 76, name, indexColumns);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, name, &_3, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(indexObjects);

}

/**
 * Lists table references
 *
 * @param	string table
 * @param	string schema
 * @return	Phalcon\Db\ReferenceInterface[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeReferences) {

	zephir_fcall_cache_entry *_16 = NULL;
	zval *_11 = NULL;
	HashTable *_5, *_13;
	HashPosition _4, _12;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table, *schema = NULL, *references, *reference = NULL, *arrayReference = NULL, *constraintName = NULL, *referenceObjects, *name = NULL, *referencedSchema = NULL, *referencedTable = NULL, *columns = NULL, *referencedColumns = NULL, *number = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3 = NULL, **_6, *_7, *_8, *_9, *_10, **_14, *_15 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &schema);

	if (!schema) {
		schema = ZEPHIR_GLOBAL(global_null);
	}


	ZEPHIR_INIT_VAR(references);
	array_init(references);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "describereferences", NULL, 0, table, schema);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 363);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HMKEY(number, _5, _4);
		ZEPHIR_GET_HVALUE(reference, _6);
		ZEPHIR_INIT_NVAR(constraintName);
		ZEPHIR_CONCAT_SV(constraintName, "foreign_key_", number);
		if (!(zephir_array_isset(references, constraintName))) {
			ZEPHIR_INIT_NVAR(referencedSchema);
			ZVAL_NULL(referencedSchema);
			ZEPHIR_OBS_NVAR(referencedTable);
			zephir_array_fetch_long(&referencedTable, reference, 2, PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 342 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(columns);
			array_init(columns);
			ZEPHIR_INIT_NVAR(referencedColumns);
			array_init(referencedColumns);
		} else {
			zephir_array_fetch(&_7, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 346 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedSchema);
			zephir_array_fetch_string(&referencedSchema, _7, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 346 TSRMLS_CC);
			zephir_array_fetch(&_8, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 347 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedTable);
			zephir_array_fetch_string(&referencedTable, _8, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 347 TSRMLS_CC);
			zephir_array_fetch(&_9, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 348 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(columns);
			zephir_array_fetch_string(&columns, _9, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 348 TSRMLS_CC);
			zephir_array_fetch(&_10, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 349 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedColumns);
			zephir_array_fetch_string(&referencedColumns, _10, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 349 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_7, reference, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 352 TSRMLS_CC);
		zephir_array_append(&columns, _7, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 352);
		zephir_array_fetch_long(&_8, reference, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 353 TSRMLS_CC);
		zephir_array_append(&referencedColumns, _8, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 353);
		ZEPHIR_INIT_NVAR(_11);
		zephir_create_array(_11, 4, 0 TSRMLS_CC);
		zephir_array_update_string(&_11, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_11, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_11, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_11, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
		zephir_array_update_zval(&references, constraintName, &_11, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(referenceObjects);
	array_init(referenceObjects);
	zephir_is_iterable(references, &_13, &_12, 0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 373);
	for (
	  ; zephir_hash_get_current_data_ex(_13, (void**) &_14, &_12) == SUCCESS
	  ; zephir_hash_move_forward_ex(_13, &_12)
	) {
		ZEPHIR_GET_HMKEY(name, _13, _12);
		ZEPHIR_GET_HVALUE(arrayReference, _14);
		ZEPHIR_INIT_NVAR(_3);
		object_init_ex(_3, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(_11);
		zephir_create_array(_11, 4, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_15);
		zephir_array_fetch_string(&_15, arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 366 TSRMLS_CC);
		zephir_array_update_string(&_11, SL("referencedSchema"), &_15, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_15);
		zephir_array_fetch_string(&_15, arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 367 TSRMLS_CC);
		zephir_array_update_string(&_11, SL("referencedTable"), &_15, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_15);
		zephir_array_fetch_string(&_15, arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 368 TSRMLS_CC);
		zephir_array_update_string(&_11, SL("columns"), &_15, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_15);
		zephir_array_fetch_string(&_15, arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 370 TSRMLS_CC);
		zephir_array_update_string(&_11, SL("referencedColumns"), &_15, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, _3, "__construct", &_16, 77, name, _11);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, name, &_3, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(referenceObjects);

}

/**
 * Check whether the database system requires an explicit value for identity columns
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, useExplicitIdValue) {


	RETURN_BOOL(1);

}

