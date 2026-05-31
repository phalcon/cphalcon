
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
 * Specific functions for the PostgreSQL database system
 *
 * ```php
 * use Phalcon\Db\Adapter\Pdo\Postgresql;
 *
 * $config = [
 *     "host"     => "localhost",
 *     "dbname"   => "blog",
 *     "port"     => 5432,
 *     "username" => "postgres",
 *     "password" => "secret",
 * ];
 *
 * $connection = new Postgresql($config);
 * ```
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Postgresql)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Postgresql, phalcon, db_adapter_pdo_postgresql, phalcon_db_adapter_pdo_abstractpdo_ce, phalcon_db_adapter_pdo_postgresql_method_entry, 0);

	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("dialectType"), "postgresql", ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("type"), "pgsql", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * Constructor for Phalcon\Db\Adapter\Pdo\Postgresql
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, __construct)
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
	if (zephir_array_isset_value_string(&descriptor, SL("charset"))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "Postgres does not allow the charset to be changed in the DSN.");
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 14, &_0$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_postgresql_ce, getThis(), "__construct", NULL, 0, &descriptor);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo
 * constructor. Call it when you need to restore a database connection.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, connect)
{
	zend_bool _2$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, __$null, schema, sql, _0$$3, _1$$6, _3$$6;
	zval descriptor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$6);
	ZVAL_UNDEF(&_3$$6);
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
	zephir_memory_observe(&schema);
	if (zephir_array_isset_string_fetch(&schema, &descriptor, SL("schema"), 0)) {
		zephir_array_unset_string(&descriptor, SL("schema"), PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(&schema);
		ZVAL_NULL(&schema);
	}
	if (zephir_array_isset_value_string(&descriptor, SL("password"))) {
		zephir_memory_observe(&_1$$6);
		zephir_array_fetch_string(&_1$$6, &descriptor, SL("password"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 86);
		_2$$6 = Z_TYPE_P(&_1$$6) == IS_STRING;
		if (_2$$6) {
			zephir_array_fetch_string(&_3$$6, &descriptor, SL("password"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 86);
			_2$$6 = zephir_fast_strlen_ev(&_3$$6) == 0;
		}
		if (_2$$6) {
			zephir_array_update_string(&descriptor, SL("password"), &__$null, PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_postgresql_ce, getThis(), "connect", NULL, 0, &descriptor);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&schema))) {
		ZEPHIR_INIT_VAR(&sql);
		ZEPHIR_CONCAT_SVS(&sql, "SET search_path TO '", &schema, "'");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, &sql);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Creates a table
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, createTable)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval tableName_zv, schemaName_zv, *definition_param = NULL, sql, queries, query, exception, columns, _2, _0$$3, _1$$4, *_3$$6, _4$$7, _6$$5, _7$$10, _8$$10;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&queries);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_4$$7);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$10);
	ZVAL_UNDEF(&_8$$10);
	ZVAL_UNDEF(&definition);
	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		ZEPHIR_Z_PARAM_ARRAY(definition, definition_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	definition_param = ZEND_CALL_ARG(execute_data, 3);
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	ZEPHIR_OBS_COPY_OR_DUP(&definition, definition_param);
	zephir_memory_observe(&columns);
	if (UNEXPECTED(!(zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0)))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		object_init_ex(&_0$$3, phalcon_db_exceptions_tablemusthavecolumn_ce);
		ZEPHIR_CALL_METHOD(NULL, &_0$$3, "__construct", NULL, 60);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_0$$3, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 108);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(zephir_fast_count_int(&columns)))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		object_init_ex(&_1$$4, phalcon_db_exceptions_tablemusthavecolumn_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$4, "__construct", NULL, 60);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$4, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 112);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property(&_2, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&sql, &_2, "createtable", NULL, 0, &tableName_zv, &schemaName_zv, &definition);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&queries);
	zephir_fast_explode_str(&queries, SL(";"), &sql, LONG_MAX);
	if (zephir_fast_count_int(&queries) > 1) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(NULL, this_ptr, "begin", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_is_iterable(&queries, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 131);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queries), _3$$6)
			{
				ZEPHIR_INIT_NVAR(&query);
				ZVAL_COPY(&query, _3$$6);
				if (ZEPHIR_IS_EMPTY(&query)) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_4$$7);
				ZEPHIR_CONCAT_VS(&_4$$7, &query, ";");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_5, 0, &_4$$7);
				zephir_check_call_status_or_jump(try_end_1);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&query);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "commit", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_6$$5);
			ZVAL_OBJ(&_6$$5, EG(exception));
			Z_ADDREF_P(&_6$$5);
			if (zephir_is_instance_of(&_6$$5, SL("Throwable"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&exception, &_6$$5);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 135);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		zephir_array_fetch_long(&_7$$10, &queries, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 138);
		ZEPHIR_INIT_VAR(&_8$$10);
		ZEPHIR_CONCAT_VS(&_8$$10, &_7$$10, ";");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_8$$10);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns)
{
	zend_bool isGenerated = 0, _76, _4$$3, _55$$3, _59$$49, _78$$57, _129$$57, _133$$103;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_67 = NULL, *_70 = NULL, *_74 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, __$true, __$false, __$null, columns, columnType, fields, field, definition, oldColumn, columnName, charSize, numericSize, numericScale, generationExpression, _0, _1, _2, *_3, _75, _56$$3, _57$$3, _71$$3, _73$$3, _5$$4, _6$$4, _7$$5, _8$$5, _9$$6, _10$$6, _11$$7, _12$$7, _13$$8, _14$$8, _15$$9, _16$$9, _17$$10, _18$$11, _19$$12, _20$$12, _21$$13, _22$$13, _23$$14, _24$$14, _25$$15, _26$$15, _27$$16, _28$$16, _29$$17, _30$$18, _31$$19, _32$$20, _33$$21, _34$$22, _35$$23, _36$$24, _37$$25, _38$$26, _39$$27, _40$$28, _41$$29, _42$$30, _43$$31, _44$$32, _45$$33, _46$$34, _47$$35, _48$$36, _49$$37, _50$$38, _51$$39, _52$$40, _53$$41, _54$$42, _58$$48, _60$$49, _61$$52, _62$$52, _63$$54, _64$$54, _65$$54, _66$$54, _68$$54, _69$$54, _72$$56, _77$$57, _130$$57, _131$$57, _143$$57, _145$$57, _79$$58, _80$$58, _81$$59, _82$$59, _83$$60, _84$$60, _85$$61, _86$$61, _87$$62, _88$$62, _89$$63, _90$$63, _91$$64, _92$$65, _93$$66, _94$$66, _95$$67, _96$$67, _97$$68, _98$$68, _99$$69, _100$$69, _101$$70, _102$$70, _103$$71, _104$$72, _105$$73, _106$$74, _107$$75, _108$$76, _109$$77, _110$$78, _111$$79, _112$$80, _113$$81, _114$$82, _115$$83, _116$$84, _117$$85, _118$$86, _119$$87, _120$$88, _121$$89, _122$$90, _123$$91, _124$$92, _125$$93, _126$$94, _127$$95, _128$$96, _132$$102, _134$$103, _135$$106, _136$$106, _137$$108, _138$$108, _139$$108, _140$$108, _141$$108, _142$$108, _144$$110;
	zend_string *table = NULL, *schema = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&table_zv);
	ZVAL_UNDEF(&schema_zv);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&fields);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&oldColumn);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&charSize);
	ZVAL_UNDEF(&numericSize);
	ZVAL_UNDEF(&numericScale);
	ZVAL_UNDEF(&generationExpression);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_75);
	ZVAL_UNDEF(&_56$$3);
	ZVAL_UNDEF(&_57$$3);
	ZVAL_UNDEF(&_71$$3);
	ZVAL_UNDEF(&_73$$3);
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
	ZVAL_UNDEF(&_20$$12);
	ZVAL_UNDEF(&_21$$13);
	ZVAL_UNDEF(&_22$$13);
	ZVAL_UNDEF(&_23$$14);
	ZVAL_UNDEF(&_24$$14);
	ZVAL_UNDEF(&_25$$15);
	ZVAL_UNDEF(&_26$$15);
	ZVAL_UNDEF(&_27$$16);
	ZVAL_UNDEF(&_28$$16);
	ZVAL_UNDEF(&_29$$17);
	ZVAL_UNDEF(&_30$$18);
	ZVAL_UNDEF(&_31$$19);
	ZVAL_UNDEF(&_32$$20);
	ZVAL_UNDEF(&_33$$21);
	ZVAL_UNDEF(&_34$$22);
	ZVAL_UNDEF(&_35$$23);
	ZVAL_UNDEF(&_36$$24);
	ZVAL_UNDEF(&_37$$25);
	ZVAL_UNDEF(&_38$$26);
	ZVAL_UNDEF(&_39$$27);
	ZVAL_UNDEF(&_40$$28);
	ZVAL_UNDEF(&_41$$29);
	ZVAL_UNDEF(&_42$$30);
	ZVAL_UNDEF(&_43$$31);
	ZVAL_UNDEF(&_44$$32);
	ZVAL_UNDEF(&_45$$33);
	ZVAL_UNDEF(&_46$$34);
	ZVAL_UNDEF(&_47$$35);
	ZVAL_UNDEF(&_48$$36);
	ZVAL_UNDEF(&_49$$37);
	ZVAL_UNDEF(&_50$$38);
	ZVAL_UNDEF(&_51$$39);
	ZVAL_UNDEF(&_52$$40);
	ZVAL_UNDEF(&_53$$41);
	ZVAL_UNDEF(&_54$$42);
	ZVAL_UNDEF(&_58$$48);
	ZVAL_UNDEF(&_60$$49);
	ZVAL_UNDEF(&_61$$52);
	ZVAL_UNDEF(&_62$$52);
	ZVAL_UNDEF(&_63$$54);
	ZVAL_UNDEF(&_64$$54);
	ZVAL_UNDEF(&_65$$54);
	ZVAL_UNDEF(&_66$$54);
	ZVAL_UNDEF(&_68$$54);
	ZVAL_UNDEF(&_69$$54);
	ZVAL_UNDEF(&_72$$56);
	ZVAL_UNDEF(&_77$$57);
	ZVAL_UNDEF(&_130$$57);
	ZVAL_UNDEF(&_131$$57);
	ZVAL_UNDEF(&_143$$57);
	ZVAL_UNDEF(&_145$$57);
	ZVAL_UNDEF(&_79$$58);
	ZVAL_UNDEF(&_80$$58);
	ZVAL_UNDEF(&_81$$59);
	ZVAL_UNDEF(&_82$$59);
	ZVAL_UNDEF(&_83$$60);
	ZVAL_UNDEF(&_84$$60);
	ZVAL_UNDEF(&_85$$61);
	ZVAL_UNDEF(&_86$$61);
	ZVAL_UNDEF(&_87$$62);
	ZVAL_UNDEF(&_88$$62);
	ZVAL_UNDEF(&_89$$63);
	ZVAL_UNDEF(&_90$$63);
	ZVAL_UNDEF(&_91$$64);
	ZVAL_UNDEF(&_92$$65);
	ZVAL_UNDEF(&_93$$66);
	ZVAL_UNDEF(&_94$$66);
	ZVAL_UNDEF(&_95$$67);
	ZVAL_UNDEF(&_96$$67);
	ZVAL_UNDEF(&_97$$68);
	ZVAL_UNDEF(&_98$$68);
	ZVAL_UNDEF(&_99$$69);
	ZVAL_UNDEF(&_100$$69);
	ZVAL_UNDEF(&_101$$70);
	ZVAL_UNDEF(&_102$$70);
	ZVAL_UNDEF(&_103$$71);
	ZVAL_UNDEF(&_104$$72);
	ZVAL_UNDEF(&_105$$73);
	ZVAL_UNDEF(&_106$$74);
	ZVAL_UNDEF(&_107$$75);
	ZVAL_UNDEF(&_108$$76);
	ZVAL_UNDEF(&_109$$77);
	ZVAL_UNDEF(&_110$$78);
	ZVAL_UNDEF(&_111$$79);
	ZVAL_UNDEF(&_112$$80);
	ZVAL_UNDEF(&_113$$81);
	ZVAL_UNDEF(&_114$$82);
	ZVAL_UNDEF(&_115$$83);
	ZVAL_UNDEF(&_116$$84);
	ZVAL_UNDEF(&_117$$85);
	ZVAL_UNDEF(&_118$$86);
	ZVAL_UNDEF(&_119$$87);
	ZVAL_UNDEF(&_120$$88);
	ZVAL_UNDEF(&_121$$89);
	ZVAL_UNDEF(&_122$$90);
	ZVAL_UNDEF(&_123$$91);
	ZVAL_UNDEF(&_124$$92);
	ZVAL_UNDEF(&_125$$93);
	ZVAL_UNDEF(&_126$$94);
	ZVAL_UNDEF(&_127$$95);
	ZVAL_UNDEF(&_128$$96);
	ZVAL_UNDEF(&_132$$102);
	ZVAL_UNDEF(&_134$$103);
	ZVAL_UNDEF(&_135$$106);
	ZVAL_UNDEF(&_136$$106);
	ZVAL_UNDEF(&_137$$108);
	ZVAL_UNDEF(&_138$$108);
	ZVAL_UNDEF(&_139$$108);
	ZVAL_UNDEF(&_140$$108);
	ZVAL_UNDEF(&_141$$108);
	ZVAL_UNDEF(&_142$$108);
	ZVAL_UNDEF(&_144$$110);
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
	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "describecolumns", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "fetchall", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_is_iterable(&fields, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 629);
	if (Z_TYPE_P(&fields) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&fields), _3)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _3);
			ZEPHIR_INIT_NVAR(&definition);
			zephir_create_array(&definition, 1, 0);
			add_assoc_long_ex(&definition, SL("bindType"), 2);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 185);
			ZEPHIR_OBS_NVAR(&charSize);
			zephir_array_fetch_long(&charSize, &field, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 186);
			ZEPHIR_OBS_NVAR(&numericSize);
			zephir_array_fetch_long(&numericSize, &field, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 187);
			ZEPHIR_OBS_NVAR(&numericScale);
			zephir_array_fetch_long(&numericScale, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 188);
			do {
				_4$$3 = 1;
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("boolean"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 206)) {
					ZEPHIR_INIT_NVAR(&_5$$4);
					ZVAL_LONG(&_5$$4, 8);
					zephir_array_update_string(&definition, SL("type"), &_5$$4, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_6$$4);
					ZVAL_LONG(&_6$$4, 5);
					zephir_array_update_string(&definition, SL("bindType"), &_6$$4, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 218)) {
					ZEPHIR_INIT_NVAR(&_7$$5);
					ZVAL_LONG(&_7$$5, 14);
					zephir_array_update_string(&definition, SL("type"), &_7$$5, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_8$$5);
					ZVAL_LONG(&_8$$5, 2);
					zephir_array_update_string(&definition, SL("bindType"), &_8$$5, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("mediumint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 228)) {
					ZEPHIR_INIT_NVAR(&_9$$6);
					ZVAL_LONG(&_9$$6, 21);
					zephir_array_update_string(&definition, SL("type"), &_9$$6, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_10$$6);
					ZVAL_LONG(&_10$$6, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_10$$6, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("smallint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 238)) {
					ZEPHIR_INIT_NVAR(&_11$$7);
					ZVAL_LONG(&_11$$7, 22);
					zephir_array_update_string(&definition, SL("type"), &_11$$7, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_12$$7);
					ZVAL_LONG(&_12$$7, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_12$$7, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("tinyint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 248)) {
					ZEPHIR_INIT_NVAR(&_13$$8);
					ZVAL_LONG(&_13$$8, 26);
					zephir_array_update_string(&definition, SL("type"), &_13$$8, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_14$$8);
					ZVAL_LONG(&_14$$8, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_14$$8, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 261)) {
					ZEPHIR_INIT_NVAR(&_15$$9);
					ZVAL_LONG(&_15$$9, 0);
					zephir_array_update_string(&definition, SL("type"), &_15$$9, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_16$$9);
					ZVAL_LONG(&_16$$9, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_16$$9, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("bit"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 271)) {
					ZEPHIR_INIT_NVAR(&_17$$10);
					ZVAL_LONG(&_17$$10, 19);
					zephir_array_update_string(&definition, SL("type"), &_17$$10, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 280)) {
					ZEPHIR_INIT_NVAR(&_18$$11);
					ZVAL_LONG(&_18$$11, 18);
					zephir_array_update_string(&definition, SL("type"), &_18$$11, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 288)) {
					ZEPHIR_INIT_NVAR(&_19$$12);
					ZVAL_LONG(&_19$$12, 4);
					zephir_array_update_string(&definition, SL("type"), &_19$$12, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_20$$12);
					ZVAL_LONG(&_20$$12, 0);
					zephir_array_update_string(&definition, SL("size"), &_20$$12, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 297)) {
					ZEPHIR_INIT_NVAR(&_21$$13);
					ZVAL_LONG(&_21$$13, 1);
					zephir_array_update_string(&definition, SL("type"), &_21$$13, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_22$$13);
					ZVAL_LONG(&_22$$13, 0);
					zephir_array_update_string(&definition, SL("size"), &_22$$13, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 307) || _4$$3 == zephir_memnstr_str(&columnType, SL("numeric"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 308)) {
					ZEPHIR_INIT_NVAR(&_23$$14);
					ZVAL_LONG(&_23$$14, 3);
					zephir_array_update_string(&definition, SL("type"), &_23$$14, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_24$$14);
					ZVAL_LONG(&_24$$14, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_24$$14, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("double precision"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 319)) {
					ZEPHIR_INIT_NVAR(&_25$$15);
					ZVAL_LONG(&_25$$15, 9);
					zephir_array_update_string(&definition, SL("type"), &_25$$15, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_26$$15);
					ZVAL_LONG(&_26$$15, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_26$$15, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 330) || _4$$3 == zephir_memnstr_str(&columnType, SL("real"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 331)) {
					ZEPHIR_INIT_NVAR(&_27$$16);
					ZVAL_LONG(&_27$$16, 7);
					zephir_array_update_string(&definition, SL("type"), &_27$$16, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
					ZEPHIR_INIT_NVAR(&_28$$16);
					ZVAL_LONG(&_28$$16, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_28$$16, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 342)) {
					ZEPHIR_INIT_NVAR(&_29$$17);
					ZVAL_LONG(&_29$$17, 6);
					zephir_array_update_string(&definition, SL("type"), &_29$$17, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 350)) {
					ZEPHIR_INIT_NVAR(&_30$$18);
					ZVAL_LONG(&_30$$18, 13);
					zephir_array_update_string(&definition, SL("type"), &_30$$18, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 358)) {
					ZEPHIR_INIT_NVAR(&_31$$19);
					ZVAL_LONG(&_31$$19, 10);
					zephir_array_update_string(&definition, SL("type"), &_31$$19, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("blob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 366)) {
					ZEPHIR_INIT_NVAR(&_32$$20);
					ZVAL_LONG(&_32$$20, 11);
					zephir_array_update_string(&definition, SL("type"), &_32$$20, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 374)) {
					ZEPHIR_INIT_NVAR(&_33$$21);
					ZVAL_LONG(&_33$$21, 17);
					zephir_array_update_string(&definition, SL("type"), &_33$$21, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("time"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 382)) {
					ZEPHIR_INIT_NVAR(&_34$$22);
					ZVAL_LONG(&_34$$22, 20);
					zephir_array_update_string(&definition, SL("type"), &_34$$22, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("jsonb"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 390)) {
					ZEPHIR_INIT_NVAR(&_35$$23);
					ZVAL_LONG(&_35$$23, 16);
					zephir_array_update_string(&definition, SL("type"), &_35$$23, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("json"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 398)) {
					ZEPHIR_INIT_NVAR(&_36$$24);
					ZVAL_LONG(&_36$$24, 15);
					zephir_array_update_string(&definition, SL("type"), &_36$$24, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("longtext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 406)) {
					ZEPHIR_INIT_NVAR(&_37$$25);
					ZVAL_LONG(&_37$$25, 24);
					zephir_array_update_string(&definition, SL("type"), &_37$$25, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("mediumtext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 414)) {
					ZEPHIR_INIT_NVAR(&_38$$26);
					ZVAL_LONG(&_38$$26, 23);
					zephir_array_update_string(&definition, SL("type"), &_38$$26, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("tinytext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 422)) {
					ZEPHIR_INIT_NVAR(&_39$$27);
					ZVAL_LONG(&_39$$27, 25);
					zephir_array_update_string(&definition, SL("type"), &_39$$27, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 430)) {
					ZEPHIR_INIT_NVAR(&_40$$28);
					ZVAL_LONG(&_40$$28, 6);
					zephir_array_update_string(&definition, SL("type"), &_40$$28, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("varying"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 438) || _4$$3 == zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 439)) {
					ZEPHIR_INIT_NVAR(&_41$$29);
					ZVAL_LONG(&_41$$29, 2);
					zephir_array_update_string(&definition, SL("type"), &_41$$29, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 448)) {
					ZEPHIR_INIT_NVAR(&_42$$30);
					ZVAL_LONG(&_42$$30, 5);
					zephir_array_update_string(&definition, SL("type"), &_42$$30, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("uuid"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 457)) {
					ZEPHIR_INIT_NVAR(&_43$$31);
					ZVAL_LONG(&_43$$31, 29);
					zephir_array_update_string(&definition, SL("type"), &_43$$31, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("bytea"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 465)) {
					ZEPHIR_INIT_NVAR(&_44$$32);
					ZVAL_LONG(&_44$$32, 30);
					zephir_array_update_string(&definition, SL("type"), &_44$$32, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("inet"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 473)) {
					ZEPHIR_INIT_NVAR(&_45$$33);
					ZVAL_LONG(&_45$$33, 31);
					zephir_array_update_string(&definition, SL("type"), &_45$$33, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("cidr"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 481)) {
					ZEPHIR_INIT_NVAR(&_46$$34);
					ZVAL_LONG(&_46$$34, 32);
					zephir_array_update_string(&definition, SL("type"), &_46$$34, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("macaddr"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 489)) {
					ZEPHIR_INIT_NVAR(&_47$$35);
					ZVAL_LONG(&_47$$35, 33);
					zephir_array_update_string(&definition, SL("type"), &_47$$35, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("int4range"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 498)) {
					ZEPHIR_INIT_NVAR(&_48$$36);
					ZVAL_LONG(&_48$$36, 34);
					zephir_array_update_string(&definition, SL("type"), &_48$$36, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("int8range"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 503)) {
					ZEPHIR_INIT_NVAR(&_49$$37);
					ZVAL_LONG(&_49$$37, 35);
					zephir_array_update_string(&definition, SL("type"), &_49$$37, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("numrange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 508)) {
					ZEPHIR_INIT_NVAR(&_50$$38);
					ZVAL_LONG(&_50$$38, 36);
					zephir_array_update_string(&definition, SL("type"), &_50$$38, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("tstzrange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 513)) {
					ZEPHIR_INIT_NVAR(&_51$$39);
					ZVAL_LONG(&_51$$39, 38);
					zephir_array_update_string(&definition, SL("type"), &_51$$39, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("tsrange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 518)) {
					ZEPHIR_INIT_NVAR(&_52$$40);
					ZVAL_LONG(&_52$$40, 37);
					zephir_array_update_string(&definition, SL("type"), &_52$$40, PH_COPY | PH_SEPARATE);
					break;
				}
				if (_4$$3 == zephir_memnstr_str(&columnType, SL("daterange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 523)) {
					ZEPHIR_INIT_NVAR(&_53$$41);
					ZVAL_LONG(&_53$$41, 39);
					zephir_array_update_string(&definition, SL("type"), &_53$$41, PH_COPY | PH_SEPARATE);
					break;
				}
				ZEPHIR_INIT_NVAR(&_54$$42);
				ZVAL_LONG(&_54$$42, 2);
				zephir_array_update_string(&definition, SL("type"), &_54$$42, PH_COPY | PH_SEPARATE);
				break;
			} while(0);

			_55$$3 = zephir_memnstr_str(&columnType, SL("ARRAY"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 544);
			if (!(_55$$3)) {
				_55$$3 = zephir_memnstr_str(&columnType, SL("[]"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 544);
			}
			if (_55$$3) {
				zephir_array_update_string(&definition, SL("array"), &__$true, PH_COPY | PH_SEPARATE);
			}
			if (Z_TYPE_P(&oldColumn) == IS_NULL) {
				zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_56$$3, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 560);
			if (ZEPHIR_IS_STRING(&_56$$3, "PRI")) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&_57$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 567);
			if (ZEPHIR_IS_STRING(&_57$$3, "YES")) {
				zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
			}
			isGenerated = 0;
			if (zephir_array_isset_value_long(&field, 11)) {
				zephir_array_fetch_long(&_58$$48, &field, 11, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 578);
				isGenerated = (ZEPHIR_IS_STRING_IDENTICAL(&_58$$48, "ALWAYS"));
			}
			if (isGenerated) {
				_59$$49 = zephir_array_isset_value_long(&field, 12);
				if (_59$$49) {
					zephir_array_fetch_long(&_60$$49, &field, 12, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 582);
					_59$$49 = Z_TYPE_P(&_60$$49) != IS_NULL;
				}
				if (_59$$49) {
					ZEPHIR_OBS_NVAR(&generationExpression);
					zephir_array_fetch_long(&generationExpression, &field, 12, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 583);
				} else {
					ZEPHIR_INIT_NVAR(&generationExpression);
					ZVAL_STRING(&generationExpression, "");
				}
				zephir_array_update_string(&definition, SL("generated"), &generationExpression, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("generationStored"), &__$true, PH_COPY | PH_SEPARATE);
			} else {
				zephir_array_fetch_long(&_61$$52, &field, 7, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 594);
				if (ZEPHIR_IS_STRING(&_61$$52, "auto_increment")) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_62$$52, &field, 9, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 601);
				if (Z_TYPE_P(&_62$$52) != IS_NULL) {
					zephir_array_fetch_long(&_63$$54, &field, 9, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 606);
					ZEPHIR_INIT_NVAR(&_64$$54);
					ZVAL_STRING(&_64$$54, "/^'|'?::[[:alnum:][:space:]]+$/");
					ZEPHIR_INIT_NVAR(&_65$$54);
					ZVAL_STRING(&_65$$54, "");
					ZEPHIR_CALL_FUNCTION(&_66$$54, "preg_replace", &_67, 76, &_64$$54, &_65$$54, &_63$$54);
					zephir_check_call_status();
					zephir_array_update_string(&definition, SL("default"), &_66$$54, PH_COPY | PH_SEPARATE);
					zephir_array_fetch_string(&_68$$54, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 608);
					ZEPHIR_INIT_NVAR(&_64$$54);
					ZVAL_STRING(&_64$$54, "null");
					ZEPHIR_CALL_FUNCTION(&_69$$54, "strcasecmp", &_70, 73, &_68$$54, &_64$$54);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_69$$54, 0)) {
						zephir_array_update_string(&definition, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
					}
				}
			}
			zephir_array_fetch_long(&_71$$3, &field, 10, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 617);
			if (Z_TYPE_P(&_71$$3) != IS_NULL) {
				zephir_array_fetch_long(&_72$$56, &field, 10, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 618);
				zephir_array_update_string(&definition, SL("comment"), &_72$$56, PH_COPY | PH_SEPARATE);
			}
			zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 624);
			ZEPHIR_INIT_NVAR(&_73$$3);
			object_init_ex(&_73$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_73$$3, "__construct", &_74, 338, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_73$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 625);
			ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, &fields, "rewind", NULL, 0);
		zephir_check_call_status();
		_76 = 1;
		while (1) {
			if (_76) {
				_76 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, &fields, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_75, &fields, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_75)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, &fields, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_77$$57);
				zephir_create_array(&_77$$57, 1, 0);
				add_assoc_long_ex(&_77$$57, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_77$$57);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 185);
				ZEPHIR_OBS_NVAR(&charSize);
				zephir_array_fetch_long(&charSize, &field, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 186);
				ZEPHIR_OBS_NVAR(&numericSize);
				zephir_array_fetch_long(&numericSize, &field, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 187);
				ZEPHIR_OBS_NVAR(&numericScale);
				zephir_array_fetch_long(&numericScale, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 188);
				do {
					_78$$57 = 1;
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("boolean"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 206)) {
						ZEPHIR_INIT_NVAR(&_79$$58);
						ZVAL_LONG(&_79$$58, 8);
						zephir_array_update_string(&definition, SL("type"), &_79$$58, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_80$$58);
						ZVAL_LONG(&_80$$58, 5);
						zephir_array_update_string(&definition, SL("bindType"), &_80$$58, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 218)) {
						ZEPHIR_INIT_NVAR(&_81$$59);
						ZVAL_LONG(&_81$$59, 14);
						zephir_array_update_string(&definition, SL("type"), &_81$$59, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_82$$59);
						ZVAL_LONG(&_82$$59, 2);
						zephir_array_update_string(&definition, SL("bindType"), &_82$$59, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("mediumint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 228)) {
						ZEPHIR_INIT_NVAR(&_83$$60);
						ZVAL_LONG(&_83$$60, 21);
						zephir_array_update_string(&definition, SL("type"), &_83$$60, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_84$$60);
						ZVAL_LONG(&_84$$60, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_84$$60, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("smallint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 238)) {
						ZEPHIR_INIT_NVAR(&_85$$61);
						ZVAL_LONG(&_85$$61, 22);
						zephir_array_update_string(&definition, SL("type"), &_85$$61, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_86$$61);
						ZVAL_LONG(&_86$$61, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_86$$61, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("tinyint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 248)) {
						ZEPHIR_INIT_NVAR(&_87$$62);
						ZVAL_LONG(&_87$$62, 26);
						zephir_array_update_string(&definition, SL("type"), &_87$$62, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_88$$62);
						ZVAL_LONG(&_88$$62, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_88$$62, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 261)) {
						ZEPHIR_INIT_NVAR(&_89$$63);
						ZVAL_LONG(&_89$$63, 0);
						zephir_array_update_string(&definition, SL("type"), &_89$$63, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_90$$63);
						ZVAL_LONG(&_90$$63, 1);
						zephir_array_update_string(&definition, SL("bindType"), &_90$$63, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("bit"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 271)) {
						ZEPHIR_INIT_NVAR(&_91$$64);
						ZVAL_LONG(&_91$$64, 19);
						zephir_array_update_string(&definition, SL("type"), &_91$$64, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 280)) {
						ZEPHIR_INIT_NVAR(&_92$$65);
						ZVAL_LONG(&_92$$65, 18);
						zephir_array_update_string(&definition, SL("type"), &_92$$65, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 288)) {
						ZEPHIR_INIT_NVAR(&_93$$66);
						ZVAL_LONG(&_93$$66, 4);
						zephir_array_update_string(&definition, SL("type"), &_93$$66, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_94$$66);
						ZVAL_LONG(&_94$$66, 0);
						zephir_array_update_string(&definition, SL("size"), &_94$$66, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 297)) {
						ZEPHIR_INIT_NVAR(&_95$$67);
						ZVAL_LONG(&_95$$67, 1);
						zephir_array_update_string(&definition, SL("type"), &_95$$67, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_96$$67);
						ZVAL_LONG(&_96$$67, 0);
						zephir_array_update_string(&definition, SL("size"), &_96$$67, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 307) || _78$$57 == zephir_memnstr_str(&columnType, SL("numeric"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 308)) {
						ZEPHIR_INIT_NVAR(&_97$$68);
						ZVAL_LONG(&_97$$68, 3);
						zephir_array_update_string(&definition, SL("type"), &_97$$68, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_98$$68);
						ZVAL_LONG(&_98$$68, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_98$$68, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("double precision"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 319)) {
						ZEPHIR_INIT_NVAR(&_99$$69);
						ZVAL_LONG(&_99$$69, 9);
						zephir_array_update_string(&definition, SL("type"), &_99$$69, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_100$$69);
						ZVAL_LONG(&_100$$69, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_100$$69, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 330) || _78$$57 == zephir_memnstr_str(&columnType, SL("real"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 331)) {
						ZEPHIR_INIT_NVAR(&_101$$70);
						ZVAL_LONG(&_101$$70, 7);
						zephir_array_update_string(&definition, SL("type"), &_101$$70, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
						ZEPHIR_INIT_NVAR(&_102$$70);
						ZVAL_LONG(&_102$$70, 32);
						zephir_array_update_string(&definition, SL("bindType"), &_102$$70, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 342)) {
						ZEPHIR_INIT_NVAR(&_103$$71);
						ZVAL_LONG(&_103$$71, 6);
						zephir_array_update_string(&definition, SL("type"), &_103$$71, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 350)) {
						ZEPHIR_INIT_NVAR(&_104$$72);
						ZVAL_LONG(&_104$$72, 13);
						zephir_array_update_string(&definition, SL("type"), &_104$$72, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 358)) {
						ZEPHIR_INIT_NVAR(&_105$$73);
						ZVAL_LONG(&_105$$73, 10);
						zephir_array_update_string(&definition, SL("type"), &_105$$73, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("blob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 366)) {
						ZEPHIR_INIT_NVAR(&_106$$74);
						ZVAL_LONG(&_106$$74, 11);
						zephir_array_update_string(&definition, SL("type"), &_106$$74, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 374)) {
						ZEPHIR_INIT_NVAR(&_107$$75);
						ZVAL_LONG(&_107$$75, 17);
						zephir_array_update_string(&definition, SL("type"), &_107$$75, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("time"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 382)) {
						ZEPHIR_INIT_NVAR(&_108$$76);
						ZVAL_LONG(&_108$$76, 20);
						zephir_array_update_string(&definition, SL("type"), &_108$$76, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("jsonb"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 390)) {
						ZEPHIR_INIT_NVAR(&_109$$77);
						ZVAL_LONG(&_109$$77, 16);
						zephir_array_update_string(&definition, SL("type"), &_109$$77, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("json"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 398)) {
						ZEPHIR_INIT_NVAR(&_110$$78);
						ZVAL_LONG(&_110$$78, 15);
						zephir_array_update_string(&definition, SL("type"), &_110$$78, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("longtext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 406)) {
						ZEPHIR_INIT_NVAR(&_111$$79);
						ZVAL_LONG(&_111$$79, 24);
						zephir_array_update_string(&definition, SL("type"), &_111$$79, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("mediumtext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 414)) {
						ZEPHIR_INIT_NVAR(&_112$$80);
						ZVAL_LONG(&_112$$80, 23);
						zephir_array_update_string(&definition, SL("type"), &_112$$80, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("tinytext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 422)) {
						ZEPHIR_INIT_NVAR(&_113$$81);
						ZVAL_LONG(&_113$$81, 25);
						zephir_array_update_string(&definition, SL("type"), &_113$$81, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 430)) {
						ZEPHIR_INIT_NVAR(&_114$$82);
						ZVAL_LONG(&_114$$82, 6);
						zephir_array_update_string(&definition, SL("type"), &_114$$82, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("varying"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 438) || _78$$57 == zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 439)) {
						ZEPHIR_INIT_NVAR(&_115$$83);
						ZVAL_LONG(&_115$$83, 2);
						zephir_array_update_string(&definition, SL("type"), &_115$$83, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 448)) {
						ZEPHIR_INIT_NVAR(&_116$$84);
						ZVAL_LONG(&_116$$84, 5);
						zephir_array_update_string(&definition, SL("type"), &_116$$84, PH_COPY | PH_SEPARATE);
						zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("uuid"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 457)) {
						ZEPHIR_INIT_NVAR(&_117$$85);
						ZVAL_LONG(&_117$$85, 29);
						zephir_array_update_string(&definition, SL("type"), &_117$$85, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("bytea"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 465)) {
						ZEPHIR_INIT_NVAR(&_118$$86);
						ZVAL_LONG(&_118$$86, 30);
						zephir_array_update_string(&definition, SL("type"), &_118$$86, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("inet"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 473)) {
						ZEPHIR_INIT_NVAR(&_119$$87);
						ZVAL_LONG(&_119$$87, 31);
						zephir_array_update_string(&definition, SL("type"), &_119$$87, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("cidr"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 481)) {
						ZEPHIR_INIT_NVAR(&_120$$88);
						ZVAL_LONG(&_120$$88, 32);
						zephir_array_update_string(&definition, SL("type"), &_120$$88, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("macaddr"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 489)) {
						ZEPHIR_INIT_NVAR(&_121$$89);
						ZVAL_LONG(&_121$$89, 33);
						zephir_array_update_string(&definition, SL("type"), &_121$$89, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("int4range"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 498)) {
						ZEPHIR_INIT_NVAR(&_122$$90);
						ZVAL_LONG(&_122$$90, 34);
						zephir_array_update_string(&definition, SL("type"), &_122$$90, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("int8range"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 503)) {
						ZEPHIR_INIT_NVAR(&_123$$91);
						ZVAL_LONG(&_123$$91, 35);
						zephir_array_update_string(&definition, SL("type"), &_123$$91, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("numrange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 508)) {
						ZEPHIR_INIT_NVAR(&_124$$92);
						ZVAL_LONG(&_124$$92, 36);
						zephir_array_update_string(&definition, SL("type"), &_124$$92, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("tstzrange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 513)) {
						ZEPHIR_INIT_NVAR(&_125$$93);
						ZVAL_LONG(&_125$$93, 38);
						zephir_array_update_string(&definition, SL("type"), &_125$$93, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("tsrange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 518)) {
						ZEPHIR_INIT_NVAR(&_126$$94);
						ZVAL_LONG(&_126$$94, 37);
						zephir_array_update_string(&definition, SL("type"), &_126$$94, PH_COPY | PH_SEPARATE);
						break;
					}
					if (_78$$57 == zephir_memnstr_str(&columnType, SL("daterange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 523)) {
						ZEPHIR_INIT_NVAR(&_127$$95);
						ZVAL_LONG(&_127$$95, 39);
						zephir_array_update_string(&definition, SL("type"), &_127$$95, PH_COPY | PH_SEPARATE);
						break;
					}
					ZEPHIR_INIT_NVAR(&_128$$96);
					ZVAL_LONG(&_128$$96, 2);
					zephir_array_update_string(&definition, SL("type"), &_128$$96, PH_COPY | PH_SEPARATE);
					break;
				} while(0);

				_129$$57 = zephir_memnstr_str(&columnType, SL("ARRAY"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 544);
				if (!(_129$$57)) {
					_129$$57 = zephir_memnstr_str(&columnType, SL("[]"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 544);
				}
				if (_129$$57) {
					zephir_array_update_string(&definition, SL("array"), &__$true, PH_COPY | PH_SEPARATE);
				}
				if (Z_TYPE_P(&oldColumn) == IS_NULL) {
					zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_130$$57, &field, 6, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 560);
				if (ZEPHIR_IS_STRING(&_130$$57, "PRI")) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				}
				zephir_array_fetch_long(&_131$$57, &field, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 567);
				if (ZEPHIR_IS_STRING(&_131$$57, "YES")) {
					zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
				}
				isGenerated = 0;
				if (zephir_array_isset_value_long(&field, 11)) {
					zephir_array_fetch_long(&_132$$102, &field, 11, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 578);
					isGenerated = (ZEPHIR_IS_STRING_IDENTICAL(&_132$$102, "ALWAYS"));
				}
				if (isGenerated) {
					_133$$103 = zephir_array_isset_value_long(&field, 12);
					if (_133$$103) {
						zephir_array_fetch_long(&_134$$103, &field, 12, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 582);
						_133$$103 = Z_TYPE_P(&_134$$103) != IS_NULL;
					}
					if (_133$$103) {
						ZEPHIR_OBS_NVAR(&generationExpression);
						zephir_array_fetch_long(&generationExpression, &field, 12, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 583);
					} else {
						ZEPHIR_INIT_NVAR(&generationExpression);
						ZVAL_STRING(&generationExpression, "");
					}
					zephir_array_update_string(&definition, SL("generated"), &generationExpression, PH_COPY | PH_SEPARATE);
					zephir_array_update_string(&definition, SL("generationStored"), &__$true, PH_COPY | PH_SEPARATE);
				} else {
					zephir_array_fetch_long(&_135$$106, &field, 7, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 594);
					if (ZEPHIR_IS_STRING(&_135$$106, "auto_increment")) {
						zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
					}
					zephir_array_fetch_long(&_136$$106, &field, 9, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 601);
					if (Z_TYPE_P(&_136$$106) != IS_NULL) {
						zephir_array_fetch_long(&_137$$108, &field, 9, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 606);
						ZEPHIR_INIT_NVAR(&_138$$108);
						ZVAL_STRING(&_138$$108, "/^'|'?::[[:alnum:][:space:]]+$/");
						ZEPHIR_INIT_NVAR(&_139$$108);
						ZVAL_STRING(&_139$$108, "");
						ZEPHIR_CALL_FUNCTION(&_140$$108, "preg_replace", &_67, 76, &_138$$108, &_139$$108, &_137$$108);
						zephir_check_call_status();
						zephir_array_update_string(&definition, SL("default"), &_140$$108, PH_COPY | PH_SEPARATE);
						zephir_array_fetch_string(&_141$$108, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 608);
						ZEPHIR_INIT_NVAR(&_138$$108);
						ZVAL_STRING(&_138$$108, "null");
						ZEPHIR_CALL_FUNCTION(&_142$$108, "strcasecmp", &_70, 73, &_141$$108, &_138$$108);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG(&_142$$108, 0)) {
							zephir_array_update_string(&definition, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
						}
					}
				}
				zephir_array_fetch_long(&_143$$57, &field, 10, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 617);
				if (Z_TYPE_P(&_143$$57) != IS_NULL) {
					zephir_array_fetch_long(&_144$$110, &field, 10, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 618);
					zephir_array_update_string(&definition, SL("comment"), &_144$$110, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 624);
				ZEPHIR_INIT_NVAR(&_145$$57);
				object_init_ex(&_145$$57, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_145$$57, "__construct", &_74, 338, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_145$$57, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 625);
				ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		}
	}
	ZEPHIR_INIT_NVAR(&field);
	RETURN_CCTOR(&columns);
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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeReferences)
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
	zephir_is_iterable(&_0, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 681);
	if (Z_TYPE_P(&_0) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
		{
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _4);
			zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 650);
			if (!(zephir_array_isset_value(&references, &constraintName))) {
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 653);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 654);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 655);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 656);
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_5$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 660);
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_5$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 660);
				zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 661);
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_6$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 661);
				zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 662);
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_7$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 662);
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 663);
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_8$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 663);
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 664);
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_string(&referenceUpdate, &_9$$5, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 664);
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 665);
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_string(&referenceDelete, &_10$$5, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 665);
			}
			zephir_array_fetch_long(&_11$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 668);
			zephir_array_append(&columns, &_11$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 668);
			zephir_array_fetch_long(&_12$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 669);
			zephir_array_append(&referencedColumns, &_12$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 669);
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
				zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 650);
				if (!(zephir_array_isset_value(&references, &constraintName))) {
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 653);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 654);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 655);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 656);
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_16$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 660);
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_16$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 660);
					zephir_array_fetch(&_17$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 661);
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_17$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 661);
					zephir_array_fetch(&_18$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 662);
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_18$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 662);
					zephir_array_fetch(&_19$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 663);
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_19$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 663);
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 664);
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_string(&referenceUpdate, &_20$$8, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 664);
					zephir_array_fetch(&_21$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 665);
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_string(&referenceDelete, &_21$$8, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 665);
				}
				zephir_array_fetch_long(&_22$$6, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 668);
				zephir_array_append(&columns, &_22$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 668);
				zephir_array_fetch_long(&_23$$6, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 669);
				zephir_array_append(&referencedColumns, &_23$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 669);
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
	zephir_is_iterable(&references, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 697);
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
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 687);
		zephir_array_update_string(&_29$$9, SL("referencedSchema"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 688);
		zephir_array_update_string(&_29$$9, SL("referencedTable"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 689);
		zephir_array_update_string(&_29$$9, SL("columns"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 690);
		zephir_array_update_string(&_29$$9, SL("referencedColumns"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 691);
		zephir_array_update_string(&_29$$9, SL("onUpdate"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_30$$9);
		zephir_array_fetch_string(&_30$$9, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 693);
		zephir_array_update_string(&_29$$9, SL("onDelete"), &_30$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_28$$9, "__construct", &_31, 62, &name, &_29$$9);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_28$$9, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&referenceObjects);
}

/**
 * Returns the default identity value to be inserted in an identity column
 *
 *```php
 * // Inserting a new robot with a valid default value for the column 'id'
 * $success = $connection->insert(
 *     "robots",
 *     [
 *         $connection->getDefaultIdValue(),
 *         "Astro Boy",
 *         1952,
 *     ],
 *     [
 *         "id",
 *         "name",
 *         "year",
 *     ]
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "DEFAULT");
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 63, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Modifies a table column based on a definition
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, modifyColumn)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_3 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, sql, queries, query, exception, _0, *_1$$4, _2$$5, _4$$3, _5$$8, _6$$8, _7$$8;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&column_sub);
	ZVAL_UNDEF(&currentColumn_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&queries);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);
	ZVAL_UNDEF(&_7$$8);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(3, 4)
		Z_PARAM_STR(tableName)
		Z_PARAM_STR(schemaName)
		Z_PARAM_OBJECT_OF_CLASS(column, phalcon_db_columninterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(currentColumn, phalcon_db_columninterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	column = ZEND_CALL_ARG(execute_data, 3);
	if (ZEND_NUM_ARGS() > 3) {
		currentColumn = ZEND_CALL_ARG(execute_data, 4);
	}
	zephir_memory_observe(&tableName_zv);
	ZVAL_STR_COPY(&tableName_zv, tableName);
	zephir_memory_observe(&schemaName_zv);
	ZVAL_STR_COPY(&schemaName_zv, schemaName);
	if (!currentColumn) {
		currentColumn = &currentColumn_sub;
		currentColumn = &__$null;
	}
	zephir_read_property(&_0, this_ptr, ZEND_STRL("dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&sql, &_0, "modifycolumn", NULL, 0, &tableName_zv, &schemaName_zv, column, currentColumn);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&queries);
	zephir_fast_explode_str(&queries, SL(";"), &sql, LONG_MAX);
	if (zephir_fast_count_int(&queries) > 1) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(NULL, this_ptr, "begin", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_is_iterable(&queries, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 753);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&queries), _1$$4)
			{
				ZEPHIR_INIT_NVAR(&query);
				ZVAL_COPY(&query, _1$$4);
				if (ZEPHIR_IS_EMPTY(&query)) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_2$$5);
				ZEPHIR_CONCAT_VS(&_2$$5, &query, ";");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_3, 0, &_2$$5);
				zephir_check_call_status_or_jump(try_end_1);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&query);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "commit", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_4$$3);
			ZVAL_OBJ(&_4$$3, EG(exception));
			Z_ADDREF_P(&_4$$3);
			if (zephir_is_instance_of(&_4$$3, SL("Throwable"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&exception, &_4$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 757);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		ZEPHIR_INIT_VAR(&_5$$8);
		if (!(ZEPHIR_IS_EMPTY(&sql))) {
			zephir_array_fetch_long(&_6$$8, &queries, 0, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 760);
			ZEPHIR_INIT_VAR(&_7$$8);
			ZEPHIR_CONCAT_VS(&_7$$8, &_6$$8, ";");
			ZEPHIR_CALL_METHOD(&_5$$8, this_ptr, "execute", NULL, 0, &_7$$8);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&_5$$8);
			ZVAL_BOOL(&_5$$8, 1);
		}
		RETURN_CCTOR(&_5$$8);
	}
	RETURN_MM_BOOL(1);
}

/**
 * Check whether the database system requires a sequence to produce
 * auto-numeric values
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences)
{

	RETURN_BOOL(1);
}

/**
 * Check whether the database system requires an explicit value for identity
 * columns
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, useExplicitIdValue)
{

	RETURN_BOOL(1);
}

/**
 * Returns PDO adapter DSN defaults as a key-value map.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDsnDefaults)
{

	array_init(return_value);
	return;
}

