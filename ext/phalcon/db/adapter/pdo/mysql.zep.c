
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
#include "kernel/string.h"
#include "kernel/array.h"
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 580, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getforeignkeychecks", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&foreignKeyCheck, this_ptr, "prepare", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, &foreignKeyCheck, "execute", NULL, 0);
	zephir_check_call_status();
	if (UNEXPECTED(!zephir_is_true(&_2))) {
		ZEPHIR_INIT_VAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_db_exceptions_missingforeignkeychecks_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 0);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$3, "phalcon/Db/Adapter/Pdo/Mysql.zep", 68);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 580, PH_NOISY_CC | PH_READONLY);
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
	zval columns, definition;
	zval sizePattern, _5;
	zend_bool isMariaDb, _78, _8$$3, _62$$3, _63$$3, _64$$3, _67$$54, _80$$63, _134$$63, _135$$63, _136$$63, _139$$114;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_70 = NULL, *_76 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, __$true, __$false, columnName, columnType, defaultValue, extraValue, field, fields, generationExpression, matchOne, matchTwo, matches, oldColumn, _0, _1, _2, _3, _4, *_6, _77, _7$$3, _60$$3, _61$$3, _73$$3, _75$$3, _9$$4, _10$$4, _11$$5, _12$$5, _13$$6, _14$$6, _15$$7, _16$$7, _17$$8, _18$$8, _19$$9, _20$$9, _21$$10, _22$$11, _23$$12, _24$$13, _25$$14, _26$$14, _27$$15, _28$$15, _29$$16, _30$$17, _31$$18, _32$$19, _33$$20, _34$$21, _35$$22, _36$$23, _37$$24, _38$$25, _39$$26, _40$$27, _41$$28, _42$$29, _43$$30, _44$$31, _45$$32, _46$$33, _47$$34, _48$$35, _49$$36, _50$$37, _51$$38, _52$$39, _53$$40, _54$$40, _55$$41, _56$$41, _57$$41, _58$$43, _59$$44, _65$$51, _66$$54, _68$$54, _69$$57, _71$$58, _72$$61, _74$$62, _79$$63, _132$$63, _133$$63, _144$$63, _146$$63, _81$$64, _82$$64, _83$$65, _84$$65, _85$$66, _86$$66, _87$$67, _88$$67, _89$$68, _90$$68, _91$$69, _92$$69, _93$$70, _94$$71, _95$$72, _96$$73, _97$$74, _98$$74, _99$$75, _100$$75, _101$$76, _102$$77, _103$$78, _104$$79, _105$$80, _106$$81, _107$$82, _108$$83, _109$$84, _110$$85, _111$$86, _112$$87, _113$$88, _114$$89, _115$$90, _116$$91, _117$$92, _118$$93, _119$$94, _120$$95, _121$$96, _122$$97, _123$$98, _124$$99, _125$$100, _126$$100, _127$$101, _128$$101, _129$$101, _130$$103, _131$$104, _137$$111, _138$$114, _140$$114, _141$$117, _142$$118, _143$$121, _145$$122;
	zend_string *table = NULL, *schema = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&defaultValue);
	ZVAL_UNDEF(&extraValue);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&generationExpression);
	ZVAL_UNDEF(&matchOne);
	ZVAL_UNDEF(&matchTwo);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&oldColumn);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_77);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_60$$3);
	ZVAL_UNDEF(&_61$$3);
	ZVAL_UNDEF(&_73$$3);
	ZVAL_UNDEF(&_75$$3);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_10$$4);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$6);
	ZVAL_UNDEF(&_14$$6);
	ZVAL_UNDEF(&_15$$7);
	ZVAL_UNDEF(&_16$$7);
	ZVAL_UNDEF(&_17$$8);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_23$$12);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
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
	ZVAL_UNDEF(&_45$$32);
	ZVAL_UNDEF(&_46$$33);
	ZVAL_UNDEF(&_47$$34);
	ZVAL_UNDEF(&_48$$35);
	ZVAL_UNDEF(&_49$$36);
	ZVAL_UNDEF(&_50$$37);
	ZVAL_UNDEF(&_51$$38);
	ZVAL_UNDEF(&_52$$39);
	ZVAL_UNDEF(&_53$$40);
	ZVAL_UNDEF(&_54$$40);
	ZVAL_UNDEF(&_55$$41);
	ZVAL_UNDEF(&_56$$41);
	ZVAL_UNDEF(&_57$$41);
	ZVAL_UNDEF(&_58$$43);
	ZVAL_UNDEF(&_59$$44);
	ZVAL_UNDEF(&_65$$51);
	ZVAL_UNDEF(&_66$$54);
	ZVAL_UNDEF(&_68$$54);
	ZVAL_UNDEF(&_69$$57);
	ZVAL_UNDEF(&_71$$58);
	ZVAL_UNDEF(&_72$$61);
	ZVAL_UNDEF(&_74$$62);
	ZVAL_UNDEF(&_79$$63);
	ZVAL_UNDEF(&_132$$63);
	ZVAL_UNDEF(&_133$$63);
	ZVAL_UNDEF(&_144$$63);
	ZVAL_UNDEF(&_146$$63);
	ZVAL_UNDEF(&_81$$64);
	ZVAL_UNDEF(&_82$$64);
	ZVAL_UNDEF(&_83$$65);
	ZVAL_UNDEF(&_84$$65);
	ZVAL_UNDEF(&_85$$66);
	ZVAL_UNDEF(&_86$$66);
	ZVAL_UNDEF(&_87$$67);
	ZVAL_UNDEF(&_88$$67);
	ZVAL_UNDEF(&_89$$68);
	ZVAL_UNDEF(&_90$$68);
	ZVAL_UNDEF(&_91$$69);
	ZVAL_UNDEF(&_92$$69);
	ZVAL_UNDEF(&_93$$70);
	ZVAL_UNDEF(&_94$$71);
	ZVAL_UNDEF(&_95$$72);
	ZVAL_UNDEF(&_96$$73);
	ZVAL_UNDEF(&_97$$74);
	ZVAL_UNDEF(&_98$$74);
	ZVAL_UNDEF(&_99$$75);
	ZVAL_UNDEF(&_100$$75);
	ZVAL_UNDEF(&_101$$76);
	ZVAL_UNDEF(&_102$$77);
	ZVAL_UNDEF(&_103$$78);
	ZVAL_UNDEF(&_104$$79);
	ZVAL_UNDEF(&_105$$80);
	ZVAL_UNDEF(&_106$$81);
	ZVAL_UNDEF(&_107$$82);
	ZVAL_UNDEF(&_108$$83);
	ZVAL_UNDEF(&_109$$84);
	ZVAL_UNDEF(&_110$$85);
	ZVAL_UNDEF(&_111$$86);
	ZVAL_UNDEF(&_112$$87);
	ZVAL_UNDEF(&_113$$88);
	ZVAL_UNDEF(&_114$$89);
	ZVAL_UNDEF(&_115$$90);
	ZVAL_UNDEF(&_116$$91);
	ZVAL_UNDEF(&_117$$92);
	ZVAL_UNDEF(&_118$$93);
	ZVAL_UNDEF(&_119$$94);
	ZVAL_UNDEF(&_120$$95);
	ZVAL_UNDEF(&_121$$96);
	ZVAL_UNDEF(&_122$$97);
	ZVAL_UNDEF(&_123$$98);
	ZVAL_UNDEF(&_124$$99);
	ZVAL_UNDEF(&_125$$100);
	ZVAL_UNDEF(&_126$$100);
	ZVAL_UNDEF(&_127$$101);
	ZVAL_UNDEF(&_128$$101);
	ZVAL_UNDEF(&_129$$101);
	ZVAL_UNDEF(&_130$$103);
	ZVAL_UNDEF(&_131$$104);
	ZVAL_UNDEF(&_137$$111);
	ZVAL_UNDEF(&_138$$114);
	ZVAL_UNDEF(&_140$$114);
	ZVAL_UNDEF(&_141$$117);
	ZVAL_UNDEF(&_142$$118);
	ZVAL_UNDEF(&_143$$121);
	ZVAL_UNDEF(&_145$$122);
	ZVAL_UNDEF(&sizePattern);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&definition);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("pdo", 3, 1);
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
	isMariaDb = 0;
	ZEPHIR_INIT_VAR(&sizePattern);
	ZVAL_STRING(&sizePattern, "#\\(([0-9]+)(?:,\\s*([0-9]+))*\\)#");
	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	ZEPHIR_INIT_VAR(&definition);
	array_init(&definition);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 580, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "describecolumns", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "fetchall", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 581, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, 4);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getattribute", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_cast_to_string(&_5, &_3);
	isMariaDb = zephir_memnstr_str(&_5, SL("MariaDB"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 114);
	zephir_is_iterable(&fields, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 583);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _6)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _6);
			ZEPHIR_INIT_NVAR(&_7$$3);
			zephir_create_array(&_7$$3, 1, 0);
			add_assoc_long_ex(&_7$$3, SL("bindType"), 2);
			ZEPHIR_CPY_WRT(&definition, &_7$$3);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 143);
			do {
				_8$$3 = 1;
				if (_8$$3 == zephir_start_with_str(&columnType, SL("bigint"))) {
					ZEPHIR_INIT_NVAR(&_9$$4);
					ZVAL_LONG(&_9$$4, 14);
					zephir_array_update_string(&definition, SL("type"), &_9$$4, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_10$$4);
					ZVAL_LONG(&_10$$4, 2);
					zephir_array_update_string(&definition, SL("bindType"), &_10$$4, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("mediumint"))) {
					ZEPHIR_INIT_NVAR(&_11$$5);
					ZVAL_LONG(&_11$$5, 21);
					zephir_array_update_string(&definition, SL("type"), &_11$$5, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_12$$5);
					ZVAL_LONG(&_12$$5, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_12$$5, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("smallint"))) {
					ZEPHIR_INIT_NVAR(&_13$$6);
					ZVAL_LONG(&_13$$6, 22);
					zephir_array_update_string(&definition, SL("type"), &_13$$6, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_14$$6);
					ZVAL_LONG(&_14$$6, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_14$$6, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("tinyint"))) {
					ZEPHIR_INIT_NVAR(&_15$$7);
					ZVAL_LONG(&_15$$7, 26);
					zephir_array_update_string(&definition, SL("type"), &_15$$7, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_16$$7);
					ZVAL_LONG(&_16$$7, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_16$$7, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("int"))) {
					ZEPHIR_INIT_NVAR(&_17$$8);
					ZVAL_LONG(&_17$$8, 0);
					zephir_array_update_string(&definition, SL("type"), &_17$$8, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_18$$8);
					ZVAL_LONG(&_18$$8, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_18$$8, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("bit"))) {
					ZEPHIR_INIT_NVAR(&_19$$9);
					ZVAL_LONG(&_19$$9, 19);
					zephir_array_update_string(&definition, SL("type"), &_19$$9, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_20$$9);
					ZVAL_LONG(&_20$$9, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_20$$9, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("enum"))) {
					ZEPHIR_INIT_NVAR(&_21$$10);
					ZVAL_LONG(&_21$$10, 18);
					zephir_array_update_string(&definition, SL("type"), &_21$$10, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("datetime"))) {
					ZEPHIR_INIT_NVAR(&_22$$11);
					ZVAL_LONG(&_22$$11, 4);
					zephir_array_update_string(&definition, SL("type"), &_22$$11, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("date"))) {
					ZEPHIR_INIT_NVAR(&_23$$12);
					ZVAL_LONG(&_23$$12, 1);
					zephir_array_update_string(&definition, SL("type"), &_23$$12, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("decimal"))) {
					ZEPHIR_INIT_NVAR(&_24$$13);
					ZVAL_LONG(&_24$$13, 3);
					zephir_array_update_string(&definition, SL("type"), &_24$$13, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("double"))) {
					ZEPHIR_INIT_NVAR(&_25$$14);
					ZVAL_LONG(&_25$$14, 9);
					zephir_array_update_string(&definition, SL("type"), &_25$$14, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_26$$14);
					ZVAL_LONG(&_26$$14, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_26$$14, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("float"))) {
					ZEPHIR_INIT_NVAR(&_27$$15);
					ZVAL_LONG(&_27$$15, 7);
					zephir_array_update_string(&definition, SL("type"), &_27$$15, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_28$$15);
					ZVAL_LONG(&_28$$15, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_28$$15, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("mediumblob"))) {
					ZEPHIR_INIT_NVAR(&_29$$16);
					ZVAL_LONG(&_29$$16, 12);
					zephir_array_update_string(&definition, SL("type"), &_29$$16, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("longblob"))) {
					ZEPHIR_INIT_NVAR(&_30$$17);
					ZVAL_LONG(&_30$$17, 13);
					zephir_array_update_string(&definition, SL("type"), &_30$$17, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("tinyblob"))) {
					ZEPHIR_INIT_NVAR(&_31$$18);
					ZVAL_LONG(&_31$$18, 10);
					zephir_array_update_string(&definition, SL("type"), &_31$$18, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("blob"))) {
					ZEPHIR_INIT_NVAR(&_32$$19);
					ZVAL_LONG(&_32$$19, 11);
					zephir_array_update_string(&definition, SL("type"), &_32$$19, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("timestamp"))) {
					ZEPHIR_INIT_NVAR(&_33$$20);
					ZVAL_LONG(&_33$$20, 17);
					zephir_array_update_string(&definition, SL("type"), &_33$$20, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("time"))) {
					ZEPHIR_INIT_NVAR(&_34$$21);
					ZVAL_LONG(&_34$$21, 20);
					zephir_array_update_string(&definition, SL("type"), &_34$$21, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("json"))) {
					ZEPHIR_INIT_NVAR(&_35$$22);
					ZVAL_LONG(&_35$$22, 15);
					zephir_array_update_string(&definition, SL("type"), &_35$$22, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("longtext"))) {
					ZEPHIR_INIT_NVAR(&_36$$23);
					ZVAL_LONG(&_36$$23, 24);
					zephir_array_update_string(&definition, SL("type"), &_36$$23, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("mediumtext"))) {
					ZEPHIR_INIT_NVAR(&_37$$24);
					ZVAL_LONG(&_37$$24, 23);
					zephir_array_update_string(&definition, SL("type"), &_37$$24, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("tinytext"))) {
					ZEPHIR_INIT_NVAR(&_38$$25);
					ZVAL_LONG(&_38$$25, 25);
					zephir_array_update_string(&definition, SL("type"), &_38$$25, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("text"))) {
					ZEPHIR_INIT_NVAR(&_39$$26);
					ZVAL_LONG(&_39$$26, 6);
					zephir_array_update_string(&definition, SL("type"), &_39$$26, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("varchar"))) {
					ZEPHIR_INIT_NVAR(&_40$$27);
					ZVAL_LONG(&_40$$27, 2);
					zephir_array_update_string(&definition, SL("type"), &_40$$27, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("char"))) {
					ZEPHIR_INIT_NVAR(&_41$$28);
					ZVAL_LONG(&_41$$28, 5);
					zephir_array_update_string(&definition, SL("type"), &_41$$28, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("varbinary"))) {
					ZEPHIR_INIT_NVAR(&_42$$29);
					ZVAL_LONG(&_42$$29, 28);
					zephir_array_update_string(&definition, SL("type"), &_42$$29, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("binary"))) {
					ZEPHIR_INIT_NVAR(&_43$$30);
					ZVAL_LONG(&_43$$30, 27);
					zephir_array_update_string(&definition, SL("type"), &_43$$30, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("multipoint"))) {
					ZEPHIR_INIT_NVAR(&_44$$31);
					ZVAL_LONG(&_44$$31, 44);
					zephir_array_update_string(&definition, SL("type"), &_44$$31, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("multilinestring"))) {
					ZEPHIR_INIT_NVAR(&_45$$32);
					ZVAL_LONG(&_45$$32, 45);
					zephir_array_update_string(&definition, SL("type"), &_45$$32, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("multipolygon"))) {
					ZEPHIR_INIT_NVAR(&_46$$33);
					ZVAL_LONG(&_46$$33, 46);
					zephir_array_update_string(&definition, SL("type"), &_46$$33, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("geometrycollection"))) {
					ZEPHIR_INIT_NVAR(&_47$$34);
					ZVAL_LONG(&_47$$34, 47);
					zephir_array_update_string(&definition, SL("type"), &_47$$34, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("linestring"))) {
					ZEPHIR_INIT_NVAR(&_48$$35);
					ZVAL_LONG(&_48$$35, 42);
					zephir_array_update_string(&definition, SL("type"), &_48$$35, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("polygon"))) {
					ZEPHIR_INIT_NVAR(&_49$$36);
					ZVAL_LONG(&_49$$36, 43);
					zephir_array_update_string(&definition, SL("type"), &_49$$36, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("point"))) {
					ZEPHIR_INIT_NVAR(&_50$$37);
					ZVAL_LONG(&_50$$37, 41);
					zephir_array_update_string(&definition, SL("type"), &_50$$37, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_8$$3 == zephir_start_with_str(&columnType, SL("geometry"))) {
					ZEPHIR_INIT_NVAR(&_51$$38);
					ZVAL_LONG(&_51$$38, 40);
					zephir_array_update_string(&definition, SL("type"), &_51$$38, PH_COPY | PH_SEPARATE);
					break;
				}
				ZEPHIR_INIT_NVAR(&_52$$39);
				ZVAL_LONG(&_52$$39, 2);
				zephir_array_update_string(&definition, SL("type"), &_52$$39, PH_COPY | PH_SEPARATE);
				break;
			} while(0);

			if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 451)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				zephir_array_fetch_string(&_53$$40, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 454);
				if (ZEPHIR_IS_LONG(&_53$$40, 18)) {
					ZVAL_LONG(&_55$$41, 5);
					ZVAL_LONG(&_56$$41, -1);
					ZEPHIR_INIT_NVAR(&_57$$41);
					zephir_substr(&_57$$41, &columnType, 5 , -1 , 0);
					zephir_array_update_string(&definition, SL("size"), &_57$$41, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_54$$40);
					zephir_preg_match(&_54$$40, &sizePattern, &columnType, &matches, 0, 0 , 0 );
					if (zephir_is_true(&_54$$40)) {
						ZEPHIR_OBS_NVAR(&matchOne);
						if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
							ZEPHIR_INIT_NVAR(&_58$$43);
							ZVAL_LONG(&_58$$43, zephir_get_intval(&matchOne));
							zephir_array_update_string(&definition, SL("size"), &_58$$43, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&matchTwo);
						if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
							ZEPHIR_INIT_NVAR(&_59$$44);
							ZVAL_LONG(&_59$$44, zephir_get_intval(&matchTwo));
							zephir_array_update_string(&definition, SL("scale"), &_59$$44, PH_COPY | PH_SEPARATE);
						}
					}
				}
			}
			if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 470)) {
				zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&oldColumn) == IS_NULL) {
				zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_60$$3, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 486);
			if (ZEPHIR_IS_STRING(&_60$$3, "PRI")) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_61$$3, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 493);
			if (ZEPHIR_IS_STRING(&_61$$3, "YES")) {
				zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_OBS_NVAR(&extraValue);
			zephir_array_fetch_long(&extraValue, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 502);
			_62$$3 = Z_TYPE_P(&extraValue) != IS_NULL;
			if (_62$$3) {
				_62$$3 = zephir_memnstr_str(&extraValue, SL("INVISIBLE"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 503);
			}
			if (_62$$3) {
				zephir_array_update_string(&definition, SL("invisible"), &__$true, PH_COPY | PH_SEPARATE);
			}
			_63$$3 = Z_TYPE_P(&extraValue) != IS_NULL;
			if (_63$$3) {
				_64$$3 = zephir_memnstr_str(&extraValue, SL("VIRTUAL GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 521);
				if (!(_64$$3)) {
					_64$$3 = zephir_memnstr_str(&extraValue, SL("STORED GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 521);
				}
				_63$$3 = _64$$3;
			}
			if (_63$$3) {
				if (zephir_array_isset_value_long(&field, 9)) {
					ZEPHIR_OBS_NVAR(&generationExpression);
					zephir_array_fetch_long(&generationExpression, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 523);
				} else {
					ZEPHIR_INIT_NVAR(&generationExpression);
					ZVAL_STRING(&generationExpression, "");
				}
				zephir_array_update_string(&definition, SL("generated"), &generationExpression, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_65$$51);
				ZVAL_BOOL(&_65$$51, zephir_memnstr_str(&extraValue, SL("STORED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 529));
				zephir_array_update_string(&definition, SL("generationStored"), &_65$$51, PH_COPY | PH_SEPARATE);
			} else {
				if (ZEPHIR_IS_STRING(&extraValue, "auto_increment")) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_66$$54, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 549);
				_67$$54 = Z_TYPE_P(&_66$$54) != IS_NULL;
				if (_67$$54) {
					zephir_array_fetch_long(&_68$$54, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 549);
					_67$$54 = !ZEPHIR_IS_STRING_IDENTICAL(&_68$$54, "NULL");
				}
				if (_67$$54) {
					ZEPHIR_OBS_NVAR(&defaultValue);
					zephir_array_fetch_long(&defaultValue, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 550);
					if (isMariaDb) {
						ZEPHIR_CALL_METHOD(&_69$$57, this_ptr, "unquotedefault", &_70, 0, &defaultValue);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&defaultValue, &_69$$57);
					}
					if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 556)) {
						ZEPHIR_INIT_NVAR(&_71$$58);
						ZEPHIR_CONCAT_VSV(&_71$$58, &defaultValue, " ", &extraValue);
						zephir_array_update_string(&definition, SL("default"), &_71$$58, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_string(&definition, SL("default"), &defaultValue, PH_COPY | PH_SEPARATE);
					}
				} else {
					if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 562)) {
						ZEPHIR_INIT_NVAR(&_72$$61);
						ZEPHIR_CONCAT_SV(&_72$$61, "NULL ", &extraValue);
						zephir_array_update_string(&definition, SL("default"), &_72$$61, PH_COPY | PH_SEPARATE);
					}
				}
			}
			zephir_array_fetch_long(&_73$$3, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 571);
			if (Z_TYPE_P(&_73$$3) != IS_NULL) {
				zephir_array_fetch_long(&_74$$62, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 572);
				zephir_array_update_string(&definition, SL("comment"), &_74$$62, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 578);
			ZEPHIR_INIT_NVAR(&_75$$3);
			object_init_ex(&_75$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_75$$3, "__construct", &_76, 0, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_75$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 579);
			ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
		zephir_check_call_status();
		_78 = 1;
		while (1) {
			if (_78) {
				_78 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_77, &fields, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_77)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_79$$63);
				zephir_create_array(&_79$$63, 1, 0);
				add_assoc_long_ex(&_79$$63, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_79$$63);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 143);
				do {
					_80$$63 = 1;
					if (_80$$63 == zephir_start_with_str(&columnType, SL("bigint"))) {
						ZEPHIR_INIT_NVAR(&_81$$64);
						ZVAL_LONG(&_81$$64, 14);
						zephir_array_update_string(&definition, SL("type"), &_81$$64, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_82$$64);
						ZVAL_LONG(&_82$$64, 2);
						zephir_array_update_string(&definition, SL("bindType"), &_82$$64, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("mediumint"))) {
						ZEPHIR_INIT_NVAR(&_83$$65);
						ZVAL_LONG(&_83$$65, 21);
						zephir_array_update_string(&definition, SL("type"), &_83$$65, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_84$$65);
						ZVAL_LONG(&_84$$65, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_84$$65, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("smallint"))) {
						ZEPHIR_INIT_NVAR(&_85$$66);
						ZVAL_LONG(&_85$$66, 22);
						zephir_array_update_string(&definition, SL("type"), &_85$$66, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_86$$66);
						ZVAL_LONG(&_86$$66, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_86$$66, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("tinyint"))) {
						ZEPHIR_INIT_NVAR(&_87$$67);
						ZVAL_LONG(&_87$$67, 26);
						zephir_array_update_string(&definition, SL("type"), &_87$$67, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_88$$67);
						ZVAL_LONG(&_88$$67, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_88$$67, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("int"))) {
						ZEPHIR_INIT_NVAR(&_89$$68);
						ZVAL_LONG(&_89$$68, 0);
						zephir_array_update_string(&definition, SL("type"), &_89$$68, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_90$$68);
						ZVAL_LONG(&_90$$68, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_90$$68, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("bit"))) {
						ZEPHIR_INIT_NVAR(&_91$$69);
						ZVAL_LONG(&_91$$69, 19);
						zephir_array_update_string(&definition, SL("type"), &_91$$69, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_92$$69);
						ZVAL_LONG(&_92$$69, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_92$$69, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("enum"))) {
						ZEPHIR_INIT_NVAR(&_93$$70);
						ZVAL_LONG(&_93$$70, 18);
						zephir_array_update_string(&definition, SL("type"), &_93$$70, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("datetime"))) {
						ZEPHIR_INIT_NVAR(&_94$$71);
						ZVAL_LONG(&_94$$71, 4);
						zephir_array_update_string(&definition, SL("type"), &_94$$71, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("date"))) {
						ZEPHIR_INIT_NVAR(&_95$$72);
						ZVAL_LONG(&_95$$72, 1);
						zephir_array_update_string(&definition, SL("type"), &_95$$72, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("decimal"))) {
						ZEPHIR_INIT_NVAR(&_96$$73);
						ZVAL_LONG(&_96$$73, 3);
						zephir_array_update_string(&definition, SL("type"), &_96$$73, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("double"))) {
						ZEPHIR_INIT_NVAR(&_97$$74);
						ZVAL_LONG(&_97$$74, 9);
						zephir_array_update_string(&definition, SL("type"), &_97$$74, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_98$$74);
						ZVAL_LONG(&_98$$74, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_98$$74, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("float"))) {
						ZEPHIR_INIT_NVAR(&_99$$75);
						ZVAL_LONG(&_99$$75, 7);
						zephir_array_update_string(&definition, SL("type"), &_99$$75, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_100$$75);
						ZVAL_LONG(&_100$$75, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_100$$75, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("mediumblob"))) {
						ZEPHIR_INIT_NVAR(&_101$$76);
						ZVAL_LONG(&_101$$76, 12);
						zephir_array_update_string(&definition, SL("type"), &_101$$76, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("longblob"))) {
						ZEPHIR_INIT_NVAR(&_102$$77);
						ZVAL_LONG(&_102$$77, 13);
						zephir_array_update_string(&definition, SL("type"), &_102$$77, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("tinyblob"))) {
						ZEPHIR_INIT_NVAR(&_103$$78);
						ZVAL_LONG(&_103$$78, 10);
						zephir_array_update_string(&definition, SL("type"), &_103$$78, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("blob"))) {
						ZEPHIR_INIT_NVAR(&_104$$79);
						ZVAL_LONG(&_104$$79, 11);
						zephir_array_update_string(&definition, SL("type"), &_104$$79, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("timestamp"))) {
						ZEPHIR_INIT_NVAR(&_105$$80);
						ZVAL_LONG(&_105$$80, 17);
						zephir_array_update_string(&definition, SL("type"), &_105$$80, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("time"))) {
						ZEPHIR_INIT_NVAR(&_106$$81);
						ZVAL_LONG(&_106$$81, 20);
						zephir_array_update_string(&definition, SL("type"), &_106$$81, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("json"))) {
						ZEPHIR_INIT_NVAR(&_107$$82);
						ZVAL_LONG(&_107$$82, 15);
						zephir_array_update_string(&definition, SL("type"), &_107$$82, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("longtext"))) {
						ZEPHIR_INIT_NVAR(&_108$$83);
						ZVAL_LONG(&_108$$83, 24);
						zephir_array_update_string(&definition, SL("type"), &_108$$83, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("mediumtext"))) {
						ZEPHIR_INIT_NVAR(&_109$$84);
						ZVAL_LONG(&_109$$84, 23);
						zephir_array_update_string(&definition, SL("type"), &_109$$84, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("tinytext"))) {
						ZEPHIR_INIT_NVAR(&_110$$85);
						ZVAL_LONG(&_110$$85, 25);
						zephir_array_update_string(&definition, SL("type"), &_110$$85, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("text"))) {
						ZEPHIR_INIT_NVAR(&_111$$86);
						ZVAL_LONG(&_111$$86, 6);
						zephir_array_update_string(&definition, SL("type"), &_111$$86, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("varchar"))) {
						ZEPHIR_INIT_NVAR(&_112$$87);
						ZVAL_LONG(&_112$$87, 2);
						zephir_array_update_string(&definition, SL("type"), &_112$$87, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("char"))) {
						ZEPHIR_INIT_NVAR(&_113$$88);
						ZVAL_LONG(&_113$$88, 5);
						zephir_array_update_string(&definition, SL("type"), &_113$$88, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("varbinary"))) {
						ZEPHIR_INIT_NVAR(&_114$$89);
						ZVAL_LONG(&_114$$89, 28);
						zephir_array_update_string(&definition, SL("type"), &_114$$89, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("binary"))) {
						ZEPHIR_INIT_NVAR(&_115$$90);
						ZVAL_LONG(&_115$$90, 27);
						zephir_array_update_string(&definition, SL("type"), &_115$$90, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("multipoint"))) {
						ZEPHIR_INIT_NVAR(&_116$$91);
						ZVAL_LONG(&_116$$91, 44);
						zephir_array_update_string(&definition, SL("type"), &_116$$91, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("multilinestring"))) {
						ZEPHIR_INIT_NVAR(&_117$$92);
						ZVAL_LONG(&_117$$92, 45);
						zephir_array_update_string(&definition, SL("type"), &_117$$92, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("multipolygon"))) {
						ZEPHIR_INIT_NVAR(&_118$$93);
						ZVAL_LONG(&_118$$93, 46);
						zephir_array_update_string(&definition, SL("type"), &_118$$93, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("geometrycollection"))) {
						ZEPHIR_INIT_NVAR(&_119$$94);
						ZVAL_LONG(&_119$$94, 47);
						zephir_array_update_string(&definition, SL("type"), &_119$$94, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("linestring"))) {
						ZEPHIR_INIT_NVAR(&_120$$95);
						ZVAL_LONG(&_120$$95, 42);
						zephir_array_update_string(&definition, SL("type"), &_120$$95, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("polygon"))) {
						ZEPHIR_INIT_NVAR(&_121$$96);
						ZVAL_LONG(&_121$$96, 43);
						zephir_array_update_string(&definition, SL("type"), &_121$$96, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("point"))) {
						ZEPHIR_INIT_NVAR(&_122$$97);
						ZVAL_LONG(&_122$$97, 41);
						zephir_array_update_string(&definition, SL("type"), &_122$$97, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_80$$63 == zephir_start_with_str(&columnType, SL("geometry"))) {
						ZEPHIR_INIT_NVAR(&_123$$98);
						ZVAL_LONG(&_123$$98, 40);
						zephir_array_update_string(&definition, SL("type"), &_123$$98, PH_COPY | PH_SEPARATE);
						break;
					}
					ZEPHIR_INIT_NVAR(&_124$$99);
					ZVAL_LONG(&_124$$99, 2);
					zephir_array_update_string(&definition, SL("type"), &_124$$99, PH_COPY | PH_SEPARATE);
					break;
				} while(0);

				if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 451)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					zephir_array_fetch_string(&_125$$100, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 454);
					if (ZEPHIR_IS_LONG(&_125$$100, 18)) {
						ZVAL_LONG(&_127$$101, 5);
						ZVAL_LONG(&_128$$101, -1);
						ZEPHIR_INIT_NVAR(&_129$$101);
						zephir_substr(&_129$$101, &columnType, 5 , -1 , 0);
						zephir_array_update_string(&definition, SL("size"), &_129$$101, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(&_126$$100);
						zephir_preg_match(&_126$$100, &sizePattern, &columnType, &matches, 0, 0 , 0 );
						if (zephir_is_true(&_126$$100)) {
							ZEPHIR_OBS_NVAR(&matchOne);
							if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
								ZEPHIR_INIT_NVAR(&_130$$103);
								ZVAL_LONG(&_130$$103, zephir_get_intval(&matchOne));
								zephir_array_update_string(&definition, SL("size"), &_130$$103, PH_COPY | PH_SEPARATE);
							}
							ZEPHIR_OBS_NVAR(&matchTwo);
							if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
								ZEPHIR_INIT_NVAR(&_131$$104);
								ZVAL_LONG(&_131$$104, zephir_get_intval(&matchTwo));
								zephir_array_update_string(&definition, SL("scale"), &_131$$104, PH_COPY | PH_SEPARATE);
							}
						}
					}
				}
				if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 470)) {
					zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
				}
				if (Z_TYPE_P(&oldColumn) == IS_NULL) {
					zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_132$$63, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 486);
				if (ZEPHIR_IS_STRING(&_132$$63, "PRI")) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_133$$63, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 493);
				if (ZEPHIR_IS_STRING(&_133$$63, "YES")) {
					zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&extraValue);
				zephir_array_fetch_long(&extraValue, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 502);
				_134$$63 = Z_TYPE_P(&extraValue) != IS_NULL;
				if (_134$$63) {
					_134$$63 = zephir_memnstr_str(&extraValue, SL("INVISIBLE"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 503);
				}
				if (_134$$63) {
					zephir_array_update_string(&definition, SL("invisible"), &__$true, PH_COPY | PH_SEPARATE);
				}
				_135$$63 = Z_TYPE_P(&extraValue) != IS_NULL;
				if (_135$$63) {
					_136$$63 = zephir_memnstr_str(&extraValue, SL("VIRTUAL GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 521);
					if (!(_136$$63)) {
						_136$$63 = zephir_memnstr_str(&extraValue, SL("STORED GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 521);
					}
					_135$$63 = _136$$63;
				}
				if (_135$$63) {
					if (zephir_array_isset_value_long(&field, 9)) {
						ZEPHIR_OBS_NVAR(&generationExpression);
						zephir_array_fetch_long(&generationExpression, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 523);
					} else {
						ZEPHIR_INIT_NVAR(&generationExpression);
						ZVAL_STRING(&generationExpression, "");
					}
					zephir_array_update_string(&definition, SL("generated"), &generationExpression, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_137$$111);
					ZVAL_BOOL(&_137$$111, zephir_memnstr_str(&extraValue, SL("STORED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 529));
					zephir_array_update_string(&definition, SL("generationStored"), &_137$$111, PH_COPY | PH_SEPARATE);
				} else {
					if (ZEPHIR_IS_STRING(&extraValue, "auto_increment")) {
						zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
					}
					zephir_array_fetch_long(&_138$$114, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 549);
					_139$$114 = Z_TYPE_P(&_138$$114) != IS_NULL;
					if (_139$$114) {
						zephir_array_fetch_long(&_140$$114, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 549);
						_139$$114 = !ZEPHIR_IS_STRING_IDENTICAL(&_140$$114, "NULL");
					}
					if (_139$$114) {
						ZEPHIR_OBS_NVAR(&defaultValue);
						zephir_array_fetch_long(&defaultValue, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 550);
						if (isMariaDb) {
							ZEPHIR_CALL_METHOD(&_141$$117, this_ptr, "unquotedefault", &_70, 0, &defaultValue);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&defaultValue, &_141$$117);
						}
						if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 556)) {
							ZEPHIR_INIT_NVAR(&_142$$118);
							ZEPHIR_CONCAT_VSV(&_142$$118, &defaultValue, " ", &extraValue);
							zephir_array_update_string(&definition, SL("default"), &_142$$118, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_update_string(&definition, SL("default"), &defaultValue, PH_COPY | PH_SEPARATE);
						}
					} else {
						if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 562)) {
							ZEPHIR_INIT_NVAR(&_143$$121);
							ZEPHIR_CONCAT_SV(&_143$$121, "NULL ", &extraValue);
							zephir_array_update_string(&definition, SL("default"), &_143$$121, PH_COPY | PH_SEPARATE);
						}
					}
				}
				zephir_array_fetch_long(&_144$$63, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 571);
				if (Z_TYPE_P(&_144$$63) != IS_NULL) {
					zephir_array_fetch_long(&_145$$122, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 572);
					zephir_array_update_string(&definition, SL("comment"), &_145$$122, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 578);
				ZEPHIR_INIT_NVAR(&_146$$63);
				object_init_ex(&_146$$63, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_146$$63, "__construct", &_76, 0, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_146$$63, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 579);
				ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	RETURN_CTOR(&columns);
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeIndexes)
{
	zval _14$$9, _35$$23;
	zend_ulong _46;
	zval indexes, indexObjects, _53$$31;
	zend_bool invisible = 0, anyDirection = 0, _25, _11$$3, _22$$3, _32$$17, _43$$17, _51$$31;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_56 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, __$true, columns, index, keyName, indexType, name, directions, collation, _0, _1, _2, _3, *_4, _24, *_45, _5$$4, _6$$3, _8$$3, _9$$3, _12$$3, _17$$3, _23$$3, _7$$6, _10$$8, _13$$9, _15$$10, _16$$11, _18$$12, _19$$13, _20$$14, _21$$15, _26$$18, _27$$17, _29$$17, _30$$17, _33$$17, _38$$17, _44$$17, _28$$20, _31$$22, _34$$23, _36$$24, _37$$25, _39$$26, _40$$27, _41$$28, _42$$29, _48$$32, *_49$$31, _50$$31, _52$$31, _54$$31, _55$$31;
	zend_string *table = NULL, *schema = NULL, *_47;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&indexType);
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
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&indexObjects);
	ZVAL_UNDEF(&_53$$31);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_35$$23);
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
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 580, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeindexes", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 664);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _4);
			zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 603);
			zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 604);
			if (!(zephir_array_isset_value(&indexes, &keyName))) {
				ZEPHIR_INIT_NVAR(&_5$$4);
				array_init(&_5$$4);
				zephir_array_update_zval(&indexes, &keyName, &_5$$4, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch(&_6$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 610);
			if (!(zephir_array_isset_value_string(&_6$$3, SL("columns")))) {
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
			} else {
				zephir_array_fetch(&_7$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 613);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_7$$6, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 613);
			}
			zephir_array_fetch_string(&_8$$3, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 616);
			zephir_array_append(&columns, &_8$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 616);
			zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
			zephir_array_fetch(&_9$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 625);
			if (!(zephir_array_isset_value_string(&_9$$3, SL("directions")))) {
				ZEPHIR_INIT_NVAR(&directions);
				array_init(&directions);
			} else {
				zephir_array_fetch(&_10$$8, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 628);
				ZEPHIR_OBS_NVAR(&directions);
				zephir_array_fetch_string(&directions, &_10$$8, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 628);
			}
			ZEPHIR_INIT_NVAR(&collation);
			ZVAL_STRING(&collation, "");
			_11$$3 = zephir_array_isset_value_string(&index, SL("Collation"));
			if (_11$$3) {
				zephir_array_fetch_string(&_12$$3, &index, SL("Collation"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 632);
				_11$$3 = Z_TYPE_P(&_12$$3) != IS_NULL;
			}
			if (_11$$3) {
				ZEPHIR_OBS_NVAR(&_13$$9);
				zephir_array_fetch_string(&_13$$9, &index, SL("Collation"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 633);
				zephir_cast_to_string(&_14$$9, &_13$$9);
				ZEPHIR_CPY_WRT(&collation, &_14$$9);
			}
			if (ZEPHIR_IS_STRING(&collation, "D")) {
				ZEPHIR_INIT_NVAR(&_15$$10);
				ZVAL_STRING(&_15$$10, "DESC");
				zephir_array_append(&directions, &_15$$10, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 637);
			} else {
				ZEPHIR_INIT_NVAR(&_16$$11);
				ZVAL_STRING(&_16$$11, "ASC");
				zephir_array_append(&directions, &_16$$11, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 639);
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
				zephir_array_fetch_string(&_17$$3, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 648);
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
				zephir_array_fetch_string(&_23$$3, &index, SL("Visible"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 659);
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
				zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 603);
				ZEPHIR_OBS_NVAR(&indexType);
				zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 604);
				if (!(zephir_array_isset_value(&indexes, &keyName))) {
					ZEPHIR_INIT_NVAR(&_26$$18);
					array_init(&_26$$18);
					zephir_array_update_zval(&indexes, &keyName, &_26$$18, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch(&_27$$17, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 610);
				if (!(zephir_array_isset_value_string(&_27$$17, SL("columns")))) {
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
				} else {
					zephir_array_fetch(&_28$$20, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 613);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_28$$20, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 613);
				}
				zephir_array_fetch_string(&_29$$17, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 616);
				zephir_array_append(&columns, &_29$$17, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 616);
				zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
				zephir_array_fetch(&_30$$17, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 625);
				if (!(zephir_array_isset_value_string(&_30$$17, SL("directions")))) {
					ZEPHIR_INIT_NVAR(&directions);
					array_init(&directions);
				} else {
					zephir_array_fetch(&_31$$22, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 628);
					ZEPHIR_OBS_NVAR(&directions);
					zephir_array_fetch_string(&directions, &_31$$22, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 628);
				}
				ZEPHIR_INIT_NVAR(&collation);
				ZVAL_STRING(&collation, "");
				_32$$17 = zephir_array_isset_value_string(&index, SL("Collation"));
				if (_32$$17) {
					zephir_array_fetch_string(&_33$$17, &index, SL("Collation"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 632);
					_32$$17 = Z_TYPE_P(&_33$$17) != IS_NULL;
				}
				if (_32$$17) {
					ZEPHIR_OBS_NVAR(&_34$$23);
					zephir_array_fetch_string(&_34$$23, &index, SL("Collation"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 633);
					zephir_cast_to_string(&_35$$23, &_34$$23);
					ZEPHIR_CPY_WRT(&collation, &_35$$23);
				}
				if (ZEPHIR_IS_STRING(&collation, "D")) {
					ZEPHIR_INIT_NVAR(&_36$$24);
					ZVAL_STRING(&_36$$24, "DESC");
					zephir_array_append(&directions, &_36$$24, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 637);
				} else {
					ZEPHIR_INIT_NVAR(&_37$$25);
					ZVAL_STRING(&_37$$25, "ASC");
					zephir_array_append(&directions, &_37$$25, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 639);
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
					zephir_array_fetch_string(&_38$$17, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 648);
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
					zephir_array_fetch_string(&_44$$17, &index, SL("Visible"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 659);
					_43$$17 = ZEPHIR_IS_STRING(&_44$$17, "NO");
				}
				if (_43$$17) {
					zephir_array_update_multi(&indexes, &__$true, SL("zs"), 3, &keyName, SL("invisible"));
				}
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	zephir_is_iterable(&indexes, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 699);
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
			zephir_array_fetch_string(&_48$$32, &index, SL("invisible"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 667);
			invisible = zephir_get_boolval(&_48$$32);
		}
		ZEPHIR_OBS_NVAR(&directions);
		zephir_array_fetch_string(&directions, &index, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 675);
		anyDirection = 0;
		zephir_is_iterable(&directions, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 684);
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
		zephir_array_fetch_string(&_54$$31, &index, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 691);
		zephir_array_update_string(&_53$$31, SL("columns"), &_54$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_54$$31);
		zephir_array_fetch_string(&_54$$31, &index, SL("type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 692);
		zephir_array_update_string(&_53$$31, SL("type"), &_54$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_55$$31);
		ZVAL_BOOL(&_55$$31, invisible);
		zephir_array_update_string(&_53$$31, SL("invisible"), &_55$$31, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_53$$31, SL("directions"), &directions, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_52$$31, "__construct", &_56, 62, &name, &_53$$31);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, &name, &_52$$31, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CTOR(&indexObjects);
}

/**
 * Lists table references
 *
 *```php
 * print_r(
 *     $connection->describeReferences("co_orders_x_products")
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeReferences)
{
	zend_ulong _26;
	zend_bool _15;
	zval references, referenceObjects, _13$$3, _24$$6, _29$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, arrayReference, columns, constraintName, name, reference, referenceDelete, referenceUpdate, referencedColumns, referencedSchema, referencedTable, _0, _1, _2, _3, *_4, _14, *_25, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$3, _12$$3, _16$$8, _17$$8, _18$$8, _19$$8, _20$$8, _21$$8, _22$$6, _23$$6, _28$$9, _30$$9;
	zend_string *table = NULL, *schema = NULL, *_27;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_UNDEF(&arrayReference);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&constraintName);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&reference);
	ZVAL_UNDEF(&referenceDelete);
	ZVAL_UNDEF(&referenceUpdate);
	ZVAL_UNDEF(&referencedColumns);
	ZVAL_UNDEF(&referencedSchema);
	ZVAL_UNDEF(&referencedTable);
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
	ZVAL_UNDEF(&references);
	ZVAL_UNDEF(&referenceObjects);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_29$$9);
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
	ZEPHIR_INIT_VAR(&referenceObjects);
	array_init(&referenceObjects);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 580, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describereferences", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 752);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _4);
			zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 721);
			if (!(zephir_array_isset_value(&references, &constraintName))) {
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 724);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 725);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 726);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 727);
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_5$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_5$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
				zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 732);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_6$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 732);
				zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 733);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_7$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 733);
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 734);
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_8$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 734);
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_string(&referenceUpdate, &_9$$5, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 736);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_string(&referenceDelete, &_10$$5, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 736);
			}
			zephir_array_fetch_long(&_11$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 739);
			zephir_array_append(&columns, &_11$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 739);
			zephir_array_fetch_long(&_12$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 740);
			zephir_array_append(&referencedColumns, &_12$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 740);
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
				zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 721);
				if (!(zephir_array_isset_value(&references, &constraintName))) {
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 724);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 725);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 726);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 727);
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_16$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_16$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
					zephir_array_fetch(&_17$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 732);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_17$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 732);
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 733);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_18$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 733);
					zephir_array_fetch(&_19$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 734);
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_19$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 734);
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_string(&referenceUpdate, &_20$$8, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
					zephir_array_fetch(&_21$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 736);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_string(&referenceDelete, &_21$$8, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 736);
				}
				zephir_array_fetch_long(&_22$$6, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 739);
				zephir_array_append(&columns, &_22$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 739);
				zephir_array_fetch_long(&_23$$6, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 740);
				zephir_array_append(&referencedColumns, &_23$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 740);
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
	zephir_is_iterable(&references, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 766);
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
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 756);
		zephir_array_update_string(&_29$$9, SL("referencedSchema"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 757);
		zephir_array_update_string(&_29$$9, SL("referencedTable"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 758);
		zephir_array_update_string(&_29$$9, SL("columns"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 759);
		zephir_array_update_string(&_29$$9, SL("referencedColumns"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 760);
		zephir_array_update_string(&_29$$9, SL("onUpdate"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 762);
		zephir_array_update_string(&_29$$9, SL("onDelete"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_28$$9, "__construct", &_31, 63, &name, &_29$$9);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_28$$9, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CTOR(&referenceObjects);
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

/**
 * Recognizes a MySQL "server has gone away" / "Lost connection" failure
 * by the driver error code (2006 / 2013) with a message fallback.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, isConnectionError)
{
	zend_bool _1, _4, _3$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, driverCode = 0;
	zval *exception, exception_sub, errorInfo, message, _0, _2$$3;

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&errorInfo);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("errorInfo", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &exception);
	zephir_read_property_cached(&_0, exception, _zephir_prop_0, 0, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CPY_WRT(&errorInfo, &_0);
	_1 = Z_TYPE_P(&errorInfo) == IS_ARRAY;
	if (_1) {
		_1 = zephir_array_isset_value_long(&errorInfo, 1);
	}
	if (_1) {
		zephir_memory_observe(&_2$$3);
		zephir_array_fetch_long(&_2$$3, &errorInfo, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 790);
		driverCode = zephir_get_intval(&_2$$3);
		_3$$3 = driverCode == 2006;
		if (!(_3$$3)) {
			_3$$3 = driverCode == 2013;
		}
		if (_3$$3) {
			RETURN_MM_BOOL(1);
		}
	}
	ZEPHIR_CALL_METHOD(&message, exception, "getmessage", NULL, 0);
	zephir_check_call_status();
	_4 = zephir_memnstr_str(&message, SL("server has gone away"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 799);
	if (!(_4)) {
		_4 = zephir_memnstr_str(&message, SL("Lost connection"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 800);
	}
	RETURN_MM_BOOL(_4);
}

/**
 * Resolves a MariaDB `COLUMN_DEFAULT` literal to the value it represents.
 *
 * MariaDB quotes literal defaults to tell them apart from the expression
 * defaults it has supported since 10.2. Expression defaults arrive
 * unquoted, so an unmatched pair leaves the value untouched.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, unquoteDefault)
{
	zend_bool _0, _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval value_zv, _1, _2, _3, _5, _6, _7, _8, _9, _10, _11, _12;
	zend_string *value = NULL;

	ZVAL_UNDEF(&value_zv);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(value)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&value_zv);
	ZVAL_STR_COPY(&value_zv, value);
	_0 = zephir_fast_strlen_ev(&value_zv) < 2;
	if (!(_0)) {
		ZVAL_LONG(&_1, 0);
		ZVAL_LONG(&_2, 1);
		ZEPHIR_INIT_VAR(&_3);
		zephir_substr(&_3, &value_zv, 0 , 1 , 0);
		_0 = !ZEPHIR_IS_STRING_IDENTICAL(&_3, "'");
	}
	_4 = _0;
	if (!(_4)) {
		ZVAL_LONG(&_5, -1);
		ZEPHIR_INIT_VAR(&_6);
		zephir_substr(&_6, &value_zv, -1 , 0, ZEPHIR_SUBSTR_NO_LENGTH);
		_4 = !ZEPHIR_IS_STRING_IDENTICAL(&_6, "'");
	}
	if (_4) {
		RETURN_MM_STR(zend_string_copy(value));
	}
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_LONG(&_8, 1);
	ZVAL_LONG(&_9, -1);
	ZEPHIR_INIT_VAR(&_10);
	zephir_substr(&_10, &value_zv, 1 , -1 , 0);
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_STRING(&_11, "''");
	ZEPHIR_INIT_VAR(&_12);
	ZVAL_STRING(&_12, "'");
	zephir_fast_str_replace(&_7, &_11, &_12, &_10);
	zephir_stripcslashes(return_value, &_7);
	RETURN_MM();
}

