
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
#include "kernel/object.h"
#include "kernel/operators.h"
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
 * Specific functions for the PostgreSQL database system
 *
 * ```php
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
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Postgresql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Postgresql, phalcon, db_adapter_pdo_postgresql, phalcon_db_adapter_pdo_abstractpdo_ce, phalcon_db_adapter_pdo_postgresql_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("dialectType"), "postgresql", ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("type"), "pgsql", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Constructor for Phalcon\Db\Adapter\Pdo\Postgresql
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 7, &_0$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_postgresql_ce, getThis(), "__construct", &_1, 0, &descriptor);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo
 * constructor. Call it when you need to restore a database connection.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, connect) {

	zend_bool _3$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("descriptor"), PH_NOISY_CC);
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
		zephir_array_fetch_string(&_2$$6, &descriptor, SL("password"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 85);
		_3$$6 = Z_TYPE_P(&_2$$6) == IS_STRING;
		if (_3$$6) {
			zephir_array_fetch_string(&_4$$6, &descriptor, SL("password"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 85);
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

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
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
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/Db/Adapter/Pdo/Postgresql.zep", 109);
		return;
	}
	if (UNEXPECTED(!(zephir_fast_count_int(&columns)))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/Db/Adapter/Pdo/Postgresql.zep", 113);
		return;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&sql, &_0, "createtable", NULL, 0, &tableName, &schemaName, &definition);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&queries);
	zephir_fast_explode_str(&queries, SL(";"), &sql, LONG_MAX);
	if (zephir_fast_count_int(&queries) > 1) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(NULL, this_ptr, "begin", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_is_iterable(&queries, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 132);
			if (Z_TYPE_P(&queries) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queries), _1$$6)
				{
					ZEPHIR_INIT_NVAR(&query);
					ZVAL_COPY(&query, _1$$6);
					if (ZEPHIR_IS_EMPTY(&query)) {
						continue;
					}
					ZEPHIR_INIT_NVAR(&_3$$7);
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
						ZEPHIR_INIT_NVAR(&_5$$9);
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
			if (zephir_is_instance_of(&_6$$5, SL("Throwable"))) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&exception, &_6$$5);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 136);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		zephir_array_fetch_long(&_7$$12, &queries, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 139);
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
 * ```php
 * print_r(
 *     $connection->describeColumns("posts")
 * );
 * ```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns) {

	zend_bool _5$$3, _62$$40;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_55 = NULL, *_58 = NULL, *_60 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$true, __$false, __$null, columns, columnType, fields, field, definition, oldColumn, columnName, charSize, numericSize, numericScale, _0, _1, _2, *_3, _4, _47$$3, _48$$3, _49$$3, _50$$3, _59$$3, _6$$4, _7$$4, _8$$5, _9$$5, _10$$6, _11$$6, _12$$7, _13$$7, _14$$8, _15$$8, _16$$9, _17$$9, _18$$10, _19$$11, _20$$12, _21$$12, _22$$13, _23$$13, _24$$14, _25$$14, _26$$15, _27$$15, _28$$16, _29$$16, _30$$17, _31$$18, _32$$19, _33$$20, _34$$21, _35$$22, _36$$23, _37$$24, _38$$25, _39$$26, _40$$27, _41$$28, _42$$29, _43$$30, _44$$31, _45$$31, _46$$32, _51$$38, _52$$38, _53$$38, _54$$38, _56$$38, _57$$38, _61$$40, _104$$40, _105$$40, _106$$40, _107$$40, _114$$40, _63$$41, _64$$41, _65$$42, _66$$42, _67$$43, _68$$43, _69$$44, _70$$44, _71$$45, _72$$45, _73$$46, _74$$46, _75$$47, _76$$48, _77$$49, _78$$49, _79$$50, _80$$50, _81$$51, _82$$51, _83$$52, _84$$52, _85$$53, _86$$53, _87$$54, _88$$55, _89$$56, _90$$57, _91$$58, _92$$59, _93$$60, _94$$61, _95$$62, _96$$63, _97$$64, _98$$65, _99$$66, _100$$67, _101$$68, _102$$68, _103$$69, _108$$75, _109$$75, _110$$75, _111$$75, _112$$75, _113$$75;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&fields);
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
	ZVAL_UNDEF(&_4);
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
	ZVAL_UNDEF(&_61$$40);
	ZVAL_UNDEF(&_104$$40);
	ZVAL_UNDEF(&_105$$40);
	ZVAL_UNDEF(&_106$$40);
	ZVAL_UNDEF(&_107$$40);
	ZVAL_UNDEF(&_114$$40);
	ZVAL_UNDEF(&_63$$41);
	ZVAL_UNDEF(&_64$$41);
	ZVAL_UNDEF(&_65$$42);
	ZVAL_UNDEF(&_66$$42);
	ZVAL_UNDEF(&_67$$43);
	ZVAL_UNDEF(&_68$$43);
	ZVAL_UNDEF(&_69$$44);
	ZVAL_UNDEF(&_70$$44);
	ZVAL_UNDEF(&_71$$45);
	ZVAL_UNDEF(&_72$$45);
	ZVAL_UNDEF(&_73$$46);
	ZVAL_UNDEF(&_74$$46);
	ZVAL_UNDEF(&_75$$47);
	ZVAL_UNDEF(&_76$$48);
	ZVAL_UNDEF(&_77$$49);
	ZVAL_UNDEF(&_78$$49);
	ZVAL_UNDEF(&_79$$50);
	ZVAL_UNDEF(&_80$$50);
	ZVAL_UNDEF(&_81$$51);
	ZVAL_UNDEF(&_82$$51);
	ZVAL_UNDEF(&_83$$52);
	ZVAL_UNDEF(&_84$$52);
	ZVAL_UNDEF(&_85$$53);
	ZVAL_UNDEF(&_86$$53);
	ZVAL_UNDEF(&_87$$54);
	ZVAL_UNDEF(&_88$$55);
	ZVAL_UNDEF(&_89$$56);
	ZVAL_UNDEF(&_90$$57);
	ZVAL_UNDEF(&_91$$58);
	ZVAL_UNDEF(&_92$$59);
	ZVAL_UNDEF(&_93$$60);
	ZVAL_UNDEF(&_94$$61);
	ZVAL_UNDEF(&_95$$62);
	ZVAL_UNDEF(&_96$$63);
	ZVAL_UNDEF(&_97$$64);
	ZVAL_UNDEF(&_98$$65);
	ZVAL_UNDEF(&_99$$66);
	ZVAL_UNDEF(&_100$$67);
	ZVAL_UNDEF(&_101$$68);
	ZVAL_UNDEF(&_102$$68);
	ZVAL_UNDEF(&_103$$69);
	ZVAL_UNDEF(&_108$$75);
	ZVAL_UNDEF(&_109$$75);
	ZVAL_UNDEF(&_110$$75);
	ZVAL_UNDEF(&_111$$75);
	ZVAL_UNDEF(&_112$$75);
	ZVAL_UNDEF(&_113$$75);

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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "describecolumns", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "fetchall", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&fields, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 524);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _3)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _3);
			ZEPHIR_INIT_NVAR(&definition);
			zephir_create_array(&definition, 1, 0);
			add_assoc_long_ex(&definition, SL("bindType"), 2);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 184);
			ZEPHIR_OBS_NVAR(&charSize);
			zephir_array_fetch_long(&charSize, &field, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 185);
			ZEPHIR_OBS_NVAR(&numericSize);
			zephir_array_fetch_long(&numericSize, &field, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 186);
			ZEPHIR_OBS_NVAR(&numericScale);
			zephir_array_fetch_long(&numericScale, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 187);
			do {
				_5$$3 = 1;
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("boolean"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 205)) {
					ZEPHIR_INIT_NVAR(&_6$$4);
					ZVAL_LONG(&_6$$4, 8);
					zephir_array_update_string(&definition, SL("type"), &_6$$4, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_7$$4);
					ZVAL_LONG(&_7$$4, 5);
					zephir_array_update_string(&definition, SL("bindType"), &_7$$4, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 217)) {
					ZEPHIR_INIT_NVAR(&_8$$5);
					ZVAL_LONG(&_8$$5, 14);
					zephir_array_update_string(&definition, SL("type"), &_8$$5, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_9$$5);
					ZVAL_LONG(&_9$$5, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_9$$5, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("mediumint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 227)) {
					ZEPHIR_INIT_NVAR(&_10$$6);
					ZVAL_LONG(&_10$$6, 21);
					zephir_array_update_string(&definition, SL("type"), &_10$$6, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_11$$6);
					ZVAL_LONG(&_11$$6, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_11$$6, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("smallint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 237)) {
					ZEPHIR_INIT_NVAR(&_12$$7);
					ZVAL_LONG(&_12$$7, 22);
					zephir_array_update_string(&definition, SL("type"), &_12$$7, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_13$$7);
					ZVAL_LONG(&_13$$7, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_13$$7, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinyint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 247)) {
					ZEPHIR_INIT_NVAR(&_14$$8);
					ZVAL_LONG(&_14$$8, 26);
					zephir_array_update_string(&definition, SL("type"), &_14$$8, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_15$$8);
					ZVAL_LONG(&_15$$8, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_15$$8, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 260)) {
					ZEPHIR_INIT_NVAR(&_16$$9);
					ZVAL_LONG(&_16$$9, 0);
					zephir_array_update_string(&definition, SL("type"), &_16$$9, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_17$$9);
					ZVAL_LONG(&_17$$9, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_17$$9, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("bit"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 270)) {
					ZEPHIR_INIT_NVAR(&_18$$10);
					ZVAL_LONG(&_18$$10, 19);
					zephir_array_update_string(&definition, SL("type"), &_18$$10, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 279)) {
					ZEPHIR_INIT_NVAR(&_19$$11);
					ZVAL_LONG(&_19$$11, 18);
					zephir_array_update_string(&definition, SL("type"), &_19$$11, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 287)) {
					ZEPHIR_INIT_NVAR(&_20$$12);
					ZVAL_LONG(&_20$$12, 4);
					zephir_array_update_string(&definition, SL("type"), &_20$$12, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_21$$12);
					ZVAL_LONG(&_21$$12, 0);
					zephir_array_update_string(&definition, SL("size"), &_21$$12, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 296)) {
					ZEPHIR_INIT_NVAR(&_22$$13);
					ZVAL_LONG(&_22$$13, 1);
					zephir_array_update_string(&definition, SL("type"), &_22$$13, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_23$$13);
					ZVAL_LONG(&_23$$13, 0);
					zephir_array_update_string(&definition, SL("size"), &_23$$13, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 306) || _5$$3 == zephir_memnstr_str(&columnType, SL("numeric"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 307)) {
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
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("double precision"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 318)) {
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
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 329) || _5$$3 == zephir_memnstr_str(&columnType, SL("real"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 330)) {
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
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 341)) {
					ZEPHIR_INIT_NVAR(&_30$$17);
					ZVAL_LONG(&_30$$17, 6);
					zephir_array_update_string(&definition, SL("type"), &_30$$17, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 349)) {
					ZEPHIR_INIT_NVAR(&_31$$18);
					ZVAL_LONG(&_31$$18, 13);
					zephir_array_update_string(&definition, SL("type"), &_31$$18, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 357)) {
					ZEPHIR_INIT_NVAR(&_32$$19);
					ZVAL_LONG(&_32$$19, 10);
					zephir_array_update_string(&definition, SL("type"), &_32$$19, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("blob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 365)) {
					ZEPHIR_INIT_NVAR(&_33$$20);
					ZVAL_LONG(&_33$$20, 11);
					zephir_array_update_string(&definition, SL("type"), &_33$$20, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 373)) {
					ZEPHIR_INIT_NVAR(&_34$$21);
					ZVAL_LONG(&_34$$21, 17);
					zephir_array_update_string(&definition, SL("type"), &_34$$21, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("time"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 381)) {
					ZEPHIR_INIT_NVAR(&_35$$22);
					ZVAL_LONG(&_35$$22, 20);
					zephir_array_update_string(&definition, SL("type"), &_35$$22, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("jsonb"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 389)) {
					ZEPHIR_INIT_NVAR(&_36$$23);
					ZVAL_LONG(&_36$$23, 16);
					zephir_array_update_string(&definition, SL("type"), &_36$$23, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("json"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 397)) {
					ZEPHIR_INIT_NVAR(&_37$$24);
					ZVAL_LONG(&_37$$24, 15);
					zephir_array_update_string(&definition, SL("type"), &_37$$24, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("longtext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 405)) {
					ZEPHIR_INIT_NVAR(&_38$$25);
					ZVAL_LONG(&_38$$25, 24);
					zephir_array_update_string(&definition, SL("type"), &_38$$25, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("mediumtext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 413)) {
					ZEPHIR_INIT_NVAR(&_39$$26);
					ZVAL_LONG(&_39$$26, 23);
					zephir_array_update_string(&definition, SL("type"), &_39$$26, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinytext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 421)) {
					ZEPHIR_INIT_NVAR(&_40$$27);
					ZVAL_LONG(&_40$$27, 25);
					zephir_array_update_string(&definition, SL("type"), &_40$$27, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 429)) {
					ZEPHIR_INIT_NVAR(&_41$$28);
					ZVAL_LONG(&_41$$28, 6);
					zephir_array_update_string(&definition, SL("type"), &_41$$28, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("varying"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 437) || _5$$3 == zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 438)) {
					ZEPHIR_INIT_NVAR(&_42$$29);
					ZVAL_LONG(&_42$$29, 2);
					zephir_array_update_string(&definition, SL("type"), &_42$$29, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 447)) {
					ZEPHIR_INIT_NVAR(&_43$$30);
					ZVAL_LONG(&_43$$30, 5);
					zephir_array_update_string(&definition, SL("type"), &_43$$30, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("uuid"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 456)) {
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
			zephir_array_fetch_long(&_47$$3, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 483);
			if (ZEPHIR_IS_STRING(&_47$$3, "PRI")) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_48$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 490);
			if (ZEPHIR_IS_STRING(&_48$$3, "YES")) {
				zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_49$$3, &field, 7, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 497);
			if (ZEPHIR_IS_STRING(&_49$$3, "auto_increment")) {
				zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_50$$3, &field, 9, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 504);
			if (Z_TYPE_P(&_50$$3) != IS_NULL) {
				zephir_array_fetch_long(&_51$$38, &field, 9, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 509);
				ZEPHIR_INIT_NVAR(&_52$$38);
				ZVAL_STRING(&_52$$38, "/^'|'?::[[:alnum:][:space:]]+$/");
				ZEPHIR_INIT_NVAR(&_53$$38);
				ZVAL_STRING(&_53$$38, "");
				ZEPHIR_CALL_FUNCTION(&_54$$38, "preg_replace", &_55, 50, &_52$$38, &_53$$38, &_51$$38);
				zephir_check_call_status();
				zephir_array_update_string(&definition, SL("default"), &_54$$38, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_string(&_56$$38, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 511);
				ZEPHIR_INIT_NVAR(&_52$$38);
				ZVAL_STRING(&_52$$38, "null");
				ZEPHIR_CALL_FUNCTION(&_57$$38, "strcasecmp", &_58, 47, &_56$$38, &_52$$38);
				zephir_check_call_status();
				if (ZEPHIR_IS_LONG(&_57$$38, 0)) {
					zephir_array_update_string(&definition, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
				}
			}
			zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 519);
			ZEPHIR_INIT_NVAR(&_59$$3);
			object_init_ex(&_59$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_59$$3, "__construct", &_60, 211, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_59$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 520);
			ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_4, &fields, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_61$$40);
				zephir_create_array(&_61$$40, 1, 0);
				add_assoc_long_ex(&_61$$40, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_61$$40);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 184);
				ZEPHIR_OBS_NVAR(&charSize);
				zephir_array_fetch_long(&charSize, &field, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 185);
				ZEPHIR_OBS_NVAR(&numericSize);
				zephir_array_fetch_long(&numericSize, &field, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 186);
				ZEPHIR_OBS_NVAR(&numericScale);
				zephir_array_fetch_long(&numericScale, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 187);
				do {
					_62$$40 = 1;
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("boolean"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 205)) {
						ZEPHIR_INIT_NVAR(&_63$$41);
						ZVAL_LONG(&_63$$41, 8);
						zephir_array_update_string(&definition, SL("type"), &_63$$41, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_64$$41);
						ZVAL_LONG(&_64$$41, 5);
						zephir_array_update_string(&definition, SL("bindType"), &_64$$41, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 217)) {
						ZEPHIR_INIT_NVAR(&_65$$42);
						ZVAL_LONG(&_65$$42, 14);
						zephir_array_update_string(&definition, SL("type"), &_65$$42, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_66$$42);
						ZVAL_LONG(&_66$$42, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_66$$42, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("mediumint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 227)) {
						ZEPHIR_INIT_NVAR(&_67$$43);
						ZVAL_LONG(&_67$$43, 21);
						zephir_array_update_string(&definition, SL("type"), &_67$$43, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_68$$43);
						ZVAL_LONG(&_68$$43, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_68$$43, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("smallint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 237)) {
						ZEPHIR_INIT_NVAR(&_69$$44);
						ZVAL_LONG(&_69$$44, 22);
						zephir_array_update_string(&definition, SL("type"), &_69$$44, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_70$$44);
						ZVAL_LONG(&_70$$44, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_70$$44, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("tinyint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 247)) {
						ZEPHIR_INIT_NVAR(&_71$$45);
						ZVAL_LONG(&_71$$45, 26);
						zephir_array_update_string(&definition, SL("type"), &_71$$45, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_72$$45);
						ZVAL_LONG(&_72$$45, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_72$$45, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 260)) {
						ZEPHIR_INIT_NVAR(&_73$$46);
						ZVAL_LONG(&_73$$46, 0);
						zephir_array_update_string(&definition, SL("type"), &_73$$46, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_74$$46);
						ZVAL_LONG(&_74$$46, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_74$$46, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("bit"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 270)) {
						ZEPHIR_INIT_NVAR(&_75$$47);
						ZVAL_LONG(&_75$$47, 19);
						zephir_array_update_string(&definition, SL("type"), &_75$$47, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 279)) {
						ZEPHIR_INIT_NVAR(&_76$$48);
						ZVAL_LONG(&_76$$48, 18);
						zephir_array_update_string(&definition, SL("type"), &_76$$48, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 287)) {
						ZEPHIR_INIT_NVAR(&_77$$49);
						ZVAL_LONG(&_77$$49, 4);
						zephir_array_update_string(&definition, SL("type"), &_77$$49, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_78$$49);
						ZVAL_LONG(&_78$$49, 0);
						zephir_array_update_string(&definition, SL("size"), &_78$$49, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 296)) {
						ZEPHIR_INIT_NVAR(&_79$$50);
						ZVAL_LONG(&_79$$50, 1);
						zephir_array_update_string(&definition, SL("type"), &_79$$50, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_80$$50);
						ZVAL_LONG(&_80$$50, 0);
						zephir_array_update_string(&definition, SL("size"), &_80$$50, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 306) || _62$$40 == zephir_memnstr_str(&columnType, SL("numeric"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 307)) {
						ZEPHIR_INIT_NVAR(&_81$$51);
						ZVAL_LONG(&_81$$51, 3);
						zephir_array_update_string(&definition, SL("type"), &_81$$51, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_82$$51);
						ZVAL_LONG(&_82$$51, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_82$$51, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("double precision"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 318)) {
						ZEPHIR_INIT_NVAR(&_83$$52);
						ZVAL_LONG(&_83$$52, 9);
						zephir_array_update_string(&definition, SL("type"), &_83$$52, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_84$$52);
						ZVAL_LONG(&_84$$52, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_84$$52, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 329) || _62$$40 == zephir_memnstr_str(&columnType, SL("real"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 330)) {
						ZEPHIR_INIT_NVAR(&_85$$53);
						ZVAL_LONG(&_85$$53, 7);
						zephir_array_update_string(&definition, SL("type"), &_85$$53, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_86$$53);
						ZVAL_LONG(&_86$$53, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_86$$53, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 341)) {
						ZEPHIR_INIT_NVAR(&_87$$54);
						ZVAL_LONG(&_87$$54, 6);
						zephir_array_update_string(&definition, SL("type"), &_87$$54, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 349)) {
						ZEPHIR_INIT_NVAR(&_88$$55);
						ZVAL_LONG(&_88$$55, 13);
						zephir_array_update_string(&definition, SL("type"), &_88$$55, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 357)) {
						ZEPHIR_INIT_NVAR(&_89$$56);
						ZVAL_LONG(&_89$$56, 10);
						zephir_array_update_string(&definition, SL("type"), &_89$$56, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("blob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 365)) {
						ZEPHIR_INIT_NVAR(&_90$$57);
						ZVAL_LONG(&_90$$57, 11);
						zephir_array_update_string(&definition, SL("type"), &_90$$57, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 373)) {
						ZEPHIR_INIT_NVAR(&_91$$58);
						ZVAL_LONG(&_91$$58, 17);
						zephir_array_update_string(&definition, SL("type"), &_91$$58, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("time"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 381)) {
						ZEPHIR_INIT_NVAR(&_92$$59);
						ZVAL_LONG(&_92$$59, 20);
						zephir_array_update_string(&definition, SL("type"), &_92$$59, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("jsonb"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 389)) {
						ZEPHIR_INIT_NVAR(&_93$$60);
						ZVAL_LONG(&_93$$60, 16);
						zephir_array_update_string(&definition, SL("type"), &_93$$60, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("json"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 397)) {
						ZEPHIR_INIT_NVAR(&_94$$61);
						ZVAL_LONG(&_94$$61, 15);
						zephir_array_update_string(&definition, SL("type"), &_94$$61, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("longtext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 405)) {
						ZEPHIR_INIT_NVAR(&_95$$62);
						ZVAL_LONG(&_95$$62, 24);
						zephir_array_update_string(&definition, SL("type"), &_95$$62, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("mediumtext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 413)) {
						ZEPHIR_INIT_NVAR(&_96$$63);
						ZVAL_LONG(&_96$$63, 23);
						zephir_array_update_string(&definition, SL("type"), &_96$$63, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("tinytext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 421)) {
						ZEPHIR_INIT_NVAR(&_97$$64);
						ZVAL_LONG(&_97$$64, 25);
						zephir_array_update_string(&definition, SL("type"), &_97$$64, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 429)) {
						ZEPHIR_INIT_NVAR(&_98$$65);
						ZVAL_LONG(&_98$$65, 6);
						zephir_array_update_string(&definition, SL("type"), &_98$$65, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("varying"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 437) || _62$$40 == zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 438)) {
						ZEPHIR_INIT_NVAR(&_99$$66);
						ZVAL_LONG(&_99$$66, 2);
						zephir_array_update_string(&definition, SL("type"), &_99$$66, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 447)) {
						ZEPHIR_INIT_NVAR(&_100$$67);
						ZVAL_LONG(&_100$$67, 5);
						zephir_array_update_string(&definition, SL("type"), &_100$$67, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_62$$40 == zephir_memnstr_str(&columnType, SL("uuid"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 456)) {
						ZEPHIR_INIT_NVAR(&_101$$68);
						ZVAL_LONG(&_101$$68, 5);
						zephir_array_update_string(&definition, SL("type"), &_101$$68, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_102$$68);
						ZVAL_LONG(&_102$$68, 36);
						zephir_array_update_string(&definition, SL("size"), &_102$$68, PH_COPY | PH_SEPARATE);
						break;
					}
					ZEPHIR_INIT_NVAR(&_103$$69);
					ZVAL_LONG(&_103$$69, 2);
					zephir_array_update_string(&definition, SL("type"), &_103$$69, PH_COPY | PH_SEPARATE);
					break;
				} while(0);

				if (Z_TYPE_P(&oldColumn) == IS_NULL) {
					zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_104$$40, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 483);
				if (ZEPHIR_IS_STRING(&_104$$40, "PRI")) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_105$$40, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 490);
				if (ZEPHIR_IS_STRING(&_105$$40, "YES")) {
					zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_106$$40, &field, 7, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 497);
				if (ZEPHIR_IS_STRING(&_106$$40, "auto_increment")) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_107$$40, &field, 9, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 504);
				if (Z_TYPE_P(&_107$$40) != IS_NULL) {
					zephir_array_fetch_long(&_108$$75, &field, 9, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 509);
					ZEPHIR_INIT_NVAR(&_109$$75);
					ZVAL_STRING(&_109$$75, "/^'|'?::[[:alnum:][:space:]]+$/");
					ZEPHIR_INIT_NVAR(&_110$$75);
					ZVAL_STRING(&_110$$75, "");
					ZEPHIR_CALL_FUNCTION(&_111$$75, "preg_replace", &_55, 50, &_109$$75, &_110$$75, &_108$$75);
					zephir_check_call_status();
					zephir_array_update_string(&definition, SL("default"), &_111$$75, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_string(&_112$$75, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 511);
					ZEPHIR_INIT_NVAR(&_109$$75);
					ZVAL_STRING(&_109$$75, "null");
					ZEPHIR_CALL_FUNCTION(&_113$$75, "strcasecmp", &_58, 47, &_112$$75, &_109$$75);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_113$$75, 0)) {
						zephir_array_update_string(&definition, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
					}
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 519);
				ZEPHIR_INIT_NVAR(&_114$$40);
				object_init_ex(&_114$$40, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_114$$40, "__construct", &_60, 211, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_114$$40, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 520);
				ZEPHIR_CPY_WRT(&oldColumn, &columnName);
			ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	RETURN_CCTOR(&columns);

}

/**
 * Lists table references
 *
 *```php
 * print_r(
 *     $connection->describeReferences("robots_parts")
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeReferences) {

	zval _14$$3, _23$$6, _29$$9, _33$$10;
	zend_string *_27;
	zend_ulong _26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be of the type string"));
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be of the type string"));
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
	zephir_read_property(&_1, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describereferences", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 576);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _4);
			zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 545);
			if (!(zephir_array_isset(&references, &constraintName))) {
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 548);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 549);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 550);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 551);
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 555);
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_6$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 555);
				zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 556);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_7$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 556);
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 557);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_8$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 557);
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 558);
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_9$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 558);
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 559);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_string(&referenceUpdate, &_10$$5, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 559);
				zephir_array_fetch(&_11$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 560);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_string(&referenceDelete, &_11$$5, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 560);
			}
			zephir_array_fetch_long(&_12$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 563);
			zephir_array_append(&columns, &_12$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 563);
			zephir_array_fetch_long(&_13$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 564);
			zephir_array_append(&referencedColumns, &_13$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 564);
			ZEPHIR_INIT_NVAR(&_14$$3);
			zephir_create_array(&_14$$3, 6, 0);
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
				zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 545);
				if (!(zephir_array_isset(&references, &constraintName))) {
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 548);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 549);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 550);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 551);
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_15$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 555);
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_15$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 555);
					zephir_array_fetch(&_16$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 556);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_16$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 556);
					zephir_array_fetch(&_17$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 557);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_17$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 557);
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 558);
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_18$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 558);
					zephir_array_fetch(&_19$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 559);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_string(&referenceUpdate, &_19$$8, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 559);
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 560);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_string(&referenceDelete, &_20$$8, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 560);
				}
				zephir_array_fetch_long(&_21$$6, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 563);
				zephir_array_append(&columns, &_21$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 563);
				zephir_array_fetch_long(&_22$$6, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 564);
				zephir_array_append(&referencedColumns, &_22$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 564);
				ZEPHIR_INIT_NVAR(&_23$$6);
				zephir_create_array(&_23$$6, 6, 0);
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
	zephir_is_iterable(&references, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 592);
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
			zephir_create_array(&_29$$9, 6, 0);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 582);
			zephir_array_update_string(&_29$$9, SL("referencedSchema"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 583);
			zephir_array_update_string(&_29$$9, SL("referencedTable"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 584);
			zephir_array_update_string(&_29$$9, SL("columns"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 585);
			zephir_array_update_string(&_29$$9, SL("referencedColumns"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 586);
			zephir_array_update_string(&_29$$9, SL("onUpdate"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 588);
			zephir_array_update_string(&_29$$9, SL("onDelete"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_28$$9, "__construct", &_31, 33, &name, &_29$$9);
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
				zephir_create_array(&_33$$10, 6, 0);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 582);
				zephir_array_update_string(&_33$$10, SL("referencedSchema"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 583);
				zephir_array_update_string(&_33$$10, SL("referencedTable"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 584);
				zephir_array_update_string(&_33$$10, SL("columns"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 585);
				zephir_array_update_string(&_33$$10, SL("referencedColumns"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 586);
				zephir_array_update_string(&_33$$10, SL("onUpdate"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 588);
				zephir_array_update_string(&_33$$10, SL("onDelete"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &_32$$10, "__construct", &_31, 33, &name, &_33$$10);
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
 *```php
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
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DEFAULT");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 34, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Modifies a table column based on a definition
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, modifyColumn) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be of the type string"));
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(&tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(&tableName);
		ZVAL_EMPTY_STRING(&tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be of the type string"));
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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&sql, &_0, "modifycolumn", NULL, 0, &tableName, &schemaName, column, currentColumn);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&queries);
	zephir_fast_explode_str(&queries, SL(";"), &sql, LONG_MAX);
	if (zephir_fast_count_int(&queries) > 1) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(NULL, this_ptr, "begin", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_is_iterable(&queries, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 648);
			if (Z_TYPE_P(&queries) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queries), _1$$4)
				{
					ZEPHIR_INIT_NVAR(&query);
					ZVAL_COPY(&query, _1$$4);
					if (ZEPHIR_IS_EMPTY(&query)) {
						continue;
					}
					ZEPHIR_INIT_NVAR(&_3$$5);
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
						ZEPHIR_INIT_NVAR(&_5$$7);
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
			if (zephir_is_instance_of(&_6$$3, SL("Throwable"))) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(&exception, &_6$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 652);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		ZEPHIR_INIT_VAR(&_7$$10);
		if (!(ZEPHIR_IS_EMPTY(&sql))) {
			zephir_array_fetch_long(&_8$$10, &queries, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 655);
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
 * Check whether the database system requires a sequence to produce
 * auto-numeric values
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * Check whether the database system requires an explicit value for identity
 * columns
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, useExplicitIdValue) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

/**
 * Returns PDO adapter DSN defaults as a key-value map.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDsnDefaults) {

	zval *this_ptr = getThis();


	array_init(return_value);
	return;

}

