
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 593, PH_NOISY_CC | PH_READONLY);
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
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 593, PH_NOISY_CC | PH_READONLY);
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
	zend_bool isMariaDb, _80, _10$$3, _64$$3, _65$$3, _66$$3, _69$$54, _82$$63, _136$$63, _137$$63, _138$$63, _141$$114;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_72 = NULL, *_78 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, __$true, __$false, columnName, columnType, defaultValue, extraValue, field, fields, generationExpression, matchOne, matchTwo, matches, oldColumn, _0, _1, _2, _3, _4, *_6, _7, *_8, _79, _9$$3, _62$$3, _63$$3, _75$$3, _77$$3, _11$$4, _12$$4, _13$$5, _14$$5, _15$$6, _16$$6, _17$$7, _18$$7, _19$$8, _20$$8, _21$$9, _22$$9, _23$$10, _24$$11, _25$$12, _26$$13, _27$$14, _28$$14, _29$$15, _30$$15, _31$$16, _32$$17, _33$$18, _34$$19, _35$$20, _36$$21, _37$$22, _38$$23, _39$$24, _40$$25, _41$$26, _42$$27, _43$$28, _44$$29, _45$$30, _46$$31, _47$$32, _48$$33, _49$$34, _50$$35, _51$$36, _52$$37, _53$$38, _54$$39, _55$$40, _56$$40, _57$$41, _58$$41, _59$$41, _60$$43, _61$$44, _67$$51, _68$$54, _70$$54, _71$$57, _73$$58, _74$$61, _76$$62, _81$$63, _134$$63, _135$$63, _146$$63, _148$$63, _83$$64, _84$$64, _85$$65, _86$$65, _87$$66, _88$$66, _89$$67, _90$$67, _91$$68, _92$$68, _93$$69, _94$$69, _95$$70, _96$$71, _97$$72, _98$$73, _99$$74, _100$$74, _101$$75, _102$$75, _103$$76, _104$$77, _105$$78, _106$$79, _107$$80, _108$$81, _109$$82, _110$$83, _111$$84, _112$$85, _113$$86, _114$$87, _115$$88, _116$$89, _117$$90, _118$$91, _119$$92, _120$$93, _121$$94, _122$$95, _123$$96, _124$$97, _125$$98, _126$$99, _127$$100, _128$$100, _129$$101, _130$$101, _131$$101, _132$$103, _133$$104, _139$$111, _140$$114, _142$$114, _143$$117, _144$$118, _145$$121, _147$$122;
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
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_79);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_62$$3);
	ZVAL_UNDEF(&_63$$3);
	ZVAL_UNDEF(&_75$$3);
	ZVAL_UNDEF(&_77$$3);
	ZVAL_UNDEF(&_11$$4);
	ZVAL_UNDEF(&_12$$4);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_14$$5);
	ZVAL_UNDEF(&_15$$6);
	ZVAL_UNDEF(&_16$$6);
	ZVAL_UNDEF(&_17$$7);
	ZVAL_UNDEF(&_18$$7);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$9);
	ZVAL_UNDEF(&_22$$9);
	ZVAL_UNDEF(&_23$$10);
	ZVAL_UNDEF(&_24$$11);
	ZVAL_UNDEF(&_25$$12);
	ZVAL_UNDEF(&_26$$13);
	ZVAL_UNDEF(&_27$$14);
	ZVAL_UNDEF(&_28$$14);
	ZVAL_UNDEF(&_29$$15);
	ZVAL_UNDEF(&_30$$15);
	ZVAL_UNDEF(&_31$$16);
	ZVAL_UNDEF(&_32$$17);
	ZVAL_UNDEF(&_33$$18);
	ZVAL_UNDEF(&_34$$19);
	ZVAL_UNDEF(&_35$$20);
	ZVAL_UNDEF(&_36$$21);
	ZVAL_UNDEF(&_37$$22);
	ZVAL_UNDEF(&_38$$23);
	ZVAL_UNDEF(&_39$$24);
	ZVAL_UNDEF(&_40$$25);
	ZVAL_UNDEF(&_41$$26);
	ZVAL_UNDEF(&_42$$27);
	ZVAL_UNDEF(&_43$$28);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_45$$30);
	ZVAL_UNDEF(&_46$$31);
	ZVAL_UNDEF(&_47$$32);
	ZVAL_UNDEF(&_48$$33);
	ZVAL_UNDEF(&_49$$34);
	ZVAL_UNDEF(&_50$$35);
	ZVAL_UNDEF(&_51$$36);
	ZVAL_UNDEF(&_52$$37);
	ZVAL_UNDEF(&_53$$38);
	ZVAL_UNDEF(&_54$$39);
	ZVAL_UNDEF(&_55$$40);
	ZVAL_UNDEF(&_56$$40);
	ZVAL_UNDEF(&_57$$41);
	ZVAL_UNDEF(&_58$$41);
	ZVAL_UNDEF(&_59$$41);
	ZVAL_UNDEF(&_60$$43);
	ZVAL_UNDEF(&_61$$44);
	ZVAL_UNDEF(&_67$$51);
	ZVAL_UNDEF(&_68$$54);
	ZVAL_UNDEF(&_70$$54);
	ZVAL_UNDEF(&_71$$57);
	ZVAL_UNDEF(&_73$$58);
	ZVAL_UNDEF(&_74$$61);
	ZVAL_UNDEF(&_76$$62);
	ZVAL_UNDEF(&_81$$63);
	ZVAL_UNDEF(&_134$$63);
	ZVAL_UNDEF(&_135$$63);
	ZVAL_UNDEF(&_146$$63);
	ZVAL_UNDEF(&_148$$63);
	ZVAL_UNDEF(&_83$$64);
	ZVAL_UNDEF(&_84$$64);
	ZVAL_UNDEF(&_85$$65);
	ZVAL_UNDEF(&_86$$65);
	ZVAL_UNDEF(&_87$$66);
	ZVAL_UNDEF(&_88$$66);
	ZVAL_UNDEF(&_89$$67);
	ZVAL_UNDEF(&_90$$67);
	ZVAL_UNDEF(&_91$$68);
	ZVAL_UNDEF(&_92$$68);
	ZVAL_UNDEF(&_93$$69);
	ZVAL_UNDEF(&_94$$69);
	ZVAL_UNDEF(&_95$$70);
	ZVAL_UNDEF(&_96$$71);
	ZVAL_UNDEF(&_97$$72);
	ZVAL_UNDEF(&_98$$73);
	ZVAL_UNDEF(&_99$$74);
	ZVAL_UNDEF(&_100$$74);
	ZVAL_UNDEF(&_101$$75);
	ZVAL_UNDEF(&_102$$75);
	ZVAL_UNDEF(&_103$$76);
	ZVAL_UNDEF(&_104$$77);
	ZVAL_UNDEF(&_105$$78);
	ZVAL_UNDEF(&_106$$79);
	ZVAL_UNDEF(&_107$$80);
	ZVAL_UNDEF(&_108$$81);
	ZVAL_UNDEF(&_109$$82);
	ZVAL_UNDEF(&_110$$83);
	ZVAL_UNDEF(&_111$$84);
	ZVAL_UNDEF(&_112$$85);
	ZVAL_UNDEF(&_113$$86);
	ZVAL_UNDEF(&_114$$87);
	ZVAL_UNDEF(&_115$$88);
	ZVAL_UNDEF(&_116$$89);
	ZVAL_UNDEF(&_117$$90);
	ZVAL_UNDEF(&_118$$91);
	ZVAL_UNDEF(&_119$$92);
	ZVAL_UNDEF(&_120$$93);
	ZVAL_UNDEF(&_121$$94);
	ZVAL_UNDEF(&_122$$95);
	ZVAL_UNDEF(&_123$$96);
	ZVAL_UNDEF(&_124$$97);
	ZVAL_UNDEF(&_125$$98);
	ZVAL_UNDEF(&_126$$99);
	ZVAL_UNDEF(&_127$$100);
	ZVAL_UNDEF(&_128$$100);
	ZVAL_UNDEF(&_129$$101);
	ZVAL_UNDEF(&_130$$101);
	ZVAL_UNDEF(&_131$$101);
	ZVAL_UNDEF(&_132$$103);
	ZVAL_UNDEF(&_133$$104);
	ZVAL_UNDEF(&_139$$111);
	ZVAL_UNDEF(&_140$$114);
	ZVAL_UNDEF(&_142$$114);
	ZVAL_UNDEF(&_143$$117);
	ZVAL_UNDEF(&_144$$118);
	ZVAL_UNDEF(&_145$$121);
	ZVAL_UNDEF(&_147$$122);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 593, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "describecolumns", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "fetchall", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 594, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, 4);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getattribute", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_cast_to_string(&_5, &_3);
	isMariaDb = zephir_memnstr_str(&_5, SL("MariaDB"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 114);
	if (Z_TYPE_P(&fields) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_7);
		zephir_string_to_char_array(&_7, &fields);
		_6 = &_7;
	} else {
		_6 = &fields;
	}
	zephir_is_iterable(_6, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 583);
	if (Z_TYPE_P(_6) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_6), _8)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _8);
			ZEPHIR_INIT_NVAR(&_9$$3);
			zephir_create_array(&_9$$3, 1, 0);
			add_assoc_long_ex(&_9$$3, SL("bindType"), 2);
			ZEPHIR_CPY_WRT(&definition, &_9$$3);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 143);
			_10$$3 = 1;
			if (_10$$3 == zephir_start_with_str(&columnType, SL("bigint"))) { goto zephir_switch_0_clause_0; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("mediumint"))) { goto zephir_switch_0_clause_1; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("smallint"))) { goto zephir_switch_0_clause_2; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("tinyint"))) { goto zephir_switch_0_clause_3; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("int"))) { goto zephir_switch_0_clause_4; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("bit"))) { goto zephir_switch_0_clause_5; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("enum"))) { goto zephir_switch_0_clause_6; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("datetime"))) { goto zephir_switch_0_clause_7; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("date"))) { goto zephir_switch_0_clause_8; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("decimal"))) { goto zephir_switch_0_clause_9; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("double"))) { goto zephir_switch_0_clause_10; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("float"))) { goto zephir_switch_0_clause_11; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("mediumblob"))) { goto zephir_switch_0_clause_12; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("longblob"))) { goto zephir_switch_0_clause_13; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("tinyblob"))) { goto zephir_switch_0_clause_14; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("blob"))) { goto zephir_switch_0_clause_15; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("timestamp"))) { goto zephir_switch_0_clause_16; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("time"))) { goto zephir_switch_0_clause_17; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("json"))) { goto zephir_switch_0_clause_18; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("longtext"))) { goto zephir_switch_0_clause_19; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("mediumtext"))) { goto zephir_switch_0_clause_20; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("tinytext"))) { goto zephir_switch_0_clause_21; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("text"))) { goto zephir_switch_0_clause_22; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("varchar"))) { goto zephir_switch_0_clause_23; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("char"))) { goto zephir_switch_0_clause_24; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("varbinary"))) { goto zephir_switch_0_clause_25; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("binary"))) { goto zephir_switch_0_clause_26; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("multipoint"))) { goto zephir_switch_0_clause_27; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("multilinestring"))) { goto zephir_switch_0_clause_28; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("multipolygon"))) { goto zephir_switch_0_clause_29; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("geometrycollection"))) { goto zephir_switch_0_clause_30; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("linestring"))) { goto zephir_switch_0_clause_31; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("polygon"))) { goto zephir_switch_0_clause_32; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("point"))) { goto zephir_switch_0_clause_33; }
			if (_10$$3 == zephir_start_with_str(&columnType, SL("geometry"))) { goto zephir_switch_0_clause_34; }
			goto zephir_switch_0_clause_35;
			zephir_switch_0_clause_0: ;
				ZEPHIR_INIT_NVAR(&_11$$4);
				ZVAL_LONG(&_11$$4, 14);
				zephir_array_update_string(&definition, SL("type"), &_11$$4, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZVAL_LONG(&_12$$4, 2);
				zephir_array_update_string(&definition, SL("bindType"), &_12$$4, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_1: ;
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_LONG(&_13$$5, 21);
				zephir_array_update_string(&definition, SL("type"), &_13$$5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZVAL_LONG(&_14$$5, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_14$$5, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_2: ;
				ZEPHIR_INIT_NVAR(&_15$$6);
				ZVAL_LONG(&_15$$6, 22);
				zephir_array_update_string(&definition, SL("type"), &_15$$6, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_16$$6);
				ZVAL_LONG(&_16$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_16$$6, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_INIT_NVAR(&_17$$7);
				ZVAL_LONG(&_17$$7, 26);
				zephir_array_update_string(&definition, SL("type"), &_17$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_18$$7);
				ZVAL_LONG(&_18$$7, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_18$$7, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
				ZEPHIR_INIT_NVAR(&_19$$8);
				ZVAL_LONG(&_19$$8, 0);
				zephir_array_update_string(&definition, SL("type"), &_19$$8, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_20$$8);
				ZVAL_LONG(&_20$$8, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_20$$8, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_5: ;
				ZEPHIR_INIT_NVAR(&_21$$9);
				ZVAL_LONG(&_21$$9, 19);
				zephir_array_update_string(&definition, SL("type"), &_21$$9, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_22$$9);
				ZVAL_LONG(&_22$$9, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_22$$9, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_6: ;
				ZEPHIR_INIT_NVAR(&_23$$10);
				ZVAL_LONG(&_23$$10, 18);
				zephir_array_update_string(&definition, SL("type"), &_23$$10, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_7: ;
				ZEPHIR_INIT_NVAR(&_24$$11);
				ZVAL_LONG(&_24$$11, 4);
				zephir_array_update_string(&definition, SL("type"), &_24$$11, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_8: ;
				ZEPHIR_INIT_NVAR(&_25$$12);
				ZVAL_LONG(&_25$$12, 1);
				zephir_array_update_string(&definition, SL("type"), &_25$$12, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_9: ;
				ZEPHIR_INIT_NVAR(&_26$$13);
				ZVAL_LONG(&_26$$13, 3);
				zephir_array_update_string(&definition, SL("type"), &_26$$13, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_10: ;
				ZEPHIR_INIT_NVAR(&_27$$14);
				ZVAL_LONG(&_27$$14, 9);
				zephir_array_update_string(&definition, SL("type"), &_27$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_28$$14);
				ZVAL_LONG(&_28$$14, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_28$$14, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_11: ;
				ZEPHIR_INIT_NVAR(&_29$$15);
				ZVAL_LONG(&_29$$15, 7);
				zephir_array_update_string(&definition, SL("type"), &_29$$15, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_30$$15);
				ZVAL_LONG(&_30$$15, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_30$$15, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_12: ;
				ZEPHIR_INIT_NVAR(&_31$$16);
				ZVAL_LONG(&_31$$16, 12);
				zephir_array_update_string(&definition, SL("type"), &_31$$16, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_13: ;
				ZEPHIR_INIT_NVAR(&_32$$17);
				ZVAL_LONG(&_32$$17, 13);
				zephir_array_update_string(&definition, SL("type"), &_32$$17, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_14: ;
				ZEPHIR_INIT_NVAR(&_33$$18);
				ZVAL_LONG(&_33$$18, 10);
				zephir_array_update_string(&definition, SL("type"), &_33$$18, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_15: ;
				ZEPHIR_INIT_NVAR(&_34$$19);
				ZVAL_LONG(&_34$$19, 11);
				zephir_array_update_string(&definition, SL("type"), &_34$$19, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_16: ;
				ZEPHIR_INIT_NVAR(&_35$$20);
				ZVAL_LONG(&_35$$20, 17);
				zephir_array_update_string(&definition, SL("type"), &_35$$20, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_17: ;
				ZEPHIR_INIT_NVAR(&_36$$21);
				ZVAL_LONG(&_36$$21, 20);
				zephir_array_update_string(&definition, SL("type"), &_36$$21, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_18: ;
				ZEPHIR_INIT_NVAR(&_37$$22);
				ZVAL_LONG(&_37$$22, 15);
				zephir_array_update_string(&definition, SL("type"), &_37$$22, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_19: ;
				ZEPHIR_INIT_NVAR(&_38$$23);
				ZVAL_LONG(&_38$$23, 24);
				zephir_array_update_string(&definition, SL("type"), &_38$$23, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_20: ;
				ZEPHIR_INIT_NVAR(&_39$$24);
				ZVAL_LONG(&_39$$24, 23);
				zephir_array_update_string(&definition, SL("type"), &_39$$24, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_21: ;
				ZEPHIR_INIT_NVAR(&_40$$25);
				ZVAL_LONG(&_40$$25, 25);
				zephir_array_update_string(&definition, SL("type"), &_40$$25, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_22: ;
				ZEPHIR_INIT_NVAR(&_41$$26);
				ZVAL_LONG(&_41$$26, 6);
				zephir_array_update_string(&definition, SL("type"), &_41$$26, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_23: ;
				ZEPHIR_INIT_NVAR(&_42$$27);
				ZVAL_LONG(&_42$$27, 2);
				zephir_array_update_string(&definition, SL("type"), &_42$$27, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_24: ;
				ZEPHIR_INIT_NVAR(&_43$$28);
				ZVAL_LONG(&_43$$28, 5);
				zephir_array_update_string(&definition, SL("type"), &_43$$28, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_25: ;
				ZEPHIR_INIT_NVAR(&_44$$29);
				ZVAL_LONG(&_44$$29, 28);
				zephir_array_update_string(&definition, SL("type"), &_44$$29, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_26: ;
				ZEPHIR_INIT_NVAR(&_45$$30);
				ZVAL_LONG(&_45$$30, 27);
				zephir_array_update_string(&definition, SL("type"), &_45$$30, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_27: ;
				ZEPHIR_INIT_NVAR(&_46$$31);
				ZVAL_LONG(&_46$$31, 44);
				zephir_array_update_string(&definition, SL("type"), &_46$$31, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_28: ;
				ZEPHIR_INIT_NVAR(&_47$$32);
				ZVAL_LONG(&_47$$32, 45);
				zephir_array_update_string(&definition, SL("type"), &_47$$32, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_29: ;
				ZEPHIR_INIT_NVAR(&_48$$33);
				ZVAL_LONG(&_48$$33, 46);
				zephir_array_update_string(&definition, SL("type"), &_48$$33, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_30: ;
				ZEPHIR_INIT_NVAR(&_49$$34);
				ZVAL_LONG(&_49$$34, 47);
				zephir_array_update_string(&definition, SL("type"), &_49$$34, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_31: ;
				ZEPHIR_INIT_NVAR(&_50$$35);
				ZVAL_LONG(&_50$$35, 42);
				zephir_array_update_string(&definition, SL("type"), &_50$$35, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_32: ;
				ZEPHIR_INIT_NVAR(&_51$$36);
				ZVAL_LONG(&_51$$36, 43);
				zephir_array_update_string(&definition, SL("type"), &_51$$36, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_33: ;
				ZEPHIR_INIT_NVAR(&_52$$37);
				ZVAL_LONG(&_52$$37, 41);
				zephir_array_update_string(&definition, SL("type"), &_52$$37, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_34: ;
				ZEPHIR_INIT_NVAR(&_53$$38);
				ZVAL_LONG(&_53$$38, 40);
				zephir_array_update_string(&definition, SL("type"), &_53$$38, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_clause_35: ;
				ZEPHIR_INIT_NVAR(&_54$$39);
				ZVAL_LONG(&_54$$39, 2);
				zephir_array_update_string(&definition, SL("type"), &_54$$39, PH_COPY | PH_SEPARATE);
				goto zephir_switch_0_end;
			zephir_switch_0_end: ;

			if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 451)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				zephir_array_fetch_string(&_55$$40, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 454);
				if (ZEPHIR_IS_LONG(&_55$$40, 18)) {
					ZVAL_LONG(&_57$$41, 5);
					ZVAL_LONG(&_58$$41, -1);
					ZEPHIR_INIT_NVAR(&_59$$41);
					zephir_substr(&_59$$41, &columnType, 5 , -1 , 0);
					zephir_array_update_string(&definition, SL("size"), &_59$$41, PH_COPY | PH_SEPARATE);
				} else {
					ZEPHIR_INIT_NVAR(&_56$$40);
					zephir_preg_match(&_56$$40, &sizePattern, &columnType, &matches, 0, 0 , 0 );
					if (zephir_is_true(&_56$$40)) {
						ZEPHIR_OBS_NVAR(&matchOne);
						if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
							ZEPHIR_INIT_NVAR(&_60$$43);
							ZVAL_LONG(&_60$$43, zephir_get_intval(&matchOne));
							zephir_array_update_string(&definition, SL("size"), &_60$$43, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&matchTwo);
						if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
							ZEPHIR_INIT_NVAR(&_61$$44);
							ZVAL_LONG(&_61$$44, zephir_get_intval(&matchTwo));
							zephir_array_update_string(&definition, SL("scale"), &_61$$44, PH_COPY | PH_SEPARATE);
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
			zephir_array_fetch_long(&_62$$3, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 486);
			if (ZEPHIR_IS_STRING(&_62$$3, "PRI")) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_63$$3, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 493);
			if (ZEPHIR_IS_STRING(&_63$$3, "YES")) {
				zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_OBS_NVAR(&extraValue);
			zephir_array_fetch_long(&extraValue, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 502);
			_64$$3 = Z_TYPE_P(&extraValue) != IS_NULL;
			if (_64$$3) {
				_64$$3 = zephir_memnstr_str(&extraValue, SL("INVISIBLE"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 503);
			}
			if (_64$$3) {
				zephir_array_update_string(&definition, SL("invisible"), &__$true, PH_COPY | PH_SEPARATE);
			}
			_65$$3 = Z_TYPE_P(&extraValue) != IS_NULL;
			if (_65$$3) {
				_66$$3 = zephir_memnstr_str(&extraValue, SL("VIRTUAL GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 521);
				if (!(_66$$3)) {
					_66$$3 = zephir_memnstr_str(&extraValue, SL("STORED GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 521);
				}
				_65$$3 = _66$$3;
			}
			if (_65$$3) {
				if (zephir_array_isset_value_long(&field, 9)) {
					ZEPHIR_OBS_NVAR(&generationExpression);
					zephir_array_fetch_long(&generationExpression, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 523);
				} else {
					ZEPHIR_INIT_NVAR(&generationExpression);
					ZVAL_STRING(&generationExpression, "");
				}
				zephir_array_update_string(&definition, SL("generated"), &generationExpression, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_67$$51);
				ZVAL_BOOL(&_67$$51, zephir_memnstr_str(&extraValue, SL("STORED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 529));
				zephir_array_update_string(&definition, SL("generationStored"), &_67$$51, PH_COPY | PH_SEPARATE);
			} else {
				if (ZEPHIR_IS_STRING(&extraValue, "auto_increment")) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_68$$54, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 549);
				_69$$54 = Z_TYPE_P(&_68$$54) != IS_NULL;
				if (_69$$54) {
					zephir_array_fetch_long(&_70$$54, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 549);
					_69$$54 = !ZEPHIR_IS_STRING_IDENTICAL(&_70$$54, "NULL");
				}
				if (_69$$54) {
					ZEPHIR_OBS_NVAR(&defaultValue);
					zephir_array_fetch_long(&defaultValue, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 550);
					if (isMariaDb) {
						ZEPHIR_CALL_METHOD(&_71$$57, this_ptr, "unquotedefault", &_72, 0, &defaultValue);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&defaultValue, &_71$$57);
					}
					if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 556)) {
						ZEPHIR_INIT_NVAR(&_73$$58);
						ZEPHIR_CONCAT_VSV(&_73$$58, &defaultValue, " ", &extraValue);
						zephir_array_update_string(&definition, SL("default"), &_73$$58, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_update_string(&definition, SL("default"), &defaultValue, PH_COPY | PH_SEPARATE);
					}
				} else {
					if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 562)) {
						ZEPHIR_INIT_NVAR(&_74$$61);
						ZEPHIR_CONCAT_SV(&_74$$61, "NULL ", &extraValue);
						zephir_array_update_string(&definition, SL("default"), &_74$$61, PH_COPY | PH_SEPARATE);
					}
				}
			}
			zephir_array_fetch_long(&_75$$3, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 571);
			if (Z_TYPE_P(&_75$$3) != IS_NULL) {
				zephir_array_fetch_long(&_76$$62, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 572);
				zephir_array_update_string(&definition, SL("comment"), &_76$$62, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 578);
			ZEPHIR_INIT_NVAR(&_77$$3);
			object_init_ex(&_77$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_77$$3, "__construct", &_78, 0, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_77$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 579);
			ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _6, "rewind", NULL, 0);
		zephir_check_call_status();
		_80 = 1;
		while (1) {
			if (_80) {
				_80 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _6, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_79, _6, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_79)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, _6, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_81$$63);
				zephir_create_array(&_81$$63, 1, 0);
				add_assoc_long_ex(&_81$$63, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_81$$63);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 143);
				_82$$63 = 1;
				if (_82$$63 == zephir_start_with_str(&columnType, SL("bigint"))) { goto zephir_switch_1_clause_0; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("mediumint"))) { goto zephir_switch_1_clause_1; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("smallint"))) { goto zephir_switch_1_clause_2; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("tinyint"))) { goto zephir_switch_1_clause_3; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("int"))) { goto zephir_switch_1_clause_4; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("bit"))) { goto zephir_switch_1_clause_5; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("enum"))) { goto zephir_switch_1_clause_6; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("datetime"))) { goto zephir_switch_1_clause_7; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("date"))) { goto zephir_switch_1_clause_8; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("decimal"))) { goto zephir_switch_1_clause_9; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("double"))) { goto zephir_switch_1_clause_10; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("float"))) { goto zephir_switch_1_clause_11; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("mediumblob"))) { goto zephir_switch_1_clause_12; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("longblob"))) { goto zephir_switch_1_clause_13; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("tinyblob"))) { goto zephir_switch_1_clause_14; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("blob"))) { goto zephir_switch_1_clause_15; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("timestamp"))) { goto zephir_switch_1_clause_16; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("time"))) { goto zephir_switch_1_clause_17; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("json"))) { goto zephir_switch_1_clause_18; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("longtext"))) { goto zephir_switch_1_clause_19; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("mediumtext"))) { goto zephir_switch_1_clause_20; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("tinytext"))) { goto zephir_switch_1_clause_21; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("text"))) { goto zephir_switch_1_clause_22; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("varchar"))) { goto zephir_switch_1_clause_23; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("char"))) { goto zephir_switch_1_clause_24; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("varbinary"))) { goto zephir_switch_1_clause_25; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("binary"))) { goto zephir_switch_1_clause_26; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("multipoint"))) { goto zephir_switch_1_clause_27; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("multilinestring"))) { goto zephir_switch_1_clause_28; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("multipolygon"))) { goto zephir_switch_1_clause_29; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("geometrycollection"))) { goto zephir_switch_1_clause_30; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("linestring"))) { goto zephir_switch_1_clause_31; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("polygon"))) { goto zephir_switch_1_clause_32; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("point"))) { goto zephir_switch_1_clause_33; }
				if (_82$$63 == zephir_start_with_str(&columnType, SL("geometry"))) { goto zephir_switch_1_clause_34; }
				goto zephir_switch_1_clause_35;
				zephir_switch_1_clause_0: ;
					ZEPHIR_INIT_NVAR(&_83$$64);
					ZVAL_LONG(&_83$$64, 14);
					zephir_array_update_string(&definition, SL("type"), &_83$$64, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_84$$64);
					ZVAL_LONG(&_84$$64, 2);
					zephir_array_update_string(&definition, SL("bindType"), &_84$$64, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_1: ;
					ZEPHIR_INIT_NVAR(&_85$$65);
					ZVAL_LONG(&_85$$65, 21);
					zephir_array_update_string(&definition, SL("type"), &_85$$65, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_86$$65);
					ZVAL_LONG(&_86$$65, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_86$$65, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_2: ;
					ZEPHIR_INIT_NVAR(&_87$$66);
					ZVAL_LONG(&_87$$66, 22);
					zephir_array_update_string(&definition, SL("type"), &_87$$66, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_88$$66);
					ZVAL_LONG(&_88$$66, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_88$$66, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_NVAR(&_89$$67);
					ZVAL_LONG(&_89$$67, 26);
					zephir_array_update_string(&definition, SL("type"), &_89$$67, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_90$$67);
					ZVAL_LONG(&_90$$67, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_90$$67, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
					ZEPHIR_INIT_NVAR(&_91$$68);
					ZVAL_LONG(&_91$$68, 0);
					zephir_array_update_string(&definition, SL("type"), &_91$$68, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_92$$68);
					ZVAL_LONG(&_92$$68, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_92$$68, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_5: ;
					ZEPHIR_INIT_NVAR(&_93$$69);
					ZVAL_LONG(&_93$$69, 19);
					zephir_array_update_string(&definition, SL("type"), &_93$$69, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_94$$69);
					ZVAL_LONG(&_94$$69, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_94$$69, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_6: ;
					ZEPHIR_INIT_NVAR(&_95$$70);
					ZVAL_LONG(&_95$$70, 18);
					zephir_array_update_string(&definition, SL("type"), &_95$$70, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_7: ;
					ZEPHIR_INIT_NVAR(&_96$$71);
					ZVAL_LONG(&_96$$71, 4);
					zephir_array_update_string(&definition, SL("type"), &_96$$71, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_8: ;
					ZEPHIR_INIT_NVAR(&_97$$72);
					ZVAL_LONG(&_97$$72, 1);
					zephir_array_update_string(&definition, SL("type"), &_97$$72, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_9: ;
					ZEPHIR_INIT_NVAR(&_98$$73);
					ZVAL_LONG(&_98$$73, 3);
					zephir_array_update_string(&definition, SL("type"), &_98$$73, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_10: ;
					ZEPHIR_INIT_NVAR(&_99$$74);
					ZVAL_LONG(&_99$$74, 9);
					zephir_array_update_string(&definition, SL("type"), &_99$$74, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_100$$74);
					ZVAL_LONG(&_100$$74, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_100$$74, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_11: ;
					ZEPHIR_INIT_NVAR(&_101$$75);
					ZVAL_LONG(&_101$$75, 7);
					zephir_array_update_string(&definition, SL("type"), &_101$$75, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_102$$75);
					ZVAL_LONG(&_102$$75, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_102$$75, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_12: ;
					ZEPHIR_INIT_NVAR(&_103$$76);
					ZVAL_LONG(&_103$$76, 12);
					zephir_array_update_string(&definition, SL("type"), &_103$$76, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_13: ;
					ZEPHIR_INIT_NVAR(&_104$$77);
					ZVAL_LONG(&_104$$77, 13);
					zephir_array_update_string(&definition, SL("type"), &_104$$77, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_14: ;
					ZEPHIR_INIT_NVAR(&_105$$78);
					ZVAL_LONG(&_105$$78, 10);
					zephir_array_update_string(&definition, SL("type"), &_105$$78, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_15: ;
					ZEPHIR_INIT_NVAR(&_106$$79);
					ZVAL_LONG(&_106$$79, 11);
					zephir_array_update_string(&definition, SL("type"), &_106$$79, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_16: ;
					ZEPHIR_INIT_NVAR(&_107$$80);
					ZVAL_LONG(&_107$$80, 17);
					zephir_array_update_string(&definition, SL("type"), &_107$$80, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_17: ;
					ZEPHIR_INIT_NVAR(&_108$$81);
					ZVAL_LONG(&_108$$81, 20);
					zephir_array_update_string(&definition, SL("type"), &_108$$81, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_18: ;
					ZEPHIR_INIT_NVAR(&_109$$82);
					ZVAL_LONG(&_109$$82, 15);
					zephir_array_update_string(&definition, SL("type"), &_109$$82, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_19: ;
					ZEPHIR_INIT_NVAR(&_110$$83);
					ZVAL_LONG(&_110$$83, 24);
					zephir_array_update_string(&definition, SL("type"), &_110$$83, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_20: ;
					ZEPHIR_INIT_NVAR(&_111$$84);
					ZVAL_LONG(&_111$$84, 23);
					zephir_array_update_string(&definition, SL("type"), &_111$$84, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_21: ;
					ZEPHIR_INIT_NVAR(&_112$$85);
					ZVAL_LONG(&_112$$85, 25);
					zephir_array_update_string(&definition, SL("type"), &_112$$85, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_22: ;
					ZEPHIR_INIT_NVAR(&_113$$86);
					ZVAL_LONG(&_113$$86, 6);
					zephir_array_update_string(&definition, SL("type"), &_113$$86, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_23: ;
					ZEPHIR_INIT_NVAR(&_114$$87);
					ZVAL_LONG(&_114$$87, 2);
					zephir_array_update_string(&definition, SL("type"), &_114$$87, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_24: ;
					ZEPHIR_INIT_NVAR(&_115$$88);
					ZVAL_LONG(&_115$$88, 5);
					zephir_array_update_string(&definition, SL("type"), &_115$$88, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_25: ;
					ZEPHIR_INIT_NVAR(&_116$$89);
					ZVAL_LONG(&_116$$89, 28);
					zephir_array_update_string(&definition, SL("type"), &_116$$89, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_26: ;
					ZEPHIR_INIT_NVAR(&_117$$90);
					ZVAL_LONG(&_117$$90, 27);
					zephir_array_update_string(&definition, SL("type"), &_117$$90, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_27: ;
					ZEPHIR_INIT_NVAR(&_118$$91);
					ZVAL_LONG(&_118$$91, 44);
					zephir_array_update_string(&definition, SL("type"), &_118$$91, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_28: ;
					ZEPHIR_INIT_NVAR(&_119$$92);
					ZVAL_LONG(&_119$$92, 45);
					zephir_array_update_string(&definition, SL("type"), &_119$$92, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_29: ;
					ZEPHIR_INIT_NVAR(&_120$$93);
					ZVAL_LONG(&_120$$93, 46);
					zephir_array_update_string(&definition, SL("type"), &_120$$93, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_30: ;
					ZEPHIR_INIT_NVAR(&_121$$94);
					ZVAL_LONG(&_121$$94, 47);
					zephir_array_update_string(&definition, SL("type"), &_121$$94, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_31: ;
					ZEPHIR_INIT_NVAR(&_122$$95);
					ZVAL_LONG(&_122$$95, 42);
					zephir_array_update_string(&definition, SL("type"), &_122$$95, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_32: ;
					ZEPHIR_INIT_NVAR(&_123$$96);
					ZVAL_LONG(&_123$$96, 43);
					zephir_array_update_string(&definition, SL("type"), &_123$$96, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_33: ;
					ZEPHIR_INIT_NVAR(&_124$$97);
					ZVAL_LONG(&_124$$97, 41);
					zephir_array_update_string(&definition, SL("type"), &_124$$97, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_34: ;
					ZEPHIR_INIT_NVAR(&_125$$98);
					ZVAL_LONG(&_125$$98, 40);
					zephir_array_update_string(&definition, SL("type"), &_125$$98, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_clause_35: ;
					ZEPHIR_INIT_NVAR(&_126$$99);
					ZVAL_LONG(&_126$$99, 2);
					zephir_array_update_string(&definition, SL("type"), &_126$$99, PH_COPY | PH_SEPARATE);
					goto zephir_switch_1_end;
				zephir_switch_1_end: ;

				if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 451)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					zephir_array_fetch_string(&_127$$100, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 454);
					if (ZEPHIR_IS_LONG(&_127$$100, 18)) {
						ZVAL_LONG(&_129$$101, 5);
						ZVAL_LONG(&_130$$101, -1);
						ZEPHIR_INIT_NVAR(&_131$$101);
						zephir_substr(&_131$$101, &columnType, 5 , -1 , 0);
						zephir_array_update_string(&definition, SL("size"), &_131$$101, PH_COPY | PH_SEPARATE);
					} else {
						ZEPHIR_INIT_NVAR(&_128$$100);
						zephir_preg_match(&_128$$100, &sizePattern, &columnType, &matches, 0, 0 , 0 );
						if (zephir_is_true(&_128$$100)) {
							ZEPHIR_OBS_NVAR(&matchOne);
							if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
								ZEPHIR_INIT_NVAR(&_132$$103);
								ZVAL_LONG(&_132$$103, zephir_get_intval(&matchOne));
								zephir_array_update_string(&definition, SL("size"), &_132$$103, PH_COPY | PH_SEPARATE);
							}
							ZEPHIR_OBS_NVAR(&matchTwo);
							if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
								ZEPHIR_INIT_NVAR(&_133$$104);
								ZVAL_LONG(&_133$$104, zephir_get_intval(&matchTwo));
								zephir_array_update_string(&definition, SL("scale"), &_133$$104, PH_COPY | PH_SEPARATE);
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
				zephir_array_fetch_long(&_134$$63, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 486);
				if (ZEPHIR_IS_STRING(&_134$$63, "PRI")) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_135$$63, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 493);
				if (ZEPHIR_IS_STRING(&_135$$63, "YES")) {
					zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&extraValue);
				zephir_array_fetch_long(&extraValue, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 502);
				_136$$63 = Z_TYPE_P(&extraValue) != IS_NULL;
				if (_136$$63) {
					_136$$63 = zephir_memnstr_str(&extraValue, SL("INVISIBLE"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 503);
				}
				if (_136$$63) {
					zephir_array_update_string(&definition, SL("invisible"), &__$true, PH_COPY | PH_SEPARATE);
				}
				_137$$63 = Z_TYPE_P(&extraValue) != IS_NULL;
				if (_137$$63) {
					_138$$63 = zephir_memnstr_str(&extraValue, SL("VIRTUAL GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 521);
					if (!(_138$$63)) {
						_138$$63 = zephir_memnstr_str(&extraValue, SL("STORED GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 521);
					}
					_137$$63 = _138$$63;
				}
				if (_137$$63) {
					if (zephir_array_isset_value_long(&field, 9)) {
						ZEPHIR_OBS_NVAR(&generationExpression);
						zephir_array_fetch_long(&generationExpression, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 523);
					} else {
						ZEPHIR_INIT_NVAR(&generationExpression);
						ZVAL_STRING(&generationExpression, "");
					}
					zephir_array_update_string(&definition, SL("generated"), &generationExpression, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_139$$111);
					ZVAL_BOOL(&_139$$111, zephir_memnstr_str(&extraValue, SL("STORED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 529));
					zephir_array_update_string(&definition, SL("generationStored"), &_139$$111, PH_COPY | PH_SEPARATE);
				} else {
					if (ZEPHIR_IS_STRING(&extraValue, "auto_increment")) {
						zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
					}
					zephir_array_fetch_long(&_140$$114, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 549);
					_141$$114 = Z_TYPE_P(&_140$$114) != IS_NULL;
					if (_141$$114) {
						zephir_array_fetch_long(&_142$$114, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 549);
						_141$$114 = !ZEPHIR_IS_STRING_IDENTICAL(&_142$$114, "NULL");
					}
					if (_141$$114) {
						ZEPHIR_OBS_NVAR(&defaultValue);
						zephir_array_fetch_long(&defaultValue, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 550);
						if (isMariaDb) {
							ZEPHIR_CALL_METHOD(&_143$$117, this_ptr, "unquotedefault", &_72, 0, &defaultValue);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&defaultValue, &_143$$117);
						}
						if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 556)) {
							ZEPHIR_INIT_NVAR(&_144$$118);
							ZEPHIR_CONCAT_VSV(&_144$$118, &defaultValue, " ", &extraValue);
							zephir_array_update_string(&definition, SL("default"), &_144$$118, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_update_string(&definition, SL("default"), &defaultValue, PH_COPY | PH_SEPARATE);
						}
					} else {
						if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 562)) {
							ZEPHIR_INIT_NVAR(&_145$$121);
							ZEPHIR_CONCAT_SV(&_145$$121, "NULL ", &extraValue);
							zephir_array_update_string(&definition, SL("default"), &_145$$121, PH_COPY | PH_SEPARATE);
						}
					}
				}
				zephir_array_fetch_long(&_146$$63, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 571);
				if (Z_TYPE_P(&_146$$63) != IS_NULL) {
					zephir_array_fetch_long(&_147$$122, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 572);
					zephir_array_update_string(&definition, SL("comment"), &_147$$122, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 578);
				ZEPHIR_INIT_NVAR(&_148$$63);
				object_init_ex(&_148$$63, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_148$$63, "__construct", &_78, 0, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_148$$63, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 579);
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
	zval _16$$9, _37$$23;
	zend_ulong _48;
	zval indexes, indexObjects, _57$$31;
	zend_bool invisible = 0, anyDirection = 0, _27, _13$$3, _24$$3, _34$$17, _45$$17, _55$$31;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_60 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, __$true, columns, index, keyName, indexType, name, directions, collation, _0, _1, _2, _3, *_4, _5, *_6, _26, *_47, _7$$4, _8$$3, _10$$3, _11$$3, _14$$3, _19$$3, _25$$3, _9$$6, _12$$8, _15$$9, _17$$10, _18$$11, _20$$12, _21$$13, _22$$14, _23$$15, _28$$18, _29$$17, _31$$17, _32$$17, _35$$17, _40$$17, _46$$17, _30$$20, _33$$22, _36$$23, _38$$24, _39$$25, _41$$26, _42$$27, _43$$28, _44$$29, _50$$32, *_51$$31, _52$$31, *_53$$31, _54$$31, _56$$31, _58$$31, _59$$31;
	zend_string *table = NULL, *schema = NULL, *_49;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_26);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_19$$3);
	ZVAL_UNDEF(&_25$$3);
	ZVAL_UNDEF(&_9$$6);
	ZVAL_UNDEF(&_12$$8);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_17$$10);
	ZVAL_UNDEF(&_18$$11);
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$14);
	ZVAL_UNDEF(&_23$$15);
	ZVAL_UNDEF(&_28$$18);
	ZVAL_UNDEF(&_29$$17);
	ZVAL_UNDEF(&_31$$17);
	ZVAL_UNDEF(&_32$$17);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_40$$17);
	ZVAL_UNDEF(&_46$$17);
	ZVAL_UNDEF(&_30$$20);
	ZVAL_UNDEF(&_33$$22);
	ZVAL_UNDEF(&_36$$23);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_39$$25);
	ZVAL_UNDEF(&_41$$26);
	ZVAL_UNDEF(&_42$$27);
	ZVAL_UNDEF(&_43$$28);
	ZVAL_UNDEF(&_44$$29);
	ZVAL_UNDEF(&_50$$32);
	ZVAL_UNDEF(&_52$$31);
	ZVAL_UNDEF(&_54$$31);
	ZVAL_UNDEF(&_56$$31);
	ZVAL_UNDEF(&_58$$31);
	ZVAL_UNDEF(&_59$$31);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&indexObjects);
	ZVAL_UNDEF(&_57$$31);
	ZVAL_UNDEF(&_16$$9);
	ZVAL_UNDEF(&_37$$23);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 593, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeindexes", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &_0);
		_4 = &_5;
	} else {
		_4 = &_0;
	}
	zephir_is_iterable(_4, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 664);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4), _6)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _6);
			zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 603);
			zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 604);
			if (!(zephir_array_isset_value(&indexes, &keyName))) {
				ZEPHIR_INIT_NVAR(&_7$$4);
				array_init(&_7$$4);
				zephir_array_update_zval(&indexes, &keyName, &_7$$4, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch(&_8$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 610);
			if (!(zephir_array_isset_value_string(&_8$$3, SL("columns")))) {
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
			} else {
				zephir_array_fetch(&_9$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 613);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_9$$6, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 613);
			}
			zephir_array_fetch_string(&_10$$3, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 616);
			zephir_array_append(&columns, &_10$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 616);
			zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
			zephir_array_fetch(&_11$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 625);
			if (!(zephir_array_isset_value_string(&_11$$3, SL("directions")))) {
				ZEPHIR_INIT_NVAR(&directions);
				array_init(&directions);
			} else {
				zephir_array_fetch(&_12$$8, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 628);
				ZEPHIR_OBS_NVAR(&directions);
				zephir_array_fetch_string(&directions, &_12$$8, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 628);
			}
			ZEPHIR_INIT_NVAR(&collation);
			ZVAL_STRING(&collation, "");
			_13$$3 = zephir_array_isset_value_string(&index, SL("Collation"));
			if (_13$$3) {
				zephir_array_fetch_string(&_14$$3, &index, SL("Collation"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 632);
				_13$$3 = Z_TYPE_P(&_14$$3) != IS_NULL;
			}
			if (_13$$3) {
				ZEPHIR_OBS_NVAR(&_15$$9);
				zephir_array_fetch_string(&_15$$9, &index, SL("Collation"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 633);
				zephir_cast_to_string(&_16$$9, &_15$$9);
				ZEPHIR_CPY_WRT(&collation, &_16$$9);
			}
			if (ZEPHIR_IS_STRING(&collation, "D")) {
				ZEPHIR_INIT_NVAR(&_17$$10);
				ZVAL_STRING(&_17$$10, "DESC");
				zephir_array_append(&directions, &_17$$10, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 637);
			} else {
				ZEPHIR_INIT_NVAR(&_18$$11);
				ZVAL_STRING(&_18$$11, "ASC");
				zephir_array_append(&directions, &_18$$11, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 639);
			}
			zephir_array_update_multi(&indexes, &directions, SL("zs"), 3, &keyName, SL("directions"));
			if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
				ZEPHIR_INIT_NVAR(&_20$$12);
				ZVAL_STRING(&_20$$12, "PRIMARY");
				zephir_array_update_multi(&indexes, &_20$$12, SL("zs"), 3, &keyName, SL("type"));
			} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
				ZEPHIR_INIT_NVAR(&_21$$13);
				ZVAL_STRING(&_21$$13, "FULLTEXT");
				zephir_array_update_multi(&indexes, &_21$$13, SL("zs"), 3, &keyName, SL("type"));
			} else {
				zephir_array_fetch_string(&_19$$3, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 648);
				if (ZEPHIR_IS_LONG(&_19$$3, 0)) {
					ZEPHIR_INIT_NVAR(&_22$$14);
					ZVAL_STRING(&_22$$14, "UNIQUE");
					zephir_array_update_multi(&indexes, &_22$$14, SL("zs"), 3, &keyName, SL("type"));
				} else {
					ZEPHIR_INIT_NVAR(&_23$$15);
					ZVAL_STRING(&_23$$15, "");
					zephir_array_update_multi(&indexes, &_23$$15, SL("zs"), 3, &keyName, SL("type"));
				}
			}
			_24$$3 = zephir_array_isset_value_string(&index, SL("Visible"));
			if (_24$$3) {
				zephir_array_fetch_string(&_25$$3, &index, SL("Visible"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 659);
				_24$$3 = ZEPHIR_IS_STRING(&_25$$3, "NO");
			}
			if (_24$$3) {
				zephir_array_update_multi(&indexes, &__$true, SL("zs"), 3, &keyName, SL("invisible"));
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_27 = 1;
		while (1) {
			if (_27) {
				_27 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_26, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_26)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&keyName);
				zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 603);
				ZEPHIR_OBS_NVAR(&indexType);
				zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 604);
				if (!(zephir_array_isset_value(&indexes, &keyName))) {
					ZEPHIR_INIT_NVAR(&_28$$18);
					array_init(&_28$$18);
					zephir_array_update_zval(&indexes, &keyName, &_28$$18, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch(&_29$$17, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 610);
				if (!(zephir_array_isset_value_string(&_29$$17, SL("columns")))) {
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
				} else {
					zephir_array_fetch(&_30$$20, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 613);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_30$$20, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 613);
				}
				zephir_array_fetch_string(&_31$$17, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 616);
				zephir_array_append(&columns, &_31$$17, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 616);
				zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
				zephir_array_fetch(&_32$$17, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 625);
				if (!(zephir_array_isset_value_string(&_32$$17, SL("directions")))) {
					ZEPHIR_INIT_NVAR(&directions);
					array_init(&directions);
				} else {
					zephir_array_fetch(&_33$$22, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 628);
					ZEPHIR_OBS_NVAR(&directions);
					zephir_array_fetch_string(&directions, &_33$$22, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 628);
				}
				ZEPHIR_INIT_NVAR(&collation);
				ZVAL_STRING(&collation, "");
				_34$$17 = zephir_array_isset_value_string(&index, SL("Collation"));
				if (_34$$17) {
					zephir_array_fetch_string(&_35$$17, &index, SL("Collation"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 632);
					_34$$17 = Z_TYPE_P(&_35$$17) != IS_NULL;
				}
				if (_34$$17) {
					ZEPHIR_OBS_NVAR(&_36$$23);
					zephir_array_fetch_string(&_36$$23, &index, SL("Collation"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 633);
					zephir_cast_to_string(&_37$$23, &_36$$23);
					ZEPHIR_CPY_WRT(&collation, &_37$$23);
				}
				if (ZEPHIR_IS_STRING(&collation, "D")) {
					ZEPHIR_INIT_NVAR(&_38$$24);
					ZVAL_STRING(&_38$$24, "DESC");
					zephir_array_append(&directions, &_38$$24, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 637);
				} else {
					ZEPHIR_INIT_NVAR(&_39$$25);
					ZVAL_STRING(&_39$$25, "ASC");
					zephir_array_append(&directions, &_39$$25, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 639);
				}
				zephir_array_update_multi(&indexes, &directions, SL("zs"), 3, &keyName, SL("directions"));
				if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
					ZEPHIR_INIT_NVAR(&_41$$26);
					ZVAL_STRING(&_41$$26, "PRIMARY");
					zephir_array_update_multi(&indexes, &_41$$26, SL("zs"), 3, &keyName, SL("type"));
				} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
					ZEPHIR_INIT_NVAR(&_42$$27);
					ZVAL_STRING(&_42$$27, "FULLTEXT");
					zephir_array_update_multi(&indexes, &_42$$27, SL("zs"), 3, &keyName, SL("type"));
				} else {
					zephir_array_fetch_string(&_40$$17, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 648);
					if (ZEPHIR_IS_LONG(&_40$$17, 0)) {
						ZEPHIR_INIT_NVAR(&_43$$28);
						ZVAL_STRING(&_43$$28, "UNIQUE");
						zephir_array_update_multi(&indexes, &_43$$28, SL("zs"), 3, &keyName, SL("type"));
					} else {
						ZEPHIR_INIT_NVAR(&_44$$29);
						ZVAL_STRING(&_44$$29, "");
						zephir_array_update_multi(&indexes, &_44$$29, SL("zs"), 3, &keyName, SL("type"));
					}
				}
				_45$$17 = zephir_array_isset_value_string(&index, SL("Visible"));
				if (_45$$17) {
					zephir_array_fetch_string(&_46$$17, &index, SL("Visible"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 659);
					_45$$17 = ZEPHIR_IS_STRING(&_46$$17, "NO");
				}
				if (_45$$17) {
					zephir_array_update_multi(&indexes, &__$true, SL("zs"), 3, &keyName, SL("invisible"));
				}
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	zephir_is_iterable(&indexes, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 699);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&indexes), _48, _49, _47)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_49 != NULL) { 
			ZVAL_STR_COPY(&name, _49);
		} else {
			ZVAL_LONG(&name, _48);
		}
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_COPY(&index, _47);
		invisible = 0;
		if (zephir_array_isset_value_string(&index, SL("invisible"))) {
			ZEPHIR_OBS_NVAR(&_50$$32);
			zephir_array_fetch_string(&_50$$32, &index, SL("invisible"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 667);
			invisible = zephir_get_boolval(&_50$$32);
		}
		ZEPHIR_OBS_NVAR(&directions);
		zephir_array_fetch_string(&directions, &index, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 675);
		anyDirection = 0;
		if (Z_TYPE_P(&directions) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_52$$31);
			zephir_string_to_char_array(&_52$$31, &directions);
			_51$$31 = &_52$$31;
		} else {
			_51$$31 = &directions;
		}
		zephir_is_iterable(_51$$31, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 684);
		if (Z_TYPE_P(_51$$31) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_51$$31), _53$$31)
			{
				ZEPHIR_INIT_NVAR(&collation);
				ZVAL_COPY(&collation, _53$$31);
				if (ZEPHIR_IS_STRING(&collation, "DESC")) {
					anyDirection = 1;
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _51$$31, "rewind", NULL, 0);
			zephir_check_call_status();
			_55$$31 = 1;
			while (1) {
				if (_55$$31) {
					_55$$31 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _51$$31, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_54$$31, _51$$31, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_54$$31)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&collation, _51$$31, "current", NULL, 0);
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
		ZEPHIR_INIT_NVAR(&_56$$31);
		object_init_ex(&_56$$31, phalcon_db_index_ce);
		ZEPHIR_INIT_NVAR(&_57$$31);
		zephir_create_array(&_57$$31, 4, 0);
		ZEPHIR_OBS_NVAR(&_58$$31);
		zephir_array_fetch_string(&_58$$31, &index, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 691);
		zephir_array_update_string(&_57$$31, SL("columns"), &_58$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_58$$31);
		zephir_array_fetch_string(&_58$$31, &index, SL("type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 692);
		zephir_array_update_string(&_57$$31, SL("type"), &_58$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_59$$31);
		ZVAL_BOOL(&_59$$31, invisible);
		zephir_array_update_string(&_57$$31, SL("invisible"), &_59$$31, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_57$$31, SL("directions"), &directions, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_56$$31, "__construct", &_60, 63, &name, &_57$$31);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, &name, &_56$$31, PH_COPY | PH_SEPARATE);
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
	zend_ulong _28;
	zend_bool _17;
	zval references, referenceObjects, _15$$3, _26$$6, _31$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_33 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, arrayReference, columns, constraintName, name, reference, referenceDelete, referenceUpdate, referencedColumns, referencedSchema, referencedTable, _0, _1, _2, _3, *_4, _5, *_6, _16, *_27, _7$$5, _8$$5, _9$$5, _10$$5, _11$$5, _12$$5, _13$$3, _14$$3, _18$$8, _19$$8, _20$$8, _21$$8, _22$$8, _23$$8, _24$$6, _25$$6, _30$$9, _32$$9;
	zend_string *table = NULL, *schema = NULL, *_29;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_18$$8);
	ZVAL_UNDEF(&_19$$8);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$6);
	ZVAL_UNDEF(&_25$$6);
	ZVAL_UNDEF(&_30$$9);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&references);
	ZVAL_UNDEF(&referenceObjects);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_31$$9);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 593, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describereferences", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	if (Z_TYPE_P(&_0) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_5);
		zephir_string_to_char_array(&_5, &_0);
		_4 = &_5;
	} else {
		_4 = &_0;
	}
	zephir_is_iterable(_4, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 752);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4), _6)
		{
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _6);
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
				zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_7$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 732);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_8$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 732);
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 733);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_9$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 733);
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 734);
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_10$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 734);
				zephir_array_fetch(&_11$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_string(&referenceUpdate, &_11$$5, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
				zephir_array_fetch(&_12$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 736);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_string(&referenceDelete, &_12$$5, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 736);
			}
			zephir_array_fetch_long(&_13$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 739);
			zephir_array_append(&columns, &_13$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 739);
			zephir_array_fetch_long(&_14$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 740);
			zephir_array_append(&referencedColumns, &_14$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 740);
			ZEPHIR_INIT_NVAR(&_15$$3);
			zephir_create_array(&_15$$3, 6, 0);
			zephir_array_update_string(&_15$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_15$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_15$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_15$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_15$$3, SL("onUpdate"), &referenceUpdate, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_15$$3, SL("onDelete"), &referenceDelete, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&references, &constraintName, &_15$$3, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_17 = 1;
		while (1) {
			if (_17) {
				_17 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_16, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_16)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&reference, _4, "current", NULL, 0);
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
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_18$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
					zephir_array_fetch(&_19$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 732);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_19$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 732);
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 733);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_20$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 733);
					zephir_array_fetch(&_21$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 734);
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_21$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 734);
					zephir_array_fetch(&_22$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_string(&referenceUpdate, &_22$$8, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
					zephir_array_fetch(&_23$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 736);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_string(&referenceDelete, &_23$$8, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 736);
				}
				zephir_array_fetch_long(&_24$$6, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 739);
				zephir_array_append(&columns, &_24$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 739);
				zephir_array_fetch_long(&_25$$6, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 740);
				zephir_array_append(&referencedColumns, &_25$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 740);
				ZEPHIR_INIT_NVAR(&_26$$6);
				zephir_create_array(&_26$$6, 6, 0);
				zephir_array_update_string(&_26$$6, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_26$$6, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_26$$6, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_26$$6, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_26$$6, SL("onUpdate"), &referenceUpdate, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_26$$6, SL("onDelete"), &referenceDelete, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&references, &constraintName, &_26$$6, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_INIT_NVAR(&reference);
	zephir_is_iterable(&references, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 766);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&references), _28, _29, _27)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_29 != NULL) { 
			ZVAL_STR_COPY(&name, _29);
		} else {
			ZVAL_LONG(&name, _28);
		}
		ZEPHIR_INIT_NVAR(&arrayReference);
		ZVAL_COPY(&arrayReference, _27);
		ZEPHIR_INIT_NVAR(&_30$$9);
		object_init_ex(&_30$$9, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(&_31$$9);
		zephir_create_array(&_31$$9, 6, 0);
		ZEPHIR_OBS_NVAR(&_32$$9);
		zephir_array_fetch_string(&_32$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 756);
		zephir_array_update_string(&_31$$9, SL("referencedSchema"), &_32$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_32$$9);
		zephir_array_fetch_string(&_32$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 757);
		zephir_array_update_string(&_31$$9, SL("referencedTable"), &_32$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_32$$9);
		zephir_array_fetch_string(&_32$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 758);
		zephir_array_update_string(&_31$$9, SL("columns"), &_32$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_32$$9);
		zephir_array_fetch_string(&_32$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 759);
		zephir_array_update_string(&_31$$9, SL("referencedColumns"), &_32$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_32$$9);
		zephir_array_fetch_string(&_32$$9, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 760);
		zephir_array_update_string(&_31$$9, SL("onUpdate"), &_32$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_32$$9);
		zephir_array_fetch_string(&_32$$9, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 762);
		zephir_array_update_string(&_31$$9, SL("onDelete"), &_32$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_30$$9, "__construct", &_33, 64, &name, &_31$$9);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_30$$9, PH_COPY | PH_SEPARATE);
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

