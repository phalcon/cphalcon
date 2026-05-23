
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
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Sqlite)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Sqlite, phalcon, db_adapter_pdo_sqlite, phalcon_db_adapter_pdo_abstractpdo_ce, phalcon_db_adapter_pdo_sqlite_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_adapter_pdo_sqlite_ce, SL("dialectType"), "sqlite", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_adapter_pdo_sqlite_ce, SL("type"), "sqlite", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor for Phalcon\Db\Adapter\Pdo\Sqlite
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, _0$$3;
	zval descriptor;

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&_0$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(descriptor, descriptor_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &descriptor_param);
	ZEPHIR_OBS_COPY_OR_DUP(&descriptor, descriptor_param);
	if (zephir_array_isset_value_string(&descriptor, SL("charset"))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "SQLite does not allow the charset to be changed in the DSN.");
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 14, &_0$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_sqlite_ce, getThis(), "__construct", NULL, 0, &descriptor);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo
 * constructor. Call it when you need to restore a database connection.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, connect)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, dbname, _0$$3, _1$$5;
	zval descriptor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&dbname);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$5);
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
	ZEPHIR_OBS_COPY_OR_DUP(&descriptor, descriptor_param);
	}
	if (ZEPHIR_IS_EMPTY(&descriptor)) {
		zephir_read_property(&_0$$3, this_ptr, ZEND_STRL("descriptor"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CPY_WRT(&descriptor, &_0$$3);
	}
	zephir_memory_observe(&dbname);
	if (zephir_array_isset_string_fetch(&dbname, &descriptor, SL("dbname"), 0)) {
		zephir_array_update_string(&descriptor, SL("dsn"), &dbname, PH_COPY | PH_SEPARATE);
		zephir_array_unset_string(&descriptor, SL("dbname"), PH_SEPARATE);
	} else if (UNEXPECTED(!(zephir_array_isset_value_string(&descriptor, SL("dsn"))))) {
		ZEPHIR_INIT_VAR(&_1$$5);
		object_init_ex(&_1$$5, phalcon_db_exceptions_missingsqlitedatabase_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$5, "__construct", NULL, 338);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$5, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 81);
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_sqlite_ce, getThis(), "connect", NULL, 0, &descriptor);
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
	zend_bool _32$$3, _36$$30, _77$$32, _81$$59;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_40 = NULL, *_45 = NULL, *_46 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, hiddenFlag = 0;
	zval table_zv, schema_zv, __$true, __$false, columns, columnType, fields, field, definition, oldColumn, sizePattern, matches, matchOne, matchTwo, columnName, _0, _1, _2, *_3, _47, _4$$3, _29$$3, _30$$3, _5$$4, _6$$4, _7$$5, _8$$5, _9$$5, _10$$7, _11$$7, _12$$8, _13$$9, _14$$10, _15$$11, _16$$11, _17$$12, _18$$12, _19$$13, _20$$13, _21$$14, _22$$15, _23$$16, _24$$17, _25$$18, _26$$19, _27$$21, _28$$22, _31$$28, _33$$29, _34$$29, _35$$30, _37$$30, _38$$30, _39$$30, _41$$31, _42$$31, _43$$31, _44$$31, _48$$32, _49$$32, _74$$32, _75$$32, _50$$33, _51$$33, _52$$34, _53$$34, _54$$34, _55$$36, _56$$36, _57$$37, _58$$38, _59$$39, _60$$40, _61$$40, _62$$41, _63$$41, _64$$42, _65$$42, _66$$43, _67$$44, _68$$45, _69$$46, _70$$47, _71$$48, _72$$50, _73$$51, _76$$57, _78$$58, _79$$58, _80$$59, _82$$59, _83$$59, _84$$59, _85$$60, _86$$60, _87$$60, _88$$60;
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
	ZVAL_UNDEF(&_47);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_29$$3);
	ZVAL_UNDEF(&_30$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$10);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$12);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_23$$16);
	ZVAL_UNDEF(&_24$$17);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_27$$21);
	ZVAL_UNDEF(&_28$$22);
	ZVAL_UNDEF(&_31$$28);
	ZVAL_UNDEF(&_33$$29);
	ZVAL_UNDEF(&_34$$29);
	ZVAL_UNDEF(&_35$$30);
	ZVAL_UNDEF(&_37$$30);
	ZVAL_UNDEF(&_38$$30);
	ZVAL_UNDEF(&_39$$30);
	ZVAL_UNDEF(&_41$$31);
	ZVAL_UNDEF(&_42$$31);
	ZVAL_UNDEF(&_43$$31);
	ZVAL_UNDEF(&_44$$31);
	ZVAL_UNDEF(&_48$$32);
	ZVAL_UNDEF(&_49$$32);
	ZVAL_UNDEF(&_74$$32);
	ZVAL_UNDEF(&_75$$32);
	ZVAL_UNDEF(&_50$$33);
	ZVAL_UNDEF(&_51$$33);
	ZVAL_UNDEF(&_52$$34);
	ZVAL_UNDEF(&_53$$34);
	ZVAL_UNDEF(&_54$$34);
	ZVAL_UNDEF(&_55$$36);
	ZVAL_UNDEF(&_56$$36);
	ZVAL_UNDEF(&_57$$37);
	ZVAL_UNDEF(&_58$$38);
	ZVAL_UNDEF(&_59$$39);
	ZVAL_UNDEF(&_60$$40);
	ZVAL_UNDEF(&_61$$40);
	ZVAL_UNDEF(&_62$$41);
	ZVAL_UNDEF(&_63$$41);
	ZVAL_UNDEF(&_64$$42);
	ZVAL_UNDEF(&_65$$42);
	ZVAL_UNDEF(&_66$$43);
	ZVAL_UNDEF(&_67$$44);
	ZVAL_UNDEF(&_68$$45);
	ZVAL_UNDEF(&_69$$46);
	ZVAL_UNDEF(&_70$$47);
	ZVAL_UNDEF(&_71$$48);
	ZVAL_UNDEF(&_72$$50);
	ZVAL_UNDEF(&_73$$51);
	ZVAL_UNDEF(&_76$$57);
	ZVAL_UNDEF(&_78$$58);
	ZVAL_UNDEF(&_79$$58);
	ZVAL_UNDEF(&_80$$59);
	ZVAL_UNDEF(&_82$$59);
	ZVAL_UNDEF(&_83$$59);
	ZVAL_UNDEF(&_84$$59);
	ZVAL_UNDEF(&_85$$60);
	ZVAL_UNDEF(&_86$$60);
	ZVAL_UNDEF(&_87$$60);
	ZVAL_UNDEF(&_88$$60);
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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "describecolumns", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "fetchall", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&fields, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 335);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _3)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _3);
			ZEPHIR_INIT_NVAR(&definition);
			zephir_create_array(&definition, 1, 0);
			add_assoc_long_ex(&definition, SL("bindType"), 2);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 126);
			ZEPHIR_INIT_NVAR(&_4$$3);
			zephir_fast_strtolower(&_4$$3, &columnType);
			ZEPHIR_CPY_WRT(&columnType, &_4$$3);
			if (zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 142)) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				ZVAL_LONG(&_5$$4, 14);
				zephir_array_update_string(&definition, SL("type"), &_5$$4, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZVAL_LONG(&_6$$4, 2);
				zephir_array_update_string(&definition, SL("bindType"), &_6$$4, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 149)) {
				ZEPHIR_INIT_NVAR(&_7$$5);
				ZVAL_LONG(&_7$$5, 0);
				zephir_array_update_string(&definition, SL("type"), &_7$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZVAL_LONG(&_8$$5, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_8$$5, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_long(&_9$$5, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 157);
				if (zephir_is_true(&_9$$5)) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
			} else if (zephir_memnstr_str(&columnType, SL("tinyint(1)"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 160)) {
				ZEPHIR_INIT_NVAR(&_10$$7);
				ZVAL_LONG(&_10$$7, 8);
				zephir_array_update_string(&definition, SL("type"), &_10$$7, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_11$$7);
				ZVAL_LONG(&_11$$7, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_11$$7, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&columnType);
				ZVAL_STRING(&columnType, "boolean");
			} else if (zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 171)) {
				ZEPHIR_INIT_NVAR(&_12$$8);
				ZVAL_LONG(&_12$$8, 5);
				zephir_array_update_string(&definition, SL("type"), &_12$$8, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 180)) {
				ZEPHIR_INIT_NVAR(&_13$$9);
				ZVAL_LONG(&_13$$9, 4);
				zephir_array_update_string(&definition, SL("type"), &_13$$9, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 185)) {
				ZEPHIR_INIT_NVAR(&_14$$10);
				ZVAL_LONG(&_14$$10, 1);
				zephir_array_update_string(&definition, SL("type"), &_14$$10, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 194)) {
				ZEPHIR_INIT_NVAR(&_15$$11);
				ZVAL_LONG(&_15$$11, 3);
				zephir_array_update_string(&definition, SL("type"), &_15$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_16$$11);
				ZVAL_LONG(&_16$$11, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_16$$11, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 201)) {
				ZEPHIR_INIT_NVAR(&_17$$12);
				ZVAL_LONG(&_17$$12, 7);
				zephir_array_update_string(&definition, SL("type"), &_17$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_18$$12);
				ZVAL_LONG(&_18$$12, 3);
				zephir_array_update_string(&definition, SL("bindType"), &_18$$12, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("real"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 208)) {
				ZEPHIR_INIT_NVAR(&_19$$13);
				ZVAL_LONG(&_19$$13, 7);
				zephir_array_update_string(&definition, SL("type"), &_19$$13, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_20$$13);
				ZVAL_LONG(&_20$$13, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_20$$13, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 219)) {
				ZEPHIR_INIT_NVAR(&_21$$14);
				ZVAL_LONG(&_21$$14, 17);
				zephir_array_update_string(&definition, SL("type"), &_21$$14, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 228)) {
				ZEPHIR_INIT_NVAR(&_22$$15);
				ZVAL_LONG(&_22$$15, 2);
				zephir_array_update_string(&definition, SL("type"), &_22$$15, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 233)) {
				ZEPHIR_INIT_NVAR(&_23$$16);
				ZVAL_LONG(&_23$$16, 5);
				zephir_array_update_string(&definition, SL("type"), &_23$$16, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 238)) {
				ZEPHIR_INIT_NVAR(&_24$$17);
				ZVAL_LONG(&_24$$17, 6);
				zephir_array_update_string(&definition, SL("type"), &_24$$17, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(&_25$$18);
				ZVAL_LONG(&_25$$18, 2);
				zephir_array_update_string(&definition, SL("type"), &_25$$18, PH_COPY | PH_SEPARATE);
			}
			if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 255)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				ZEPHIR_INIT_NVAR(&_26$$19);
				zephir_preg_match(&_26$$19, &sizePattern, &columnType, &matches, 0, 0 , 0 );
				if (zephir_is_true(&_26$$19)) {
					ZEPHIR_OBS_NVAR(&matchOne);
					if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
						ZEPHIR_INIT_NVAR(&_27$$21);
						ZVAL_LONG(&_27$$21, zephir_get_intval(&matchOne));
						zephir_array_update_string(&definition, SL("size"), &_27$$21, PH_COPY | PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(&matchTwo);
					if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
						ZEPHIR_INIT_NVAR(&_28$$22);
						ZVAL_LONG(&_28$$22, zephir_get_intval(&matchTwo));
						zephir_array_update_string(&definition, SL("scale"), &_28$$22, PH_COPY | PH_SEPARATE);
					}
				}
			}
			if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 271)) {
				zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&oldColumn) == IS_NULL) {
				zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_29$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 287);
			if (zephir_is_true(&_29$$3)) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_30$$3, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 294);
			if (ZEPHIR_IS_LONG(&_30$$3, 0)) {
				zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
			}
			hiddenFlag = 0;
			if (zephir_array_isset_value_long(&field, 6)) {
				ZEPHIR_OBS_NVAR(&_31$$28);
				zephir_array_fetch_long(&_31$$28, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 307);
				hiddenFlag = zephir_get_intval(&_31$$28);
			}
			_32$$3 = hiddenFlag == 2;
			if (!(_32$$3)) {
				_32$$3 = hiddenFlag == 3;
			}
			if (_32$$3) {
				ZEPHIR_INIT_NVAR(&_33$$29);
				ZVAL_STRING(&_33$$29, "");
				zephir_array_update_string(&definition, SL("generated"), &_33$$29, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_34$$29);
				ZVAL_BOOL(&_34$$29, (hiddenFlag == 3));
				zephir_array_update_string(&definition, SL("generationStored"), &_34$$29, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_OBS_NVAR(&_35$$30);
				zephir_array_fetch_long(&_35$$30, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 318);
				_36$$30 = !(ZEPHIR_IS_EMPTY(&_35$$30));
				if (_36$$30) {
					zephir_array_fetch_long(&_37$$30, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 318);
					ZEPHIR_INIT_NVAR(&_38$$30);
					ZVAL_STRING(&_38$$30, "null");
					ZEPHIR_CALL_FUNCTION(&_39$$30, "strcasecmp", &_40, 72, &_37$$30, &_38$$30);
					zephir_check_call_status();
					_36$$30 = !ZEPHIR_IS_LONG_IDENTICAL(&_39$$30, 0);
				}
				if (_36$$30) {
					zephir_array_fetch_long(&_41$$31, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 323);
					ZEPHIR_INIT_NVAR(&_42$$31);
					ZVAL_STRING(&_42$$31, "/^'|'$/");
					ZEPHIR_INIT_NVAR(&_43$$31);
					ZVAL_STRING(&_43$$31, "");
					ZEPHIR_CALL_FUNCTION(&_44$$31, "preg_replace", &_45, 75, &_42$$31, &_43$$31, &_41$$31);
					zephir_check_call_status();
					zephir_array_update_string(&definition, SL("default"), &_44$$31, PH_COPY | PH_SEPARATE);
				}
			}
			zephir_array_fetch_long(&columnName, &field, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 330);
			ZEPHIR_INIT_NVAR(&_4$$3);
			object_init_ex(&_4$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_4$$3, "__construct", &_46, 337, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_4$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 331);
			ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_47, &fields, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_47)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_48$$32);
				zephir_create_array(&_48$$32, 1, 0);
				add_assoc_long_ex(&_48$$32, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_48$$32);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 126);
				ZEPHIR_INIT_NVAR(&_49$$32);
				zephir_fast_strtolower(&_49$$32, &columnType);
				ZEPHIR_CPY_WRT(&columnType, &_49$$32);
				if (zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 142)) {
					ZEPHIR_INIT_NVAR(&_50$$33);
					ZVAL_LONG(&_50$$33, 14);
					zephir_array_update_string(&definition, SL("type"), &_50$$33, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_51$$33);
					ZVAL_LONG(&_51$$33, 2);
					zephir_array_update_string(&definition, SL("bindType"), &_51$$33, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 149)) {
					ZEPHIR_INIT_NVAR(&_52$$34);
					ZVAL_LONG(&_52$$34, 0);
					zephir_array_update_string(&definition, SL("type"), &_52$$34, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_53$$34);
					ZVAL_LONG(&_53$$34, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_53$$34, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_long(&_54$$34, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 157);
					if (zephir_is_true(&_54$$34)) {
						zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
					}
				} else if (zephir_memnstr_str(&columnType, SL("tinyint(1)"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 160)) {
					ZEPHIR_INIT_NVAR(&_55$$36);
					ZVAL_LONG(&_55$$36, 8);
					zephir_array_update_string(&definition, SL("type"), &_55$$36, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_56$$36);
					ZVAL_LONG(&_56$$36, 5);
					zephir_array_update_string(&definition, SL("bindType"), &_56$$36, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&columnType);
					ZVAL_STRING(&columnType, "boolean");
				} else if (zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 171)) {
					ZEPHIR_INIT_NVAR(&_57$$37);
					ZVAL_LONG(&_57$$37, 5);
					zephir_array_update_string(&definition, SL("type"), &_57$$37, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 180)) {
					ZEPHIR_INIT_NVAR(&_58$$38);
					ZVAL_LONG(&_58$$38, 4);
					zephir_array_update_string(&definition, SL("type"), &_58$$38, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 185)) {
					ZEPHIR_INIT_NVAR(&_59$$39);
					ZVAL_LONG(&_59$$39, 1);
					zephir_array_update_string(&definition, SL("type"), &_59$$39, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 194)) {
					ZEPHIR_INIT_NVAR(&_60$$40);
					ZVAL_LONG(&_60$$40, 3);
					zephir_array_update_string(&definition, SL("type"), &_60$$40, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_61$$40);
					ZVAL_LONG(&_61$$40, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_61$$40, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 201)) {
					ZEPHIR_INIT_NVAR(&_62$$41);
					ZVAL_LONG(&_62$$41, 7);
					zephir_array_update_string(&definition, SL("type"), &_62$$41, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_63$$41);
					ZVAL_LONG(&_63$$41, 3);
					zephir_array_update_string(&definition, SL("bindType"), &_63$$41, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("real"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 208)) {
					ZEPHIR_INIT_NVAR(&_64$$42);
					ZVAL_LONG(&_64$$42, 7);
					zephir_array_update_string(&definition, SL("type"), &_64$$42, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_65$$42);
					ZVAL_LONG(&_65$$42, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_65$$42, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 219)) {
					ZEPHIR_INIT_NVAR(&_66$$43);
					ZVAL_LONG(&_66$$43, 17);
					zephir_array_update_string(&definition, SL("type"), &_66$$43, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 228)) {
					ZEPHIR_INIT_NVAR(&_67$$44);
					ZVAL_LONG(&_67$$44, 2);
					zephir_array_update_string(&definition, SL("type"), &_67$$44, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 233)) {
					ZEPHIR_INIT_NVAR(&_68$$45);
					ZVAL_LONG(&_68$$45, 5);
					zephir_array_update_string(&definition, SL("type"), &_68$$45, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 238)) {
					ZEPHIR_INIT_NVAR(&_69$$46);
					ZVAL_LONG(&_69$$46, 6);
					zephir_array_update_string(&definition, SL("type"), &_69$$46, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_70$$47);
					ZVAL_LONG(&_70$$47, 2);
					zephir_array_update_string(&definition, SL("type"), &_70$$47, PH_COPY | PH_SEPARATE);
				}
				if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 255)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					ZEPHIR_INIT_NVAR(&_71$$48);
					zephir_preg_match(&_71$$48, &sizePattern, &columnType, &matches, 0, 0 , 0 );
					if (zephir_is_true(&_71$$48)) {
						ZEPHIR_OBS_NVAR(&matchOne);
						if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
							ZEPHIR_INIT_NVAR(&_72$$50);
							ZVAL_LONG(&_72$$50, zephir_get_intval(&matchOne));
							zephir_array_update_string(&definition, SL("size"), &_72$$50, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&matchTwo);
						if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
							ZEPHIR_INIT_NVAR(&_73$$51);
							ZVAL_LONG(&_73$$51, zephir_get_intval(&matchTwo));
							zephir_array_update_string(&definition, SL("scale"), &_73$$51, PH_COPY | PH_SEPARATE);
						}
					}
				}
				if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 271)) {
					zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
				}
				if (Z_TYPE_P(&oldColumn) == IS_NULL) {
					zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_74$$32, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 287);
				if (zephir_is_true(&_74$$32)) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_75$$32, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 294);
				if (ZEPHIR_IS_LONG(&_75$$32, 0)) {
					zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
				}
				hiddenFlag = 0;
				if (zephir_array_isset_value_long(&field, 6)) {
					ZEPHIR_OBS_NVAR(&_76$$57);
					zephir_array_fetch_long(&_76$$57, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 307);
					hiddenFlag = zephir_get_intval(&_76$$57);
				}
				_77$$32 = hiddenFlag == 2;
				if (!(_77$$32)) {
					_77$$32 = hiddenFlag == 3;
				}
				if (_77$$32) {
					ZEPHIR_INIT_NVAR(&_78$$58);
					ZVAL_STRING(&_78$$58, "");
					zephir_array_update_string(&definition, SL("generated"), &_78$$58, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_79$$58);
					ZVAL_BOOL(&_79$$58, (hiddenFlag == 3));
					zephir_array_update_string(&definition, SL("generationStored"), &_79$$58, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_OBS_NVAR(&_80$$59);
					zephir_array_fetch_long(&_80$$59, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 318);
					_81$$59 = !(ZEPHIR_IS_EMPTY(&_80$$59));
					if (_81$$59) {
						zephir_array_fetch_long(&_82$$59, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 318);
						ZEPHIR_INIT_NVAR(&_83$$59);
						ZVAL_STRING(&_83$$59, "null");
						ZEPHIR_CALL_FUNCTION(&_84$$59, "strcasecmp", &_40, 72, &_82$$59, &_83$$59);
						zephir_check_call_status();
						_81$$59 = !ZEPHIR_IS_LONG_IDENTICAL(&_84$$59, 0);
					}
					if (_81$$59) {
						zephir_array_fetch_long(&_85$$60, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 323);
						ZEPHIR_INIT_NVAR(&_86$$60);
						ZVAL_STRING(&_86$$60, "/^'|'$/");
						ZEPHIR_INIT_NVAR(&_87$$60);
						ZVAL_STRING(&_87$$60, "");
						ZEPHIR_CALL_FUNCTION(&_88$$60, "preg_replace", &_45, 75, &_86$$60, &_87$$60, &_85$$60);
						zephir_check_call_status();
						zephir_array_update_string(&definition, SL("default"), &_88$$60, PH_COPY | PH_SEPARATE);
					}
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 330);
				ZEPHIR_INIT_NVAR(&_49$$32);
				object_init_ex(&_49$$32, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_49$$32, "__construct", &_46, 337, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_49$$32, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 331);
				ZEPHIR_CPY_WRT(&oldColumn, &columnName);
			ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
			zephir_check_call_status();
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
 *     $connection->describeIndexes("robots_parts")
 * );
 * ```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes)
{
	zend_ulong _46;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_16 = NULL, *_51 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, indexes, index, keyName, indexObjects, name, columns, describeIndexes, describeIndex, indexSql, _0, _1, _2, _3, *_4, _25, *_45, _5$$4, _6$$3, _8$$3, _9$$3, _10$$3, *_11$$3, _13$$3, _15$$3, _17$$3, _7$$6, _12$$7, _14$$8, _18$$9, _19$$9, _20$$9, _21$$9, _22$$10, _23$$11, _24$$12, _26$$14, _27$$13, _29$$13, _30$$13, _31$$13, *_32$$13, _34$$13, _36$$13, _37$$13, _28$$16, _33$$17, _35$$18, _38$$19, _39$$19, _40$$19, _41$$19, _42$$20, _43$$21, _44$$22, _48$$23, _49$$23, _50$$23;
	zend_string *table = NULL, *schema = NULL, *_47;
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
	ZVAL_UNDEF(&_25);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$10);
	ZVAL_UNDEF(&_23$$11);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_33$$17);
	ZVAL_UNDEF(&_35$$18);
	ZVAL_UNDEF(&_38$$19);
	ZVAL_UNDEF(&_39$$19);
	ZVAL_UNDEF(&_40$$19);
	ZVAL_UNDEF(&_41$$19);
	ZVAL_UNDEF(&_42$$20);
	ZVAL_UNDEF(&_43$$21);
	ZVAL_UNDEF(&_44$$22);
	ZVAL_UNDEF(&_48$$23);
	ZVAL_UNDEF(&_49$$23);
	ZVAL_UNDEF(&_50$$23);
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
	zephir_read_property(&_1, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeindexes", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 393);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _4);
			ZEPHIR_OBS_NVAR(&keyName);
			zephir_array_fetch_string(&keyName, &index, SL("name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 355);
			if (!(zephir_array_isset_value(&indexes, &keyName))) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				array_init(&_5$$4);
				zephir_array_update_zval(&indexes, &keyName, &_5$$4, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch(&_6$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 361);
			if (!(zephir_array_isset_value_string(&_6$$3, SL("columns")))) {
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
			} else {
				zephir_array_fetch(&_7$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 364);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_7$$6, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 364);
			}
			zephir_read_property(&_8$$3, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_9$$3, &_8$$3, "describeindex", NULL, 0, &keyName);
			zephir_check_call_status();
			ZVAL_LONG(&_10$$3, 2);
			ZEPHIR_CALL_METHOD(&describeIndexes, this_ptr, "fetchall", NULL, 0, &_9$$3, &_10$$3);
			zephir_check_call_status();
			zephir_is_iterable(&describeIndexes, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 376);
			if (Z_TYPE_P(&describeIndexes) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&describeIndexes), _11$$3)
				{
					ZEPHIR_INIT_NVAR(&describeIndex);
					ZVAL_COPY(&describeIndex, _11$$3);
					zephir_array_fetch_string(&_12$$7, &describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 373);
					zephir_array_append(&columns, &_12$$7, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 373);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &describeIndexes, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_13$$3, &describeIndexes, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_13$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&describeIndex, &describeIndexes, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_fetch_string(&_14$$8, &describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 373);
						zephir_array_append(&columns, &_14$$8, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 373);
					ZEPHIR_CALL_METHOD(NULL, &describeIndexes, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&describeIndex);
			zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
			zephir_read_property(&_10$$3, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_15$$3, &_10$$3, "listindexessql", NULL, 0, &table_zv, &schema_zv, &keyName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&indexSql, this_ptr, "fetchcolumn", &_16, 0, &_15$$3);
			zephir_check_call_status();
			zephir_array_fetch_string(&_17$$3, &index, SL("unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 382);
			if (zephir_is_true(&_17$$3)) {
				ZEPHIR_INIT_NVAR(&_18$$9);
				ZEPHIR_INIT_NVAR(&_19$$9);
				ZVAL_STRING(&_19$$9, "# UNIQUE #i");
				ZEPHIR_INIT_NVAR(&_20$$9);
				ZEPHIR_INIT_NVAR(&_21$$9);
				ZVAL_STRING(&_21$$9, "# UNIQUE #i");
				zephir_preg_match(&_20$$9, &_21$$9, &indexSql, &_18$$9, 0, 0 , 0 );
				if (zephir_is_true(&_20$$9)) {
					ZEPHIR_INIT_NVAR(&_22$$10);
					ZVAL_STRING(&_22$$10, "UNIQUE");
					zephir_array_update_multi(&indexes, &_22$$10, SL("zs"), 3, &keyName, SL("type"));
				} else {
					ZEPHIR_INIT_NVAR(&_23$$11);
					ZVAL_STRING(&_23$$11, "PRIMARY");
					zephir_array_update_multi(&indexes, &_23$$11, SL("zs"), 3, &keyName, SL("type"));
				}
			} else {
				ZEPHIR_INIT_NVAR(&_24$$12);
				ZVAL_STRING(&_24$$12, "");
				zephir_array_update_multi(&indexes, &_24$$12, SL("zs"), 3, &keyName, SL("type"));
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_25, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_25)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&keyName);
				zephir_array_fetch_string(&keyName, &index, SL("name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 355);
				if (!(zephir_array_isset_value(&indexes, &keyName))) {
					ZEPHIR_INIT_NVAR(&_26$$14);
					array_init(&_26$$14);
					zephir_array_update_zval(&indexes, &keyName, &_26$$14, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch(&_27$$13, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 361);
				if (!(zephir_array_isset_value_string(&_27$$13, SL("columns")))) {
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
				} else {
					zephir_array_fetch(&_28$$16, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 364);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_28$$16, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 364);
				}
				zephir_read_property(&_29$$13, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_30$$13, &_29$$13, "describeindex", NULL, 0, &keyName);
				zephir_check_call_status();
				ZVAL_LONG(&_31$$13, 2);
				ZEPHIR_CALL_METHOD(&describeIndexes, this_ptr, "fetchall", NULL, 0, &_30$$13, &_31$$13);
				zephir_check_call_status();
				zephir_is_iterable(&describeIndexes, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 376);
				if (Z_TYPE_P(&describeIndexes) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&describeIndexes), _32$$13)
					{
						ZEPHIR_INIT_NVAR(&describeIndex);
						ZVAL_COPY(&describeIndex, _32$$13);
						zephir_array_fetch_string(&_33$$17, &describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 373);
						zephir_array_append(&columns, &_33$$17, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 373);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &describeIndexes, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_34$$13, &describeIndexes, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_34$$13)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&describeIndex, &describeIndexes, "current", NULL, 0);
						zephir_check_call_status();
							zephir_array_fetch_string(&_35$$18, &describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 373);
							zephir_array_append(&columns, &_35$$18, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 373);
						ZEPHIR_CALL_METHOD(NULL, &describeIndexes, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&describeIndex);
				zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
				zephir_read_property(&_31$$13, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_36$$13, &_31$$13, "listindexessql", NULL, 0, &table_zv, &schema_zv, &keyName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&indexSql, this_ptr, "fetchcolumn", &_16, 0, &_36$$13);
				zephir_check_call_status();
				zephir_array_fetch_string(&_37$$13, &index, SL("unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 382);
				if (zephir_is_true(&_37$$13)) {
					ZEPHIR_INIT_NVAR(&_38$$19);
					ZEPHIR_INIT_NVAR(&_39$$19);
					ZVAL_STRING(&_39$$19, "# UNIQUE #i");
					ZEPHIR_INIT_NVAR(&_40$$19);
					ZEPHIR_INIT_NVAR(&_41$$19);
					ZVAL_STRING(&_41$$19, "# UNIQUE #i");
					zephir_preg_match(&_40$$19, &_41$$19, &indexSql, &_38$$19, 0, 0 , 0 );
					if (zephir_is_true(&_40$$19)) {
						ZEPHIR_INIT_NVAR(&_42$$20);
						ZVAL_STRING(&_42$$20, "UNIQUE");
						zephir_array_update_multi(&indexes, &_42$$20, SL("zs"), 3, &keyName, SL("type"));
					} else {
						ZEPHIR_INIT_NVAR(&_43$$21);
						ZVAL_STRING(&_43$$21, "PRIMARY");
						zephir_array_update_multi(&indexes, &_43$$21, SL("zs"), 3, &keyName, SL("type"));
					}
				} else {
					ZEPHIR_INIT_NVAR(&_44$$22);
					ZVAL_STRING(&_44$$22, "");
					zephir_array_update_multi(&indexes, &_44$$22, SL("zs"), 3, &keyName, SL("type"));
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	zephir_is_iterable(&indexes, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 403);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&indexes), _46, _47, _45)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_47 != NULL) { 
			ZVAL_STR_COPY(&name, _47);
		} else {
			ZVAL_LONG(&name, _46);
		}
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_COPY(&index, _45);
		ZEPHIR_INIT_NVAR(&_48$$23);
		object_init_ex(&_48$$23, phalcon_db_index_ce);
		zephir_array_fetch_string(&_49$$23, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 398);
		zephir_array_fetch_string(&_50$$23, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 400);
		ZEPHIR_CALL_METHOD(NULL, &_48$$23, "__construct", &_51, 60, &name, &_49$$23, &_50$$23);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, &name, &_48$$23, PH_COPY | PH_SEPARATE);
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
	zval _13$$3, _21$$6, _26$$9;
	zend_ulong _5, _23;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_28 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, number, _0, _1, _2, _3, *_4, _14, *_22, _7$$5, _8$$5, _9$$5, _10$$5, _11$$3, _12$$3, _15$$8, _16$$8, _17$$8, _18$$8, _19$$6, _20$$6, _25$$9, _27$$9;
	zend_string *table = NULL, *schema = NULL, *_6, *_24;
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
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_25$$9);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_26$$9);
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
	zephir_read_property(&_1, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describereferences", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 443);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
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
			if (!(zephir_array_isset_value(&references, &constraintName))) {
				ZEPHIR_INIT_NVAR(&referencedSchema);
				ZVAL_NULL(&referencedSchema);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 422);
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 426);
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_7$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 426);
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 427);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_8$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 427);
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 428);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_9$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 428);
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 429);
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_10$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 429);
			}
			zephir_array_fetch_long(&_11$$3, &reference, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 432);
			zephir_array_append(&columns, &_11$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 432);
			zephir_array_fetch_long(&_12$$3, &reference, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 433);
			zephir_array_append(&referencedColumns, &_12$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 433);
			ZEPHIR_INIT_NVAR(&_13$$3);
			zephir_create_array(&_13$$3, 4, 0);
			zephir_array_update_string(&_13$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&references, &constraintName, &_13$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_14, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&number, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&reference, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&constraintName);
				ZEPHIR_CONCAT_SV(&constraintName, "foreign_key_", &number);
				if (!(zephir_array_isset_value(&references, &constraintName))) {
					ZEPHIR_INIT_NVAR(&referencedSchema);
					ZVAL_NULL(&referencedSchema);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 422);
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_15$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 426);
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_15$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 426);
					zephir_array_fetch(&_16$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 427);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_16$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 427);
					zephir_array_fetch(&_17$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 428);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_17$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 428);
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 429);
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_18$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 429);
				}
				zephir_array_fetch_long(&_19$$6, &reference, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 432);
				zephir_array_append(&columns, &_19$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 432);
				zephir_array_fetch_long(&_20$$6, &reference, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 433);
				zephir_array_append(&referencedColumns, &_20$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 433);
				ZEPHIR_INIT_NVAR(&_21$$6);
				zephir_create_array(&_21$$6, 4, 0);
				zephir_array_update_string(&_21$$6, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_21$$6, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_21$$6, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_21$$6, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&references, &constraintName, &_21$$6, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&reference);
	ZEPHIR_INIT_NVAR(&number);
	ZEPHIR_INIT_VAR(&referenceObjects);
	array_init(&referenceObjects);
	zephir_is_iterable(&references, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 457);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&references), _23, _24, _22)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_24 != NULL) { 
			ZVAL_STR_COPY(&name, _24);
		} else {
			ZVAL_LONG(&name, _23);
		}
		ZEPHIR_INIT_NVAR(&arrayReference);
		ZVAL_COPY(&arrayReference, _22);
		ZEPHIR_INIT_NVAR(&_25$$9);
		object_init_ex(&_25$$9, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(&_26$$9);
		zephir_create_array(&_26$$9, 4, 0);
		ZEPHIR_OBS_NVAR(&_27$$9);
		zephir_array_fetch_string(&_27$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 449);
		zephir_array_update_string(&_26$$9, SL("referencedSchema"), &_27$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_27$$9);
		zephir_array_fetch_string(&_27$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 450);
		zephir_array_update_string(&_26$$9, SL("referencedTable"), &_27$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_27$$9);
		zephir_array_fetch_string(&_27$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 451);
		zephir_array_update_string(&_26$$9, SL("columns"), &_27$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_27$$9);
		zephir_array_fetch_string(&_27$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 453);
		zephir_array_update_string(&_26$$9, SL("referencedColumns"), &_27$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_25$$9, "__construct", &_28, 61, &name, &_26$$9);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_25$$9, PH_COPY | PH_SEPARATE);
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
 * // Inserting a new robot with a valid default value for the column 'year'
 * $success = $connection->insert(
 *     "robots",
 *     [
 *         "Astro Boy",
 *         $connection->getDefaultValue(),
 *     ],
 *     [
 *         "name",
 *         "year",
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
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "NULL");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 62, &_0);
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
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, getDsnDefaults)
{

	array_init(return_value);
	return;
}

