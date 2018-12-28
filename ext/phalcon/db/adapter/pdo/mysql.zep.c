
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/array.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Db\Adapter\Pdo\Mysql
 *
 * Specific functions for the Mysql database system
 *
 *<code>
 * use Phalcon\Db\Adapter\Pdo\Mysql;
 *
 * $config = [
 *     "host"     => "localhost",
 *     "dbname"   => "blog",
 *     "port"     => 3306,
 *     "username" => "sigma",
 *     "password" => "secret",
 * ];
 *
 * $connection = new Mysql($config);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Mysql, phalcon, db_adapter_pdo_mysql, phalcon_db_adapter_pdo_ce, phalcon_db_adapter_pdo_mysql_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_dialectType"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_type"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Adds a foreign key to a table
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, addForeignKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, reference_sub, foreignKeyCheck, _0, _1, _2, _3, _4;
	zval tableName, schemaName;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName);
	ZVAL_UNDEF(&schemaName);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&foreignKeyCheck);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

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


	zephir_read_property(&_0, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getforeignkeychecks", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&foreignKeyCheck, this_ptr, "prepare", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &foreignKeyCheck, "execute", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "DATABASE PARAMETER 'FOREIGN_KEY_CHECKS' HAS TO BE 1", "phalcon/db/adapter/pdo/mysql.zep", 58);
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "addforeignkey", NULL, 0, &tableName, &schemaName, reference);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_4);
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns) {

	zend_bool _5$$3;
	zephir_fcall_cache_entry *_55 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$true, columns, columnType, field, definition, oldColumn, sizePattern, matches, matchOne, matchTwo, columnName, _0, _1, _2, _3, *_4, _49$$3, _50$$3, _51$$3, _52$$3, _54$$3, _6$$4, _7$$4, _8$$5, _9$$5, _10$$6, _11$$6, _12$$7, _13$$7, _14$$8, _15$$8, _16$$9, _17$$9, _18$$10, _19$$10, _20$$11, _21$$12, _22$$13, _23$$14, _24$$15, _25$$15, _26$$16, _27$$16, _28$$17, _29$$18, _30$$19, _31$$20, _32$$21, _33$$22, _34$$23, _35$$24, _36$$25, _37$$26, _38$$27, _39$$28, _40$$29, _41$$30, _42$$31, _43$$31, _44$$32, _45$$32, _46$$32, _47$$34, _48$$35, _53$$42;
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
	ZVAL_UNDEF(&_49$$3);
	ZVAL_UNDEF(&_50$$3);
	ZVAL_UNDEF(&_51$$3);
	ZVAL_UNDEF(&_52$$3);
	ZVAL_UNDEF(&_54$$3);
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
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_29$$18);
	ZVAL_UNDEF(&_30$$19);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$21);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_35$$24);
	ZVAL_UNDEF(&_36$$25);
	ZVAL_UNDEF(&_37$$26);
	ZVAL_UNDEF(&_38$$27);
	ZVAL_UNDEF(&_39$$28);
	ZVAL_UNDEF(&_40$$29);
	ZVAL_UNDEF(&_41$$30);
	ZVAL_UNDEF(&_42$$31);
	ZVAL_UNDEF(&_43$$31);
	ZVAL_UNDEF(&_44$$32);
	ZVAL_UNDEF(&_45$$32);
	ZVAL_UNDEF(&_46$$32);
	ZVAL_UNDEF(&_47$$34);
	ZVAL_UNDEF(&_48$$35);
	ZVAL_UNDEF(&_53$$42);

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
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/mysql.zep", 399);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&field);
		ZVAL_COPY(&field, _4);
		ZEPHIR_INIT_NVAR(&definition);
		zephir_create_array(&definition, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(&definition, SL("bindType"), 2);
		ZEPHIR_OBS_NVAR(&columnType);
		zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 99 TSRMLS_CC);
		do {
			_5$$3 = 1;
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinyint(1)"), "phalcon/db/adapter/pdo/mysql.zep", 116)) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				ZVAL_LONG(&_6$$4, 8);
				zephir_array_update_string(&definition, SL("type"), &_6$$4, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZVAL_LONG(&_7$$4, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_7$$4, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/db/adapter/pdo/mysql.zep", 128)) {
				ZEPHIR_INIT_NVAR(&_8$$5);
				ZVAL_LONG(&_8$$5, 14);
				zephir_array_update_string(&definition, SL("type"), &_8$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_LONG(&_9$$5, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_9$$5, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("mediumint"), "phalcon/db/adapter/pdo/mysql.zep", 137)) {
				ZEPHIR_INIT_NVAR(&_10$$6);
				ZVAL_LONG(&_10$$6, 21);
				zephir_array_update_string(&definition, SL("type"), &_10$$6, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZVAL_LONG(&_11$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_11$$6, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("smallint"), "phalcon/db/adapter/pdo/mysql.zep", 146)) {
				ZEPHIR_INIT_NVAR(&_12$$7);
				ZVAL_LONG(&_12$$7, 22);
				zephir_array_update_string(&definition, SL("type"), &_12$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZVAL_LONG(&_13$$7, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_13$$7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinyint"), "phalcon/db/adapter/pdo/mysql.zep", 155)) {
				ZEPHIR_INIT_NVAR(&_14$$8);
				ZVAL_LONG(&_14$$8, 26);
				zephir_array_update_string(&definition, SL("type"), &_14$$8, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_15$$8);
				ZVAL_LONG(&_15$$8, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_15$$8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("int"), "phalcon/db/adapter/pdo/mysql.zep", 167)) {
				ZEPHIR_INIT_NVAR(&_16$$9);
				ZVAL_LONG(&_16$$9, 0);
				zephir_array_update_string(&definition, SL("type"), &_16$$9, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_17$$9);
				ZVAL_LONG(&_17$$9, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_17$$9, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("bit"), "phalcon/db/adapter/pdo/mysql.zep", 177)) {
				ZEPHIR_INIT_NVAR(&_18$$10);
				ZVAL_LONG(&_18$$10, 19);
				zephir_array_update_string(&definition, SL("type"), &_18$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_19$$10);
				ZVAL_LONG(&_19$$10, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_19$$10, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("enum"), "phalcon/db/adapter/pdo/mysql.zep", 185)) {
				ZEPHIR_INIT_NVAR(&_20$$11);
				ZVAL_LONG(&_20$$11, 18);
				zephir_array_update_string(&definition, SL("type"), &_20$$11, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/db/adapter/pdo/mysql.zep", 193)) {
				ZEPHIR_INIT_NVAR(&_21$$12);
				ZVAL_LONG(&_21$$12, 4);
				zephir_array_update_string(&definition, SL("type"), &_21$$12, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("date"), "phalcon/db/adapter/pdo/mysql.zep", 200)) {
				ZEPHIR_INIT_NVAR(&_22$$13);
				ZVAL_LONG(&_22$$13, 1);
				zephir_array_update_string(&definition, SL("type"), &_22$$13, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/db/adapter/pdo/mysql.zep", 208)) {
				ZEPHIR_INIT_NVAR(&_23$$14);
				ZVAL_LONG(&_23$$14, 3);
				zephir_array_update_string(&definition, SL("type"), &_23$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("double"), "phalcon/db/adapter/pdo/mysql.zep", 216)) {
				ZEPHIR_INIT_NVAR(&_24$$15);
				ZVAL_LONG(&_24$$15, 9);
				zephir_array_update_string(&definition, SL("type"), &_24$$15, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_25$$15);
				ZVAL_LONG(&_25$$15, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_25$$15, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("float"), "phalcon/db/adapter/pdo/mysql.zep", 225)) {
				ZEPHIR_INIT_NVAR(&_26$$16);
				ZVAL_LONG(&_26$$16, 7);
				zephir_array_update_string(&definition, SL("type"), &_26$$16, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_27$$16);
				ZVAL_LONG(&_27$$16, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_27$$16, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/db/adapter/pdo/mysql.zep", 234)) {
				ZEPHIR_INIT_NVAR(&_28$$17);
				ZVAL_LONG(&_28$$17, 12);
				zephir_array_update_string(&definition, SL("type"), &_28$$17, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/db/adapter/pdo/mysql.zep", 241)) {
				ZEPHIR_INIT_NVAR(&_29$$18);
				ZVAL_LONG(&_29$$18, 13);
				zephir_array_update_string(&definition, SL("type"), &_29$$18, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/db/adapter/pdo/mysql.zep", 248)) {
				ZEPHIR_INIT_NVAR(&_30$$19);
				ZVAL_LONG(&_30$$19, 10);
				zephir_array_update_string(&definition, SL("type"), &_30$$19, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("blob"), "phalcon/db/adapter/pdo/mysql.zep", 255)) {
				ZEPHIR_INIT_NVAR(&_31$$20);
				ZVAL_LONG(&_31$$20, 11);
				zephir_array_update_string(&definition, SL("type"), &_31$$20, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/db/adapter/pdo/mysql.zep", 262)) {
				ZEPHIR_INIT_NVAR(&_32$$21);
				ZVAL_LONG(&_32$$21, 17);
				zephir_array_update_string(&definition, SL("type"), &_32$$21, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("time"), "phalcon/db/adapter/pdo/mysql.zep", 269)) {
				ZEPHIR_INIT_NVAR(&_33$$22);
				ZVAL_LONG(&_33$$22, 20);
				zephir_array_update_string(&definition, SL("type"), &_33$$22, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("json"), "phalcon/db/adapter/pdo/mysql.zep", 276)) {
				ZEPHIR_INIT_NVAR(&_34$$23);
				ZVAL_LONG(&_34$$23, 15);
				zephir_array_update_string(&definition, SL("type"), &_34$$23, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("longtext"), "phalcon/db/adapter/pdo/mysql.zep", 283)) {
				ZEPHIR_INIT_NVAR(&_35$$24);
				ZVAL_LONG(&_35$$24, 24);
				zephir_array_update_string(&definition, SL("type"), &_35$$24, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("mediumtext"), "phalcon/db/adapter/pdo/mysql.zep", 290)) {
				ZEPHIR_INIT_NVAR(&_36$$25);
				ZVAL_LONG(&_36$$25, 23);
				zephir_array_update_string(&definition, SL("type"), &_36$$25, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinytext"), "phalcon/db/adapter/pdo/mysql.zep", 297)) {
				ZEPHIR_INIT_NVAR(&_37$$26);
				ZVAL_LONG(&_37$$26, 25);
				zephir_array_update_string(&definition, SL("type"), &_37$$26, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("text"), "phalcon/db/adapter/pdo/mysql.zep", 304)) {
				ZEPHIR_INIT_NVAR(&_38$$27);
				ZVAL_LONG(&_38$$27, 6);
				zephir_array_update_string(&definition, SL("type"), &_38$$27, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/db/adapter/pdo/mysql.zep", 311)) {
				ZEPHIR_INIT_NVAR(&_39$$28);
				ZVAL_LONG(&_39$$28, 2);
				zephir_array_update_string(&definition, SL("type"), &_39$$28, PH_COPY | PH_SEPARATE);
				break;
			}
			if (_5$$3 == zephir_memnstr_str(&columnType, SL("char"), "phalcon/db/adapter/pdo/mysql.zep", 318)) {
				ZEPHIR_INIT_NVAR(&_40$$29);
				ZVAL_LONG(&_40$$29, 5);
				zephir_array_update_string(&definition, SL("type"), &_40$$29, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(&_41$$30);
			ZVAL_LONG(&_41$$30, 2);
			zephir_array_update_string(&definition, SL("type"), &_41$$30, PH_COPY | PH_SEPARATE);
			break;
		} while(0);

		if (zephir_memnstr_str(&columnType, SL("("), "phalcon/db/adapter/pdo/mysql.zep", 333)) {
			ZEPHIR_INIT_NVAR(&matches);
			ZVAL_NULL(&matches);
			zephir_array_fetch_string(&_42$$31, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 335 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_43$$31);
			zephir_preg_match(&_43$$31, &sizePattern, &columnType, &matches, 0, 0 , 0  TSRMLS_CC);
			if (ZEPHIR_IS_LONG(&_42$$31, 18)) {
				ZVAL_LONG(&_44$$32, 5);
				ZVAL_LONG(&_45$$32, -1);
				ZEPHIR_INIT_NVAR(&_46$$32);
				zephir_substr(&_46$$32, &columnType, 5 , -1 , 0);
				zephir_array_update_string(&definition, SL("size"), &_46$$32, PH_COPY | PH_SEPARATE);
			} else if (zephir_is_true(&_43$$31)) {
				ZEPHIR_OBS_NVAR(&matchOne);
				if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(&_47$$34);
					ZVAL_LONG(&_47$$34, zephir_get_intval(&matchOne));
					zephir_array_update_string(&definition, SL("size"), &_47$$34, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&matchTwo);
				if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(&_48$$35);
					ZVAL_LONG(&_48$$35, zephir_get_intval(&matchTwo));
					zephir_array_update_string(&definition, SL("scale"), &_48$$35, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/db/adapter/pdo/mysql.zep", 350)) {
			zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_49$$3, &field, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 366 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_49$$3, "PRI")) {
			zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_50$$3, &field, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 373 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_50$$3, "NO")) {
			zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_51$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 380 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_51$$3, "auto_increment")) {
			zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_NVAR(&_52$$3);
		zephir_array_fetch_long(&_52$$3, &field, 4, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 387 TSRMLS_CC);
		if (Z_TYPE_P(&_52$$3) != IS_NULL) {
			zephir_array_fetch_long(&_53$$42, &field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 388 TSRMLS_CC);
			zephir_array_update_string(&definition, SL("default"), &_53$$42, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 394 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_54$$3);
		object_init_ex(&_54$$3, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, &_54$$3, "__construct", &_55, 132, &columnName, &definition);
		zephir_check_call_status();
		zephir_array_append(&columns, &_54$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 395);
		ZEPHIR_CPY_WRT(&oldColumn, &columnName);
	} ZEND_HASH_FOREACH_END();
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeIndexes) {

	zend_string *_15;
	zend_ulong _14;
	zephir_fcall_cache_entry *_19 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$null, indexes, index, keyName, indexType, indexObjects, columns, name, _0, _1, _2, _3, *_4, *_13, _5$$4, _6$$3, _8$$3, _9$$3, _7$$6, _10$$7, _11$$8, _12$$9, _16$$11, _17$$11, _18$$11;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&indexObjects);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);

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
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/mysql.zep", 444);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_COPY(&index, _4);
		zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 417 TSRMLS_CC);
		zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 418 TSRMLS_CC);
		if (!(zephir_array_isset(&indexes, &keyName))) {
			ZEPHIR_INIT_NVAR(&_5$$4);
			array_init(&_5$$4);
			zephir_array_update_zval(&indexes, &keyName, &_5$$4, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch(&_6$$3, &indexes, &keyName, PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 424 TSRMLS_CC);
		if (!(zephir_array_isset_string(&_6$$3, SL("columns")))) {
			ZEPHIR_INIT_NVAR(&columns);
			array_init(&columns);
		} else {
			zephir_array_fetch(&_7$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 427 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&columns);
			zephir_array_fetch_string(&columns, &_7$$6, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 427 TSRMLS_CC);
		}
		zephir_array_fetch_string(&_8$$3, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 430 TSRMLS_CC);
		zephir_array_append(&columns, &_8$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 430);
		zephir_array_update_multi(&indexes, &columns TSRMLS_CC, SL("zs"), 3, &keyName, SL("columns"));
		zephir_array_fetch_string(&_9$$3, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 437 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
			ZEPHIR_INIT_NVAR(&_10$$7);
			ZVAL_STRING(&_10$$7, "PRIMARY");
			zephir_array_update_multi(&indexes, &_10$$7 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
		} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
			ZEPHIR_INIT_NVAR(&_11$$8);
			ZVAL_STRING(&_11$$8, "FULLTEXT");
			zephir_array_update_multi(&indexes, &_11$$8 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
		} else if (ZEPHIR_IS_LONG(&_9$$3, 0)) {
			ZEPHIR_INIT_NVAR(&_12$$9);
			ZVAL_STRING(&_12$$9, "UNIQUE");
			zephir_array_update_multi(&indexes, &_12$$9 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
		} else {
			zephir_array_update_multi(&indexes, &__$null TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	zephir_is_iterable(&indexes, 0, "phalcon/db/adapter/pdo/mysql.zep", 449);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&indexes), _14, _15, _13)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_15 != NULL) { 
			ZVAL_STR_COPY(&name, _15);
		} else {
			ZVAL_LONG(&name, _14);
		}
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_COPY(&index, _13);
		ZEPHIR_INIT_NVAR(&_16$$11);
		object_init_ex(&_16$$11, phalcon_db_index_ce);
		zephir_array_fetch_string(&_17$$11, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 446 TSRMLS_CC);
		zephir_array_fetch_string(&_18$$11, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 446 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_16$$11, "__construct", &_19, 14, &name, &_17$$11, &_18$$11);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, &name, &_16$$11, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&indexObjects);

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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeReferences) {

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
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/mysql.zep", 503);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&reference);
		ZVAL_COPY(&reference, _4);
		zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 472 TSRMLS_CC);
		if (!(zephir_array_isset(&references, &constraintName))) {
			ZEPHIR_OBS_NVAR(&referencedSchema);
			zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 474 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedTable);
			zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 475 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referenceUpdate);
			zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 476 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referenceDelete);
			zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 477 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&columns);
			array_init(&columns);
			ZEPHIR_INIT_NVAR(&referencedColumns);
			array_init(&referencedColumns);
		} else {
			zephir_array_fetch(&_5$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 482 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedSchema);
			zephir_array_fetch_string(&referencedSchema, &_5$$5, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 482 TSRMLS_CC);
			zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 483 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedTable);
			zephir_array_fetch_string(&referencedTable, &_6$$5, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 483 TSRMLS_CC);
			zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 484 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&columns);
			zephir_array_fetch_string(&columns, &_7$$5, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 484 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 485 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedColumns);
			zephir_array_fetch_string(&referencedColumns, &_8$$5, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 485 TSRMLS_CC);
			zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 486 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referenceUpdate);
			zephir_array_fetch_string(&referenceUpdate, &_9$$5, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 486 TSRMLS_CC);
			zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 487 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referenceDelete);
			zephir_array_fetch_string(&referenceDelete, &_10$$5, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 487 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_11$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 490 TSRMLS_CC);
		zephir_array_append(&columns, &_11$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 490);
		zephir_array_fetch_long(&_12$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 491 TSRMLS_CC);
		zephir_array_append(&referencedColumns, &_12$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 491);
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
	zephir_is_iterable(&references, 0, "phalcon/db/adapter/pdo/mysql.zep", 515);
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
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 506 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedSchema"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 507 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedTable"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 508 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("columns"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 509 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedColumns"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 510 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("onUpdate"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 512 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("onDelete"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_17$$6, "__construct", &_20, 15, &name, &_18$$6);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_17$$6, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&referenceObjects);

}

