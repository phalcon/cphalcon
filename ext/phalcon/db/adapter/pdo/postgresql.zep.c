
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
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/string.h"
#include "kernel/concat.h"


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
 * Returns PDO adapter DSN defaults as a key-value map.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDsnDefaults) {

	zval *this_ptr = getThis();


	array_init(return_value);
	return;

}

/**
 * Constructor for Phalcon\Db\Adapter\Pdo\Postgresql
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, __construct) {

	zephir_fcall_cache_entry *_1 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, _0$$3;
	zval descriptor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&_0$$3);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &descriptor_param);

	ZEPHIR_OBS_COPY_OR_DUP(&descriptor, descriptor_param);


	if (zephir_array_isset_string(&descriptor, SL("charset"))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "Postgres does not allow the charset to be changed in the DSN.");
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_0$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_postgresql_ce, getThis(), "__construct", &_1, 0, &descriptor);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

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
		zephir_array_fetch_string(&_2$$6, &descriptor, SL("password"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 87 TSRMLS_CC);
		_3$$6 = Z_TYPE_P(&_2$$6) == IS_STRING;
		if (_3$$6) {
			zephir_array_fetch_string(&_4$$6, &descriptor, SL("password"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 87 TSRMLS_CC);
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

	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, sql, queries, query, exception, columns, _0, *_1$$6, _2$$6, _3$$7, _5$$9, _6$$5, _7$$12, _8$$12;
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
	ZVAL_UNDEF(&_2$$6);
	ZVAL_UNDEF(&_3$$7);
	ZVAL_UNDEF(&_5$$9);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$12);
	ZVAL_UNDEF(&_8$$12);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter/pdo/postgresql.zep", 110);
		return;
	}
	if (!(zephir_fast_count_int(&columns TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter/pdo/postgresql.zep", 114);
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
			zephir_is_iterable(&queries, 0, "phalcon/db/adapter/pdo/postgresql.zep", 130);
			if (Z_TYPE_P(&queries) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queries), _1$$6)
				{
					ZEPHIR_INIT_NVAR(&query);
					ZVAL_COPY(&query, _1$$6);
					if (ZEPHIR_IS_EMPTY(&query)) {
						continue;
					}
					ZEPHIR_INIT_LNVAR(_3$$7);
					ZEPHIR_CONCAT_VS(&_3$$7, &query, ";");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_4, 0, &_3$$7);
					zephir_check_call_status_or_jump(try_end_1);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &queries, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_2$$6, &queries, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_2$$6)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&query, &queries, "current", NULL, 0);
					zephir_check_call_status();
						if (ZEPHIR_IS_EMPTY(&query)) {
							continue;
						}
						ZEPHIR_INIT_LNVAR(_5$$9);
						ZEPHIR_CONCAT_VS(&_5$$9, &query, ";");
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_4, 0, &_5$$9);
						zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CALL_METHOD(NULL, &queries, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&query);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "commit", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_6$$5);
			ZVAL_OBJ(&_6$$5, EG(exception));
			Z_ADDREF_P(&_6$$5);
			if (zephir_is_instance_of(&_6$$5, SL("Throwable") TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&exception, &_6$$5);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/db/adapter/pdo/postgresql.zep", 134 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		zephir_array_fetch_long(&_7$$12, &queries, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 137 TSRMLS_CC);
		ZEPHIR_INIT_VAR(&_8$$12);
		ZEPHIR_CONCAT_VS(&_8$$12, &_7$$12, ";");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_8$$12);
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

	zend_bool _6$$3, _63$$40;
	zephir_fcall_cache_entry *_56 = NULL, *_59 = NULL, *_61 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$true, __$null, columns, columnType, field, definition, oldColumn, columnName, charSize, numericSize, numericScale, _0, _1, _2, _3, *_4, _5, _48$$3, _49$$3, _50$$3, _51$$3, _60$$3, _7$$4, _8$$4, _9$$5, _10$$5, _11$$6, _12$$6, _13$$7, _14$$7, _15$$8, _16$$8, _17$$9, _18$$9, _19$$10, _20$$11, _21$$12, _22$$12, _23$$13, _24$$13, _25$$14, _26$$14, _27$$15, _28$$15, _29$$16, _30$$16, _31$$17, _32$$18, _33$$19, _34$$20, _35$$21, _36$$22, _37$$23, _38$$24, _39$$25, _40$$26, _41$$27, _42$$28, _43$$29, _44$$30, _45$$31, _46$$31, _47$$32, _52$$38, _53$$38, _54$$38, _55$$38, _57$$38, _58$$38, _62$$40, _105$$40, _106$$40, _107$$40, _108$$40, _115$$40, _64$$41, _65$$41, _66$$42, _67$$42, _68$$43, _69$$43, _70$$44, _71$$44, _72$$45, _73$$45, _74$$46, _75$$46, _76$$47, _77$$48, _78$$49, _79$$49, _80$$50, _81$$50, _82$$51, _83$$51, _84$$52, _85$$52, _86$$53, _87$$53, _88$$54, _89$$55, _90$$56, _91$$57, _92$$58, _93$$59, _94$$60, _95$$61, _96$$62, _97$$63, _98$$64, _99$$65, _100$$66, _101$$67, _102$$68, _103$$68, _104$$69, _109$$75, _110$$75, _111$$75, _112$$75, _113$$75, _114$$75;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_48$$3);
	ZVAL_UNDEF(&_49$$3);
	ZVAL_UNDEF(&_50$$3);
	ZVAL_UNDEF(&_51$$3);
	ZVAL_UNDEF(&_60$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&_31$$17);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_37$$23);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_39$$25);
	ZVAL_UNDEF(&_40$$26);
	ZVAL_UNDEF(&_41$$27);
	ZVAL_UNDEF(&_42$$28);
	ZVAL_UNDEF(&_43$$29);
	ZVAL_UNDEF(&_44$$30);
	ZVAL_UNDEF(&_45$$31);
	ZVAL_UNDEF(&_46$$31);
	ZVAL_UNDEF(&_47$$32);
	ZVAL_UNDEF(&_52$$38);
	ZVAL_UNDEF(&_53$$38);
	ZVAL_UNDEF(&_54$$38);
	ZVAL_UNDEF(&_55$$38);
	ZVAL_UNDEF(&_57$$38);
	ZVAL_UNDEF(&_58$$38);
	ZVAL_UNDEF(&_62$$40);
	ZVAL_UNDEF(&_105$$40);
	ZVAL_UNDEF(&_106$$40);
	ZVAL_UNDEF(&_107$$40);
	ZVAL_UNDEF(&_108$$40);
	ZVAL_UNDEF(&_115$$40);
	ZVAL_UNDEF(&_64$$41);
	ZVAL_UNDEF(&_65$$41);
	ZVAL_UNDEF(&_66$$42);
	ZVAL_UNDEF(&_67$$42);
	ZVAL_UNDEF(&_68$$43);
	ZVAL_UNDEF(&_69$$43);
	ZVAL_UNDEF(&_70$$44);
	ZVAL_UNDEF(&_71$$44);
	ZVAL_UNDEF(&_72$$45);
	ZVAL_UNDEF(&_73$$45);
	ZVAL_UNDEF(&_74$$46);
	ZVAL_UNDEF(&_75$$46);
	ZVAL_UNDEF(&_76$$47);
	ZVAL_UNDEF(&_77$$48);
	ZVAL_UNDEF(&_78$$49);
	ZVAL_UNDEF(&_79$$49);
	ZVAL_UNDEF(&_80$$50);
	ZVAL_UNDEF(&_81$$50);
	ZVAL_UNDEF(&_82$$51);
	ZVAL_UNDEF(&_83$$51);
	ZVAL_UNDEF(&_84$$52);
	ZVAL_UNDEF(&_85$$52);
	ZVAL_UNDEF(&_86$$53);
	ZVAL_UNDEF(&_87$$53);
	ZVAL_UNDEF(&_88$$54);
	ZVAL_UNDEF(&_89$$55);
	ZVAL_UNDEF(&_90$$56);
	ZVAL_UNDEF(&_91$$57);
	ZVAL_UNDEF(&_92$$58);
	ZVAL_UNDEF(&_93$$59);
	ZVAL_UNDEF(&_94$$60);
	ZVAL_UNDEF(&_95$$61);
	ZVAL_UNDEF(&_96$$62);
	ZVAL_UNDEF(&_97$$63);
	ZVAL_UNDEF(&_98$$64);
	ZVAL_UNDEF(&_99$$65);
	ZVAL_UNDEF(&_100$$66);
	ZVAL_UNDEF(&_101$$67);
	ZVAL_UNDEF(&_102$$68);
	ZVAL_UNDEF(&_103$$68);
	ZVAL_UNDEF(&_104$$69);
	ZVAL_UNDEF(&_109$$75);
	ZVAL_UNDEF(&_110$$75);
	ZVAL_UNDEF(&_111$$75);
	ZVAL_UNDEF(&_112$$75);
	ZVAL_UNDEF(&_113$$75);
	ZVAL_UNDEF(&_114$$75);

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
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 480);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _4);
			ZEPHIR_INIT_NVAR(&definition);
			zephir_create_array(&definition, 1, 0 TSRMLS_CC);
			add_assoc_long_ex(&definition, SL("bindType"), 2);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 172 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&charSize);
			zephir_array_fetch_long(&charSize, &field, 2, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 173 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&numericSize);
			zephir_array_fetch_long(&numericSize, &field, 3, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 174 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&numericScale);
			zephir_array_fetch_long(&numericScale, &field, 4, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 175 TSRMLS_CC);
			do {
				_6$$3 = 1;
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("boolean"), "phalcon/db/adapter/pdo/postgresql.zep", 192)) {
					ZEPHIR_INIT_NVAR(&_7$$4);
					ZVAL_LONG(&_7$$4, 8);
					zephir_array_update_string(&definition, SL("type"), &_7$$4, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_8$$4);
					ZVAL_LONG(&_8$$4, 5);
					zephir_array_update_string(&definition, SL("bindType"), &_8$$4, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/db/adapter/pdo/postgresql.zep", 204)) {
					ZEPHIR_INIT_NVAR(&_9$$5);
					ZVAL_LONG(&_9$$5, 14);
					zephir_array_update_string(&definition, SL("type"), &_9$$5, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_10$$5);
					ZVAL_LONG(&_10$$5, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_10$$5, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("mediumint"), "phalcon/db/adapter/pdo/postgresql.zep", 213)) {
					ZEPHIR_INIT_NVAR(&_11$$6);
					ZVAL_LONG(&_11$$6, 21);
					zephir_array_update_string(&definition, SL("type"), &_11$$6, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_12$$6);
					ZVAL_LONG(&_12$$6, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_12$$6, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("smallint"), "phalcon/db/adapter/pdo/postgresql.zep", 222)) {
					ZEPHIR_INIT_NVAR(&_13$$7);
					ZVAL_LONG(&_13$$7, 22);
					zephir_array_update_string(&definition, SL("type"), &_13$$7, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_14$$7);
					ZVAL_LONG(&_14$$7, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_14$$7, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("tinyint"), "phalcon/db/adapter/pdo/postgresql.zep", 231)) {
					ZEPHIR_INIT_NVAR(&_15$$8);
					ZVAL_LONG(&_15$$8, 26);
					zephir_array_update_string(&definition, SL("type"), &_15$$8, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_16$$8);
					ZVAL_LONG(&_16$$8, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_16$$8, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("int"), "phalcon/db/adapter/pdo/postgresql.zep", 243)) {
					ZEPHIR_INIT_NVAR(&_17$$9);
					ZVAL_LONG(&_17$$9, 0);
					zephir_array_update_string(&definition, SL("type"), &_17$$9, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_18$$9);
					ZVAL_LONG(&_18$$9, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_18$$9, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("bit"), "phalcon/db/adapter/pdo/postgresql.zep", 253)) {
					ZEPHIR_INIT_NVAR(&_19$$10);
					ZVAL_LONG(&_19$$10, 19);
					zephir_array_update_string(&definition, SL("type"), &_19$$10, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("enum"), "phalcon/db/adapter/pdo/postgresql.zep", 261)) {
					ZEPHIR_INIT_NVAR(&_20$$11);
					ZVAL_LONG(&_20$$11, 18);
					zephir_array_update_string(&definition, SL("type"), &_20$$11, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/db/adapter/pdo/postgresql.zep", 269)) {
					ZEPHIR_INIT_NVAR(&_21$$12);
					ZVAL_LONG(&_21$$12, 4);
					zephir_array_update_string(&definition, SL("type"), &_21$$12, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_22$$12);
					ZVAL_LONG(&_22$$12, 0);
					zephir_array_update_string(&definition, SL("size"), &_22$$12, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("date"), "phalcon/db/adapter/pdo/postgresql.zep", 277)) {
					ZEPHIR_INIT_NVAR(&_23$$13);
					ZVAL_LONG(&_23$$13, 1);
					zephir_array_update_string(&definition, SL("type"), &_23$$13, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_24$$13);
					ZVAL_LONG(&_24$$13, 0);
					zephir_array_update_string(&definition, SL("size"), &_24$$13, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/db/adapter/pdo/postgresql.zep", 286) || _6$$3 == zephir_memnstr_str(&columnType, SL("numeric"), "phalcon/db/adapter/pdo/postgresql.zep", 287)) {
					ZEPHIR_INIT_NVAR(&_25$$14);
					ZVAL_LONG(&_25$$14, 3);
					zephir_array_update_string(&definition, SL("type"), &_25$$14, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_26$$14);
					ZVAL_LONG(&_26$$14, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_26$$14, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("double precision"), "phalcon/db/adapter/pdo/postgresql.zep", 297)) {
					ZEPHIR_INIT_NVAR(&_27$$15);
					ZVAL_LONG(&_27$$15, 9);
					zephir_array_update_string(&definition, SL("type"), &_27$$15, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_28$$15);
					ZVAL_LONG(&_28$$15, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_28$$15, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("float"), "phalcon/db/adapter/pdo/postgresql.zep", 307) || _6$$3 == zephir_memnstr_str(&columnType, SL("real"), "phalcon/db/adapter/pdo/postgresql.zep", 308)) {
					ZEPHIR_INIT_NVAR(&_29$$16);
					ZVAL_LONG(&_29$$16, 7);
					zephir_array_update_string(&definition, SL("type"), &_29$$16, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_30$$16);
					ZVAL_LONG(&_30$$16, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_30$$16, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/db/adapter/pdo/postgresql.zep", 318)) {
					ZEPHIR_INIT_NVAR(&_31$$17);
					ZVAL_LONG(&_31$$17, 6);
					zephir_array_update_string(&definition, SL("type"), &_31$$17, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/db/adapter/pdo/postgresql.zep", 325)) {
					ZEPHIR_INIT_NVAR(&_32$$18);
					ZVAL_LONG(&_32$$18, 13);
					zephir_array_update_string(&definition, SL("type"), &_32$$18, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/db/adapter/pdo/postgresql.zep", 332)) {
					ZEPHIR_INIT_NVAR(&_33$$19);
					ZVAL_LONG(&_33$$19, 10);
					zephir_array_update_string(&definition, SL("type"), &_33$$19, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("blob"), "phalcon/db/adapter/pdo/postgresql.zep", 339)) {
					ZEPHIR_INIT_NVAR(&_34$$20);
					ZVAL_LONG(&_34$$20, 11);
					zephir_array_update_string(&definition, SL("type"), &_34$$20, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/db/adapter/pdo/postgresql.zep", 346)) {
					ZEPHIR_INIT_NVAR(&_35$$21);
					ZVAL_LONG(&_35$$21, 17);
					zephir_array_update_string(&definition, SL("type"), &_35$$21, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("time"), "phalcon/db/adapter/pdo/postgresql.zep", 353)) {
					ZEPHIR_INIT_NVAR(&_36$$22);
					ZVAL_LONG(&_36$$22, 20);
					zephir_array_update_string(&definition, SL("type"), &_36$$22, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("jsonb"), "phalcon/db/adapter/pdo/postgresql.zep", 360)) {
					ZEPHIR_INIT_NVAR(&_37$$23);
					ZVAL_LONG(&_37$$23, 16);
					zephir_array_update_string(&definition, SL("type"), &_37$$23, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("json"), "phalcon/db/adapter/pdo/postgresql.zep", 367)) {
					ZEPHIR_INIT_NVAR(&_38$$24);
					ZVAL_LONG(&_38$$24, 15);
					zephir_array_update_string(&definition, SL("type"), &_38$$24, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("longtext"), "phalcon/db/adapter/pdo/postgresql.zep", 374)) {
					ZEPHIR_INIT_NVAR(&_39$$25);
					ZVAL_LONG(&_39$$25, 24);
					zephir_array_update_string(&definition, SL("type"), &_39$$25, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("mediumtext"), "phalcon/db/adapter/pdo/postgresql.zep", 381)) {
					ZEPHIR_INIT_NVAR(&_40$$26);
					ZVAL_LONG(&_40$$26, 23);
					zephir_array_update_string(&definition, SL("type"), &_40$$26, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("tinytext"), "phalcon/db/adapter/pdo/postgresql.zep", 388)) {
					ZEPHIR_INIT_NVAR(&_41$$27);
					ZVAL_LONG(&_41$$27, 25);
					zephir_array_update_string(&definition, SL("type"), &_41$$27, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("text"), "phalcon/db/adapter/pdo/postgresql.zep", 395)) {
					ZEPHIR_INIT_NVAR(&_42$$28);
					ZVAL_LONG(&_42$$28, 6);
					zephir_array_update_string(&definition, SL("type"), &_42$$28, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("varying"), "phalcon/db/adapter/pdo/postgresql.zep", 402) || _6$$3 == zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/db/adapter/pdo/postgresql.zep", 403)) {
					ZEPHIR_INIT_NVAR(&_43$$29);
					ZVAL_LONG(&_43$$29, 2);
					zephir_array_update_string(&definition, SL("type"), &_43$$29, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("char"), "phalcon/db/adapter/pdo/postgresql.zep", 411)) {
					ZEPHIR_INIT_NVAR(&_44$$30);
					ZVAL_LONG(&_44$$30, 5);
					zephir_array_update_string(&definition, SL("type"), &_44$$30, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_6$$3 == zephir_memnstr_str(&columnType, SL("uuid"), "phalcon/db/adapter/pdo/postgresql.zep", 419)) {
					ZEPHIR_INIT_NVAR(&_45$$31);
					ZVAL_LONG(&_45$$31, 5);
					zephir_array_update_string(&definition, SL("type"), &_45$$31, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_46$$31);
					ZVAL_LONG(&_46$$31, 36);
					zephir_array_update_string(&definition, SL("size"), &_46$$31, PH_COPY | PH_SEPARATE);
					break;
				}
				ZEPHIR_INIT_NVAR(&_47$$32);
				ZVAL_LONG(&_47$$32, 2);
				zephir_array_update_string(&definition, SL("type"), &_47$$32, PH_COPY | PH_SEPARATE);
				break;
			} while(0);

			if (Z_TYPE_P(&oldColumn) == IS_NULL) {
				zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_48$$3, &field, 6, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 444 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(&_48$$3, "PRI")) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_49$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 451 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(&_49$$3, "NO")) {
				zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_50$$3, &field, 7, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 458 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(&_50$$3, "auto_increment")) {
				zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_OBS_NVAR(&_51$$3);
			zephir_array_fetch_long(&_51$$3, &field, 9, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 465 TSRMLS_CC);
			if (Z_TYPE_P(&_51$$3) != IS_NULL) {
				zephir_array_fetch_long(&_52$$38, &field, 9, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 466 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_53$$38);
				ZVAL_STRING(&_53$$38, "/^'|'?::[[:alnum:][:space:]]+$/");
				ZEPHIR_INIT_NVAR(&_54$$38);
				ZVAL_STRING(&_54$$38, "");
				ZEPHIR_CALL_FUNCTION(&_55$$38, "preg_replace", &_56, 21, &_53$$38, &_54$$38, &_52$$38);
				zephir_check_call_status();
				zephir_array_update_string(&definition, SL("default"), &_55$$38, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_string(&_57$$38, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 467 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_53$$38);
				ZVAL_STRING(&_53$$38, "null");
				ZEPHIR_CALL_FUNCTION(&_58$$38, "strcasecmp", &_59, 19, &_57$$38, &_53$$38);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_58$$38, 0)) {
					zephir_array_update_string(&definition, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
				}
			}
			zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 475 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_60$$3);
			object_init_ex(&_60$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_60$$3, "__construct", &_61, 142, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_60$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 476);
			ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_62$$40);
				zephir_create_array(&_62$$40, 1, 0 TSRMLS_CC);
				add_assoc_long_ex(&_62$$40, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_62$$40);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 172 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&charSize);
				zephir_array_fetch_long(&charSize, &field, 2, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 173 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&numericSize);
				zephir_array_fetch_long(&numericSize, &field, 3, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 174 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&numericScale);
				zephir_array_fetch_long(&numericScale, &field, 4, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 175 TSRMLS_CC);
				do {
					_63$$40 = 1;
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("boolean"), "phalcon/db/adapter/pdo/postgresql.zep", 192)) {
						ZEPHIR_INIT_NVAR(&_64$$41);
						ZVAL_LONG(&_64$$41, 8);
						zephir_array_update_string(&definition, SL("type"), &_64$$41, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_65$$41);
						ZVAL_LONG(&_65$$41, 5);
						zephir_array_update_string(&definition, SL("bindType"), &_65$$41, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/db/adapter/pdo/postgresql.zep", 204)) {
						ZEPHIR_INIT_NVAR(&_66$$42);
						ZVAL_LONG(&_66$$42, 14);
						zephir_array_update_string(&definition, SL("type"), &_66$$42, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_67$$42);
						ZVAL_LONG(&_67$$42, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_67$$42, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("mediumint"), "phalcon/db/adapter/pdo/postgresql.zep", 213)) {
						ZEPHIR_INIT_NVAR(&_68$$43);
						ZVAL_LONG(&_68$$43, 21);
						zephir_array_update_string(&definition, SL("type"), &_68$$43, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_69$$43);
						ZVAL_LONG(&_69$$43, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_69$$43, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("smallint"), "phalcon/db/adapter/pdo/postgresql.zep", 222)) {
						ZEPHIR_INIT_NVAR(&_70$$44);
						ZVAL_LONG(&_70$$44, 22);
						zephir_array_update_string(&definition, SL("type"), &_70$$44, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_71$$44);
						ZVAL_LONG(&_71$$44, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_71$$44, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("tinyint"), "phalcon/db/adapter/pdo/postgresql.zep", 231)) {
						ZEPHIR_INIT_NVAR(&_72$$45);
						ZVAL_LONG(&_72$$45, 26);
						zephir_array_update_string(&definition, SL("type"), &_72$$45, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_73$$45);
						ZVAL_LONG(&_73$$45, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_73$$45, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("int"), "phalcon/db/adapter/pdo/postgresql.zep", 243)) {
						ZEPHIR_INIT_NVAR(&_74$$46);
						ZVAL_LONG(&_74$$46, 0);
						zephir_array_update_string(&definition, SL("type"), &_74$$46, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_75$$46);
						ZVAL_LONG(&_75$$46, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_75$$46, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("bit"), "phalcon/db/adapter/pdo/postgresql.zep", 253)) {
						ZEPHIR_INIT_NVAR(&_76$$47);
						ZVAL_LONG(&_76$$47, 19);
						zephir_array_update_string(&definition, SL("type"), &_76$$47, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("enum"), "phalcon/db/adapter/pdo/postgresql.zep", 261)) {
						ZEPHIR_INIT_NVAR(&_77$$48);
						ZVAL_LONG(&_77$$48, 18);
						zephir_array_update_string(&definition, SL("type"), &_77$$48, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/db/adapter/pdo/postgresql.zep", 269)) {
						ZEPHIR_INIT_NVAR(&_78$$49);
						ZVAL_LONG(&_78$$49, 4);
						zephir_array_update_string(&definition, SL("type"), &_78$$49, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_79$$49);
						ZVAL_LONG(&_79$$49, 0);
						zephir_array_update_string(&definition, SL("size"), &_79$$49, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("date"), "phalcon/db/adapter/pdo/postgresql.zep", 277)) {
						ZEPHIR_INIT_NVAR(&_80$$50);
						ZVAL_LONG(&_80$$50, 1);
						zephir_array_update_string(&definition, SL("type"), &_80$$50, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_81$$50);
						ZVAL_LONG(&_81$$50, 0);
						zephir_array_update_string(&definition, SL("size"), &_81$$50, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/db/adapter/pdo/postgresql.zep", 286) || _63$$40 == zephir_memnstr_str(&columnType, SL("numeric"), "phalcon/db/adapter/pdo/postgresql.zep", 287)) {
						ZEPHIR_INIT_NVAR(&_82$$51);
						ZVAL_LONG(&_82$$51, 3);
						zephir_array_update_string(&definition, SL("type"), &_82$$51, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_83$$51);
						ZVAL_LONG(&_83$$51, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_83$$51, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("double precision"), "phalcon/db/adapter/pdo/postgresql.zep", 297)) {
						ZEPHIR_INIT_NVAR(&_84$$52);
						ZVAL_LONG(&_84$$52, 9);
						zephir_array_update_string(&definition, SL("type"), &_84$$52, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_85$$52);
						ZVAL_LONG(&_85$$52, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_85$$52, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("float"), "phalcon/db/adapter/pdo/postgresql.zep", 307) || _63$$40 == zephir_memnstr_str(&columnType, SL("real"), "phalcon/db/adapter/pdo/postgresql.zep", 308)) {
						ZEPHIR_INIT_NVAR(&_86$$53);
						ZVAL_LONG(&_86$$53, 7);
						zephir_array_update_string(&definition, SL("type"), &_86$$53, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_87$$53);
						ZVAL_LONG(&_87$$53, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_87$$53, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/db/adapter/pdo/postgresql.zep", 318)) {
						ZEPHIR_INIT_NVAR(&_88$$54);
						ZVAL_LONG(&_88$$54, 6);
						zephir_array_update_string(&definition, SL("type"), &_88$$54, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/db/adapter/pdo/postgresql.zep", 325)) {
						ZEPHIR_INIT_NVAR(&_89$$55);
						ZVAL_LONG(&_89$$55, 13);
						zephir_array_update_string(&definition, SL("type"), &_89$$55, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/db/adapter/pdo/postgresql.zep", 332)) {
						ZEPHIR_INIT_NVAR(&_90$$56);
						ZVAL_LONG(&_90$$56, 10);
						zephir_array_update_string(&definition, SL("type"), &_90$$56, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("blob"), "phalcon/db/adapter/pdo/postgresql.zep", 339)) {
						ZEPHIR_INIT_NVAR(&_91$$57);
						ZVAL_LONG(&_91$$57, 11);
						zephir_array_update_string(&definition, SL("type"), &_91$$57, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/db/adapter/pdo/postgresql.zep", 346)) {
						ZEPHIR_INIT_NVAR(&_92$$58);
						ZVAL_LONG(&_92$$58, 17);
						zephir_array_update_string(&definition, SL("type"), &_92$$58, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("time"), "phalcon/db/adapter/pdo/postgresql.zep", 353)) {
						ZEPHIR_INIT_NVAR(&_93$$59);
						ZVAL_LONG(&_93$$59, 20);
						zephir_array_update_string(&definition, SL("type"), &_93$$59, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("jsonb"), "phalcon/db/adapter/pdo/postgresql.zep", 360)) {
						ZEPHIR_INIT_NVAR(&_94$$60);
						ZVAL_LONG(&_94$$60, 16);
						zephir_array_update_string(&definition, SL("type"), &_94$$60, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("json"), "phalcon/db/adapter/pdo/postgresql.zep", 367)) {
						ZEPHIR_INIT_NVAR(&_95$$61);
						ZVAL_LONG(&_95$$61, 15);
						zephir_array_update_string(&definition, SL("type"), &_95$$61, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("longtext"), "phalcon/db/adapter/pdo/postgresql.zep", 374)) {
						ZEPHIR_INIT_NVAR(&_96$$62);
						ZVAL_LONG(&_96$$62, 24);
						zephir_array_update_string(&definition, SL("type"), &_96$$62, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("mediumtext"), "phalcon/db/adapter/pdo/postgresql.zep", 381)) {
						ZEPHIR_INIT_NVAR(&_97$$63);
						ZVAL_LONG(&_97$$63, 23);
						zephir_array_update_string(&definition, SL("type"), &_97$$63, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("tinytext"), "phalcon/db/adapter/pdo/postgresql.zep", 388)) {
						ZEPHIR_INIT_NVAR(&_98$$64);
						ZVAL_LONG(&_98$$64, 25);
						zephir_array_update_string(&definition, SL("type"), &_98$$64, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("text"), "phalcon/db/adapter/pdo/postgresql.zep", 395)) {
						ZEPHIR_INIT_NVAR(&_99$$65);
						ZVAL_LONG(&_99$$65, 6);
						zephir_array_update_string(&definition, SL("type"), &_99$$65, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("varying"), "phalcon/db/adapter/pdo/postgresql.zep", 402) || _63$$40 == zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/db/adapter/pdo/postgresql.zep", 403)) {
						ZEPHIR_INIT_NVAR(&_100$$66);
						ZVAL_LONG(&_100$$66, 2);
						zephir_array_update_string(&definition, SL("type"), &_100$$66, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("char"), "phalcon/db/adapter/pdo/postgresql.zep", 411)) {
						ZEPHIR_INIT_NVAR(&_101$$67);
						ZVAL_LONG(&_101$$67, 5);
						zephir_array_update_string(&definition, SL("type"), &_101$$67, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_63$$40 == zephir_memnstr_str(&columnType, SL("uuid"), "phalcon/db/adapter/pdo/postgresql.zep", 419)) {
						ZEPHIR_INIT_NVAR(&_102$$68);
						ZVAL_LONG(&_102$$68, 5);
						zephir_array_update_string(&definition, SL("type"), &_102$$68, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_103$$68);
						ZVAL_LONG(&_103$$68, 36);
						zephir_array_update_string(&definition, SL("size"), &_103$$68, PH_COPY | PH_SEPARATE);
						break;
					}
					ZEPHIR_INIT_NVAR(&_104$$69);
					ZVAL_LONG(&_104$$69, 2);
					zephir_array_update_string(&definition, SL("type"), &_104$$69, PH_COPY | PH_SEPARATE);
					break;
				} while(0);

				if (Z_TYPE_P(&oldColumn) == IS_NULL) {
					zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_105$$40, &field, 6, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 444 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&_105$$40, "PRI")) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_106$$40, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 451 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&_106$$40, "NO")) {
					zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_107$$40, &field, 7, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 458 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&_107$$40, "auto_increment")) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&_108$$40);
				zephir_array_fetch_long(&_108$$40, &field, 9, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 465 TSRMLS_CC);
				if (Z_TYPE_P(&_108$$40) != IS_NULL) {
					zephir_array_fetch_long(&_109$$75, &field, 9, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 466 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_110$$75);
					ZVAL_STRING(&_110$$75, "/^'|'?::[[:alnum:][:space:]]+$/");
					ZEPHIR_INIT_NVAR(&_111$$75);
					ZVAL_STRING(&_111$$75, "");
					ZEPHIR_CALL_FUNCTION(&_112$$75, "preg_replace", &_56, 21, &_110$$75, &_111$$75, &_109$$75);
					zephir_check_call_status();
					zephir_array_update_string(&definition, SL("default"), &_112$$75, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_string(&_113$$75, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 467 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_110$$75);
					ZVAL_STRING(&_110$$75, "null");
					ZEPHIR_CALL_FUNCTION(&_114$$75, "strcasecmp", &_59, 19, &_113$$75, &_110$$75);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_114$$75, 0)) {
						zephir_array_update_string(&definition, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
					}
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 475 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_115$$40);
				object_init_ex(&_115$$40, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_115$$40, "__construct", &_61, 142, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_115$$40, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 476);
				ZEPHIR_CPY_WRT(&oldColumn, &columnName);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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

	zval _14$$3, _23$$6, _29$$9, _33$$10;
	zend_string *_27;
	zend_ulong _26;
	zephir_fcall_cache_entry *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, referenceUpdate, referenceDelete, _0, _1, _2, _3, *_4, _5, *_24, _25, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$5, _12$$3, _13$$3, _15$$8, _16$$8, _17$$8, _18$$8, _19$$8, _20$$8, _21$$6, _22$$6, _28$$9, _30$$9, _32$$10, _34$$10;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_34$$10);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_29$$9);
	ZVAL_UNDEF(&_33$$10);

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
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 534);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _4);
			zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 503 TSRMLS_CC);
			if (!(zephir_array_isset(&references, &constraintName))) {
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 505 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 506 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 507 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 508 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 513 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_6$$5, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 513 TSRMLS_CC);
				zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 514 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_7$$5, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 514 TSRMLS_CC);
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 515 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_8$$5, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 515 TSRMLS_CC);
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 516 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_9$$5, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 516 TSRMLS_CC);
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 517 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_string(&referenceUpdate, &_10$$5, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 517 TSRMLS_CC);
				zephir_array_fetch(&_11$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 518 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_string(&referenceDelete, &_11$$5, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 518 TSRMLS_CC);
			}
			zephir_array_fetch_long(&_12$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 521 TSRMLS_CC);
			zephir_array_append(&columns, &_12$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 521);
			zephir_array_fetch_long(&_13$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 522 TSRMLS_CC);
			zephir_array_append(&referencedColumns, &_13$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 522);
			ZEPHIR_INIT_NVAR(&_14$$3);
			zephir_create_array(&_14$$3, 6, 0 TSRMLS_CC);
			zephir_array_update_string(&_14$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("onUpdate"), &referenceUpdate, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("onDelete"), &referenceDelete, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&references, &constraintName, &_14$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_5, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_5)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&reference, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&constraintName);
				zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 503 TSRMLS_CC);
				if (!(zephir_array_isset(&references, &constraintName))) {
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 505 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 506 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 507 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 508 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_15$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 513 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_15$$8, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 513 TSRMLS_CC);
					zephir_array_fetch(&_16$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 514 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_16$$8, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 514 TSRMLS_CC);
					zephir_array_fetch(&_17$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 515 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_17$$8, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 515 TSRMLS_CC);
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 516 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_18$$8, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 516 TSRMLS_CC);
					zephir_array_fetch(&_19$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 517 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_string(&referenceUpdate, &_19$$8, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 517 TSRMLS_CC);
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 518 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_string(&referenceDelete, &_20$$8, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 518 TSRMLS_CC);
				}
				zephir_array_fetch_long(&_21$$6, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 521 TSRMLS_CC);
				zephir_array_append(&columns, &_21$$6, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 521);
				zephir_array_fetch_long(&_22$$6, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 522 TSRMLS_CC);
				zephir_array_append(&referencedColumns, &_22$$6, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 522);
				ZEPHIR_INIT_NVAR(&_23$$6);
				zephir_create_array(&_23$$6, 6, 0 TSRMLS_CC);
				zephir_array_update_string(&_23$$6, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$6, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$6, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$6, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$6, SL("onUpdate"), &referenceUpdate, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_23$$6, SL("onDelete"), &referenceDelete, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&references, &constraintName, &_23$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&reference);
	ZEPHIR_INIT_VAR(&referenceObjects);
	array_init(&referenceObjects);
	zephir_is_iterable(&references, 0, "phalcon/db/adapter/pdo/postgresql.zep", 546);
	if (Z_TYPE_P(&references) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&references), _26, _27, _24)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_27 != NULL) { 
				ZVAL_STR_COPY(&name, _27);
			} else {
				ZVAL_LONG(&name, _26);
			}
			ZEPHIR_INIT_NVAR(&arrayReference);
			ZVAL_COPY(&arrayReference, _24);
			ZEPHIR_INIT_NVAR(&_28$$9);
			object_init_ex(&_28$$9, phalcon_db_reference_ce);
			ZEPHIR_INIT_NVAR(&_29$$9);
			zephir_create_array(&_29$$9, 6, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 537 TSRMLS_CC);
			zephir_array_update_string(&_29$$9, SL("referencedSchema"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 538 TSRMLS_CC);
			zephir_array_update_string(&_29$$9, SL("referencedTable"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 539 TSRMLS_CC);
			zephir_array_update_string(&_29$$9, SL("columns"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 540 TSRMLS_CC);
			zephir_array_update_string(&_29$$9, SL("referencedColumns"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 541 TSRMLS_CC);
			zephir_array_update_string(&_29$$9, SL("onUpdate"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 543 TSRMLS_CC);
			zephir_array_update_string(&_29$$9, SL("onDelete"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_28$$9, "__construct", &_31, 16, &name, &_29$$9);
			zephir_check_call_status();
			zephir_array_update_zval(&referenceObjects, &name, &_28$$9, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &references, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_25, &references, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_25)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &references, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&arrayReference, &references, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_32$$10);
				object_init_ex(&_32$$10, phalcon_db_reference_ce);
				ZEPHIR_INIT_NVAR(&_33$$10);
				zephir_create_array(&_33$$10, 6, 0 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 537 TSRMLS_CC);
				zephir_array_update_string(&_33$$10, SL("referencedSchema"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 538 TSRMLS_CC);
				zephir_array_update_string(&_33$$10, SL("referencedTable"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 539 TSRMLS_CC);
				zephir_array_update_string(&_33$$10, SL("columns"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 540 TSRMLS_CC);
				zephir_array_update_string(&_33$$10, SL("referencedColumns"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 541 TSRMLS_CC);
				zephir_array_update_string(&_33$$10, SL("onUpdate"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 543 TSRMLS_CC);
				zephir_array_update_string(&_33$$10, SL("onDelete"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &_32$$10, "__construct", &_31, 16, &name, &_33$$10);
				zephir_check_call_status();
				zephir_array_update_zval(&referenceObjects, &name, &_32$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &references, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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

	zephir_fcall_cache_entry *_4 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, sql, queries, query, exception, _0, *_1$$4, _2$$4, _3$$5, _5$$7, _6$$3, _7$$10, _8$$10, _9$$10;
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
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&_9$$10);

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
			zephir_is_iterable(&queries, 0, "phalcon/db/adapter/pdo/postgresql.zep", 594);
			if (Z_TYPE_P(&queries) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queries), _1$$4)
				{
					ZEPHIR_INIT_NVAR(&query);
					ZVAL_COPY(&query, _1$$4);
					if (ZEPHIR_IS_EMPTY(&query)) {
						continue;
					}
					ZEPHIR_INIT_LNVAR(_3$$5);
					ZEPHIR_CONCAT_VS(&_3$$5, &query, ";");
					ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_4, 0, &_3$$5);
					zephir_check_call_status_or_jump(try_end_1);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &queries, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_2$$4, &queries, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_2$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&query, &queries, "current", NULL, 0);
					zephir_check_call_status();
						if (ZEPHIR_IS_EMPTY(&query)) {
							continue;
						}
						ZEPHIR_INIT_LNVAR(_5$$7);
						ZEPHIR_CONCAT_VS(&_5$$7, &query, ";");
						ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_4, 0, &_5$$7);
						zephir_check_call_status_or_jump(try_end_1);
					ZEPHIR_CALL_METHOD(NULL, &queries, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&query);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "commit", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_6$$3);
			ZVAL_OBJ(&_6$$3, EG(exception));
			Z_ADDREF_P(&_6$$3);
			if (zephir_is_instance_of(&_6$$3, SL("Throwable") TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&exception, &_6$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/db/adapter/pdo/postgresql.zep", 599 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		ZEPHIR_INIT_VAR(&_7$$10);
		if (!(ZEPHIR_IS_EMPTY(&sql))) {
			zephir_array_fetch_long(&_8$$10, &queries, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 603 TSRMLS_CC);
			ZEPHIR_INIT_VAR(&_9$$10);
			ZEPHIR_CONCAT_VS(&_9$$10, &_8$$10, ";");
			ZEPHIR_CALL_METHOD(&_7$$10, this_ptr, "execute", NULL, 0, &_9$$10);
			zephir_check_call_status();
		} else {
			ZVAL_BOOL(&_7$$10, 1);
		}
		RETURN_CCTOR(&_7$$10);
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

