
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/main.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Specific functions for the SQLite database system
 *
 * ```php
 * use Phalcon\Db\Adapter\Pdo\Sqlite;
 *
 * $connection = new Sqlite(
 *     [
 *         "dbname" => "/tmp/test.sqlite",
 *     ]
 * );
 * ```
 *
 * @phpstan-import-type db_dsn_defaults from DbTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Sqlite)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Sqlite, phalcon, db_adapter_pdo_sqlite, phalcon_db_adapter_pdo_abstractpdo_ce, phalcon_db_adapter_pdo_sqlite_method_entry, 0);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "sqlite", sizeof("sqlite") - 1);
		zephir_declare_typed_property(phalcon_db_adapter_pdo_sqlite_ce, SL("dialectType"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "sqlite", sizeof("sqlite") - 1);
		zephir_declare_typed_property(phalcon_db_adapter_pdo_sqlite_ce, SL("type"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Constructor for Phalcon\Db\Adapter\Pdo\Sqlite
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, __construct)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, _1$$3;
	zval descriptor;

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&_1$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(descriptor, descriptor_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &descriptor_param);
	zephir_get_arrval(&descriptor, descriptor_param);
	_0 = zephir_array_isset_value_string(&descriptor, SL("charset"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "SQLite does not allow the charset to be changed in the DSN.");
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 8, &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_db_adapter_pdo_sqlite_ce, getThis(), "__construct", &_zephir_call_cache[0], &descriptor);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo
 * constructor. Call it when you need to restore a database connection.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, connect)
{
	zend_bool _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, dbname, _0$$3, _3$$5;
	zval descriptor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&dbname);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_3$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("descriptor", 10, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(descriptor, descriptor_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &descriptor_param);
	if (!descriptor_param) {
		ZEPHIR_INIT_VAR(&descriptor);
		array_init(&descriptor);
	} else {
		zephir_get_arrval(&descriptor, descriptor_param);
	}
	if (ZEPHIR_IS_EMPTY(&descriptor)) {
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 614, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(Z_TYPE_P(&_0$$3) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&_0$$3, "descriptor", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&descriptor, &_0$$3);
	}
	zephir_memory_observe(&dbname);
	_1 = zephir_array_isset_string_fetch(&dbname, &descriptor, SL("dbname"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_array_update_string(&descriptor, SL("dsn"), &dbname, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_unset_string(&descriptor, SL("dbname"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		_2 = zephir_array_isset_value_string(&descriptor, SL("dsn"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (UNEXPECTED(!(_2))) {
			ZEPHIR_INIT_VAR(&_3$$5);
			object_init_ex(&_3$$5, phalcon_db_exceptions_missingsqlitedatabase_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_3$$5, "__construct", &_zephir_call_cache[0]);
			zephir_check_call_status();
			zephir_throw_exception_debug(&_3$$5, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 77);
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_PARENT_CACHED(NULL, phalcon_db_adapter_pdo_sqlite_ce, getThis(), "connect", &_zephir_call_cache[1], &descriptor);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeColumns)
{
	zend_bool _56, _39$$3, _41$$3, _33$$24, _35$$24, _44$$34, _45$$34, _91$$36, _93$$36, _85$$57, _87$$57, _96$$67, _97$$67;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_49 = NULL, *_54 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, hiddenFlag = 0;
	zval table_zv, schema_zv, __$true, __$false, columns, columnType, fields, field, definition, oldColumn, sizePattern, matches, matchOne, matchTwo, columnName, _0, _1, _2, *_3, _4, *_5, _55, _6$$3, _37$$3, _38$$3, _7$$4, _8$$4, _9$$5, _10$$5, _11$$6, _12$$6, _13$$6, _14$$8, _15$$9, _16$$10, _17$$11, _18$$11, _19$$12, _20$$12, _21$$13, _22$$13, _23$$14, _24$$15, _25$$16, _26$$17, _27$$18, _28$$19, _29$$20, _30$$21, _31$$22, _32$$23, _34$$25, _36$$26, _40$$32, _42$$33, _43$$33, _46$$34, _47$$34, _48$$34, _50$$35, _51$$35, _52$$35, _53$$35, _57$$36, _58$$36, _89$$36, _90$$36, _59$$37, _60$$37, _61$$38, _62$$38, _63$$39, _64$$39, _65$$39, _66$$41, _67$$42, _68$$43, _69$$44, _70$$44, _71$$45, _72$$45, _73$$46, _74$$46, _75$$47, _76$$48, _77$$49, _78$$50, _79$$51, _80$$52, _81$$53, _82$$54, _83$$55, _84$$56, _86$$58, _88$$59, _92$$65, _94$$66, _95$$66, _98$$67, _99$$67, _100$$67, _101$$68, _102$$68, _103$$68, _104$$68;
	zend_string *table = NULL, *schema = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&fields);
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_55);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_37$$3);
	ZVAL_UNDEF(&_38$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_30$$21);
	ZVAL_UNDEF(&_31$$22);
	ZVAL_UNDEF(&_32$$23);
	ZVAL_UNDEF(&_34$$25);
	ZVAL_UNDEF(&_36$$26);
	ZVAL_UNDEF(&_40$$32);
	ZVAL_UNDEF(&_42$$33);
	ZVAL_UNDEF(&_43$$33);
	ZVAL_UNDEF(&_46$$34);
	ZVAL_UNDEF(&_47$$34);
	ZVAL_UNDEF(&_48$$34);
	ZVAL_UNDEF(&_50$$35);
	ZVAL_UNDEF(&_51$$35);
	ZVAL_UNDEF(&_52$$35);
	ZVAL_UNDEF(&_53$$35);
	ZVAL_UNDEF(&_57$$36);
	ZVAL_UNDEF(&_58$$36);
	ZVAL_UNDEF(&_89$$36);
	ZVAL_UNDEF(&_90$$36);
	ZVAL_UNDEF(&_59$$37);
	ZVAL_UNDEF(&_60$$37);
	ZVAL_UNDEF(&_61$$38);
	ZVAL_UNDEF(&_62$$38);
	ZVAL_UNDEF(&_63$$39);
	ZVAL_UNDEF(&_64$$39);
	ZVAL_UNDEF(&_65$$39);
	ZVAL_UNDEF(&_66$$41);
	ZVAL_UNDEF(&_67$$42);
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
	ZVAL_UNDEF(&_78$$50);
	ZVAL_UNDEF(&_79$$51);
	ZVAL_UNDEF(&_80$$52);
	ZVAL_UNDEF(&_81$$53);
	ZVAL_UNDEF(&_82$$54);
	ZVAL_UNDEF(&_83$$55);
	ZVAL_UNDEF(&_84$$56);
	ZVAL_UNDEF(&_86$$58);
	ZVAL_UNDEF(&_88$$59);
	ZVAL_UNDEF(&_92$$65);
	ZVAL_UNDEF(&_94$$66);
	ZVAL_UNDEF(&_95$$66);
	ZVAL_UNDEF(&_98$$67);
	ZVAL_UNDEF(&_99$$67);
	ZVAL_UNDEF(&_100$$67);
	ZVAL_UNDEF(&_101$$68);
	ZVAL_UNDEF(&_102$$68);
	ZVAL_UNDEF(&_103$$68);
	ZVAL_UNDEF(&_104$$68);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
		zephir_memory_observe(&schema_zv);
	ZVAL_STR_COPY(&schema_zv, schema);
	}
	ZEPHIR_INIT_VAR(&oldColumn);
	ZVAL_NULL(&oldColumn);
	ZEPHIR_INIT_VAR(&sizePattern);
	ZVAL_STRING(&sizePattern, "#\\(([0-9]+)(?:,\\s*([0-9]+))*\\)#");
	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 615, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_1, &_0, "describeColumns", &_zephir_call_cache[0], &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD_CACHED(&fields, this_ptr, "fetchAll", &_zephir_call_cache[1], &_1, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&fields) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &fields);
		_3 = &_4;
	} else {
		_3 = &fields;
	}
	zephir_is_iterable(_3, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 345);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _5);
			ZEPHIR_INIT_NVAR(&definition);
			zephir_create_array(&definition, 1, 0);
			add_assoc_long_ex(&definition, SL("bindType"), 2);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 122);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_6$$3);
			zephir_fast_strtolower(&_6$$3, &columnType);
			ZEPHIR_CPY_WRT(&columnType, &_6$$3);
			if (zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 138)) {
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZVAL_LONG(&_7$$4, 14);
				zephir_array_update_string(&definition, SL("type"), &_7$$4, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZVAL_LONG(&_8$$4, 2);
				zephir_array_update_string(&definition, SL("bindType"), &_8$$4, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("tinyint(1)"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 145)) {
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_LONG(&_9$$5, 8);
				zephir_array_update_string(&definition, SL("type"), &_9$$5, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZVAL_LONG(&_10$$5, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_10$$5, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&columnType);
				ZVAL_STRING(&columnType, "boolean");
			} else if (zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 152)) {
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZVAL_LONG(&_11$$6, 0);
				zephir_array_update_string(&definition, SL("type"), &_11$$6, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_12$$6);
				ZVAL_LONG(&_12$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_12$$6, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_13$$6);
				zephir_array_fetch_long(&_13$$6, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 160);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&_13$$6)) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else if (zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 167)) {
				ZEPHIR_INIT_NVAR(&_14$$8);
				ZVAL_LONG(&_14$$8, 5);
				zephir_array_update_string(&definition, SL("type"), &_14$$8, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 176)) {
				ZEPHIR_INIT_NVAR(&_15$$9);
				ZVAL_LONG(&_15$$9, 4);
				zephir_array_update_string(&definition, SL("type"), &_15$$9, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 181)) {
				ZEPHIR_INIT_NVAR(&_16$$10);
				ZVAL_LONG(&_16$$10, 1);
				zephir_array_update_string(&definition, SL("type"), &_16$$10, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 190)) {
				ZEPHIR_INIT_NVAR(&_17$$11);
				ZVAL_LONG(&_17$$11, 3);
				zephir_array_update_string(&definition, SL("type"), &_17$$11, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_18$$11);
				ZVAL_LONG(&_18$$11, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_18$$11, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 197)) {
				ZEPHIR_INIT_NVAR(&_19$$12);
				ZVAL_LONG(&_19$$12, 7);
				zephir_array_update_string(&definition, SL("type"), &_19$$12, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_20$$12);
				ZVAL_LONG(&_20$$12, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_20$$12, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("real"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 204)) {
				ZEPHIR_INIT_NVAR(&_21$$13);
				ZVAL_LONG(&_21$$13, 7);
				zephir_array_update_string(&definition, SL("type"), &_21$$13, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_22$$13);
				ZVAL_LONG(&_22$$13, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_22$$13, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 215)) {
				ZEPHIR_INIT_NVAR(&_23$$14);
				ZVAL_LONG(&_23$$14, 17);
				zephir_array_update_string(&definition, SL("type"), &_23$$14, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 224)) {
				ZEPHIR_INIT_NVAR(&_24$$15);
				ZVAL_LONG(&_24$$15, 2);
				zephir_array_update_string(&definition, SL("type"), &_24$$15, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 229)) {
				ZEPHIR_INIT_NVAR(&_25$$16);
				ZVAL_LONG(&_25$$16, 5);
				zephir_array_update_string(&definition, SL("type"), &_25$$16, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 234)) {
				ZEPHIR_INIT_NVAR(&_26$$17);
				ZVAL_LONG(&_26$$17, 6);
				zephir_array_update_string(&definition, SL("type"), &_26$$17, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 245)) {
				ZEPHIR_INIT_NVAR(&_27$$18);
				ZVAL_LONG(&_27$$18, 10);
				zephir_array_update_string(&definition, SL("type"), &_27$$18, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 247)) {
				ZEPHIR_INIT_NVAR(&_28$$19);
				ZVAL_LONG(&_28$$19, 12);
				zephir_array_update_string(&definition, SL("type"), &_28$$19, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 249)) {
				ZEPHIR_INIT_NVAR(&_29$$20);
				ZVAL_LONG(&_29$$20, 13);
				zephir_array_update_string(&definition, SL("type"), &_29$$20, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (zephir_memnstr_str(&columnType, SL("blob"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 251)) {
				ZEPHIR_INIT_NVAR(&_30$$21);
				ZVAL_LONG(&_30$$21, 11);
				zephir_array_update_string(&definition, SL("type"), &_30$$21, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_INIT_NVAR(&_31$$22);
				ZVAL_LONG(&_31$$22, 2);
				zephir_array_update_string(&definition, SL("type"), &_31$$22, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 265)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				ZEPHIR_INIT_NVAR(&_32$$23);
				zephir_preg_match(&_32$$23, &sizePattern, &columnType, &matches, 0, 0 , 0 );
				if (zephir_is_true(&_32$$23)) {
					ZEPHIR_OBS_NVAR(&matchOne);
					_33$$24 = zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_33$$24) {
						ZEPHIR_INIT_NVAR(&_34$$25);
						ZVAL_LONG(&_34$$25, zephir_get_intval(&matchOne));
						zephir_array_update_string(&definition, SL("size"), &_34$$25, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_OBS_NVAR(&matchTwo);
					_35$$24 = zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_35$$24) {
						ZEPHIR_INIT_NVAR(&_36$$26);
						ZVAL_LONG(&_36$$26, zephir_get_intval(&matchTwo));
						zephir_array_update_string(&definition, SL("scale"), &_36$$26, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			}
			if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 281)) {
				zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			if (Z_TYPE_P(&oldColumn) == IS_NULL) {
				zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&_37$$3);
			zephir_array_fetch_long(&_37$$3, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 297);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_true(&_37$$3)) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&_38$$3);
			zephir_array_fetch_long(&_38$$3, &field, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 304);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_LONG(&_38$$3, 0)) {
				zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			hiddenFlag = 0;
			_39$$3 = zephir_array_isset_value_long(&field, 6);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_39$$3) {
				ZEPHIR_OBS_NVAR(&_40$$32);
				zephir_array_fetch_long(&_40$$32, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 317);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				hiddenFlag = zephir_get_intval(&_40$$32);
			}
			_41$$3 = hiddenFlag == 2;
			if (!(_41$$3)) {
				_41$$3 = hiddenFlag == 3;
			}
			if (_41$$3) {
				ZEPHIR_INIT_NVAR(&_42$$33);
				ZVAL_STRING(&_42$$33, "");
				zephir_array_update_string(&definition, SL("generated"), &_42$$33, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_43$$33);
				ZVAL_BOOL(&_43$$33, (hiddenFlag == 3));
				zephir_array_update_string(&definition, SL("generationStored"), &_43$$33, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				_44$$34 = zephir_isempty_dim_long(&field, 4);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_45$$34 = !(_44$$34);
				if (_45$$34) {
					ZEPHIR_OBS_NVAR(&_46$$34);
					zephir_array_fetch_long(&_46$$34, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 328);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_47$$34);
					ZVAL_STRING(&_47$$34, "null");
					ZEPHIR_CALL_FUNCTION(&_48$$34, "strcasecmp", &_49, 35, &_46$$34, &_47$$34);
					zephir_check_call_status();
					_45$$34 = !ZEPHIR_IS_LONG_IDENTICAL(&_48$$34, 0);
				}
				if (_45$$34) {
					ZEPHIR_OBS_NVAR(&_50$$35);
					zephir_array_fetch_long(&_50$$35, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 333);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_51$$35);
					ZVAL_STRING(&_51$$35, "/(?:^')|(?:'$)/");
					ZEPHIR_INIT_NVAR(&_52$$35);
					ZVAL_STRING(&_52$$35, "");
					ZEPHIR_CALL_FUNCTION(&_53$$35, "preg_replace", &_54, 2, &_51$$35, &_52$$35, &_50$$35);
					zephir_check_call_status();
					zephir_array_update_string(&definition, SL("default"), &_53$$35, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			ZEPHIR_OBS_NVAR(&columnName);
			zephir_array_fetch_long(&columnName, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 340);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_6$$3);
			object_init_ex(&_6$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD_CACHED(NULL, &_6$$3, "__construct", &_zephir_call_cache[2], &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_6$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 341);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "rewind", &_zephir_call_cache[3]);
		zephir_check_call_status();
		_56 = 1;
		while (1) {
			if (_56) {
				_56 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _3, "next", &_zephir_call_cache[4]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_55, _3, "valid", &_zephir_call_cache[5]);
			zephir_check_call_status();
			if (!zend_is_true(&_55)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&field, _3, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_57$$36);
				zephir_create_array(&_57$$36, 1, 0);
				add_assoc_long_ex(&_57$$36, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_57$$36);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 122);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_58$$36);
				zephir_fast_strtolower(&_58$$36, &columnType);
				ZEPHIR_CPY_WRT(&columnType, &_58$$36);
				if (zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 138)) {
					ZEPHIR_INIT_NVAR(&_59$$37);
					ZVAL_LONG(&_59$$37, 14);
					zephir_array_update_string(&definition, SL("type"), &_59$$37, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_60$$37);
					ZVAL_LONG(&_60$$37, 2);
					zephir_array_update_string(&definition, SL("bindType"), &_60$$37, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("tinyint(1)"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 145)) {
					ZEPHIR_INIT_NVAR(&_61$$38);
					ZVAL_LONG(&_61$$38, 8);
					zephir_array_update_string(&definition, SL("type"), &_61$$38, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_62$$38);
					ZVAL_LONG(&_62$$38, 5);
					zephir_array_update_string(&definition, SL("bindType"), &_62$$38, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&columnType);
					ZVAL_STRING(&columnType, "boolean");
				} else if (zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 152)) {
					ZEPHIR_INIT_NVAR(&_63$$39);
					ZVAL_LONG(&_63$$39, 0);
					zephir_array_update_string(&definition, SL("type"), &_63$$39, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_64$$39);
					ZVAL_LONG(&_64$$39, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_64$$39, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&_65$$39);
					zephir_array_fetch_long(&_65$$39, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 160);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (zephir_is_true(&_65$$39)) {
						zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else if (zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 167)) {
					ZEPHIR_INIT_NVAR(&_66$$41);
					ZVAL_LONG(&_66$$41, 5);
					zephir_array_update_string(&definition, SL("type"), &_66$$41, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 176)) {
					ZEPHIR_INIT_NVAR(&_67$$42);
					ZVAL_LONG(&_67$$42, 4);
					zephir_array_update_string(&definition, SL("type"), &_67$$42, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 181)) {
					ZEPHIR_INIT_NVAR(&_68$$43);
					ZVAL_LONG(&_68$$43, 1);
					zephir_array_update_string(&definition, SL("type"), &_68$$43, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 190)) {
					ZEPHIR_INIT_NVAR(&_69$$44);
					ZVAL_LONG(&_69$$44, 3);
					zephir_array_update_string(&definition, SL("type"), &_69$$44, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_70$$44);
					ZVAL_LONG(&_70$$44, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_70$$44, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 197)) {
					ZEPHIR_INIT_NVAR(&_71$$45);
					ZVAL_LONG(&_71$$45, 7);
					zephir_array_update_string(&definition, SL("type"), &_71$$45, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_72$$45);
					ZVAL_LONG(&_72$$45, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_72$$45, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("real"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 204)) {
					ZEPHIR_INIT_NVAR(&_73$$46);
					ZVAL_LONG(&_73$$46, 7);
					zephir_array_update_string(&definition, SL("type"), &_73$$46, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_74$$46);
					ZVAL_LONG(&_74$$46, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_74$$46, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 215)) {
					ZEPHIR_INIT_NVAR(&_75$$47);
					ZVAL_LONG(&_75$$47, 17);
					zephir_array_update_string(&definition, SL("type"), &_75$$47, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 224)) {
					ZEPHIR_INIT_NVAR(&_76$$48);
					ZVAL_LONG(&_76$$48, 2);
					zephir_array_update_string(&definition, SL("type"), &_76$$48, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 229)) {
					ZEPHIR_INIT_NVAR(&_77$$49);
					ZVAL_LONG(&_77$$49, 5);
					zephir_array_update_string(&definition, SL("type"), &_77$$49, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 234)) {
					ZEPHIR_INIT_NVAR(&_78$$50);
					ZVAL_LONG(&_78$$50, 6);
					zephir_array_update_string(&definition, SL("type"), &_78$$50, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 245)) {
					ZEPHIR_INIT_NVAR(&_79$$51);
					ZVAL_LONG(&_79$$51, 10);
					zephir_array_update_string(&definition, SL("type"), &_79$$51, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 247)) {
					ZEPHIR_INIT_NVAR(&_80$$52);
					ZVAL_LONG(&_80$$52, 12);
					zephir_array_update_string(&definition, SL("type"), &_80$$52, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 249)) {
					ZEPHIR_INIT_NVAR(&_81$$53);
					ZVAL_LONG(&_81$$53, 13);
					zephir_array_update_string(&definition, SL("type"), &_81$$53, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (zephir_memnstr_str(&columnType, SL("blob"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 251)) {
					ZEPHIR_INIT_NVAR(&_82$$54);
					ZVAL_LONG(&_82$$54, 11);
					zephir_array_update_string(&definition, SL("type"), &_82$$54, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_83$$55);
					ZVAL_LONG(&_83$$55, 2);
					zephir_array_update_string(&definition, SL("type"), &_83$$55, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 265)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					ZEPHIR_INIT_NVAR(&_84$$56);
					zephir_preg_match(&_84$$56, &sizePattern, &columnType, &matches, 0, 0 , 0 );
					if (zephir_is_true(&_84$$56)) {
						ZEPHIR_OBS_NVAR(&matchOne);
						_85$$57 = zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_85$$57) {
							ZEPHIR_INIT_NVAR(&_86$$58);
							ZVAL_LONG(&_86$$58, zephir_get_intval(&matchOne));
							zephir_array_update_string(&definition, SL("size"), &_86$$58, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						ZEPHIR_OBS_NVAR(&matchTwo);
						_87$$57 = zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_87$$57) {
							ZEPHIR_INIT_NVAR(&_88$$59);
							ZVAL_LONG(&_88$$59, zephir_get_intval(&matchTwo));
							zephir_array_update_string(&definition, SL("scale"), &_88$$59, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				}
				if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 281)) {
					zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				if (Z_TYPE_P(&oldColumn) == IS_NULL) {
					zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&_89$$36);
				zephir_array_fetch_long(&_89$$36, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 297);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&_89$$36)) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&_90$$36);
				zephir_array_fetch_long(&_90$$36, &field, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 304);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&_90$$36, 0)) {
					zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				hiddenFlag = 0;
				_91$$36 = zephir_array_isset_value_long(&field, 6);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_91$$36) {
					ZEPHIR_OBS_NVAR(&_92$$65);
					zephir_array_fetch_long(&_92$$65, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 317);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					hiddenFlag = zephir_get_intval(&_92$$65);
				}
				_93$$36 = hiddenFlag == 2;
				if (!(_93$$36)) {
					_93$$36 = hiddenFlag == 3;
				}
				if (_93$$36) {
					ZEPHIR_INIT_NVAR(&_94$$66);
					ZVAL_STRING(&_94$$66, "");
					zephir_array_update_string(&definition, SL("generated"), &_94$$66, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_95$$66);
					ZVAL_BOOL(&_95$$66, (hiddenFlag == 3));
					zephir_array_update_string(&definition, SL("generationStored"), &_95$$66, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					_96$$67 = zephir_isempty_dim_long(&field, 4);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_97$$67 = !(_96$$67);
					if (_97$$67) {
						ZEPHIR_OBS_NVAR(&_98$$67);
						zephir_array_fetch_long(&_98$$67, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 328);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_99$$67);
						ZVAL_STRING(&_99$$67, "null");
						ZEPHIR_CALL_FUNCTION(&_100$$67, "strcasecmp", &_49, 35, &_98$$67, &_99$$67);
						zephir_check_call_status();
						_97$$67 = !ZEPHIR_IS_LONG_IDENTICAL(&_100$$67, 0);
					}
					if (_97$$67) {
						ZEPHIR_OBS_NVAR(&_101$$68);
						zephir_array_fetch_long(&_101$$68, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 333);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_102$$68);
						ZVAL_STRING(&_102$$68, "/(?:^')|(?:'$)/");
						ZEPHIR_INIT_NVAR(&_103$$68);
						ZVAL_STRING(&_103$$68, "");
						ZEPHIR_CALL_FUNCTION(&_104$$68, "preg_replace", &_54, 2, &_102$$68, &_103$$68, &_101$$68);
						zephir_check_call_status();
						zephir_array_update_string(&definition, SL("default"), &_104$$68, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 340);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_58$$36);
				object_init_ex(&_58$$36, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD_CACHED(NULL, &_58$$36, "__construct", &_zephir_call_cache[7], &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_58$$36, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 341);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	RETURN_CCTOR(&columns);
}

/**
 * Lists table indexes
 *
 * ```php
 * print_r(
 *     $connection->describeIndexes("co_orders_x_products")
 * );
 * ```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes)
{
	zend_ulong _60;
	zend_bool _32, _7$$3, _10$$3, _20$$3, _33$$13, _36$$13, _46$$13;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, indexes, index, keyName, indexObjects, name, columns, describeIndexes, describeIndex, indexSql, _0, _1, _2, _3, *_4, _5, *_6, _31, *_57, _58, *_59, _9$$3, _12$$3, _13$$3, _14$$3, *_15$$3, _16$$3, *_17$$3, _19$$3, _22$$3, _23$$3, _8$$4, _11$$6, _18$$7, _21$$8, _24$$9, _25$$9, _26$$9, _27$$9, _28$$10, _29$$11, _30$$12, _35$$13, _38$$13, _39$$13, _40$$13, *_41$$13, _42$$13, *_43$$13, _45$$13, _48$$13, _49$$13, _34$$14, _37$$16, _44$$17, _47$$18, _50$$19, _51$$19, _52$$19, _53$$19, _54$$20, _55$$21, _56$$22, _62$$23, _63$$23, _64$$23;
	zend_string *table = NULL, *schema = NULL, *_61;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&indexObjects);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&describeIndexes);
	ZVAL_UNDEF(&describeIndex);
	ZVAL_UNDEF(&indexSql);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_58);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_22$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_24$$9);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_28$$10);
	ZVAL_UNDEF(&_29$$11);
	ZVAL_UNDEF(&_30$$12);
	ZVAL_UNDEF(&_35$$13);
	ZVAL_UNDEF(&_38$$13);
	ZVAL_UNDEF(&_39$$13);
	ZVAL_UNDEF(&_40$$13);
	ZVAL_UNDEF(&_42$$13);
	ZVAL_UNDEF(&_45$$13);
	ZVAL_UNDEF(&_48$$13);
	ZVAL_UNDEF(&_49$$13);
	ZVAL_UNDEF(&_34$$14);
	ZVAL_UNDEF(&_37$$16);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_47$$18);
	ZVAL_UNDEF(&_50$$19);
	ZVAL_UNDEF(&_51$$19);
	ZVAL_UNDEF(&_52$$19);
	ZVAL_UNDEF(&_53$$19);
	ZVAL_UNDEF(&_54$$20);
	ZVAL_UNDEF(&_55$$21);
	ZVAL_UNDEF(&_56$$22);
	ZVAL_UNDEF(&_62$$23);
	ZVAL_UNDEF(&_63$$23);
	ZVAL_UNDEF(&_64$$23);
	ZEND_TLS zephir_method_cache _zephir_call_cache[23];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
		zephir_memory_observe(&schema_zv);
	ZVAL_STR_COPY(&schema_zv, schema);
	}
	ZEPHIR_INIT_VAR(&indexes);
	array_init(&indexes);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 615, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, &_1, "describeIndexes", &_zephir_call_cache[0], &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "fetchAll", &_zephir_call_cache[1], &_2, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &_0);
		_4 = &_5;
	} else {
		_4 = &_0;
	}
	zephir_is_iterable(_4, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 403);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4), _6)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _6);
			ZEPHIR_OBS_NVAR(&keyName);
			zephir_array_fetch_string(&keyName, &index, SL("name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 365);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_7$$3 = zephir_array_isset_value(&indexes, &keyName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_7$$3)) {
				ZEPHIR_INIT_NVAR(&_8$$4);
				array_init(&_8$$4);
				zephir_array_update_zval(&indexes, &keyName, &_8$$4, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_array_fetch(&_9$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 371);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_10$$3 = zephir_array_isset_value_string(&_9$$3, SL("columns"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_10$$3)) {
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
			} else {
				zephir_array_fetch(&_11$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 374);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_11$$6, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 374);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_read_property_cached(&_12$$3, this_ptr, _zephir_prop_0, 615, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_13$$3, &_12$$3, "describeIndex", &_zephir_call_cache[2], &keyName);
			zephir_check_call_status();
			ZVAL_LONG(&_14$$3, 2);
			ZEPHIR_CALL_METHOD_CACHED(&describeIndexes, this_ptr, "fetchAll", &_zephir_call_cache[3], &_13$$3, &_14$$3);
			zephir_check_call_status();
			if (Z_TYPE_P(&describeIndexes) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_16$$3);
				zephir_string_to_char_array(&_16$$3, &describeIndexes);
				_15$$3 = &_16$$3;
			} else {
				_15$$3 = &describeIndexes;
			}
			zephir_is_iterable(_15$$3, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 386);
			if (Z_TYPE_P(_15$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_15$$3), _17$$3)
				{
					ZEPHIR_INIT_NVAR(&describeIndex);
					ZVAL_COPY(&describeIndex, _17$$3);
					ZEPHIR_OBS_NVAR(&_18$$7);
					zephir_array_fetch_string(&_18$$7, &describeIndex, SL("name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 383);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_append(&columns, &_18$$7, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 383);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _15$$3, "rewind", &_zephir_call_cache[4]);
				zephir_check_call_status();
				_20$$3 = 1;
				while (1) {
					if (_20$$3) {
						_20$$3 = 0;
					} else {
						ZEPHIR_CALL_METHOD_CACHED(NULL, _15$$3, "next", &_zephir_call_cache[5]);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD_CACHED(&_19$$3, _15$$3, "valid", &_zephir_call_cache[6]);
					zephir_check_call_status();
					if (!zend_is_true(&_19$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD_CACHED(&describeIndex, _15$$3, "current", &_zephir_call_cache[7]);
					zephir_check_call_status();
						ZEPHIR_OBS_NVAR(&_21$$8);
						zephir_array_fetch_string(&_21$$8, &describeIndex, SL("name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 383);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&columns, &_21$$8, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 383);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
				}
			}
			ZEPHIR_INIT_NVAR(&describeIndex);
			zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_read_property_cached(&_14$$3, this_ptr, _zephir_prop_0, 615, PH_NOISY_CC | PH_READONLY);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD_CACHED(&_22$$3, &_14$$3, "listIndexesSql", &_zephir_call_cache[8], &table_zv, &schema_zv, &keyName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&indexSql, this_ptr, "fetchColumn", &_zephir_call_cache[9], &_22$$3);
			zephir_check_call_status();
			ZEPHIR_OBS_NVAR(&_23$$3);
			zephir_array_fetch_string(&_23$$3, &index, SL("unique"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 392);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (zephir_is_true(&_23$$3)) {
				ZEPHIR_INIT_NVAR(&_24$$9);
				ZEPHIR_INIT_NVAR(&_25$$9);
				ZVAL_STRING(&_25$$9, "# UNIQUE #i");
				ZEPHIR_INIT_NVAR(&_26$$9);
				ZEPHIR_INIT_NVAR(&_27$$9);
				ZVAL_STRING(&_27$$9, "# UNIQUE #i");
				zephir_preg_match(&_26$$9, &_27$$9, &indexSql, &_24$$9, 0, 0 , 0 );
				if (zephir_is_true(&_26$$9)) {
					ZEPHIR_INIT_NVAR(&_28$$10);
					ZVAL_STRING(&_28$$10, "UNIQUE");
					zephir_array_update_multi(&indexes, &_28$$10, SL("zs"), 3, &keyName, SL("type"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_29$$11);
					ZVAL_STRING(&_29$$11, "PRIMARY");
					zephir_array_update_multi(&indexes, &_29$$11, SL("zs"), 3, &keyName, SL("type"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			} else {
				ZEPHIR_INIT_NVAR(&_30$$12);
				ZVAL_STRING(&_30$$12, "");
				zephir_array_update_multi(&indexes, &_30$$12, SL("zs"), 3, &keyName, SL("type"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _4, "rewind", &_zephir_call_cache[10]);
		zephir_check_call_status();
		_32 = 1;
		while (1) {
			if (_32) {
				_32 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _4, "next", &_zephir_call_cache[11]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_31, _4, "valid", &_zephir_call_cache[12]);
			zephir_check_call_status();
			if (!zend_is_true(&_31)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&index, _4, "current", &_zephir_call_cache[13]);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&keyName);
				zephir_array_fetch_string(&keyName, &index, SL("name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 365);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_33$$13 = zephir_array_isset_value(&indexes, &keyName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_33$$13)) {
					ZEPHIR_INIT_NVAR(&_34$$14);
					array_init(&_34$$14);
					zephir_array_update_zval(&indexes, &keyName, &_34$$14, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_fetch(&_35$$13, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 371);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_36$$13 = zephir_array_isset_value_string(&_35$$13, SL("columns"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_36$$13)) {
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
				} else {
					zephir_array_fetch(&_37$$16, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 374);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_37$$16, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 374);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_read_property_cached(&_38$$13, this_ptr, _zephir_prop_0, 615, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_39$$13, &_38$$13, "describeIndex", &_zephir_call_cache[14], &keyName);
				zephir_check_call_status();
				ZVAL_LONG(&_40$$13, 2);
				ZEPHIR_CALL_METHOD_CACHED(&describeIndexes, this_ptr, "fetchAll", &_zephir_call_cache[15], &_39$$13, &_40$$13);
				zephir_check_call_status();
				if (Z_TYPE_P(&describeIndexes) == IS_STRING) {
					ZEPHIR_INIT_NVAR(&_42$$13);
					zephir_string_to_char_array(&_42$$13, &describeIndexes);
					_41$$13 = &_42$$13;
				} else {
					_41$$13 = &describeIndexes;
				}
				zephir_is_iterable(_41$$13, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 386);
				if (Z_TYPE_P(_41$$13) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_41$$13), _43$$13)
					{
						ZEPHIR_INIT_NVAR(&describeIndex);
						ZVAL_COPY(&describeIndex, _43$$13);
						ZEPHIR_OBS_NVAR(&_44$$17);
						zephir_array_fetch_string(&_44$$17, &describeIndex, SL("name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 383);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_append(&columns, &_44$$17, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 383);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD_CACHED(NULL, _41$$13, "rewind", &_zephir_call_cache[16]);
					zephir_check_call_status();
					_46$$13 = 1;
					while (1) {
						if (_46$$13) {
							_46$$13 = 0;
						} else {
							ZEPHIR_CALL_METHOD_CACHED(NULL, _41$$13, "next", &_zephir_call_cache[17]);
							zephir_check_call_status();
						}
						ZEPHIR_CALL_METHOD_CACHED(&_45$$13, _41$$13, "valid", &_zephir_call_cache[18]);
						zephir_check_call_status();
						if (!zend_is_true(&_45$$13)) {
							break;
						}
						ZEPHIR_CALL_METHOD_CACHED(&describeIndex, _41$$13, "current", &_zephir_call_cache[19]);
						zephir_check_call_status();
							ZEPHIR_OBS_NVAR(&_47$$18);
							zephir_array_fetch_string(&_47$$18, &describeIndex, SL("name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 383);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_append(&columns, &_47$$18, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 383);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
					}
				}
				ZEPHIR_INIT_NVAR(&describeIndex);
				zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_read_property_cached(&_40$$13, this_ptr, _zephir_prop_0, 615, PH_NOISY_CC | PH_READONLY);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CALL_METHOD_CACHED(&_48$$13, &_40$$13, "listIndexesSql", &_zephir_call_cache[20], &table_zv, &schema_zv, &keyName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(&indexSql, this_ptr, "fetchColumn", &_zephir_call_cache[21], &_48$$13);
				zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&_49$$13);
				zephir_array_fetch_string(&_49$$13, &index, SL("unique"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 392);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (zephir_is_true(&_49$$13)) {
					ZEPHIR_INIT_NVAR(&_50$$19);
					ZEPHIR_INIT_NVAR(&_51$$19);
					ZVAL_STRING(&_51$$19, "# UNIQUE #i");
					ZEPHIR_INIT_NVAR(&_52$$19);
					ZEPHIR_INIT_NVAR(&_53$$19);
					ZVAL_STRING(&_53$$19, "# UNIQUE #i");
					zephir_preg_match(&_52$$19, &_53$$19, &indexSql, &_50$$19, 0, 0 , 0 );
					if (zephir_is_true(&_52$$19)) {
						ZEPHIR_INIT_NVAR(&_54$$20);
						ZVAL_STRING(&_54$$20, "UNIQUE");
						zephir_array_update_multi(&indexes, &_54$$20, SL("zs"), 3, &keyName, SL("type"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_55$$21);
						ZVAL_STRING(&_55$$21, "PRIMARY");
						zephir_array_update_multi(&indexes, &_55$$21, SL("zs"), 3, &keyName, SL("type"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					ZEPHIR_INIT_NVAR(&_56$$22);
					ZVAL_STRING(&_56$$22, "");
					zephir_array_update_multi(&indexes, &_56$$22, SL("zs"), 3, &keyName, SL("type"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	if (Z_TYPE_P(&indexes) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_58);
		zephir_string_to_char_array(&_58, &indexes);
		_57 = &_58;
	} else {
		_57 = &indexes;
	}
	zephir_is_iterable(_57, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 413);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_57), _60, _61, _59)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_61 != NULL) { 
			ZVAL_STR_COPY(&name, _61);
		} else {
			ZVAL_LONG(&name, _60);
		}
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_COPY(&index, _59);
		ZEPHIR_INIT_NVAR(&_62$$23);
		object_init_ex(&_62$$23, phalcon_db_index_ce);
		ZEPHIR_OBS_NVAR(&_63$$23);
		zephir_array_fetch_string(&_63$$23, &index, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 408);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_OBS_NVAR(&_64$$23);
		zephir_array_fetch_string(&_64$$23, &index, SL("type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 410);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_62$$23, "__construct", &_zephir_call_cache[22], &name, &_63$$23, &_64$$23);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, &name, &_62$$23, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&indexObjects);
}

/**
 * Lists table references
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeReferences)
{
	zval _16$$3, _26$$6, _33$$9;
	zend_bool _18, _9$$3, _19$$6;
	zend_ulong _7, _30;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, number, _0, _1, _2, _3, *_4, _5, *_6, _17, *_27, _28, *_29, _14$$3, _15$$3, _10$$5, _11$$5, _12$$5, _13$$5, _24$$6, _25$$6, _20$$8, _21$$8, _22$$8, _23$$8, _32$$9, _34$$9;
	zend_string *table = NULL, *schema = NULL, *_8, *_31;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_28);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_33$$9);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&table_zv);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
		zephir_memory_observe(&schema_zv);
	ZVAL_STR_COPY(&schema_zv, schema);
	}
	ZEPHIR_INIT_VAR(&references);
	array_init(&references);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 615, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_2, &_1, "describeReferences", &_zephir_call_cache[0], &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "fetchAll", &_zephir_call_cache[1], &_2, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &_0);
		_4 = &_5;
	} else {
		_4 = &_0;
	}
	zephir_is_iterable(_4, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 453);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_4), _7, _8, _6)
		{
			ZEPHIR_INIT_NVAR(&number);
			if (_8 != NULL) { 
				ZVAL_STR_COPY(&number, _8);
			} else {
				ZVAL_LONG(&number, _7);
			}
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _6);
			ZEPHIR_INIT_NVAR(&constraintName);
			ZEPHIR_CONCAT_SV(&constraintName, "foreign_key_", &number);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_9$$3 = zephir_array_isset_value(&references, &constraintName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_9$$3)) {
				ZEPHIR_INIT_NVAR(&referencedSchema);
				ZVAL_NULL(&referencedSchema);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 432);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 436);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_10$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 436);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_11$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 437);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_11$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 437);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_12$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 438);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_12$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 438);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_13$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 439);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_13$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 439);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&_14$$3);
			zephir_array_fetch_long(&_14$$3, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 442);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&columns, &_14$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 442);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_15$$3);
			zephir_array_fetch_long(&_15$$3, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 443);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&referencedColumns, &_15$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 443);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_16$$3);
			zephir_create_array(&_16$$3, 4, 0);
			zephir_array_update_string(&_16$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&references, &constraintName, &_16$$3, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, _4, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, _4, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_17, _4, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&number, _4, "key", &_zephir_call_cache[5]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&reference, _4, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&constraintName);
				ZEPHIR_CONCAT_SV(&constraintName, "foreign_key_", &number);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_19$$6 = zephir_array_isset_value(&references, &constraintName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_19$$6)) {
					ZEPHIR_INIT_NVAR(&referencedSchema);
					ZVAL_NULL(&referencedSchema);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 432);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 436);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_20$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 436);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_21$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 437);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_21$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 437);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_22$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 438);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_22$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 438);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_23$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 439);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_23$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 439);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&_24$$6);
				zephir_array_fetch_long(&_24$$6, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 442);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&columns, &_24$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 442);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_25$$6);
				zephir_array_fetch_long(&_25$$6, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 443);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&referencedColumns, &_25$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 443);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_26$$6);
				zephir_create_array(&_26$$6, 4, 0);
				zephir_array_update_string(&_26$$6, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_26$$6, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_26$$6, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_26$$6, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&references, &constraintName, &_26$$6, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&reference);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_INIT_VAR(&referenceObjects);
	array_init(&referenceObjects);
	if (Z_TYPE_P(&references) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_28);
		zephir_string_to_char_array(&_28, &references);
		_27 = &_28;
	} else {
		_27 = &references;
	}
	zephir_is_iterable(_27, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 467);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_27), _30, _31, _29)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_31 != NULL) { 
			ZVAL_STR_COPY(&name, _31);
		} else {
			ZVAL_LONG(&name, _30);
		}
		ZEPHIR_INIT_NVAR(&arrayReference);
		ZVAL_COPY(&arrayReference, _29);
		ZEPHIR_INIT_NVAR(&_32$$9);
		object_init_ex(&_32$$9, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(&_33$$9);
		zephir_create_array(&_33$$9, 4, 0);
		ZEPHIR_OBS_NVAR(&_34$$9);
		zephir_array_fetch_string(&_34$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 459);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_33$$9, SL("referencedSchema"), &_34$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_34$$9);
		zephir_array_fetch_string(&_34$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 460);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_33$$9, SL("referencedTable"), &_34$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_34$$9);
		zephir_array_fetch_string(&_34$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 461);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_33$$9, SL("columns"), &_34$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_34$$9);
		zephir_array_fetch_string(&_34$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 463);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_33$$9, SL("referencedColumns"), &_34$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_32$$9, "__construct", &_zephir_call_cache[7], &name, &_33$$9);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_32$$9, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&referenceObjects);
}

/**
 * Returns the default value to make the RBDM use the default value declared
 * in the table definition
 *
 *```php
 * // Inserting a new invoice with a valid default value for the column 'inv_total'
 * $success = $connection->insert(
 *     "co_invoices",
 *     [
 *         "Test Invoice",
 *         $connection->getDefaultValue(),
 *     ],
 *     [
 *         "inv_title",
 *         "inv_total",
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, getDefaultValue)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "NULL");
	ZEPHIR_CALL_METHOD_CACHED(NULL, return_value, "__construct", &_zephir_call_cache[0], &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Check whether the database system requires an explicit value for identity
 * columns
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, useExplicitIdValue)
{

	RETURN_BOOL(1);
}

/**
 * SQLite does not support the DEFAULT keyword
 *
 * @deprecated Will re removed in the next version
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, supportsDefaultValue)
{

	RETURN_BOOL(0);
}

/**
 * Returns PDO adapter DSN defaults as a key-value map.
 *
 * @phpstan-return db_dsn_defaults
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, getDsnDefaults)
{

	array_init(return_value);
	return;
}

