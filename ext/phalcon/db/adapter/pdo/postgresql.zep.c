
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

	zend_bool _1$$6;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_3 = NULL;
	zval *descriptor = NULL, descriptor_sub, __$null, schema, sql, _0$$6, _2$$6;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&descriptor_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_0$$6);
	ZVAL_UNDEF(&_2$$6);

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
	ZEPHIR_OBS_VAR(&schema);
	if (zephir_array_isset_string_fetch(&schema, descriptor, SL("schema"), 0)) {
		zephir_array_unset_string(descriptor, SL("schema"), PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(&schema);
		ZVAL_STRING(&schema, "");
	}
	if (zephir_array_isset_string(descriptor, SL("password"))) {
		ZEPHIR_OBS_VAR(&_0$$6);
		zephir_array_fetch_string(&_0$$6, descriptor, SL("password"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 75 TSRMLS_CC);
		_1$$6 = Z_TYPE_P(&_0$$6) == IS_STRING;
		if (_1$$6) {
			zephir_array_fetch_string(&_2$$6, descriptor, SL("password"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 75 TSRMLS_CC);
			_1$$6 = zephir_fast_strlen_ev(&_2$$6) == 0;
		}
		if (_1$$6) {
			zephir_array_update_string(descriptor, SL("password"), &__$null, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_postgresql_ce, this_ptr, "connect", &_3, 152, descriptor);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&schema))) {
		ZEPHIR_INIT_VAR(&sql);
		ZEPHIR_CONCAT_SVS(&sql, "SET search_path TO '", &schema, "'");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, &sql);
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

	zephir_fcall_cache_entry *_39 = NULL, *_42 = NULL, *_44 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$true, __$null, columns, columnType, field, definition, oldColumn, columnName, charSize, numericSize, numericScale, _0, _1, _2, _3, *_4, _5$$5, _6$$5, _7$$6, _8$$6, _9$$7, _10$$7, _11$$8, _12$$9, _13$$9, _14$$10, _15$$11, _16$$11, _17$$12, _18$$13, _19$$13, _20$$14, _21$$15, _22$$15, _23$$16, _24$$16, _25$$16, _26$$17, _27$$18, _28$$19, _29$$19, _30$$4, _31$$3, _32$$3, _33$$3, _34$$3, _43$$3, _35$$26, _36$$26, _37$$26, _38$$26, _40$$26, _41$$26;
	zval table, schema;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&oldColumn);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&charSize);
	ZVAL_UNDEF(&numericSize);
	ZVAL_UNDEF(&numericScale);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$13);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$4);
	ZVAL_UNDEF(&_31$$3);
	ZVAL_UNDEF(&_32$$3);
	ZVAL_UNDEF(&_33$$3);
	ZVAL_UNDEF(&_34$$3);
	ZVAL_UNDEF(&_43$$3);
	ZVAL_UNDEF(&_35$$26);
	ZVAL_UNDEF(&_36$$26);
	ZVAL_UNDEF(&_37$$26);
	ZVAL_UNDEF(&_38$$26);
	ZVAL_UNDEF(&_40$$26);
	ZVAL_UNDEF(&_41$$26);

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
	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describecolumns", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 326);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&field);
		ZVAL_COPY(&field, _4);
		ZEPHIR_INIT_NVAR(&definition);
		zephir_create_array(&definition, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(&definition, SL("bindType"), 2);
		ZEPHIR_OBS_NVAR(&columnType);
		zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 116 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&charSize);
		zephir_array_fetch_long(&charSize, &field, 2, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 117 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&numericSize);
		zephir_array_fetch_long(&numericSize, &field, 3, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 118 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&numericScale);
		zephir_array_fetch_long(&numericScale, &field, 4, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 119 TSRMLS_CC);
		while (1) {
			if (zephir_memnstr_str(&columnType, SL("smallint(1)"), "phalcon/db/adapter/pdo/postgresql.zep", 126)) {
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_LONG(&_5$$5, 8);
				zephir_array_update_string(&definition, SL("type"), &_5$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_6$$5);
				ZVAL_LONG(&_6$$5, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_6$$5, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/db/adapter/pdo/postgresql.zep", 135)) {
				ZEPHIR_INIT_NVAR(&_7$$6);
				ZVAL_LONG(&_7$$6, 14);
				zephir_array_update_string(&definition, SL("type"), &_7$$6, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_8$$6);
				ZVAL_LONG(&_8$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_8$$6, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("int"), "phalcon/db/adapter/pdo/postgresql.zep", 145)) {
				ZEPHIR_INIT_NVAR(&_9$$7);
				ZVAL_LONG(&_9$$7, 0);
				zephir_array_update_string(&definition, SL("type"), &_9$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_10$$7);
				ZVAL_LONG(&_10$$7, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_10$$7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("varying"), "phalcon/db/adapter/pdo/postgresql.zep", 156)) {
				ZEPHIR_INIT_NVAR(&_11$$8);
				ZVAL_LONG(&_11$$8, 2);
				zephir_array_update_string(&definition, SL("type"), &_11$$8, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("date"), "phalcon/db/adapter/pdo/postgresql.zep", 165)) {
				ZEPHIR_INIT_NVAR(&_12$$9);
				ZVAL_LONG(&_12$$9, 1);
				zephir_array_update_string(&definition, SL("type"), &_12$$9, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_13$$9);
				ZVAL_LONG(&_13$$9, 0);
				zephir_array_update_string(&definition, SL("size"), &_13$$9, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/db/adapter/pdo/postgresql.zep", 174)) {
				ZEPHIR_INIT_NVAR(&_14$$10);
				ZVAL_LONG(&_14$$10, 17);
				zephir_array_update_string(&definition, SL("type"), &_14$$10, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("numeric"), "phalcon/db/adapter/pdo/postgresql.zep", 182)) {
				ZEPHIR_INIT_NVAR(&_15$$11);
				ZVAL_LONG(&_15$$11, 3);
				zephir_array_update_string(&definition, SL("type"), &_15$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("scale"), &numericScale, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_16$$11);
				ZVAL_LONG(&_16$$11, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_16$$11, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("char"), "phalcon/db/adapter/pdo/postgresql.zep", 194)) {
				ZEPHIR_INIT_NVAR(&_17$$12);
				ZVAL_LONG(&_17$$12, 5);
				zephir_array_update_string(&definition, SL("type"), &_17$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/db/adapter/pdo/postgresql.zep", 203)) {
				ZEPHIR_INIT_NVAR(&_18$$13);
				ZVAL_LONG(&_18$$13, 4);
				zephir_array_update_string(&definition, SL("type"), &_18$$13, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_19$$13);
				ZVAL_LONG(&_19$$13, 0);
				zephir_array_update_string(&definition, SL("size"), &_19$$13, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("text"), "phalcon/db/adapter/pdo/postgresql.zep", 212)) {
				ZEPHIR_INIT_NVAR(&_20$$14);
				ZVAL_LONG(&_20$$14, 6);
				zephir_array_update_string(&definition, SL("type"), &_20$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("float"), "phalcon/db/adapter/pdo/postgresql.zep", 221)) {
				ZEPHIR_INIT_NVAR(&_21$$15);
				ZVAL_LONG(&_21$$15, 7);
				zephir_array_update_string(&definition, SL("type"), &_21$$15, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_22$$15);
				ZVAL_LONG(&_22$$15, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_22$$15, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("bool"), "phalcon/db/adapter/pdo/postgresql.zep", 232)) {
				ZEPHIR_INIT_NVAR(&_23$$16);
				ZVAL_LONG(&_23$$16, 8);
				zephir_array_update_string(&definition, SL("type"), &_23$$16, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_24$$16);
				ZVAL_LONG(&_24$$16, 0);
				zephir_array_update_string(&definition, SL("size"), &_24$$16, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_25$$16);
				ZVAL_LONG(&_25$$16, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_25$$16, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("jsonb"), "phalcon/db/adapter/pdo/postgresql.zep", 242)) {
				ZEPHIR_INIT_NVAR(&_26$$17);
				ZVAL_LONG(&_26$$17, 16);
				zephir_array_update_string(&definition, SL("type"), &_26$$17, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("json"), "phalcon/db/adapter/pdo/postgresql.zep", 250)) {
				ZEPHIR_INIT_NVAR(&_27$$18);
				ZVAL_LONG(&_27$$18, 15);
				zephir_array_update_string(&definition, SL("type"), &_27$$18, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("uuid"), "phalcon/db/adapter/pdo/postgresql.zep", 258)) {
				ZEPHIR_INIT_NVAR(&_28$$19);
				ZVAL_LONG(&_28$$19, 5);
				zephir_array_update_string(&definition, SL("type"), &_28$$19, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_29$$19);
				ZVAL_LONG(&_29$$19, 36);
				zephir_array_update_string(&definition, SL("size"), &_29$$19, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(&_30$$4);
			ZVAL_LONG(&_30$$4, 2);
			zephir_array_update_string(&definition, SL("type"), &_30$$4, PH_COPY | PH_SEPARATE);
			break;
		}
		if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/db/adapter/pdo/postgresql.zep", 274)) {
			zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_31$$3, &field, 6, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 290 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_31$$3, "PRI")) {
			zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_32$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 297 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_32$$3, "NO")) {
			zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_33$$3, &field, 7, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 304 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_33$$3, "auto_increment")) {
			zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_NVAR(&_34$$3);
		zephir_array_fetch_long(&_34$$3, &field, 9, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 311 TSRMLS_CC);
		if (Z_TYPE_P(&_34$$3) != IS_NULL) {
			zephir_array_fetch_long(&_35$$26, &field, 9, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 312 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_36$$26);
			ZVAL_STRING(&_36$$26, "/^'|'?::[[:alnum:][:space:]]+$/");
			ZEPHIR_INIT_NVAR(&_37$$26);
			ZVAL_STRING(&_37$$26, "");
			ZEPHIR_CALL_FUNCTION(&_38$$26, "preg_replace", &_39, 29, &_36$$26, &_37$$26, &_35$$26);
			zephir_check_call_status();
			zephir_array_update_string(&definition, SL("default"), &_38$$26, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_40$$26, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 313 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_36$$26);
			ZVAL_STRING(&_36$$26, "null");
			ZEPHIR_CALL_FUNCTION(&_41$$26, "strcasecmp", &_42, 23, &_40$$26, &_36$$26);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(&_41$$26, 0)) {
				zephir_array_update_string(&definition, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
			}
		}
		zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 321 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_43$$3);
		object_init_ex(&_43$$3, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, &_43$$3, "__construct", &_44, 151, &columnName, &definition);
		zephir_check_call_status();
		zephir_array_append(&columns, &_43$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 322);
		ZEPHIR_CPY_WRT(&oldColumn, &columnName);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&field);
	RETURN_CCTOR(columns);

}

