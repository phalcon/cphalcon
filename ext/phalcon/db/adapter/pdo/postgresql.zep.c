
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
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Db\Adapter\Pdo\Postgresql
 *
 * Specific functions for the Postgresql database system
 *
 * <code>
 * use Phalcon\Db\Adapter\Pdo\Postgresql;
 *
 * $config = [
 *     "host"     => "localhost",
 *     "dbname"   => "blog",
 *     "port"     => 5432,
 *     "username" => "postgres",
 *     "password" => "secret",
 * ];
 *
 * $connection = new Postgresql($config);
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Postgresql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Postgresql, phalcon, db_adapter_pdo_postgresql, phalcon_db_adapter_pdo_ce, phalcon_db_adapter_pdo_postgresql_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("_dialectType"), "postgresql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("_type"), "pgsql", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, connect) {

	zend_bool _3$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *descriptor_param = NULL, __$null, schema, sql, status, _0$$3, _2$$6, _4$$6;
	zval descriptor, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_4$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &descriptor_param);

	if (!descriptor_param) {
		ZEPHIR_INIT_VAR(&descriptor);
		array_init(&descriptor);
	} else {
		zephir_get_arrval(&descriptor, descriptor_param);
	}


	if (ZEPHIR_IS_EMPTY(&descriptor)) {
		ZEPHIR_OBS_VAR(&_0$$3);
		zephir_read_property(&_0$$3, this_ptr, SL("_descriptor"), PH_NOISY_CC);
		zephir_get_arrval(&_1$$3, &_0$$3);
		ZEPHIR_CPY_WRT(&descriptor, &_1$$3);
	}
	ZEPHIR_OBS_VAR(&schema);
	if (zephir_array_isset_string_fetch(&schema, &descriptor, SL("schema"), 0)) {
		zephir_array_unset_string(&descriptor, SL("schema"), PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(&schema);
		ZVAL_STRING(&schema, "");
	}
	if (zephir_array_isset_string(&descriptor, SL("password"))) {
		ZEPHIR_OBS_VAR(&_2$$6);
		zephir_array_fetch_string(&_2$$6, &descriptor, SL("password"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 67 TSRMLS_CC);
		_3$$6 = Z_TYPE_P(&_2$$6) == IS_STRING;
		if (_3$$6) {
			zephir_array_fetch_string(&_4$$6, &descriptor, SL("password"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 67 TSRMLS_CC);
			_3$$6 = zephir_fast_strlen_ev(&_4$$6) == 0;
		}
		if (_3$$6) {
			zephir_array_update_string(&descriptor, SL("password"), &__$null, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_PARENT(&status, phalcon_db_adapter_pdo_postgresql_ce, getThis(), "connect", &_5, 0, &descriptor);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&schema))) {
		ZEPHIR_INIT_VAR(&sql);
		ZEPHIR_CONCAT_SVS(&sql, "SET search_path TO '", &schema, "'");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, &sql);
		zephir_check_call_status();
	}
	RETURN_CCTOR(&status);

}

/**
 * Creates a table
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, createTable) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, sql, queries, query, exception, columns, _0, *_1$$6, _2$$7, _4$$5, _5$$10, _6$$10;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&queries);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$7);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$10);
	ZVAL_UNDEF(&_6$$10);
	ZVAL_UNDEF(&definition);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(&schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(&schemaName);
		ZVAL_EMPTY_STRING(&schemaName);
	}
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);


	ZEPHIR_OBS_VAR(&columns);
	if (!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter/pdo/postgresql.zep", 90);
		return;
	}
	if (!(zephir_fast_count_int(&columns TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter/pdo/postgresql.zep", 94);
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
			zephir_is_iterable(&queries, 0, "phalcon/db/adapter/pdo/postgresql.zep", 110);
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
			ZEPHIR_INIT_VAR(&_4$$5);
			ZVAL_OBJ(&_4$$5, EG(exception));
			Z_ADDREF_P(&_4$$5);
			if (zephir_is_instance_of(&_4$$5, SL("Throwable") TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&exception, &_4$$5);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/db/adapter/pdo/postgresql.zep", 114 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		zephir_array_fetch_long(&_5$$10, &queries, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 117 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_6$$10);
		ZEPHIR_CONCAT_VS(&_6$$10, &_5$$10, ";");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_6$$10);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 *
 * <code>
 * print_r(
 *     $connection->describeColumns("posts")
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns) {

	zend_bool _5$$3;
	zephir_fcall_cache_entry *_55 = NULL, *_58 = NULL, *_60 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$true, __$null, columns, columnType, field, definition, oldColumn, columnName, charSize, numericSize, numericScale, _0, _1, _2, _3, *_4, _47$$3, _48$$3, _49$$3, _50$$3, _59$$3, _6$$4, _7$$4, _8$$5, _9$$5, _10$$6, _11$$6, _12$$7, _13$$7, _14$$8, _15$$8, _16$$9, _17$$9, _18$$10, _19$$11, _20$$12, _21$$12, _22$$13, _23$$13, _24$$14, _25$$14, _26$$15, _27$$15, _28$$16, _29$$16, _30$$17, _31$$18, _32$$19, _33$$20, _34$$21, _35$$22, _36$$23, _37$$24, _38$$25, _39$$26, _40$$27, _41$$28, _42$$29, _43$$30, _44$$31, _45$$31, _46$$32, _51$$38, _52$$38, _53$$38, _54$$38, _56$$38, _57$$38;
	zval table, schema;
	zval *this_ptr = getThis();

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
	ZVAL_UNDEF(&_47$$3);
	ZVAL_UNDEF(&_48$$3);
	ZVAL_UNDEF(&_49$$3);
	ZVAL_UNDEF(&_50$$3);
	ZVAL_UNDEF(&_59$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$10);
	ZVAL_UNDEF(&_19$$11);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_30$$17);
	ZVAL_UNDEF(&_31$$18);
	ZVAL_UNDEF(&_32$$19);
	ZVAL_UNDEF(&_33$$20);
	ZVAL_UNDEF(&_34$$21);
	ZVAL_UNDEF(&_35$$22);
	ZVAL_UNDEF(&_36$$23);
	ZVAL_UNDEF(&_37$$24);
	ZVAL_UNDEF(&_38$$25);
	ZVAL_UNDEF(&_39$$26);
	ZVAL_UNDEF(&_40$$27);
	ZVAL_UNDEF(&_41$$28);
	ZVAL_UNDEF(&_42$$29);
	ZVAL_UNDEF(&_43$$30);
	ZVAL_UNDEF(&_44$$31);
	ZVAL_UNDEF(&_45$$31);
	ZVAL_UNDEF(&_46$$32);
	ZVAL_UNDEF(&_51$$38);
	ZVAL_UNDEF(&_52$$38);
	ZVAL_UNDEF(&_53$$38);
	ZVAL_UNDEF(&_54$$38);
	ZVAL_UNDEF(&_56$$38);
	ZVAL_UNDEF(&_57$$38);

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
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 460);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&field);
		ZVAL_COPY(&field, _4);
		ZEPHIR_INIT_NVAR(&definition);
		zephir_create_array(&definition, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(&definition, SL("bindType"), 2);
		ZEPHIR_OBS_NVAR(&columnType);
		zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 152 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&charSize);
		zephir_array_fetch_long(&charSize, &field, 2, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 153 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&numericSize);
		zephir_array_fetch_long(&numericSize, &field, 3, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 154 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&numericScale);
		zephir_array_fetch_long(&numericScale, &field, 4, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 155 TSRMLS_CC);
		do {
			_5$$3 = 1;
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("boolean"), "phalcon/db/adapter/pdo/postgresql.zep", 172)) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZVAL_LONG(&_6$$4, 8);
				zephir_array_update_string(&definition, SL("type"), &_6$$4, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZVAL_LONG(&_7$$4, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_7$$4, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/db/adapter/pdo/postgresql.zep", 184)) {
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZVAL_LONG(&_8$$5, 14);
				zephir_array_update_string(&definition, SL("type"), &_8$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_LONG(&_9$$5, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_9$$5, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("mediumint"), "phalcon/db/adapter/pdo/postgresql.zep", 193)) {
				ZEPHIR_INIT_NVAR(&_10$$6);
				ZVAL_LONG(&_10$$6, 21);
				zephir_array_update_string(&definition, SL("type"), &_10$$6, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZVAL_LONG(&_11$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_11$$6, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("smallint"), "phalcon/db/adapter/pdo/postgresql.zep", 202)) {
				ZEPHIR_INIT_NVAR(&_12$$7);
				ZVAL_LONG(&_12$$7, 22);
				zephir_array_update_string(&definition, SL("type"), &_12$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZVAL_LONG(&_13$$7, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_13$$7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinyint"), "phalcon/db/adapter/pdo/postgresql.zep", 211)) {
				ZEPHIR_INIT_NVAR(&_14$$8);
				ZVAL_LONG(&_14$$8, 26);
				zephir_array_update_string(&definition, SL("type"), &_14$$8, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_15$$8);
				ZVAL_LONG(&_15$$8, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_15$$8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("int"), "phalcon/db/adapter/pdo/postgresql.zep", 223)) {
				ZEPHIR_INIT_NVAR(&_16$$9);
				ZVAL_LONG(&_16$$9, 0);
				zephir_array_update_string(&definition, SL("type"), &_16$$9, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_17$$9);
				ZVAL_LONG(&_17$$9, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_17$$9, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("bit"), "phalcon/db/adapter/pdo/postgresql.zep", 233)) {
				ZEPHIR_INIT_NVAR(&_18$$10);
				ZVAL_LONG(&_18$$10, 19);
				zephir_array_update_string(&definition, SL("type"), &_18$$10, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("enum"), "phalcon/db/adapter/pdo/postgresql.zep", 241)) {
				ZEPHIR_INIT_NVAR(&_19$$11);
				ZVAL_LONG(&_19$$11, 18);
				zephir_array_update_string(&definition, SL("type"), &_19$$11, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/db/adapter/pdo/postgresql.zep", 249)) {
				ZEPHIR_INIT_NVAR(&_20$$12);
				ZVAL_LONG(&_20$$12, 4);
				zephir_array_update_string(&definition, SL("type"), &_20$$12, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_21$$12);
				ZVAL_LONG(&_21$$12, 0);
				zephir_array_update_string(&definition, SL("size"), &_21$$12, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("date"), "phalcon/db/adapter/pdo/postgresql.zep", 257)) {
				ZEPHIR_INIT_NVAR(&_22$$13);
				ZVAL_LONG(&_22$$13, 1);
				zephir_array_update_string(&definition, SL("type"), &_22$$13, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_23$$13);
				ZVAL_LONG(&_23$$13, 0);
				zephir_array_update_string(&definition, SL("size"), &_23$$13, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/db/adapter/pdo/postgresql.zep", 266) || _5$$3 == zephir_memnstr_str(&columnType, SL("numeric"), "phalcon/db/adapter/pdo/postgresql.zep", 267)) {
				ZEPHIR_INIT_NVAR(&_24$$14);
				ZVAL_LONG(&_24$$14, 3);
				zephir_array_update_string(&definition, SL("type"), &_24$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_25$$14);
				ZVAL_LONG(&_25$$14, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_25$$14, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("double precision"), "phalcon/db/adapter/pdo/postgresql.zep", 277)) {
				ZEPHIR_INIT_NVAR(&_26$$15);
				ZVAL_LONG(&_26$$15, 9);
				zephir_array_update_string(&definition, SL("type"), &_26$$15, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_27$$15);
				ZVAL_LONG(&_27$$15, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_27$$15, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("float"), "phalcon/db/adapter/pdo/postgresql.zep", 287) || _5$$3 == zephir_memnstr_str(&columnType, SL("real"), "phalcon/db/adapter/pdo/postgresql.zep", 288)) {
				ZEPHIR_INIT_NVAR(&_28$$16);
				ZVAL_LONG(&_28$$16, 7);
				zephir_array_update_string(&definition, SL("type"), &_28$$16, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_29$$16);
				ZVAL_LONG(&_29$$16, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_29$$16, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/db/adapter/pdo/postgresql.zep", 298)) {
				ZEPHIR_INIT_NVAR(&_30$$17);
				ZVAL_LONG(&_30$$17, 6);
				zephir_array_update_string(&definition, SL("type"), &_30$$17, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/db/adapter/pdo/postgresql.zep", 305)) {
				ZEPHIR_INIT_NVAR(&_31$$18);
				ZVAL_LONG(&_31$$18, 13);
				zephir_array_update_string(&definition, SL("type"), &_31$$18, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/db/adapter/pdo/postgresql.zep", 312)) {
				ZEPHIR_INIT_NVAR(&_32$$19);
				ZVAL_LONG(&_32$$19, 10);
				zephir_array_update_string(&definition, SL("type"), &_32$$19, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("blob"), "phalcon/db/adapter/pdo/postgresql.zep", 319)) {
				ZEPHIR_INIT_NVAR(&_33$$20);
				ZVAL_LONG(&_33$$20, 11);
				zephir_array_update_string(&definition, SL("type"), &_33$$20, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/db/adapter/pdo/postgresql.zep", 326)) {
				ZEPHIR_INIT_NVAR(&_34$$21);
				ZVAL_LONG(&_34$$21, 17);
				zephir_array_update_string(&definition, SL("type"), &_34$$21, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("time"), "phalcon/db/adapter/pdo/postgresql.zep", 333)) {
				ZEPHIR_INIT_NVAR(&_35$$22);
				ZVAL_LONG(&_35$$22, 20);
				zephir_array_update_string(&definition, SL("type"), &_35$$22, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("jsonb"), "phalcon/db/adapter/pdo/postgresql.zep", 340)) {
				ZEPHIR_INIT_NVAR(&_36$$23);
				ZVAL_LONG(&_36$$23, 16);
				zephir_array_update_string(&definition, SL("type"), &_36$$23, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("json"), "phalcon/db/adapter/pdo/postgresql.zep", 347)) {
				ZEPHIR_INIT_NVAR(&_37$$24);
				ZVAL_LONG(&_37$$24, 15);
				zephir_array_update_string(&definition, SL("type"), &_37$$24, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("longtext"), "phalcon/db/adapter/pdo/postgresql.zep", 354)) {
				ZEPHIR_INIT_NVAR(&_38$$25);
				ZVAL_LONG(&_38$$25, 24);
				zephir_array_update_string(&definition, SL("type"), &_38$$25, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("mediumtext"), "phalcon/db/adapter/pdo/postgresql.zep", 361)) {
				ZEPHIR_INIT_NVAR(&_39$$26);
				ZVAL_LONG(&_39$$26, 23);
				zephir_array_update_string(&definition, SL("type"), &_39$$26, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinytext"), "phalcon/db/adapter/pdo/postgresql.zep", 368)) {
				ZEPHIR_INIT_NVAR(&_40$$27);
				ZVAL_LONG(&_40$$27, 25);
				zephir_array_update_string(&definition, SL("type"), &_40$$27, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("text"), "phalcon/db/adapter/pdo/postgresql.zep", 375)) {
				ZEPHIR_INIT_NVAR(&_41$$28);
				ZVAL_LONG(&_41$$28, 6);
				zephir_array_update_string(&definition, SL("type"), &_41$$28, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("varying"), "phalcon/db/adapter/pdo/postgresql.zep", 382) || _5$$3 == zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/db/adapter/pdo/postgresql.zep", 383)) {
				ZEPHIR_INIT_NVAR(&_42$$29);
				ZVAL_LONG(&_42$$29, 2);
				zephir_array_update_string(&definition, SL("type"), &_42$$29, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("char"), "phalcon/db/adapter/pdo/postgresql.zep", 391)) {
				ZEPHIR_INIT_NVAR(&_43$$30);
				ZVAL_LONG(&_43$$30, 5);
				zephir_array_update_string(&definition, SL("type"), &_43$$30, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("uuid"), "phalcon/db/adapter/pdo/postgresql.zep", 399)) {
				ZEPHIR_INIT_NVAR(&_44$$31);
				ZVAL_LONG(&_44$$31, 5);
				zephir_array_update_string(&definition, SL("type"), &_44$$31, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_45$$31);
				ZVAL_LONG(&_45$$31, 36);
				zephir_array_update_string(&definition, SL("size"), &_45$$31, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(&_46$$32);
			ZVAL_LONG(&_46$$32, 2);
			zephir_array_update_string(&definition, SL("type"), &_46$$32, PH_COPY | PH_SEPARATE);
			break;
		} while(0);

		if (Z_TYPE_P(&oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_47$$3, &field, 6, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 424 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_47$$3, "PRI")) {
			zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_48$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 431 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_48$$3, "NO")) {
			zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_49$$3, &field, 7, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 438 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_49$$3, "auto_increment")) {
			zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_NVAR(&_50$$3);
		zephir_array_fetch_long(&_50$$3, &field, 9, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 445 TSRMLS_CC);
		if (Z_TYPE_P(&_50$$3) != IS_NULL) {
			zephir_array_fetch_long(&_51$$38, &field, 9, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 446 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_52$$38);
			ZVAL_STRING(&_52$$38, "/^'|'?::[[:alnum:][:space:]]+$/");
			ZEPHIR_INIT_NVAR(&_53$$38);
			ZVAL_STRING(&_53$$38, "");
			ZEPHIR_CALL_FUNCTION(&_54$$38, "preg_replace", &_55, 23, &_52$$38, &_53$$38, &_51$$38);
			zephir_check_call_status();
			zephir_array_update_string(&definition, SL("default"), &_54$$38, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_56$$38, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 447 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_52$$38);
			ZVAL_STRING(&_52$$38, "null");
			ZEPHIR_CALL_FUNCTION(&_57$$38, "strcasecmp", &_58, 19, &_56$$38, &_52$$38);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(&_57$$38, 0)) {
				zephir_array_update_string(&definition, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
			}
		}
		zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 455 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_59$$3);
		object_init_ex(&_59$$3, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, &_59$$3, "__construct", &_60, 159, &columnName, &definition);
		zephir_check_call_status();
		zephir_array_append(&columns, &_59$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 456);
		ZEPHIR_CPY_WRT(&oldColumn, &columnName);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&field);
	RETURN_CCTOR(&columns);

}

/**
 * Lists table references
 *
 *<code>
 * print_r(
 *     $connection->describeReferences("robots_parts")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeReferences) {

	zval _13$$3, _18$$6;
	zend_string *_16;
	zend_ulong _15;
	zephir_fcall_cache_entry *_20 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, referenceUpdate, referenceDelete, _0, _1, _2, _3, *_4, *_14, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$3, _12$$3, _17$$6, _19$$6;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
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
	ZVAL_UNDEF(&referenceUpdate);
	ZVAL_UNDEF(&referenceDelete);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
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
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
	if (UNEXPECTED(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schema_param) == IS_STRING)) {
		zephir_get_strval(&schema, schema_param);
	} else {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_EMPTY_STRING(&schema);
	}
	}


	ZEPHIR_INIT_VAR(&references);
	array_init(&references);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describereferences", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 514);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&reference);
		ZVAL_COPY(&reference, _4);
		zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 483 TSRMLS_CC);
		if (!(zephir_array_isset(&references, &constraintName))) {
			ZEPHIR_OBS_NVAR(&referencedSchema);
			zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 485 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedTable);
			zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 486 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referenceUpdate);
			zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 487 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referenceDelete);
			zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 488 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&columns);
			array_init(&columns);
			ZEPHIR_INIT_NVAR(&referencedColumns);
			array_init(&referencedColumns);
		} else {
			zephir_array_fetch(&_5$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 493 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedSchema);
			zephir_array_fetch_string(&referencedSchema, &_5$$5, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 493 TSRMLS_CC);
			zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 494 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedTable);
			zephir_array_fetch_string(&referencedTable, &_6$$5, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 494 TSRMLS_CC);
			zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 495 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&columns);
			zephir_array_fetch_string(&columns, &_7$$5, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 495 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 496 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedColumns);
			zephir_array_fetch_string(&referencedColumns, &_8$$5, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 496 TSRMLS_CC);
			zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 497 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referenceUpdate);
			zephir_array_fetch_string(&referenceUpdate, &_9$$5, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 497 TSRMLS_CC);
			zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 498 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referenceDelete);
			zephir_array_fetch_string(&referenceDelete, &_10$$5, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 498 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_11$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 501 TSRMLS_CC);
		zephir_array_append(&columns, &_11$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 501);
		zephir_array_fetch_long(&_12$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 502 TSRMLS_CC);
		zephir_array_append(&referencedColumns, &_12$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 502);
		ZEPHIR_INIT_NVAR(&_13$$3);
		zephir_create_array(&_13$$3, 6, 0 TSRMLS_CC);
		zephir_array_update_string(&_13$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("onUpdate"), &referenceUpdate, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("onDelete"), &referenceDelete, PH_COPY | PH_SEPARATE);
		zephir_array_update_zval(&references, &constraintName, &_13$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&reference);
	ZEPHIR_INIT_VAR(&referenceObjects);
	array_init(&referenceObjects);
	zephir_is_iterable(&references, 0, "phalcon/db/adapter/pdo/postgresql.zep", 526);
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
		zephir_create_array(&_18$$6, 6, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 517 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedSchema"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 518 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedTable"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 519 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("columns"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 520 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedColumns"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 521 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("onUpdate"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 523 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("onDelete"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_17$$6, "__construct", &_20, 16, &name, &_18$$6);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_17$$6, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&referenceObjects);

}

/**
 * Returns the default identity value to be inserted in an identity column
 *
 *<code>
 * // Inserting a new robot with a valid default value for the column 'id'
 * $success = $connection->insert(
 *     "robots",
 *     [
 *         $connection->getDefaultIdValue(),
 *         "Astro Boy",
 *         1952,
 *     ],
 *     [
 *         "id",
 *         "name",
 *         "year",
 *     ]
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DEFAULT");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 17, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Modifies a table column based on a definition
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, modifyColumn) {

	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, sql, queries, query, exception, _0, *_1$$4, _2$$5, _4$$3, _5$$8, _6$$8, _7$$8;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

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
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &tableName_param, &schemaName_param, &column, &currentColumn);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
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
			zephir_is_iterable(&queries, 0, "phalcon/db/adapter/pdo/postgresql.zep", 574);
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
			ZEPHIR_INIT_VAR(&_4$$3);
			ZVAL_OBJ(&_4$$3, EG(exception));
			Z_ADDREF_P(&_4$$3);
			if (zephir_is_instance_of(&_4$$3, SL("Throwable") TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&exception, &_4$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/db/adapter/pdo/postgresql.zep", 579 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		ZEPHIR_INIT_VAR(&_5$$8);
		if (!(ZEPHIR_IS_EMPTY(&sql))) {
			zephir_array_fetch_long(&_6$$8, &queries, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 583 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_7$$8);
			ZEPHIR_CONCAT_VS(&_7$$8, &_6$$8, ";");
			ZEPHIR_CALL_METHOD(&_5$$8, this_ptr, "execute", NULL, 0, &_7$$8);
			zephir_check_call_status();
		} else {
			ZVAL_BOOL(&_5$$8, 1);
		}
		RETURN_CCTOR(&_5$$8);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * Check whether the database system requires an explicit value for identity columns
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, useExplicitIdValue) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

