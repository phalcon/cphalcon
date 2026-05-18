
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
	zval tableName_zv, schemaName_zv, *reference, reference_sub, foreignKeyCheck, _0, _1, _2, _3, _4;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&reference_sub);
	ZVAL_UNDEF(&foreignKeyCheck);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
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
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "DATABASE PARAMETER 'FOREIGN_KEY_CHECKS' HAS TO BE 1", "phalcon/Db/Adapter/Pdo/Mysql.zep", 66);
		return;
	}
	zephir_read_property(&_3, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_4, &_3, "addforeignkey", NULL, 0, &tableName_zv, &schemaName_zv, reference);
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns)
{
	zend_bool _5$$3, _59$$3, _60$$3, _61$$3, _73$$62, _127$$62, _128$$62, _129$$62;
	zval definition;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_71 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, __$true, __$false, columns, columnType, fields, field, oldColumn, sizePattern, matches, matchOne, matchTwo, columnName, extraValue, generationExpression, _0, _1, _2, *_3, _4, _57$$3, _58$$3, _68$$3, _70$$3, _6$$4, _7$$4, _8$$5, _9$$5, _10$$6, _11$$6, _12$$7, _13$$7, _14$$8, _15$$8, _16$$9, _17$$9, _18$$10, _19$$11, _20$$12, _21$$13, _22$$14, _23$$14, _24$$15, _25$$15, _26$$16, _27$$17, _28$$18, _29$$19, _30$$20, _31$$21, _32$$22, _33$$23, _34$$24, _35$$25, _36$$26, _37$$27, _38$$28, _39$$29, _40$$30, _41$$31, _42$$32, _43$$33, _44$$34, _45$$35, _46$$36, _47$$37, _48$$38, _49$$39, _50$$40, _51$$40, _52$$41, _53$$41, _54$$41, _55$$43, _56$$44, _62$$51, _63$$54, _64$$57, _65$$57, _66$$58, _67$$60, _69$$61, _72$$62, _125$$62, _126$$62, _136$$62, _138$$62, _74$$63, _75$$63, _76$$64, _77$$64, _78$$65, _79$$65, _80$$66, _81$$66, _82$$67, _83$$67, _84$$68, _85$$68, _86$$69, _87$$70, _88$$71, _89$$72, _90$$73, _91$$73, _92$$74, _93$$74, _94$$75, _95$$76, _96$$77, _97$$78, _98$$79, _99$$80, _100$$81, _101$$82, _102$$83, _103$$84, _104$$85, _105$$86, _106$$87, _107$$88, _108$$89, _109$$90, _110$$91, _111$$92, _112$$93, _113$$94, _114$$95, _115$$96, _116$$97, _117$$98, _118$$99, _119$$99, _120$$100, _121$$100, _122$$100, _123$$102, _124$$103, _130$$110, _131$$113, _132$$116, _133$$116, _134$$117, _135$$119, _137$$120;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_57$$3);
	ZVAL_UNDEF(&_58$$3);
	ZVAL_UNDEF(&_68$$3);
	ZVAL_UNDEF(&_70$$3);
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
	ZVAL_UNDEF(&_41$$31);
	ZVAL_UNDEF(&_42$$32);
	ZVAL_UNDEF(&_43$$33);
	ZVAL_UNDEF(&_44$$34);
	ZVAL_UNDEF(&_45$$35);
	ZVAL_UNDEF(&_46$$36);
	ZVAL_UNDEF(&_47$$37);
	ZVAL_UNDEF(&_48$$38);
	ZVAL_UNDEF(&_49$$39);
	ZVAL_UNDEF(&_50$$40);
	ZVAL_UNDEF(&_51$$40);
	ZVAL_UNDEF(&_52$$41);
	ZVAL_UNDEF(&_53$$41);
	ZVAL_UNDEF(&_54$$41);
	ZVAL_UNDEF(&_55$$43);
	ZVAL_UNDEF(&_56$$44);
	ZVAL_UNDEF(&_62$$51);
	ZVAL_UNDEF(&_63$$54);
	ZVAL_UNDEF(&_64$$57);
	ZVAL_UNDEF(&_65$$57);
	ZVAL_UNDEF(&_66$$58);
	ZVAL_UNDEF(&_67$$60);
	ZVAL_UNDEF(&_69$$61);
	ZVAL_UNDEF(&_72$$62);
	ZVAL_UNDEF(&_125$$62);
	ZVAL_UNDEF(&_126$$62);
	ZVAL_UNDEF(&_136$$62);
	ZVAL_UNDEF(&_138$$62);
	ZVAL_UNDEF(&_74$$63);
	ZVAL_UNDEF(&_75$$63);
	ZVAL_UNDEF(&_76$$64);
	ZVAL_UNDEF(&_77$$64);
	ZVAL_UNDEF(&_78$$65);
	ZVAL_UNDEF(&_79$$65);
	ZVAL_UNDEF(&_80$$66);
	ZVAL_UNDEF(&_81$$66);
	ZVAL_UNDEF(&_82$$67);
	ZVAL_UNDEF(&_83$$67);
	ZVAL_UNDEF(&_84$$68);
	ZVAL_UNDEF(&_85$$68);
	ZVAL_UNDEF(&_86$$69);
	ZVAL_UNDEF(&_87$$70);
	ZVAL_UNDEF(&_88$$71);
	ZVAL_UNDEF(&_89$$72);
	ZVAL_UNDEF(&_90$$73);
	ZVAL_UNDEF(&_91$$73);
	ZVAL_UNDEF(&_92$$74);
	ZVAL_UNDEF(&_93$$74);
	ZVAL_UNDEF(&_94$$75);
	ZVAL_UNDEF(&_95$$76);
	ZVAL_UNDEF(&_96$$77);
	ZVAL_UNDEF(&_97$$78);
	ZVAL_UNDEF(&_98$$79);
	ZVAL_UNDEF(&_99$$80);
	ZVAL_UNDEF(&_100$$81);
	ZVAL_UNDEF(&_101$$82);
	ZVAL_UNDEF(&_102$$83);
	ZVAL_UNDEF(&_103$$84);
	ZVAL_UNDEF(&_104$$85);
	ZVAL_UNDEF(&_105$$86);
	ZVAL_UNDEF(&_106$$87);
	ZVAL_UNDEF(&_107$$88);
	ZVAL_UNDEF(&_108$$89);
	ZVAL_UNDEF(&_109$$90);
	ZVAL_UNDEF(&_110$$91);
	ZVAL_UNDEF(&_111$$92);
	ZVAL_UNDEF(&_112$$93);
	ZVAL_UNDEF(&_113$$94);
	ZVAL_UNDEF(&_114$$95);
	ZVAL_UNDEF(&_115$$96);
	ZVAL_UNDEF(&_116$$97);
	ZVAL_UNDEF(&_117$$98);
	ZVAL_UNDEF(&_118$$99);
	ZVAL_UNDEF(&_119$$99);
	ZVAL_UNDEF(&_120$$100);
	ZVAL_UNDEF(&_121$$100);
	ZVAL_UNDEF(&_122$$100);
	ZVAL_UNDEF(&_123$$102);
	ZVAL_UNDEF(&_124$$103);
	ZVAL_UNDEF(&_130$$110);
	ZVAL_UNDEF(&_131$$113);
	ZVAL_UNDEF(&_132$$116);
	ZVAL_UNDEF(&_133$$116);
	ZVAL_UNDEF(&_134$$117);
	ZVAL_UNDEF(&_135$$119);
	ZVAL_UNDEF(&_137$$120);
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
	zephir_is_iterable(&fields, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 548);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _3)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _3);
			ZEPHIR_INIT_NVAR(&definition);
			zephir_create_array(&definition, 1, 0);
			add_assoc_long_ex(&definition, SL("bindType"), 2);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 122);
			do {
				_5$$3 = 1;
				if (_5$$3 == zephir_start_with_str(&columnType, SL("bigint"))) {
					ZEPHIR_INIT_NVAR(&_6$$4);
					ZVAL_LONG(&_6$$4, 14);
					zephir_array_update_string(&definition, SL("type"), &_6$$4, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_7$$4);
					ZVAL_LONG(&_7$$4, 2);
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
				if (_5$$3 == zephir_start_with_str(&columnType, SL("varbinary"))) {
					ZEPHIR_INIT_NVAR(&_39$$29);
					ZVAL_LONG(&_39$$29, 28);
					zephir_array_update_string(&definition, SL("type"), &_39$$29, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("binary"))) {
					ZEPHIR_INIT_NVAR(&_40$$30);
					ZVAL_LONG(&_40$$30, 27);
					zephir_array_update_string(&definition, SL("type"), &_40$$30, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("multipoint"))) {
					ZEPHIR_INIT_NVAR(&_41$$31);
					ZVAL_LONG(&_41$$31, 44);
					zephir_array_update_string(&definition, SL("type"), &_41$$31, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("multilinestring"))) {
					ZEPHIR_INIT_NVAR(&_42$$32);
					ZVAL_LONG(&_42$$32, 45);
					zephir_array_update_string(&definition, SL("type"), &_42$$32, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("multipolygon"))) {
					ZEPHIR_INIT_NVAR(&_43$$33);
					ZVAL_LONG(&_43$$33, 46);
					zephir_array_update_string(&definition, SL("type"), &_43$$33, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("geometrycollection"))) {
					ZEPHIR_INIT_NVAR(&_44$$34);
					ZVAL_LONG(&_44$$34, 47);
					zephir_array_update_string(&definition, SL("type"), &_44$$34, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("linestring"))) {
					ZEPHIR_INIT_NVAR(&_45$$35);
					ZVAL_LONG(&_45$$35, 42);
					zephir_array_update_string(&definition, SL("type"), &_45$$35, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("polygon"))) {
					ZEPHIR_INIT_NVAR(&_46$$36);
					ZVAL_LONG(&_46$$36, 43);
					zephir_array_update_string(&definition, SL("type"), &_46$$36, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("point"))) {
					ZEPHIR_INIT_NVAR(&_47$$37);
					ZVAL_LONG(&_47$$37, 41);
					zephir_array_update_string(&definition, SL("type"), &_47$$37, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_5$$3 == zephir_start_with_str(&columnType, SL("geometry"))) {
					ZEPHIR_INIT_NVAR(&_48$$38);
					ZVAL_LONG(&_48$$38, 40);
					zephir_array_update_string(&definition, SL("type"), &_48$$38, PH_COPY | PH_SEPARATE);
					break;
				}
				ZEPHIR_INIT_NVAR(&_49$$39);
				ZVAL_LONG(&_49$$39, 2);
				zephir_array_update_string(&definition, SL("type"), &_49$$39, PH_COPY | PH_SEPARATE);
				break;
			} while(0);

			if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 430)) {
				ZEPHIR_INIT_NVAR(&matches);
				ZVAL_NULL(&matches);
				zephir_array_fetch_string(&_50$$40, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 433);
				ZEPHIR_INIT_NVAR(&_51$$40);
				zephir_preg_match(&_51$$40, &sizePattern, &columnType, &matches, 0, 0 , 0 );
				if (ZEPHIR_IS_LONG(&_50$$40, 18)) {
					ZVAL_LONG(&_52$$41, 5);
					ZVAL_LONG(&_53$$41, -1);
					ZEPHIR_INIT_NVAR(&_54$$41);
					zephir_substr(&_54$$41, &columnType, 5 , -1 , 0);
					zephir_array_update_string(&definition, SL("size"), &_54$$41, PH_COPY | PH_SEPARATE);
				} else if (zephir_is_true(&_51$$40)) {
					ZEPHIR_OBS_NVAR(&matchOne);
					if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
						ZEPHIR_INIT_NVAR(&_55$$43);
						ZVAL_LONG(&_55$$43, zephir_get_intval(&matchOne));
						zephir_array_update_string(&definition, SL("size"), &_55$$43, PH_COPY | PH_SEPARATE);
					}
					ZEPHIR_OBS_NVAR(&matchTwo);
					if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
						ZEPHIR_INIT_NVAR(&_56$$44);
						ZVAL_LONG(&_56$$44, zephir_get_intval(&matchTwo));
						zephir_array_update_string(&definition, SL("scale"), &_56$$44, PH_COPY | PH_SEPARATE);
					}
				}
			}
			if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 449)) {
				zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&oldColumn) == IS_NULL) {
				zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_57$$3, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 465);
			if (ZEPHIR_IS_STRING(&_57$$3, "PRI")) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_58$$3, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 472);
			if (ZEPHIR_IS_STRING(&_58$$3, "YES")) {
				zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
			}
			ZEPHIR_OBS_NVAR(&extraValue);
			zephir_array_fetch_long(&extraValue, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 481);
			_59$$3 = Z_TYPE_P(&extraValue) != IS_NULL;
			if (_59$$3) {
				_59$$3 = zephir_memnstr_str(&extraValue, SL("INVISIBLE"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 482);
			}
			if (_59$$3) {
				zephir_array_update_string(&definition, SL("invisible"), &__$true, PH_COPY | PH_SEPARATE);
			}
			_60$$3 = Z_TYPE_P(&extraValue) != IS_NULL;
			if (_60$$3) {
				_61$$3 = zephir_memnstr_str(&extraValue, SL("VIRTUAL GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 500);
				if (!(_61$$3)) {
					_61$$3 = zephir_memnstr_str(&extraValue, SL("STORED GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 500);
				}
				_60$$3 = _61$$3;
			}
			if (_60$$3) {
				if (zephir_array_isset_long(&field, 9)) {
					ZEPHIR_OBS_NVAR(&generationExpression);
					zephir_array_fetch_long(&generationExpression, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 502);
				} else {
					ZEPHIR_INIT_NVAR(&generationExpression);
					ZVAL_STRING(&generationExpression, "");
				}
				zephir_array_update_string(&definition, SL("generated"), &generationExpression, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_62$$51);
				ZVAL_BOOL(&_62$$51, zephir_memnstr_str(&extraValue, SL("STORED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 508));
				zephir_array_update_string(&definition, SL("generationStored"), &_62$$51, PH_COPY | PH_SEPARATE);
			} else {
				if (ZEPHIR_IS_STRING(&extraValue, "auto_increment")) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_63$$54, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 520);
				if (Z_TYPE_P(&_63$$54) != IS_NULL) {
					if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 521)) {
						zephir_array_fetch_long(&_64$$57, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 522);
						ZEPHIR_INIT_NVAR(&_65$$57);
						ZEPHIR_CONCAT_VSV(&_65$$57, &_64$$57, " ", &extraValue);
						zephir_array_update_string(&definition, SL("default"), &_65$$57, PH_COPY | PH_SEPARATE);
					} else {
						zephir_array_fetch_long(&_66$$58, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 524);
						zephir_array_update_string(&definition, SL("default"), &_66$$58, PH_COPY | PH_SEPARATE);
					}
				} else {
					if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 527)) {
						ZEPHIR_INIT_NVAR(&_67$$60);
						ZEPHIR_CONCAT_SV(&_67$$60, "NULL ", &extraValue);
						zephir_array_update_string(&definition, SL("default"), &_67$$60, PH_COPY | PH_SEPARATE);
					}
				}
			}
			zephir_array_fetch_long(&_68$$3, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 536);
			if (Z_TYPE_P(&_68$$3) != IS_NULL) {
				zephir_array_fetch_long(&_69$$61, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 537);
				zephir_array_update_string(&definition, SL("comment"), &_69$$61, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 543);
			ZEPHIR_INIT_NVAR(&_70$$3);
			object_init_ex(&_70$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_70$$3, "__construct", &_71, 230, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_70$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 544);
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
				ZEPHIR_INIT_NVAR(&_72$$62);
				zephir_create_array(&_72$$62, 1, 0);
				add_assoc_long_ex(&_72$$62, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_72$$62);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 122);
				do {
					_73$$62 = 1;
					if (_73$$62 == zephir_start_with_str(&columnType, SL("bigint"))) {
						ZEPHIR_INIT_NVAR(&_74$$63);
						ZVAL_LONG(&_74$$63, 14);
						zephir_array_update_string(&definition, SL("type"), &_74$$63, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_75$$63);
						ZVAL_LONG(&_75$$63, 2);
						zephir_array_update_string(&definition, SL("bindType"), &_75$$63, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("mediumint"))) {
						ZEPHIR_INIT_NVAR(&_76$$64);
						ZVAL_LONG(&_76$$64, 21);
						zephir_array_update_string(&definition, SL("type"), &_76$$64, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_77$$64);
						ZVAL_LONG(&_77$$64, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_77$$64, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("smallint"))) {
						ZEPHIR_INIT_NVAR(&_78$$65);
						ZVAL_LONG(&_78$$65, 22);
						zephir_array_update_string(&definition, SL("type"), &_78$$65, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_79$$65);
						ZVAL_LONG(&_79$$65, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_79$$65, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("tinyint"))) {
						ZEPHIR_INIT_NVAR(&_80$$66);
						ZVAL_LONG(&_80$$66, 26);
						zephir_array_update_string(&definition, SL("type"), &_80$$66, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_81$$66);
						ZVAL_LONG(&_81$$66, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_81$$66, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("int"))) {
						ZEPHIR_INIT_NVAR(&_82$$67);
						ZVAL_LONG(&_82$$67, 0);
						zephir_array_update_string(&definition, SL("type"), &_82$$67, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_83$$67);
						ZVAL_LONG(&_83$$67, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_83$$67, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("bit"))) {
						ZEPHIR_INIT_NVAR(&_84$$68);
						ZVAL_LONG(&_84$$68, 19);
						zephir_array_update_string(&definition, SL("type"), &_84$$68, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_85$$68);
						ZVAL_LONG(&_85$$68, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_85$$68, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("enum"))) {
						ZEPHIR_INIT_NVAR(&_86$$69);
						ZVAL_LONG(&_86$$69, 18);
						zephir_array_update_string(&definition, SL("type"), &_86$$69, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("datetime"))) {
						ZEPHIR_INIT_NVAR(&_87$$70);
						ZVAL_LONG(&_87$$70, 4);
						zephir_array_update_string(&definition, SL("type"), &_87$$70, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("date"))) {
						ZEPHIR_INIT_NVAR(&_88$$71);
						ZVAL_LONG(&_88$$71, 1);
						zephir_array_update_string(&definition, SL("type"), &_88$$71, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("decimal"))) {
						ZEPHIR_INIT_NVAR(&_89$$72);
						ZVAL_LONG(&_89$$72, 3);
						zephir_array_update_string(&definition, SL("type"), &_89$$72, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("double"))) {
						ZEPHIR_INIT_NVAR(&_90$$73);
						ZVAL_LONG(&_90$$73, 9);
						zephir_array_update_string(&definition, SL("type"), &_90$$73, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_91$$73);
						ZVAL_LONG(&_91$$73, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_91$$73, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("float"))) {
						ZEPHIR_INIT_NVAR(&_92$$74);
						ZVAL_LONG(&_92$$74, 7);
						zephir_array_update_string(&definition, SL("type"), &_92$$74, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_93$$74);
						ZVAL_LONG(&_93$$74, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_93$$74, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("mediumblob"))) {
						ZEPHIR_INIT_NVAR(&_94$$75);
						ZVAL_LONG(&_94$$75, 12);
						zephir_array_update_string(&definition, SL("type"), &_94$$75, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("longblob"))) {
						ZEPHIR_INIT_NVAR(&_95$$76);
						ZVAL_LONG(&_95$$76, 13);
						zephir_array_update_string(&definition, SL("type"), &_95$$76, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("tinyblob"))) {
						ZEPHIR_INIT_NVAR(&_96$$77);
						ZVAL_LONG(&_96$$77, 10);
						zephir_array_update_string(&definition, SL("type"), &_96$$77, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("blob"))) {
						ZEPHIR_INIT_NVAR(&_97$$78);
						ZVAL_LONG(&_97$$78, 11);
						zephir_array_update_string(&definition, SL("type"), &_97$$78, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("timestamp"))) {
						ZEPHIR_INIT_NVAR(&_98$$79);
						ZVAL_LONG(&_98$$79, 17);
						zephir_array_update_string(&definition, SL("type"), &_98$$79, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("time"))) {
						ZEPHIR_INIT_NVAR(&_99$$80);
						ZVAL_LONG(&_99$$80, 20);
						zephir_array_update_string(&definition, SL("type"), &_99$$80, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("json"))) {
						ZEPHIR_INIT_NVAR(&_100$$81);
						ZVAL_LONG(&_100$$81, 15);
						zephir_array_update_string(&definition, SL("type"), &_100$$81, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("longtext"))) {
						ZEPHIR_INIT_NVAR(&_101$$82);
						ZVAL_LONG(&_101$$82, 24);
						zephir_array_update_string(&definition, SL("type"), &_101$$82, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("mediumtext"))) {
						ZEPHIR_INIT_NVAR(&_102$$83);
						ZVAL_LONG(&_102$$83, 23);
						zephir_array_update_string(&definition, SL("type"), &_102$$83, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("tinytext"))) {
						ZEPHIR_INIT_NVAR(&_103$$84);
						ZVAL_LONG(&_103$$84, 25);
						zephir_array_update_string(&definition, SL("type"), &_103$$84, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("text"))) {
						ZEPHIR_INIT_NVAR(&_104$$85);
						ZVAL_LONG(&_104$$85, 6);
						zephir_array_update_string(&definition, SL("type"), &_104$$85, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("varchar"))) {
						ZEPHIR_INIT_NVAR(&_105$$86);
						ZVAL_LONG(&_105$$86, 2);
						zephir_array_update_string(&definition, SL("type"), &_105$$86, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("char"))) {
						ZEPHIR_INIT_NVAR(&_106$$87);
						ZVAL_LONG(&_106$$87, 5);
						zephir_array_update_string(&definition, SL("type"), &_106$$87, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("varbinary"))) {
						ZEPHIR_INIT_NVAR(&_107$$88);
						ZVAL_LONG(&_107$$88, 28);
						zephir_array_update_string(&definition, SL("type"), &_107$$88, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("binary"))) {
						ZEPHIR_INIT_NVAR(&_108$$89);
						ZVAL_LONG(&_108$$89, 27);
						zephir_array_update_string(&definition, SL("type"), &_108$$89, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("multipoint"))) {
						ZEPHIR_INIT_NVAR(&_109$$90);
						ZVAL_LONG(&_109$$90, 44);
						zephir_array_update_string(&definition, SL("type"), &_109$$90, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("multilinestring"))) {
						ZEPHIR_INIT_NVAR(&_110$$91);
						ZVAL_LONG(&_110$$91, 45);
						zephir_array_update_string(&definition, SL("type"), &_110$$91, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("multipolygon"))) {
						ZEPHIR_INIT_NVAR(&_111$$92);
						ZVAL_LONG(&_111$$92, 46);
						zephir_array_update_string(&definition, SL("type"), &_111$$92, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("geometrycollection"))) {
						ZEPHIR_INIT_NVAR(&_112$$93);
						ZVAL_LONG(&_112$$93, 47);
						zephir_array_update_string(&definition, SL("type"), &_112$$93, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("linestring"))) {
						ZEPHIR_INIT_NVAR(&_113$$94);
						ZVAL_LONG(&_113$$94, 42);
						zephir_array_update_string(&definition, SL("type"), &_113$$94, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("polygon"))) {
						ZEPHIR_INIT_NVAR(&_114$$95);
						ZVAL_LONG(&_114$$95, 43);
						zephir_array_update_string(&definition, SL("type"), &_114$$95, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("point"))) {
						ZEPHIR_INIT_NVAR(&_115$$96);
						ZVAL_LONG(&_115$$96, 41);
						zephir_array_update_string(&definition, SL("type"), &_115$$96, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_73$$62 == zephir_start_with_str(&columnType, SL("geometry"))) {
						ZEPHIR_INIT_NVAR(&_116$$97);
						ZVAL_LONG(&_116$$97, 40);
						zephir_array_update_string(&definition, SL("type"), &_116$$97, PH_COPY | PH_SEPARATE);
						break;
					}
					ZEPHIR_INIT_NVAR(&_117$$98);
					ZVAL_LONG(&_117$$98, 2);
					zephir_array_update_string(&definition, SL("type"), &_117$$98, PH_COPY | PH_SEPARATE);
					break;
				} while(0);

				if (zephir_memnstr_str(&columnType, SL("("), "phalcon/Db/Adapter/Pdo/Mysql.zep", 430)) {
					ZEPHIR_INIT_NVAR(&matches);
					ZVAL_NULL(&matches);
					zephir_array_fetch_string(&_118$$99, &definition, SL("type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 433);
					ZEPHIR_INIT_NVAR(&_119$$99);
					zephir_preg_match(&_119$$99, &sizePattern, &columnType, &matches, 0, 0 , 0 );
					if (ZEPHIR_IS_LONG(&_118$$99, 18)) {
						ZVAL_LONG(&_120$$100, 5);
						ZVAL_LONG(&_121$$100, -1);
						ZEPHIR_INIT_NVAR(&_122$$100);
						zephir_substr(&_122$$100, &columnType, 5 , -1 , 0);
						zephir_array_update_string(&definition, SL("size"), &_122$$100, PH_COPY | PH_SEPARATE);
					} else if (zephir_is_true(&_119$$99)) {
						ZEPHIR_OBS_NVAR(&matchOne);
						if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0)) {
							ZEPHIR_INIT_NVAR(&_123$$102);
							ZVAL_LONG(&_123$$102, zephir_get_intval(&matchOne));
							zephir_array_update_string(&definition, SL("size"), &_123$$102, PH_COPY | PH_SEPARATE);
						}
						ZEPHIR_OBS_NVAR(&matchTwo);
						if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0)) {
							ZEPHIR_INIT_NVAR(&_124$$103);
							ZVAL_LONG(&_124$$103, zephir_get_intval(&matchTwo));
							zephir_array_update_string(&definition, SL("scale"), &_124$$103, PH_COPY | PH_SEPARATE);
						}
					}
				}
				if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 449)) {
					zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
				}
				if (Z_TYPE_P(&oldColumn) == IS_NULL) {
					zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_125$$62, &field, 4, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 465);
				if (ZEPHIR_IS_STRING(&_125$$62, "PRI")) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_126$$62, &field, 3, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 472);
				if (ZEPHIR_IS_STRING(&_126$$62, "YES")) {
					zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&extraValue);
				zephir_array_fetch_long(&extraValue, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 481);
				_127$$62 = Z_TYPE_P(&extraValue) != IS_NULL;
				if (_127$$62) {
					_127$$62 = zephir_memnstr_str(&extraValue, SL("INVISIBLE"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 482);
				}
				if (_127$$62) {
					zephir_array_update_string(&definition, SL("invisible"), &__$true, PH_COPY | PH_SEPARATE);
				}
				_128$$62 = Z_TYPE_P(&extraValue) != IS_NULL;
				if (_128$$62) {
					_129$$62 = zephir_memnstr_str(&extraValue, SL("VIRTUAL GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 500);
					if (!(_129$$62)) {
						_129$$62 = zephir_memnstr_str(&extraValue, SL("STORED GENERATED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 500);
					}
					_128$$62 = _129$$62;
				}
				if (_128$$62) {
					if (zephir_array_isset_long(&field, 9)) {
						ZEPHIR_OBS_NVAR(&generationExpression);
						zephir_array_fetch_long(&generationExpression, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 502);
					} else {
						ZEPHIR_INIT_NVAR(&generationExpression);
						ZVAL_STRING(&generationExpression, "");
					}
					zephir_array_update_string(&definition, SL("generated"), &generationExpression, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_130$$110);
					ZVAL_BOOL(&_130$$110, zephir_memnstr_str(&extraValue, SL("STORED"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 508));
					zephir_array_update_string(&definition, SL("generationStored"), &_130$$110, PH_COPY | PH_SEPARATE);
				} else {
					if (ZEPHIR_IS_STRING(&extraValue, "auto_increment")) {
						zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
					}
					zephir_array_fetch_long(&_131$$113, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 520);
					if (Z_TYPE_P(&_131$$113) != IS_NULL) {
						if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 521)) {
							zephir_array_fetch_long(&_132$$116, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 522);
							ZEPHIR_INIT_NVAR(&_133$$116);
							ZEPHIR_CONCAT_VSV(&_133$$116, &_132$$116, " ", &extraValue);
							zephir_array_update_string(&definition, SL("default"), &_133$$116, PH_COPY | PH_SEPARATE);
						} else {
							zephir_array_fetch_long(&_134$$117, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 524);
							zephir_array_update_string(&definition, SL("default"), &_134$$117, PH_COPY | PH_SEPARATE);
						}
					} else {
						if (zephir_memnstr_str(&extraValue, SL("on update"), "phalcon/Db/Adapter/Pdo/Mysql.zep", 527)) {
							ZEPHIR_INIT_NVAR(&_135$$119);
							ZEPHIR_CONCAT_SV(&_135$$119, "NULL ", &extraValue);
							zephir_array_update_string(&definition, SL("default"), &_135$$119, PH_COPY | PH_SEPARATE);
						}
					}
				}
				zephir_array_fetch_long(&_136$$62, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 536);
				if (Z_TYPE_P(&_136$$62) != IS_NULL) {
					zephir_array_fetch_long(&_137$$120, &field, 8, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 537);
					zephir_array_update_string(&definition, SL("comment"), &_137$$120, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 543);
				ZEPHIR_INIT_NVAR(&_138$$62);
				object_init_ex(&_138$$62, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_138$$62, "__construct", &_71, 230, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_138$$62, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 544);
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeIndexes)
{
	zval _52$$31, _60$$38;
	zval _15$$9, _34$$23;
	zend_ulong _46;
	zend_bool invisible = 0, anyDirection = 0, _12$$3, _23$$3, _31$$17, _42$$17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_55 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, __$true, indexes, index, keyName, indexType, indexObjects, columns, name, directions, collation, _0, _1, _2, _3, *_4, _5, *_44, _45, _6$$4, _7$$3, _9$$3, _10$$3, _13$$3, _18$$3, _24$$3, _8$$6, _11$$8, _14$$9, _16$$10, _17$$11, _19$$12, _20$$13, _21$$14, _22$$15, _25$$18, _26$$17, _28$$17, _29$$17, _32$$17, _37$$17, _43$$17, _27$$20, _30$$22, _33$$23, _35$$24, _36$$25, _38$$26, _39$$27, _40$$28, _41$$29, _48$$32, *_49$$31, _50$$31, _51$$31, _53$$31, _54$$31, _56$$39, *_57$$38, _58$$38, _59$$38, _61$$38, _62$$38;
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
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_45);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_7$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_10$$3);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_18$$3);
	ZVAL_UNDEF(&_24$$3);
	ZVAL_UNDEF(&_8$$6);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_14$$9);
	ZVAL_UNDEF(&_16$$10);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_19$$12);
	ZVAL_UNDEF(&_20$$13);
	ZVAL_UNDEF(&_21$$14);
	ZVAL_UNDEF(&_22$$15);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_26$$17);
	ZVAL_UNDEF(&_28$$17);
	ZVAL_UNDEF(&_29$$17);
	ZVAL_UNDEF(&_32$$17);
	ZVAL_UNDEF(&_37$$17);
	ZVAL_UNDEF(&_43$$17);
	ZVAL_UNDEF(&_27$$20);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_33$$23);
	ZVAL_UNDEF(&_35$$24);
	ZVAL_UNDEF(&_36$$25);
	ZVAL_UNDEF(&_38$$26);
	ZVAL_UNDEF(&_39$$27);
	ZVAL_UNDEF(&_40$$28);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_48$$32);
	ZVAL_UNDEF(&_50$$31);
	ZVAL_UNDEF(&_51$$31);
	ZVAL_UNDEF(&_53$$31);
	ZVAL_UNDEF(&_54$$31);
	ZVAL_UNDEF(&_56$$39);
	ZVAL_UNDEF(&_58$$38);
	ZVAL_UNDEF(&_59$$38);
	ZVAL_UNDEF(&_61$$38);
	ZVAL_UNDEF(&_62$$38);
	ZVAL_UNDEF(&_15$$9);
	ZVAL_UNDEF(&_34$$23);
	ZVAL_UNDEF(&_52$$31);
	ZVAL_UNDEF(&_60$$38);
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
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 630);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _4);
			zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 569);
			zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 570);
			if (!(zephir_array_isset(&indexes, &keyName))) {
				ZEPHIR_INIT_NVAR(&_6$$4);
				array_init(&_6$$4);
				zephir_array_update_zval(&indexes, &keyName, &_6$$4, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch(&_7$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 576);
			if (!(zephir_array_isset_string(&_7$$3, SL("columns")))) {
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
			} else {
				zephir_array_fetch(&_8$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 579);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_8$$6, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 579);
			}
			zephir_array_fetch_string(&_9$$3, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 582);
			zephir_array_append(&columns, &_9$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 582);
			zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
			zephir_array_fetch(&_10$$3, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 591);
			if (!(zephir_array_isset_string(&_10$$3, SL("directions")))) {
				ZEPHIR_INIT_NVAR(&directions);
				array_init(&directions);
			} else {
				zephir_array_fetch(&_11$$8, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 594);
				ZEPHIR_OBS_NVAR(&directions);
				zephir_array_fetch_string(&directions, &_11$$8, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 594);
			}
			ZEPHIR_INIT_NVAR(&collation);
			ZVAL_STRING(&collation, "");
			_12$$3 = zephir_array_isset_string(&index, SL("Collation"));
			if (_12$$3) {
				zephir_array_fetch_string(&_13$$3, &index, SL("Collation"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 598);
				_12$$3 = Z_TYPE_P(&_13$$3) != IS_NULL;
			}
			if (_12$$3) {
				ZEPHIR_OBS_NVAR(&_14$$9);
				zephir_array_fetch_string(&_14$$9, &index, SL("Collation"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 599);
				zephir_cast_to_string(&_15$$9, &_14$$9);
				ZEPHIR_CPY_WRT(&collation, &_15$$9);
			}
			if (ZEPHIR_IS_STRING(&collation, "D")) {
				ZEPHIR_INIT_NVAR(&_16$$10);
				ZVAL_STRING(&_16$$10, "DESC");
				zephir_array_append(&directions, &_16$$10, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 603);
			} else {
				ZEPHIR_INIT_NVAR(&_17$$11);
				ZVAL_STRING(&_17$$11, "ASC");
				zephir_array_append(&directions, &_17$$11, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 605);
			}
			zephir_array_update_multi(&indexes, &directions, SL("zs"), 3, &keyName, SL("directions"));
			zephir_array_fetch_string(&_18$$3, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 614);
			if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
				ZEPHIR_INIT_NVAR(&_19$$12);
				ZVAL_STRING(&_19$$12, "PRIMARY");
				zephir_array_update_multi(&indexes, &_19$$12, SL("zs"), 3, &keyName, SL("type"));
			} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
				ZEPHIR_INIT_NVAR(&_20$$13);
				ZVAL_STRING(&_20$$13, "FULLTEXT");
				zephir_array_update_multi(&indexes, &_20$$13, SL("zs"), 3, &keyName, SL("type"));
			} else if (ZEPHIR_IS_LONG(&_18$$3, 0)) {
				ZEPHIR_INIT_NVAR(&_21$$14);
				ZVAL_STRING(&_21$$14, "UNIQUE");
				zephir_array_update_multi(&indexes, &_21$$14, SL("zs"), 3, &keyName, SL("type"));
			} else {
				ZEPHIR_INIT_NVAR(&_22$$15);
				ZVAL_STRING(&_22$$15, "");
				zephir_array_update_multi(&indexes, &_22$$15, SL("zs"), 3, &keyName, SL("type"));
			}
			_23$$3 = zephir_array_isset_string(&index, SL("Visible"));
			if (_23$$3) {
				zephir_array_fetch_string(&_24$$3, &index, SL("Visible"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 625);
				_23$$3 = ZEPHIR_IS_STRING(&_24$$3, "NO");
			}
			if (_23$$3) {
				zephir_array_update_multi(&indexes, &__$true, SL("zs"), 3, &keyName, SL("invisible"));
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
				zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 569);
				ZEPHIR_OBS_NVAR(&indexType);
				zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 570);
				if (!(zephir_array_isset(&indexes, &keyName))) {
					ZEPHIR_INIT_NVAR(&_25$$18);
					array_init(&_25$$18);
					zephir_array_update_zval(&indexes, &keyName, &_25$$18, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch(&_26$$17, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 576);
				if (!(zephir_array_isset_string(&_26$$17, SL("columns")))) {
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
				} else {
					zephir_array_fetch(&_27$$20, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 579);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_27$$20, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 579);
				}
				zephir_array_fetch_string(&_28$$17, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 582);
				zephir_array_append(&columns, &_28$$17, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 582);
				zephir_array_update_multi(&indexes, &columns, SL("zs"), 3, &keyName, SL("columns"));
				zephir_array_fetch(&_29$$17, &indexes, &keyName, PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 591);
				if (!(zephir_array_isset_string(&_29$$17, SL("directions")))) {
					ZEPHIR_INIT_NVAR(&directions);
					array_init(&directions);
				} else {
					zephir_array_fetch(&_30$$22, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 594);
					ZEPHIR_OBS_NVAR(&directions);
					zephir_array_fetch_string(&directions, &_30$$22, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 594);
				}
				ZEPHIR_INIT_NVAR(&collation);
				ZVAL_STRING(&collation, "");
				_31$$17 = zephir_array_isset_string(&index, SL("Collation"));
				if (_31$$17) {
					zephir_array_fetch_string(&_32$$17, &index, SL("Collation"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 598);
					_31$$17 = Z_TYPE_P(&_32$$17) != IS_NULL;
				}
				if (_31$$17) {
					ZEPHIR_OBS_NVAR(&_33$$23);
					zephir_array_fetch_string(&_33$$23, &index, SL("Collation"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 599);
					zephir_cast_to_string(&_34$$23, &_33$$23);
					ZEPHIR_CPY_WRT(&collation, &_34$$23);
				}
				if (ZEPHIR_IS_STRING(&collation, "D")) {
					ZEPHIR_INIT_NVAR(&_35$$24);
					ZVAL_STRING(&_35$$24, "DESC");
					zephir_array_append(&directions, &_35$$24, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 603);
				} else {
					ZEPHIR_INIT_NVAR(&_36$$25);
					ZVAL_STRING(&_36$$25, "ASC");
					zephir_array_append(&directions, &_36$$25, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 605);
				}
				zephir_array_update_multi(&indexes, &directions, SL("zs"), 3, &keyName, SL("directions"));
				zephir_array_fetch_string(&_37$$17, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 614);
				if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
					ZEPHIR_INIT_NVAR(&_38$$26);
					ZVAL_STRING(&_38$$26, "PRIMARY");
					zephir_array_update_multi(&indexes, &_38$$26, SL("zs"), 3, &keyName, SL("type"));
				} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
					ZEPHIR_INIT_NVAR(&_39$$27);
					ZVAL_STRING(&_39$$27, "FULLTEXT");
					zephir_array_update_multi(&indexes, &_39$$27, SL("zs"), 3, &keyName, SL("type"));
				} else if (ZEPHIR_IS_LONG(&_37$$17, 0)) {
					ZEPHIR_INIT_NVAR(&_40$$28);
					ZVAL_STRING(&_40$$28, "UNIQUE");
					zephir_array_update_multi(&indexes, &_40$$28, SL("zs"), 3, &keyName, SL("type"));
				} else {
					ZEPHIR_INIT_NVAR(&_41$$29);
					ZVAL_STRING(&_41$$29, "");
					zephir_array_update_multi(&indexes, &_41$$29, SL("zs"), 3, &keyName, SL("type"));
				}
				_42$$17 = zephir_array_isset_string(&index, SL("Visible"));
				if (_42$$17) {
					zephir_array_fetch_string(&_43$$17, &index, SL("Visible"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 625);
					_42$$17 = ZEPHIR_IS_STRING(&_43$$17, "NO");
				}
				if (_42$$17) {
					zephir_array_update_multi(&indexes, &__$true, SL("zs"), 3, &keyName, SL("invisible"));
				}
			ZEPHIR_CALL_METHOD(NULL, &_0, "next", NULL, 0);
			zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	zephir_is_iterable(&indexes, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 667);
	if (Z_TYPE_P(&indexes) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&indexes), _46, _47, _44)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_47 != NULL) { 
				ZVAL_STR_COPY(&name, _47);
			} else {
				ZVAL_LONG(&name, _46);
			}
			ZEPHIR_INIT_NVAR(&index);
			ZVAL_COPY(&index, _44);
			invisible = 0;
			if (zephir_array_isset_string(&index, SL("invisible"))) {
				ZEPHIR_OBS_NVAR(&_48$$32);
				zephir_array_fetch_string(&_48$$32, &index, SL("invisible"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 635);
				invisible = zephir_get_boolval(&_48$$32);
			}
			ZEPHIR_OBS_NVAR(&directions);
			zephir_array_fetch_string(&directions, &index, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 643);
			anyDirection = 0;
			zephir_is_iterable(&directions, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 652);
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
				while (1) {
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
					ZEPHIR_CALL_METHOD(NULL, &directions, "next", NULL, 0);
					zephir_check_call_status();
				}
			}
			ZEPHIR_INIT_NVAR(&collation);
			if (!(anyDirection)) {
				ZEPHIR_INIT_NVAR(&directions);
				array_init(&directions);
			}
			ZEPHIR_INIT_NVAR(&_51$$31);
			object_init_ex(&_51$$31, phalcon_db_index_ce);
			ZEPHIR_INIT_NVAR(&_52$$31);
			zephir_create_array(&_52$$31, 4, 0);
			ZEPHIR_OBS_NVAR(&_53$$31);
			zephir_array_fetch_string(&_53$$31, &index, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 659);
			zephir_array_update_string(&_52$$31, SL("columns"), &_53$$31, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_53$$31);
			zephir_array_fetch_string(&_53$$31, &index, SL("type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 660);
			zephir_array_update_string(&_52$$31, SL("type"), &_53$$31, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(&_54$$31);
			ZVAL_BOOL(&_54$$31, invisible);
			zephir_array_update_string(&_52$$31, SL("invisible"), &_54$$31, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&_52$$31, SL("directions"), &directions, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_51$$31, "__construct", &_55, 50, &name, &_52$$31);
			zephir_check_call_status();
			zephir_array_update_zval(&indexObjects, &name, &_51$$31, PH_COPY | PH_SEPARATE);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &indexes, "rewind", NULL, 0);
		zephir_check_call_status();
		while (1) {
			ZEPHIR_CALL_METHOD(&_45, &indexes, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_45)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&name, &indexes, "key", NULL, 0);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD(&index, &indexes, "current", NULL, 0);
			zephir_check_call_status();
				invisible = 0;
				if (zephir_array_isset_string(&index, SL("invisible"))) {
					ZEPHIR_OBS_NVAR(&_56$$39);
					zephir_array_fetch_string(&_56$$39, &index, SL("invisible"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 635);
					invisible = zephir_get_boolval(&_56$$39);
				}
				ZEPHIR_OBS_NVAR(&directions);
				zephir_array_fetch_string(&directions, &index, SL("directions"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 643);
				anyDirection = 0;
				zephir_is_iterable(&directions, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 652);
				if (Z_TYPE_P(&directions) == IS_ARRAY) {
					ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&directions), _57$$38)
					{
						ZEPHIR_INIT_NVAR(&collation);
						ZVAL_COPY(&collation, _57$$38);
						if (ZEPHIR_IS_STRING(&collation, "DESC")) {
							anyDirection = 1;
							break;
						}
					} ZEND_HASH_FOREACH_END();
				} else {
					ZEPHIR_CALL_METHOD(NULL, &directions, "rewind", NULL, 0);
					zephir_check_call_status();
					while (1) {
						ZEPHIR_CALL_METHOD(&_58$$38, &directions, "valid", NULL, 0);
						zephir_check_call_status();
						if (!zend_is_true(&_58$$38)) {
							break;
						}
						ZEPHIR_CALL_METHOD(&collation, &directions, "current", NULL, 0);
						zephir_check_call_status();
							if (ZEPHIR_IS_STRING(&collation, "DESC")) {
								anyDirection = 1;
								break;
							}
						ZEPHIR_CALL_METHOD(NULL, &directions, "next", NULL, 0);
						zephir_check_call_status();
					}
				}
				ZEPHIR_INIT_NVAR(&collation);
				if (!(anyDirection)) {
					ZEPHIR_INIT_NVAR(&directions);
					array_init(&directions);
				}
				ZEPHIR_INIT_NVAR(&_59$$38);
				object_init_ex(&_59$$38, phalcon_db_index_ce);
				ZEPHIR_INIT_NVAR(&_60$$38);
				zephir_create_array(&_60$$38, 4, 0);
				ZEPHIR_OBS_NVAR(&_61$$38);
				zephir_array_fetch_string(&_61$$38, &index, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 659);
				zephir_array_update_string(&_60$$38, SL("columns"), &_61$$38, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_61$$38);
				zephir_array_fetch_string(&_61$$38, &index, SL("type"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 660);
				zephir_array_update_string(&_60$$38, SL("type"), &_61$$38, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_62$$38);
				ZVAL_BOOL(&_62$$38, invisible);
				zephir_array_update_string(&_60$$38, SL("invisible"), &_62$$38, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&_60$$38, SL("directions"), &directions, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &_59$$38, "__construct", &_55, 50, &name, &_60$$38);
				zephir_check_call_status();
				zephir_array_update_zval(&indexObjects, &name, &_59$$38, PH_COPY | PH_SEPARATE);
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeReferences)
{
	zval _14$$3, _23$$6, _29$$9, _33$$10;
	zend_ulong _26;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_31 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, referenceUpdate, referenceDelete, _0, _1, _2, _3, *_4, _5, *_24, _25, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$5, _12$$3, _13$$3, _15$$8, _16$$8, _17$$8, _18$$8, _19$$8, _20$$8, _21$$6, _22$$6, _28$$9, _30$$9, _32$$10, _34$$10;
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
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 720);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _4);
			zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 689);
			if (!(zephir_array_isset(&references, &constraintName))) {
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 692);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 693);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 694);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 695);
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 699);
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_6$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 699);
				zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 700);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_7$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 700);
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 701);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_8$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 701);
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 702);
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_9$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 702);
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 703);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_string(&referenceUpdate, &_10$$5, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 703);
				zephir_array_fetch(&_11$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 704);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_string(&referenceDelete, &_11$$5, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 704);
			}
			zephir_array_fetch_long(&_12$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 707);
			zephir_array_append(&columns, &_12$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 707);
			zephir_array_fetch_long(&_13$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 708);
			zephir_array_append(&referencedColumns, &_13$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 708);
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
				zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 689);
				if (!(zephir_array_isset(&references, &constraintName))) {
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 692);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 693);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 694);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 695);
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_15$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 699);
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_15$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 699);
					zephir_array_fetch(&_16$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 700);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_16$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 700);
					zephir_array_fetch(&_17$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 701);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_17$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 701);
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 702);
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_18$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 702);
					zephir_array_fetch(&_19$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 703);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_string(&referenceUpdate, &_19$$8, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 703);
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 704);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_string(&referenceDelete, &_20$$8, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 704);
				}
				zephir_array_fetch_long(&_21$$6, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 707);
				zephir_array_append(&columns, &_21$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 707);
				zephir_array_fetch_long(&_22$$6, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 708);
				zephir_array_append(&referencedColumns, &_22$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Mysql.zep", 708);
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
	zephir_is_iterable(&references, 0, "phalcon/Db/Adapter/Pdo/Mysql.zep", 735);
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
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 725);
			zephir_array_update_string(&_29$$9, SL("referencedSchema"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 726);
			zephir_array_update_string(&_29$$9, SL("referencedTable"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 727);
			zephir_array_update_string(&_29$$9, SL("columns"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 728);
			zephir_array_update_string(&_29$$9, SL("referencedColumns"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 729);
			zephir_array_update_string(&_29$$9, SL("onUpdate"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_OBS_NVAR(&_30$$9);
			zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
			zephir_array_update_string(&_29$$9, SL("onDelete"), &_30$$9, PH_COPY | PH_SEPARATE);
			ZEPHIR_CALL_METHOD(NULL, &_28$$9, "__construct", &_31, 51, &name, &_29$$9);
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
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 725);
				zephir_array_update_string(&_33$$10, SL("referencedSchema"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 726);
				zephir_array_update_string(&_33$$10, SL("referencedTable"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 727);
				zephir_array_update_string(&_33$$10, SL("columns"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 728);
				zephir_array_update_string(&_33$$10, SL("referencedColumns"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 729);
				zephir_array_update_string(&_33$$10, SL("onUpdate"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_OBS_NVAR(&_34$$10);
				zephir_array_fetch_string(&_34$$10, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Mysql.zep", 731);
				zephir_array_update_string(&_33$$10, SL("onDelete"), &_34$$10, PH_COPY | PH_SEPARATE);
				ZEPHIR_CALL_METHOD(NULL, &_32$$10, "__construct", &_31, 51, &name, &_33$$10);
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, getDsnDefaults)
{

	zephir_create_array(return_value, 1, 0);
	add_assoc_stringl_ex(return_value, SL("charset"), SL("utf8mb4"));
	return;
}