/**
 * Creates a table
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, createTable) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, sql, queries, query, exception, columns, _0, *_1$$6, _2$$7, _4$$10, _5$$10;
	zval tableName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&queries);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_4$$10);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	ZEPHIR_OBS_VAR_ONCE(&definition);
	ZVAL_COPY(&definition, definition_param);


	ZEPHIR_OBS_VAR(&columns);
	if (!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter/pdo/postgresql.zep", 337);
		return;
	}
	if (!(zephir_fast_count_int(&columns TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter/pdo/postgresql.zep", 341);
		return;
	}
	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&sql, &_0, "createtable", NULL, 0, &tableName, &schemaName, &definition);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&queries);
	zephir_fast_explode_str(&queries, SL(";"), &sql, LONG_MAX TSRMLS_CC);
	if (zephir_fast_count_int(&queries TSRMLS_CC) > 1) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(NULL, this_ptr, "begin", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_is_iterable(&queries, 0, "phalcon/db/adapter/pdo/postgresql.zep", 357);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queries), _1$$6)
			{
				ZEPHIR_INIT_NVAR(&query);
				ZVAL_COPY(&query, _1$$6);
				if (ZEPHIR_IS_EMPTY(&query)) {
					continue;
				}
				ZEPHIR_INIT_LNVAR(_2$$7);
				ZEPHIR_CONCAT_VS(&_2$$7, &query, ";");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_3, 0, &_2$$7);
				zephir_check_call_status_or_jump(try_end_1);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&query);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "commit", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZVAL_OBJ(&exception, EG(exception));
			Z_ADDREF_P(&exception);
			if (zephir_instance_of_ev(&exception, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/db/adapter/pdo/postgresql.zep", 361 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		zephir_array_fetch_long(&_4$$10, &queries, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 364 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_5$$10);
		ZEPHIR_CONCAT_VS(&_5$$10, &_4$$10, ";");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_5$$10);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Modifies a table column based on a definition
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, modifyColumn) {

	zephir_fcall_cache_entry *_3 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, sql, queries, query, exception, _0, *_1$$4, _2$$5, _4$$8, _5$$8, _6$$8;
	zval tableName, schemaName;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&currentColumn_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&queries);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$8);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &tableName_param, &schemaName_param, &column, &currentColumn);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	if (!currentColumn) {
		currentColumn = &currentColumn_sub;
		currentColumn = &__$null;
	}


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&sql, &_0, "modifycolumn", NULL, 0, &tableName, &schemaName, column, currentColumn);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&queries);
	zephir_fast_explode_str(&queries, SL(";"), &sql, LONG_MAX TSRMLS_CC);
	if (zephir_fast_count_int(&queries TSRMLS_CC) > 1) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(NULL, this_ptr, "begin", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_is_iterable(&queries, 0, "phalcon/db/adapter/pdo/postgresql.zep", 389);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queries), _1$$4)
			{
				ZEPHIR_INIT_NVAR(&query);
				ZVAL_COPY(&query, _1$$4);
				if (ZEPHIR_IS_EMPTY(&query)) {
					continue;
				}
				ZEPHIR_INIT_LNVAR(_2$$5);
				ZEPHIR_CONCAT_VS(&_2$$5, &query, ";");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_3, 0, &_2$$5);
				zephir_check_call_status_or_jump(try_end_1);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&query);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "commit", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZVAL_OBJ(&exception, EG(exception));
			Z_ADDREF_P(&exception);
			if (zephir_instance_of_ev(&exception, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/db/adapter/pdo/postgresql.zep", 394 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		ZEPHIR_INIT_VAR(&_4$$8);
		if (!(ZEPHIR_IS_EMPTY(&sql))) {
			zephir_array_fetch_long(&_5$$8, &queries, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 398 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_6$$8);
			ZEPHIR_CONCAT_VS(&_6$$8, &_5$$8, ";");
			ZEPHIR_CALL_METHOD(&_4$$8, this_ptr, "execute", NULL, 0, &_6$$8);
			zephir_check_call_status();
		} else {
			ZVAL_BOOL(&_4$$8, 1);
		}
		RETURN_CCTOR(_4$$8);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Check whether the database system requires an explicit value for identity columns
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, useExplicitIdValue) {

	ZEPHIR_INIT_THIS();


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

	zval _0;
	int ZEPHIR_LAST_CALL_STATUS;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DEFAULT");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 21, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences) {

	ZEPHIR_INIT_THIS();


	RETURN_BOOL(1);

}

