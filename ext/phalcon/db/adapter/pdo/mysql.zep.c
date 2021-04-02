
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
 * Specific functions for the MySQL database system
 *
 *```php
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
 *```
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Mysql, phalcon, db_adapter_pdo_mysql, phalcon_db_adapter_pdo_abstractpdo_ce, phalcon_db_adapter_pdo_mysql_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("dialectType"), "mysql", ZEND_ACC_PROTECTED);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("type"), "mysql", ZEND_ACC_PROTECTED);

	return SUCCESS;

}

/**
 * Adds a foreign key to a table
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, addForeignKey) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(reference, phalcon_db_referenceinterface_ce)
	ZEND_PARSE_PARAMETERS_END();

#endif


	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

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


	zephir_read_property(&_0, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getforeignkeychecks", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&foreignKeyCheck, this_ptr, "prepare", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &foreignKeyCheck, "execute", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "DATABASE PARAMETER 'FOREIGN_KEY_CHECKS' HAS TO BE 1", "phalcon/Db/Adapter/Pdo/Mysql.zep", 66);
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "addforeignkey", NULL, 0, &tableName, &schemaName, reference);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_4);
	zephir_check_call_status();
	RETURN_MM();

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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns) {

	zend_bool _5$$3, _64$$47;
	zval definition;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_62 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$true, __$false, columns, columnType, fields, field, oldColumn, sizePattern, matches, matchOne, matchTwo, columnName, _0, _1, _2, *_3, _4, _47$$3, _48$$3, _49$$3, _50$$3, _59$$3, _61$$3, _6$$4, _7$$4, _8$$5, _9$$5, _10$$6, _11$$6, _12$$7, _13$$7, _14$$8, _15$$8, _16$$9, _17$$9, _18$$10, _19$$11, _20$$12, _21$$13, _22$$14, _23$$14, _24$$15, _25$$15, _26$$16, _27$$17, _28$$18, _29$$19, _30$$20, _31$$21, _32$$22, _33$$23, _34$$24, _35$$25, _36$$26, _37$$27, _38$$28, _39$$29, _40$$30, _41$$30, _42$$31, _43$$31, _44$$31, _45$$33, _46$$34, _51$$41, _52$$42, _53$$42, _54$$42, _55$$43, _56$$44, _57$$45, _58$$45, _60$$46, _63$$47, _106$$47, _107$$47, _108$$47, _109$$47, _118$$47, _120$$47, _65$$48, _66$$48, _67$$49, _68$$49, _69$$50, _70$$50, _71$$51, _72$$51, _73$$52, _74$$52, _75$$53, _76$$53, _77$$54, _78$$55, _79$$56, _80$$57, _81$$58, _82$$58, _83$$59, _84$$59, _85$$60, _86$$61, _87$$62, _88$$63, _89$$64, _90$$65, _91$$66, _92$$67, _93$$68, _94$$69, _95$$70, _96$$71, _97$$72, _98$$73, _99$$74, _100$$74, _101$$75, _102$$75, _103$$75, _104$$77, _105$$78, _110$$85, _111$$86, _112$$86, _113$$86, _114$$87, _115$$88, _116$$89, _117$$89, _119$$90;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&field);
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
	ZVAL_UNDEF(&_47$$3);
	ZVAL_UNDEF(&_48$$3);
	ZVAL_UNDEF(&_49$$3);
	ZVAL_UNDEF(&_50$$3);
	ZVAL_UNDEF(&_59$$3);
	ZVAL_UNDEF(&_61$$3);
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
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_26$$16);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$19);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$21);
	ZVAL_UNDEF(&_32$$22);
	ZVAL_UNDEF(&_33$$23);
	ZVAL_UNDEF(&_34$$24);
	ZVAL_UNDEF(&_35$$25);
	ZVAL_UNDEF(&_36$$26);
	ZVAL_UNDEF(&_37$$27);
	ZVAL_UNDEF(&_38$$28);
	ZVAL_UNDEF(&_39$$29);
	ZVAL_UNDEF(&_40$$30);
	ZVAL_UNDEF(&_41$$30);
	ZVAL_UNDEF(&_42$$31);
	ZVAL_UNDEF(&_43$$31);
	ZVAL_UNDEF(&_44$$31);
	ZVAL_UNDEF(&_45$$33);
	ZVAL_UNDEF(&_46$$34);
	ZVAL_UNDEF(&_51$$41);
	ZVAL_UNDEF(&_52$$42);
	ZVAL_UNDEF(&_53$$42);
	ZVAL_UNDEF(&_54$$42);
	ZVAL_UNDEF(&_55$$43);
	ZVAL_UNDEF(&_56$$44);
	ZVAL_UNDEF(&_57$$45);
	ZVAL_UNDEF(&_58$$45);
	ZVAL_UNDEF(&_60$$46);
	ZVAL_UNDEF(&_63$$47);
	ZVAL_UNDEF(&_106$$47);
	ZVAL_UNDEF(&_107$$47);
	ZVAL_UNDEF(&_108$$47);
	ZVAL_UNDEF(&_109$$47);
	ZVAL_UNDEF(&_118$$47);
	ZVAL_UNDEF(&_120$$47);
	ZVAL_UNDEF(&_65$$48);
	ZVAL_UNDEF(&_66$$48);
	ZVAL_UNDEF(&_67$$49);
	ZVAL_UNDEF(&_68$$49);
	ZVAL_UNDEF(&_69$$50);
	ZVAL_UNDEF(&_70$$50);
	ZVAL_UNDEF(&_71$$51);
	ZVAL_UNDEF(&_72$$51);
	ZVAL_UNDEF(&_73$$52);
	ZVAL_UNDEF(&_74$$52);
	ZVAL_UNDEF(&_75$$53);
	ZVAL_UNDEF(&_76$$53);
	ZVAL_UNDEF(&_77$$54);
	ZVAL_UNDEF(&_78$$55);
	ZVAL_UNDEF(&_79$$56);
	ZVAL_UNDEF(&_80$$57);
	ZVAL_UNDEF(&_81$$58);
	ZVAL_UNDEF(&_82$$58);
	ZVAL_UNDEF(&_83$$59);
	ZVAL_UNDEF(&_84$$59);
	ZVAL_UNDEF(&_85$$60);
	ZVAL_UNDEF(&_86$$61);
	ZVAL_UNDEF(&_87$$62);
	ZVAL_UNDEF(&_88$$63);
	ZVAL_UNDEF(&_89$$64);
	ZVAL_UNDEF(&_90$$65);
	ZVAL_UNDEF(&_91$$66);
	ZVAL_UNDEF(&_92$$67);
	ZVAL_UNDEF(&_93$$68);
	ZVAL_UNDEF(&_94$$69);
	ZVAL_UNDEF(&_95$$70);
	ZVAL_UNDEF(&_96$$71);
	ZVAL_UNDEF(&_97$$72);
	ZVAL_UNDEF(&_98$$73);
	ZVAL_UNDEF(&_99$$74);
	ZVAL_UNDEF(&_100$$74);
	ZVAL_UNDEF(&_101$$75);
	ZVAL_UNDEF(&_102$$75);
	ZVAL_UNDEF(&_103$$75);
	ZVAL_UNDEF(&_104$$77);
	ZVAL_UNDEF(&_105$$78);
	ZVAL_UNDEF(&_110$$85);
	ZVAL_UNDEF(&_111$$86);
	ZVAL_UNDEF(&_112$$86);
	ZVAL_UNDEF(&_113$$86);
	ZVAL_UNDEF(&_114$$87);
	ZVAL_UNDEF(&_115$$88);
	ZVAL_UNDEF(&_116$$89);
	ZVAL_UNDEF(&_117$$89);
	ZVAL_UNDEF(&_119$$90);
	ZVAL_UNDEF(&definition);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();

#endif


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
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "describecolumns", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "fetchall", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&fields, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 452);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _3)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _3);
			ZEPHIR_INIT_NVAR(&definition);
			zephir_create_array(&definition, 1, 0);
			add_assoc_long_ex(&definition, SL("bindType"), 2);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 121);
			do {
				_5$$3 = 1;
				if (_5$$3 == zephir_start_with_str(&columnType, SL("bigint"))) {
					ZEPHIR_INIT_NVAR(&_6$$4);
					ZVAL_LONG(&_6$$4, 14);
					zephir_array_update_string(&definition, SL("type"), &_6$$4, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_7$$4);
					ZVAL_LONG(&_7$$4, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_7$$4, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("mediumint"))) {
					ZEPHIR_INIT_NVAR(&_8$$5);
					ZVAL_LONG(&_8$$5, 21);
					zephir_array_update_string(&definition, SL("type"), &_8$$5, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_9$$5);
					ZVAL_LONG(&_9$$5, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_9$$5, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("smallint"))) {
					ZEPHIR_INIT_NVAR(&_10$$6);
					ZVAL_LONG(&_10$$6, 22);
					zephir_array_update_string(&definition, SL("type"), &_10$$6, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_11$$6);
					ZVAL_LONG(&_11$$6, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_11$$6, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("tinyint"))) {
					ZEPHIR_INIT_NVAR(&_12$$7);
					ZVAL_LONG(&_12$$7, 26);
					zephir_array_update_string(&definition, SL("type"), &_12$$7, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_13$$7);
					ZVAL_LONG(&_13$$7, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_13$$7, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("int"))) {
					ZEPHIR_INIT_NVAR(&_14$$8);
					ZVAL_LONG(&_14$$8, 0);
					zephir_array_update_string(&definition, SL("type"), &_14$$8, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_15$$8);
					ZVAL_LONG(&_15$$8, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_15$$8, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("bit"))) {
					ZEPHIR_INIT_NVAR(&_16$$9);
					ZVAL_LONG(&_16$$9, 19);
					zephir_array_update_string(&definition, SL("type"), &_16$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_17$$9);
					ZVAL_LONG(&_17$$9, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_17$$9, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("enum"))) {
					ZEPHIR_INIT_NVAR(&_18$$10);
					ZVAL_LONG(&_18$$10, 18);
					zephir_array_update_string(&definition, SL("type"), &_18$$10, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("datetime"))) {
					ZEPHIR_INIT_NVAR(&_19$$11);
					ZVAL_LONG(&_19$$11, 4);
					zephir_array_update_string(&definition, SL("type"), &_19$$11, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("date"))) {
					ZEPHIR_INIT_NVAR(&_20$$12);
					ZVAL_LONG(&_20$$12, 1);
					zephir_array_update_string(&definition, SL("type"), &_20$$12, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("decimal"))) {
					ZEPHIR_INIT_NVAR(&_21$$13);
					ZVAL_LONG(&_21$$13, 3);
					zephir_array_update_string(&definition, SL("type"), &_21$$13, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("double"))) {
					ZEPHIR_INIT_NVAR(&_22$$14);
					ZVAL_LONG(&_22$$14, 9);
					zephir_array_update_string(&definition, SL("type"), &_22$$14, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_23$$14);
					ZVAL_LONG(&_23$$14, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_23$$14, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("float"))) {
					ZEPHIR_INIT_NVAR(&_24$$15);
					ZVAL_LONG(&_24$$15, 7);
					zephir_array_update_string(&definition, SL("type"), &_24$$15, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_25$$15);
					ZVAL_LONG(&_25$$15, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_25$$15, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("mediumblob"))) {
					ZEPHIR_INIT_NVAR(&_26$$16);
					ZVAL_LONG(&_26$$16, 12);
					zephir_array_update_string(&definition, SL("type"), &_26$$16, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("longblob"))) {
					ZEPHIR_INIT_NVAR(&_27$$17);
					ZVAL_LONG(&_27$$17, 13);
					zephir_array_update_string(&definition, SL("type"), &_27$$17, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("tinyblob"))) {
					ZEPHIR_INIT_NVAR(&_28$$18);
					ZVAL_LONG(&_28$$18, 10);
					zephir_array_update_string(&definition, SL("type"), &_28$$18, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("blob"))) {
					ZEPHIR_INIT_NVAR(&_29$$19);
					ZVAL_LONG(&_29$$19, 11);
					zephir_array_update_string(&definition, SL("type"), &_29$$19, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("timestamp"))) {
					ZEPHIR_INIT_NVAR(&_30$$20);
					ZVAL_LONG(&_30$$20, 17);
					zephir_array_update_string(&definition, SL("type"), &_30$$20, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("time"))) {
					ZEPHIR_INIT_NVAR(&_31$$21);
					ZVAL_LONG(&_31$$21, 20);
					zephir_array_update_string(&definition, SL("type"), &_31$$21, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("json"))) {
					ZEPHIR_INIT_NVAR(&_32$$22);
					ZVAL_LONG(&_32$$22, 15);
					zephir_array_update_string(&definition, SL("type"), &_32$$22, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("longtext"))) {
					ZEPHIR_INIT_NVAR(&_33$$23);
					ZVAL_LONG(&_33$$23, 24);
					zephir_array_update_string(&definition, SL("type"), &_33$$23, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("mediumtext"))) {
					ZEPHIR_INIT_NVAR(&_34$$24);
					ZVAL_LONG(&_34$$24, 23);
					zephir_array_update_string(&definition, SL("type"), &_34$$24, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("tinytext"))) {
					ZEPHIR_INIT_NVAR(&_35$$25);
					ZVAL_LONG(&_35$$25, 25);
					zephir_array_update_string(&definition, SL("type"), &_35$$25, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("text"))) {
					ZEPHIR_INIT_NVAR(&_36$$26);
					ZVAL_LONG(&_36$$26, 6);
					zephir_array_update_string(&definition, SL("type"), &_36$$26, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("varchar"))) {
					ZEPHIR_INIT_NVAR(&_37$$27);
					ZVAL_LONG(&_37$$27, 2);
					zephir_array_update_string(&definition, SL("type"), &_37$$27, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("char"))) {
					ZEPHIR_INIT_NVAR(&_38$$28);
					ZVAL_LONG(&_38$$28, 5);
					zephir_array_update_string(&definition, SL("type"), &_38$$28, PH_COPY | PH_SEPARATE);
					break;
				}
				ZEPHIR_INIT_NVAR(&_39$$29);
				ZVAL_LONG(&_39$$29, 2);
				zephir_array_update_string(&definition, SL("type"), &_39$$29, PH_COPY | PH_SEPARATE);
				break;
			} while(0);

			if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 369)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				zephir_array_fetch_string(&_40$$30, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 372);
				ZEPHIR_INIT_NVAR(&_41$$30);
				zephir_preg_match(&_41$$30, &sizePattern, &columnType, &matches, 0, 0 , 0 );
				if (ZEPHIR_IS_LONG(&_40$$30, 18)) {
					ZVAL_LONG(&_42$$31, 5);
					ZVAL_LONG(&_43$$31, -1);
					ZEPHIR_INIT_NVAR(&_44$$31);
					zephir_substr(&_44$$31, &columnType, 5 , -1 , 0);
					zephir_array_update_string(&definition, SL("size"), &_44$$31, PH_COPY | PH_SEPARATE);
				} else if (zephir_is_true(&_41$$30)) {
					ZEPHIR_OBS_NVAR(&matchOne);
					if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
						ZEPHIR_INIT_NVAR(&_45$$33);
						ZVAL_LONG(&_45$$33, zephir_get_intval(&matchOne));
						zephir_array_update_string(&definition, SL("size"), &_45$$33, PH_COPY | PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(&matchTwo);
					if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
						ZEPHIR_INIT_NVAR(&_46$$34);
						ZVAL_LONG(&_46$$34, zephir_get_intval(&matchTwo));
						zephir_array_update_string(&definition, SL("scale"), &_46$$34, PH_COPY | PH_SEPARATE);
					}
				}
			}
			if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 388)) {
				zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&oldColumn) == IS_NULL) {
				zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_47$$3, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 404);
			if (ZEPHIR_IS_STRING(&_47$$3, "PRI")) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_48$$3, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 411);
			if (ZEPHIR_IS_STRING(&_48$$3, "YES")) {
				zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_49$$3, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 418);
			if (ZEPHIR_IS_STRING(&_49$$3, "auto_increment")) {
				zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_50$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 425);
			if (Z_TYPE_P(&_50$$3) != IS_NULL) {
				zephir_array_fetch_long(&_51$$41, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 426);
				if (zephir_memnstr_str(&_51$$41, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 426)) {
					zephir_array_fetch_long(&_52$$42, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 427);
					zephir_array_fetch_long(&_53$$42, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 427);
					ZEPHIR_INIT_NVAR(&_54$$42);
					ZEPHIR_CONCAT_VSV(&_54$$42, &_52$$42, " ", &_53$$42);
					zephir_array_update_string(&definition, SL("default"), &_54$$42, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_fetch_long(&_55$$43, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 429);
					zephir_array_update_string(&definition, SL("default"), &_55$$43, PH_COPY | PH_SEPARATE);
				}
			} else {
				zephir_array_fetch_long(&_56$$44, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 432);
				if (zephir_memnstr_str(&_56$$44, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 432)) {
					zephir_array_fetch_long(&_57$$45, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 433);
					ZEPHIR_INIT_NVAR(&_58$$45);
					ZEPHIR_CONCAT_SV(&_58$$45, "NULL ", &_57$$45);
					zephir_array_update_string(&definition, SL("default"), &_58$$45, PH_COPY | PH_SEPARATE);
				}
			}
			zephir_array_fetch_long(&_59$$3, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 440);
			if (Z_TYPE_P(&_59$$3) != IS_NULL) {
				zephir_array_fetch_long(&_60$$46, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 441);
				zephir_array_update_string(&definition, SL("comment"), &_60$$46, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 447);
			ZEPHIR_INIT_NVAR(&_61$$3);
			object_init_ex(&_61$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_61$$3, "__construct", &_62, 213, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_61$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 448);
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
				ZEPHIR_INIT_NVAR(&_63$$47);
				zephir_create_array(&_63$$47, 1, 0);
				add_assoc_long_ex(&_63$$47, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_63$$47);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 121);
				do {
					_64$$47 = 1;
					if (_64$$47 == zephir_start_with_str(&columnType, SL("bigint"))) {
						ZEPHIR_INIT_NVAR(&_65$$48);
						ZVAL_LONG(&_65$$48, 14);
						zephir_array_update_string(&definition, SL("type"), &_65$$48, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_66$$48);
						ZVAL_LONG(&_66$$48, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_66$$48, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("mediumint"))) {
						ZEPHIR_INIT_NVAR(&_67$$49);
						ZVAL_LONG(&_67$$49, 21);
						zephir_array_update_string(&definition, SL("type"), &_67$$49, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_68$$49);
						ZVAL_LONG(&_68$$49, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_68$$49, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("smallint"))) {
						ZEPHIR_INIT_NVAR(&_69$$50);
						ZVAL_LONG(&_69$$50, 22);
						zephir_array_update_string(&definition, SL("type"), &_69$$50, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_70$$50);
						ZVAL_LONG(&_70$$50, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_70$$50, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("tinyint"))) {
						ZEPHIR_INIT_NVAR(&_71$$51);
						ZVAL_LONG(&_71$$51, 26);
						zephir_array_update_string(&definition, SL("type"), &_71$$51, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_72$$51);
						ZVAL_LONG(&_72$$51, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_72$$51, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("int"))) {
						ZEPHIR_INIT_NVAR(&_73$$52);
						ZVAL_LONG(&_73$$52, 0);
						zephir_array_update_string(&definition, SL("type"), &_73$$52, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_74$$52);
						ZVAL_LONG(&_74$$52, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_74$$52, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("bit"))) {
						ZEPHIR_INIT_NVAR(&_75$$53);
						ZVAL_LONG(&_75$$53, 19);
						zephir_array_update_string(&definition, SL("type"), &_75$$53, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_76$$53);
						ZVAL_LONG(&_76$$53, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_76$$53, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("enum"))) {
						ZEPHIR_INIT_NVAR(&_77$$54);
						ZVAL_LONG(&_77$$54, 18);
						zephir_array_update_string(&definition, SL("type"), &_77$$54, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("datetime"))) {
						ZEPHIR_INIT_NVAR(&_78$$55);
						ZVAL_LONG(&_78$$55, 4);
						zephir_array_update_string(&definition, SL("type"), &_78$$55, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("date"))) {
						ZEPHIR_INIT_NVAR(&_79$$56);
						ZVAL_LONG(&_79$$56, 1);
						zephir_array_update_string(&definition, SL("type"), &_79$$56, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("decimal"))) {
						ZEPHIR_INIT_NVAR(&_80$$57);
						ZVAL_LONG(&_80$$57, 3);
						zephir_array_update_string(&definition, SL("type"), &_80$$57, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("double"))) {
						ZEPHIR_INIT_NVAR(&_81$$58);
						ZVAL_LONG(&_81$$58, 9);
						zephir_array_update_string(&definition, SL("type"), &_81$$58, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_82$$58);
						ZVAL_LONG(&_82$$58, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_82$$58, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("float"))) {
						ZEPHIR_INIT_NVAR(&_83$$59);
						ZVAL_LONG(&_83$$59, 7);
						zephir_array_update_string(&definition, SL("type"), &_83$$59, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_84$$59);
						ZVAL_LONG(&_84$$59, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_84$$59, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("mediumblob"))) {
						ZEPHIR_INIT_NVAR(&_85$$60);
						ZVAL_LONG(&_85$$60, 12);
						zephir_array_update_string(&definition, SL("type"), &_85$$60, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("longblob"))) {
						ZEPHIR_INIT_NVAR(&_86$$61);
						ZVAL_LONG(&_86$$61, 13);
						zephir_array_update_string(&definition, SL("type"), &_86$$61, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("tinyblob"))) {
						ZEPHIR_INIT_NVAR(&_87$$62);
						ZVAL_LONG(&_87$$62, 10);
						zephir_array_update_string(&definition, SL("type"), &_87$$62, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("blob"))) {
						ZEPHIR_INIT_NVAR(&_88$$63);
						ZVAL_LONG(&_88$$63, 11);
						zephir_array_update_string(&definition, SL("type"), &_88$$63, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("timestamp"))) {
						ZEPHIR_INIT_NVAR(&_89$$64);
						ZVAL_LONG(&_89$$64, 17);
						zephir_array_update_string(&definition, SL("type"), &_89$$64, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("time"))) {
						ZEPHIR_INIT_NVAR(&_90$$65);
						ZVAL_LONG(&_90$$65, 20);
						zephir_array_update_string(&definition, SL("type"), &_90$$65, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("json"))) {
						ZEPHIR_INIT_NVAR(&_91$$66);
						ZVAL_LONG(&_91$$66, 15);
						zephir_array_update_string(&definition, SL("type"), &_91$$66, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("longtext"))) {
						ZEPHIR_INIT_NVAR(&_92$$67);
						ZVAL_LONG(&_92$$67, 24);
						zephir_array_update_string(&definition, SL("type"), &_92$$67, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("mediumtext"))) {
						ZEPHIR_INIT_NVAR(&_93$$68);
						ZVAL_LONG(&_93$$68, 23);
						zephir_array_update_string(&definition, SL("type"), &_93$$68, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("tinytext"))) {
						ZEPHIR_INIT_NVAR(&_94$$69);
						ZVAL_LONG(&_94$$69, 25);
						zephir_array_update_string(&definition, SL("type"), &_94$$69, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("text"))) {
						ZEPHIR_INIT_NVAR(&_95$$70);
						ZVAL_LONG(&_95$$70, 6);
						zephir_array_update_string(&definition, SL("type"), &_95$$70, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("varchar"))) {
						ZEPHIR_INIT_NVAR(&_96$$71);
						ZVAL_LONG(&_96$$71, 2);
						zephir_array_update_string(&definition, SL("type"), &_96$$71, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_64$$47 == zephir_start_with_str(&columnType, SL("char"))) {
						ZEPHIR_INIT_NVAR(&_97$$72);
						ZVAL_LONG(&_97$$72, 5);
						zephir_array_update_string(&definition, SL("type"), &_97$$72, PH_COPY | PH_SEPARATE);
						break;
					}
					ZEPHIR_INIT_NVAR(&_98$$73);
					ZVAL_LONG(&_98$$73, 2);
					zephir_array_update_string(&definition, SL("type"), &_98$$73, PH_COPY | PH_SEPARATE);
					break;
				} while(0);

				if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 369)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					zephir_array_fetch_string(&_99$$74, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 372);
					ZEPHIR_INIT_NVAR(&_100$$74);
					zephir_preg_match(&_100$$74, &sizePattern, &columnType, &matches, 0, 0 , 0 );
					if (ZEPHIR_IS_LONG(&_99$$74, 18)) {
						ZVAL_LONG(&_101$$75, 5);
						ZVAL_LONG(&_102$$75, -1);
						ZEPHIR_INIT_NVAR(&_103$$75);
						zephir_substr(&_103$$75, &columnType, 5 , -1 , 0);
						zephir_array_update_string(&definition, SL("size"), &_103$$75, PH_COPY | PH_SEPARATE);
					} else if (zephir_is_true(&_100$$74)) {
						ZEPHIR_OBS_NVAR(&matchOne);
						if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
							ZEPHIR_INIT_NVAR(&_104$$77);
							ZVAL_LONG(&_104$$77, zephir_get_intval(&matchOne));
							zephir_array_update_string(&definition, SL("size"), &_104$$77, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&matchTwo);
						if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
							ZEPHIR_INIT_NVAR(&_105$$78);
							ZVAL_LONG(&_105$$78, zephir_get_intval(&matchTwo));
							zephir_array_update_string(&definition, SL("scale"), &_105$$78, PH_COPY | PH_SEPARATE);
						}
					}
				}
				if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 388)) {
					zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
				}
				if (Z_TYPE_P(&oldColumn) == IS_NULL) {
					zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_106$$47, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 404);
				if (ZEPHIR_IS_STRING(&_106$$47, "PRI")) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_107$$47, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 411);
				if (ZEPHIR_IS_STRING(&_107$$47, "YES")) {
					zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_108$$47, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 418);
				if (ZEPHIR_IS_STRING(&_108$$47, "auto_increment")) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_109$$47, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 425);
				if (Z_TYPE_P(&_109$$47) != IS_NULL) {
					zephir_array_fetch_long(&_110$$85, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 426);
					if (zephir_memnstr_str(&_110$$85, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 426)) {
						zephir_array_fetch_long(&_111$$86, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 427);
						zephir_array_fetch_long(&_112$$86, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 427);
						ZEPHIR_INIT_NVAR(&_113$$86);
						ZEPHIR_CONCAT_VSV(&_113$$86, &_111$$86, " ", &_112$$86);
						zephir_array_update_string(&definition, SL("default"), &_113$$86, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_fetch_long(&_114$$87, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 429);
						zephir_array_update_string(&definition, SL("default"), &_114$$87, PH_COPY | PH_SEPARATE);
					}
				} else {
					zephir_array_fetch_long(&_115$$88, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 432);
					if (zephir_memnstr_str(&_115$$88, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 432)) {
						zephir_array_fetch_long(&_116$$89, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 433);
						ZEPHIR_INIT_NVAR(&_117$$89);
						ZEPHIR_CONCAT_SV(&_117$$89, "NULL ", &_116$$89);
						zephir_array_update_string(&definition, SL("default"), &_117$$89, PH_COPY | PH_SEPARATE);
					}
				}
				zephir_array_fetch_long(&_118$$47, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 440);
				if (Z_TYPE_P(&_118$$47) != IS_NULL) {
					zephir_array_fetch_long(&_119$$90, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 441);
					zephir_array_update_string(&definition, SL("comment"), &_119$$90, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 447);
				ZEPHIR_INIT_NVAR(&_120$$47);
				object_init_ex(&_120$$47, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_120$$47, "__construct", &_62, 213, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_120$$47, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 448);
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeIndexes) {

	zend_string *_25;
	zend_ulong _24;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_29 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$null, indexes, index, keyName, indexType, indexObjects, columns, name, _0, _1, _2, _3, *_4, _5, *_22, _23, _6$$4, _7$$3, _9$$3, _10$$3, _8$$6, _11$$7, _12$$8, _13$$9, _14$$12, _15$$11, _17$$11, _18$$11, _16$$14, _19$$15, _20$$16, _21$$17, _26$$19, _27$$19, _28$$19, _30$$20, _31$$20, _32$$20;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_23);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_21$$17);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_27$$19);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_31$$20);
	ZVAL_UNDEF(&_32$$20);
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();

#endif


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


	ZEPHIR_INIT_VAR(&indexes);
	array_init(&indexes);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeindexes", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 498);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _4);
			zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 471);
			zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 472);
			if (!(zephir_array_isset(&indexes, &keyName))) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				array_init(&_6$$4);
				zephir_array_update_zval(&indexes, &keyName, &_6$$4, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch(&_7$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 478);
			if (!(zephir_array_isset_string(&_7$$3, SL("columns")))) {
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
			} else {
				zephir_array_fetch(&_8$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 481);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_8$$6, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 481);
			}
			zephir_array_fetch_string(&_9$$3, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 484);
			zephir_array_append(&columns, &_9$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 484);
			zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
			zephir_array_fetch_string(&_10$$3, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 491);
			if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
				ZEPHIR_INIT_NVAR(&_11$$7);
				ZVAL_STRING(&_11$$7, "PRIMARY");
				zephir_array_update_multi(&indexes, &_11$$7, SL("zs"), 3, &keyName, SL("type"));
			} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
				ZEPHIR_INIT_NVAR(&_12$$8);
				ZVAL_STRING(&_12$$8, "FULLTEXT");
				zephir_array_update_multi(&indexes, &_12$$8, SL("zs"), 3, &keyName, SL("type"));
			} else if (ZEPHIR_IS_LONG(&_10$$3, 0)) {
				ZEPHIR_INIT_NVAR(&_13$$9);
				ZVAL_STRING(&_13$$9, "UNIQUE");
				zephir_array_update_multi(&indexes, &_13$$9, SL("zs"), 3, &keyName, SL("type"));
			} else {
				zephir_array_update_multi(&indexes, &__$null, SL("zs"), 3, &keyName, SL("type"));
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
				zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 471);
				ZEPHIR_OBS_NVAR(&indexType);
				zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 472);
				if (!(zephir_array_isset(&indexes, &keyName))) {
					ZEPHIR_INIT_NVAR(&_14$$12);
					array_init(&_14$$12);
					zephir_array_update_zval(&indexes, &keyName, &_14$$12, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch(&_15$$11, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 478);
				if (!(zephir_array_isset_string(&_15$$11, SL("columns")))) {
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
				} else {
					zephir_array_fetch(&_16$$14, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 481);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_16$$14, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 481);
				}
				zephir_array_fetch_string(&_17$$11, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 484);
				zephir_array_append(&columns, &_17$$11, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 484);
				zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
				zephir_array_fetch_string(&_18$$11, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 491);
				if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
					ZEPHIR_INIT_NVAR(&_19$$15);
					ZVAL_STRING(&_19$$15, "PRIMARY");
					zephir_array_update_multi(&indexes, &_19$$15, SL("zs"), 3, &keyName, SL("type"));
				} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
					ZEPHIR_INIT_NVAR(&_20$$16);
					ZVAL_STRING(&_20$$16, "FULLTEXT");
					zephir_array_update_multi(&indexes, &_20$$16, SL("zs"), 3, &keyName, SL("type"));
				} else if (ZEPHIR_IS_LONG(&_18$$11, 0)) {
					ZEPHIR_INIT_NVAR(&_21$$17);
					ZVAL_STRING(&_21$$17, "UNIQUE");
					zephir_array_update_multi(&indexes, &_21$$17, SL("zs"), 3, &keyName, SL("type"));
				} else {
					zephir_array_update_multi(&indexes, &__$null, SL("zs"), 3, &keyName, SL("type"));
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	zephir_is_iterable(&indexes, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 508);
	if (Z_TYPE_P(&indexes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&indexes), _24, _25, _22)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_25 != NULL) { 
				ZVAL_STR_COPY(&name, _25);
			} else {
				ZVAL_LONG(&name, _24);
			}
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _22);
			ZEPHIR_INIT_NVAR(&_26$$19);
			object_init_ex(&_26$$19, phalcon_db_index_ce);
			zephir_array_fetch_string(&_27$$19, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 503);
			zephir_array_fetch_string(&_28$$19, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 505);
			ZEPHIR_CALL_METHOD(NULL, &_26$$19, "__construct", &_29, 32, &name, &_27$$19, &_28$$19);
			zephir_check_call_status();
			zephir_array_update_zval(&indexObjects, &name, &_26$$19, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &indexes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_23, &indexes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_23)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &indexes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&index, &indexes, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_30$$20);
				object_init_ex(&_30$$20, phalcon_db_index_ce);
				zephir_array_fetch_string(&_31$$20, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 503);
				zephir_array_fetch_string(&_32$$20, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 505);
				ZEPHIR_CALL_METHOD(NULL, &_30$$20, "__construct", &_29, 32, &name, &_31$$20, &_32$$20);
				zephir_check_call_status();
				zephir_array_update_zval(&indexObjects, &name, &_30$$20, PH_COPY | PH_SEPARATE);
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
 *
 *```php
 * print_r(
 *     $connection->describeReferences("robots_parts")
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeReferences) {

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
#if PHP_VERSION_ID >= 80000
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(table)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR_OR_NULL(schema)
	ZEND_PARSE_PARAMETERS_END();

#endif


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
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 561);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _4);
			zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 530);
			if (!(zephir_array_isset(&references, &constraintName))) {
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 533);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 534);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 535);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 536);
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 540);
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_6$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 540);
				zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 541);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_7$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 541);
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 542);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_8$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 542);
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 543);
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_9$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 543);
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 544);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_string(&referenceUpdate, &_10$$5, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 544);
				zephir_array_fetch(&_11$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 545);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_string(&referenceDelete, &_11$$5, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 545);
			}
			zephir_array_fetch_long(&_12$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 548);
			zephir_array_append(&columns, &_12$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 548);
			zephir_array_fetch_long(&_13$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 549);
			zephir_array_append(&referencedColumns, &_13$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 549);
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
				zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 530);
				if (!(zephir_array_isset(&references, &constraintName))) {
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 533);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 534);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 535);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 536);
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_15$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 540);
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_15$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 540);
					zephir_array_fetch(&_16$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 541);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_16$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 541);
					zephir_array_fetch(&_17$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 542);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_17$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 542);
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 543);
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_18$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 543);
					zephir_array_fetch(&_19$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 544);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_string(&referenceUpdate, &_19$$8, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 544);
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 545);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_string(&referenceDelete, &_20$$8, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 545);
				}
				zephir_array_fetch_long(&_21$$6, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 548);
				zephir_array_append(&columns, &_21$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 548);
				zephir_array_fetch_long(&_22$$6, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 549);
				zephir_array_append(&referencedColumns, &_22$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 549);
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
	zephir_is_iterable(&references, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 576);
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
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 566);
			zephir_array_update_string(&_29$$9, SL("referencedSchema"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 567);
			zephir_array_update_string(&_29$$9, SL("referencedTable"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 568);
			zephir_array_update_string(&_29$$9, SL("columns"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 569);
			zephir_array_update_string(&_29$$9, SL("referencedColumns"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 570);
			zephir_array_update_string(&_29$$9, SL("onUpdate"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 572);
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
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 566);
				zephir_array_update_string(&_33$$10, SL("referencedSchema"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 567);
				zephir_array_update_string(&_33$$10, SL("referencedTable"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 568);
				zephir_array_update_string(&_33$$10, SL("columns"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 569);
				zephir_array_update_string(&_33$$10, SL("referencedColumns"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 570);
				zephir_array_update_string(&_33$$10, SL("onUpdate"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 572);
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
 * Returns PDO adapter DSN defaults as a key-value map.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, getDsnDefaults) {

	zval *this_ptr = getThis();



	zephir_create_array(return_value, 1, 0);
	add_assoc_stringl_ex(return_value, SL("charset"), SL("utf8mb4"));
	return;

}

