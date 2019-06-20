
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

	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("dialectType"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("type"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

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


	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getforeignkeychecks", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&foreignKeyCheck, this_ptr, "prepare", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &foreignKeyCheck, "execute", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "DATABASE PARAMETER 'FOREIGN_KEY_CHECKS' HAS TO BE 1", "phalcon/Db/Adapter/Pdo/Mysql.zep", 62);
		return;
	}
	zephir_read_property(&_3, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
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

	zend_bool _5$$3, _57$$43;
	zval definition;
	zephir_fcall_cache_entry *_55 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$true, columns, columnType, fields, field, oldColumn, sizePattern, matches, matchOne, matchTwo, columnName, _0, _1, _2, *_3, _4, _49$$3, _50$$3, _51$$3, _52$$3, _54$$3, _6$$4, _7$$4, _8$$5, _9$$5, _10$$6, _11$$6, _12$$7, _13$$7, _14$$8, _15$$8, _16$$9, _17$$9, _18$$10, _19$$10, _20$$11, _21$$12, _22$$13, _23$$14, _24$$15, _25$$15, _26$$16, _27$$16, _28$$17, _29$$18, _30$$19, _31$$20, _32$$21, _33$$22, _34$$23, _35$$24, _36$$25, _37$$26, _38$$27, _39$$28, _40$$29, _41$$30, _42$$31, _43$$31, _44$$32, _45$$32, _46$$32, _47$$34, _48$$35, _53$$42, _56$$43, _101$$43, _102$$43, _103$$43, _104$$43, _106$$43, _58$$44, _59$$44, _60$$45, _61$$45, _62$$46, _63$$46, _64$$47, _65$$47, _66$$48, _67$$48, _68$$49, _69$$49, _70$$50, _71$$50, _72$$51, _73$$52, _74$$53, _75$$54, _76$$55, _77$$55, _78$$56, _79$$56, _80$$57, _81$$58, _82$$59, _83$$60, _84$$61, _85$$62, _86$$63, _87$$64, _88$$65, _89$$66, _90$$67, _91$$68, _92$$69, _93$$70, _94$$71, _95$$71, _96$$72, _97$$72, _98$$72, _99$$74, _100$$75, _105$$82;
	zval table, schema;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_BOOL(&__$true, 1);
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
	ZVAL_UNDEF(&_56$$43);
	ZVAL_UNDEF(&_101$$43);
	ZVAL_UNDEF(&_102$$43);
	ZVAL_UNDEF(&_103$$43);
	ZVAL_UNDEF(&_104$$43);
	ZVAL_UNDEF(&_106$$43);
	ZVAL_UNDEF(&_58$$44);
	ZVAL_UNDEF(&_59$$44);
	ZVAL_UNDEF(&_60$$45);
	ZVAL_UNDEF(&_61$$45);
	ZVAL_UNDEF(&_62$$46);
	ZVAL_UNDEF(&_63$$46);
	ZVAL_UNDEF(&_64$$47);
	ZVAL_UNDEF(&_65$$47);
	ZVAL_UNDEF(&_66$$48);
	ZVAL_UNDEF(&_67$$48);
	ZVAL_UNDEF(&_68$$49);
	ZVAL_UNDEF(&_69$$49);
	ZVAL_UNDEF(&_70$$50);
	ZVAL_UNDEF(&_71$$50);
	ZVAL_UNDEF(&_72$$51);
	ZVAL_UNDEF(&_73$$52);
	ZVAL_UNDEF(&_74$$53);
	ZVAL_UNDEF(&_75$$54);
	ZVAL_UNDEF(&_76$$55);
	ZVAL_UNDEF(&_77$$55);
	ZVAL_UNDEF(&_78$$56);
	ZVAL_UNDEF(&_79$$56);
	ZVAL_UNDEF(&_80$$57);
	ZVAL_UNDEF(&_81$$58);
	ZVAL_UNDEF(&_82$$59);
	ZVAL_UNDEF(&_83$$60);
	ZVAL_UNDEF(&_84$$61);
	ZVAL_UNDEF(&_85$$62);
	ZVAL_UNDEF(&_86$$63);
	ZVAL_UNDEF(&_87$$64);
	ZVAL_UNDEF(&_88$$65);
	ZVAL_UNDEF(&_89$$66);
	ZVAL_UNDEF(&_90$$67);
	ZVAL_UNDEF(&_91$$68);
	ZVAL_UNDEF(&_92$$69);
	ZVAL_UNDEF(&_93$$70);
	ZVAL_UNDEF(&_94$$71);
	ZVAL_UNDEF(&_95$$71);
	ZVAL_UNDEF(&_96$$72);
	ZVAL_UNDEF(&_97$$72);
	ZVAL_UNDEF(&_98$$72);
	ZVAL_UNDEF(&_99$$74);
	ZVAL_UNDEF(&_100$$75);
	ZVAL_UNDEF(&_105$$82);
	ZVAL_UNDEF(&definition);

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
	zephir_read_property(&_0, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "describecolumns", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "fetchall", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&fields, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 446);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _3)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _3);
			ZEPHIR_INIT_NVAR(&definition);
			zephir_create_array(&definition, 1, 0 TSRMLS_CC);
			add_assoc_long_ex(&definition, SL("bindType"), 2);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 117 TSRMLS_CC);
			do {
				_5$$3 = 1;
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinyint(1)"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 135)) {
					ZEPHIR_INIT_NVAR(&_6$$4);
					ZVAL_LONG(&_6$$4, 8);
					zephir_array_update_string(&definition, SL("type"), &_6$$4, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_7$$4);
					ZVAL_LONG(&_7$$4, 5);
					zephir_array_update_string(&definition, SL("bindType"), &_7$$4, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 148)) {
					ZEPHIR_INIT_NVAR(&_8$$5);
					ZVAL_LONG(&_8$$5, 14);
					zephir_array_update_string(&definition, SL("type"), &_8$$5, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_9$$5);
					ZVAL_LONG(&_9$$5, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_9$$5, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("mediumint"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 158)) {
					ZEPHIR_INIT_NVAR(&_10$$6);
					ZVAL_LONG(&_10$$6, 21);
					zephir_array_update_string(&definition, SL("type"), &_10$$6, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_11$$6);
					ZVAL_LONG(&_11$$6, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_11$$6, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("smallint"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 168)) {
					ZEPHIR_INIT_NVAR(&_12$$7);
					ZVAL_LONG(&_12$$7, 22);
					zephir_array_update_string(&definition, SL("type"), &_12$$7, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_13$$7);
					ZVAL_LONG(&_13$$7, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_13$$7, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinyint"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 178)) {
					ZEPHIR_INIT_NVAR(&_14$$8);
					ZVAL_LONG(&_14$$8, 26);
					zephir_array_update_string(&definition, SL("type"), &_14$$8, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_15$$8);
					ZVAL_LONG(&_15$$8, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_15$$8, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 191)) {
					ZEPHIR_INIT_NVAR(&_16$$9);
					ZVAL_LONG(&_16$$9, 0);
					zephir_array_update_string(&definition, SL("type"), &_16$$9, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_17$$9);
					ZVAL_LONG(&_17$$9, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_17$$9, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("bit"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 201)) {
					ZEPHIR_INIT_NVAR(&_18$$10);
					ZVAL_LONG(&_18$$10, 19);
					zephir_array_update_string(&definition, SL("type"), &_18$$10, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_19$$10);
					ZVAL_LONG(&_19$$10, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_19$$10, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 210)) {
					ZEPHIR_INIT_NVAR(&_20$$11);
					ZVAL_LONG(&_20$$11, 18);
					zephir_array_update_string(&definition, SL("type"), &_20$$11, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 218)) {
					ZEPHIR_INIT_NVAR(&_21$$12);
					ZVAL_LONG(&_21$$12, 4);
					zephir_array_update_string(&definition, SL("type"), &_21$$12, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 226)) {
					ZEPHIR_INIT_NVAR(&_22$$13);
					ZVAL_LONG(&_22$$13, 1);
					zephir_array_update_string(&definition, SL("type"), &_22$$13, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 235)) {
					ZEPHIR_INIT_NVAR(&_23$$14);
					ZVAL_LONG(&_23$$14, 3);
					zephir_array_update_string(&definition, SL("type"), &_23$$14, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("double"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 244)) {
					ZEPHIR_INIT_NVAR(&_24$$15);
					ZVAL_LONG(&_24$$15, 9);
					zephir_array_update_string(&definition, SL("type"), &_24$$15, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_25$$15);
					ZVAL_LONG(&_25$$15, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_25$$15, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 254)) {
					ZEPHIR_INIT_NVAR(&_26$$16);
					ZVAL_LONG(&_26$$16, 7);
					zephir_array_update_string(&definition, SL("type"), &_26$$16, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_27$$16);
					ZVAL_LONG(&_27$$16, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_27$$16, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 264)) {
					ZEPHIR_INIT_NVAR(&_28$$17);
					ZVAL_LONG(&_28$$17, 12);
					zephir_array_update_string(&definition, SL("type"), &_28$$17, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 272)) {
					ZEPHIR_INIT_NVAR(&_29$$18);
					ZVAL_LONG(&_29$$18, 13);
					zephir_array_update_string(&definition, SL("type"), &_29$$18, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 280)) {
					ZEPHIR_INIT_NVAR(&_30$$19);
					ZVAL_LONG(&_30$$19, 10);
					zephir_array_update_string(&definition, SL("type"), &_30$$19, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("blob"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 288)) {
					ZEPHIR_INIT_NVAR(&_31$$20);
					ZVAL_LONG(&_31$$20, 11);
					zephir_array_update_string(&definition, SL("type"), &_31$$20, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 296)) {
					ZEPHIR_INIT_NVAR(&_32$$21);
					ZVAL_LONG(&_32$$21, 17);
					zephir_array_update_string(&definition, SL("type"), &_32$$21, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("time"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 304)) {
					ZEPHIR_INIT_NVAR(&_33$$22);
					ZVAL_LONG(&_33$$22, 20);
					zephir_array_update_string(&definition, SL("type"), &_33$$22, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("json"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 312)) {
					ZEPHIR_INIT_NVAR(&_34$$23);
					ZVAL_LONG(&_34$$23, 15);
					zephir_array_update_string(&definition, SL("type"), &_34$$23, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("longtext"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 320)) {
					ZEPHIR_INIT_NVAR(&_35$$24);
					ZVAL_LONG(&_35$$24, 24);
					zephir_array_update_string(&definition, SL("type"), &_35$$24, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("mediumtext"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 328)) {
					ZEPHIR_INIT_NVAR(&_36$$25);
					ZVAL_LONG(&_36$$25, 23);
					zephir_array_update_string(&definition, SL("type"), &_36$$25, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("tinytext"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 336)) {
					ZEPHIR_INIT_NVAR(&_37$$26);
					ZVAL_LONG(&_37$$26, 25);
					zephir_array_update_string(&definition, SL("type"), &_37$$26, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 344)) {
					ZEPHIR_INIT_NVAR(&_38$$27);
					ZVAL_LONG(&_38$$27, 6);
					zephir_array_update_string(&definition, SL("type"), &_38$$27, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 352)) {
					ZEPHIR_INIT_NVAR(&_39$$28);
					ZVAL_LONG(&_39$$28, 2);
					zephir_array_update_string(&definition, SL("type"), &_39$$28, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 360)) {
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

			if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 378)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				zephir_array_fetch_string(&_42$$31, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 381 TSRMLS_CC);
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
			if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 397)) {
				zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&oldColumn) == IS_NULL) {
				zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_49$$3, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 413 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(&_49$$3, "PRI")) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_50$$3, &field, 2, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 420 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(&_50$$3, "NO")) {
				zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_51$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 427 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(&_51$$3, "auto_increment")) {
				zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_52$$3, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 434 TSRMLS_CC);
			if (Z_TYPE_P(&_52$$3) != IS_NULL) {
				zephir_array_fetch_long(&_53$$42, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 435 TSRMLS_CC);
				zephir_array_update_string(&definition, SL("default"), &_53$$42, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 441 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&_54$$3);
			object_init_ex(&_54$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_54$$3, "__construct", &_55, 182, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_54$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 442);
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
				ZEPHIR_INIT_NVAR(&_56$$43);
				zephir_create_array(&_56$$43, 1, 0 TSRMLS_CC);
				add_assoc_long_ex(&_56$$43, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_56$$43);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 117 TSRMLS_CC);
				do {
					_57$$43 = 1;
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("tinyint(1)"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 135)) {
						ZEPHIR_INIT_NVAR(&_58$$44);
						ZVAL_LONG(&_58$$44, 8);
						zephir_array_update_string(&definition, SL("type"), &_58$$44, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_59$$44);
						ZVAL_LONG(&_59$$44, 5);
						zephir_array_update_string(&definition, SL("bindType"), &_59$$44, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 148)) {
						ZEPHIR_INIT_NVAR(&_60$$45);
						ZVAL_LONG(&_60$$45, 14);
						zephir_array_update_string(&definition, SL("type"), &_60$$45, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_61$$45);
						ZVAL_LONG(&_61$$45, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_61$$45, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("mediumint"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 158)) {
						ZEPHIR_INIT_NVAR(&_62$$46);
						ZVAL_LONG(&_62$$46, 21);
						zephir_array_update_string(&definition, SL("type"), &_62$$46, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_63$$46);
						ZVAL_LONG(&_63$$46, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_63$$46, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("smallint"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 168)) {
						ZEPHIR_INIT_NVAR(&_64$$47);
						ZVAL_LONG(&_64$$47, 22);
						zephir_array_update_string(&definition, SL("type"), &_64$$47, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_65$$47);
						ZVAL_LONG(&_65$$47, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_65$$47, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("tinyint"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 178)) {
						ZEPHIR_INIT_NVAR(&_66$$48);
						ZVAL_LONG(&_66$$48, 26);
						zephir_array_update_string(&definition, SL("type"), &_66$$48, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_67$$48);
						ZVAL_LONG(&_67$$48, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_67$$48, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 191)) {
						ZEPHIR_INIT_NVAR(&_68$$49);
						ZVAL_LONG(&_68$$49, 0);
						zephir_array_update_string(&definition, SL("type"), &_68$$49, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_69$$49);
						ZVAL_LONG(&_69$$49, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_69$$49, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("bit"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 201)) {
						ZEPHIR_INIT_NVAR(&_70$$50);
						ZVAL_LONG(&_70$$50, 19);
						zephir_array_update_string(&definition, SL("type"), &_70$$50, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_71$$50);
						ZVAL_LONG(&_71$$50, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_71$$50, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 210)) {
						ZEPHIR_INIT_NVAR(&_72$$51);
						ZVAL_LONG(&_72$$51, 18);
						zephir_array_update_string(&definition, SL("type"), &_72$$51, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 218)) {
						ZEPHIR_INIT_NVAR(&_73$$52);
						ZVAL_LONG(&_73$$52, 4);
						zephir_array_update_string(&definition, SL("type"), &_73$$52, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 226)) {
						ZEPHIR_INIT_NVAR(&_74$$53);
						ZVAL_LONG(&_74$$53, 1);
						zephir_array_update_string(&definition, SL("type"), &_74$$53, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 235)) {
						ZEPHIR_INIT_NVAR(&_75$$54);
						ZVAL_LONG(&_75$$54, 3);
						zephir_array_update_string(&definition, SL("type"), &_75$$54, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("double"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 244)) {
						ZEPHIR_INIT_NVAR(&_76$$55);
						ZVAL_LONG(&_76$$55, 9);
						zephir_array_update_string(&definition, SL("type"), &_76$$55, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_77$$55);
						ZVAL_LONG(&_77$$55, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_77$$55, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 254)) {
						ZEPHIR_INIT_NVAR(&_78$$56);
						ZVAL_LONG(&_78$$56, 7);
						zephir_array_update_string(&definition, SL("type"), &_78$$56, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_79$$56);
						ZVAL_LONG(&_79$$56, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_79$$56, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 264)) {
						ZEPHIR_INIT_NVAR(&_80$$57);
						ZVAL_LONG(&_80$$57, 12);
						zephir_array_update_string(&definition, SL("type"), &_80$$57, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 272)) {
						ZEPHIR_INIT_NVAR(&_81$$58);
						ZVAL_LONG(&_81$$58, 13);
						zephir_array_update_string(&definition, SL("type"), &_81$$58, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 280)) {
						ZEPHIR_INIT_NVAR(&_82$$59);
						ZVAL_LONG(&_82$$59, 10);
						zephir_array_update_string(&definition, SL("type"), &_82$$59, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("blob"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 288)) {
						ZEPHIR_INIT_NVAR(&_83$$60);
						ZVAL_LONG(&_83$$60, 11);
						zephir_array_update_string(&definition, SL("type"), &_83$$60, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 296)) {
						ZEPHIR_INIT_NVAR(&_84$$61);
						ZVAL_LONG(&_84$$61, 17);
						zephir_array_update_string(&definition, SL("type"), &_84$$61, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("time"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 304)) {
						ZEPHIR_INIT_NVAR(&_85$$62);
						ZVAL_LONG(&_85$$62, 20);
						zephir_array_update_string(&definition, SL("type"), &_85$$62, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("json"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 312)) {
						ZEPHIR_INIT_NVAR(&_86$$63);
						ZVAL_LONG(&_86$$63, 15);
						zephir_array_update_string(&definition, SL("type"), &_86$$63, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("longtext"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 320)) {
						ZEPHIR_INIT_NVAR(&_87$$64);
						ZVAL_LONG(&_87$$64, 24);
						zephir_array_update_string(&definition, SL("type"), &_87$$64, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("mediumtext"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 328)) {
						ZEPHIR_INIT_NVAR(&_88$$65);
						ZVAL_LONG(&_88$$65, 23);
						zephir_array_update_string(&definition, SL("type"), &_88$$65, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("tinytext"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 336)) {
						ZEPHIR_INIT_NVAR(&_89$$66);
						ZVAL_LONG(&_89$$66, 25);
						zephir_array_update_string(&definition, SL("type"), &_89$$66, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 344)) {
						ZEPHIR_INIT_NVAR(&_90$$67);
						ZVAL_LONG(&_90$$67, 6);
						zephir_array_update_string(&definition, SL("type"), &_90$$67, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 352)) {
						ZEPHIR_INIT_NVAR(&_91$$68);
						ZVAL_LONG(&_91$$68, 2);
						zephir_array_update_string(&definition, SL("type"), &_91$$68, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_57$$43 == zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 360)) {
						ZEPHIR_INIT_NVAR(&_92$$69);
						ZVAL_LONG(&_92$$69, 5);
						zephir_array_update_string(&definition, SL("type"), &_92$$69, PH_COPY | PH_SEPARATE);
						break;
					}
					ZEPHIR_INIT_NVAR(&_93$$70);
					ZVAL_LONG(&_93$$70, 2);
					zephir_array_update_string(&definition, SL("type"), &_93$$70, PH_COPY | PH_SEPARATE);
					break;
				} while(0);

				if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 378)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					zephir_array_fetch_string(&_94$$71, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 381 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&_95$$71);
					zephir_preg_match(&_95$$71, &sizePattern, &columnType, &matches, 0, 0 , 0  TSRMLS_CC);
					if (ZEPHIR_IS_LONG(&_94$$71, 18)) {
						ZVAL_LONG(&_96$$72, 5);
						ZVAL_LONG(&_97$$72, -1);
						ZEPHIR_INIT_NVAR(&_98$$72);
						zephir_substr(&_98$$72, &columnType, 5 , -1 , 0);
						zephir_array_update_string(&definition, SL("size"), &_98$$72, PH_COPY | PH_SEPARATE);
					} else if (zephir_is_true(&_95$$71)) {
						ZEPHIR_OBS_NVAR(&matchOne);
						if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0 TSRMLS_CC)) {
							ZEPHIR_INIT_NVAR(&_99$$74);
							ZVAL_LONG(&_99$$74, zephir_get_intval(&matchOne));
							zephir_array_update_string(&definition, SL("size"), &_99$$74, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&matchTwo);
						if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0 TSRMLS_CC)) {
							ZEPHIR_INIT_NVAR(&_100$$75);
							ZVAL_LONG(&_100$$75, zephir_get_intval(&matchTwo));
							zephir_array_update_string(&definition, SL("scale"), &_100$$75, PH_COPY | PH_SEPARATE);
						}
					}
				}
				if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 397)) {
					zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
				}
				if (Z_TYPE_P(&oldColumn) == IS_NULL) {
					zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_101$$43, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 413 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&_101$$43, "PRI")) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_102$$43, &field, 2, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 420 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&_102$$43, "NO")) {
					zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_103$$43, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 427 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&_103$$43, "auto_increment")) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_104$$43, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 434 TSRMLS_CC);
				if (Z_TYPE_P(&_104$$43) != IS_NULL) {
					zephir_array_fetch_long(&_105$$82, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 435 TSRMLS_CC);
					zephir_array_update_string(&definition, SL("default"), &_105$$82, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 441 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&_106$$43);
				object_init_ex(&_106$$43, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_106$$43, "__construct", &_55, 182, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_106$$43, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 442);
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
 * <code>
 * print_r(
 *     $connection->describeIndexes("robots_parts")
 * );
 * </code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeIndexes) {

	zend_string *_25;
	zend_ulong _24;
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
	zephir_read_property(&_1, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeindexes", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 492);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _4);
			zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 465 TSRMLS_CC);
			zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 466 TSRMLS_CC);
			if (!(zephir_array_isset(&indexes, &keyName))) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				array_init(&_6$$4);
				zephir_array_update_zval(&indexes, &keyName, &_6$$4, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch(&_7$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 472 TSRMLS_CC);
			if (!(zephir_array_isset_string(&_7$$3, SL("columns")))) {
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
			} else {
				zephir_array_fetch(&_8$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 475 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_8$$6, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 475 TSRMLS_CC);
			}
			zephir_array_fetch_string(&_9$$3, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 478 TSRMLS_CC);
			zephir_array_append(&columns, &_9$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 478);
			zephir_array_update_multi(&indexes, &columns TSRMLS_CC, SL("zs"), 3, &keyName, SL("columns"));
			zephir_array_fetch_string(&_10$$3, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 485 TSRMLS_CC);
			if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
				ZEPHIR_INIT_NVAR(&_11$$7);
				ZVAL_STRING(&_11$$7, "PRIMARY");
				zephir_array_update_multi(&indexes, &_11$$7 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
			} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
				ZEPHIR_INIT_NVAR(&_12$$8);
				ZVAL_STRING(&_12$$8, "FULLTEXT");
				zephir_array_update_multi(&indexes, &_12$$8 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
			} else if (ZEPHIR_IS_LONG(&_10$$3, 0)) {
				ZEPHIR_INIT_NVAR(&_13$$9);
				ZVAL_STRING(&_13$$9, "UNIQUE");
				zephir_array_update_multi(&indexes, &_13$$9 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
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
				zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 465 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&indexType);
				zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 466 TSRMLS_CC);
				if (!(zephir_array_isset(&indexes, &keyName))) {
					ZEPHIR_INIT_NVAR(&_14$$12);
					array_init(&_14$$12);
					zephir_array_update_zval(&indexes, &keyName, &_14$$12, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch(&_15$$11, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 472 TSRMLS_CC);
				if (!(zephir_array_isset_string(&_15$$11, SL("columns")))) {
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
				} else {
					zephir_array_fetch(&_16$$14, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 475 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_16$$14, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 475 TSRMLS_CC);
				}
				zephir_array_fetch_string(&_17$$11, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 478 TSRMLS_CC);
				zephir_array_append(&columns, &_17$$11, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 478);
				zephir_array_update_multi(&indexes, &columns TSRMLS_CC, SL("zs"), 3, &keyName, SL("columns"));
				zephir_array_fetch_string(&_18$$11, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 485 TSRMLS_CC);
				if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
					ZEPHIR_INIT_NVAR(&_19$$15);
					ZVAL_STRING(&_19$$15, "PRIMARY");
					zephir_array_update_multi(&indexes, &_19$$15 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
				} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
					ZEPHIR_INIT_NVAR(&_20$$16);
					ZVAL_STRING(&_20$$16, "FULLTEXT");
					zephir_array_update_multi(&indexes, &_20$$16 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
				} else if (ZEPHIR_IS_LONG(&_18$$11, 0)) {
					ZEPHIR_INIT_NVAR(&_21$$17);
					ZVAL_STRING(&_21$$17, "UNIQUE");
					zephir_array_update_multi(&indexes, &_21$$17 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
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
	zephir_is_iterable(&indexes, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 502);
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
			zephir_array_fetch_string(&_27$$19, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 497 TSRMLS_CC);
			zephir_array_fetch_string(&_28$$19, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 499 TSRMLS_CC);
			ZEPHIR_CALL_METHOD(NULL, &_26$$19, "__construct", &_29, 21, &name, &_27$$19, &_28$$19);
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
				zephir_array_fetch_string(&_31$$20, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 497 TSRMLS_CC);
				zephir_array_fetch_string(&_32$$20, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 499 TSRMLS_CC);
				ZEPHIR_CALL_METHOD(NULL, &_30$$20, "__construct", &_29, 21, &name, &_31$$20, &_32$$20);
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
 *<code>
 * print_r(
 *     $connection->describeReferences("robots_parts")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeReferences) {

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
	zephir_read_property(&_1, this_ptr, SL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describereferences", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 555);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _4);
			zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 524 TSRMLS_CC);
			if (!(zephir_array_isset(&references, &constraintName))) {
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 527 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 528 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 529 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 530 TSRMLS_CC);
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 534 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_6$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 534 TSRMLS_CC);
				zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 535 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_7$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 535 TSRMLS_CC);
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 536 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_8$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 536 TSRMLS_CC);
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 537 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_9$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 537 TSRMLS_CC);
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 538 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_string(&referenceUpdate, &_10$$5, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 538 TSRMLS_CC);
				zephir_array_fetch(&_11$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 539 TSRMLS_CC);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_string(&referenceDelete, &_11$$5, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 539 TSRMLS_CC);
			}
			zephir_array_fetch_long(&_12$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 542 TSRMLS_CC);
			zephir_array_append(&columns, &_12$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 542);
			zephir_array_fetch_long(&_13$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 543 TSRMLS_CC);
			zephir_array_append(&referencedColumns, &_13$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 543);
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
				zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 524 TSRMLS_CC);
				if (!(zephir_array_isset(&references, &constraintName))) {
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 527 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 528 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 529 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 530 TSRMLS_CC);
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_15$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 534 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_15$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 534 TSRMLS_CC);
					zephir_array_fetch(&_16$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 535 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_16$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 535 TSRMLS_CC);
					zephir_array_fetch(&_17$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 536 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_17$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 536 TSRMLS_CC);
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 537 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_18$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 537 TSRMLS_CC);
					zephir_array_fetch(&_19$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 538 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_string(&referenceUpdate, &_19$$8, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 538 TSRMLS_CC);
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 539 TSRMLS_CC);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_string(&referenceDelete, &_20$$8, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 539 TSRMLS_CC);
				}
				zephir_array_fetch_long(&_21$$6, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 542 TSRMLS_CC);
				zephir_array_append(&columns, &_21$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 542);
				zephir_array_fetch_long(&_22$$6, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 543 TSRMLS_CC);
				zephir_array_append(&referencedColumns, &_22$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 543);
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
	zephir_is_iterable(&references, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 570);
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
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 560 TSRMLS_CC);
			zephir_array_update_string(&_29$$9, SL("referencedSchema"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 561 TSRMLS_CC);
			zephir_array_update_string(&_29$$9, SL("referencedTable"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 562 TSRMLS_CC);
			zephir_array_update_string(&_29$$9, SL("columns"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 563 TSRMLS_CC);
			zephir_array_update_string(&_29$$9, SL("referencedColumns"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 564 TSRMLS_CC);
			zephir_array_update_string(&_29$$9, SL("onUpdate"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 566 TSRMLS_CC);
			zephir_array_update_string(&_29$$9, SL("onDelete"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_28$$9, "__construct", &_31, 22, &name, &_29$$9);
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
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 560 TSRMLS_CC);
				zephir_array_update_string(&_33$$10, SL("referencedSchema"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 561 TSRMLS_CC);
				zephir_array_update_string(&_33$$10, SL("referencedTable"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 562 TSRMLS_CC);
				zephir_array_update_string(&_33$$10, SL("columns"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 563 TSRMLS_CC);
				zephir_array_update_string(&_33$$10, SL("referencedColumns"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 564 TSRMLS_CC);
				zephir_array_update_string(&_33$$10, SL("onUpdate"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 566 TSRMLS_CC);
				zephir_array_update_string(&_33$$10, SL("onDelete"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &_32$$10, "__construct", &_31, 22, &name, &_33$$10);
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


	zephir_create_array(return_value, 1, 0 TSRMLS_CC);
	add_assoc_stringl_ex(return_value, SL("charset"), SL("utf8mb4"));
	return;

}

