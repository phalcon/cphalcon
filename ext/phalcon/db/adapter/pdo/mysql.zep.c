
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
 *
 * @phpstan-import-type db_dsn_defaults from DbTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Mysql, phalcon, db_adapter_pdo_mysql, phalcon_db_adapter_pdo_abstractpdo_ce, phalcon_db_adapter_pdo_mysql_method_entry, 0);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "mysql", sizeof("mysql") - 1);
		zephir_declare_typed_property(phalcon_db_adapter_pdo_mysql_ce, SL("dialectType"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "mysql", sizeof("mysql") - 1);
		zephir_declare_typed_property(phalcon_db_adapter_pdo_mysql_ce, SL("type"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 610, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "getForeignKeyChecks", NULL, 0);
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
		zephir_throw_exception_debug(&_3$$3, "phalcon/Db/Adapter/Pdo/Mysql.zep", 64);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_0, 610, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_5, &_4, "addForeignKey", NULL, 0, &tableName_zv, &schemaName_zv, reference);
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
	zend_bool isMariaDb, _83, _10$$3, _66$$3, _67$$3, _68$$3, _60$$42, _62$$42, _69$$51, _72$$54, _85$$63, _141$$63, _142$$63, _143$$63, _135$$102, _137$$102, _144$$111, _147$$114;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_75 = NULL, *_81 = NULL, *_155 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, __$true, __$false, columnName, columnType, defaultValue, extraValue, field, fields, generationExpression, matchOne, matchTwo, matches, oldColumn, _0, _1, _2, _3, _4, *_6, _7, *_8, _82, _9$$3, _64$$3, _65$$3, _78$$3, _80$$3, _11$$4, _12$$4, _13$$5, _14$$5, _15$$6, _16$$6, _17$$7, _18$$7, _19$$8, _20$$8, _21$$9, _22$$9, _23$$10, _24$$11, _25$$12, _26$$13, _27$$14, _28$$14, _29$$15, _30$$15, _31$$16, _32$$17, _33$$18, _34$$19, _35$$20, _36$$21, _37$$22, _38$$23, _39$$24, _40$$25, _41$$26, _42$$27, _43$$28, _44$$29, _45$$30, _46$$31, _47$$32, _48$$33, _49$$34, _50$$35, _51$$36, _52$$37, _53$$38, _54$$39, _55$$40, _56$$40, _57$$41, _58$$41, _59$$41, _61$$43, _63$$44, _70$$51, _71$$54, _73$$54, _74$$57, _76$$58, _77$$61, _79$$62, _84$$63, _139$$63, _140$$63, _152$$63, _154$$63, _86$$64, _87$$64, _88$$65, _89$$65, _90$$66, _91$$66, _92$$67, _93$$67, _94$$68, _95$$68, _96$$69, _97$$69, _98$$70, _99$$71, _100$$72, _101$$73, _102$$74, _103$$74, _104$$75, _105$$75, _106$$76, _107$$77, _108$$78, _109$$79, _110$$80, _111$$81, _112$$82, _113$$83, _114$$84, _115$$85, _116$$86, _117$$87, _118$$88, _119$$89, _120$$90, _121$$91, _122$$92, _123$$93, _124$$94, _125$$95, _126$$96, _127$$97, _128$$98, _129$$99, _130$$100, _131$$100, _132$$101, _133$$101, _134$$101, _136$$103, _138$$104, _145$$111, _146$$114, _148$$114, _149$$117, _150$$118, _151$$121, _153$$122;
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
	ZVAL_UNDEF(&_82);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_64$$3);
	ZVAL_UNDEF(&_65$$3);
	ZVAL_UNDEF(&_78$$3);
	ZVAL_UNDEF(&_80$$3);
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
	ZVAL_UNDEF(&_61$$43);
	ZVAL_UNDEF(&_63$$44);
	ZVAL_UNDEF(&_70$$51);
	ZVAL_UNDEF(&_71$$54);
	ZVAL_UNDEF(&_73$$54);
	ZVAL_UNDEF(&_74$$57);
	ZVAL_UNDEF(&_76$$58);
	ZVAL_UNDEF(&_77$$61);
	ZVAL_UNDEF(&_79$$62);
	ZVAL_UNDEF(&_84$$63);
	ZVAL_UNDEF(&_139$$63);
	ZVAL_UNDEF(&_140$$63);
	ZVAL_UNDEF(&_152$$63);
	ZVAL_UNDEF(&_154$$63);
	ZVAL_UNDEF(&_86$$64);
	ZVAL_UNDEF(&_87$$64);
	ZVAL_UNDEF(&_88$$65);
	ZVAL_UNDEF(&_89$$65);
	ZVAL_UNDEF(&_90$$66);
	ZVAL_UNDEF(&_91$$66);
	ZVAL_UNDEF(&_92$$67);
	ZVAL_UNDEF(&_93$$67);
	ZVAL_UNDEF(&_94$$68);
	ZVAL_UNDEF(&_95$$68);
	ZVAL_UNDEF(&_96$$69);
	ZVAL_UNDEF(&_97$$69);
	ZVAL_UNDEF(&_98$$70);
	ZVAL_UNDEF(&_99$$71);
	ZVAL_UNDEF(&_100$$72);
	ZVAL_UNDEF(&_101$$73);
	ZVAL_UNDEF(&_102$$74);
	ZVAL_UNDEF(&_103$$74);
	ZVAL_UNDEF(&_104$$75);
	ZVAL_UNDEF(&_105$$75);
	ZVAL_UNDEF(&_106$$76);
	ZVAL_UNDEF(&_107$$77);
	ZVAL_UNDEF(&_108$$78);
	ZVAL_UNDEF(&_109$$79);
	ZVAL_UNDEF(&_110$$80);
	ZVAL_UNDEF(&_111$$81);
	ZVAL_UNDEF(&_112$$82);
	ZVAL_UNDEF(&_113$$83);
	ZVAL_UNDEF(&_114$$84);
	ZVAL_UNDEF(&_115$$85);
	ZVAL_UNDEF(&_116$$86);
	ZVAL_UNDEF(&_117$$87);
	ZVAL_UNDEF(&_118$$88);
	ZVAL_UNDEF(&_119$$89);
	ZVAL_UNDEF(&_120$$90);
	ZVAL_UNDEF(&_121$$91);
	ZVAL_UNDEF(&_122$$92);
	ZVAL_UNDEF(&_123$$93);
	ZVAL_UNDEF(&_124$$94);
	ZVAL_UNDEF(&_125$$95);
	ZVAL_UNDEF(&_126$$96);
	ZVAL_UNDEF(&_127$$97);
	ZVAL_UNDEF(&_128$$98);
	ZVAL_UNDEF(&_129$$99);
	ZVAL_UNDEF(&_130$$100);
	ZVAL_UNDEF(&_131$$100);
	ZVAL_UNDEF(&_132$$101);
	ZVAL_UNDEF(&_133$$101);
	ZVAL_UNDEF(&_134$$101);
	ZVAL_UNDEF(&_136$$103);
	ZVAL_UNDEF(&_138$$104);
	ZVAL_UNDEF(&_145$$111);
	ZVAL_UNDEF(&_146$$114);
	ZVAL_UNDEF(&_148$$114);
	ZVAL_UNDEF(&_149$$117);
	ZVAL_UNDEF(&_150$$118);
	ZVAL_UNDEF(&_151$$121);
	ZVAL_UNDEF(&_153$$122);
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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 610, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "describeColumns", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "fetchAll", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_1, 611, PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_4, 4);
	ZEPHIR_CALL_METHOD(&_3, &_2, "getAttribute", NULL, 0, &_4);
	zephir_check_call_status();
	zephir_cast_to_string(&_5, &_3);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	isMariaDb = zephir_memnstr_str(&_5, SL("MariaDB"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 110);
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
			zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 139);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
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
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_12$$4);
				ZVAL_LONG(&_12$$4, 2);
				zephir_array_update_string(&definition, SL("bindType"), &_12$$4, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_1: ;
				ZEPHIR_INIT_NVAR(&_13$$5);
				ZVAL_LONG(&_13$$5, 21);
				zephir_array_update_string(&definition, SL("type"), &_13$$5, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_14$$5);
				ZVAL_LONG(&_14$$5, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_14$$5, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_2: ;
				ZEPHIR_INIT_NVAR(&_15$$6);
				ZVAL_LONG(&_15$$6, 22);
				zephir_array_update_string(&definition, SL("type"), &_15$$6, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_16$$6);
				ZVAL_LONG(&_16$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_16$$6, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_INIT_NVAR(&_17$$7);
				ZVAL_LONG(&_17$$7, 26);
				zephir_array_update_string(&definition, SL("type"), &_17$$7, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_18$$7);
				ZVAL_LONG(&_18$$7, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_18$$7, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
				ZEPHIR_INIT_NVAR(&_19$$8);
				ZVAL_LONG(&_19$$8, 0);
				zephir_array_update_string(&definition, SL("type"), &_19$$8, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_20$$8);
				ZVAL_LONG(&_20$$8, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_20$$8, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_5: ;
				ZEPHIR_INIT_NVAR(&_21$$9);
				ZVAL_LONG(&_21$$9, 19);
				zephir_array_update_string(&definition, SL("type"), &_21$$9, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_22$$9);
				ZVAL_LONG(&_22$$9, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_22$$9, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_6: ;
				ZEPHIR_INIT_NVAR(&_23$$10);
				ZVAL_LONG(&_23$$10, 18);
				zephir_array_update_string(&definition, SL("type"), &_23$$10, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_7: ;
				ZEPHIR_INIT_NVAR(&_24$$11);
				ZVAL_LONG(&_24$$11, 4);
				zephir_array_update_string(&definition, SL("type"), &_24$$11, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_8: ;
				ZEPHIR_INIT_NVAR(&_25$$12);
				ZVAL_LONG(&_25$$12, 1);
				zephir_array_update_string(&definition, SL("type"), &_25$$12, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_9: ;
				ZEPHIR_INIT_NVAR(&_26$$13);
				ZVAL_LONG(&_26$$13, 3);
				zephir_array_update_string(&definition, SL("type"), &_26$$13, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_10: ;
				ZEPHIR_INIT_NVAR(&_27$$14);
				ZVAL_LONG(&_27$$14, 9);
				zephir_array_update_string(&definition, SL("type"), &_27$$14, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_28$$14);
				ZVAL_LONG(&_28$$14, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_28$$14, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_11: ;
				ZEPHIR_INIT_NVAR(&_29$$15);
				ZVAL_LONG(&_29$$15, 7);
				zephir_array_update_string(&definition, SL("type"), &_29$$15, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_30$$15);
				ZVAL_LONG(&_30$$15, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_30$$15, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_12: ;
				ZEPHIR_INIT_NVAR(&_31$$16);
				ZVAL_LONG(&_31$$16, 12);
				zephir_array_update_string(&definition, SL("type"), &_31$$16, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_13: ;
				ZEPHIR_INIT_NVAR(&_32$$17);
				ZVAL_LONG(&_32$$17, 13);
				zephir_array_update_string(&definition, SL("type"), &_32$$17, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_14: ;
				ZEPHIR_INIT_NVAR(&_33$$18);
				ZVAL_LONG(&_33$$18, 10);
				zephir_array_update_string(&definition, SL("type"), &_33$$18, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_15: ;
				ZEPHIR_INIT_NVAR(&_34$$19);
				ZVAL_LONG(&_34$$19, 11);
				zephir_array_update_string(&definition, SL("type"), &_34$$19, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_16: ;
				ZEPHIR_INIT_NVAR(&_35$$20);
				ZVAL_LONG(&_35$$20, 17);
				zephir_array_update_string(&definition, SL("type"), &_35$$20, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_17: ;
				ZEPHIR_INIT_NVAR(&_36$$21);
				ZVAL_LONG(&_36$$21, 20);
				zephir_array_update_string(&definition, SL("type"), &_36$$21, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_18: ;
				ZEPHIR_INIT_NVAR(&_37$$22);
				ZVAL_LONG(&_37$$22, 15);
				zephir_array_update_string(&definition, SL("type"), &_37$$22, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_19: ;
				ZEPHIR_INIT_NVAR(&_38$$23);
				ZVAL_LONG(&_38$$23, 24);
				zephir_array_update_string(&definition, SL("type"), &_38$$23, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_20: ;
				ZEPHIR_INIT_NVAR(&_39$$24);
				ZVAL_LONG(&_39$$24, 23);
				zephir_array_update_string(&definition, SL("type"), &_39$$24, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_21: ;
				ZEPHIR_INIT_NVAR(&_40$$25);
				ZVAL_LONG(&_40$$25, 25);
				zephir_array_update_string(&definition, SL("type"), &_40$$25, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_22: ;
				ZEPHIR_INIT_NVAR(&_41$$26);
				ZVAL_LONG(&_41$$26, 6);
				zephir_array_update_string(&definition, SL("type"), &_41$$26, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_23: ;
				ZEPHIR_INIT_NVAR(&_42$$27);
				ZVAL_LONG(&_42$$27, 2);
				zephir_array_update_string(&definition, SL("type"), &_42$$27, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_24: ;
				ZEPHIR_INIT_NVAR(&_43$$28);
				ZVAL_LONG(&_43$$28, 5);
				zephir_array_update_string(&definition, SL("type"), &_43$$28, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_25: ;
				ZEPHIR_INIT_NVAR(&_44$$29);
				ZVAL_LONG(&_44$$29, 28);
				zephir_array_update_string(&definition, SL("type"), &_44$$29, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_26: ;
				ZEPHIR_INIT_NVAR(&_45$$30);
				ZVAL_LONG(&_45$$30, 27);
				zephir_array_update_string(&definition, SL("type"), &_45$$30, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_27: ;
				ZEPHIR_INIT_NVAR(&_46$$31);
				ZVAL_LONG(&_46$$31, 44);
				zephir_array_update_string(&definition, SL("type"), &_46$$31, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_28: ;
				ZEPHIR_INIT_NVAR(&_47$$32);
				ZVAL_LONG(&_47$$32, 45);
				zephir_array_update_string(&definition, SL("type"), &_47$$32, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_29: ;
				ZEPHIR_INIT_NVAR(&_48$$33);
				ZVAL_LONG(&_48$$33, 46);
				zephir_array_update_string(&definition, SL("type"), &_48$$33, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_30: ;
				ZEPHIR_INIT_NVAR(&_49$$34);
				ZVAL_LONG(&_49$$34, 47);
				zephir_array_update_string(&definition, SL("type"), &_49$$34, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_31: ;
				ZEPHIR_INIT_NVAR(&_50$$35);
				ZVAL_LONG(&_50$$35, 42);
				zephir_array_update_string(&definition, SL("type"), &_50$$35, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_32: ;
				ZEPHIR_INIT_NVAR(&_51$$36);
				ZVAL_LONG(&_51$$36, 43);
				zephir_array_update_string(&definition, SL("type"), &_51$$36, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_33: ;
				ZEPHIR_INIT_NVAR(&_52$$37);
				ZVAL_LONG(&_52$$37, 41);
				zephir_array_update_string(&definition, SL("type"), &_52$$37, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_34: ;
				ZEPHIR_INIT_NVAR(&_53$$38);
				ZVAL_LONG(&_53$$38, 40);
				zephir_array_update_string(&definition, SL("type"), &_53$$38, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_35: ;
				ZEPHIR_INIT_NVAR(&_54$$39);
				ZVAL_LONG(&_54$$39, 2);
				zephir_array_update_string(&definition, SL("type"), &_54$$39, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_end: ;

			if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 447)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				zephir_array_fetch_string(&_55$$40, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 450);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&_55$$40, 18)) {
					ZVAL_LONG(&_57$$41, 5);
					ZVAL_LONG(&_58$$41, -1);
					ZEPHIR_INIT_NVAR(&_59$$41);
					zephir_substr(&_59$$41, &columnType, 5 , -1 , 0);
					zephir_array_update_string(&definition, SL("size"), &_59$$41, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_56$$40);
					zephir_preg_match(&_56$$40, &sizePattern, &columnType, &matches, 0, 0 , 0 );
					if (zephir_is_true(&_56$$40)) {
						ZEPHIR_OBS_NVAR(&matchOne);
						_60$$42 = zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_60$$42) {
							ZEPHIR_INIT_NVAR(&_61$$43);
							ZVAL_LONG(&_61$$43, zephir_get_intval(&matchOne));
							zephir_array_update_string(&definition, SL("size"), &_61$$43, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
						ZEPHIR_OBS_NVAR(&matchTwo);
						_62$$42 = zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (_62$$42) {
							ZEPHIR_INIT_NVAR(&_63$$44);
							ZVAL_LONG(&_63$$44, zephir_get_intval(&matchTwo));
							zephir_array_update_string(&definition, SL("scale"), &_63$$44, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				}
			}
			if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 466)) {
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
			ZEPHIR_OBS_NVAR(&_64$$3);
			zephir_array_fetch_long(&_64$$3, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 482);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_STRING(&_64$$3, "PRI")) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&_65$$3);
			zephir_array_fetch_long(&_65$$3, &field, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 489);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_STRING(&_65$$3, "YES")) {
				zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&extraValue);
			zephir_array_fetch_long(&extraValue, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 498);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_66$$3 = Z_TYPE_P(&extraValue) != IS_NULL;
			if (_66$$3) {
				_66$$3 = zephir_memnstr_str(&extraValue, SL("INVISIBLE"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 499);
			}
			if (_66$$3) {
				zephir_array_update_string(&definition, SL("invisible"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			_67$$3 = Z_TYPE_P(&extraValue) != IS_NULL;
			if (_67$$3) {
				_68$$3 = zephir_memnstr_str(&extraValue, SL("VIRTUAL GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 517);
				if (!(_68$$3)) {
					_68$$3 = zephir_memnstr_str(&extraValue, SL("STORED GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 517);
				}
				_67$$3 = _68$$3;
			}
			if (_67$$3) {
				_69$$51 = zephir_array_isset_value_long(&field, 9);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_69$$51) {
					ZEPHIR_OBS_NVAR(&generationExpression);
					zephir_array_fetch_long(&generationExpression, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 519);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&generationExpression);
					ZVAL_STRING(&generationExpression, "");
				}
				zephir_array_update_string(&definition, SL("generated"), &generationExpression, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_70$$51);
				ZVAL_BOOL(&_70$$51, zephir_memnstr_str(&extraValue, SL("STORED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 525));
				zephir_array_update_string(&definition, SL("generationStored"), &_70$$51, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				if (ZEPHIR_IS_STRING(&extraValue, "auto_increment")) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&_71$$54);
				zephir_array_fetch_long(&_71$$54, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 545);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_72$$54 = Z_TYPE_P(&_71$$54) != IS_NULL;
				if (_72$$54) {
					ZEPHIR_OBS_NVAR(&_73$$54);
					zephir_array_fetch_long(&_73$$54, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 545);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_72$$54 = !ZEPHIR_IS_STRING_IDENTICAL(&_73$$54, "NULL");
				}
				if (_72$$54) {
					ZEPHIR_OBS_NVAR(&defaultValue);
					zephir_array_fetch_long(&defaultValue, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 546);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (isMariaDb) {
						ZEPHIR_CALL_METHOD(&_74$$57, this_ptr, "unquoteDefault", &_75, 0, &defaultValue);
						zephir_check_call_status();
						ZEPHIR_CPY_WRT(&defaultValue, &_74$$57);
					}
					if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 552)) {
						ZEPHIR_INIT_NVAR(&_76$$58);
						ZEPHIR_CONCAT_VSV(&_76$$58, &defaultValue, " ", &extraValue);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_string(&definition, SL("default"), &_76$$58, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						zephir_array_update_string(&definition, SL("default"), &defaultValue, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				} else {
					if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 558)) {
						ZEPHIR_INIT_NVAR(&_77$$61);
						ZEPHIR_CONCAT_SV(&_77$$61, "NULL ", &extraValue);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_update_string(&definition, SL("default"), &_77$$61, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			}
			ZEPHIR_OBS_NVAR(&_78$$3);
			zephir_array_fetch_long(&_78$$3, &field, 8, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 571);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&_78$$3) != IS_NULL) {
				ZEPHIR_OBS_NVAR(&_79$$62);
				zephir_array_fetch_long(&_79$$62, &field, 8, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 572);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("comment"), &_79$$62, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&columnName);
			zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 578);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_80$$3);
			object_init_ex(&_80$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_80$$3, "__construct", &_81, 0, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_80$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 579);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _6, "rewind", NULL, 0);
		zephir_check_call_status();
		_83 = 1;
		while (1) {
			if (_83) {
				_83 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _6, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_82, _6, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_82)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, _6, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_84$$63);
				zephir_create_array(&_84$$63, 1, 0);
				add_assoc_long_ex(&_84$$63, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_84$$63);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 139);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_85$$63 = 1;
				if (_85$$63 == zephir_start_with_str(&columnType, SL("bigint"))) { goto zephir_switch_1_clause_0; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("mediumint"))) { goto zephir_switch_1_clause_1; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("smallint"))) { goto zephir_switch_1_clause_2; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("tinyint"))) { goto zephir_switch_1_clause_3; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("int"))) { goto zephir_switch_1_clause_4; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("bit"))) { goto zephir_switch_1_clause_5; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("enum"))) { goto zephir_switch_1_clause_6; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("datetime"))) { goto zephir_switch_1_clause_7; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("date"))) { goto zephir_switch_1_clause_8; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("decimal"))) { goto zephir_switch_1_clause_9; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("double"))) { goto zephir_switch_1_clause_10; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("float"))) { goto zephir_switch_1_clause_11; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("mediumblob"))) { goto zephir_switch_1_clause_12; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("longblob"))) { goto zephir_switch_1_clause_13; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("tinyblob"))) { goto zephir_switch_1_clause_14; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("blob"))) { goto zephir_switch_1_clause_15; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("timestamp"))) { goto zephir_switch_1_clause_16; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("time"))) { goto zephir_switch_1_clause_17; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("json"))) { goto zephir_switch_1_clause_18; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("longtext"))) { goto zephir_switch_1_clause_19; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("mediumtext"))) { goto zephir_switch_1_clause_20; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("tinytext"))) { goto zephir_switch_1_clause_21; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("text"))) { goto zephir_switch_1_clause_22; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("varchar"))) { goto zephir_switch_1_clause_23; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("char"))) { goto zephir_switch_1_clause_24; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("varbinary"))) { goto zephir_switch_1_clause_25; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("binary"))) { goto zephir_switch_1_clause_26; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("multipoint"))) { goto zephir_switch_1_clause_27; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("multilinestring"))) { goto zephir_switch_1_clause_28; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("multipolygon"))) { goto zephir_switch_1_clause_29; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("geometrycollection"))) { goto zephir_switch_1_clause_30; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("linestring"))) { goto zephir_switch_1_clause_31; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("polygon"))) { goto zephir_switch_1_clause_32; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("point"))) { goto zephir_switch_1_clause_33; }
				if (_85$$63 == zephir_start_with_str(&columnType, SL("geometry"))) { goto zephir_switch_1_clause_34; }
				goto zephir_switch_1_clause_35;
				zephir_switch_1_clause_0: ;
					ZEPHIR_INIT_NVAR(&_86$$64);
					ZVAL_LONG(&_86$$64, 14);
					zephir_array_update_string(&definition, SL("type"), &_86$$64, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_87$$64);
					ZVAL_LONG(&_87$$64, 2);
					zephir_array_update_string(&definition, SL("bindType"), &_87$$64, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_1: ;
					ZEPHIR_INIT_NVAR(&_88$$65);
					ZVAL_LONG(&_88$$65, 21);
					zephir_array_update_string(&definition, SL("type"), &_88$$65, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_89$$65);
					ZVAL_LONG(&_89$$65, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_89$$65, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_2: ;
					ZEPHIR_INIT_NVAR(&_90$$66);
					ZVAL_LONG(&_90$$66, 22);
					zephir_array_update_string(&definition, SL("type"), &_90$$66, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_91$$66);
					ZVAL_LONG(&_91$$66, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_91$$66, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_NVAR(&_92$$67);
					ZVAL_LONG(&_92$$67, 26);
					zephir_array_update_string(&definition, SL("type"), &_92$$67, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_93$$67);
					ZVAL_LONG(&_93$$67, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_93$$67, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
					ZEPHIR_INIT_NVAR(&_94$$68);
					ZVAL_LONG(&_94$$68, 0);
					zephir_array_update_string(&definition, SL("type"), &_94$$68, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_95$$68);
					ZVAL_LONG(&_95$$68, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_95$$68, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_5: ;
					ZEPHIR_INIT_NVAR(&_96$$69);
					ZVAL_LONG(&_96$$69, 19);
					zephir_array_update_string(&definition, SL("type"), &_96$$69, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_97$$69);
					ZVAL_LONG(&_97$$69, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_97$$69, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_6: ;
					ZEPHIR_INIT_NVAR(&_98$$70);
					ZVAL_LONG(&_98$$70, 18);
					zephir_array_update_string(&definition, SL("type"), &_98$$70, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_7: ;
					ZEPHIR_INIT_NVAR(&_99$$71);
					ZVAL_LONG(&_99$$71, 4);
					zephir_array_update_string(&definition, SL("type"), &_99$$71, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_8: ;
					ZEPHIR_INIT_NVAR(&_100$$72);
					ZVAL_LONG(&_100$$72, 1);
					zephir_array_update_string(&definition, SL("type"), &_100$$72, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_9: ;
					ZEPHIR_INIT_NVAR(&_101$$73);
					ZVAL_LONG(&_101$$73, 3);
					zephir_array_update_string(&definition, SL("type"), &_101$$73, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_10: ;
					ZEPHIR_INIT_NVAR(&_102$$74);
					ZVAL_LONG(&_102$$74, 9);
					zephir_array_update_string(&definition, SL("type"), &_102$$74, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_103$$74);
					ZVAL_LONG(&_103$$74, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_103$$74, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_11: ;
					ZEPHIR_INIT_NVAR(&_104$$75);
					ZVAL_LONG(&_104$$75, 7);
					zephir_array_update_string(&definition, SL("type"), &_104$$75, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_105$$75);
					ZVAL_LONG(&_105$$75, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_105$$75, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_12: ;
					ZEPHIR_INIT_NVAR(&_106$$76);
					ZVAL_LONG(&_106$$76, 12);
					zephir_array_update_string(&definition, SL("type"), &_106$$76, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_13: ;
					ZEPHIR_INIT_NVAR(&_107$$77);
					ZVAL_LONG(&_107$$77, 13);
					zephir_array_update_string(&definition, SL("type"), &_107$$77, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_14: ;
					ZEPHIR_INIT_NVAR(&_108$$78);
					ZVAL_LONG(&_108$$78, 10);
					zephir_array_update_string(&definition, SL("type"), &_108$$78, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_15: ;
					ZEPHIR_INIT_NVAR(&_109$$79);
					ZVAL_LONG(&_109$$79, 11);
					zephir_array_update_string(&definition, SL("type"), &_109$$79, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_16: ;
					ZEPHIR_INIT_NVAR(&_110$$80);
					ZVAL_LONG(&_110$$80, 17);
					zephir_array_update_string(&definition, SL("type"), &_110$$80, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_17: ;
					ZEPHIR_INIT_NVAR(&_111$$81);
					ZVAL_LONG(&_111$$81, 20);
					zephir_array_update_string(&definition, SL("type"), &_111$$81, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_18: ;
					ZEPHIR_INIT_NVAR(&_112$$82);
					ZVAL_LONG(&_112$$82, 15);
					zephir_array_update_string(&definition, SL("type"), &_112$$82, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_19: ;
					ZEPHIR_INIT_NVAR(&_113$$83);
					ZVAL_LONG(&_113$$83, 24);
					zephir_array_update_string(&definition, SL("type"), &_113$$83, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_20: ;
					ZEPHIR_INIT_NVAR(&_114$$84);
					ZVAL_LONG(&_114$$84, 23);
					zephir_array_update_string(&definition, SL("type"), &_114$$84, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_21: ;
					ZEPHIR_INIT_NVAR(&_115$$85);
					ZVAL_LONG(&_115$$85, 25);
					zephir_array_update_string(&definition, SL("type"), &_115$$85, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_22: ;
					ZEPHIR_INIT_NVAR(&_116$$86);
					ZVAL_LONG(&_116$$86, 6);
					zephir_array_update_string(&definition, SL("type"), &_116$$86, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_23: ;
					ZEPHIR_INIT_NVAR(&_117$$87);
					ZVAL_LONG(&_117$$87, 2);
					zephir_array_update_string(&definition, SL("type"), &_117$$87, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_24: ;
					ZEPHIR_INIT_NVAR(&_118$$88);
					ZVAL_LONG(&_118$$88, 5);
					zephir_array_update_string(&definition, SL("type"), &_118$$88, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_25: ;
					ZEPHIR_INIT_NVAR(&_119$$89);
					ZVAL_LONG(&_119$$89, 28);
					zephir_array_update_string(&definition, SL("type"), &_119$$89, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_26: ;
					ZEPHIR_INIT_NVAR(&_120$$90);
					ZVAL_LONG(&_120$$90, 27);
					zephir_array_update_string(&definition, SL("type"), &_120$$90, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_27: ;
					ZEPHIR_INIT_NVAR(&_121$$91);
					ZVAL_LONG(&_121$$91, 44);
					zephir_array_update_string(&definition, SL("type"), &_121$$91, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_28: ;
					ZEPHIR_INIT_NVAR(&_122$$92);
					ZVAL_LONG(&_122$$92, 45);
					zephir_array_update_string(&definition, SL("type"), &_122$$92, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_29: ;
					ZEPHIR_INIT_NVAR(&_123$$93);
					ZVAL_LONG(&_123$$93, 46);
					zephir_array_update_string(&definition, SL("type"), &_123$$93, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_30: ;
					ZEPHIR_INIT_NVAR(&_124$$94);
					ZVAL_LONG(&_124$$94, 47);
					zephir_array_update_string(&definition, SL("type"), &_124$$94, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_31: ;
					ZEPHIR_INIT_NVAR(&_125$$95);
					ZVAL_LONG(&_125$$95, 42);
					zephir_array_update_string(&definition, SL("type"), &_125$$95, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_32: ;
					ZEPHIR_INIT_NVAR(&_126$$96);
					ZVAL_LONG(&_126$$96, 43);
					zephir_array_update_string(&definition, SL("type"), &_126$$96, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_33: ;
					ZEPHIR_INIT_NVAR(&_127$$97);
					ZVAL_LONG(&_127$$97, 41);
					zephir_array_update_string(&definition, SL("type"), &_127$$97, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_34: ;
					ZEPHIR_INIT_NVAR(&_128$$98);
					ZVAL_LONG(&_128$$98, 40);
					zephir_array_update_string(&definition, SL("type"), &_128$$98, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_35: ;
					ZEPHIR_INIT_NVAR(&_129$$99);
					ZVAL_LONG(&_129$$99, 2);
					zephir_array_update_string(&definition, SL("type"), &_129$$99, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_end: ;

				if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 447)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					zephir_array_fetch_string(&_130$$100, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 450);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (ZEPHIR_IS_LONG(&_130$$100, 18)) {
						ZVAL_LONG(&_132$$101, 5);
						ZVAL_LONG(&_133$$101, -1);
						ZEPHIR_INIT_NVAR(&_134$$101);
						zephir_substr(&_134$$101, &columnType, 5 , -1 , 0);
						zephir_array_update_string(&definition, SL("size"), &_134$$101, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_131$$100);
						zephir_preg_match(&_131$$100, &sizePattern, &columnType, &matches, 0, 0 , 0 );
						if (zephir_is_true(&_131$$100)) {
							ZEPHIR_OBS_NVAR(&matchOne);
							_135$$102 = zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_135$$102) {
								ZEPHIR_INIT_NVAR(&_136$$103);
								ZVAL_LONG(&_136$$103, zephir_get_intval(&matchOne));
								zephir_array_update_string(&definition, SL("size"), &_136$$103, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
							ZEPHIR_OBS_NVAR(&matchTwo);
							_137$$102 = zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							if (_137$$102) {
								ZEPHIR_INIT_NVAR(&_138$$104);
								ZVAL_LONG(&_138$$104, zephir_get_intval(&matchTwo));
								zephir_array_update_string(&definition, SL("scale"), &_138$$104, PH_COPY | PH_SEPARATE);
								if (UNEXPECTED(EG(exception))) {
									ZEPHIR_MM_RESTORE();
									return;
								}
							}
						}
					}
				}
				if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 466)) {
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
				ZEPHIR_OBS_NVAR(&_139$$63);
				zephir_array_fetch_long(&_139$$63, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 482);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_STRING(&_139$$63, "PRI")) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&_140$$63);
				zephir_array_fetch_long(&_140$$63, &field, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 489);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_STRING(&_140$$63, "YES")) {
					zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&extraValue);
				zephir_array_fetch_long(&extraValue, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 498);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_141$$63 = Z_TYPE_P(&extraValue) != IS_NULL;
				if (_141$$63) {
					_141$$63 = zephir_memnstr_str(&extraValue, SL("INVISIBLE"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 499);
				}
				if (_141$$63) {
					zephir_array_update_string(&definition, SL("invisible"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				_142$$63 = Z_TYPE_P(&extraValue) != IS_NULL;
				if (_142$$63) {
					_143$$63 = zephir_memnstr_str(&extraValue, SL("VIRTUAL GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 517);
					if (!(_143$$63)) {
						_143$$63 = zephir_memnstr_str(&extraValue, SL("STORED GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 517);
					}
					_142$$63 = _143$$63;
				}
				if (_142$$63) {
					_144$$111 = zephir_array_isset_value_long(&field, 9);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (_144$$111) {
						ZEPHIR_OBS_NVAR(&generationExpression);
						zephir_array_fetch_long(&generationExpression, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 519);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&generationExpression);
						ZVAL_STRING(&generationExpression, "");
					}
					zephir_array_update_string(&definition, SL("generated"), &generationExpression, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_145$$111);
					ZVAL_BOOL(&_145$$111, zephir_memnstr_str(&extraValue, SL("STORED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 525));
					zephir_array_update_string(&definition, SL("generationStored"), &_145$$111, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					if (ZEPHIR_IS_STRING(&extraValue, "auto_increment")) {
						zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_OBS_NVAR(&_146$$114);
					zephir_array_fetch_long(&_146$$114, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 545);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_147$$114 = Z_TYPE_P(&_146$$114) != IS_NULL;
					if (_147$$114) {
						ZEPHIR_OBS_NVAR(&_148$$114);
						zephir_array_fetch_long(&_148$$114, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 545);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_147$$114 = !ZEPHIR_IS_STRING_IDENTICAL(&_148$$114, "NULL");
					}
					if (_147$$114) {
						ZEPHIR_OBS_NVAR(&defaultValue);
						zephir_array_fetch_long(&defaultValue, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 546);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						if (isMariaDb) {
							ZEPHIR_CALL_METHOD(&_149$$117, this_ptr, "unquoteDefault", &_75, 0, &defaultValue);
							zephir_check_call_status();
							ZEPHIR_CPY_WRT(&defaultValue, &_149$$117);
						}
						if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 552)) {
							ZEPHIR_INIT_NVAR(&_150$$118);
							ZEPHIR_CONCAT_VSV(&_150$$118, &defaultValue, " ", &extraValue);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_string(&definition, SL("default"), &_150$$118, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						} else {
							zephir_array_update_string(&definition, SL("default"), &defaultValue, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					} else {
						if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 558)) {
							ZEPHIR_INIT_NVAR(&_151$$121);
							ZEPHIR_CONCAT_SV(&_151$$121, "NULL ", &extraValue);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
							zephir_array_update_string(&definition, SL("default"), &_151$$121, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				}
				ZEPHIR_OBS_NVAR(&_152$$63);
				zephir_array_fetch_long(&_152$$63, &field, 8, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 571);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&_152$$63) != IS_NULL) {
					ZEPHIR_OBS_NVAR(&_153$$122);
					zephir_array_fetch_long(&_153$$122, &field, 8, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 572);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("comment"), &_153$$122, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 578);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_154$$63);
				object_init_ex(&_154$$63, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_154$$63, "__construct", &_155, 0, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_154$$63, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 579);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
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
	zval _20$$9, _46$$23;
	zend_ulong _58;
	zval indexes, indexObjects, _68$$31;
	zend_bool invisible = 0, anyDirection = 0, _32, _7$$3, _10$$3, _14$$3, _16$$3, _17$$3, _28$$3, _29$$3, _33$$17, _36$$17, _40$$17, _42$$17, _43$$17, _54$$17, _55$$17, _60$$31, _66$$31;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_71 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, __$true, columns, index, keyName, indexType, name, directions, collation, _0, _1, _2, _3, *_4, _5, *_6, _31, *_57, _9$$3, _12$$3, _13$$3, _18$$3, _23$$3, _30$$3, _8$$4, _11$$6, _15$$8, _19$$9, _21$$10, _22$$11, _24$$12, _25$$13, _26$$14, _27$$15, _35$$17, _38$$17, _39$$17, _44$$17, _49$$17, _56$$17, _34$$18, _37$$20, _41$$22, _45$$23, _47$$24, _48$$25, _50$$26, _51$$27, _52$$28, _53$$29, *_62$$31, _63$$31, *_64$$31, _65$$31, _67$$31, _69$$31, _70$$31, _61$$32;
	zend_string *table = NULL, *schema = NULL, *_59;
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
	ZVAL_UNDEF(&_31);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_23$$3);
	ZVAL_UNDEF(&_30$$3);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_19$$9);
	ZVAL_UNDEF(&_21$$10);
	ZVAL_UNDEF(&_22$$11);
	ZVAL_UNDEF(&_24$$12);
	ZVAL_UNDEF(&_25$$13);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_35$$17);
	ZVAL_UNDEF(&_38$$17);
	ZVAL_UNDEF(&_39$$17);
	ZVAL_UNDEF(&_44$$17);
	ZVAL_UNDEF(&_49$$17);
	ZVAL_UNDEF(&_56$$17);
	ZVAL_UNDEF(&_34$$18);
	ZVAL_UNDEF(&_37$$20);
	ZVAL_UNDEF(&_41$$22);
	ZVAL_UNDEF(&_45$$23);
	ZVAL_UNDEF(&_47$$24);
	ZVAL_UNDEF(&_48$$25);
	ZVAL_UNDEF(&_50$$26);
	ZVAL_UNDEF(&_51$$27);
	ZVAL_UNDEF(&_52$$28);
	ZVAL_UNDEF(&_53$$29);
	ZVAL_UNDEF(&_63$$31);
	ZVAL_UNDEF(&_65$$31);
	ZVAL_UNDEF(&_67$$31);
	ZVAL_UNDEF(&_69$$31);
	ZVAL_UNDEF(&_70$$31);
	ZVAL_UNDEF(&_61$$32);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&indexObjects);
	ZVAL_UNDEF(&_68$$31);
	ZVAL_UNDEF(&_20$$9);
	ZVAL_UNDEF(&_46$$23);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 610, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeIndexes", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchAll", NULL, 0, &_2, &_3);
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
			ZEPHIR_OBS_NVAR(&keyName);
			zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 603);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&indexType);
			zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 604);
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
			zephir_array_fetch(&_9$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 610);
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
				zephir_array_fetch(&_11$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 613);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_11$$6, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 613);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&_12$$3);
			zephir_array_fetch_string(&_12$$3, &index, SL("Column_name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 616);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&columns, &_12$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 616);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_fetch(&_13$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 625);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_14$$3 = zephir_array_isset_value_string(&_13$$3, SL("directions"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_14$$3)) {
				ZEPHIR_INIT_NVAR(&directions);
				array_init(&directions);
			} else {
				zephir_array_fetch(&_15$$8, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 628);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&directions);
				zephir_array_fetch_string(&directions, &_15$$8, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 628);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_INIT_NVAR(&collation);
			ZVAL_STRING(&collation, "");
			_16$$3 = zephir_array_isset_value_string(&index, SL("Collation"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_17$$3 = _16$$3;
			if (_17$$3) {
				ZEPHIR_OBS_NVAR(&_18$$3);
				zephir_array_fetch_string(&_18$$3, &index, SL("Collation"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 632);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_17$$3 = Z_TYPE_P(&_18$$3) != IS_NULL;
			}
			if (_17$$3) {
				ZEPHIR_OBS_NVAR(&_19$$9);
				zephir_array_fetch_string(&_19$$9, &index, SL("Collation"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 633);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_cast_to_string(&_20$$9, &_19$$9);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_CPY_WRT(&collation, &_20$$9);
			}
			if (ZEPHIR_IS_STRING(&collation, "D")) {
				ZEPHIR_INIT_NVAR(&_21$$10);
				ZVAL_STRING(&_21$$10, "DESC");
				zephir_array_append(&directions, &_21$$10, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 637);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_INIT_NVAR(&_22$$11);
				ZVAL_STRING(&_22$$11, "ASC");
				zephir_array_append(&directions, &_22$$11, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 639);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			zephir_array_update_multi(&indexes, &directions, SL("zs"), 3, &keyName, SL("directions"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
				ZEPHIR_INIT_NVAR(&_24$$12);
				ZVAL_STRING(&_24$$12, "PRIMARY");
				zephir_array_update_multi(&indexes, &_24$$12, SL("zs"), 3, &keyName, SL("type"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
				ZEPHIR_INIT_NVAR(&_25$$13);
				ZVAL_STRING(&_25$$13, "FULLTEXT");
				zephir_array_update_multi(&indexes, &_25$$13, SL("zs"), 3, &keyName, SL("type"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_OBS_NVAR(&_23$$3);
				zephir_array_fetch_string(&_23$$3, &index, SL("Non_unique"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 648);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_LONG(&_23$$3, 0)) {
					ZEPHIR_INIT_NVAR(&_26$$14);
					ZVAL_STRING(&_26$$14, "UNIQUE");
					zephir_array_update_multi(&indexes, &_26$$14, SL("zs"), 3, &keyName, SL("type"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_27$$15);
					ZVAL_STRING(&_27$$15, "");
					zephir_array_update_multi(&indexes, &_27$$15, SL("zs"), 3, &keyName, SL("type"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
			}
			_28$$3 = zephir_array_isset_value_string(&index, SL("Visible"));
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_29$$3 = _28$$3;
			if (_29$$3) {
				ZEPHIR_OBS_NVAR(&_30$$3);
				zephir_array_fetch_string(&_30$$3, &index, SL("Visible"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 659);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_29$$3 = ZEPHIR_IS_STRING(&_30$$3, "NO");
			}
			if (_29$$3) {
				zephir_array_update_multi(&indexes, &__$true, SL("zs"), 3, &keyName, SL("invisible"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_32 = 1;
		while (1) {
			if (_32) {
				_32 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_31, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_31)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&index, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&keyName);
				zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 603);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&indexType);
				zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 604);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_33$$17 = zephir_array_isset_value(&indexes, &keyName);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_33$$17)) {
					ZEPHIR_INIT_NVAR(&_34$$18);
					array_init(&_34$$18);
					zephir_array_update_zval(&indexes, &keyName, &_34$$18, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_fetch(&_35$$17, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 610);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_36$$17 = zephir_array_isset_value_string(&_35$$17, SL("columns"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_36$$17)) {
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
				} else {
					zephir_array_fetch(&_37$$20, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 613);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_37$$20, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 613);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&_38$$17);
				zephir_array_fetch_string(&_38$$17, &index, SL("Column_name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 616);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&columns, &_38$$17, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 616);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_39$$17, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 625);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_40$$17 = zephir_array_isset_value_string(&_39$$17, SL("directions"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (!(_40$$17)) {
					ZEPHIR_INIT_NVAR(&directions);
					array_init(&directions);
				} else {
					zephir_array_fetch(&_41$$22, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 628);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&directions);
					zephir_array_fetch_string(&directions, &_41$$22, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 628);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_INIT_NVAR(&collation);
				ZVAL_STRING(&collation, "");
				_42$$17 = zephir_array_isset_value_string(&index, SL("Collation"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_43$$17 = _42$$17;
				if (_43$$17) {
					ZEPHIR_OBS_NVAR(&_44$$17);
					zephir_array_fetch_string(&_44$$17, &index, SL("Collation"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 632);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_43$$17 = Z_TYPE_P(&_44$$17) != IS_NULL;
				}
				if (_43$$17) {
					ZEPHIR_OBS_NVAR(&_45$$23);
					zephir_array_fetch_string(&_45$$23, &index, SL("Collation"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 633);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_cast_to_string(&_46$$23, &_45$$23);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_CPY_WRT(&collation, &_46$$23);
				}
				if (ZEPHIR_IS_STRING(&collation, "D")) {
					ZEPHIR_INIT_NVAR(&_47$$24);
					ZVAL_STRING(&_47$$24, "DESC");
					zephir_array_append(&directions, &_47$$24, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 637);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_INIT_NVAR(&_48$$25);
					ZVAL_STRING(&_48$$25, "ASC");
					zephir_array_append(&directions, &_48$$25, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 639);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				zephir_array_update_multi(&indexes, &directions, SL("zs"), 3, &keyName, SL("directions"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
					ZEPHIR_INIT_NVAR(&_50$$26);
					ZVAL_STRING(&_50$$26, "PRIMARY");
					zephir_array_update_multi(&indexes, &_50$$26, SL("zs"), 3, &keyName, SL("type"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
					ZEPHIR_INIT_NVAR(&_51$$27);
					ZVAL_STRING(&_51$$27, "FULLTEXT");
					zephir_array_update_multi(&indexes, &_51$$27, SL("zs"), 3, &keyName, SL("type"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_OBS_NVAR(&_49$$17);
					zephir_array_fetch_string(&_49$$17, &index, SL("Non_unique"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 648);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (ZEPHIR_IS_LONG(&_49$$17, 0)) {
						ZEPHIR_INIT_NVAR(&_52$$28);
						ZVAL_STRING(&_52$$28, "UNIQUE");
						zephir_array_update_multi(&indexes, &_52$$28, SL("zs"), 3, &keyName, SL("type"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					} else {
						ZEPHIR_INIT_NVAR(&_53$$29);
						ZVAL_STRING(&_53$$29, "");
						zephir_array_update_multi(&indexes, &_53$$29, SL("zs"), 3, &keyName, SL("type"));
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
				_54$$17 = zephir_array_isset_value_string(&index, SL("Visible"));
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_55$$17 = _54$$17;
				if (_55$$17) {
					ZEPHIR_OBS_NVAR(&_56$$17);
					zephir_array_fetch_string(&_56$$17, &index, SL("Visible"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 659);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_55$$17 = ZEPHIR_IS_STRING(&_56$$17, "NO");
				}
				if (_55$$17) {
					zephir_array_update_multi(&indexes, &__$true, SL("zs"), 3, &keyName, SL("invisible"));
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	zephir_is_iterable(&indexes, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 699);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&indexes), _58, _59, _57)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_59 != NULL) { 
			ZVAL_STR_COPY(&name, _59);
		} else {
			ZVAL_LONG(&name, _58);
		}
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_COPY(&index, _57);
		invisible = 0;
		_60$$31 = zephir_array_isset_value_string(&index, SL("invisible"));
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		if (_60$$31) {
			ZEPHIR_OBS_NVAR(&_61$$32);
			zephir_array_fetch_string(&_61$$32, &index, SL("invisible"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 667);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			invisible = zephir_get_boolval(&_61$$32);
		}
		ZEPHIR_OBS_NVAR(&directions);
		zephir_array_fetch_string(&directions, &index, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 675);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		anyDirection = 0;
		if (Z_TYPE_P(&directions) == IS_STRING) {
			ZEPHIR_INIT_NVAR(&_63$$31);
			zephir_string_to_char_array(&_63$$31, &directions);
			_62$$31 = &_63$$31;
		} else {
			_62$$31 = &directions;
		}
		zephir_is_iterable(_62$$31, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 684);
		if (Z_TYPE_P(_62$$31) == IS_ARRAY) {
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_62$$31), _64$$31)
			{
				ZEPHIR_INIT_NVAR(&collation);
				ZVAL_COPY(&collation, _64$$31);
				if (ZEPHIR_IS_STRING(&collation, "DESC")) {
					anyDirection = 1;
					break;
				}
			} ZEND_HASH_FOREACH_END();
		} else {
			ZEPHIR_CALL_METHOD(NULL, _62$$31, "rewind", NULL, 0);
			zephir_check_call_status();
			_66$$31 = 1;
			while (1) {
				if (_66$$31) {
					_66$$31 = 0;
				} else {
					ZEPHIR_CALL_METHOD(NULL, _62$$31, "next", NULL, 0);
					zephir_check_call_status();
				}
				ZEPHIR_CALL_METHOD(&_65$$31, _62$$31, "valid", NULL, 0);
				zephir_check_call_status();
				if (!zend_is_true(&_65$$31)) {
					break;
				}
				ZEPHIR_CALL_METHOD(&collation, _62$$31, "current", NULL, 0);
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
		ZEPHIR_INIT_NVAR(&_67$$31);
		object_init_ex(&_67$$31, phalcon_db_index_ce);
		ZEPHIR_INIT_NVAR(&_68$$31);
		zephir_create_array(&_68$$31, 4, 0);
		ZEPHIR_OBS_NVAR(&_69$$31);
		zephir_array_fetch_string(&_69$$31, &index, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 691);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_68$$31, SL("columns"), &_69$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_69$$31);
		zephir_array_fetch_string(&_69$$31, &index, SL("type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 692);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_68$$31, SL("type"), &_69$$31, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_NVAR(&_70$$31);
		ZVAL_BOOL(&_70$$31, invisible);
		zephir_array_update_string(&_68$$31, SL("invisible"), &_70$$31, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_68$$31, SL("directions"), &directions, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_67$$31, "__construct", &_71, 60, &name, &_68$$31);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, &name, &_67$$31, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
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
	zend_ulong _30;
	zend_bool _18, _7$$3, _19$$6;
	zval references, referenceObjects, _16$$3, _28$$6, _33$$9;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_35 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, arrayReference, columns, constraintName, name, reference, referenceDelete, referenceUpdate, referencedColumns, referencedSchema, referencedTable, _0, _1, _2, _3, *_4, _5, *_6, _17, *_29, _14$$3, _15$$3, _8$$5, _9$$5, _10$$5, _11$$5, _12$$5, _13$$5, _26$$6, _27$$6, _20$$8, _21$$8, _22$$8, _23$$8, _24$$8, _25$$8, _32$$9, _34$$9;
	zend_string *table = NULL, *schema = NULL, *_31;
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
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_14$$3);
	ZVAL_UNDEF(&_15$$3);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$5);
	ZVAL_UNDEF(&_13$$5);
	ZVAL_UNDEF(&_26$$6);
	ZVAL_UNDEF(&_27$$6);
	ZVAL_UNDEF(&_20$$8);
	ZVAL_UNDEF(&_21$$8);
	ZVAL_UNDEF(&_22$$8);
	ZVAL_UNDEF(&_23$$8);
	ZVAL_UNDEF(&_24$$8);
	ZVAL_UNDEF(&_25$$8);
	ZVAL_UNDEF(&_32$$9);
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&references);
	ZVAL_UNDEF(&referenceObjects);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_33$$9);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 610, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeReferences", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchAll", NULL, 0, &_2, &_3);
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
			ZEPHIR_OBS_NVAR(&constraintName);
			zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 721);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_7$$3 = zephir_array_isset_value(&references, &constraintName);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (!(_7$$3)) {
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 724);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 725);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 726);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 727);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_8$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 732);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_9$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 732);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 733);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_10$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 733);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_11$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 734);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_11$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 734);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_12$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_string(&referenceUpdate, &_12$$5, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_13$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 736);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_string(&referenceDelete, &_13$$5, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 736);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&_14$$3);
			zephir_array_fetch_long(&_14$$3, &reference, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 739);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&columns, &_14$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 739);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_15$$3);
			zephir_array_fetch_long(&_15$$3, &reference, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 740);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&referencedColumns, &_15$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 740);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_16$$3);
			zephir_create_array(&_16$$3, 6, 0);
			zephir_array_update_string(&_16$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$3, SL("onUpdate"), &referenceUpdate, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_16$$3, SL("onDelete"), &referenceDelete, PH_COPY | PH_SEPARATE);
			zephir_array_update_zval(&references, &constraintName, &_16$$3, PH_COPY | PH_SEPARATE);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _4, "rewind", NULL, 0);
		zephir_check_call_status();
		_18 = 1;
		while (1) {
			if (_18) {
				_18 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _4, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_17, _4, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_17)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&reference, _4, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_OBS_NVAR(&constraintName);
				zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 721);
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
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 724);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 725);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 726);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 727);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_20$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_21$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 732);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_21$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 732);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_22$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 733);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_22$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 733);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_23$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 734);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_23$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 734);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_24$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_string(&referenceUpdate, &_24$$8, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_25$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 736);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_string(&referenceDelete, &_25$$8, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 736);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&_26$$6);
				zephir_array_fetch_long(&_26$$6, &reference, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 739);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&columns, &_26$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 739);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_27$$6);
				zephir_array_fetch_long(&_27$$6, &reference, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 740);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&referencedColumns, &_27$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 740);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_28$$6);
				zephir_create_array(&_28$$6, 6, 0);
				zephir_array_update_string(&_28$$6, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_28$$6, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_28$$6, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_28$$6, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_28$$6, SL("onUpdate"), &referenceUpdate, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_28$$6, SL("onDelete"), &referenceDelete, PH_COPY | PH_SEPARATE);
				zephir_array_update_zval(&references, &constraintName, &_28$$6, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
		}
	}
	ZEPHIR_INIT_NVAR(&reference);
	zephir_is_iterable(&references, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 766);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&references), _30, _31, _29)
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
		zephir_create_array(&_33$$9, 6, 0);
		ZEPHIR_OBS_NVAR(&_34$$9);
		zephir_array_fetch_string(&_34$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 756);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_33$$9, SL("referencedSchema"), &_34$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_34$$9);
		zephir_array_fetch_string(&_34$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 757);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_33$$9, SL("referencedTable"), &_34$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_34$$9);
		zephir_array_fetch_string(&_34$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 758);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_33$$9, SL("columns"), &_34$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_34$$9);
		zephir_array_fetch_string(&_34$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 759);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_33$$9, SL("referencedColumns"), &_34$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_34$$9);
		zephir_array_fetch_string(&_34$$9, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 760);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_33$$9, SL("onUpdate"), &_34$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_34$$9);
		zephir_array_fetch_string(&_34$$9, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 762);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_33$$9, SL("onDelete"), &_34$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_32$$9, "__construct", &_35, 61, &name, &_33$$9);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_32$$9, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CTOR(&referenceObjects);
}

/**
 * Returns PDO adapter DSN defaults as a key-value map.
 *
 * @phpstan-return db_dsn_defaults
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
	zend_bool _1, _2, _5, _4$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS, driverCode = 0;
	zval *exception, exception_sub, errorInfo, message, _0, _3$$3;

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&errorInfo);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3$$3);
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
		_2 = zephir_array_isset_value_long(&errorInfo, 1);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_1 = _2;
	}
	if (_1) {
		zephir_memory_observe(&_3$$3);
		zephir_array_fetch_long(&_3$$3, &errorInfo, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 792);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		driverCode = zephir_get_intval(&_3$$3);
		_4$$3 = driverCode == 2006;
		if (!(_4$$3)) {
			_4$$3 = driverCode == 2013;
		}
		if (_4$$3) {
			RETURN_MM_BOOL(1);
		}
	}
	ZEPHIR_CALL_METHOD(&message, exception, "getMessage", NULL, 0);
	zephir_check_call_status();
	_5 = zephir_memnstr_str(&message, SL("server has gone away"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 801);
	if (!(_5)) {
		_5 = zephir_memnstr_str(&message, SL("Lost connection"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 802);
	}
	RETURN_MM_BOOL(_5);
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

