
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
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/main.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "kernel/exception.h"


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
 *
 * @phpstan-import-type db_descriptor from DbTypes
 * @phpstan-import-type db_dsn_defaults from DbTypes
 * @phpstan-import-type db_table_definition from DbTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Postgresql)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Postgresql, phalcon, db_adapter_pdo_postgresql, phalcon_db_adapter_pdo_abstractpdo_ce, phalcon_db_adapter_pdo_postgresql_method_entry, 0);

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "postgresql", sizeof("postgresql") - 1);
		zephir_declare_typed_property(phalcon_db_adapter_pdo_postgresql_ce, SL("dialectType"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "pgsql", sizeof("pgsql") - 1);
		zephir_declare_typed_property(phalcon_db_adapter_pdo_postgresql_ce, SL("type"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	return SUCCESS;
}

/**
 * Constructor for Phalcon\Db\Adapter\Pdo\Postgresql
 *
 * @phpstan-param db_descriptor $descriptor
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, __construct)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, _1$$3;
	zval descriptor;

	ZVAL_UNDEF(&descriptor);
	ZVAL_UNDEF(&_1$$3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		ZEPHIR_Z_PARAM_ARRAY(descriptor, descriptor_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &descriptor_param);
	zephir_get_arrval(&descriptor, descriptor_param);
	_0 = zephir_array_isset_value_string(&descriptor, SL("charset"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_0) {
		ZEPHIR_INIT_VAR(&_1$$3);
		ZVAL_STRING(&_1$$3, "Postgres does not allow the charset to be changed in the DSN.");
		ZEPHIR_CALL_FUNCTION(NULL, "trigger_error", NULL, 11, &_1$$3);
		zephir_check_call_status();
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_postgresql_ce, getThis(), "__construct", NULL, 0, &descriptor);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo
 * constructor. Call it when you need to restore a database connection.
 *
 * @phpstan-param db_descriptor $descriptor
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, connect)
{
	zend_bool _1, _2, _3, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *descriptor_param = NULL, __$null, schema, sql, _4, _6, _0$$3;
	zval descriptor;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&descriptor);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&schema);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_0$$3);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("descriptor", 10, 1);
	}

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
		zephir_get_arrval(&descriptor, descriptor_param);
	}
	if (ZEPHIR_IS_EMPTY(&descriptor)) {
		zephir_read_property_cached(&_0$$3, this_ptr, _zephir_prop_0, 612, PH_NOISY_CC | PH_READONLY);
		if (UNEXPECTED(Z_TYPE_P(&_0$$3) != IS_ARRAY)) {
			zephir_throw_variable_type_error(&_0$$3, "descriptor", "array");
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CPY_WRT(&descriptor, &_0$$3);
	}
	zephir_memory_observe(&schema);
	_1 = zephir_array_isset_string_fetch(&schema, &descriptor, SL("schema"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (_1) {
		zephir_array_unset_string(&descriptor, SL("schema"), PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} else {
		ZEPHIR_INIT_NVAR(&schema);
		ZVAL_NULL(&schema);
	}
	_2 = zephir_array_isset_value_string(&descriptor, SL("password"));
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_3 = _2;
	if (_3) {
		zephir_memory_observe(&_4);
		zephir_array_fetch_string(&_4, &descriptor, SL("password"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 88);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_3 = Z_TYPE_P(&_4) == IS_STRING;
	}
	_5 = _3;
	if (_5) {
		zephir_memory_observe(&_6);
		zephir_array_fetch_string(&_6, &descriptor, SL("password"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 89);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		_5 = zephir_fast_strlen_ev(&_6) == 0;
	}
	if (_5) {
		zephir_array_update_string(&descriptor, SL("password"), &__$null, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_db_adapter_pdo_postgresql_ce, getThis(), "connect", NULL, 0, &descriptor);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(&schema))) {
		ZEPHIR_INIT_VAR(&sql);
		ZEPHIR_CONCAT_SVS(&sql, "SET search_path TO '", &schema, "'");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, &sql);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Creates a table
 *
 * @phpstan-param db_table_definition $definition
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, createTable)
{
	zend_bool _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_2 = NULL, *_4 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval definition;
	zval tableName_zv, schemaName_zv, *definition_param = NULL, sql, queries, query, exception, columns, _5, _1$$3, _3$$4, *_6$$6, _7$$6, *_8$$6, _9$$7, _11$$5, _12$$11, _13$$11;
	zend_string *tableName = NULL, *schemaName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tableName_zv);
	ZVAL_UNDEF(&schemaName_zv);
	ZVAL_UNDEF(&sql);
	ZVAL_UNDEF(&queries);
	ZVAL_UNDEF(&query);
	ZVAL_UNDEF(&exception);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_11$$5);
	ZVAL_UNDEF(&_12$$11);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&definition);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

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
	zephir_get_arrval(&definition, definition_param);
	zephir_memory_observe(&columns);
	_0 = zephir_array_isset_string_fetch(&columns, &definition, SL("columns"), 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(!(_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_db_exceptions_tablemusthavecolumn_ce);
		ZEPHIR_CALL_METHOD(NULL, &_1$$3, "__construct", &_2, 59);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 112);
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (UNEXPECTED(ZEPHIR_IS_EMPTY(&columns))) {
		ZEPHIR_INIT_VAR(&_3$$4);
		object_init_ex(&_3$$4, phalcon_db_exceptions_tablemusthavecolumn_ce);
		ZEPHIR_CALL_METHOD(NULL, &_3$$4, "__construct", &_4, 59);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_3$$4, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 116);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_5, this_ptr, _zephir_prop_0, 613, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&sql, &_5, "createTable", NULL, 0, &tableName_zv, &schemaName_zv, &definition);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&queries);
	zephir_fast_explode_str(&queries, SL(";"), &sql, NULL);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_fast_count_int(&queries) > 1) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(NULL, this_ptr, "begin", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (Z_TYPE_P(&queries) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_7$$6);
				zephir_string_to_char_array(&_7$$6, &queries);
				_6$$6 = &_7$$6;
			} else {
				_6$$6 = &queries;
			}
			zephir_is_iterable(_6$$6, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 135);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_6$$6), _8$$6)
			{
				ZEPHIR_INIT_NVAR(&query);
				ZVAL_COPY(&query, _8$$6);
				if (ZEPHIR_IS_EMPTY(&query)) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_9$$7);
				ZEPHIR_CONCAT_VS(&_9$$7, &query, ";");
				if (UNEXPECTED(EG(exception))) {
					goto try_end_1;
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_10, 0, &_9$$7);
				zephir_check_call_status_or_jump(try_end_1);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&query);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "commit", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_11$$5);
			ZVAL_OBJ(&_11$$5, EG(exception));
			Z_ADDREF_P(&_11$$5);
			if (zephir_is_instance_of(&_11$$5, SL("Throwable"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&exception, &_11$$5);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 139);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		zephir_memory_observe(&_12$$11);
		zephir_array_fetch_long(&_12$$11, &queries, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 142);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_INIT_VAR(&_13$$11);
		ZEPHIR_CONCAT_VS(&_13$$11, &_12$$11, ";");
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, &_13$$11);
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
	zend_bool isGenerated = 0, _80, _6$$3, _57$$3, _60$$3, _62$$49, _63$$49, _82$$57, _133$$57, _136$$57, _138$$103, _139$$103;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_71 = NULL, *_74 = NULL, *_78 = NULL, *_152 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, __$true, __$false, __$null, columns, columnType, fields, field, definition, oldColumn, columnName, charSize, numericSize, numericScale, generationExpression, _0, _1, _2, *_3, _4, *_5, _79, _58$$3, _59$$3, _75$$3, _77$$3, _7$$4, _8$$4, _9$$5, _10$$5, _11$$6, _12$$6, _13$$7, _14$$7, _15$$8, _16$$8, _17$$9, _18$$9, _19$$10, _20$$11, _21$$12, _22$$12, _23$$13, _24$$13, _25$$14, _26$$14, _27$$15, _28$$15, _29$$16, _30$$16, _31$$17, _32$$18, _33$$19, _34$$20, _35$$21, _36$$22, _37$$23, _38$$24, _39$$25, _40$$26, _41$$27, _42$$28, _43$$29, _44$$30, _45$$31, _46$$32, _47$$33, _48$$34, _49$$35, _50$$36, _51$$37, _52$$38, _53$$39, _54$$40, _55$$41, _56$$42, _61$$48, _64$$49, _65$$52, _66$$52, _67$$54, _68$$54, _69$$54, _70$$54, _72$$54, _73$$54, _76$$56, _81$$57, _134$$57, _135$$57, _149$$57, _151$$57, _83$$58, _84$$58, _85$$59, _86$$59, _87$$60, _88$$60, _89$$61, _90$$61, _91$$62, _92$$62, _93$$63, _94$$63, _95$$64, _96$$65, _97$$66, _98$$66, _99$$67, _100$$67, _101$$68, _102$$68, _103$$69, _104$$69, _105$$70, _106$$70, _107$$71, _108$$72, _109$$73, _110$$74, _111$$75, _112$$76, _113$$77, _114$$78, _115$$79, _116$$80, _117$$81, _118$$82, _119$$83, _120$$84, _121$$85, _122$$86, _123$$87, _124$$88, _125$$89, _126$$90, _127$$91, _128$$92, _129$$93, _130$$94, _131$$95, _132$$96, _137$$102, _140$$103, _141$$106, _142$$106, _143$$108, _144$$108, _145$$108, _146$$108, _147$$108, _148$$108, _150$$110;
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
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_79);
	ZVAL_UNDEF(&_58$$3);
	ZVAL_UNDEF(&_59$$3);
	ZVAL_UNDEF(&_75$$3);
	ZVAL_UNDEF(&_77$$3);
	ZVAL_UNDEF(&_7$$4);
	ZVAL_UNDEF(&_8$$4);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$6);
	ZVAL_UNDEF(&_12$$6);
	ZVAL_UNDEF(&_13$$7);
	ZVAL_UNDEF(&_14$$7);
	ZVAL_UNDEF(&_15$$8);
	ZVAL_UNDEF(&_16$$8);
	ZVAL_UNDEF(&_17$$9);
	ZVAL_UNDEF(&_18$$9);
	ZVAL_UNDEF(&_19$$10);
	ZVAL_UNDEF(&_20$$11);
	ZVAL_UNDEF(&_21$$12);
	ZVAL_UNDEF(&_22$$12);
	ZVAL_UNDEF(&_23$$13);
	ZVAL_UNDEF(&_24$$13);
	ZVAL_UNDEF(&_25$$14);
	ZVAL_UNDEF(&_26$$14);
	ZVAL_UNDEF(&_27$$15);
	ZVAL_UNDEF(&_28$$15);
	ZVAL_UNDEF(&_29$$16);
	ZVAL_UNDEF(&_30$$16);
	ZVAL_UNDEF(&_31$$17);
	ZVAL_UNDEF(&_32$$18);
	ZVAL_UNDEF(&_33$$19);
	ZVAL_UNDEF(&_34$$20);
	ZVAL_UNDEF(&_35$$21);
	ZVAL_UNDEF(&_36$$22);
	ZVAL_UNDEF(&_37$$23);
	ZVAL_UNDEF(&_38$$24);
	ZVAL_UNDEF(&_39$$25);
	ZVAL_UNDEF(&_40$$26);
	ZVAL_UNDEF(&_41$$27);
	ZVAL_UNDEF(&_42$$28);
	ZVAL_UNDEF(&_43$$29);
	ZVAL_UNDEF(&_44$$30);
	ZVAL_UNDEF(&_45$$31);
	ZVAL_UNDEF(&_46$$32);
	ZVAL_UNDEF(&_47$$33);
	ZVAL_UNDEF(&_48$$34);
	ZVAL_UNDEF(&_49$$35);
	ZVAL_UNDEF(&_50$$36);
	ZVAL_UNDEF(&_51$$37);
	ZVAL_UNDEF(&_52$$38);
	ZVAL_UNDEF(&_53$$39);
	ZVAL_UNDEF(&_54$$40);
	ZVAL_UNDEF(&_55$$41);
	ZVAL_UNDEF(&_56$$42);
	ZVAL_UNDEF(&_61$$48);
	ZVAL_UNDEF(&_64$$49);
	ZVAL_UNDEF(&_65$$52);
	ZVAL_UNDEF(&_66$$52);
	ZVAL_UNDEF(&_67$$54);
	ZVAL_UNDEF(&_68$$54);
	ZVAL_UNDEF(&_69$$54);
	ZVAL_UNDEF(&_70$$54);
	ZVAL_UNDEF(&_72$$54);
	ZVAL_UNDEF(&_73$$54);
	ZVAL_UNDEF(&_76$$56);
	ZVAL_UNDEF(&_81$$57);
	ZVAL_UNDEF(&_134$$57);
	ZVAL_UNDEF(&_135$$57);
	ZVAL_UNDEF(&_149$$57);
	ZVAL_UNDEF(&_151$$57);
	ZVAL_UNDEF(&_83$$58);
	ZVAL_UNDEF(&_84$$58);
	ZVAL_UNDEF(&_85$$59);
	ZVAL_UNDEF(&_86$$59);
	ZVAL_UNDEF(&_87$$60);
	ZVAL_UNDEF(&_88$$60);
	ZVAL_UNDEF(&_89$$61);
	ZVAL_UNDEF(&_90$$61);
	ZVAL_UNDEF(&_91$$62);
	ZVAL_UNDEF(&_92$$62);
	ZVAL_UNDEF(&_93$$63);
	ZVAL_UNDEF(&_94$$63);
	ZVAL_UNDEF(&_95$$64);
	ZVAL_UNDEF(&_96$$65);
	ZVAL_UNDEF(&_97$$66);
	ZVAL_UNDEF(&_98$$66);
	ZVAL_UNDEF(&_99$$67);
	ZVAL_UNDEF(&_100$$67);
	ZVAL_UNDEF(&_101$$68);
	ZVAL_UNDEF(&_102$$68);
	ZVAL_UNDEF(&_103$$69);
	ZVAL_UNDEF(&_104$$69);
	ZVAL_UNDEF(&_105$$70);
	ZVAL_UNDEF(&_106$$70);
	ZVAL_UNDEF(&_107$$71);
	ZVAL_UNDEF(&_108$$72);
	ZVAL_UNDEF(&_109$$73);
	ZVAL_UNDEF(&_110$$74);
	ZVAL_UNDEF(&_111$$75);
	ZVAL_UNDEF(&_112$$76);
	ZVAL_UNDEF(&_113$$77);
	ZVAL_UNDEF(&_114$$78);
	ZVAL_UNDEF(&_115$$79);
	ZVAL_UNDEF(&_116$$80);
	ZVAL_UNDEF(&_117$$81);
	ZVAL_UNDEF(&_118$$82);
	ZVAL_UNDEF(&_119$$83);
	ZVAL_UNDEF(&_120$$84);
	ZVAL_UNDEF(&_121$$85);
	ZVAL_UNDEF(&_122$$86);
	ZVAL_UNDEF(&_123$$87);
	ZVAL_UNDEF(&_124$$88);
	ZVAL_UNDEF(&_125$$89);
	ZVAL_UNDEF(&_126$$90);
	ZVAL_UNDEF(&_127$$91);
	ZVAL_UNDEF(&_128$$92);
	ZVAL_UNDEF(&_129$$93);
	ZVAL_UNDEF(&_130$$94);
	ZVAL_UNDEF(&_131$$95);
	ZVAL_UNDEF(&_132$$96);
	ZVAL_UNDEF(&_137$$102);
	ZVAL_UNDEF(&_140$$103);
	ZVAL_UNDEF(&_141$$106);
	ZVAL_UNDEF(&_142$$106);
	ZVAL_UNDEF(&_143$$108);
	ZVAL_UNDEF(&_144$$108);
	ZVAL_UNDEF(&_145$$108);
	ZVAL_UNDEF(&_146$$108);
	ZVAL_UNDEF(&_147$$108);
	ZVAL_UNDEF(&_148$$108);
	ZVAL_UNDEF(&_150$$110);
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
	ZEPHIR_INIT_VAR(&oldColumn);
	ZVAL_NULL(&oldColumn);
	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 613, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, &_0, "describeColumns", NULL, 0, &table_zv, &schema_zv);
	zephir_check_call_status();
	ZVAL_LONG(&_2, 3);
	ZEPHIR_CALL_METHOD(&fields, this_ptr, "fetchAll", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	if (Z_TYPE_P(&fields) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_4);
		zephir_string_to_char_array(&_4, &fields);
		_3 = &_4;
	} else {
		_3 = &fields;
	}
	zephir_is_iterable(_3, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 633);
	if (Z_TYPE_P(_3) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_3), _5)
		{
			ZEPHIR_INIT_NVAR(&field);
			ZVAL_COPY(&field, _5);
			ZEPHIR_INIT_NVAR(&definition);
			zephir_create_array(&definition, 1, 0);
			add_assoc_long_ex(&definition, SL("bindType"), 2);
			ZEPHIR_OBS_NVAR(&columnType);
			zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 189);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&charSize);
			zephir_array_fetch_long(&charSize, &field, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 190);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&numericSize);
			zephir_array_fetch_long(&numericSize, &field, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 191);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&numericScale);
			zephir_array_fetch_long(&numericScale, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 192);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			_6$$3 = 1;
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("boolean"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 210)) { goto zephir_switch_0_clause_0; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 222)) { goto zephir_switch_0_clause_1; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("mediumint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 232)) { goto zephir_switch_0_clause_2; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("smallint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 242)) { goto zephir_switch_0_clause_3; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("tinyint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 252)) { goto zephir_switch_0_clause_4; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 265)) { goto zephir_switch_0_clause_5; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("bit"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 275)) { goto zephir_switch_0_clause_6; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 284)) { goto zephir_switch_0_clause_7; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 292)) { goto zephir_switch_0_clause_8; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 301)) { goto zephir_switch_0_clause_9; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 311)) { goto zephir_switch_0_clause_10; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("numeric"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 312)) { goto zephir_switch_0_clause_11; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("double precision"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 323)) { goto zephir_switch_0_clause_12; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 334)) { goto zephir_switch_0_clause_13; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("real"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 335)) { goto zephir_switch_0_clause_14; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 346)) { goto zephir_switch_0_clause_15; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 354)) { goto zephir_switch_0_clause_16; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 362)) { goto zephir_switch_0_clause_17; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("blob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 370)) { goto zephir_switch_0_clause_18; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 378)) { goto zephir_switch_0_clause_19; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("time"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 386)) { goto zephir_switch_0_clause_20; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("jsonb"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 394)) { goto zephir_switch_0_clause_21; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("json"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 402)) { goto zephir_switch_0_clause_22; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("longtext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 410)) { goto zephir_switch_0_clause_23; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("mediumtext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 418)) { goto zephir_switch_0_clause_24; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("tinytext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 426)) { goto zephir_switch_0_clause_25; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 434)) { goto zephir_switch_0_clause_26; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("varying"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 442)) { goto zephir_switch_0_clause_27; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 443)) { goto zephir_switch_0_clause_28; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 452)) { goto zephir_switch_0_clause_29; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("uuid"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 461)) { goto zephir_switch_0_clause_30; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("bytea"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 469)) { goto zephir_switch_0_clause_31; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("inet"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 477)) { goto zephir_switch_0_clause_32; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("cidr"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 485)) { goto zephir_switch_0_clause_33; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("macaddr"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 493)) { goto zephir_switch_0_clause_34; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("int4range"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 502)) { goto zephir_switch_0_clause_35; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("int8range"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 507)) { goto zephir_switch_0_clause_36; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("numrange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 512)) { goto zephir_switch_0_clause_37; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("tstzrange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 517)) { goto zephir_switch_0_clause_38; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("tsrange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 522)) { goto zephir_switch_0_clause_39; }
			if (_6$$3 == zephir_memnstr_str(&columnType, SL("daterange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 527)) { goto zephir_switch_0_clause_40; }
			goto zephir_switch_0_clause_41;
			zephir_switch_0_clause_0: ;
				ZEPHIR_INIT_NVAR(&_7$$4);
				ZVAL_LONG(&_7$$4, 8);
				zephir_array_update_string(&definition, SL("type"), &_7$$4, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_8$$4);
				ZVAL_LONG(&_8$$4, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_8$$4, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_1: ;
				ZEPHIR_INIT_NVAR(&_9$$5);
				ZVAL_LONG(&_9$$5, 14);
				zephir_array_update_string(&definition, SL("type"), &_9$$5, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_10$$5);
				ZVAL_LONG(&_10$$5, 2);
				zephir_array_update_string(&definition, SL("bindType"), &_10$$5, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_2: ;
				ZEPHIR_INIT_NVAR(&_11$$6);
				ZVAL_LONG(&_11$$6, 21);
				zephir_array_update_string(&definition, SL("type"), &_11$$6, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_12$$6);
				ZVAL_LONG(&_12$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_12$$6, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_3: ;
				ZEPHIR_INIT_NVAR(&_13$$7);
				ZVAL_LONG(&_13$$7, 22);
				zephir_array_update_string(&definition, SL("type"), &_13$$7, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_14$$7);
				ZVAL_LONG(&_14$$7, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_14$$7, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_4: ;
				ZEPHIR_INIT_NVAR(&_15$$8);
				ZVAL_LONG(&_15$$8, 26);
				zephir_array_update_string(&definition, SL("type"), &_15$$8, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_16$$8);
				ZVAL_LONG(&_16$$8, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_16$$8, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_5: ;
				ZEPHIR_INIT_NVAR(&_17$$9);
				ZVAL_LONG(&_17$$9, 0);
				zephir_array_update_string(&definition, SL("type"), &_17$$9, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_18$$9);
				ZVAL_LONG(&_18$$9, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_18$$9, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_6: ;
				ZEPHIR_INIT_NVAR(&_19$$10);
				ZVAL_LONG(&_19$$10, 19);
				zephir_array_update_string(&definition, SL("type"), &_19$$10, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_7: ;
				ZEPHIR_INIT_NVAR(&_20$$11);
				ZVAL_LONG(&_20$$11, 18);
				zephir_array_update_string(&definition, SL("type"), &_20$$11, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_8: ;
				ZEPHIR_INIT_NVAR(&_21$$12);
				ZVAL_LONG(&_21$$12, 4);
				zephir_array_update_string(&definition, SL("type"), &_21$$12, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_22$$12);
				ZVAL_LONG(&_22$$12, 0);
				zephir_array_update_string(&definition, SL("size"), &_22$$12, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_9: ;
				ZEPHIR_INIT_NVAR(&_23$$13);
				ZVAL_LONG(&_23$$13, 1);
				zephir_array_update_string(&definition, SL("type"), &_23$$13, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_24$$13);
				ZVAL_LONG(&_24$$13, 0);
				zephir_array_update_string(&definition, SL("size"), &_24$$13, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_10: ;
			zephir_switch_0_clause_11: ;
				ZEPHIR_INIT_NVAR(&_25$$14);
				ZVAL_LONG(&_25$$14, 3);
				zephir_array_update_string(&definition, SL("type"), &_25$$14, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_26$$14);
				ZVAL_LONG(&_26$$14, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_26$$14, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_12: ;
				ZEPHIR_INIT_NVAR(&_27$$15);
				ZVAL_LONG(&_27$$15, 9);
				zephir_array_update_string(&definition, SL("type"), &_27$$15, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_28$$15);
				ZVAL_LONG(&_28$$15, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_28$$15, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_13: ;
			zephir_switch_0_clause_14: ;
				ZEPHIR_INIT_NVAR(&_29$$16);
				ZVAL_LONG(&_29$$16, 7);
				zephir_array_update_string(&definition, SL("type"), &_29$$16, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_30$$16);
				ZVAL_LONG(&_30$$16, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_30$$16, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_15: ;
				ZEPHIR_INIT_NVAR(&_31$$17);
				ZVAL_LONG(&_31$$17, 12);
				zephir_array_update_string(&definition, SL("type"), &_31$$17, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_16: ;
				ZEPHIR_INIT_NVAR(&_32$$18);
				ZVAL_LONG(&_32$$18, 13);
				zephir_array_update_string(&definition, SL("type"), &_32$$18, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_17: ;
				ZEPHIR_INIT_NVAR(&_33$$19);
				ZVAL_LONG(&_33$$19, 10);
				zephir_array_update_string(&definition, SL("type"), &_33$$19, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_18: ;
				ZEPHIR_INIT_NVAR(&_34$$20);
				ZVAL_LONG(&_34$$20, 11);
				zephir_array_update_string(&definition, SL("type"), &_34$$20, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_19: ;
				ZEPHIR_INIT_NVAR(&_35$$21);
				ZVAL_LONG(&_35$$21, 17);
				zephir_array_update_string(&definition, SL("type"), &_35$$21, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_20: ;
				ZEPHIR_INIT_NVAR(&_36$$22);
				ZVAL_LONG(&_36$$22, 20);
				zephir_array_update_string(&definition, SL("type"), &_36$$22, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_21: ;
				ZEPHIR_INIT_NVAR(&_37$$23);
				ZVAL_LONG(&_37$$23, 16);
				zephir_array_update_string(&definition, SL("type"), &_37$$23, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_22: ;
				ZEPHIR_INIT_NVAR(&_38$$24);
				ZVAL_LONG(&_38$$24, 15);
				zephir_array_update_string(&definition, SL("type"), &_38$$24, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_23: ;
				ZEPHIR_INIT_NVAR(&_39$$25);
				ZVAL_LONG(&_39$$25, 24);
				zephir_array_update_string(&definition, SL("type"), &_39$$25, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_24: ;
				ZEPHIR_INIT_NVAR(&_40$$26);
				ZVAL_LONG(&_40$$26, 23);
				zephir_array_update_string(&definition, SL("type"), &_40$$26, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_25: ;
				ZEPHIR_INIT_NVAR(&_41$$27);
				ZVAL_LONG(&_41$$27, 25);
				zephir_array_update_string(&definition, SL("type"), &_41$$27, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_26: ;
				ZEPHIR_INIT_NVAR(&_42$$28);
				ZVAL_LONG(&_42$$28, 6);
				zephir_array_update_string(&definition, SL("type"), &_42$$28, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_27: ;
			zephir_switch_0_clause_28: ;
				ZEPHIR_INIT_NVAR(&_43$$29);
				ZVAL_LONG(&_43$$29, 2);
				zephir_array_update_string(&definition, SL("type"), &_43$$29, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_29: ;
				ZEPHIR_INIT_NVAR(&_44$$30);
				ZVAL_LONG(&_44$$30, 5);
				zephir_array_update_string(&definition, SL("type"), &_44$$30, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_30: ;
				ZEPHIR_INIT_NVAR(&_45$$31);
				ZVAL_LONG(&_45$$31, 29);
				zephir_array_update_string(&definition, SL("type"), &_45$$31, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_31: ;
				ZEPHIR_INIT_NVAR(&_46$$32);
				ZVAL_LONG(&_46$$32, 30);
				zephir_array_update_string(&definition, SL("type"), &_46$$32, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_32: ;
				ZEPHIR_INIT_NVAR(&_47$$33);
				ZVAL_LONG(&_47$$33, 31);
				zephir_array_update_string(&definition, SL("type"), &_47$$33, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_33: ;
				ZEPHIR_INIT_NVAR(&_48$$34);
				ZVAL_LONG(&_48$$34, 32);
				zephir_array_update_string(&definition, SL("type"), &_48$$34, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_34: ;
				ZEPHIR_INIT_NVAR(&_49$$35);
				ZVAL_LONG(&_49$$35, 33);
				zephir_array_update_string(&definition, SL("type"), &_49$$35, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_35: ;
				ZEPHIR_INIT_NVAR(&_50$$36);
				ZVAL_LONG(&_50$$36, 34);
				zephir_array_update_string(&definition, SL("type"), &_50$$36, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_36: ;
				ZEPHIR_INIT_NVAR(&_51$$37);
				ZVAL_LONG(&_51$$37, 35);
				zephir_array_update_string(&definition, SL("type"), &_51$$37, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_37: ;
				ZEPHIR_INIT_NVAR(&_52$$38);
				ZVAL_LONG(&_52$$38, 36);
				zephir_array_update_string(&definition, SL("type"), &_52$$38, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_38: ;
				ZEPHIR_INIT_NVAR(&_53$$39);
				ZVAL_LONG(&_53$$39, 38);
				zephir_array_update_string(&definition, SL("type"), &_53$$39, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_39: ;
				ZEPHIR_INIT_NVAR(&_54$$40);
				ZVAL_LONG(&_54$$40, 37);
				zephir_array_update_string(&definition, SL("type"), &_54$$40, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_40: ;
				ZEPHIR_INIT_NVAR(&_55$$41);
				ZVAL_LONG(&_55$$41, 39);
				zephir_array_update_string(&definition, SL("type"), &_55$$41, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_clause_41: ;
				ZEPHIR_INIT_NVAR(&_56$$42);
				ZVAL_LONG(&_56$$42, 2);
				zephir_array_update_string(&definition, SL("type"), &_56$$42, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				goto zephir_switch_0_end;
			zephir_switch_0_end: ;

			_57$$3 = zephir_memnstr_str(&columnType, SL("ARRAY"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 548);
			if (!(_57$$3)) {
				_57$$3 = zephir_memnstr_str(&columnType, SL("[]"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 548);
			}
			if (_57$$3) {
				zephir_array_update_string(&definition, SL("array"), &__$true, PH_COPY | PH_SEPARATE);
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
			ZEPHIR_OBS_NVAR(&_58$$3);
			zephir_array_fetch_long(&_58$$3, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 564);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_STRING(&_58$$3, "PRI")) {
				zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&_59$$3);
			zephir_array_fetch_long(&_59$$3, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 571);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (ZEPHIR_IS_STRING(&_59$$3, "YES")) {
				zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			isGenerated = 0;
			_60$$3 = zephir_array_isset_value_long(&field, 11);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (_60$$3) {
				ZEPHIR_OBS_NVAR(&_61$$48);
				zephir_array_fetch_long(&_61$$48, &field, 11, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 582);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				isGenerated = (ZEPHIR_IS_STRING_IDENTICAL(&_61$$48, "ALWAYS"));
			}
			if (isGenerated) {
				_62$$49 = zephir_array_isset_value_long(&field, 12);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_63$$49 = _62$$49;
				if (_63$$49) {
					ZEPHIR_OBS_NVAR(&_64$$49);
					zephir_array_fetch_long(&_64$$49, &field, 12, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 586);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_63$$49 = Z_TYPE_P(&_64$$49) != IS_NULL;
				}
				if (_63$$49) {
					ZEPHIR_OBS_NVAR(&generationExpression);
					zephir_array_fetch_long(&generationExpression, &field, 12, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 587);
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
				zephir_array_update_string(&definition, SL("generationStored"), &__$true, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			} else {
				ZEPHIR_OBS_NVAR(&_65$$52);
				zephir_array_fetch_long(&_65$$52, &field, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 598);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_STRING(&_65$$52, "auto_increment")) {
					zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&_66$$52);
				zephir_array_fetch_long(&_66$$52, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 605);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&_66$$52) != IS_NULL) {
					ZEPHIR_OBS_NVAR(&_67$$54);
					zephir_array_fetch_long(&_67$$54, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 610);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_68$$54);
					ZVAL_STRING(&_68$$54, "/(?:^')|(?:'?::[[:alnum:][:space:]]+$)/");
					ZEPHIR_INIT_NVAR(&_69$$54);
					ZVAL_STRING(&_69$$54, "");
					ZEPHIR_CALL_FUNCTION(&_70$$54, "preg_replace", &_71, 4, &_68$$54, &_69$$54, &_67$$54);
					zephir_check_call_status();
					zephir_array_update_string(&definition, SL("default"), &_70$$54, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch_string(&_72$$54, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 612);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_68$$54);
					ZVAL_STRING(&_68$$54, "null");
					ZEPHIR_CALL_FUNCTION(&_73$$54, "strcasecmp", &_74, 85, &_72$$54, &_68$$54);
					zephir_check_call_status();
					if (ZEPHIR_IS_LONG(&_73$$54, 0)) {
						zephir_array_update_string(&definition, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
				}
			}
			ZEPHIR_OBS_NVAR(&_75$$3);
			zephir_array_fetch_long(&_75$$3, &field, 10, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 621);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			if (Z_TYPE_P(&_75$$3) != IS_NULL) {
				ZEPHIR_OBS_NVAR(&_76$$56);
				zephir_array_fetch_long(&_76$$56, &field, 10, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 622);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_update_string(&definition, SL("comment"), &_76$$56, PH_COPY | PH_SEPARATE);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&columnName);
			zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 628);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_NVAR(&_77$$3);
			object_init_ex(&_77$$3, phalcon_db_column_ce);
			ZEPHIR_CALL_METHOD(NULL, &_77$$3, "__construct", &_78, 0, &columnName, &definition);
			zephir_check_call_status();
			zephir_array_append(&columns, &_77$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 629);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CPY_WRT(&oldColumn, &columnName);
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD(NULL, _3, "rewind", NULL, 0);
		zephir_check_call_status();
		_80 = 1;
		while (1) {
			if (_80) {
				_80 = 0;
			} else {
				ZEPHIR_CALL_METHOD(NULL, _3, "next", NULL, 0);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD(&_79, _3, "valid", NULL, 0);
			zephir_check_call_status();
			if (!zend_is_true(&_79)) {
				break;
			}
			ZEPHIR_CALL_METHOD(&field, _3, "current", NULL, 0);
			zephir_check_call_status();
				ZEPHIR_INIT_NVAR(&_81$$57);
				zephir_create_array(&_81$$57, 1, 0);
				add_assoc_long_ex(&_81$$57, SL("bindType"), 2);
				ZEPHIR_CPY_WRT(&definition, &_81$$57);
				ZEPHIR_OBS_NVAR(&columnType);
				zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 189);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&charSize);
				zephir_array_fetch_long(&charSize, &field, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 190);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&numericSize);
				zephir_array_fetch_long(&numericSize, &field, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 191);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&numericScale);
				zephir_array_fetch_long(&numericScale, &field, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 192);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				_82$$57 = 1;
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("boolean"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 210)) { goto zephir_switch_1_clause_0; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 222)) { goto zephir_switch_1_clause_1; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("mediumint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 232)) { goto zephir_switch_1_clause_2; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("smallint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 242)) { goto zephir_switch_1_clause_3; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("tinyint"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 252)) { goto zephir_switch_1_clause_4; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("int"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 265)) { goto zephir_switch_1_clause_5; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("bit"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 275)) { goto zephir_switch_1_clause_6; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("enum"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 284)) { goto zephir_switch_1_clause_7; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 292)) { goto zephir_switch_1_clause_8; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("date"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 301)) { goto zephir_switch_1_clause_9; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 311)) { goto zephir_switch_1_clause_10; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("numeric"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 312)) { goto zephir_switch_1_clause_11; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("double precision"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 323)) { goto zephir_switch_1_clause_12; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("float"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 334)) { goto zephir_switch_1_clause_13; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("real"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 335)) { goto zephir_switch_1_clause_14; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 346)) { goto zephir_switch_1_clause_15; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 354)) { goto zephir_switch_1_clause_16; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 362)) { goto zephir_switch_1_clause_17; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("blob"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 370)) { goto zephir_switch_1_clause_18; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 378)) { goto zephir_switch_1_clause_19; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("time"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 386)) { goto zephir_switch_1_clause_20; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("jsonb"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 394)) { goto zephir_switch_1_clause_21; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("json"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 402)) { goto zephir_switch_1_clause_22; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("longtext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 410)) { goto zephir_switch_1_clause_23; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("mediumtext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 418)) { goto zephir_switch_1_clause_24; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("tinytext"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 426)) { goto zephir_switch_1_clause_25; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("text"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 434)) { goto zephir_switch_1_clause_26; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("varying"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 442)) { goto zephir_switch_1_clause_27; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 443)) { goto zephir_switch_1_clause_28; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("char"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 452)) { goto zephir_switch_1_clause_29; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("uuid"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 461)) { goto zephir_switch_1_clause_30; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("bytea"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 469)) { goto zephir_switch_1_clause_31; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("inet"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 477)) { goto zephir_switch_1_clause_32; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("cidr"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 485)) { goto zephir_switch_1_clause_33; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("macaddr"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 493)) { goto zephir_switch_1_clause_34; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("int4range"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 502)) { goto zephir_switch_1_clause_35; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("int8range"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 507)) { goto zephir_switch_1_clause_36; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("numrange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 512)) { goto zephir_switch_1_clause_37; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("tstzrange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 517)) { goto zephir_switch_1_clause_38; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("tsrange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 522)) { goto zephir_switch_1_clause_39; }
				if (_82$$57 == zephir_memnstr_str(&columnType, SL("daterange"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 527)) { goto zephir_switch_1_clause_40; }
				goto zephir_switch_1_clause_41;
				zephir_switch_1_clause_0: ;
					ZEPHIR_INIT_NVAR(&_83$$58);
					ZVAL_LONG(&_83$$58, 8);
					zephir_array_update_string(&definition, SL("type"), &_83$$58, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_84$$58);
					ZVAL_LONG(&_84$$58, 5);
					zephir_array_update_string(&definition, SL("bindType"), &_84$$58, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_1: ;
					ZEPHIR_INIT_NVAR(&_85$$59);
					ZVAL_LONG(&_85$$59, 14);
					zephir_array_update_string(&definition, SL("type"), &_85$$59, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_86$$59);
					ZVAL_LONG(&_86$$59, 2);
					zephir_array_update_string(&definition, SL("bindType"), &_86$$59, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_2: ;
					ZEPHIR_INIT_NVAR(&_87$$60);
					ZVAL_LONG(&_87$$60, 21);
					zephir_array_update_string(&definition, SL("type"), &_87$$60, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_88$$60);
					ZVAL_LONG(&_88$$60, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_88$$60, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_3: ;
					ZEPHIR_INIT_NVAR(&_89$$61);
					ZVAL_LONG(&_89$$61, 22);
					zephir_array_update_string(&definition, SL("type"), &_89$$61, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_90$$61);
					ZVAL_LONG(&_90$$61, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_90$$61, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_4: ;
					ZEPHIR_INIT_NVAR(&_91$$62);
					ZVAL_LONG(&_91$$62, 26);
					zephir_array_update_string(&definition, SL("type"), &_91$$62, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_92$$62);
					ZVAL_LONG(&_92$$62, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_92$$62, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_5: ;
					ZEPHIR_INIT_NVAR(&_93$$63);
					ZVAL_LONG(&_93$$63, 0);
					zephir_array_update_string(&definition, SL("type"), &_93$$63, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_94$$63);
					ZVAL_LONG(&_94$$63, 1);
					zephir_array_update_string(&definition, SL("bindType"), &_94$$63, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_6: ;
					ZEPHIR_INIT_NVAR(&_95$$64);
					ZVAL_LONG(&_95$$64, 19);
					zephir_array_update_string(&definition, SL("type"), &_95$$64, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_7: ;
					ZEPHIR_INIT_NVAR(&_96$$65);
					ZVAL_LONG(&_96$$65, 18);
					zephir_array_update_string(&definition, SL("type"), &_96$$65, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_8: ;
					ZEPHIR_INIT_NVAR(&_97$$66);
					ZVAL_LONG(&_97$$66, 4);
					zephir_array_update_string(&definition, SL("type"), &_97$$66, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_98$$66);
					ZVAL_LONG(&_98$$66, 0);
					zephir_array_update_string(&definition, SL("size"), &_98$$66, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_9: ;
					ZEPHIR_INIT_NVAR(&_99$$67);
					ZVAL_LONG(&_99$$67, 1);
					zephir_array_update_string(&definition, SL("type"), &_99$$67, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_100$$67);
					ZVAL_LONG(&_100$$67, 0);
					zephir_array_update_string(&definition, SL("size"), &_100$$67, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_10: ;
				zephir_switch_1_clause_11: ;
					ZEPHIR_INIT_NVAR(&_101$$68);
					ZVAL_LONG(&_101$$68, 3);
					zephir_array_update_string(&definition, SL("type"), &_101$$68, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_102$$68);
					ZVAL_LONG(&_102$$68, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_102$$68, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_12: ;
					ZEPHIR_INIT_NVAR(&_103$$69);
					ZVAL_LONG(&_103$$69, 9);
					zephir_array_update_string(&definition, SL("type"), &_103$$69, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_104$$69);
					ZVAL_LONG(&_104$$69, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_104$$69, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_13: ;
				zephir_switch_1_clause_14: ;
					ZEPHIR_INIT_NVAR(&_105$$70);
					ZVAL_LONG(&_105$$70, 7);
					zephir_array_update_string(&definition, SL("type"), &_105$$70, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&_106$$70);
					ZVAL_LONG(&_106$$70, 32);
					zephir_array_update_string(&definition, SL("bindType"), &_106$$70, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_15: ;
					ZEPHIR_INIT_NVAR(&_107$$71);
					ZVAL_LONG(&_107$$71, 12);
					zephir_array_update_string(&definition, SL("type"), &_107$$71, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_16: ;
					ZEPHIR_INIT_NVAR(&_108$$72);
					ZVAL_LONG(&_108$$72, 13);
					zephir_array_update_string(&definition, SL("type"), &_108$$72, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_17: ;
					ZEPHIR_INIT_NVAR(&_109$$73);
					ZVAL_LONG(&_109$$73, 10);
					zephir_array_update_string(&definition, SL("type"), &_109$$73, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_18: ;
					ZEPHIR_INIT_NVAR(&_110$$74);
					ZVAL_LONG(&_110$$74, 11);
					zephir_array_update_string(&definition, SL("type"), &_110$$74, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_19: ;
					ZEPHIR_INIT_NVAR(&_111$$75);
					ZVAL_LONG(&_111$$75, 17);
					zephir_array_update_string(&definition, SL("type"), &_111$$75, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_20: ;
					ZEPHIR_INIT_NVAR(&_112$$76);
					ZVAL_LONG(&_112$$76, 20);
					zephir_array_update_string(&definition, SL("type"), &_112$$76, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_21: ;
					ZEPHIR_INIT_NVAR(&_113$$77);
					ZVAL_LONG(&_113$$77, 16);
					zephir_array_update_string(&definition, SL("type"), &_113$$77, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_22: ;
					ZEPHIR_INIT_NVAR(&_114$$78);
					ZVAL_LONG(&_114$$78, 15);
					zephir_array_update_string(&definition, SL("type"), &_114$$78, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_23: ;
					ZEPHIR_INIT_NVAR(&_115$$79);
					ZVAL_LONG(&_115$$79, 24);
					zephir_array_update_string(&definition, SL("type"), &_115$$79, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_24: ;
					ZEPHIR_INIT_NVAR(&_116$$80);
					ZVAL_LONG(&_116$$80, 23);
					zephir_array_update_string(&definition, SL("type"), &_116$$80, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_25: ;
					ZEPHIR_INIT_NVAR(&_117$$81);
					ZVAL_LONG(&_117$$81, 25);
					zephir_array_update_string(&definition, SL("type"), &_117$$81, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_26: ;
					ZEPHIR_INIT_NVAR(&_118$$82);
					ZVAL_LONG(&_118$$82, 6);
					zephir_array_update_string(&definition, SL("type"), &_118$$82, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_27: ;
				zephir_switch_1_clause_28: ;
					ZEPHIR_INIT_NVAR(&_119$$83);
					ZVAL_LONG(&_119$$83, 2);
					zephir_array_update_string(&definition, SL("type"), &_119$$83, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_29: ;
					ZEPHIR_INIT_NVAR(&_120$$84);
					ZVAL_LONG(&_120$$84, 5);
					zephir_array_update_string(&definition, SL("type"), &_120$$84, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_30: ;
					ZEPHIR_INIT_NVAR(&_121$$85);
					ZVAL_LONG(&_121$$85, 29);
					zephir_array_update_string(&definition, SL("type"), &_121$$85, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_31: ;
					ZEPHIR_INIT_NVAR(&_122$$86);
					ZVAL_LONG(&_122$$86, 30);
					zephir_array_update_string(&definition, SL("type"), &_122$$86, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_32: ;
					ZEPHIR_INIT_NVAR(&_123$$87);
					ZVAL_LONG(&_123$$87, 31);
					zephir_array_update_string(&definition, SL("type"), &_123$$87, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_33: ;
					ZEPHIR_INIT_NVAR(&_124$$88);
					ZVAL_LONG(&_124$$88, 32);
					zephir_array_update_string(&definition, SL("type"), &_124$$88, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_34: ;
					ZEPHIR_INIT_NVAR(&_125$$89);
					ZVAL_LONG(&_125$$89, 33);
					zephir_array_update_string(&definition, SL("type"), &_125$$89, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_35: ;
					ZEPHIR_INIT_NVAR(&_126$$90);
					ZVAL_LONG(&_126$$90, 34);
					zephir_array_update_string(&definition, SL("type"), &_126$$90, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_36: ;
					ZEPHIR_INIT_NVAR(&_127$$91);
					ZVAL_LONG(&_127$$91, 35);
					zephir_array_update_string(&definition, SL("type"), &_127$$91, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_37: ;
					ZEPHIR_INIT_NVAR(&_128$$92);
					ZVAL_LONG(&_128$$92, 36);
					zephir_array_update_string(&definition, SL("type"), &_128$$92, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_38: ;
					ZEPHIR_INIT_NVAR(&_129$$93);
					ZVAL_LONG(&_129$$93, 38);
					zephir_array_update_string(&definition, SL("type"), &_129$$93, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_39: ;
					ZEPHIR_INIT_NVAR(&_130$$94);
					ZVAL_LONG(&_130$$94, 37);
					zephir_array_update_string(&definition, SL("type"), &_130$$94, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_40: ;
					ZEPHIR_INIT_NVAR(&_131$$95);
					ZVAL_LONG(&_131$$95, 39);
					zephir_array_update_string(&definition, SL("type"), &_131$$95, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_clause_41: ;
					ZEPHIR_INIT_NVAR(&_132$$96);
					ZVAL_LONG(&_132$$96, 2);
					zephir_array_update_string(&definition, SL("type"), &_132$$96, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					goto zephir_switch_1_end;
				zephir_switch_1_end: ;

				_133$$57 = zephir_memnstr_str(&columnType, SL("ARRAY"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 548);
				if (!(_133$$57)) {
					_133$$57 = zephir_memnstr_str(&columnType, SL("[]"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 548);
				}
				if (_133$$57) {
					zephir_array_update_string(&definition, SL("array"), &__$true, PH_COPY | PH_SEPARATE);
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
				ZEPHIR_OBS_NVAR(&_134$$57);
				zephir_array_fetch_long(&_134$$57, &field, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 564);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_STRING(&_134$$57, "PRI")) {
					zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&_135$$57);
				zephir_array_fetch_long(&_135$$57, &field, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 571);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (ZEPHIR_IS_STRING(&_135$$57, "YES")) {
					zephir_array_update_string(&definition, SL("notNull"), &__$false, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				isGenerated = 0;
				_136$$57 = zephir_array_isset_value_long(&field, 11);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (_136$$57) {
					ZEPHIR_OBS_NVAR(&_137$$102);
					zephir_array_fetch_long(&_137$$102, &field, 11, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 582);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					isGenerated = (ZEPHIR_IS_STRING_IDENTICAL(&_137$$102, "ALWAYS"));
				}
				if (isGenerated) {
					_138$$103 = zephir_array_isset_value_long(&field, 12);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					_139$$103 = _138$$103;
					if (_139$$103) {
						ZEPHIR_OBS_NVAR(&_140$$103);
						zephir_array_fetch_long(&_140$$103, &field, 12, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 586);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						_139$$103 = Z_TYPE_P(&_140$$103) != IS_NULL;
					}
					if (_139$$103) {
						ZEPHIR_OBS_NVAR(&generationExpression);
						zephir_array_fetch_long(&generationExpression, &field, 12, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 587);
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
					zephir_array_update_string(&definition, SL("generationStored"), &__$true, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				} else {
					ZEPHIR_OBS_NVAR(&_141$$106);
					zephir_array_fetch_long(&_141$$106, &field, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 598);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (ZEPHIR_IS_STRING(&_141$$106, "auto_increment")) {
						zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
					}
					ZEPHIR_OBS_NVAR(&_142$$106);
					zephir_array_fetch_long(&_142$$106, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 605);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					if (Z_TYPE_P(&_142$$106) != IS_NULL) {
						ZEPHIR_OBS_NVAR(&_143$$108);
						zephir_array_fetch_long(&_143$$108, &field, 9, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 610);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_144$$108);
						ZVAL_STRING(&_144$$108, "/(?:^')|(?:'?::[[:alnum:][:space:]]+$)/");
						ZEPHIR_INIT_NVAR(&_145$$108);
						ZVAL_STRING(&_145$$108, "");
						ZEPHIR_CALL_FUNCTION(&_146$$108, "preg_replace", &_71, 4, &_144$$108, &_145$$108, &_143$$108);
						zephir_check_call_status();
						zephir_array_update_string(&definition, SL("default"), &_146$$108, PH_COPY | PH_SEPARATE);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						zephir_array_fetch_string(&_147$$108, &definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 612);
						if (UNEXPECTED(EG(exception))) {
							ZEPHIR_MM_RESTORE();
							return;
						}
						ZEPHIR_INIT_NVAR(&_144$$108);
						ZVAL_STRING(&_144$$108, "null");
						ZEPHIR_CALL_FUNCTION(&_148$$108, "strcasecmp", &_74, 85, &_147$$108, &_144$$108);
						zephir_check_call_status();
						if (ZEPHIR_IS_LONG(&_148$$108, 0)) {
							zephir_array_update_string(&definition, SL("default"), &__$null, PH_COPY | PH_SEPARATE);
							if (UNEXPECTED(EG(exception))) {
								ZEPHIR_MM_RESTORE();
								return;
							}
						}
					}
				}
				ZEPHIR_OBS_NVAR(&_149$$57);
				zephir_array_fetch_long(&_149$$57, &field, 10, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 621);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				if (Z_TYPE_P(&_149$$57) != IS_NULL) {
					ZEPHIR_OBS_NVAR(&_150$$110);
					zephir_array_fetch_long(&_150$$110, &field, 10, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 622);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_update_string(&definition, SL("comment"), &_150$$110, PH_COPY | PH_SEPARATE);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&columnName);
				zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 628);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&_151$$57);
				object_init_ex(&_151$$57, phalcon_db_column_ce);
				ZEPHIR_CALL_METHOD(NULL, &_151$$57, "__construct", &_152, 0, &columnName, &definition);
				zephir_check_call_status();
				zephir_array_append(&columns, &_151$$57, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 629);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
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
 *     $connection->describeReferences("co_orders_x_products")
 * );
 *```
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeReferences)
{
	zval _16$$3, _28$$6, _35$$9;
	zend_ulong _32;
	zend_bool _18, _7$$3, _19$$6;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_37 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval table_zv, schema_zv, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, referenceUpdate, referenceDelete, _0, _1, _2, _3, *_4, _5, *_6, _17, *_29, _30, *_31, _14$$3, _15$$3, _8$$5, _9$$5, _10$$5, _11$$5, _12$$5, _13$$5, _26$$6, _27$$6, _20$$8, _21$$8, _22$$8, _23$$8, _24$$8, _25$$8, _34$$9, _36$$9;
	zend_string *table = NULL, *schema = NULL, *_33;
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
	ZVAL_UNDEF(&_17);
	ZVAL_UNDEF(&_30);
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
	ZVAL_UNDEF(&_34$$9);
	ZVAL_UNDEF(&_36$$9);
	ZVAL_UNDEF(&_16$$3);
	ZVAL_UNDEF(&_28$$6);
	ZVAL_UNDEF(&_35$$9);
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
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_0, 613, PH_NOISY_CC | PH_READONLY);
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
	zephir_is_iterable(_4, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 685);
	if (Z_TYPE_P(_4) == IS_ARRAY) {
		ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_4), _6)
		{
			ZEPHIR_INIT_NVAR(&reference);
			ZVAL_COPY(&reference, _6);
			ZEPHIR_OBS_NVAR(&constraintName);
			zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 654);
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
				zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 657);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 658);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 659);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 660);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_INIT_NVAR(&columns);
				array_init(&columns);
				ZEPHIR_INIT_NVAR(&referencedColumns);
				array_init(&referencedColumns);
			} else {
				zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 664);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedSchema);
				zephir_array_fetch_string(&referencedSchema, &_8$$5, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 664);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 665);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedTable);
				zephir_array_fetch_string(&referencedTable, &_9$$5, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 665);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 666);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&columns);
				zephir_array_fetch_string(&columns, &_10$$5, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 666);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_11$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 667);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referencedColumns);
				zephir_array_fetch_string(&referencedColumns, &_11$$5, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 667);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_12$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 668);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referenceUpdate);
				zephir_array_fetch_string(&referenceUpdate, &_12$$5, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 668);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_fetch(&_13$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 669);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&referenceDelete);
				zephir_array_fetch_string(&referenceDelete, &_13$$5, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 669);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
			}
			ZEPHIR_OBS_NVAR(&_14$$3);
			zephir_array_fetch_long(&_14$$3, &reference, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 672);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&columns, &_14$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 672);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_OBS_NVAR(&_15$$3);
			zephir_array_fetch_long(&_15$$3, &reference, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 673);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			zephir_array_append(&referencedColumns, &_15$$3, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 673);
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
				zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 654);
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
					zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 657);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 658);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 659);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 660);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_INIT_NVAR(&columns);
					array_init(&columns);
					ZEPHIR_INIT_NVAR(&referencedColumns);
					array_init(&referencedColumns);
				} else {
					zephir_array_fetch(&_20$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 664);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedSchema);
					zephir_array_fetch_string(&referencedSchema, &_20$$8, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 664);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_21$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 665);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedTable);
					zephir_array_fetch_string(&referencedTable, &_21$$8, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 665);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_22$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 666);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&columns);
					zephir_array_fetch_string(&columns, &_22$$8, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 666);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_23$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 667);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referencedColumns);
					zephir_array_fetch_string(&referencedColumns, &_23$$8, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 667);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_24$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 668);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referenceUpdate);
					zephir_array_fetch_string(&referenceUpdate, &_24$$8, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 668);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					zephir_array_fetch(&_25$$8, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 669);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
					ZEPHIR_OBS_NVAR(&referenceDelete);
					zephir_array_fetch_string(&referenceDelete, &_25$$8, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 669);
					if (UNEXPECTED(EG(exception))) {
						ZEPHIR_MM_RESTORE();
						return;
					}
				}
				ZEPHIR_OBS_NVAR(&_26$$6);
				zephir_array_fetch_long(&_26$$6, &reference, 1, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 672);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&columns, &_26$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 672);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				ZEPHIR_OBS_NVAR(&_27$$6);
				zephir_array_fetch_long(&_27$$6, &reference, 5, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 673);
				if (UNEXPECTED(EG(exception))) {
					ZEPHIR_MM_RESTORE();
					return;
				}
				zephir_array_append(&referencedColumns, &_27$$6, PH_SEPARATE, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 673);
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
	ZEPHIR_INIT_VAR(&referenceObjects);
	array_init(&referenceObjects);
	if (Z_TYPE_P(&references) == IS_STRING) {
		ZEPHIR_INIT_VAR(&_30);
		zephir_string_to_char_array(&_30, &references);
		_29 = &_30;
	} else {
		_29 = &references;
	}
	zephir_is_iterable(_29, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 701);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(_29), _32, _33, _31)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_33 != NULL) { 
			ZVAL_STR_COPY(&name, _33);
		} else {
			ZVAL_LONG(&name, _32);
		}
		ZEPHIR_INIT_NVAR(&arrayReference);
		ZVAL_COPY(&arrayReference, _31);
		ZEPHIR_INIT_NVAR(&_34$$9);
		object_init_ex(&_34$$9, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(&_35$$9);
		zephir_create_array(&_35$$9, 6, 0);
		ZEPHIR_OBS_NVAR(&_36$$9);
		zephir_array_fetch_string(&_36$$9, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 691);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_35$$9, SL("referencedSchema"), &_36$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_36$$9);
		zephir_array_fetch_string(&_36$$9, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 692);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_35$$9, SL("referencedTable"), &_36$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_36$$9);
		zephir_array_fetch_string(&_36$$9, &arrayReference, SL("columns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 693);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_35$$9, SL("columns"), &_36$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_36$$9);
		zephir_array_fetch_string(&_36$$9, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 694);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_35$$9, SL("referencedColumns"), &_36$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_36$$9);
		zephir_array_fetch_string(&_36$$9, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 695);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_35$$9, SL("onUpdate"), &_36$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_36$$9);
		zephir_array_fetch_string(&_36$$9, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 697);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
		zephir_array_update_string(&_35$$9, SL("onDelete"), &_36$$9, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_34$$9, "__construct", &_37, 61, &name, &_35$$9);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_34$$9, PH_COPY | PH_SEPARATE);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(&referenceObjects);
}

/**
 * Returns the default identity value to be inserted in an identity column
 *
 *```php
 * // Inserting a new invoice with a valid default value for the column 'inv_id'
 * $success = $connection->insert(
 *     "co_invoices",
 *     [
 *         $connection->getDefaultIdValue(),
 *         "Test Invoice",
 *         100,
 *     ],
 *     [
 *         "inv_id",
 *         "inv_title",
 *         "inv_total",
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
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 62, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Modifies a table column based on a definition
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, modifyColumn)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval tableName_zv, schemaName_zv, *column, column_sub, *currentColumn = NULL, currentColumn_sub, __$null, sql, queries, query, exception, _0, *_1$$4, _2$$4, *_3$$4, _4$$5, _6$$3, _7$$9, _8$$9, _9$$9;
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
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_7$$9);
	ZVAL_UNDEF(&_8$$9);
	ZVAL_UNDEF(&_9$$9);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("dialect", 7, 1);
	}

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
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 613, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&sql, &_0, "modifyColumn", NULL, 0, &tableName_zv, &schemaName_zv, column, currentColumn);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&queries);
	zephir_fast_explode_str(&queries, SL(";"), &sql, NULL);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (zephir_fast_count_int(&queries) > 1) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(NULL, this_ptr, "begin", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			if (Z_TYPE_P(&queries) == IS_STRING) {
				ZEPHIR_INIT_VAR(&_2$$4);
				zephir_string_to_char_array(&_2$$4, &queries);
				_1$$4 = &_2$$4;
			} else {
				_1$$4 = &queries;
			}
			zephir_is_iterable(_1$$4, 0, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 757);
			ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_1$$4), _3$$4)
			{
				ZEPHIR_INIT_NVAR(&query);
				ZVAL_COPY(&query, _3$$4);
				if (ZEPHIR_IS_EMPTY(&query)) {
					continue;
				}
				ZEPHIR_INIT_NVAR(&_4$$5);
				ZEPHIR_CONCAT_VS(&_4$$5, &query, ";");
				if (UNEXPECTED(EG(exception))) {
					goto try_end_1;
				}
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_5, 0, &_4$$5);
				zephir_check_call_status_or_jump(try_end_1);
			} ZEND_HASH_FOREACH_END();
			ZEPHIR_INIT_NVAR(&query);
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "commit", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(&_6$$3);
			ZVAL_OBJ(&_6$$3, EG(exception));
			Z_ADDREF_P(&_6$$3);
			if (zephir_is_instance_of(&_6$$3, SL("Throwable"))) {
				zend_clear_exception();
				ZEPHIR_CPY_WRT(&exception, &_6$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(&exception, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 761);
				ZEPHIR_MM_RESTORE();
				return;
			} else {
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		ZEPHIR_INIT_VAR(&_7$$9);
		if (!(ZEPHIR_IS_EMPTY(&sql))) {
			zephir_memory_observe(&_8$$9);
			zephir_array_fetch_long(&_8$$9, &queries, 0, PH_NOISY, "phalcon/Db/Adapter/Pdo/Postgresql.zep", 764);
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_INIT_VAR(&_9$$9);
			ZEPHIR_CONCAT_VS(&_9$$9, &_8$$9, ";");
			if (UNEXPECTED(EG(exception))) {
				ZEPHIR_MM_RESTORE();
				return;
			}
			ZEPHIR_CALL_METHOD(&_7$$9, this_ptr, "execute", NULL, 0, &_9$$9);
			zephir_check_call_status();
		} else {
			ZEPHIR_INIT_NVAR(&_7$$9);
			ZVAL_BOOL(&_7$$9, 1);
		}
		RETURN_CCTOR(&_7$$9);
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
 *
 * @phpstan-return db_dsn_defaults
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDsnDefaults)
{

	array_init(return_value);
	return;
}

/**
 * Recognizes a PostgreSQL connection-loss failure by SQLSTATE
 * (connection exception class 08, or admin/crash shutdown 57P0x) with a
 * message fallback.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, isConnectionError)
{
	zend_bool _2, _3, _4, _5, _6;
	zval _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *exception, exception_sub, sqlState, message, _0;

	ZVAL_UNDEF(&exception_sub);
	ZVAL_UNDEF(&sqlState);
	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(exception, zend_ce_throwable)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &exception);
	ZEPHIR_CALL_METHOD(&_0, exception, "getCode", NULL, 0);
	zephir_check_call_status();
	zephir_cast_to_string(&_1, &_0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	ZEPHIR_CPY_WRT(&sqlState, &_1);
	_2 = ZEPHIR_IS_STRING_IDENTICAL(&sqlState, "08003");
	if (!(_2)) {
		_2 = ZEPHIR_IS_STRING_IDENTICAL(&sqlState, "08006");
	}
	_3 = _2;
	if (!(_3)) {
		_3 = ZEPHIR_IS_STRING_IDENTICAL(&sqlState, "57P01");
	}
	_4 = _3;
	if (!(_4)) {
		_4 = ZEPHIR_IS_STRING_IDENTICAL(&sqlState, "57P02");
	}
	_5 = _4;
	if (!(_5)) {
		_5 = ZEPHIR_IS_STRING_IDENTICAL(&sqlState, "57P03");
	}
	if (_5) {
		RETURN_MM_BOOL(1);
	}
	ZEPHIR_CALL_METHOD(&message, exception, "getMessage", NULL, 0);
	zephir_check_call_status();
	_6 = zephir_memnstr_str(&message, SL("server closed the connection unexpectedly"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 816);
	if (!(_6)) {
		_6 = zephir_memnstr_str(&message, SL("no connection to the server"), "phalcon/Db/Adapter/Pdo/Postgresql.zep", 817);
	}
	RETURN_MM_BOOL(_6);
}

