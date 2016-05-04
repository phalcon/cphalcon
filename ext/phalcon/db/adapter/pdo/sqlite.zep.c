
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
	zval *descriptor = NULL, *dbname = NULL;

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
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_sqlite_ce, this_ptr, "connect", &_0, 147, descriptor);
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

	zend_bool _11$$4, _36$$3;
	HashTable *_5;
	HashPosition _4;
	zephir_fcall_cache_entry *_35 = NULL, *_42 = NULL, *_44 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *columns = NULL, *columnType = NULL, *field = NULL, *definition = NULL, *oldColumn = NULL, *sizePattern = NULL, *matches = NULL, *matchOne = NULL, *matchTwo = NULL, *columnName = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, *_7$$5 = NULL, *_8$$5 = NULL, *_9$$6 = NULL, *_10$$6 = NULL, *_26$$4 = NULL, *_12$$7 = NULL, *_13$$7 = NULL, *_14$$7, *_15$$9 = NULL, *_16$$10 = NULL, *_17$$11 = NULL, *_18$$12 = NULL, *_19$$12 = NULL, *_20$$13 = NULL, *_21$$14 = NULL, *_22$$15 = NULL, *_23$$16 = NULL, *_24$$16 = NULL, *_25$$17 = NULL, *_27$$18 = NULL, *_28$$20 = NULL, *_29$$21 = NULL, *_30$$3, *_31$$3, *_32$$3, _33$$3 = zval_used_for_init, *_34$$3 = NULL, *_37$$3, *_43$$3 = NULL, *_38$$27, *_39$$27 = NULL, *_40$$27 = NULL, *_41$$27 = NULL;
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
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 291);
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
				ZEPHIR_INIT_NVAR(_7$$5);
				ZVAL_LONG(_7$$5, 8);
				zephir_array_update_string(&definition, SL("type"), &_7$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8$$5);
				ZVAL_LONG(_8$$5, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_8$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(columnType);
				ZVAL_STRING(columnType, "boolean", 1);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("bigint"), "phalcon/db/adapter/pdo/sqlite.zep", 125)) {
				ZEPHIR_INIT_NVAR(_9$$6);
				ZVAL_LONG(_9$$6, 14);
				zephir_array_update_string(&definition, SL("type"), &_9$$6, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_10$$6);
				ZVAL_LONG(_10$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_10$$6, PH_COPY | PH_SEPARATE);
				break;
			}
			_11$$4 = zephir_memnstr_str(columnType, SL("int"), "phalcon/db/adapter/pdo/sqlite.zep", 135);
			if (!(_11$$4)) {
				_11$$4 = zephir_memnstr_str(columnType, SL("INT"), "phalcon/db/adapter/pdo/sqlite.zep", 135);
			}
			if (_11$$4) {
				ZEPHIR_INIT_NVAR(_12$$7);
				ZVAL_LONG(_12$$7, 0);
				zephir_array_update_string(&definition, SL("type"), &_12$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_13$$7);
				ZVAL_LONG(_13$$7, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_13$$7, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_long(&_14$$7, field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 141 TSRMLS_CC);
				if (zephir_is_true(_14$$7)) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				}
				break;
			}
			if (zephir_memnstr_str(columnType, SL("varchar"), "phalcon/db/adapter/pdo/sqlite.zep", 150)) {
				ZEPHIR_INIT_NVAR(_15$$9);
				ZVAL_LONG(_15$$9, 2);
				zephir_array_update_string(&definition, SL("type"), &_15$$9, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("date"), "phalcon/db/adapter/pdo/sqlite.zep", 158)) {
				ZEPHIR_INIT_NVAR(_16$$10);
				ZVAL_LONG(_16$$10, 1);
				zephir_array_update_string(&definition, SL("type"), &_16$$10, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("timestamp"), "phalcon/db/adapter/pdo/sqlite.zep", 166)) {
				ZEPHIR_INIT_NVAR(_17$$11);
				ZVAL_LONG(_17$$11, 17);
				zephir_array_update_string(&definition, SL("type"), &_17$$11, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("decimal"), "phalcon/db/adapter/pdo/sqlite.zep", 174)) {
				ZEPHIR_INIT_NVAR(_18$$12);
				ZVAL_LONG(_18$$12, 3);
				zephir_array_update_string(&definition, SL("type"), &_18$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_19$$12);
				ZVAL_LONG(_19$$12, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_19$$12, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("char"), "phalcon/db/adapter/pdo/sqlite.zep", 184)) {
				ZEPHIR_INIT_NVAR(_20$$13);
				ZVAL_LONG(_20$$13, 5);
				zephir_array_update_string(&definition, SL("type"), &_20$$13, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("datetime"), "phalcon/db/adapter/pdo/sqlite.zep", 192)) {
				ZEPHIR_INIT_NVAR(_21$$14);
				ZVAL_LONG(_21$$14, 4);
				zephir_array_update_string(&definition, SL("type"), &_21$$14, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("text"), "phalcon/db/adapter/pdo/sqlite.zep", 200)) {
				ZEPHIR_INIT_NVAR(_22$$15);
				ZVAL_LONG(_22$$15, 6);
				zephir_array_update_string(&definition, SL("type"), &_22$$15, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("float"), "phalcon/db/adapter/pdo/sqlite.zep", 208)) {
				ZEPHIR_INIT_NVAR(_23$$16);
				ZVAL_LONG(_23$$16, 7);
				zephir_array_update_string(&definition, SL("type"), &_23$$16, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_24$$16);
				ZVAL_LONG(_24$$16, 3);
				zephir_array_update_string(&definition, SL("bindType"), &_24$$16, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("enum"), "phalcon/db/adapter/pdo/sqlite.zep", 218)) {
				ZEPHIR_INIT_NVAR(_25$$17);
				ZVAL_LONG(_25$$17, 5);
				zephir_array_update_string(&definition, SL("type"), &_25$$17, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(_26$$4);
			ZVAL_LONG(_26$$4, 2);
			zephir_array_update_string(&definition, SL("type"), &_26$$4, PH_COPY | PH_SEPARATE);
			break;
		}
		if (zephir_memnstr_str(columnType, SL("("), "phalcon/db/adapter/pdo/sqlite.zep", 233)) {
			ZEPHIR_INIT_NVAR(matches);
			ZVAL_NULL(matches);
			ZEPHIR_INIT_NVAR(_27$$18);
			zephir_preg_match(_27$$18, sizePattern, columnType, matches, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(_27$$18)) {
				ZEPHIR_OBS_NVAR(matchOne);
				if (zephir_array_isset_long_fetch(&matchOne, matches, 1, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_28$$20);
					ZVAL_LONG(_28$$20, zephir_get_intval(matchOne));
					zephir_array_update_string(&definition, SL("size"), &_28$$20, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(matchTwo);
				if (zephir_array_isset_long_fetch(&matchTwo, matches, 2, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_29$$21);
					ZVAL_LONG(_29$$21, zephir_get_intval(matchTwo));
					zephir_array_update_string(&definition, SL("scale"), &_29$$21, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_memnstr_str(columnType, SL("unsigned"), "phalcon/db/adapter/pdo/sqlite.zep", 248)) {
			zephir_array_update_string(&definition, SL("unsigned"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_30$$3, field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 264 TSRMLS_CC);
		if (zephir_is_true(_30$$3)) {
			zephir_array_update_string(&definition, SL("primary"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_31$$3, field, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 271 TSRMLS_CC);
		if (zephir_is_true(_31$$3)) {
			zephir_array_update_string(&definition, SL("notNull"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_32$$3, field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 279 TSRMLS_CC);
		ZEPHIR_SINIT_NVAR(_33$$3);
		ZVAL_STRING(&_33$$3, "null", 0);
		ZEPHIR_CALL_FUNCTION(&_34$$3, "strcasecmp", &_35, 19, _32$$3, &_33$$3);
		zephir_check_call_status();
		_36$$3 = !ZEPHIR_IS_LONG(_34$$3, 0);
		if (_36$$3) {
			zephir_array_fetch_long(&_37$$3, field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 279 TSRMLS_CC);
			_36$$3 = !ZEPHIR_IS_STRING(_37$$3, "");
		}
		if (_36$$3) {
			zephir_array_fetch_long(&_38$$27, field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 280 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_39$$27);
			ZVAL_STRING(_39$$27, "/^'|'$/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_40$$27);
			ZVAL_STRING(_40$$27, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_41$$27, "preg_replace", &_42, 29, _39$$27, _40$$27, _38$$27);
			zephir_check_temp_parameter(_39$$27);
			zephir_check_temp_parameter(_40$$27);
			zephir_check_call_status();
			zephir_array_update_string(&definition, SL("default"), &_41$$27, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&columnName, field, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 286 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_43$$3);
		object_init_ex(_43$$3, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, _43$$3, "__construct", &_44, 146, columnName, definition);
		zephir_check_call_status();
		zephir_array_append(&columns, _43$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 287);
		ZEPHIR_CPY_WRT(oldColumn, columnName);
	}
	RETURN_CCTOR(columns);

}

/**
 * Lists table indexes
 *
 * <code>
 *   print_r($connection->describeIndexes('robots_parts'));
 * </code>
 *
 * @param  string table
 * @param  string schema
 * @return \Phalcon\Db\IndexInterface[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes) {

	HashTable *_5, *_28, *_15$$3;
	HashPosition _4, _27, _14$$3;
	zephir_fcall_cache_entry *_20 = NULL, *_33 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table, *schema = NULL, *indexes = NULL, *index = NULL, *keyName = NULL, *indexObjects = NULL, *name = NULL, *columns = NULL, *describeIndex = NULL, *indexSql = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, **_29, *_7$$4 = NULL, *_8$$3, *_10$$3 = NULL, *_11$$3, *_12$$3 = NULL, *_13$$3 = NULL, **_16$$3, *_18$$3, *_19$$3 = NULL, *_21$$3, *_9$$6, *_17$$7, *_22$$8 = NULL, *_23$$8 = NULL, _24$$8 = zval_used_for_init, *_25$$9 = NULL, *_26$$10 = NULL, *_30$$12 = NULL, *_31$$12, *_32$$12;

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
	ZVAL_LONG(_3, 2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 341);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(index, _6);
		ZEPHIR_OBS_NVAR(keyName);
		zephir_array_fetch_string(&keyName, index, SL("name"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 311 TSRMLS_CC);
		if (!(zephir_array_isset(indexes, keyName))) {
			ZEPHIR_INIT_NVAR(_7$$4);
			array_init(_7$$4);
			zephir_array_update_zval(&indexes, keyName, &_7$$4, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch(&_8$$3, indexes, keyName, PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 317 TSRMLS_CC);
		if (!(zephir_array_isset_string(_8$$3, SS("columns")))) {
			ZEPHIR_INIT_NVAR(columns);
			array_init(columns);
		} else {
			zephir_array_fetch(&_9$$6, indexes, keyName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 320 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(columns);
			zephir_array_fetch_string(&columns, _9$$6, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 320 TSRMLS_CC);
		}
		_11$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_12$$3, _11$$3, "describeindex", NULL, 0, keyName);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(_13$$3);
		ZVAL_LONG(_13$$3, 2);
		ZEPHIR_CALL_METHOD(&_10$$3, this_ptr, "fetchall", NULL, 0, _12$$3, _13$$3);
		zephir_check_call_status();
		zephir_is_iterable(_10$$3, &_15$$3, &_14$$3, 0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 327);
		for (
		  ; zephir_hash_get_current_data_ex(_15$$3, (void**) &_16$$3, &_14$$3) == SUCCESS
		  ; zephir_hash_move_forward_ex(_15$$3, &_14$$3)
		) {
			ZEPHIR_GET_HVALUE(describeIndex, _16$$3);
			zephir_array_fetch_string(&_17$$7, describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 324 TSRMLS_CC);
			zephir_array_append(&columns, _17$$7, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 324);
		}
		zephir_array_update_multi(&indexes, &columns TSRMLS_CC, SL("zs"), 3, keyName, SL("columns"));
		_18$$3 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
		ZEPHIR_CALL_METHOD(&_19$$3, _18$$3, "listindexessql", NULL, 0, table, schema, keyName);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&indexSql, this_ptr, "fetchcolumn", &_20, 0, _19$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_21$$3, index, SL("unique"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 330 TSRMLS_CC);
		if (zephir_is_true(_21$$3)) {
			ZEPHIR_INIT_NVAR(_22$$8);
			ZEPHIR_INIT_NVAR(_23$$8);
			ZEPHIR_SINIT_NVAR(_24$$8);
			ZVAL_STRING(&_24$$8, "# UNIQUE #i", 0);
			zephir_preg_match(_23$$8, &_24$$8, indexSql, _22$$8, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(_23$$8)) {
				ZEPHIR_INIT_NVAR(_25$$9);
				ZVAL_STRING(_25$$9, "UNIQUE", 1);
				zephir_array_update_multi(&indexes, &_25$$9 TSRMLS_CC, SL("zs"), 3, keyName, SL("type"));
			} else {
				ZEPHIR_INIT_NVAR(_26$$10);
				ZVAL_STRING(_26$$10, "PRIMARY", 1);
				zephir_array_update_multi(&indexes, &_26$$10 TSRMLS_CC, SL("zs"), 3, keyName, SL("type"));
			}
		} else {
			zephir_array_update_multi(&indexes, &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("zs"), 3, keyName, SL("type"));
		}
	}
	ZEPHIR_INIT_VAR(indexObjects);
	array_init(indexObjects);
	zephir_is_iterable(indexes, &_28, &_27, 0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 346);
	for (
	  ; zephir_hash_get_current_data_ex(_28, (void**) &_29, &_27) == SUCCESS
	  ; zephir_hash_move_forward_ex(_28, &_27)
	) {
		ZEPHIR_GET_HMKEY(name, _28, _27);
		ZEPHIR_GET_HVALUE(index, _29);
		ZEPHIR_INIT_NVAR(_30$$12);
		object_init_ex(_30$$12, phalcon_db_index_ce);
		zephir_array_fetch_string(&_31$$12, index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 343 TSRMLS_CC);
		zephir_array_fetch_string(&_32$$12, index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 343 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, _30$$12, "__construct", &_33, 15, name, _31$$12, _32$$12);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, name, &_30$$12, PH_COPY | PH_SEPARATE);
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

	zval *_13$$3 = NULL, *_18$$6 = NULL;
	HashTable *_5, *_15;
	HashPosition _4, _14;
	zephir_fcall_cache_entry *_20 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table, *schema = NULL, *references = NULL, *reference = NULL, *arrayReference = NULL, *constraintName = NULL, *referenceObjects = NULL, *name = NULL, *referencedSchema = NULL, *referencedTable = NULL, *columns = NULL, *referencedColumns = NULL, *number = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, **_16, *_7$$5, *_8$$5, *_9$$5, *_10$$5, *_11$$3, *_12$$3, *_17$$6 = NULL, *_19$$6 = NULL;

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
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 391);
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
			zephir_array_fetch_long(&referencedTable, reference, 2, PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 370 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(columns);
			array_init(columns);
			ZEPHIR_INIT_NVAR(referencedColumns);
			array_init(referencedColumns);
		} else {
			zephir_array_fetch(&_7$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 374 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedSchema);
			zephir_array_fetch_string(&referencedSchema, _7$$5, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 374 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 375 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedTable);
			zephir_array_fetch_string(&referencedTable, _8$$5, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 375 TSRMLS_CC);
			zephir_array_fetch(&_9$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 376 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(columns);
			zephir_array_fetch_string(&columns, _9$$5, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 376 TSRMLS_CC);
			zephir_array_fetch(&_10$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 377 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedColumns);
			zephir_array_fetch_string(&referencedColumns, _10$$5, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 377 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_11$$3, reference, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 380 TSRMLS_CC);
		zephir_array_append(&columns, _11$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 380);
		zephir_array_fetch_long(&_12$$3, reference, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 381 TSRMLS_CC);
		zephir_array_append(&referencedColumns, _12$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 381);
		ZEPHIR_INIT_NVAR(_13$$3);
		zephir_create_array(_13$$3, 4, 0 TSRMLS_CC);
		zephir_array_update_string(&_13$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
		zephir_array_update_zval(&references, constraintName, &_13$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(referenceObjects);
	array_init(referenceObjects);
	zephir_is_iterable(references, &_15, &_14, 0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 401);
	for (
	  ; zephir_hash_get_current_data_ex(_15, (void**) &_16, &_14) == SUCCESS
	  ; zephir_hash_move_forward_ex(_15, &_14)
	) {
		ZEPHIR_GET_HMKEY(name, _15, _14);
		ZEPHIR_GET_HVALUE(arrayReference, _16);
		ZEPHIR_INIT_NVAR(_17$$6);
		object_init_ex(_17$$6, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(_18$$6);
		zephir_create_array(_18$$6, 4, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_19$$6);
		zephir_array_fetch_string(&_19$$6, arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 394 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedSchema"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_19$$6);
		zephir_array_fetch_string(&_19$$6, arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 395 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedTable"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_19$$6);
		zephir_array_fetch_string(&_19$$6, arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 396 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("columns"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_19$$6);
		zephir_array_fetch_string(&_19$$6, arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 398 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedColumns"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, _17$$6, "__construct", &_20, 16, name, _18$$6);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, name, &_17$$6, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(referenceObjects);

}

/**
 * Check whether the database system requires an explicit value for identity columns
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, useExplicitIdValue) {

	

	RETURN_BOOL(1);

}

/**
 * Returns the default value to make the RBDM use the default value declared in the table definition
 *
 *<code>
 * //Inserting a new robot with a valid default value for the column 'year'
 * $success = $connection->insert(
 *	 "robots",
 *	 array("Astro Boy", $connection->getDefaultValue()),
 *	 array("name", "year")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, getDefaultValue) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "NULL", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 17, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

