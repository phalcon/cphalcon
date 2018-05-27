
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
#include "kernel/operators.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "ext/spl/spl_exceptions.h"


/**
 * Phalcon\Db\Adapter\Pdo\Postgresql
 *
 * Specific functions for the Postgresql database system
 *
 * <code>
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
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Postgresql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Postgresql, phalcon, db_adapter_pdo_postgresql, phalcon_db_adapter_pdo_ce, phalcon_db_adapter_pdo_postgresql_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("_type"), "pgsql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("_dialectType"), "postgresql", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, connect) {

	zend_bool _3$$6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_5 = NULL;
	zval *descriptor_param = NULL, *schema = NULL, *sql = NULL, *status = NULL, *_0$$3, *_2$$6, *_4$$6;
	zval *descriptor = NULL, *_1$$3 = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &descriptor_param);

	if (!descriptor_param) {
		ZEPHIR_INIT_VAR(descriptor);
		array_init(descriptor);
	} else {
		zephir_get_arrval(descriptor, descriptor_param);
	}


	if (ZEPHIR_IS_EMPTY(descriptor)) {
		ZEPHIR_OBS_VAR(_0$$3);
		zephir_read_property_this(&_0$$3, this_ptr, SL("_descriptor"), PH_NOISY_CC);
		zephir_get_arrval(_1$$3, _0$$3);
		ZEPHIR_CPY_WRT(descriptor, _1$$3);
	}
	ZEPHIR_OBS_VAR(schema);
	if (zephir_array_isset_string_fetch(&schema, descriptor, SS("schema"), 0 TSRMLS_CC)) {
		zephir_array_unset_string(&descriptor, SS("schema"), PH_SEPARATE);
	} else {
		ZEPHIR_INIT_NVAR(schema);
		ZVAL_STRING(schema, "", 1);
	}
	if (zephir_array_isset_string(descriptor, SS("password"))) {
		ZEPHIR_OBS_VAR(_2$$6);
		zephir_array_fetch_string(&_2$$6, descriptor, SL("password"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 73 TSRMLS_CC);
		_3$$6 = Z_TYPE_P(_2$$6) == IS_STRING;
		if (_3$$6) {
			zephir_array_fetch_string(&_4$$6, descriptor, SL("password"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 73 TSRMLS_CC);
			_3$$6 = zephir_fast_strlen_ev(_4$$6) == 0;
		}
		if (_3$$6) {
			zephir_array_update_string(&descriptor, SL("password"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_PARENT(&status, phalcon_db_adapter_pdo_postgresql_ce, getThis(), "connect", &_5, 168, descriptor);
	zephir_check_call_status();
	if (!(ZEPHIR_IS_EMPTY(schema))) {
		ZEPHIR_INIT_VAR(sql);
		ZEPHIR_CONCAT_SVS(sql, "SET search_path TO '", schema, "'");
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "execute", NULL, 0, sql);
		zephir_check_call_status();
	}
	RETURN_CCTOR(status);

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
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns) {

	HashTable *_5;
	HashPosition _4;
	zephir_fcall_cache_entry *_43 = NULL, *_47 = NULL, *_49 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *columns = NULL, *columnType = NULL, *field = NULL, *definition = NULL, *oldColumn = NULL, *columnName = NULL, *charSize = NULL, *numericSize = NULL, *numericScale = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, *_7$$4 = NULL, *_8$$4 = NULL, *_9$$5 = NULL, *_10$$5 = NULL, *_11$$6 = NULL, *_12$$6 = NULL, *_13$$7 = NULL, *_14$$7 = NULL, *_15$$8 = NULL, *_16$$8 = NULL, *_17$$9 = NULL, *_18$$10 = NULL, *_19$$10 = NULL, *_20$$11 = NULL, *_21$$12 = NULL, *_22$$12 = NULL, *_23$$13 = NULL, *_24$$14 = NULL, *_25$$15 = NULL, *_26$$15 = NULL, *_27$$16 = NULL, *_28$$16 = NULL, *_29$$16 = NULL, *_30$$17 = NULL, *_31$$18 = NULL, *_32$$19 = NULL, *_33$$19 = NULL, *_34$$20 = NULL, *_35$$3, *_36$$3, *_37$$3, *_38$$3 = NULL, *_48$$3 = NULL, *_39$$26, *_40$$26 = NULL, *_41$$26 = NULL, *_42$$26 = NULL, *_44$$26, _45$$26 = zval_used_for_init, *_46$$26 = NULL;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	zephir_get_strval(table, table_param);
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}


	ZEPHIR_INIT_VAR(oldColumn);
	ZVAL_NULL(oldColumn);
	ZEPHIR_INIT_VAR(columns);
	array_init(columns);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "describecolumns", NULL, 0, table, schema);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 284);
	for (
	  ; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(field, _6);
		ZEPHIR_INIT_NVAR(definition);
		zephir_create_array(definition, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(definition, SS("bindType"), 2);
		ZEPHIR_OBS_NVAR(columnType);
		zephir_array_fetch_long(&columnType, field, 1, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 118 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(charSize);
		zephir_array_fetch_long(&charSize, field, 2, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 119 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(numericSize);
		zephir_array_fetch_long(&numericSize, field, 3, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 120 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(numericScale);
		zephir_array_fetch_long(&numericScale, field, 4, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 121 TSRMLS_CC);
		if (zephir_memnstr_str(columnType, SL("smallint(1)"), "phalcon/db/adapter/pdo/postgresql.zep", 123)) {
			ZEPHIR_INIT_NVAR(_7$$4);
			ZVAL_LONG(_7$$4, 8);
			zephir_array_update_string(&definition, SL("type"), &_7$$4, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_8$$4);
			ZVAL_LONG(_8$$4, 5);
			zephir_array_update_string(&definition, SL("bindType"), &_8$$4, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("bigint"), "phalcon/db/adapter/pdo/postgresql.zep", 129)) {
			ZEPHIR_INIT_NVAR(_9$$5);
			ZVAL_LONG(_9$$5, 14);
			zephir_array_update_string(&definition, SL("type"), &_9$$5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_10$$5);
			ZVAL_LONG(_10$$5, 1);
			zephir_array_update_string(&definition, SL("bindType"), &_10$$5, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("int"), "phalcon/db/adapter/pdo/postgresql.zep", 136)) {
			ZEPHIR_INIT_NVAR(_11$$6);
			ZVAL_LONG(_11$$6, 0);
			zephir_array_update_string(&definition, SL("type"), &_11$$6, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_12$$6);
			ZVAL_LONG(_12$$6, 1);
			zephir_array_update_string(&definition, SL("bindType"), &_12$$6, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("double precision"), "phalcon/db/adapter/pdo/postgresql.zep", 144)) {
			ZEPHIR_INIT_NVAR(_13$$7);
			ZVAL_LONG(_13$$7, 9);
			zephir_array_update_string(&definition, SL("type"), &_13$$7, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_14$$7);
			ZVAL_LONG(_14$$7, 32);
			zephir_array_update_string(&definition, SL("bindType"), &_14$$7, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("real"), "phalcon/db/adapter/pdo/postgresql.zep", 152)) {
			ZEPHIR_INIT_NVAR(_15$$8);
			ZVAL_LONG(_15$$8, 7);
			zephir_array_update_string(&definition, SL("type"), &_15$$8, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_16$$8);
			ZVAL_LONG(_16$$8, 32);
			zephir_array_update_string(&definition, SL("bindType"), &_16$$8, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("varying"), "phalcon/db/adapter/pdo/postgresql.zep", 160)) {
			ZEPHIR_INIT_NVAR(_17$$9);
			ZVAL_LONG(_17$$9, 2);
			zephir_array_update_string(&definition, SL("type"), &_17$$9, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("date"), "phalcon/db/adapter/pdo/postgresql.zep", 166)) {
			ZEPHIR_INIT_NVAR(_18$$10);
			ZVAL_LONG(_18$$10, 1);
			zephir_array_update_string(&definition, SL("type"), &_18$$10, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_19$$10);
			ZVAL_LONG(_19$$10, 0);
			zephir_array_update_string(&definition, SL("size"), &_19$$10, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("timestamp"), "phalcon/db/adapter/pdo/postgresql.zep", 172)) {
			ZEPHIR_INIT_NVAR(_20$$11);
			ZVAL_LONG(_20$$11, 17);
			zephir_array_update_string(&definition, SL("type"), &_20$$11, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("numeric"), "phalcon/db/adapter/pdo/postgresql.zep", 177)) {
			ZEPHIR_INIT_NVAR(_21$$12);
			ZVAL_LONG(_21$$12, 3);
			zephir_array_update_string(&definition, SL("type"), &_21$$12, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("scale"), &numericScale, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_22$$12);
			ZVAL_LONG(_22$$12, 32);
			zephir_array_update_string(&definition, SL("bindType"), &_22$$12, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("char"), "phalcon/db/adapter/pdo/postgresql.zep", 186)) {
			ZEPHIR_INIT_NVAR(_23$$13);
			ZVAL_LONG(_23$$13, 5);
			zephir_array_update_string(&definition, SL("type"), &_23$$13, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("text"), "phalcon/db/adapter/pdo/postgresql.zep", 192)) {
			ZEPHIR_INIT_NVAR(_24$$14);
			ZVAL_LONG(_24$$14, 6);
			zephir_array_update_string(&definition, SL("type"), &_24$$14, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("float"), "phalcon/db/adapter/pdo/postgresql.zep", 198)) {
			ZEPHIR_INIT_NVAR(_25$$15);
			ZVAL_LONG(_25$$15, 7);
			zephir_array_update_string(&definition, SL("type"), &_25$$15, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_26$$15);
			ZVAL_LONG(_26$$15, 32);
			zephir_array_update_string(&definition, SL("bindType"), &_26$$15, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("bool"), "phalcon/db/adapter/pdo/postgresql.zep", 206)) {
			ZEPHIR_INIT_NVAR(_27$$16);
			ZVAL_LONG(_27$$16, 8);
			zephir_array_update_string(&definition, SL("type"), &_27$$16, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_28$$16);
			ZVAL_LONG(_28$$16, 0);
			zephir_array_update_string(&definition, SL("size"), &_28$$16, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_29$$16);
			ZVAL_LONG(_29$$16, 5);
			zephir_array_update_string(&definition, SL("bindType"), &_29$$16, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("jsonb"), "phalcon/db/adapter/pdo/postgresql.zep", 213)) {
			ZEPHIR_INIT_NVAR(_30$$17);
			ZVAL_LONG(_30$$17, 16);
			zephir_array_update_string(&definition, SL("type"), &_30$$17, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("json"), "phalcon/db/adapter/pdo/postgresql.zep", 218)) {
			ZEPHIR_INIT_NVAR(_31$$18);
			ZVAL_LONG(_31$$18, 15);
			zephir_array_update_string(&definition, SL("type"), &_31$$18, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("uuid"), "phalcon/db/adapter/pdo/postgresql.zep", 223)) {
			ZEPHIR_INIT_NVAR(_32$$19);
			ZVAL_LONG(_32$$19, 5);
			zephir_array_update_string(&definition, SL("type"), &_32$$19, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_33$$19);
			ZVAL_LONG(_33$$19, 36);
			zephir_array_update_string(&definition, SL("size"), &_33$$19, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_NVAR(_34$$20);
			ZVAL_LONG(_34$$20, 2);
			zephir_array_update_string(&definition, SL("type"), &_34$$20, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_35$$3, field, 6, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 248 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_35$$3, "PRI")) {
			zephir_array_update_string(&definition, SL("primary"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_36$$3, field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 255 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_36$$3, "NO")) {
			zephir_array_update_string(&definition, SL("notNull"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_37$$3, field, 7, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 262 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_37$$3, "auto_increment")) {
			zephir_array_update_string(&definition, SL("autoIncrement"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_NVAR(_38$$3);
		zephir_array_fetch_long(&_38$$3, field, 9, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 269 TSRMLS_CC);
		if (Z_TYPE_P(_38$$3) != IS_NULL) {
			zephir_array_fetch_long(&_39$$26, field, 9, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 270 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_40$$26);
			ZVAL_STRING(_40$$26, "/^'|'?::[[:alnum:][:space:]]+$/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_41$$26);
			ZVAL_STRING(_41$$26, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_42$$26, "preg_replace", &_43, 42, _40$$26, _41$$26, _39$$26);
			zephir_check_temp_parameter(_40$$26);
			zephir_check_temp_parameter(_41$$26);
			zephir_check_call_status();
			zephir_array_update_string(&definition, SL("default"), &_42$$26, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_44$$26, definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 271 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_45$$26);
			ZVAL_STRING(&_45$$26, "null", 0);
			ZEPHIR_CALL_FUNCTION(&_46$$26, "strcasecmp", &_47, 16, _44$$26, &_45$$26);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(_46$$26, 0)) {
				zephir_array_update_string(&definition, SL("default"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
			}
		}
		zephir_array_fetch_long(&columnName, field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 279 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_48$$3);
		object_init_ex(_48$$3, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, _48$$3, "__construct", &_49, 167, columnName, definition);
		zephir_check_call_status();
		zephir_array_append(&columns, _48$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 280);
		ZEPHIR_CPY_WRT(oldColumn, columnName);
	}
	RETURN_CCTOR(columns);

}

/**
 * Creates a table
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, createTable) {

	HashTable *_2$$6;
	HashPosition _1$$6;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *definition = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, *sql = NULL, *queries = NULL, *query = NULL, *exception = NULL, *columns = NULL, *_0, **_3$$6, *_4$$7 = NULL, *_6$$5, *_7$$10, *_8$$10;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	definition = definition_param;


	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter/pdo/postgresql.zep", 295);
		return;
	}
	if (!(zephir_fast_count_int(columns TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter/pdo/postgresql.zep", 299);
		return;
	}
	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&sql, _0, "createtable", NULL, 0, tableName, schemaName, definition);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(queries);
	zephir_fast_explode_str(queries, SL(";"), sql, LONG_MAX TSRMLS_CC);
	if (zephir_fast_count_int(queries TSRMLS_CC) > 1) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(NULL, this_ptr, "begin", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_is_iterable(queries, &_2$$6, &_1$$6, 0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 315);
			for (
			  ; zend_hash_get_current_data_ex(_2$$6, (void**) &_3$$6, &_1$$6) == SUCCESS
			  ; zend_hash_move_forward_ex(_2$$6, &_1$$6)
			) {
				ZEPHIR_GET_HVALUE(query, _3$$6);
				if (ZEPHIR_IS_EMPTY(query)) {
					continue;
				}
				ZEPHIR_INIT_LNVAR(_4$$7);
				ZEPHIR_CONCAT_VS(_4$$7, query, ";");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_5, 0, _4$$7);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "commit", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(_6$$5);
			ZEPHIR_CPY_WRT(_6$$5, EG(exception));
			if (zephir_instance_of_ev(_6$$5, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(exception, _6$$5);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(exception, "phalcon/db/adapter/pdo/postgresql.zep", 319 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		zephir_array_fetch_long(&_7$$10, queries, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 322 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_8$$10);
		ZEPHIR_CONCAT_VS(_8$$10, _7$$10, ";");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _8$$10);
		zephir_check_call_status();
		RETURN_MM();
	}
	RETURN_MM_BOOL(1);

}

/**
 * Modifies a table column based on a definition
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, modifyColumn) {

	HashTable *_2$$4;
	HashPosition _1$$4;
	zephir_fcall_cache_entry *_5 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *currentColumn = NULL, *sql = NULL, *queries = NULL, *query = NULL, *exception = NULL, *_0, **_3$$4, *_4$$5 = NULL, *_6$$3, *_7$$8 = NULL, *_8$$8, *_9$$8;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &tableName_param, &schemaName_param, &column, &currentColumn);

	if (UNEXPECTED(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (UNEXPECTED(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	if (!currentColumn) {
		currentColumn = ZEPHIR_GLOBAL(global_null);
	}


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&sql, _0, "modifycolumn", NULL, 0, tableName, schemaName, column, currentColumn);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(queries);
	zephir_fast_explode_str(queries, SL(";"), sql, LONG_MAX TSRMLS_CC);
	if (zephir_fast_count_int(queries TSRMLS_CC) > 1) {

		/* try_start_1: */

			ZEPHIR_CALL_METHOD(NULL, this_ptr, "begin", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			zephir_is_iterable(queries, &_2$$4, &_1$$4, 0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 347);
			for (
			  ; zend_hash_get_current_data_ex(_2$$4, (void**) &_3$$4, &_1$$4) == SUCCESS
			  ; zend_hash_move_forward_ex(_2$$4, &_1$$4)
			) {
				ZEPHIR_GET_HVALUE(query, _3$$4);
				if (ZEPHIR_IS_EMPTY(query)) {
					continue;
				}
				ZEPHIR_INIT_LNVAR(_4$$5);
				ZEPHIR_CONCAT_VS(_4$$5, query, ";");
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "query", &_5, 0, _4$$5);
				zephir_check_call_status_or_jump(try_end_1);
			}
			ZEPHIR_RETURN_CALL_METHOD(this_ptr, "commit", NULL, 0);
			zephir_check_call_status_or_jump(try_end_1);
			RETURN_MM();

		try_end_1:

		if (EG(exception)) {
			ZEPHIR_INIT_VAR(_6$$3);
			ZEPHIR_CPY_WRT(_6$$3, EG(exception));
			if (zephir_instance_of_ev(_6$$3, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CPY_WRT(exception, _6$$3);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(exception, "phalcon/db/adapter/pdo/postgresql.zep", 352 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		ZEPHIR_INIT_VAR(_7$$8);
		if (!(ZEPHIR_IS_EMPTY(sql))) {
			zephir_array_fetch_long(&_8$$8, queries, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 356 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_9$$8);
			ZEPHIR_CONCAT_VS(_9$$8, _8$$8, ";");
			ZEPHIR_CALL_METHOD(&_7$$8, this_ptr, "execute", NULL, 0, _9$$8);
			zephir_check_call_status();
		} else {
			ZVAL_BOOL(_7$$8, 1);
		}
		RETURN_CCTOR(_7$$8);
	}
	RETURN_MM_BOOL(1);

}

/**
 * Check whether the database system requires an explicit value for identity columns
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, useExplicitIdValue) {

	

	RETURN_BOOL(1);

}

/**
 * Returns the default identity value to be inserted in an identity column
 *
 *<code>
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
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue) {

	zval *_0;
	zend_long ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "DEFAULT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 26, _0);
	zephir_check_temp_parameter(_0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Check whether the database system requires a sequence to produce auto-numeric values
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, supportSequences) {

	

	RETURN_BOOL(1);

}

