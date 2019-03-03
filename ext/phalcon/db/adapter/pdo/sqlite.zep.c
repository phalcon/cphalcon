
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
 * Phalcon\Db\Adapter\Pdo\Sqlite
 *
 * Specific functions for the Sqlite database system
 *
 * <code>
 * use Phalcon\Db\Adapter\Pdo\Sqlite;
 *
 * $connection = new Sqlite(
 *     [
 *         "dbname" => "/tmp/test.sqlite",
 *     ]
 * );
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Sqlite) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Sqlite, phalcon, db_adapter_pdo_sqlite, phalcon_db_adapter_pdo_ce, phalcon_db_adapter_pdo_sqlite_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_sqlite_ce, SL("_dialectType"), "sqlite", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_db_adapter_pdo_sqlite_ce, SL("_type"), "sqlite", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Returns PDO adapter DSN defaults as a key-value map.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, getDsnDefaults) {

	zval *this_ptr = getThis();


	array_init(return_value);
	return;

}

/**
 * Constructor for Phalcon\Db\Adapter\Pdo\Sqlite
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, __construct) {

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
		ZVAL_STRING(&_0$$3, "Sqlite does not allow the charset to be changed in the DSN.");
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 1, &_0$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_sqlite_ce, getThis(), "__construct", &_1, 0, &descriptor);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, connect) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_2 = NULL;
	zval *descriptor_param = NULL, dbname, _0$$3;
	zval descriptor, _1$$3;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&dbname);
	ZVAL_UNDEF(&_0$$3);

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
	ZEPHIR_OBS_VAR(&dbname);
	if (zephir_array_isset_string_fetch(&dbname, &descriptor, SL("dbname"), 0)) {
		zephir_array_update_string(&descriptor, SL("dsn"), &dbname, PH_COPY | PH_SEPARATE);
		zephir_array_unset_string(&descriptor, SL("dbname"), PH_SEPARATE);
	} else if (!(zephir_array_isset_string(&descriptor, SL("dsn")))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The database must be specified with either 'dbname' or 'dsn'.", "phalcon/db/adapter/pdo/sqlite.zep", 82);
		return;
	}
	ZEPHIR_RETURN_CALL_PARENT(phalcon_db_adapter_pdo_sqlite_ce, getThis(), "connect", &_2, 0, &descriptor);
	zephir_check_call_status();
	RETURN_MM();

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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeColumns) {

	zend_bool _6$$3, _35$$3, _44$$28, _72$$28;
	zephir_fcall_cache_entry *_34 = NULL, *_41 = NULL, *_42 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$true, columns, columnType, field, definition, oldColumn, sizePattern, matches, matchOne, matchTwo, columnName, _0, _1, _2, _3, *_4, _5, _29$$3, _30$$3, _31$$3, _32$$3, _33$$3, _36$$3, _7$$4, _8$$4, _9$$5, _10$$5, _11$$5, _12$$7, _13$$7, _14$$8, _15$$9, _16$$10, _17$$11, _18$$11, _19$$12, _20$$12, _21$$13, _22$$14, _23$$15, _24$$16, _25$$17, _26$$18, _27$$20, _28$$21, _37$$27, _38$$27, _39$$27, _40$$27, _43$$28, _67$$28, _68$$28, _69$$28, _70$$28, _71$$28, _73$$28, _45$$29, _46$$29, _47$$30, _48$$30, _49$$30, _50$$32, _51$$32, _52$$33, _53$$34, _54$$35, _55$$36, _56$$36, _57$$37, _58$$37, _59$$38, _60$$39, _61$$40, _62$$41, _63$$42, _64$$43, _65$$45, _66$$46, _74$$52, _75$$52, _76$$52, _77$$52;
	zval table, schema;
	zval *this_ptr = getThis();

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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_29$$3);
	ZVAL_UNDEF(&_30$$3);
	ZVAL_UNDEF(&_31$$3);
	ZVAL_UNDEF(&_32$$3);
	ZVAL_UNDEF(&_33$$3);
	ZVAL_UNDEF(&_36$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$16);
	ZVAL_UNDEF(&_25$$17);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$20);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_37$$27);
	ZVAL_UNDEF(&_38$$27);
	ZVAL_UNDEF(&_39$$27);
	ZVAL_UNDEF(&_40$$27);
	ZVAL_UNDEF(&_43$$28);
	ZVAL_UNDEF(&_67$$28);
	ZVAL_UNDEF(&_68$$28);
	ZVAL_UNDEF(&_69$$28);
	ZVAL_UNDEF(&_70$$28);
	ZVAL_UNDEF(&_71$$28);
	ZVAL_UNDEF(&_73$$28);
	ZVAL_UNDEF(&_45$$29);
	ZVAL_UNDEF(&_46$$29);
	ZVAL_UNDEF(&_47$$30);
	ZVAL_UNDEF(&_48$$30);
	ZVAL_UNDEF(&_49$$30);
	ZVAL_UNDEF(&_50$$32);
	ZVAL_UNDEF(&_51$$32);
	ZVAL_UNDEF(&_52$$33);
	ZVAL_UNDEF(&_53$$34);
	ZVAL_UNDEF(&_54$$35);
	ZVAL_UNDEF(&_55$$36);
	ZVAL_UNDEF(&_56$$36);
	ZVAL_UNDEF(&_57$$37);
	ZVAL_UNDEF(&_58$$37);
	ZVAL_UNDEF(&_59$$38);
	ZVAL_UNDEF(&_60$$39);
	ZVAL_UNDEF(&_61$$40);
	ZVAL_UNDEF(&_62$$41);
	ZVAL_UNDEF(&_63$$42);
	ZVAL_UNDEF(&_64$$43);
	ZVAL_UNDEF(&_65$$45);
	ZVAL_UNDEF(&_66$$46);
	ZVAL_UNDEF(&_74$$52);
	ZVAL_UNDEF(&_75$$52);
	ZVAL_UNDEF(&_76$$52);
	ZVAL_UNDEF(&_77$$52);

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
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 297);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _4);
			ZEPHIR_INIT_NVAR(&definition);
			zephir_create_array(&definition, 1, 0 TSRMLS_CC);
			add_assoc_long_ex(&definition, SL("bindType"), 2);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 2, PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 120 TSRMLS_CC);
			_6$$3 = zephir_memnstr_str(&columnType, SL("int"), "phalcon/db/adapter/pdo/sqlite.zep", 141);
			if (!(_6$$3)) {
				_6$$3 = zephir_memnstr_str(&columnType, SL("INT"), "phalcon/db/adapter/pdo/sqlite.zep", 141);
			}
			if (zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/db/adapter/pdo/sqlite.zep", 134)) {
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZVAL_LONG(&_7$$4, 14);
				zephir_array_update_string(&definition, SL("type"), &_7$$4, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZVAL_LONG(&_8$$4, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_8$$4, PH_COPY | PH_SEPARATE);
			} else if (_6$$3) {
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_LONG(&_9$$5, 0);
				zephir_array_update_string(&definition, SL("type"), &_9$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZVAL_LONG(&_10$$5, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_10$$5, PH_COPY | PH_SEPARATE);
				zephir_array_fetch_long(&_11$$5, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 149 TSRMLS_CC);
				if (zephir_is_true(&_11$$5)) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
			} else if (zephir_memnstr_str(&columnType, SL("tinyint(1)"), "phalcon/db/adapter/pdo/sqlite.zep", 152)) {
				ZEPHIR_INIT_NVAR(&_12$$7);
				ZVAL_LONG(&_12$$7, 8);
				zephir_array_update_string(&definition, SL("type"), &_12$$7, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZVAL_LONG(&_13$$7, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_13$$7, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&columnType);
				ZVAL_STRING(&columnType, "boolean");
			} else if (zephir_memnstr_str(&columnType, SL("enum"), "phalcon/db/adapter/pdo/sqlite.zep", 163)) {
				ZEPHIR_INIT_NVAR(&_14$$8);
				ZVAL_LONG(&_14$$8, 5);
				zephir_array_update_string(&definition, SL("type"), &_14$$8, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/db/adapter/pdo/sqlite.zep", 172)) {
				ZEPHIR_INIT_NVAR(&_15$$9);
				ZVAL_LONG(&_15$$9, 4);
				zephir_array_update_string(&definition, SL("type"), &_15$$9, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("date"), "phalcon/db/adapter/pdo/sqlite.zep", 177)) {
				ZEPHIR_INIT_NVAR(&_16$$10);
				ZVAL_LONG(&_16$$10, 1);
				zephir_array_update_string(&definition, SL("type"), &_16$$10, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/db/adapter/pdo/sqlite.zep", 186)) {
				ZEPHIR_INIT_NVAR(&_17$$11);
				ZVAL_LONG(&_17$$11, 3);
				zephir_array_update_string(&definition, SL("type"), &_17$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_18$$11);
				ZVAL_LONG(&_18$$11, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_18$$11, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("float"), "phalcon/db/adapter/pdo/sqlite.zep", 193)) {
				ZEPHIR_INIT_NVAR(&_19$$12);
				ZVAL_LONG(&_19$$12, 7);
				zephir_array_update_string(&definition, SL("type"), &_19$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_20$$12);
				ZVAL_LONG(&_20$$12, 3);
				zephir_array_update_string(&definition, SL("bindType"), &_20$$12, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/db/adapter/pdo/sqlite.zep", 204)) {
				ZEPHIR_INIT_NVAR(&_21$$13);
				ZVAL_LONG(&_21$$13, 17);
				zephir_array_update_string(&definition, SL("type"), &_21$$13, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/db/adapter/pdo/sqlite.zep", 213)) {
				ZEPHIR_INIT_NVAR(&_22$$14);
				ZVAL_LONG(&_22$$14, 2);
				zephir_array_update_string(&definition, SL("type"), &_22$$14, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("char"), "phalcon/db/adapter/pdo/sqlite.zep", 218)) {
				ZEPHIR_INIT_NVAR(&_23$$15);
				ZVAL_LONG(&_23$$15, 5);
				zephir_array_update_string(&definition, SL("type"), &_23$$15, PH_COPY | PH_SEPARATE);
			} else if (zephir_memnstr_str(&columnType, SL("text"), "phalcon/db/adapter/pdo/sqlite.zep", 223)) {
				ZEPHIR_INIT_NVAR(&_24$$16);
				ZVAL_LONG(&_24$$16, 6);
				zephir_array_update_string(&definition, SL("type"), &_24$$16, PH_COPY | PH_SEPARATE);
			} else {
				ZEPHIR_INIT_NVAR(&_25$$17);
				ZVAL_LONG(&_25$$17, 2);
				zephir_array_update_string(&definition, SL("type"), &_25$$17, PH_COPY | PH_SEPARATE);
			}
			if (zephir_memnstr_str(&columnType, SL("("), "phalcon/db/adapter/pdo/sqlite.zep", 239)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				ZEPHIR_INIT_NVAR(&_26$$18);
				zephir_preg_match(&_26$$18, &sizePattern, &columnType, &matches, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(&_26$$18)) {
					ZEPHIR_OBS_NVAR(&matchOne);
					if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0 TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(&_27$$20);
						ZVAL_LONG(&_27$$20, zephir_get_intval(&matchOne));
						zephir_array_update_string(&definition, SL("size"), &_27$$20, PH_COPY | PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(&matchTwo);
					if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0 TSRMLS_CC)) {
						ZEPHIR_INIT_NVAR(&_28$$21);
						ZVAL_LONG(&_28$$21, zephir_get_intval(&matchTwo));
						zephir_array_update_string(&definition, SL("scale"), &_28$$21, PH_COPY | PH_SEPARATE);
					}
				}
			}
			if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/db/adapter/pdo/sqlite.zep", 254)) {
				zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&oldColumn) == IS_NULL) {
				zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_29$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 270 TSRMLS_CC);
			if (zephir_is_true(&_29$$3)) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_30$$3, &field, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 277 TSRMLS_CC);
			if (zephir_is_true(&_30$$3)) {
				zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_31$$3, &field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 285 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_32$$3);
			ZVAL_STRING(&_32$$3, "null");
			ZEPHIR_CALL_FUNCTION(&_33$$3, "strcasecmp", &_34, 19, &_31$$3, &_32$$3);
			zephir_check_call_status();
			_35$$3 = !ZEPHIR_IS_LONG(&_33$$3, 0);
			if (_35$$3) {
				zephir_array_fetch_long(&_36$$3, &field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 285 TSRMLS_CC);
				_35$$3 = !ZEPHIR_IS_STRING(&_36$$3, "");
			}
			if (_35$$3) {
				zephir_array_fetch_long(&_37$$27, &field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 286 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_38$$27);
				ZVAL_STRING(&_38$$27, "/^'|'$/");
				ZEPHIR_INIT_NVAR(&_39$$27);
				ZVAL_STRING(&_39$$27, "");
				ZEPHIR_CALL_FUNCTION(&_40$$27, "preg_replace", &_41, 21, &_38$$27, &_39$$27, &_37$$27);
				zephir_check_call_status();
				zephir_array_update_string(&definition, SL("default"), &_40$$27, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&columnName, &field, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 292 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_32$$3);
			object_init_ex(&_32$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_32$$3, "__construct", &_42, 142, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_32$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 293);
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
				ZEPHIR_INIT_NVAR(&_43$$28);
				zephir_create_array(&_43$$28, 1, 0 TSRMLS_CC);
				add_assoc_long_ex(&_43$$28, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_43$$28);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 2, PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 120 TSRMLS_CC);
				_44$$28 = zephir_memnstr_str(&columnType, SL("int"), "phalcon/db/adapter/pdo/sqlite.zep", 141);
				if (!(_44$$28)) {
					_44$$28 = zephir_memnstr_str(&columnType, SL("INT"), "phalcon/db/adapter/pdo/sqlite.zep", 141);
				}
				if (zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/db/adapter/pdo/sqlite.zep", 134)) {
					ZEPHIR_INIT_NVAR(&_45$$29);
					ZVAL_LONG(&_45$$29, 14);
					zephir_array_update_string(&definition, SL("type"), &_45$$29, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_46$$29);
					ZVAL_LONG(&_46$$29, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_46$$29, PH_COPY | PH_SEPARATE);
				} else if (_44$$28) {
					ZEPHIR_INIT_NVAR(&_47$$30);
					ZVAL_LONG(&_47$$30, 0);
					zephir_array_update_string(&definition, SL("type"), &_47$$30, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_48$$30);
					ZVAL_LONG(&_48$$30, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_48$$30, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_long(&_49$$30, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 149 TSRMLS_CC);
					if (zephir_is_true(&_49$$30)) {
						zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
					}
				} else if (zephir_memnstr_str(&columnType, SL("tinyint(1)"), "phalcon/db/adapter/pdo/sqlite.zep", 152)) {
					ZEPHIR_INIT_NVAR(&_50$$32);
					ZVAL_LONG(&_50$$32, 8);
					zephir_array_update_string(&definition, SL("type"), &_50$$32, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_51$$32);
					ZVAL_LONG(&_51$$32, 5);
					zephir_array_update_string(&definition, SL("bindType"), &_51$$32, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&columnType);
					ZVAL_STRING(&columnType, "boolean");
				} else if (zephir_memnstr_str(&columnType, SL("enum"), "phalcon/db/adapter/pdo/sqlite.zep", 163)) {
					ZEPHIR_INIT_NVAR(&_52$$33);
					ZVAL_LONG(&_52$$33, 5);
					zephir_array_update_string(&definition, SL("type"), &_52$$33, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/db/adapter/pdo/sqlite.zep", 172)) {
					ZEPHIR_INIT_NVAR(&_53$$34);
					ZVAL_LONG(&_53$$34, 4);
					zephir_array_update_string(&definition, SL("type"), &_53$$34, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("date"), "phalcon/db/adapter/pdo/sqlite.zep", 177)) {
					ZEPHIR_INIT_NVAR(&_54$$35);
					ZVAL_LONG(&_54$$35, 1);
					zephir_array_update_string(&definition, SL("type"), &_54$$35, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/db/adapter/pdo/sqlite.zep", 186)) {
					ZEPHIR_INIT_NVAR(&_55$$36);
					ZVAL_LONG(&_55$$36, 3);
					zephir_array_update_string(&definition, SL("type"), &_55$$36, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_56$$36);
					ZVAL_LONG(&_56$$36, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_56$$36, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("float"), "phalcon/db/adapter/pdo/sqlite.zep", 193)) {
					ZEPHIR_INIT_NVAR(&_57$$37);
					ZVAL_LONG(&_57$$37, 7);
					zephir_array_update_string(&definition, SL("type"), &_57$$37, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_58$$37);
					ZVAL_LONG(&_58$$37, 3);
					zephir_array_update_string(&definition, SL("bindType"), &_58$$37, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/db/adapter/pdo/sqlite.zep", 204)) {
					ZEPHIR_INIT_NVAR(&_59$$38);
					ZVAL_LONG(&_59$$38, 17);
					zephir_array_update_string(&definition, SL("type"), &_59$$38, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/db/adapter/pdo/sqlite.zep", 213)) {
					ZEPHIR_INIT_NVAR(&_60$$39);
					ZVAL_LONG(&_60$$39, 2);
					zephir_array_update_string(&definition, SL("type"), &_60$$39, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("char"), "phalcon/db/adapter/pdo/sqlite.zep", 218)) {
					ZEPHIR_INIT_NVAR(&_61$$40);
					ZVAL_LONG(&_61$$40, 5);
					zephir_array_update_string(&definition, SL("type"), &_61$$40, PH_COPY | PH_SEPARATE);
				} else if (zephir_memnstr_str(&columnType, SL("text"), "phalcon/db/adapter/pdo/sqlite.zep", 223)) {
					ZEPHIR_INIT_NVAR(&_62$$41);
					ZVAL_LONG(&_62$$41, 6);
					zephir_array_update_string(&definition, SL("type"), &_62$$41, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_63$$42);
					ZVAL_LONG(&_63$$42, 2);
					zephir_array_update_string(&definition, SL("type"), &_63$$42, PH_COPY | PH_SEPARATE);
				}
				if (zephir_memnstr_str(&columnType, SL("("), "phalcon/db/adapter/pdo/sqlite.zep", 239)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					ZEPHIR_INIT_NVAR(&_64$$43);
					zephir_preg_match(&_64$$43, &sizePattern, &columnType, &matches, 0, 0 , 0  TSRMLS_CC);
					if (zephir_is_true(&_64$$43)) {
						ZEPHIR_OBS_NVAR(&matchOne);
						if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0 TSRMLS_CC)) {
							ZEPHIR_INIT_NVAR(&_65$$45);
							ZVAL_LONG(&_65$$45, zephir_get_intval(&matchOne));
							zephir_array_update_string(&definition, SL("size"), &_65$$45, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&matchTwo);
						if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0 TSRMLS_CC)) {
							ZEPHIR_INIT_NVAR(&_66$$46);
							ZVAL_LONG(&_66$$46, zephir_get_intval(&matchTwo));
							zephir_array_update_string(&definition, SL("scale"), &_66$$46, PH_COPY | PH_SEPARATE);
						}
					}
				}
				if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/db/adapter/pdo/sqlite.zep", 254)) {
					zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
				}
				if (Z_TYPE_P(&oldColumn) == IS_NULL) {
					zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_67$$28, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 270 TSRMLS_CC);
				if (zephir_is_true(&_67$$28)) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_68$$28, &field, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 277 TSRMLS_CC);
				if (zephir_is_true(&_68$$28)) {
					zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_69$$28, &field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 285 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_70$$28);
				ZVAL_STRING(&_70$$28, "null");
				ZEPHIR_CALL_FUNCTION(&_71$$28, "strcasecmp", &_34, 19, &_69$$28, &_70$$28);
				zephir_check_call_status();
				_72$$28 = !ZEPHIR_IS_LONG(&_71$$28, 0);
				if (_72$$28) {
					zephir_array_fetch_long(&_73$$28, &field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 285 TSRMLS_CC);
					_72$$28 = !ZEPHIR_IS_STRING(&_73$$28, "");
				}
				if (_72$$28) {
					zephir_array_fetch_long(&_74$$52, &field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 286 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_75$$52);
					ZVAL_STRING(&_75$$52, "/^'|'$/");
					ZEPHIR_INIT_NVAR(&_76$$52);
					ZVAL_STRING(&_76$$52, "");
					ZEPHIR_CALL_FUNCTION(&_77$$52, "preg_replace", &_41, 21, &_75$$52, &_76$$52, &_74$$52);
					zephir_check_call_status();
					zephir_array_update_string(&definition, SL("default"), &_77$$52, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 1, PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 292 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_70$$28);
				object_init_ex(&_70$$28, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_70$$28, "__construct", &_42, 142, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_70$$28, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 293);
				ZEPHIR_CPY_WRT(&oldColumn, &columnName);
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	RETURN_CCTOR(&columns);

}

/**
 * Lists table indexes
 *
 * <code>
 * print_r(
 *     $connection->describeIndexes("robots_parts")
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeIndexes) {

	zend_string *_48;
	zend_ulong _47;
	zephir_fcall_cache_entry *_18 = NULL, *_52 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$null, indexes, index, keyName, indexObjects, name, columns, describeIndex, indexSql, _0, _1, _2, _3, *_4, _5, *_45, _46, _6$$4, _7$$3, _9$$3, _10$$3, _11$$3, _12$$3, *_13$$3, _14$$3, _17$$3, _19$$3, _8$$6, _15$$7, _16$$8, _20$$9, _21$$9, _22$$9, _23$$9, _24$$10, _25$$11, _26$$14, _27$$13, _29$$13, _30$$13, _31$$13, _32$$13, *_33$$13, _34$$13, _37$$13, _38$$13, _28$$16, _35$$17, _36$$18, _39$$19, _40$$19, _41$$19, _42$$19, _43$$20, _44$$21, _49$$23, _50$$23, _51$$23, _53$$24, _54$$24, _55$$24;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_46);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$9);
	ZVAL_UNDEF(&_24$$10);
	ZVAL_UNDEF(&_25$$11);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$13);
	ZVAL_UNDEF(&_29$$13);
	ZVAL_UNDEF(&_30$$13);
	ZVAL_UNDEF(&_31$$13);
	ZVAL_UNDEF(&_32$$13);
	ZVAL_UNDEF(&_34$$13);
	ZVAL_UNDEF(&_37$$13);
	ZVAL_UNDEF(&_38$$13);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_36$$18);
	ZVAL_UNDEF(&_39$$19);
	ZVAL_UNDEF(&_40$$19);
	ZVAL_UNDEF(&_41$$19);
	ZVAL_UNDEF(&_42$$19);
	ZVAL_UNDEF(&_43$$20);
	ZVAL_UNDEF(&_44$$21);
	ZVAL_UNDEF(&_49$$23);
	ZVAL_UNDEF(&_50$$23);
	ZVAL_UNDEF(&_51$$23);
	ZVAL_UNDEF(&_53$$24);
	ZVAL_UNDEF(&_54$$24);
	ZVAL_UNDEF(&_55$$24);

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


	ZEPHIR_INIT_VAR(&indexes);
	array_init(&indexes);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeindexes", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 345);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _4);
			ZEPHIR_OBS_NVAR(&keyName);
			zephir_array_fetch_string(&keyName, &index, SL("name"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 315 TSRMLS_CC);
			if (!(zephir_array_isset(&indexes, &keyName))) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				array_init(&_6$$4);
				zephir_array_update_zval(&indexes, &keyName, &_6$$4, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch(&_7$$3, &indexes, &keyName, PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 321 TSRMLS_CC);
			if (!(zephir_array_isset_string(&_7$$3, SL("columns")))) {
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
			} else {
				zephir_array_fetch(&_8$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 324 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_8$$6, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 324 TSRMLS_CC);
			}
			zephir_read_property(&_10$$3, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_11$$3, &_10$$3, "describeindex", NULL, 0, &keyName);
			zephir_check_call_status();
			ZVAL_LONG(&_12$$3, 2);
			ZEPHIR_CALL_METHOD(&_9$$3, this_ptr, "fetchall", NULL, 0, &_11$$3, &_12$$3);
			zephir_check_call_status();
			zephir_is_iterable(&_9$$3, 0, "phalcon/db/adapter/pdo/sqlite.zep", 331);
			if (Z_TYPE_P(&_9$$3) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_9$$3), _13$$3)
				{
					ZEPHIR_INIT_NVAR(&describeIndex);
					ZVAL_COPY(&describeIndex, _13$$3);
					zephir_array_fetch_string(&_15$$7, &describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 328 TSRMLS_CC);
					zephir_array_append(&columns, &_15$$7, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 328);
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_9$$3, "rewind", NULL, 0);
				zephir_check_call_status();
				while (1) {
					ZEPHIR_CALL_METHOD(&_14$$3, &_9$$3, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_14$$3)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&describeIndex, &_9$$3, "current", NULL, 0);
					zephir_check_call_status();
						zephir_array_fetch_string(&_16$$8, &describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 328 TSRMLS_CC);
						zephir_array_append(&columns, &_16$$8, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 328);
					ZEPHIR_CALL_METHOD(NULL, &_9$$3, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&describeIndex);
			zephir_array_update_multi(&indexes, &columns TSRMLS_CC, SL("zs"), 3, &keyName, SL("columns"));
			zephir_read_property(&_12$$3, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
			ZEPHIR_CALL_METHOD(&_17$$3, &_12$$3, "listindexessql", NULL, 0, &table, &schema, &keyName);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&indexSql, this_ptr, "fetchcolumn", &_18, 0, &_17$$3);
			zephir_check_call_status();
			zephir_array_fetch_string(&_19$$3, &index, SL("unique"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 334 TSRMLS_CC);
			if (zephir_is_true(&_19$$3)) {
				ZEPHIR_INIT_NVAR(&_20$$9);
				ZEPHIR_INIT_NVAR(&_21$$9);
				ZVAL_STRING(&_21$$9, "# UNIQUE #i");
				ZEPHIR_INIT_NVAR(&_22$$9);
				ZEPHIR_INIT_NVAR(&_23$$9);
				ZVAL_STRING(&_23$$9, "# UNIQUE #i");
				zephir_preg_match(&_22$$9, &_23$$9, &indexSql, &_20$$9, 0, 0 , 0  TSRMLS_CC);
				if (zephir_is_true(&_22$$9)) {
					ZEPHIR_INIT_NVAR(&_24$$10);
					ZVAL_STRING(&_24$$10, "UNIQUE");
					zephir_array_update_multi(&indexes, &_24$$10 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
				} else {
					ZEPHIR_INIT_NVAR(&_25$$11);
					ZVAL_STRING(&_25$$11, "PRIMARY");
					zephir_array_update_multi(&indexes, &_25$$11 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
				}
			} else {
				zephir_array_update_multi(&indexes, &__$null TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
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
				zephir_array_fetch_string(&keyName, &index, SL("name"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 315 TSRMLS_CC);
				if (!(zephir_array_isset(&indexes, &keyName))) {
					ZEPHIR_INIT_NVAR(&_26$$14);
					array_init(&_26$$14);
					zephir_array_update_zval(&indexes, &keyName, &_26$$14, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch(&_27$$13, &indexes, &keyName, PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 321 TSRMLS_CC);
				if (!(zephir_array_isset_string(&_27$$13, SL("columns")))) {
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
				} else {
					zephir_array_fetch(&_28$$16, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 324 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_28$$16, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 324 TSRMLS_CC);
				}
				zephir_read_property(&_30$$13, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_31$$13, &_30$$13, "describeindex", NULL, 0, &keyName);
				zephir_check_call_status();
				ZVAL_LONG(&_32$$13, 2);
				ZEPHIR_CALL_METHOD(&_29$$13, this_ptr, "fetchall", NULL, 0, &_31$$13, &_32$$13);
				zephir_check_call_status();
				zephir_is_iterable(&_29$$13, 0, "phalcon/db/adapter/pdo/sqlite.zep", 331);
				if (Z_TYPE_P(&_29$$13) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_29$$13), _33$$13)
					{
						ZEPHIR_INIT_NVAR(&describeIndex);
						ZVAL_COPY(&describeIndex, _33$$13);
						zephir_array_fetch_string(&_35$$17, &describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 328 TSRMLS_CC);
						zephir_array_append(&columns, &_35$$17, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 328);
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &_29$$13, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_34$$13, &_29$$13, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_34$$13)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&describeIndex, &_29$$13, "current", NULL, 0);
						zephir_check_call_status();
							zephir_array_fetch_string(&_36$$18, &describeIndex, SL("name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 328 TSRMLS_CC);
							zephir_array_append(&columns, &_36$$18, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 328);
						ZEPHIR_CALL_METHOD(NULL, &_29$$13, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&describeIndex);
				zephir_array_update_multi(&indexes, &columns TSRMLS_CC, SL("zs"), 3, &keyName, SL("columns"));
				zephir_read_property(&_32$$13, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
				ZEPHIR_CALL_METHOD(&_37$$13, &_32$$13, "listindexessql", NULL, 0, &table, &schema, &keyName);
				zephir_check_call_status();
				ZEPHIR_CALL_METHOD(&indexSql, this_ptr, "fetchcolumn", &_18, 0, &_37$$13);
				zephir_check_call_status();
				zephir_array_fetch_string(&_38$$13, &index, SL("unique"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 334 TSRMLS_CC);
				if (zephir_is_true(&_38$$13)) {
					ZEPHIR_INIT_NVAR(&_39$$19);
					ZEPHIR_INIT_NVAR(&_40$$19);
					ZVAL_STRING(&_40$$19, "# UNIQUE #i");
					ZEPHIR_INIT_NVAR(&_41$$19);
					ZEPHIR_INIT_NVAR(&_42$$19);
					ZVAL_STRING(&_42$$19, "# UNIQUE #i");
					zephir_preg_match(&_41$$19, &_42$$19, &indexSql, &_39$$19, 0, 0 , 0  TSRMLS_CC);
					if (zephir_is_true(&_41$$19)) {
						ZEPHIR_INIT_NVAR(&_43$$20);
						ZVAL_STRING(&_43$$20, "UNIQUE");
						zephir_array_update_multi(&indexes, &_43$$20 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
					} else {
						ZEPHIR_INIT_NVAR(&_44$$21);
						ZVAL_STRING(&_44$$21, "PRIMARY");
						zephir_array_update_multi(&indexes, &_44$$21 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
					}
				} else {
					zephir_array_update_multi(&indexes, &__$null TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	zephir_is_iterable(&indexes, 0, "phalcon/db/adapter/pdo/sqlite.zep", 350);
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
			zephir_array_fetch_string(&_50$$23, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 347 TSRMLS_CC);
			zephir_array_fetch_string(&_51$$23, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 347 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, &_49$$23, "__construct", &_52, 15, &name, &_50$$23, &_51$$23);
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
				zephir_array_fetch_string(&_54$$24, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 347 TSRMLS_CC);
				zephir_array_fetch_string(&_55$$24, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 347 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, &_53$$24, "__construct", &_52, 15, &name, &_54$$24, &_55$$24);
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, describeReferences) {

	zval _14$$3, _21$$6, _27$$9, _31$$10;
	zend_string *_7, *_25;
	zend_ulong _6, _24;
	zephir_fcall_cache_entry *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, number, _0, _1, _2, _3, *_4, _5, *_22, _23, _8$$5, _9$$5, _10$$5, _11$$5, _12$$3, _13$$3, _15$$8, _16$$8, _17$$8, _18$$8, _19$$6, _20$$6, _26$$9, _28$$9, _30$$10, _32$$10;
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
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/sqlite.zep", 391);
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
				zephir_array_fetch_long(&referencedTable, &reference, 2, PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 370 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 374 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_8$$5, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 374 TSRMLS_CC);
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 375 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_9$$5, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 375 TSRMLS_CC);
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 376 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_10$$5, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 376 TSRMLS_CC);
				zephir_array_fetch(&_11$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 377 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_11$$5, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 377 TSRMLS_CC);
			}
			zephir_array_fetch_long(&_12$$3, &reference, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 380 TSRMLS_CC);
			zephir_array_append(&columns, &_12$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 380);
			zephir_array_fetch_long(&_13$$3, &reference, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 381 TSRMLS_CC);
			zephir_array_append(&referencedColumns, &_13$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 381);
			ZEPHIR_INIT_NVAR(&_14$$3);
			zephir_create_array(&_14$$3, 4, 0 TSRMLS_CC);
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
					zephir_array_fetch_long(&referencedTable, &reference, 2, PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 370 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_15$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 374 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_15$$8, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 374 TSRMLS_CC);
					zephir_array_fetch(&_16$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 375 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_16$$8, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 375 TSRMLS_CC);
					zephir_array_fetch(&_17$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 376 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_17$$8, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 376 TSRMLS_CC);
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 377 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_18$$8, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 377 TSRMLS_CC);
				}
				zephir_array_fetch_long(&_19$$6, &reference, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 380 TSRMLS_CC);
				zephir_array_append(&columns, &_19$$6, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 380);
				zephir_array_fetch_long(&_20$$6, &reference, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/sqlite.zep", 381 TSRMLS_CC);
				zephir_array_append(&referencedColumns, &_20$$6, PH_SEPARATE, "phalcon/db/adapter/pdo/sqlite.zep", 381);
				ZEPHIR_INIT_NVAR(&_21$$6);
				zephir_create_array(&_21$$6, 4, 0 TSRMLS_CC);
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
	zephir_is_iterable(&references, 0, "phalcon/db/adapter/pdo/sqlite.zep", 401);
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
			zephir_create_array(&_27$$9, 4, 0 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&_28$$9);
			zephir_array_fetch_string(&_28$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 394 TSRMLS_CC);
			zephir_array_update_string(&_27$$9, SL("referencedSchema"), &_28$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_28$$9);
			zephir_array_fetch_string(&_28$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 395 TSRMLS_CC);
			zephir_array_update_string(&_27$$9, SL("referencedTable"), &_28$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_28$$9);
			zephir_array_fetch_string(&_28$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 396 TSRMLS_CC);
			zephir_array_update_string(&_27$$9, SL("columns"), &_28$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_28$$9);
			zephir_array_fetch_string(&_28$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 398 TSRMLS_CC);
			zephir_array_update_string(&_27$$9, SL("referencedColumns"), &_28$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_26$$9, "__construct", &_29, 16, &name, &_27$$9);
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
				zephir_create_array(&_31$$10, 4, 0 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&_32$$10);
				zephir_array_fetch_string(&_32$$10, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 394 TSRMLS_CC);
				zephir_array_update_string(&_31$$10, SL("referencedSchema"), &_32$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_32$$10);
				zephir_array_fetch_string(&_32$$10, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 395 TSRMLS_CC);
				zephir_array_update_string(&_31$$10, SL("referencedTable"), &_32$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_32$$10);
				zephir_array_fetch_string(&_32$$10, &arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 396 TSRMLS_CC);
				zephir_array_update_string(&_31$$10, SL("columns"), &_32$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_32$$10);
				zephir_array_fetch_string(&_32$$10, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/sqlite.zep", 398 TSRMLS_CC);
				zephir_array_update_string(&_31$$10, SL("referencedColumns"), &_32$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &_30$$10, "__construct", &_29, 16, &name, &_31$$10);
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
 * Returns the default value to make the RBDM use the default value declared in the table definition
 *
 *<code>
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
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, getDefaultValue) {

	zval _0;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "NULL");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 17, &_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether the database system requires an explicit value for identity columns
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Sqlite, useExplicitIdValue) {

	zval *this_ptr = getThis();


	RETURN_BOOL(1);

}

