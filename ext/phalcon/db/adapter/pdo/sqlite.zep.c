
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
	if (zephir_array_isset_string(&descriptor, SL("charset"))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "SQLite does not allow the charset to be changed in the DSN.");
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 9, &_0$$3);
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
	zval *descriptor_param = NULL, dbname, _0$$3;
	zval descriptor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&dbname);
	ZVAL_UNDEF(&_0$$3);
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
	} else if (UNEXPECTED(!(zephir_array_isset_string(&descriptor, SL("dsn"))))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The database must be specified with either 'dbname' or 'dsn'.", "phalcon/Db/Adapter/Pdo/Sqlite.zep", 82);
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
	zend_bool _33$$3, _72$$29;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_36 = NULL, *_41 = NULL, *_42 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, __$true, __$false, columns, columnType, fields, field, definition, oldColumn, sizePattern, matches, matchOne, matchTwo, columnName, _0, _1, _2, *_3, _4, _5$$3, _30$$3, _31$$3, _32$$3, _34$$3, _35$$3, _6$$4, _7$$4, _8$$5, _9$$5, _10$$5, _11$$7, _12$$7, _13$$8, _14$$9, _15$$10, _16$$11, _17$$11, _18$$12, _19$$12, _20$$13, _21$$13, _22$$14, _23$$15, _24$$16, _25$$17, _26$$18, _27$$19, _28$$21, _29$$22, _37$$28, _38$$28, _39$$28, _40$$28, _43$$29, _44$$29, _69$$29, _70$$29, _71$$29, _73$$29, _74$$29, _45$$30, _46$$30, _47$$31, _48$$31, _49$$31, _50$$33, _51$$33, _52$$34, _53$$35, _54$$36, _55$$37, _56$$37, _57$$38, _58$$38, _59$$39, _60$$39, _61$$40, _62$$41, _63$$42, _64$$43, _65$$44, _66$$45, _67$$47, _68$$48, _75$$54, _76$$54, _77$$54, _78$$54;
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
	ZVAL_UNDEF(&_5$$3);
	ZVAL_UNDEF(&_30$$3);
	ZVAL_UNDEF(&_31$$3);
	ZVAL_UNDEF(&_32$$3);
	ZVAL_UNDEF(&_34$$3);
	ZVAL_UNDEF(&_35$$3);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_29$$22);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&_38$$28);
	ZVAL_UNDEF(&_39$$28);
	ZVAL_UNDEF(&_40$$28);
	ZVAL_UNDEF(&_43$$29);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_69$$29);
	ZVAL_UNDEF(&_70$$29);
	ZVAL_UNDEF(&_71$$29);
	ZVAL_UNDEF(&_73$$29);
	ZVAL_UNDEF(&_74$$29);
	ZVAL_UNDEF(&_45$$30);
	ZVAL_UNDEF(&_46$$30);
	ZVAL_UNDEF(&_47$$31);
	ZVAL_UNDEF(&_48$$31);
	ZVAL_UNDEF(&_49$$31);
	ZVAL_UNDEF(&_50$$33);
	ZVAL_UNDEF(&_51$$33);
	ZVAL_UNDEF(&_52$$34);
	ZVAL_UNDEF(&_53$$35);
	ZVAL_UNDEF(&_54$$36);
	ZVAL_UNDEF(&_55$$37);
	ZVAL_UNDEF(&_56$$37);
	ZVAL_UNDEF(&_57$$38);
	ZVAL_UNDEF(&_58$$38);
	ZVAL_UNDEF(&_59$$39);
	ZVAL_UNDEF(&_60$$39);
	ZVAL_UNDEF(&_61$$40);
	ZVAL_UNDEF(&_62$$41);
	ZVAL_UNDEF(&_63$$42);
	ZVAL_UNDEF(&_64$$43);
	ZVAL_UNDEF(&_65$$44);
	ZVAL_UNDEF(&_66$$45);
	ZVAL_UNDEF(&_67$$47);
	ZVAL_UNDEF(&_68$$48);
	ZVAL_UNDEF(&_75$$54);
	ZVAL_UNDEF(&_76$$54);
	ZVAL_UNDEF(&_77$$54);
	ZVAL_UNDEF(&_78$$54);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
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
	zephir_is_iterable(&fields, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 319);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _3)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _3);
			ZEPHIR_INIT_NVAR(&definition);
			zephir_create_array(&definition, 1, 0);
			add_assoc_long_ex(&definition, SL("bindType"), 2);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 127);
			ZEPHIR_INIT_NVAR(&_5$$3);
			zephir_fast_strtolower(&_5$$3, &columnType);
			ZEPHIR_CPY_WRT(&columnType, &_5$$3);
			if (zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 143)) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZVAL_LONG(&_6$$4, 14);
				zephir_array_update_string(&definition, SL("type"), &_6$$4, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZVAL_LONG(&_7$$4, 2);
				zephir_array_update_string(&definition, SL("bindType"), &_7$$4, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 150)) {
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZVAL_LONG(&_8$$5, 0);
				zephir_array_update_string(&definition, SL("type"), &_8$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_LONG(&_9$$5, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_9$$5, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_long(&_10$$5, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 158);
				if (zephir_is_true(&_10$$5)) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
			} else if (zephir_memnstr_str(&columnType, SL("tinyint(1)"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 161)) {
				ZEPHIR_INIT_NVAR(&_11$$7);
				ZVAL_LONG(&_11$$7, 8);
				zephir_array_update_string(&definition, SL("type"), &_11$$7, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_12$$7);
				ZVAL_LONG(&_12$$7, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_12$$7, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&columnType);
				ZVAL_STRING(&columnType, "boolean");
			} else if (zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 172)) {
				ZEPHIR_INIT_NVAR(&_13$$8);
				ZVAL_LONG(&_13$$8, 5);
				zephir_array_update_string(&definition, SL("type"), &_13$$8, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 181)) {
				ZEPHIR_INIT_NVAR(&_14$$9);
				ZVAL_LONG(&_14$$9, 4);
				zephir_array_update_string(&definition, SL("type"), &_14$$9, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 186)) {
				ZEPHIR_INIT_NVAR(&_15$$10);
				ZVAL_LONG(&_15$$10, 1);
				zephir_array_update_string(&definition, SL("type"), &_15$$10, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 195)) {
				ZEPHIR_INIT_NVAR(&_16$$11);
				ZVAL_LONG(&_16$$11, 3);
				zephir_array_update_string(&definition, SL("type"), &_16$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_17$$11);
				ZVAL_LONG(&_17$$11, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_17$$11, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 202)) {
				ZEPHIR_INIT_NVAR(&_18$$12);
				ZVAL_LONG(&_18$$12, 7);
				zephir_array_update_string(&definition, SL("type"), &_18$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_19$$12);
				ZVAL_LONG(&_19$$12, 3);
				zephir_array_update_string(&definition, SL("bindType"), &_19$$12, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("real"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 209)) {
				ZEPHIR_INIT_NVAR(&_20$$13);
				ZVAL_LONG(&_20$$13, 7);
				zephir_array_update_string(&definition, SL("type"), &_20$$13, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_21$$13);
				ZVAL_LONG(&_21$$13, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_21$$13, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 220)) {
				ZEPHIR_INIT_NVAR(&_22$$14);
				ZVAL_LONG(&_22$$14, 17);
				zephir_array_update_string(&definition, SL("type"), &_22$$14, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 229)) {
				ZEPHIR_INIT_NVAR(&_23$$15);
				ZVAL_LONG(&_23$$15, 2);
				zephir_array_update_string(&definition, SL("type"), &_23$$15, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 234)) {
				ZEPHIR_INIT_NVAR(&_24$$16);
				ZVAL_LONG(&_24$$16, 5);
				zephir_array_update_string(&definition, SL("type"), &_24$$16, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 239)) {
				ZEPHIR_INIT_NVAR(&_25$$17);
				ZVAL_LONG(&_25$$17, 6);
				zephir_array_update_string(&definition, SL("type"), &_25$$17, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(&_26$$18);
				ZVAL_LONG(&_26$$18, 2);
				zephir_array_update_string(&definition, SL("type"), &_26$$18, PH_COPY | PH_SEPARATE);
			}
			if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 256)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				ZEPHIR_INIT_NVAR(&_27$$19);
				zephir_preg_match(&_27$$19, &sizePattern, &columnType, &matches, 0, 0 , 0 );
				if (zephir_is_true(&_27$$19)) {
					ZEPHIR_OBS_NVAR(&matchOne);
					if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
						ZEPHIR_INIT_NVAR(&_28$$21);
						ZVAL_LONG(&_28$$21, zephir_get_intval(&matchOne));
						zephir_array_update_string(&definition, SL("size"), &_28$$21, PH_COPY | PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(&matchTwo);
					if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
						ZEPHIR_INIT_NVAR(&_29$$22);
						ZVAL_LONG(&_29$$22, zephir_get_intval(&matchTwo));
						zephir_array_update_string(&definition, SL("scale"), &_29$$22, PH_COPY | PH_SEPARATE);
					}
				}
			}
			if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 272)) {
				zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&oldColumn) == IS_NULL) {
				zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_30$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 288);
			if (zephir_is_true(&_30$$3)) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_31$$3, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 295);
			if (ZEPHIR_IS_LONG(&_31$$3, 0)) {
				zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_OBS_NVAR(&_32$$3);
			zephir_array_fetch_long(&_32$$3, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 303);
			_33$$3 = !(ZEPHIR_IS_EMPTY(&_32$$3));
			if (_33$$3) {
				zephir_array_fetch_long(&_34$$3, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 303);
				ZEPHIR_INIT_NVAR(&_5$$3);
				ZVAL_STRING(&_5$$3, "null");
				ZEPHIR_CALL_FUNCTION(&_35$$3, "strcasecmp", &_36, 38, &_34$$3, &_5$$3);
				zephir_check_call_status();
				_33$$3 = !ZEPHIR_IS_LONG_IDENTICAL(&_35$$3, 0);
			}
			if (_33$$3) {
				zephir_array_fetch_long(&_37$$28, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 308);
				ZEPHIR_INIT_NVAR(&_38$$28);
				ZVAL_STRING(&_38$$28, "/^'|'$/");
				ZEPHIR_INIT_NVAR(&_39$$28);
				ZVAL_STRING(&_39$$28, "");
				ZEPHIR_CALL_FUNCTION(&_40$$28, "preg_replace", &_41, 40, &_38$$28, &_39$$28, &_37$$28);
				zephir_check_call_status();
				zephir_array_update_string(&definition, SL("default"), &_40$$28, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&columnName, &field, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 314);
			ZEPHIR_INIT_NVAR(&_5$$3);
			object_init_ex(&_5$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_5$$3, "__construct", &_42, 215, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_5$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 315);
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
				ZEPHIR_INIT_NVAR(&_43$$29);
				zephir_create_array(&_43$$29, 1, 0);
				add_assoc_long_ex(&_43$$29, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_43$$29);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 127);
				ZEPHIR_INIT_NVAR(&_44$$29);
				zephir_fast_strtolower(&_44$$29, &columnType);
				ZEPHIR_CPY_WRT(&columnType, &_44$$29);
				if (zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 143)) {
					ZEPHIR_INIT_NVAR(&_45$$30);
					ZVAL_LONG(&_45$$30, 14);
					zephir_array_update_string(&definition, SL("type"), &_45$$30, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_46$$30);
					ZVAL_LONG(&_46$$30, 2);
					zephir_array_update_string(&definition, SL("bindType"), &_46$$30, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 150)) {
					ZEPHIR_INIT_NVAR(&_47$$31);
					ZVAL_LONG(&_47$$31, 0);
					zephir_array_update_string(&definition, SL("type"), &_47$$31, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_48$$31);
					ZVAL_LONG(&_48$$31, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_48$$31, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_long(&_49$$31, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 158);
					if (zephir_is_true(&_49$$31)) {
						zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
					}
				} else if (zephir_memnstr_str(&columnType, SL("tinyint(1)"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 161)) {
					ZEPHIR_INIT_NVAR(&_50$$33);
					ZVAL_LONG(&_50$$33, 8);
					zephir_array_update_string(&definition, SL("type"), &_50$$33, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_51$$33);
					ZVAL_LONG(&_51$$33, 5);
					zephir_array_update_string(&definition, SL("bindType"), &_51$$33, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&columnType);
					ZVAL_STRING(&columnType, "boolean");
				} else if (zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 172)) {
					ZEPHIR_INIT_NVAR(&_52$$34);
					ZVAL_LONG(&_52$$34, 5);
					zephir_array_update_string(&definition, SL("type"), &_52$$34, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 181)) {
					ZEPHIR_INIT_NVAR(&_53$$35);
					ZVAL_LONG(&_53$$35, 4);
					zephir_array_update_string(&definition, SL("type"), &_53$$35, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 186)) {
					ZEPHIR_INIT_NVAR(&_54$$36);
					ZVAL_LONG(&_54$$36, 1);
					zephir_array_update_string(&definition, SL("type"), &_54$$36, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 195)) {
					ZEPHIR_INIT_NVAR(&_55$$37);
					ZVAL_LONG(&_55$$37, 3);
					zephir_array_update_string(&definition, SL("type"), &_55$$37, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_56$$37);
					ZVAL_LONG(&_56$$37, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_56$$37, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 202)) {
					ZEPHIR_INIT_NVAR(&_57$$38);
					ZVAL_LONG(&_57$$38, 7);
					zephir_array_update_string(&definition, SL("type"), &_57$$38, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_58$$38);
					ZVAL_LONG(&_58$$38, 3);
					zephir_array_update_string(&definition, SL("bindType"), &_58$$38, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("real"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 209)) {
					ZEPHIR_INIT_NVAR(&_59$$39);
					ZVAL_LONG(&_59$$39, 7);
					zephir_array_update_string(&definition, SL("type"), &_59$$39, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_60$$39);
					ZVAL_LONG(&_60$$39, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_60$$39, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 220)) {
					ZEPHIR_INIT_NVAR(&_61$$40);
					ZVAL_LONG(&_61$$40, 17);
					zephir_array_update_string(&definition, SL("type"), &_61$$40, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 229)) {
					ZEPHIR_INIT_NVAR(&_62$$41);
					ZVAL_LONG(&_62$$41, 2);
					zephir_array_update_string(&definition, SL("type"), &_62$$41, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 234)) {
					ZEPHIR_INIT_NVAR(&_63$$42);
					ZVAL_LONG(&_63$$42, 5);
					zephir_array_update_string(&definition, SL("type"), &_63$$42, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 239)) {
					ZEPHIR_INIT_NVAR(&_64$$43);
					ZVAL_LONG(&_64$$43, 6);
					zephir_array_update_string(&definition, SL("type"), &_64$$43, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_65$$44);
					ZVAL_LONG(&_65$$44, 2);
					zephir_array_update_string(&definition, SL("type"), &_65$$44, PH_COPY | PH_SEPARATE);
				}
				if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 256)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					ZEPHIR_INIT_NVAR(&_66$$45);
					zephir_preg_match(&_66$$45, &sizePattern, &columnType, &matches, 0, 0 , 0 );
					if (zephir_is_true(&_66$$45)) {
						ZEPHIR_OBS_NVAR(&matchOne);
						if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
							ZEPHIR_INIT_NVAR(&_67$$47);
							ZVAL_LONG(&_67$$47, zephir_get_intval(&matchOne));
							zephir_array_update_string(&definition, SL("size"), &_67$$47, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&matchTwo);
						if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
							ZEPHIR_INIT_NVAR(&_68$$48);
							ZVAL_LONG(&_68$$48, zephir_get_intval(&matchTwo));
							zephir_array_update_string(&definition, SL("scale"), &_68$$48, PH_COPY | PH_SEPARATE);
						}
					}
				}
				if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Sqlite.zep", 272)) {
					zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
				}
				if (Z_TYPE_P(&oldColumn) == IS_NULL) {
					zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_69$$29, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 288);
				if (zephir_is_true(&_69$$29)) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_70$$29, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 295);
				if (ZEPHIR_IS_LONG(&_70$$29, 0)) {
					zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&_71$$29);
				zephir_array_fetch_long(&_71$$29, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 303);
				_72$$29 = !(ZEPHIR_IS_EMPTY(&_71$$29));
				if (_72$$29) {
					zephir_array_fetch_long(&_73$$29, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 303);
					ZEPHIR_INIT_NVAR(&_44$$29);
					ZVAL_STRING(&_44$$29, "null");
					ZEPHIR_CALL_FUNCTION(&_74$$29, "strcasecmp", &_36, 38, &_73$$29, &_44$$29);
					zephir_check_call_status();
					_72$$29 = !ZEPHIR_IS_LONG_IDENTICAL(&_74$$29, 0);
				}
				if (_72$$29) {
					zephir_array_fetch_long(&_75$$54, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 308);
					ZEPHIR_INIT_NVAR(&_76$$54);
					ZVAL_STRING(&_76$$54, "/^'|'$/");
					ZEPHIR_INIT_NVAR(&_77$$54);
					ZVAL_STRING(&_77$$54, "");
					ZEPHIR_CALL_FUNCTION(&_78$$54, "preg_replace", &_41, 40, &_76$$54, &_77$$54, &_75$$54);
					zephir_check_call_status();
					zephir_array_update_string(&definition, SL("default"), &_78$$54, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 314);
				ZEPHIR_INIT_NVAR(&_44$$29);
				object_init_ex(&_44$$29, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_44$$29, "__construct", &_42, 215, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_44$$29, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 315);
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
	zend_ulong _47;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_17 = NULL, *_52 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, indexes, index, keyName, indexObjects, name, columns, describeIndexes, describeIndex, indexSql, _0, _1, _2, _3, *_4, _5, *_45, _46, _6$$4, _7$$3, _9$$3, _10$$3, _11$$3, *_12$$3, _13$$3, _16$$3, _18$$3, _8$$6, _14$$7, _15$$8, _19$$9, _20$$9, _21$$9, _22$$9, _23$$10, _24$$11, _25$$12, _26$$14, _27$$13, _29$$13, _30$$13, _31$$13, *_32$$13, _33$$13, _36$$13, _37$$13, _28$$16, _34$$17, _35$$18, _38$$19, _39$$19, _40$$19, _41$$19, _42$$20, _43$$21, _44$$22, _49$$23, _50$$23, _51$$23, _53$$24, _54$$24, _55$$24;
	zend_string *table = NULL, *schema = NULL, *_48;
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
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_33$$13);
	ZVAL_UNDEF(&_36$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_34$$17);
	ZVAL_UNDEF(&_35$$18);
	ZVAL_UNDEF(&_38$$19);
	ZVAL_UNDEF(&_39$$19);
	ZVAL_UNDEF(&_40$$19);
	ZVAL_UNDEF(&_41$$19);
	ZVAL_UNDEF(&_42$$20);
	ZVAL_UNDEF(&_43$$21);
	ZVAL_UNDEF(&_44$$22);
	ZVAL_UNDEF(&_49$$23);
	ZVAL_UNDEF(&_50$$23);
	ZVAL_UNDEF(&_51$$23);
	ZVAL_UNDEF(&_53$$24);
	ZVAL_UNDEF(&_54$$24);
	ZVAL_UNDEF(&_55$$24);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
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
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 377);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _4);
			ZEPHIR_OBS_NVAR(&keyName);
			zephir_array_fetch_string(&keyName, &index, SL("name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 339);
			if (!(zephir_array_isset(&indexes, &keyName))) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				array_init(&_6$$4);
				zephir_array_update_zval(&indexes, &keyName, &_6$$4, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch(&_7$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 345);
			if (!(zephir_array_isset_string(&_7$$3, SL("columns")))) {
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
			} else {
				zephir_array_fetch(&_8$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 348);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_8$$6, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 348);
			}
			zephir_read_property(&_9$$3, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_10$$3, &_9$$3, "describeindex", NULL, 0, &keyName);
			zephir_check_call_status();
			ZVAL_LONG(&_11$$3, 2);
			ZEPHIR_CALL_METHOD(&describeIndexes, this_ptr, "fetchall", NULL, 0, &_10$$3, &_11$$3);
			zephir_check_call_status();
			zephir_is_iterable(&describeIndexes, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 360);
			if (Z_TYPE_P(&describeIndexes) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&describeIndexes), _12$$3)
				{
					ZEPHIR_INIT_NVAR(&describeIndex);
					ZVAL_COPY(&describeIndex, _12$$3);
					zephir_array_fetch_string(&_14$$7, &describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 357);
					zephir_array_append(&columns, &_14$$7, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 357);
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
						zephir_array_fetch_string(&_15$$8, &describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 357);
						zephir_array_append(&columns, &_15$$8, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 357);
					ZEPHIR_CALL_METHOD(NULL, &describeIndexes, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&describeIndex);
			zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
			zephir_read_property(&_11$$3, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_16$$3, &_11$$3, "listindexessql", NULL, 0, &table_zv, &schema_zv, &keyName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&indexSql, this_ptr, "fetchcolumn", &_17, 0, &_16$$3);
			zephir_check_call_status();
			zephir_array_fetch_string(&_18$$3, &index, SL("unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 366);
			if (zephir_is_true(&_18$$3)) {
				ZEPHIR_INIT_NVAR(&_19$$9);
				ZEPHIR_INIT_NVAR(&_20$$9);
				ZVAL_STRING(&_20$$9, "# UNIQUE #i");
				ZEPHIR_INIT_NVAR(&_21$$9);
				ZEPHIR_INIT_NVAR(&_22$$9);
				ZVAL_STRING(&_22$$9, "# UNIQUE #i");
				zephir_preg_match(&_21$$9, &_22$$9, &indexSql, &_19$$9, 0, 0 , 0 );
				if (zephir_is_true(&_21$$9)) {
					ZEPHIR_INIT_NVAR(&_23$$10);
					ZVAL_STRING(&_23$$10, "UNIQUE");
					zephir_array_update_multi(&indexes, &_23$$10, SL("zs"), 3, &keyName, SL("type"));
				} else {
					ZEPHIR_INIT_NVAR(&_24$$11);
					ZVAL_STRING(&_24$$11, "PRIMARY");
					zephir_array_update_multi(&indexes, &_24$$11, SL("zs"), 3, &keyName, SL("type"));
				}
			} else {
				ZEPHIR_INIT_NVAR(&_25$$12);
				ZVAL_STRING(&_25$$12, "");
				zephir_array_update_multi(&indexes, &_25$$12, SL("zs"), 3, &keyName, SL("type"));
			}
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
			ZEPHIR_CALL_METHOD(&index, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&keyName);
				zephir_array_fetch_string(&keyName, &index, SL("name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 339);
				if (!(zephir_array_isset(&indexes, &keyName))) {
					ZEPHIR_INIT_NVAR(&_26$$14);
					array_init(&_26$$14);
					zephir_array_update_zval(&indexes, &keyName, &_26$$14, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch(&_27$$13, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 345);
				if (!(zephir_array_isset_string(&_27$$13, SL("columns")))) {
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
				} else {
					zephir_array_fetch(&_28$$16, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 348);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_28$$16, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 348);
				}
				zephir_read_property(&_29$$13, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_30$$13, &_29$$13, "describeindex", NULL, 0, &keyName);
				zephir_check_call_status();
				ZVAL_LONG(&_31$$13, 2);
				ZEPHIR_CALL_METHOD(&describeIndexes, this_ptr, "fetchall", NULL, 0, &_30$$13, &_31$$13);
				zephir_check_call_status();
				zephir_is_iterable(&describeIndexes, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 360);
				if (Z_TYPE_P(&describeIndexes) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&describeIndexes), _32$$13)
					{
						ZEPHIR_INIT_NVAR(&describeIndex);
						ZVAL_COPY(&describeIndex, _32$$13);
						zephir_array_fetch_string(&_34$$17, &describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 357);
						zephir_array_append(&columns, &_34$$17, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 357);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &describeIndexes, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_33$$13, &describeIndexes, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_33$$13)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&describeIndex, &describeIndexes, "current", NULL, 0);
						zephir_check_call_status();
							zephir_array_fetch_string(&_35$$18, &describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 357);
							zephir_array_append(&columns, &_35$$18, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 357);
						ZEPHIR_CALL_METHOD(NULL, &describeIndexes, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&describeIndex);
				zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
				zephir_read_property(&_31$$13, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_36$$13, &_31$$13, "listindexessql", NULL, 0, &table_zv, &schema_zv, &keyName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&indexSql, this_ptr, "fetchcolumn", &_17, 0, &_36$$13);
				zephir_check_call_status();
				zephir_array_fetch_string(&_37$$13, &index, SL("unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 366);
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
	zephir_is_iterable(&indexes, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 387);
	if (Z_TYPE_P(&indexes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&indexes), _47, _48, _45)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_48 != NULL) { 
				ZVAL_STR_COPY(&name, _48);
			} else {
				ZVAL_LONG(&name, _47);
			}
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _45);
			ZEPHIR_INIT_NVAR(&_49$$23);
			object_init_ex(&_49$$23, phalcon_db_index_ce);
			zephir_array_fetch_string(&_50$$23, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 382);
			zephir_array_fetch_string(&_51$$23, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 384);
			ZEPHIR_CALL_METHOD(NULL, &_49$$23, "__construct", &_52, 33, &name, &_50$$23, &_51$$23);
			zephir_check_call_status();
			zephir_array_update_zval(&indexObjects, &name, &_49$$23, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &indexes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_46, &indexes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_46)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &indexes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&index, &indexes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_53$$24);
				object_init_ex(&_53$$24, phalcon_db_index_ce);
				zephir_array_fetch_string(&_54$$24, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 382);
				zephir_array_fetch_string(&_55$$24, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 384);
				ZEPHIR_CALL_METHOD(NULL, &_53$$24, "__construct", &_52, 33, &name, &_54$$24, &_55$$24);
				zephir_check_call_status();
				zephir_array_update_zval(&indexObjects, &name, &_53$$24, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &indexes, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&indexObjects);
}

/**
 * Lists table references
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeReferences)
{
	zval _14$$3, _21$$6, _27$$9, _31$$10;
	zend_ulong _6, _24;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, number, _0, _1, _2, _3, *_4, _5, *_22, _23, _8$$5, _9$$5, _10$$5, _11$$5, _12$$3, _13$$3, _15$$8, _16$$8, _17$$8, _18$$8, _19$$6, _20$$6, _26$$9, _28$$9, _30$$10, _32$$10;
	zend_string *table = NULL, *schema = NULL, *_7, *_25;
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
	ZVAL_UNDEF(&_23);
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
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_20$$6);
	ZVAL_UNDEF(&_26$$9);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_30$$10);
	ZVAL_UNDEF(&_32$$10);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_21$$6);
	ZVAL_UNDEF(&_27$$9);
	ZVAL_UNDEF(&_31$$10);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	ZVAL_STR_COPY(&table_zv, table);
	if (!schema) {
		ZEPHIR_INIT_VAR(&schema_zv);
	} else {
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
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 427);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&_0), _6, _7, _4)
		{
			ZEPHIR_INIT_NVAR(&number);
			if (_7 != NULL) { 
				ZVAL_STR_COPY(&number, _7);
			} else {
				ZVAL_LONG(&number, _6);
			}
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _4);
			ZEPHIR_INIT_NVAR(&constraintName);
			ZEPHIR_CONCAT_SV(&constraintName, "foreign_key_", &number);
			if (!(zephir_array_isset(&references, &constraintName))) {
				ZEPHIR_INIT_NVAR(&referencedSchema);
				ZVAL_NULL(&referencedSchema);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 406);
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 410);
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_8$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 410);
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 411);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_9$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 411);
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 412);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_10$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 412);
				zephir_array_fetch(&_11$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 413);
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_11$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 413);
			}
			zephir_array_fetch_long(&_12$$3, &reference, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 416);
			zephir_array_append(&columns, &_12$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 416);
			zephir_array_fetch_long(&_13$$3, &reference, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 417);
			zephir_array_append(&referencedColumns, &_13$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 417);
			ZEPHIR_INIT_NVAR(&_14$$3);
			zephir_create_array(&_14$$3, 4, 0);
			zephir_array_update_string(&_14$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_14$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
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
			ZEPHIR_CALL_METHOD(&number, &_0, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&reference, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&constraintName);
				ZEPHIR_CONCAT_SV(&constraintName, "foreign_key_", &number);
				if (!(zephir_array_isset(&references, &constraintName))) {
					ZEPHIR_INIT_NVAR(&referencedSchema);
					ZVAL_NULL(&referencedSchema);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 406);
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_15$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 410);
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_15$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 410);
					zephir_array_fetch(&_16$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 411);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_16$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 411);
					zephir_array_fetch(&_17$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 412);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_17$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 412);
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 413);
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_18$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 413);
				}
				zephir_array_fetch_long(&_19$$6, &reference, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 416);
				zephir_array_append(&columns, &_19$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 416);
				zephir_array_fetch_long(&_20$$6, &reference, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 417);
				zephir_array_append(&referencedColumns, &_20$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 417);
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
	zephir_is_iterable(&references, 0, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 441);
	if (Z_TYPE_P(&references) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&references), _24, _25, _22)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_25 != NULL) { 
				ZVAL_STR_COPY(&name, _25);
			} else {
				ZVAL_LONG(&name, _24);
			}
			ZEPHIR_INIT_NVAR(&arrayReference);
			ZVAL_COPY(&arrayReference, _22);
			ZEPHIR_INIT_NVAR(&_26$$9);
			object_init_ex(&_26$$9, phalcon_db_reference_ce);
			ZEPHIR_INIT_NVAR(&_27$$9);
			zephir_create_array(&_27$$9, 4, 0);
			ZEPHIR_OBS_NVAR(&_28$$9);
			zephir_array_fetch_string(&_28$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 433);
			zephir_array_update_string(&_27$$9, SL("referencedSchema"), &_28$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_28$$9);
			zephir_array_fetch_string(&_28$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 434);
			zephir_array_update_string(&_27$$9, SL("referencedTable"), &_28$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_28$$9);
			zephir_array_fetch_string(&_28$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 435);
			zephir_array_update_string(&_27$$9, SL("columns"), &_28$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_28$$9);
			zephir_array_fetch_string(&_28$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 437);
			zephir_array_update_string(&_27$$9, SL("referencedColumns"), &_28$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_26$$9, "__construct", &_29, 34, &name, &_27$$9);
			zephir_check_call_status();
			zephir_array_update_zval(&referenceObjects, &name, &_26$$9, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &references, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_23, &references, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &references, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&arrayReference, &references, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_30$$10);
				object_init_ex(&_30$$10, phalcon_db_reference_ce);
				ZEPHIR_INIT_NVAR(&_31$$10);
				zephir_create_array(&_31$$10, 4, 0);
				ZEPHIR_OBS_NVAR(&_32$$10);
				zephir_array_fetch_string(&_32$$10, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 433);
				zephir_array_update_string(&_31$$10, SL("referencedSchema"), &_32$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_32$$10);
				zephir_array_fetch_string(&_32$$10, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 434);
				zephir_array_update_string(&_31$$10, SL("referencedTable"), &_32$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_32$$10);
				zephir_array_fetch_string(&_32$$10, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 435);
				zephir_array_update_string(&_31$$10, SL("columns"), &_32$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_32$$10);
				zephir_array_fetch_string(&_32$$10, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Sqlite.zep", 437);
				zephir_array_update_string(&_31$$10, SL("referencedColumns"), &_32$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &_30$$10, "__construct", &_29, 34, &name, &_31$$10);
				zephir_check_call_status();
				zephir_array_update_zval(&referenceObjects, &name, &_30$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &references, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
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
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 35, &_0);
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

