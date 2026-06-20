
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
#include "kernel/array.h"
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
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql)
{
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, addForeignKey)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *reference, reference_sub, foreignKeyCheck, _0, _1, _2, _4, _5, _3$$3;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&foreignKeyCheck);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_3$$3);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(reference, phalcon_db_referenceinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	reference = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getforeignkeychecks", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&foreignKeyCheck, this_ptr, "prepare", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &foreignKeyCheck, "execute", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_db_exceptions_missingforeignkeychecks_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 425);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Db/Adapter/Pdo/Mysql.zep", 65);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_4, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "addforeignkey", NULL, 0, &tableName_zv, &schemaName_zv, reference);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_5);
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns)
{
	zend_bool _74, _4$$3, _58$$3, _59$$3, _60$$3, _63$$54, _76$$62, _130$$62, _131$$62, _132$$62, _135$$113;
	zval definition;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_72 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, __$true, __$false, columns, columnType, fields, field, oldColumn, sizePattern, matches, matchOne, matchTwo, columnName, extraValue, generationExpression, _0, _1, _2, *_3, _73, _56$$3, _57$$3, _69$$3, _71$$3, _5$$4, _6$$4, _7$$5, _8$$5, _9$$6, _10$$6, _11$$7, _12$$7, _13$$8, _14$$8, _15$$9, _16$$9, _17$$10, _18$$11, _19$$12, _20$$13, _21$$14, _22$$14, _23$$15, _24$$15, _25$$16, _26$$17, _27$$18, _28$$19, _29$$20, _30$$21, _31$$22, _32$$23, _33$$24, _34$$25, _35$$26, _36$$27, _37$$28, _38$$29, _39$$30, _40$$31, _41$$32, _42$$33, _43$$34, _44$$35, _45$$36, _46$$37, _47$$38, _48$$39, _49$$40, _50$$40, _51$$41, _52$$41, _53$$41, _54$$43, _55$$44, _61$$51, _62$$54, _64$$54, _65$$57, _66$$57, _67$$58, _68$$60, _70$$61, _75$$62, _128$$62, _129$$62, _141$$62, _143$$62, _77$$63, _78$$63, _79$$64, _80$$64, _81$$65, _82$$65, _83$$66, _84$$66, _85$$67, _86$$67, _87$$68, _88$$68, _89$$69, _90$$70, _91$$71, _92$$72, _93$$73, _94$$73, _95$$74, _96$$74, _97$$75, _98$$76, _99$$77, _100$$78, _101$$79, _102$$80, _103$$81, _104$$82, _105$$83, _106$$84, _107$$85, _108$$86, _109$$87, _110$$88, _111$$89, _112$$90, _113$$91, _114$$92, _115$$93, _116$$94, _117$$95, _118$$96, _119$$97, _120$$98, _121$$99, _122$$99, _123$$100, _124$$100, _125$$100, _126$$102, _127$$103, _133$$110, _134$$113, _136$$113, _137$$116, _138$$116, _139$$117, _140$$119, _142$$120;
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
	ZVAL_UNDEF(&oldColumn);
	ZVAL_UNDEF(&sizePattern);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&matchOne);
	ZVAL_UNDEF(&matchTwo);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&extraValue);
	ZVAL_UNDEF(&generationExpression);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_73);
	ZVAL_UNDEF(&_56$$3);
	ZVAL_UNDEF(&_57$$3);
	ZVAL_UNDEF(&_69$$3);
	ZVAL_UNDEF(&_71$$3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_10$$6);
	ZVAL_UNDEF(&_11$$7);
	ZVAL_UNDEF(&_12$$7);
	ZVAL_UNDEF(&_13$$8);
	ZVAL_UNDEF(&_14$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_24$$15);
	ZVAL_UNDEF(&_25$$16);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_27$$18);
	ZVAL_UNDEF(&_28$$19);
	ZVAL_UNDEF(&_29$$20);
	ZVAL_UNDEF(&_30$$21);
	ZVAL_UNDEF(&_31$$22);
	ZVAL_UNDEF(&_32$$23);
	ZVAL_UNDEF(&_33$$24);
	ZVAL_UNDEF(&_34$$25);
	ZVAL_UNDEF(&_35$$26);
	ZVAL_UNDEF(&_36$$27);
	ZVAL_UNDEF(&_37$$28);
	ZVAL_UNDEF(&_38$$29);
	ZVAL_UNDEF(&_39$$30);
	ZVAL_UNDEF(&_40$$31);
	ZVAL_UNDEF(&_41$$32);
	ZVAL_UNDEF(&_42$$33);
	ZVAL_UNDEF(&_43$$34);
	ZVAL_UNDEF(&_44$$35);
	ZVAL_UNDEF(&_45$$36);
	ZVAL_UNDEF(&_46$$37);
	ZVAL_UNDEF(&_47$$38);
	ZVAL_UNDEF(&_48$$39);
	ZVAL_UNDEF(&_49$$40);
	ZVAL_UNDEF(&_50$$40);
	ZVAL_UNDEF(&_51$$41);
	ZVAL_UNDEF(&_52$$41);
	ZVAL_UNDEF(&_53$$41);
	ZVAL_UNDEF(&_54$$43);
	ZVAL_UNDEF(&_55$$44);
	ZVAL_UNDEF(&_61$$51);
	ZVAL_UNDEF(&_62$$54);
	ZVAL_UNDEF(&_64$$54);
	ZVAL_UNDEF(&_65$$57);
	ZVAL_UNDEF(&_66$$57);
	ZVAL_UNDEF(&_67$$58);
	ZVAL_UNDEF(&_68$$60);
	ZVAL_UNDEF(&_70$$61);
	ZVAL_UNDEF(&_75$$62);
	ZVAL_UNDEF(&_128$$62);
	ZVAL_UNDEF(&_129$$62);
	ZVAL_UNDEF(&_141$$62);
	ZVAL_UNDEF(&_143$$62);
	ZVAL_UNDEF(&_77$$63);
	ZVAL_UNDEF(&_78$$63);
	ZVAL_UNDEF(&_79$$64);
	ZVAL_UNDEF(&_80$$64);
	ZVAL_UNDEF(&_81$$65);
	ZVAL_UNDEF(&_82$$65);
	ZVAL_UNDEF(&_83$$66);
	ZVAL_UNDEF(&_84$$66);
	ZVAL_UNDEF(&_85$$67);
	ZVAL_UNDEF(&_86$$67);
	ZVAL_UNDEF(&_87$$68);
	ZVAL_UNDEF(&_88$$68);
	ZVAL_UNDEF(&_89$$69);
	ZVAL_UNDEF(&_90$$70);
	ZVAL_UNDEF(&_91$$71);
	ZVAL_UNDEF(&_92$$72);
	ZVAL_UNDEF(&_93$$73);
	ZVAL_UNDEF(&_94$$73);
	ZVAL_UNDEF(&_95$$74);
	ZVAL_UNDEF(&_96$$74);
	ZVAL_UNDEF(&_97$$75);
	ZVAL_UNDEF(&_98$$76);
	ZVAL_UNDEF(&_99$$77);
	ZVAL_UNDEF(&_100$$78);
	ZVAL_UNDEF(&_101$$79);
	ZVAL_UNDEF(&_102$$80);
	ZVAL_UNDEF(&_103$$81);
	ZVAL_UNDEF(&_104$$82);
	ZVAL_UNDEF(&_105$$83);
	ZVAL_UNDEF(&_106$$84);
	ZVAL_UNDEF(&_107$$85);
	ZVAL_UNDEF(&_108$$86);
	ZVAL_UNDEF(&_109$$87);
	ZVAL_UNDEF(&_110$$88);
	ZVAL_UNDEF(&_111$$89);
	ZVAL_UNDEF(&_112$$90);
	ZVAL_UNDEF(&_113$$91);
	ZVAL_UNDEF(&_114$$92);
	ZVAL_UNDEF(&_115$$93);
	ZVAL_UNDEF(&_116$$94);
	ZVAL_UNDEF(&_117$$95);
	ZVAL_UNDEF(&_118$$96);
	ZVAL_UNDEF(&_119$$97);
	ZVAL_UNDEF(&_120$$98);
	ZVAL_UNDEF(&_121$$99);
	ZVAL_UNDEF(&_122$$99);
	ZVAL_UNDEF(&_123$$100);
	ZVAL_UNDEF(&_124$$100);
	ZVAL_UNDEF(&_125$$100);
	ZVAL_UNDEF(&_126$$102);
	ZVAL_UNDEF(&_127$$103);
	ZVAL_UNDEF(&_133$$110);
	ZVAL_UNDEF(&_134$$113);
	ZVAL_UNDEF(&_136$$113);
	ZVAL_UNDEF(&_137$$116);
	ZVAL_UNDEF(&_138$$116);
	ZVAL_UNDEF(&_139$$117);
	ZVAL_UNDEF(&_140$$119);
	ZVAL_UNDEF(&_142$$120);
	ZVAL_UNDEF(&definition);
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
	zephir_is_iterable(&fields, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 555);
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
				_4$$3 = 1;
				if (_4$$3 == zephir_start_with_str(&columnType, SL("bigint"))) {
					ZEPHIR_INIT_NVAR(&_5$$4);
					ZVAL_LONG(&_5$$4, 14);
					zephir_array_update_string(&definition, SL("type"), &_5$$4, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_6$$4);
					ZVAL_LONG(&_6$$4, 2);
					zephir_array_update_string(&definition, SL("bindType"), &_6$$4, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("mediumint"))) {
					ZEPHIR_INIT_NVAR(&_7$$5);
					ZVAL_LONG(&_7$$5, 21);
					zephir_array_update_string(&definition, SL("type"), &_7$$5, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_8$$5);
					ZVAL_LONG(&_8$$5, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_8$$5, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("smallint"))) {
					ZEPHIR_INIT_NVAR(&_9$$6);
					ZVAL_LONG(&_9$$6, 22);
					zephir_array_update_string(&definition, SL("type"), &_9$$6, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_10$$6);
					ZVAL_LONG(&_10$$6, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_10$$6, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("tinyint"))) {
					ZEPHIR_INIT_NVAR(&_11$$7);
					ZVAL_LONG(&_11$$7, 26);
					zephir_array_update_string(&definition, SL("type"), &_11$$7, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_12$$7);
					ZVAL_LONG(&_12$$7, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_12$$7, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("int"))) {
					ZEPHIR_INIT_NVAR(&_13$$8);
					ZVAL_LONG(&_13$$8, 0);
					zephir_array_update_string(&definition, SL("type"), &_13$$8, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_14$$8);
					ZVAL_LONG(&_14$$8, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_14$$8, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("bit"))) {
					ZEPHIR_INIT_NVAR(&_15$$9);
					ZVAL_LONG(&_15$$9, 19);
					zephir_array_update_string(&definition, SL("type"), &_15$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_16$$9);
					ZVAL_LONG(&_16$$9, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_16$$9, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("enum"))) {
					ZEPHIR_INIT_NVAR(&_17$$10);
					ZVAL_LONG(&_17$$10, 18);
					zephir_array_update_string(&definition, SL("type"), &_17$$10, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("datetime"))) {
					ZEPHIR_INIT_NVAR(&_18$$11);
					ZVAL_LONG(&_18$$11, 4);
					zephir_array_update_string(&definition, SL("type"), &_18$$11, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("date"))) {
					ZEPHIR_INIT_NVAR(&_19$$12);
					ZVAL_LONG(&_19$$12, 1);
					zephir_array_update_string(&definition, SL("type"), &_19$$12, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("decimal"))) {
					ZEPHIR_INIT_NVAR(&_20$$13);
					ZVAL_LONG(&_20$$13, 3);
					zephir_array_update_string(&definition, SL("type"), &_20$$13, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("double"))) {
					ZEPHIR_INIT_NVAR(&_21$$14);
					ZVAL_LONG(&_21$$14, 9);
					zephir_array_update_string(&definition, SL("type"), &_21$$14, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_22$$14);
					ZVAL_LONG(&_22$$14, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_22$$14, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("float"))) {
					ZEPHIR_INIT_NVAR(&_23$$15);
					ZVAL_LONG(&_23$$15, 7);
					zephir_array_update_string(&definition, SL("type"), &_23$$15, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_24$$15);
					ZVAL_LONG(&_24$$15, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_24$$15, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("mediumblob"))) {
					ZEPHIR_INIT_NVAR(&_25$$16);
					ZVAL_LONG(&_25$$16, 12);
					zephir_array_update_string(&definition, SL("type"), &_25$$16, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("longblob"))) {
					ZEPHIR_INIT_NVAR(&_26$$17);
					ZVAL_LONG(&_26$$17, 13);
					zephir_array_update_string(&definition, SL("type"), &_26$$17, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("tinyblob"))) {
					ZEPHIR_INIT_NVAR(&_27$$18);
					ZVAL_LONG(&_27$$18, 10);
					zephir_array_update_string(&definition, SL("type"), &_27$$18, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("blob"))) {
					ZEPHIR_INIT_NVAR(&_28$$19);
					ZVAL_LONG(&_28$$19, 11);
					zephir_array_update_string(&definition, SL("type"), &_28$$19, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("timestamp"))) {
					ZEPHIR_INIT_NVAR(&_29$$20);
					ZVAL_LONG(&_29$$20, 17);
					zephir_array_update_string(&definition, SL("type"), &_29$$20, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("time"))) {
					ZEPHIR_INIT_NVAR(&_30$$21);
					ZVAL_LONG(&_30$$21, 20);
					zephir_array_update_string(&definition, SL("type"), &_30$$21, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("json"))) {
					ZEPHIR_INIT_NVAR(&_31$$22);
					ZVAL_LONG(&_31$$22, 15);
					zephir_array_update_string(&definition, SL("type"), &_31$$22, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("longtext"))) {
					ZEPHIR_INIT_NVAR(&_32$$23);
					ZVAL_LONG(&_32$$23, 24);
					zephir_array_update_string(&definition, SL("type"), &_32$$23, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("mediumtext"))) {
					ZEPHIR_INIT_NVAR(&_33$$24);
					ZVAL_LONG(&_33$$24, 23);
					zephir_array_update_string(&definition, SL("type"), &_33$$24, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("tinytext"))) {
					ZEPHIR_INIT_NVAR(&_34$$25);
					ZVAL_LONG(&_34$$25, 25);
					zephir_array_update_string(&definition, SL("type"), &_34$$25, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("text"))) {
					ZEPHIR_INIT_NVAR(&_35$$26);
					ZVAL_LONG(&_35$$26, 6);
					zephir_array_update_string(&definition, SL("type"), &_35$$26, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("varchar"))) {
					ZEPHIR_INIT_NVAR(&_36$$27);
					ZVAL_LONG(&_36$$27, 2);
					zephir_array_update_string(&definition, SL("type"), &_36$$27, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("char"))) {
					ZEPHIR_INIT_NVAR(&_37$$28);
					ZVAL_LONG(&_37$$28, 5);
					zephir_array_update_string(&definition, SL("type"), &_37$$28, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("varbinary"))) {
					ZEPHIR_INIT_NVAR(&_38$$29);
					ZVAL_LONG(&_38$$29, 28);
					zephir_array_update_string(&definition, SL("type"), &_38$$29, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("binary"))) {
					ZEPHIR_INIT_NVAR(&_39$$30);
					ZVAL_LONG(&_39$$30, 27);
					zephir_array_update_string(&definition, SL("type"), &_39$$30, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("multipoint"))) {
					ZEPHIR_INIT_NVAR(&_40$$31);
					ZVAL_LONG(&_40$$31, 44);
					zephir_array_update_string(&definition, SL("type"), &_40$$31, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("multilinestring"))) {
					ZEPHIR_INIT_NVAR(&_41$$32);
					ZVAL_LONG(&_41$$32, 45);
					zephir_array_update_string(&definition, SL("type"), &_41$$32, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("multipolygon"))) {
					ZEPHIR_INIT_NVAR(&_42$$33);
					ZVAL_LONG(&_42$$33, 46);
					zephir_array_update_string(&definition, SL("type"), &_42$$33, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("geometrycollection"))) {
					ZEPHIR_INIT_NVAR(&_43$$34);
					ZVAL_LONG(&_43$$34, 47);
					zephir_array_update_string(&definition, SL("type"), &_43$$34, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("linestring"))) {
					ZEPHIR_INIT_NVAR(&_44$$35);
					ZVAL_LONG(&_44$$35, 42);
					zephir_array_update_string(&definition, SL("type"), &_44$$35, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("polygon"))) {
					ZEPHIR_INIT_NVAR(&_45$$36);
					ZVAL_LONG(&_45$$36, 43);
					zephir_array_update_string(&definition, SL("type"), &_45$$36, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("point"))) {
					ZEPHIR_INIT_NVAR(&_46$$37);
					ZVAL_LONG(&_46$$37, 41);
					zephir_array_update_string(&definition, SL("type"), &_46$$37, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_start_with_str(&columnType, SL("geometry"))) {
					ZEPHIR_INIT_NVAR(&_47$$38);
					ZVAL_LONG(&_47$$38, 40);
					zephir_array_update_string(&definition, SL("type"), &_47$$38, PH_COPY | PH_SEPARATE);
					break;
				}
				ZEPHIR_INIT_NVAR(&_48$$39);
				ZVAL_LONG(&_48$$39, 2);
				zephir_array_update_string(&definition, SL("type"), &_48$$39, PH_COPY | PH_SEPARATE);
				break;
			} while(0);

			if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 429)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				zephir_array_fetch_string(&_49$$40, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 432);
				if (ZEPHIR_IS_LONG(&_49$$40, 18)) {
					ZVAL_LONG(&_51$$41, 5);
					ZVAL_LONG(&_52$$41, -1);
					ZEPHIR_INIT_NVAR(&_53$$41);
					zephir_substr(&_53$$41, &columnType, 5 , -1 , 0);
					zephir_array_update_string(&definition, SL("size"), &_53$$41, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_50$$40);
					zephir_preg_match(&_50$$40, &sizePattern, &columnType, &matches, 0, 0 , 0 );
					if (zephir_is_true(&_50$$40)) {
						ZEPHIR_OBS_NVAR(&matchOne);
						if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
							ZEPHIR_INIT_NVAR(&_54$$43);
							ZVAL_LONG(&_54$$43, zephir_get_intval(&matchOne));
							zephir_array_update_string(&definition, SL("size"), &_54$$43, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&matchTwo);
						if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
							ZEPHIR_INIT_NVAR(&_55$$44);
							ZVAL_LONG(&_55$$44, zephir_get_intval(&matchTwo));
							zephir_array_update_string(&definition, SL("scale"), &_55$$44, PH_COPY | PH_SEPARATE);
						}
					}
				}
			}
			if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 448)) {
				zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&oldColumn) == IS_NULL) {
				zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_56$$3, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 464);
			if (ZEPHIR_IS_STRING(&_56$$3, "PRI")) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_57$$3, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 471);
			if (ZEPHIR_IS_STRING(&_57$$3, "YES")) {
				zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_OBS_NVAR(&extraValue);
			zephir_array_fetch_long(&extraValue, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 480);
			_58$$3 = Z_TYPE_P(&extraValue) != IS_NULL;
			if (_58$$3) {
				_58$$3 = zephir_memnstr_str(&extraValue, SL("INVISIBLE"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 481);
			}
			if (_58$$3) {
				zephir_array_update_string(&definition, SL("invisible"), &__$true, PH_COPY | PH_SEPARATE);
			}
			_59$$3 = Z_TYPE_P(&extraValue) != IS_NULL;
			if (_59$$3) {
				_60$$3 = zephir_memnstr_str(&extraValue, SL("VIRTUAL GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 499);
				if (!(_60$$3)) {
					_60$$3 = zephir_memnstr_str(&extraValue, SL("STORED GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 499);
				}
				_59$$3 = _60$$3;
			}
			if (_59$$3) {
				if (zephir_array_isset_value_long(&field, 9)) {
					ZEPHIR_OBS_NVAR(&generationExpression);
					zephir_array_fetch_long(&generationExpression, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 501);
				} else {
					ZEPHIR_INIT_NVAR(&generationExpression);
					ZVAL_STRING(&generationExpression, "");
				}
				zephir_array_update_string(&definition, SL("generated"), &generationExpression, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_61$$51);
				ZVAL_BOOL(&_61$$51, zephir_memnstr_str(&extraValue, SL("STORED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 507));
				zephir_array_update_string(&definition, SL("generationStored"), &_61$$51, PH_COPY | PH_SEPARATE);
			} else {
				if (ZEPHIR_IS_STRING(&extraValue, "auto_increment")) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_62$$54, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 527);
				_63$$54 = Z_TYPE_P(&_62$$54) != IS_NULL;
				if (_63$$54) {
					zephir_array_fetch_long(&_64$$54, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 527);
					_63$$54 = !ZEPHIR_IS_STRING_IDENTICAL(&_64$$54, "NULL");
				}
				if (_63$$54) {
					if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 528)) {
						zephir_array_fetch_long(&_65$$57, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 529);
						ZEPHIR_INIT_NVAR(&_66$$57);
						ZEPHIR_CONCAT_VSV(&_66$$57, &_65$$57, " ", &extraValue);
						zephir_array_update_string(&definition, SL("default"), &_66$$57, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_fetch_long(&_67$$58, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 531);
						zephir_array_update_string(&definition, SL("default"), &_67$$58, PH_COPY | PH_SEPARATE);
					}
				} else {
					if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 534)) {
						ZEPHIR_INIT_NVAR(&_68$$60);
						ZEPHIR_CONCAT_SV(&_68$$60, "NULL ", &extraValue);
						zephir_array_update_string(&definition, SL("default"), &_68$$60, PH_COPY | PH_SEPARATE);
					}
				}
			}
			zephir_array_fetch_long(&_69$$3, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 543);
			if (Z_TYPE_P(&_69$$3) != IS_NULL) {
				zephir_array_fetch_long(&_70$$61, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 544);
				zephir_array_update_string(&definition, SL("comment"), &_70$$61, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 550);
			ZEPHIR_INIT_NVAR(&_71$$3);
			object_init_ex(&_71$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_71$$3, "__construct", &_72, 426, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_71$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 551);
			ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
		zephir_check_call_status();
		_74 = 1;
		while (1) {
			if (_74) {
				_74 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_73, &fields, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_73)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_75$$62);
				zephir_create_array(&_75$$62, 1, 0);
				add_assoc_long_ex(&_75$$62, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_75$$62);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 121);
				do {
					_76$$62 = 1;
					if (_76$$62 == zephir_start_with_str(&columnType, SL("bigint"))) {
						ZEPHIR_INIT_NVAR(&_77$$63);
						ZVAL_LONG(&_77$$63, 14);
						zephir_array_update_string(&definition, SL("type"), &_77$$63, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_78$$63);
						ZVAL_LONG(&_78$$63, 2);
						zephir_array_update_string(&definition, SL("bindType"), &_78$$63, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("mediumint"))) {
						ZEPHIR_INIT_NVAR(&_79$$64);
						ZVAL_LONG(&_79$$64, 21);
						zephir_array_update_string(&definition, SL("type"), &_79$$64, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_80$$64);
						ZVAL_LONG(&_80$$64, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_80$$64, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("smallint"))) {
						ZEPHIR_INIT_NVAR(&_81$$65);
						ZVAL_LONG(&_81$$65, 22);
						zephir_array_update_string(&definition, SL("type"), &_81$$65, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_82$$65);
						ZVAL_LONG(&_82$$65, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_82$$65, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("tinyint"))) {
						ZEPHIR_INIT_NVAR(&_83$$66);
						ZVAL_LONG(&_83$$66, 26);
						zephir_array_update_string(&definition, SL("type"), &_83$$66, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_84$$66);
						ZVAL_LONG(&_84$$66, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_84$$66, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("int"))) {
						ZEPHIR_INIT_NVAR(&_85$$67);
						ZVAL_LONG(&_85$$67, 0);
						zephir_array_update_string(&definition, SL("type"), &_85$$67, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_86$$67);
						ZVAL_LONG(&_86$$67, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_86$$67, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("bit"))) {
						ZEPHIR_INIT_NVAR(&_87$$68);
						ZVAL_LONG(&_87$$68, 19);
						zephir_array_update_string(&definition, SL("type"), &_87$$68, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_88$$68);
						ZVAL_LONG(&_88$$68, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_88$$68, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("enum"))) {
						ZEPHIR_INIT_NVAR(&_89$$69);
						ZVAL_LONG(&_89$$69, 18);
						zephir_array_update_string(&definition, SL("type"), &_89$$69, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("datetime"))) {
						ZEPHIR_INIT_NVAR(&_90$$70);
						ZVAL_LONG(&_90$$70, 4);
						zephir_array_update_string(&definition, SL("type"), &_90$$70, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("date"))) {
						ZEPHIR_INIT_NVAR(&_91$$71);
						ZVAL_LONG(&_91$$71, 1);
						zephir_array_update_string(&definition, SL("type"), &_91$$71, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("decimal"))) {
						ZEPHIR_INIT_NVAR(&_92$$72);
						ZVAL_LONG(&_92$$72, 3);
						zephir_array_update_string(&definition, SL("type"), &_92$$72, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("double"))) {
						ZEPHIR_INIT_NVAR(&_93$$73);
						ZVAL_LONG(&_93$$73, 9);
						zephir_array_update_string(&definition, SL("type"), &_93$$73, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_94$$73);
						ZVAL_LONG(&_94$$73, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_94$$73, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("float"))) {
						ZEPHIR_INIT_NVAR(&_95$$74);
						ZVAL_LONG(&_95$$74, 7);
						zephir_array_update_string(&definition, SL("type"), &_95$$74, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_96$$74);
						ZVAL_LONG(&_96$$74, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_96$$74, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("mediumblob"))) {
						ZEPHIR_INIT_NVAR(&_97$$75);
						ZVAL_LONG(&_97$$75, 12);
						zephir_array_update_string(&definition, SL("type"), &_97$$75, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("longblob"))) {
						ZEPHIR_INIT_NVAR(&_98$$76);
						ZVAL_LONG(&_98$$76, 13);
						zephir_array_update_string(&definition, SL("type"), &_98$$76, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("tinyblob"))) {
						ZEPHIR_INIT_NVAR(&_99$$77);
						ZVAL_LONG(&_99$$77, 10);
						zephir_array_update_string(&definition, SL("type"), &_99$$77, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("blob"))) {
						ZEPHIR_INIT_NVAR(&_100$$78);
						ZVAL_LONG(&_100$$78, 11);
						zephir_array_update_string(&definition, SL("type"), &_100$$78, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("timestamp"))) {
						ZEPHIR_INIT_NVAR(&_101$$79);
						ZVAL_LONG(&_101$$79, 17);
						zephir_array_update_string(&definition, SL("type"), &_101$$79, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("time"))) {
						ZEPHIR_INIT_NVAR(&_102$$80);
						ZVAL_LONG(&_102$$80, 20);
						zephir_array_update_string(&definition, SL("type"), &_102$$80, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("json"))) {
						ZEPHIR_INIT_NVAR(&_103$$81);
						ZVAL_LONG(&_103$$81, 15);
						zephir_array_update_string(&definition, SL("type"), &_103$$81, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("longtext"))) {
						ZEPHIR_INIT_NVAR(&_104$$82);
						ZVAL_LONG(&_104$$82, 24);
						zephir_array_update_string(&definition, SL("type"), &_104$$82, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("mediumtext"))) {
						ZEPHIR_INIT_NVAR(&_105$$83);
						ZVAL_LONG(&_105$$83, 23);
						zephir_array_update_string(&definition, SL("type"), &_105$$83, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("tinytext"))) {
						ZEPHIR_INIT_NVAR(&_106$$84);
						ZVAL_LONG(&_106$$84, 25);
						zephir_array_update_string(&definition, SL("type"), &_106$$84, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("text"))) {
						ZEPHIR_INIT_NVAR(&_107$$85);
						ZVAL_LONG(&_107$$85, 6);
						zephir_array_update_string(&definition, SL("type"), &_107$$85, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("varchar"))) {
						ZEPHIR_INIT_NVAR(&_108$$86);
						ZVAL_LONG(&_108$$86, 2);
						zephir_array_update_string(&definition, SL("type"), &_108$$86, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("char"))) {
						ZEPHIR_INIT_NVAR(&_109$$87);
						ZVAL_LONG(&_109$$87, 5);
						zephir_array_update_string(&definition, SL("type"), &_109$$87, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("varbinary"))) {
						ZEPHIR_INIT_NVAR(&_110$$88);
						ZVAL_LONG(&_110$$88, 28);
						zephir_array_update_string(&definition, SL("type"), &_110$$88, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("binary"))) {
						ZEPHIR_INIT_NVAR(&_111$$89);
						ZVAL_LONG(&_111$$89, 27);
						zephir_array_update_string(&definition, SL("type"), &_111$$89, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("multipoint"))) {
						ZEPHIR_INIT_NVAR(&_112$$90);
						ZVAL_LONG(&_112$$90, 44);
						zephir_array_update_string(&definition, SL("type"), &_112$$90, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("multilinestring"))) {
						ZEPHIR_INIT_NVAR(&_113$$91);
						ZVAL_LONG(&_113$$91, 45);
						zephir_array_update_string(&definition, SL("type"), &_113$$91, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("multipolygon"))) {
						ZEPHIR_INIT_NVAR(&_114$$92);
						ZVAL_LONG(&_114$$92, 46);
						zephir_array_update_string(&definition, SL("type"), &_114$$92, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("geometrycollection"))) {
						ZEPHIR_INIT_NVAR(&_115$$93);
						ZVAL_LONG(&_115$$93, 47);
						zephir_array_update_string(&definition, SL("type"), &_115$$93, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("linestring"))) {
						ZEPHIR_INIT_NVAR(&_116$$94);
						ZVAL_LONG(&_116$$94, 42);
						zephir_array_update_string(&definition, SL("type"), &_116$$94, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("polygon"))) {
						ZEPHIR_INIT_NVAR(&_117$$95);
						ZVAL_LONG(&_117$$95, 43);
						zephir_array_update_string(&definition, SL("type"), &_117$$95, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("point"))) {
						ZEPHIR_INIT_NVAR(&_118$$96);
						ZVAL_LONG(&_118$$96, 41);
						zephir_array_update_string(&definition, SL("type"), &_118$$96, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_76$$62 == zephir_start_with_str(&columnType, SL("geometry"))) {
						ZEPHIR_INIT_NVAR(&_119$$97);
						ZVAL_LONG(&_119$$97, 40);
						zephir_array_update_string(&definition, SL("type"), &_119$$97, PH_COPY | PH_SEPARATE);
						break;
					}
					ZEPHIR_INIT_NVAR(&_120$$98);
					ZVAL_LONG(&_120$$98, 2);
					zephir_array_update_string(&definition, SL("type"), &_120$$98, PH_COPY | PH_SEPARATE);
					break;
				} while(0);

				if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 429)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					zephir_array_fetch_string(&_121$$99, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 432);
					if (ZEPHIR_IS_LONG(&_121$$99, 18)) {
						ZVAL_LONG(&_123$$100, 5);
						ZVAL_LONG(&_124$$100, -1);
						ZEPHIR_INIT_NVAR(&_125$$100);
						zephir_substr(&_125$$100, &columnType, 5 , -1 , 0);
						zephir_array_update_string(&definition, SL("size"), &_125$$100, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(&_122$$99);
						zephir_preg_match(&_122$$99, &sizePattern, &columnType, &matches, 0, 0 , 0 );
						if (zephir_is_true(&_122$$99)) {
							ZEPHIR_OBS_NVAR(&matchOne);
							if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
								ZEPHIR_INIT_NVAR(&_126$$102);
								ZVAL_LONG(&_126$$102, zephir_get_intval(&matchOne));
								zephir_array_update_string(&definition, SL("size"), &_126$$102, PH_COPY | PH_SEPARATE);
							}
							ZEPHIR_OBS_NVAR(&matchTwo);
							if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
								ZEPHIR_INIT_NVAR(&_127$$103);
								ZVAL_LONG(&_127$$103, zephir_get_intval(&matchTwo));
								zephir_array_update_string(&definition, SL("scale"), &_127$$103, PH_COPY | PH_SEPARATE);
							}
						}
					}
				}
				if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 448)) {
					zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
				}
				if (Z_TYPE_P(&oldColumn) == IS_NULL) {
					zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_128$$62, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 464);
				if (ZEPHIR_IS_STRING(&_128$$62, "PRI")) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_129$$62, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 471);
				if (ZEPHIR_IS_STRING(&_129$$62, "YES")) {
					zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&extraValue);
				zephir_array_fetch_long(&extraValue, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 480);
				_130$$62 = Z_TYPE_P(&extraValue) != IS_NULL;
				if (_130$$62) {
					_130$$62 = zephir_memnstr_str(&extraValue, SL("INVISIBLE"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 481);
				}
				if (_130$$62) {
					zephir_array_update_string(&definition, SL("invisible"), &__$true, PH_COPY | PH_SEPARATE);
				}
				_131$$62 = Z_TYPE_P(&extraValue) != IS_NULL;
				if (_131$$62) {
					_132$$62 = zephir_memnstr_str(&extraValue, SL("VIRTUAL GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 499);
					if (!(_132$$62)) {
						_132$$62 = zephir_memnstr_str(&extraValue, SL("STORED GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 499);
					}
					_131$$62 = _132$$62;
				}
				if (_131$$62) {
					if (zephir_array_isset_value_long(&field, 9)) {
						ZEPHIR_OBS_NVAR(&generationExpression);
						zephir_array_fetch_long(&generationExpression, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 501);
					} else {
						ZEPHIR_INIT_NVAR(&generationExpression);
						ZVAL_STRING(&generationExpression, "");
					}
					zephir_array_update_string(&definition, SL("generated"), &generationExpression, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_133$$110);
					ZVAL_BOOL(&_133$$110, zephir_memnstr_str(&extraValue, SL("STORED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 507));
					zephir_array_update_string(&definition, SL("generationStored"), &_133$$110, PH_COPY | PH_SEPARATE);
				} else {
					if (ZEPHIR_IS_STRING(&extraValue, "auto_increment")) {
						zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
					}
					zephir_array_fetch_long(&_134$$113, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 527);
					_135$$113 = Z_TYPE_P(&_134$$113) != IS_NULL;
					if (_135$$113) {
						zephir_array_fetch_long(&_136$$113, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 527);
						_135$$113 = !ZEPHIR_IS_STRING_IDENTICAL(&_136$$113, "NULL");
					}
					if (_135$$113) {
						if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 528)) {
							zephir_array_fetch_long(&_137$$116, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 529);
							ZEPHIR_INIT_NVAR(&_138$$116);
							ZEPHIR_CONCAT_VSV(&_138$$116, &_137$$116, " ", &extraValue);
							zephir_array_update_string(&definition, SL("default"), &_138$$116, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_fetch_long(&_139$$117, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 531);
							zephir_array_update_string(&definition, SL("default"), &_139$$117, PH_COPY | PH_SEPARATE);
						}
					} else {
						if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 534)) {
							ZEPHIR_INIT_NVAR(&_140$$119);
							ZEPHIR_CONCAT_SV(&_140$$119, "NULL ", &extraValue);
							zephir_array_update_string(&definition, SL("default"), &_140$$119, PH_COPY | PH_SEPARATE);
						}
					}
				}
				zephir_array_fetch_long(&_141$$62, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 543);
				if (Z_TYPE_P(&_141$$62) != IS_NULL) {
					zephir_array_fetch_long(&_142$$120, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 544);
					zephir_array_update_string(&definition, SL("comment"), &_142$$120, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 550);
				ZEPHIR_INIT_NVAR(&_143$$62);
				object_init_ex(&_143$$62, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_143$$62, "__construct", &_72, 426, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_143$$62, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 551);
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
 *     $connection->describeIndexes("robots_parts")
 * );
 * ```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeIndexes)
{
	zval _53$$31;
	zval _14$$9, _35$$23;
	zend_ulong _46;
	zend_bool invisible = 0, anyDirection = 0, _25, _11$$3, _22$$3, _32$$17, _43$$17, _51$$31;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_56 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, __$true, indexes, index, keyName, indexType, indexObjects, columns, name, directions, collation, _0, _1, _2, _3, *_4, _24, *_45, _5$$4, _6$$3, _8$$3, _9$$3, _12$$3, _17$$3, _23$$3, _7$$6, _10$$8, _13$$9, _15$$10, _16$$11, _18$$12, _19$$13, _20$$14, _21$$15, _26$$18, _27$$17, _29$$17, _30$$17, _33$$17, _38$$17, _44$$17, _28$$20, _31$$22, _34$$23, _36$$24, _37$$25, _39$$26, _40$$27, _41$$28, _42$$29, _48$$32, *_49$$31, _50$$31, _52$$31, _54$$31, _55$$31;
	zend_string *table = NULL, *schema = NULL, *_47;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&indexObjects);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&directions);
	ZVAL_UNDEF(&collation);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_24);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_17$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_13$$9);
	ZVAL_UNDEF(&_15$$10);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_18$$12);
	ZVAL_UNDEF(&_19$$13);
	ZVAL_UNDEF(&_20$$14);
	ZVAL_UNDEF(&_21$$15);
	ZVAL_UNDEF(&_26$$18);
	ZVAL_UNDEF(&_27$$17);
	ZVAL_UNDEF(&_29$$17);
	ZVAL_UNDEF(&_30$$17);
	ZVAL_UNDEF(&_33$$17);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_28$$20);
	ZVAL_UNDEF(&_31$$22);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_36$$24);
	ZVAL_UNDEF(&_37$$25);
	ZVAL_UNDEF(&_39$$26);
	ZVAL_UNDEF(&_40$$27);
	ZVAL_UNDEF(&_41$$28);
	ZVAL_UNDEF(&_42$$29);
	ZVAL_UNDEF(&_48$$32);
	ZVAL_UNDEF(&_50$$31);
	ZVAL_UNDEF(&_52$$31);
	ZVAL_UNDEF(&_54$$31);
	ZVAL_UNDEF(&_55$$31);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_35$$23);
	ZVAL_UNDEF(&_53$$31);
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
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 637);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _4);
			zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 576);
			zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 577);
			if (!(zephir_array_isset_value(&indexes, &keyName))) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				array_init(&_5$$4);
				zephir_array_update_zval(&indexes, &keyName, &_5$$4, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch(&_6$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 583);
			if (!(zephir_array_isset_value_string(&_6$$3, SL("columns")))) {
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
			} else {
				zephir_array_fetch(&_7$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 586);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_7$$6, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 586);
			}
			zephir_array_fetch_string(&_8$$3, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 589);
			zephir_array_append(&columns, &_8$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 589);
			zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
			zephir_array_fetch(&_9$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 598);
			if (!(zephir_array_isset_value_string(&_9$$3, SL("directions")))) {
				ZEPHIR_INIT_NVAR(&directions);
				array_init(&directions);
			} else {
				zephir_array_fetch(&_10$$8, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 601);
				ZEPHIR_OBS_NVAR(&directions);
				zephir_array_fetch_string(&directions, &_10$$8, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 601);
			}
			ZEPHIR_INIT_NVAR(&collation);
			ZVAL_STRING(&collation, "");
			_11$$3 = zephir_array_isset_value_string(&index, SL("Collation"));
			if (_11$$3) {
				zephir_array_fetch_string(&_12$$3, &index, SL("Collation"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 605);
				_11$$3 = Z_TYPE_P(&_12$$3) != IS_NULL;
			}
			if (_11$$3) {
				ZEPHIR_OBS_NVAR(&_13$$9);
				zephir_array_fetch_string(&_13$$9, &index, SL("Collation"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 606);
				zephir_cast_to_string(&_14$$9, &_13$$9);
				ZEPHIR_CPY_WRT(&collation, &_14$$9);
			}
			if (ZEPHIR_IS_STRING(&collation, "D")) {
				ZEPHIR_INIT_NVAR(&_15$$10);
				ZVAL_STRING(&_15$$10, "DESC");
				zephir_array_append(&directions, &_15$$10, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 610);
			} else {
				ZEPHIR_INIT_NVAR(&_16$$11);
				ZVAL_STRING(&_16$$11, "ASC");
				zephir_array_append(&directions, &_16$$11, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 612);
			}
			zephir_array_update_multi(&indexes, &directions, SL("zs"), 3, &keyName, SL("directions"));
			if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
				ZEPHIR_INIT_NVAR(&_18$$12);
				ZVAL_STRING(&_18$$12, "PRIMARY");
				zephir_array_update_multi(&indexes, &_18$$12, SL("zs"), 3, &keyName, SL("type"));
			} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
				ZEPHIR_INIT_NVAR(&_19$$13);
				ZVAL_STRING(&_19$$13, "FULLTEXT");
				zephir_array_update_multi(&indexes, &_19$$13, SL("zs"), 3, &keyName, SL("type"));
			} else {
				zephir_array_fetch_string(&_17$$3, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 621);
				if (ZEPHIR_IS_LONG(&_17$$3, 0)) {
					ZEPHIR_INIT_NVAR(&_20$$14);
					ZVAL_STRING(&_20$$14, "UNIQUE");
					zephir_array_update_multi(&indexes, &_20$$14, SL("zs"), 3, &keyName, SL("type"));
				} else {
					ZEPHIR_INIT_NVAR(&_21$$15);
					ZVAL_STRING(&_21$$15, "");
					zephir_array_update_multi(&indexes, &_21$$15, SL("zs"), 3, &keyName, SL("type"));
				}
			}
			_22$$3 = zephir_array_isset_value_string(&index, SL("Visible"));
			if (_22$$3) {
				zephir_array_fetch_string(&_23$$3, &index, SL("Visible"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 632);
				_22$$3 = ZEPHIR_IS_STRING(&_23$$3, "NO");
			}
			if (_22$$3) {
				zephir_array_update_multi(&indexes, &__$true, SL("zs"), 3, &keyName, SL("invisible"));
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_25 = 1;
		while (1) {
			if (_25) {
				_25 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_24, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_24)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&keyName);
				zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 576);
				ZEPHIR_OBS_NVAR(&indexType);
				zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 577);
				if (!(zephir_array_isset_value(&indexes, &keyName))) {
					ZEPHIR_INIT_NVAR(&_26$$18);
					array_init(&_26$$18);
					zephir_array_update_zval(&indexes, &keyName, &_26$$18, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch(&_27$$17, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 583);
				if (!(zephir_array_isset_value_string(&_27$$17, SL("columns")))) {
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
				} else {
					zephir_array_fetch(&_28$$20, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 586);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_28$$20, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 586);
				}
				zephir_array_fetch_string(&_29$$17, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 589);
				zephir_array_append(&columns, &_29$$17, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 589);
				zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
				zephir_array_fetch(&_30$$17, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 598);
				if (!(zephir_array_isset_value_string(&_30$$17, SL("directions")))) {
					ZEPHIR_INIT_NVAR(&directions);
					array_init(&directions);
				} else {
					zephir_array_fetch(&_31$$22, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 601);
					ZEPHIR_OBS_NVAR(&directions);
					zephir_array_fetch_string(&directions, &_31$$22, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 601);
				}
				ZEPHIR_INIT_NVAR(&collation);
				ZVAL_STRING(&collation, "");
				_32$$17 = zephir_array_isset_value_string(&index, SL("Collation"));
				if (_32$$17) {
					zephir_array_fetch_string(&_33$$17, &index, SL("Collation"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 605);
					_32$$17 = Z_TYPE_P(&_33$$17) != IS_NULL;
				}
				if (_32$$17) {
					ZEPHIR_OBS_NVAR(&_34$$23);
					zephir_array_fetch_string(&_34$$23, &index, SL("Collation"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 606);
					zephir_cast_to_string(&_35$$23, &_34$$23);
					ZEPHIR_CPY_WRT(&collation, &_35$$23);
				}
				if (ZEPHIR_IS_STRING(&collation, "D")) {
					ZEPHIR_INIT_NVAR(&_36$$24);
					ZVAL_STRING(&_36$$24, "DESC");
					zephir_array_append(&directions, &_36$$24, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 610);
				} else {
					ZEPHIR_INIT_NVAR(&_37$$25);
					ZVAL_STRING(&_37$$25, "ASC");
					zephir_array_append(&directions, &_37$$25, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 612);
				}
				zephir_array_update_multi(&indexes, &directions, SL("zs"), 3, &keyName, SL("directions"));
				if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
					ZEPHIR_INIT_NVAR(&_39$$26);
					ZVAL_STRING(&_39$$26, "PRIMARY");
					zephir_array_update_multi(&indexes, &_39$$26, SL("zs"), 3, &keyName, SL("type"));
				} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
					ZEPHIR_INIT_NVAR(&_40$$27);
					ZVAL_STRING(&_40$$27, "FULLTEXT");
					zephir_array_update_multi(&indexes, &_40$$27, SL("zs"), 3, &keyName, SL("type"));
				} else {
					zephir_array_fetch_string(&_38$$17, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 621);
					if (ZEPHIR_IS_LONG(&_38$$17, 0)) {
						ZEPHIR_INIT_NVAR(&_41$$28);
						ZVAL_STRING(&_41$$28, "UNIQUE");
						zephir_array_update_multi(&indexes, &_41$$28, SL("zs"), 3, &keyName, SL("type"));
					} else {
						ZEPHIR_INIT_NVAR(&_42$$29);
						ZVAL_STRING(&_42$$29, "");
						zephir_array_update_multi(&indexes, &_42$$29, SL("zs"), 3, &keyName, SL("type"));
					}
				}
				_43$$17 = zephir_array_isset_value_string(&index, SL("Visible"));
				if (_43$$17) {
					zephir_array_fetch_string(&_44$$17, &index, SL("Visible"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 632);
					_43$$17 = ZEPHIR_IS_STRING(&_44$$17, "NO");
				}
				if (_43$$17) {
					zephir_array_update_multi(&indexes, &__$true, SL("zs"), 3, &keyName, SL("invisible"));
				}
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	zephir_is_iterable(&indexes, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 674);
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
		invisible = 0;
		if (zephir_array_isset_value_string(&index, SL("invisible"))) {
			ZEPHIR_OBS_NVAR(&_48$$32);
			zephir_array_fetch_string(&_48$$32, &index, SL("invisible"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 642);
			invisible = zephir_get_boolval(&_48$$32);
		}
		ZEPHIR_OBS_NVAR(&directions);
		zephir_array_fetch_string(&directions, &index, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 650);
		anyDirection = 0;
		zephir_is_iterable(&directions, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 659);
		if (Z_TYPE_P(&directions) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&directions), _49$$31)
			{
				ZEPHIR_INIT_NVAR(&collation);
				ZVAL_COPY(&collation, _49$$31);
				if (ZEPHIR_IS_STRING(&collation, "DESC")) {
					anyDirection = 1;
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, &directions, "rewind", NULL, 0);
			zephir_check_call_status();
			_51$$31 = 1;
			while (1) {
				if (_51$$31) {
					_51$$31 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, &directions, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_50$$31, &directions, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_50$$31)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&collation, &directions, "current", NULL, 0);
				zephir_check_call_status();
					if (ZEPHIR_IS_STRING(&collation, "DESC")) {
						anyDirection = 1;
						break;
					}
			}
		}
		ZEPHIR_INIT_NVAR(&collation);
		if (!(anyDirection)) {
			ZEPHIR_INIT_NVAR(&directions);
			array_init(&directions);
		}
		ZEPHIR_INIT_NVAR(&_52$$31);
		object_init_ex(&_52$$31, phalcon_db_index_ce);
		ZEPHIR_INIT_NVAR(&_53$$31);
		zephir_create_array(&_53$$31, 4, 0);
		ZEPHIR_OBS_NVAR(&_54$$31);
		zephir_array_fetch_string(&_54$$31, &index, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 666);
		zephir_array_update_string(&_53$$31, SL("columns"), &_54$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_54$$31);
		zephir_array_fetch_string(&_54$$31, &index, SL("type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 667);
		zephir_array_update_string(&_53$$31, SL("type"), &_54$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_55$$31);
		ZVAL_BOOL(&_55$$31, invisible);
		zephir_array_update_string(&_53$$31, SL("invisible"), &_55$$31, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_53$$31, SL("directions"), &directions, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_52$$31, "__construct", &_56, 63, &name, &_53$$31);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, &name, &_52$$31, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeReferences)
{
	zval _13$$3, _24$$6, _29$$9;
	zend_ulong _26;
	zend_bool _15;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, referenceUpdate, referenceDelete, _0, _1, _2, _3, *_4, _14, *_25, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$3, _12$$3, _16$$8, _17$$8, _18$$8, _19$$8, _20$$8, _21$$8, _22$$6, _23$$6, _28$$9, _30$$9;
	zend_string *table = NULL, *schema = NULL, *_27;
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
	ZVAL_UNDEF(&referenceUpdate);
	ZVAL_UNDEF(&referenceDelete);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$6);
	ZVAL_UNDEF(&_23$$6);
	ZVAL_UNDEF(&_28$$9);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_29$$9);
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
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 727);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _4);
			zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 696);
			if (!(zephir_array_isset_value(&references, &constraintName))) {
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 699);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 700);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 701);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 702);
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_5$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 706);
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_5$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 706);
				zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 707);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_6$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 707);
				zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 708);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_7$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 708);
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 709);
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_8$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 709);
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 710);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_string(&referenceUpdate, &_9$$5, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 710);
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 711);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_string(&referenceDelete, &_10$$5, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 711);
			}
			zephir_array_fetch_long(&_11$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 714);
			zephir_array_append(&columns, &_11$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 714);
			zephir_array_fetch_long(&_12$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 715);
			zephir_array_append(&referencedColumns, &_12$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 715);
			ZEPHIR_INIT_NVAR(&_13$$3);
			zephir_create_array(&_13$$3, 6, 0);
			zephir_array_update_string(&_13$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$3, SL("onUpdate"), &referenceUpdate, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_13$$3, SL("onDelete"), &referenceDelete, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&references, &constraintName, &_13$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &_0, "rewind", NULL, 0);
		zephir_check_call_status();
		_15 = 1;
		while (1) {
			if (_15) {
				_15 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_14, &_0, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_14)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&reference, &_0, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&constraintName);
				zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 696);
				if (!(zephir_array_isset_value(&references, &constraintName))) {
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 699);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 700);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 701);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 702);
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_16$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 706);
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_16$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 706);
					zephir_array_fetch(&_17$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 707);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_17$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 707);
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 708);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_18$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 708);
					zephir_array_fetch(&_19$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 709);
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_19$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 709);
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 710);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_string(&referenceUpdate, &_20$$8, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 710);
					zephir_array_fetch(&_21$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 711);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_string(&referenceDelete, &_21$$8, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 711);
				}
				zephir_array_fetch_long(&_22$$6, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 714);
				zephir_array_append(&columns, &_22$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 714);
				zephir_array_fetch_long(&_23$$6, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 715);
				zephir_array_append(&referencedColumns, &_23$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 715);
				ZEPHIR_INIT_NVAR(&_24$$6);
				zephir_create_array(&_24$$6, 6, 0);
				zephir_array_update_string(&_24$$6, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_24$$6, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_24$$6, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_24$$6, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_24$$6, SL("onUpdate"), &referenceUpdate, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_24$$6, SL("onDelete"), &referenceDelete, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&references, &constraintName, &_24$$6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&reference);
	ZEPHIR_INIT_VAR(&referenceObjects);
	array_init(&referenceObjects);
	zephir_is_iterable(&references, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 742);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&references), _26, _27, _25)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_27 != NULL) { 
			ZVAL_STR_COPY(&name, _27);
		} else {
			ZVAL_LONG(&name, _26);
		}
		ZEPHIR_INIT_NVAR(&arrayReference);
		ZVAL_COPY(&arrayReference, _25);
		ZEPHIR_INIT_NVAR(&_28$$9);
		object_init_ex(&_28$$9, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(&_29$$9);
		zephir_create_array(&_29$$9, 6, 0);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 732);
		zephir_array_update_string(&_29$$9, SL("referencedSchema"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 733);
		zephir_array_update_string(&_29$$9, SL("referencedTable"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 734);
		zephir_array_update_string(&_29$$9, SL("columns"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
		zephir_array_update_string(&_29$$9, SL("referencedColumns"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 736);
		zephir_array_update_string(&_29$$9, SL("onUpdate"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 738);
		zephir_array_update_string(&_29$$9, SL("onDelete"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_28$$9, "__construct", &_31, 64, &name, &_29$$9);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_28$$9, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&referenceObjects);
}

/**
 * Returns PDO adapter DSN defaults as a key-value map.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, getDsnDefaults)
{

	zephir_create_array(return_value, 1, 0);
	add_assoc_stringl_ex(return_value, SL("charset"), SL("utf8mb4"));
	return;
}

