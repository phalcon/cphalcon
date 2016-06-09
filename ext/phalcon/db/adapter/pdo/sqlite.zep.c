
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
	zval *descriptor = NULL, descriptor_sub, __$null, dbname;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&descriptor_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&dbname);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &descriptor);

	if (!descriptor) {
		descriptor = &descriptor_sub;
		ZEPHIR_CPY_WRT(descriptor, &__$null);
	} else {
		ZEPHIR_SEPARATE_PARAM(descriptor);
	}


	if (Z_TYPE_P(descriptor) == IS_NULL) {
		ZEPHIR_OBS_NVAR(descriptor);
		zephir_read_property(descriptor, this_ptr, SL("_descriptor"), PH_NOISY_CC);
	}
	ZEPHIR_OBS_VAR(&dbname);
	if (!(zephir_array_isset_string_fetch(&dbname, descriptor, SL("dbname"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "dbname must be specified", "phalcon/db/adapter/pdo/sqlite.zep", 70);
		return;
	}
	zephir_array_update_string(descriptor, SL("dsn"), &dbname, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_sqlite_ce, this_ptr, "connect", &_0, 152, descriptor);
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

	zend_bool _9$$4, _34$$3;
	zephir_fcall_cache_entry *_33 = NULL, *_40 = NULL, *_41 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$true, columns, columnType, field, definition, oldColumn, sizePattern, matches, matchOne, matchTwo, columnName, _0, _1, _2, _3, *_4, _5$$5, _6$$5, _7$$6, _8$$6, _24$$4, _10$$7, _11$$7, _12$$7, _13$$9, _14$$10, _15$$11, _16$$12, _17$$12, _18$$13, _19$$14, _20$$15, _21$$16, _22$$16, _23$$17, _25$$18, _26$$20, _27$$21, _28$$3, _29$$3, _30$$3, _31$$3, _32$$3, _35$$3, _36$$27, _37$$27, _38$$27, _39$$27;
	zval table, schema;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&oldColumn);
	ZVAL_UNDEF(&sizePattern);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&matchOne);
	ZVAL_UNDEF(&matchTwo);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_24$$4);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$12);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$14);
	ZVAL_UNDEF(&_20$$15);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_22$$16);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_26$$20);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_28$$3);
	ZVAL_UNDEF(&_29$$3);
	ZVAL_UNDEF(&_30$$3);
	ZVAL_UNDEF(&_31$$3);
	ZVAL_UNDEF(&_32$$3);
	ZVAL_UNDEF(&_35$$3);
	ZVAL_UNDEF(&_36$$27);
	ZVAL_UNDEF(&_37$$27);
	ZVAL_UNDEF(&_38$$27);
	ZVAL_UNDEF(&_39$$27);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	zephir_get_strval(&table, table_param);
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_INIT_VAR(&oldColumn);
	ZVAL_NULL(&oldColumn);
	ZEPHIR_INIT_VAR(&sizePattern);
	ZVAL_STRING(&sizePattern, "#\\(([0-9]+)(?:,\\s*([0-9]+))*\\)#");
	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describecolumns", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 291);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&field);
		ZVAL_COPY(&field, _4);
		ZEPHIR_INIT_NVAR(&definition);
		zephir_create_array(&definition, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(&definition, SL("bindType"), 2);
		ZEPHIR_OBS_NVAR(&columnType);
		zephir_array_fetch_long(&columnType, &field, 2, PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 108 TSRMLS_CC);
		while (1) {
			if (zephir_memnstr_str(&columnType, SL("tinyint(1)"), "phalcon/db/adapter/pdo/sqlite.zep", 115)) {
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_LONG(&_5$$5, 8);
				zephir_array_update_string(&definition, SL("type"), &_5$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZVAL_LONG(&_6$$5, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_6$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&columnType);
				ZVAL_STRING(&columnType, "boolean");
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/db/adapter/pdo/sqlite.zep", 125)) {
				ZEPHIR_INIT_NVAR(&_7$$6);
				ZVAL_LONG(&_7$$6, 14);
				zephir_array_update_string(&definition, SL("type"), &_7$$6, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_8$$6);
				ZVAL_LONG(&_8$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_8$$6, PH_COPY | PH_SEPARATE);
				break;
			}
			_9$$4 = zephir_memnstr_str(&columnType, SL("int"), "phalcon/db/adapter/pdo/sqlite.zep", 135);
			if (!(_9$$4)) {
				_9$$4 = zephir_memnstr_str(&columnType, SL("INT"), "phalcon/db/adapter/pdo/sqlite.zep", 135);
			}
			if (_9$$4) {
				ZEPHIR_INIT_NVAR(&_10$$7);
				ZVAL_LONG(&_10$$7, 0);
				zephir_array_update_string(&definition, SL("type"), &_10$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_11$$7);
				ZVAL_LONG(&_11$$7, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_11$$7, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_long(&_12$$7, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 141 TSRMLS_CC);
				if (zephir_is_true(&_12$$7)) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/db/adapter/pdo/sqlite.zep", 150)) {
				ZEPHIR_INIT_NVAR(&_13$$9);
				ZVAL_LONG(&_13$$9, 2);
				zephir_array_update_string(&definition, SL("type"), &_13$$9, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("date"), "phalcon/db/adapter/pdo/sqlite.zep", 158)) {
				ZEPHIR_INIT_NVAR(&_14$$10);
				ZVAL_LONG(&_14$$10, 1);
				zephir_array_update_string(&definition, SL("type"), &_14$$10, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/db/adapter/pdo/sqlite.zep", 166)) {
				ZEPHIR_INIT_NVAR(&_15$$11);
				ZVAL_LONG(&_15$$11, 17);
				zephir_array_update_string(&definition, SL("type"), &_15$$11, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/db/adapter/pdo/sqlite.zep", 174)) {
				ZEPHIR_INIT_NVAR(&_16$$12);
				ZVAL_LONG(&_16$$12, 3);
				zephir_array_update_string(&definition, SL("type"), &_16$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_17$$12);
				ZVAL_LONG(&_17$$12, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_17$$12, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("char"), "phalcon/db/adapter/pdo/sqlite.zep", 184)) {
				ZEPHIR_INIT_NVAR(&_18$$13);
				ZVAL_LONG(&_18$$13, 5);
				zephir_array_update_string(&definition, SL("type"), &_18$$13, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/db/adapter/pdo/sqlite.zep", 192)) {
				ZEPHIR_INIT_NVAR(&_19$$14);
				ZVAL_LONG(&_19$$14, 4);
				zephir_array_update_string(&definition, SL("type"), &_19$$14, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("text"), "phalcon/db/adapter/pdo/sqlite.zep", 200)) {
				ZEPHIR_INIT_NVAR(&_20$$15);
				ZVAL_LONG(&_20$$15, 6);
				zephir_array_update_string(&definition, SL("type"), &_20$$15, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("float"), "phalcon/db/adapter/pdo/sqlite.zep", 208)) {
				ZEPHIR_INIT_NVAR(&_21$$16);
				ZVAL_LONG(&_21$$16, 7);
				zephir_array_update_string(&definition, SL("type"), &_21$$16, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_22$$16);
				ZVAL_LONG(&_22$$16, 3);
				zephir_array_update_string(&definition, SL("bindType"), &_22$$16, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("enum"), "phalcon/db/adapter/pdo/sqlite.zep", 218)) {
				ZEPHIR_INIT_NVAR(&_23$$17);
				ZVAL_LONG(&_23$$17, 5);
				zephir_array_update_string(&definition, SL("type"), &_23$$17, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(&_24$$4);
			ZVAL_LONG(&_24$$4, 2);
			zephir_array_update_string(&definition, SL("type"), &_24$$4, PH_COPY | PH_SEPARATE);
			break;
		}
		if (zephir_memnstr_str(&columnType, SL("("), "phalcon/db/adapter/pdo/sqlite.zep", 233)) {
			ZEPHIR_INIT_NVAR(&matches);
			ZVAL_NULL(&matches);
			ZEPHIR_INIT_NVAR(&_25$$18);
			zephir_preg_match(&_25$$18, &sizePattern, &columnType, &matches, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(&_25$$18)) {
				ZEPHIR_OBS_NVAR(&matchOne);
				if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(&_26$$20);
					ZVAL_LONG(&_26$$20, zephir_get_intval(&matchOne));
					zephir_array_update_string(&definition, SL("size"), &_26$$20, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&matchTwo);
				if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(&_27$$21);
					ZVAL_LONG(&_27$$21, zephir_get_intval(&matchTwo));
					zephir_array_update_string(&definition, SL("scale"), &_27$$21, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/db/adapter/pdo/sqlite.zep", 248)) {
			zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_28$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 264 TSRMLS_CC);
		if (zephir_is_true(&_28$$3)) {
			zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_29$$3, &field, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 271 TSRMLS_CC);
		if (zephir_is_true(&_29$$3)) {
			zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_30$$3, &field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 279 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_31$$3);
		ZVAL_STRING(&_31$$3, "null");
		ZEPHIR_CALL_FUNCTION(&_32$$3, "strcasecmp", &_33, 23, &_30$$3, &_31$$3);
		zephir_check_call_status();
		_34$$3 = !ZEPHIR_IS_LONG(&_32$$3, 0);
		if (_34$$3) {
			zephir_array_fetch_long(&_35$$3, &field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 279 TSRMLS_CC);
			_34$$3 = !ZEPHIR_IS_STRING(&_35$$3, "");
		}
		if (_34$$3) {
			zephir_array_fetch_long(&_36$$27, &field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 280 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_37$$27);
			ZVAL_STRING(&_37$$27, "/^'|'$/");
			ZEPHIR_INIT_NVAR(&_38$$27);
			ZVAL_STRING(&_38$$27, "");
			ZEPHIR_CALL_FUNCTION(&_39$$27, "preg_replace", &_40, 29, &_37$$27, &_38$$27, &_36$$27);
			zephir_check_call_status();
			zephir_array_update_string(&definition, SL("default"), &_39$$27, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&columnName, &field, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 286 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_31$$3);
		object_init_ex(&_31$$3, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, &_31$$3, "__construct", &_41, 151, &columnName, &definition);
		zephir_check_call_status();
		zephir_array_append(&columns, &_31$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 287);
		ZEPHIR_CPY_WRT(&oldColumn, &columnName);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&field);
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

	zend_string *_24;
	zend_ulong _23;
	zephir_fcall_cache_entry *_15 = NULL, *_28 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table, table_sub, *schema = NULL, schema_sub, __$null, indexes, index, keyName, indexObjects, name, columns, describeIndex, indexSql, _0, _1, _2, _3, *_4, *_22, _5$$4, _6$$3, _8$$3, _9$$3, _10$$3, _11$$3, *_12$$3, _14$$3, _16$$3, _7$$6, _13$$7, _17$$8, _18$$8, _19$$8, _20$$9, _21$$10, _25$$12, _26$$12, _27$$12;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&schema_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&indexObjects);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&describeIndex);
	ZVAL_UNDEF(&indexSql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$12);
	ZVAL_UNDEF(&_27$$12);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &schema);

	if (!schema) {
		schema = &schema_sub;
		schema = &__$null;
	}


	ZEPHIR_INIT_VAR(&indexes);
	array_init(&indexes);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeindexes", NULL, 0, table, schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 341);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_COPY(&index, _4);
		ZEPHIR_OBS_NVAR(&keyName);
		zephir_array_fetch_string(&keyName, &index, SL("name"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 311 TSRMLS_CC);
		if (!(zephir_array_isset(&indexes, &keyName))) {
			ZEPHIR_INIT_NVAR(&_5$$4);
			array_init(&_5$$4);
			zephir_array_update_zval(&indexes, &keyName, &_5$$4, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch(&_6$$3, &indexes, &keyName, PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 317 TSRMLS_CC);
		if (!(zephir_array_isset_string(&_6$$3, SL("columns")))) {
			ZEPHIR_INIT_NVAR(&columns);
			array_init(&columns);
		} else {
			zephir_array_fetch(&_7$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 320 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&columns);
			zephir_array_fetch_string(&columns, &_7$$6, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 320 TSRMLS_CC);
		}
		zephir_read_property(&_9$$3, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_10$$3, &_9$$3, "describeindex", NULL, 0, &keyName);
		zephir_check_call_status();
		ZVAL_LONG(&_11$$3, 2);
		ZEPHIR_CALL_METHOD(&_8$$3, this_ptr, "fetchall", NULL, 0, &_10$$3, &_11$$3);
		zephir_check_call_status();
		zephir_is_iterable(&_8$$3, 0, "phalcon/db/adapter/pdo/sqlite.zep", 327);
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_8$$3), _12$$3)
		{
			ZEPHIR_INIT_NVAR(&describeIndex);
			ZVAL_COPY(&describeIndex, _12$$3);
			zephir_array_fetch_string(&_13$$7, &describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 324 TSRMLS_CC);
			zephir_array_append(&columns, &_13$$7, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 324);
		} ZEND_HASH_FOREACH_END();
		ZEPHIR_INIT_NVAR(&describeIndex);
		zephir_array_update_multi(&indexes, &columns TSRMLS_CC, SL("zs"), 3, &keyName, SL("columns"));
		zephir_read_property(&_11$$3, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(&_14$$3, &_11$$3, "listindexessql", NULL, 0, table, schema, &keyName);
		zephir_check_call_status();
		ZEPHIR_CALL_METHOD(&indexSql, this_ptr, "fetchcolumn", &_15, 0, &_14$$3);
		zephir_check_call_status();
		zephir_array_fetch_string(&_16$$3, &index, SL("unique"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 330 TSRMLS_CC);
		if (zephir_is_true(&_16$$3)) {
			ZEPHIR_INIT_NVAR(&_17$$8);
			ZEPHIR_INIT_NVAR(&_18$$8);
			ZEPHIR_INIT_NVAR(&_19$$8);
			ZVAL_STRING(&_19$$8, "# UNIQUE #i");
			zephir_preg_match(&_18$$8, &_19$$8, &indexSql, &_17$$8, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(&_18$$8)) {
				ZEPHIR_INIT_NVAR(&_20$$9);
				ZVAL_STRING(&_20$$9, "UNIQUE");
				zephir_array_update_multi(&indexes, &_20$$9 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
			} else {
				ZEPHIR_INIT_NVAR(&_21$$10);
				ZVAL_STRING(&_21$$10, "PRIMARY");
				zephir_array_update_multi(&indexes, &_21$$10 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
			}
		} else {
			zephir_array_update_multi(&indexes, &__$null TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	zephir_is_iterable(&indexes, 0, "phalcon/db/adapter/pdo/sqlite.zep", 346);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&indexes), _23, _24, _22)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_24 != NULL) { 
			ZVAL_STR_COPY(&name, _24);
		} else {
			ZVAL_LONG(&name, _23);
		}
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_COPY(&index, _22);
		ZEPHIR_INIT_NVAR(&_25$$12);
		object_init_ex(&_25$$12, phalcon_db_index_ce);
		zephir_array_fetch_string(&_26$$12, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 343 TSRMLS_CC);
		zephir_array_fetch_string(&_27$$12, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 343 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_25$$12, "__construct", &_28, 19, &name, &_26$$12, &_27$$12);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, &name, &_25$$12, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_NVAR(&name);
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

	zval _13$$3, _18$$6;
	zend_string *_6, *_16;
	zend_ulong _5, _15;
	zephir_fcall_cache_entry *_20 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table, table_sub, *schema = NULL, schema_sub, __$null, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, number, _0, _1, _2, _3, *_4, *_14, _7$$5, _8$$5, _9$$5, _10$$5, _11$$3, _12$$3, _17$$6, _19$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table_sub);
	ZVAL_UNDEF(&schema_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&references);
	ZVAL_UNDEF(&reference);
	ZVAL_UNDEF(&arrayReference);
	ZVAL_UNDEF(&constraintName);
	ZVAL_UNDEF(&referenceObjects);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&referencedSchema);
	ZVAL_UNDEF(&referencedTable);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&referencedColumns);
	ZVAL_UNDEF(&number);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_18$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table, &schema);

	if (!schema) {
		schema = &schema_sub;
		schema = &__$null;
	}


	ZEPHIR_INIT_VAR(&references);
	array_init(&references);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describereferences", NULL, 0, table, schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 391);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _5, _6, _4)
	{
		ZEPHIR_INIT_NVAR(&number);
		if (_6 != NULL) { 
			ZVAL_STR_COPY(&number, _6);
		} else {
			ZVAL_LONG(&number, _5);
		}
		ZEPHIR_INIT_NVAR(&reference);
		ZVAL_COPY(&reference, _4);
		ZEPHIR_INIT_NVAR(&constraintName);
		ZEPHIR_CONCAT_SV(&constraintName, "foreign_key_", &number);
		if (!(zephir_array_isset(&references, &constraintName))) {
			ZEPHIR_INIT_NVAR(&referencedSchema);
			ZVAL_NULL(&referencedSchema);
			ZEPHIR_OBS_NVAR(&referencedTable);
			zephir_array_fetch_long(&referencedTable, &reference, 2, PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 370 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&columns);
			array_init(&columns);
			ZEPHIR_INIT_NVAR(&referencedColumns);
			array_init(&referencedColumns);
		} else {
			zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 374 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedSchema);
			zephir_array_fetch_string(&referencedSchema, &_7$$5, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 374 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 375 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedTable);
			zephir_array_fetch_string(&referencedTable, &_8$$5, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 375 TSRMLS_CC);
			zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 376 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&columns);
			zephir_array_fetch_string(&columns, &_9$$5, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 376 TSRMLS_CC);
			zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 377 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedColumns);
			zephir_array_fetch_string(&referencedColumns, &_10$$5, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 377 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_11$$3, &reference, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 380 TSRMLS_CC);
		zephir_array_append(&columns, &_11$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 380);
		zephir_array_fetch_long(&_12$$3, &reference, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 381 TSRMLS_CC);
		zephir_array_append(&referencedColumns, &_12$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 381);
		ZEPHIR_INIT_NVAR(&_13$$3);
		zephir_create_array(&_13$$3, 4, 0 TSRMLS_CC);
		zephir_array_update_string(&_13$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
		zephir_array_update_zval(&references, &constraintName, &_13$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&reference);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_INIT_VAR(&referenceObjects);
	array_init(&referenceObjects);
	zephir_is_iterable(&references, 0, "phalcon/db/adapter/pdo/sqlite.zep", 401);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&references), _15, _16, _14)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_16 != NULL) { 
			ZVAL_STR_COPY(&name, _16);
		} else {
			ZVAL_LONG(&name, _15);
		}
		ZEPHIR_INIT_NVAR(&arrayReference);
		ZVAL_COPY(&arrayReference, _14);
		ZEPHIR_INIT_NVAR(&_17$$6);
		object_init_ex(&_17$$6, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(&_18$$6);
		zephir_create_array(&_18$$6, 4, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 394 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedSchema"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 395 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedTable"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 396 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("columns"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 398 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedColumns"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_17$$6, "__construct", &_20, 20, &name, &_18$$6);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_17$$6, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(referenceObjects);

}

/**
 * Check whether the database system requires an explicit value for identity columns
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, useExplicitIdValue) {

	ZEPHIR_INIT_THIS();


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

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "NULL");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 21, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

