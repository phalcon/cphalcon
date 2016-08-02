
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
#include "kernel/hash.h"
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
 *   'host'     => 'localhost',
 *   'dbname'   => 'blog',
 *   'port'     => 5432,
 *   'username' => 'postgres',
 *   'password' => 'secret'
 * ];
 *
 *
 * $connection = new Postgresql($config);
 * </code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Postgresql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Postgresql, phalcon, db_adapter_pdo_postgresql, phalcon_db_adapter_pdo_ce, phalcon_db_adapter_pdo_postgresql_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("_type"), "pgsql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_db_adapter_pdo_postgresql_ce, SL("_dialectType"), "postgresql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_adapter_pdo_postgresql_ce TSRMLS_CC, 1, phalcon_db_adapterinterface_ce);
	return SUCCESS;

}

/**
 * This method is automatically called in Phalcon\Db\Adapter\Pdo constructor.
 * Call it when you need to restore a database connection.
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, connect) {

	zend_bool _3$$6;
	int ZEPHIR_LAST_CALL_STATUS;
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
		zephir_array_fetch_string(&_2$$6, descriptor, SL("password"), PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 75 TSRMLS_CC);
		_3$$6 = Z_TYPE_P(_2$$6) == IS_STRING;
		if (_3$$6) {
			zephir_array_fetch_string(&_4$$6, descriptor, SL("password"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 75 TSRMLS_CC);
			_3$$6 = zephir_fast_strlen_ev(_4$$6) == 0;
		}
		if (_3$$6) {
			zephir_array_update_string(&descriptor, SL("password"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
		}
	}
	ZEPHIR_CALL_PARENT(&status, phalcon_db_adapter_pdo_postgresql_ce, this_ptr, "connect", &_5, 150, descriptor);
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
 * print_r($connection->describeColumns("posts"));
 * </code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, describeColumns) {

	HashTable *_5;
	HashPosition _4;
	zephir_fcall_cache_entry *_41 = NULL, *_45 = NULL, *_47 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *columns = NULL, *columnType = NULL, *field = NULL, *definition = NULL, *oldColumn = NULL, *columnName = NULL, *charSize = NULL, *numericSize = NULL, *numericScale = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, *_7$$5 = NULL, *_8$$5 = NULL, *_9$$6 = NULL, *_10$$6 = NULL, *_11$$7 = NULL, *_12$$7 = NULL, *_13$$8 = NULL, *_14$$9 = NULL, *_15$$9 = NULL, *_16$$10 = NULL, *_17$$11 = NULL, *_18$$11 = NULL, *_19$$12 = NULL, *_20$$13 = NULL, *_21$$13 = NULL, *_22$$14 = NULL, *_23$$15 = NULL, *_24$$15 = NULL, *_25$$16 = NULL, *_26$$16 = NULL, *_27$$16 = NULL, *_28$$17 = NULL, *_29$$18 = NULL, *_30$$19 = NULL, *_31$$19 = NULL, *_32$$4 = NULL, *_33$$3, *_34$$3, *_35$$3, *_36$$3 = NULL, *_46$$3 = NULL, *_37$$26, *_38$$26 = NULL, *_39$$26 = NULL, *_40$$26 = NULL, *_42$$26, _43$$26 = zval_used_for_init, *_44$$26 = NULL;
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
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 328);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
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
		while (1) {
			if (zephir_memnstr_str(columnType, SL("smallint(1)"), "phalcon/db/adapter/pdo/postgresql.zep", 128)) {
				ZEPHIR_INIT_NVAR(_7$$5);
				ZVAL_LONG(_7$$5, 8);
				zephir_array_update_string(&definition, SL("type"), &_7$$5, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8$$5);
				ZVAL_LONG(_8$$5, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_8$$5, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("bigint"), "phalcon/db/adapter/pdo/postgresql.zep", 137)) {
				ZEPHIR_INIT_NVAR(_9$$6);
				ZVAL_LONG(_9$$6, 14);
				zephir_array_update_string(&definition, SL("type"), &_9$$6, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_10$$6);
				ZVAL_LONG(_10$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_10$$6, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("int"), "phalcon/db/adapter/pdo/postgresql.zep", 147)) {
				ZEPHIR_INIT_NVAR(_11$$7);
				ZVAL_LONG(_11$$7, 0);
				zephir_array_update_string(&definition, SL("type"), &_11$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_12$$7);
				ZVAL_LONG(_12$$7, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_12$$7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("varying"), "phalcon/db/adapter/pdo/postgresql.zep", 158)) {
				ZEPHIR_INIT_NVAR(_13$$8);
				ZVAL_LONG(_13$$8, 2);
				zephir_array_update_string(&definition, SL("type"), &_13$$8, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("date"), "phalcon/db/adapter/pdo/postgresql.zep", 167)) {
				ZEPHIR_INIT_NVAR(_14$$9);
				ZVAL_LONG(_14$$9, 1);
				zephir_array_update_string(&definition, SL("type"), &_14$$9, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_15$$9);
				ZVAL_LONG(_15$$9, 0);
				zephir_array_update_string(&definition, SL("size"), &_15$$9, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("timestamp"), "phalcon/db/adapter/pdo/postgresql.zep", 176)) {
				ZEPHIR_INIT_NVAR(_16$$10);
				ZVAL_LONG(_16$$10, 17);
				zephir_array_update_string(&definition, SL("type"), &_16$$10, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("numeric"), "phalcon/db/adapter/pdo/postgresql.zep", 184)) {
				ZEPHIR_INIT_NVAR(_17$$11);
				ZVAL_LONG(_17$$11, 3);
				zephir_array_update_string(&definition, SL("type"), &_17$$11, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("scale"), &numericScale, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_18$$11);
				ZVAL_LONG(_18$$11, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_18$$11, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("char"), "phalcon/db/adapter/pdo/postgresql.zep", 196)) {
				ZEPHIR_INIT_NVAR(_19$$12);
				ZVAL_LONG(_19$$12, 5);
				zephir_array_update_string(&definition, SL("type"), &_19$$12, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("timestamp"), "phalcon/db/adapter/pdo/postgresql.zep", 205)) {
				ZEPHIR_INIT_NVAR(_20$$13);
				ZVAL_LONG(_20$$13, 4);
				zephir_array_update_string(&definition, SL("type"), &_20$$13, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_21$$13);
				ZVAL_LONG(_21$$13, 0);
				zephir_array_update_string(&definition, SL("size"), &_21$$13, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("text"), "phalcon/db/adapter/pdo/postgresql.zep", 214)) {
				ZEPHIR_INIT_NVAR(_22$$14);
				ZVAL_LONG(_22$$14, 6);
				zephir_array_update_string(&definition, SL("type"), &_22$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &charSize, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("float"), "phalcon/db/adapter/pdo/postgresql.zep", 223)) {
				ZEPHIR_INIT_NVAR(_23$$15);
				ZVAL_LONG(_23$$15, 7);
				zephir_array_update_string(&definition, SL("type"), &_23$$15, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("size"), &numericSize, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_24$$15);
				ZVAL_LONG(_24$$15, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_24$$15, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("bool"), "phalcon/db/adapter/pdo/postgresql.zep", 234)) {
				ZEPHIR_INIT_NVAR(_25$$16);
				ZVAL_LONG(_25$$16, 8);
				zephir_array_update_string(&definition, SL("type"), &_25$$16, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_26$$16);
				ZVAL_LONG(_26$$16, 0);
				zephir_array_update_string(&definition, SL("size"), &_26$$16, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_27$$16);
				ZVAL_LONG(_27$$16, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_27$$16, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("jsonb"), "phalcon/db/adapter/pdo/postgresql.zep", 244)) {
				ZEPHIR_INIT_NVAR(_28$$17);
				ZVAL_LONG(_28$$17, 16);
				zephir_array_update_string(&definition, SL("type"), &_28$$17, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("json"), "phalcon/db/adapter/pdo/postgresql.zep", 252)) {
				ZEPHIR_INIT_NVAR(_29$$18);
				ZVAL_LONG(_29$$18, 15);
				zephir_array_update_string(&definition, SL("type"), &_29$$18, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("uuid"), "phalcon/db/adapter/pdo/postgresql.zep", 260)) {
				ZEPHIR_INIT_NVAR(_30$$19);
				ZVAL_LONG(_30$$19, 5);
				zephir_array_update_string(&definition, SL("type"), &_30$$19, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_31$$19);
				ZVAL_LONG(_31$$19, 36);
				zephir_array_update_string(&definition, SL("size"), &_31$$19, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(_32$$4);
			ZVAL_LONG(_32$$4, 2);
			zephir_array_update_string(&definition, SL("type"), &_32$$4, PH_COPY | PH_SEPARATE);
			break;
		}
		if (zephir_memnstr_str(columnType, SL("unsigned"), "phalcon/db/adapter/pdo/postgresql.zep", 276)) {
			zephir_array_update_string(&definition, SL("unsigned"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_33$$3, field, 6, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 292 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_33$$3, "PRI")) {
			zephir_array_update_string(&definition, SL("primary"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_34$$3, field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 299 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_34$$3, "NO")) {
			zephir_array_update_string(&definition, SL("notNull"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_35$$3, field, 7, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 306 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_35$$3, "auto_increment")) {
			zephir_array_update_string(&definition, SL("autoIncrement"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_NVAR(_36$$3);
		zephir_array_fetch_long(&_36$$3, field, 9, PH_NOISY, "phalcon/db/adapter/pdo/postgresql.zep", 313 TSRMLS_CC);
		if (Z_TYPE_P(_36$$3) != IS_NULL) {
			zephir_array_fetch_long(&_37$$26, field, 9, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 314 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(_38$$26);
			ZVAL_STRING(_38$$26, "/^'|'?::[[:alnum:][:space:]]+$/", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_INIT_NVAR(_39$$26);
			ZVAL_STRING(_39$$26, "", ZEPHIR_TEMP_PARAM_COPY);
			ZEPHIR_CALL_FUNCTION(&_40$$26, "preg_replace", &_41, 39, _38$$26, _39$$26, _37$$26);
			zephir_check_temp_parameter(_38$$26);
			zephir_check_temp_parameter(_39$$26);
			zephir_check_call_status();
			zephir_array_update_string(&definition, SL("default"), &_40$$26, PH_COPY | PH_SEPARATE);
			zephir_array_fetch_string(&_42$$26, definition, SL("default"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 315 TSRMLS_CC);
			ZEPHIR_SINIT_NVAR(_43$$26);
			ZVAL_STRING(&_43$$26, "null", 0);
			ZEPHIR_CALL_FUNCTION(&_44$$26, "strcasecmp", &_45, 16, _42$$26, &_43$$26);
			zephir_check_call_status();
			if (ZEPHIR_IS_LONG(_44$$26, 0)) {
				zephir_array_update_string(&definition, SL("default"), &ZEPHIR_GLOBAL(global_null), PH_COPY | PH_SEPARATE);
			}
		}
		zephir_array_fetch_long(&columnName, field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 323 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_46$$3);
		object_init_ex(_46$$3, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, _46$$3, "__construct", &_47, 149, columnName, definition);
		zephir_check_call_status();
		zephir_array_append(&columns, _46$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/postgresql.zep", 324);
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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *definition = NULL;
	zval *tableName_param = NULL, *schemaName_param = NULL, *definition_param = NULL, *sql = NULL, *queries = NULL, *query = NULL, *exception = NULL, *columns = NULL, *_0, **_3$$6, *_4$$7 = NULL, *_6$$10, *_7$$10;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &definition_param);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
		zephir_get_strval(schemaName, schemaName_param);
	} else {
		ZEPHIR_INIT_VAR(schemaName);
		ZVAL_EMPTY_STRING(schemaName);
	}
	definition = definition_param;


	ZEPHIR_OBS_VAR(columns);
	if (!(zephir_array_isset_string_fetch(&columns, definition, SS("columns"), 0 TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter/pdo/postgresql.zep", 339);
		return;
	}
	if (!(zephir_fast_count_int(columns TSRMLS_CC))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_db_exception_ce, "The table must contain at least one column", "phalcon/db/adapter/pdo/postgresql.zep", 343);
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
			zephir_is_iterable(queries, &_2$$6, &_1$$6, 0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 359);
			for (
			  ; zephir_hash_get_current_data_ex(_2$$6, (void**) &_3$$6, &_1$$6) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2$$6, &_1$$6)
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
			ZEPHIR_CPY_WRT(exception, EG(exception));
			if (zephir_instance_of_ev(exception, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(exception, "phalcon/db/adapter/pdo/postgresql.zep", 363 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		zephir_array_fetch_long(&_6$$10, queries, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 366 TSRMLS_CC);
		ZEPHIR_INIT_VAR(_7$$10);
		ZEPHIR_CONCAT_VS(_7$$10, _6$$10, ";");
		ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _7$$10);
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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *column, *currentColumn = NULL, *sql = NULL, *queries = NULL, *query = NULL, *exception = NULL, *_0, **_3$$4, *_4$$5 = NULL, *_6$$8 = NULL, *_7$$8, *_8$$8;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 1, &tableName_param, &schemaName_param, &column, &currentColumn);

	if (unlikely(Z_TYPE_P(tableName_param) != IS_STRING && Z_TYPE_P(tableName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tableName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(tableName_param) == IS_STRING)) {
		zephir_get_strval(tableName, tableName_param);
	} else {
		ZEPHIR_INIT_VAR(tableName);
		ZVAL_EMPTY_STRING(tableName);
	}
	if (unlikely(Z_TYPE_P(schemaName_param) != IS_STRING && Z_TYPE_P(schemaName_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schemaName' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schemaName_param) == IS_STRING)) {
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
			zephir_is_iterable(queries, &_2$$4, &_1$$4, 0, 0, "phalcon/db/adapter/pdo/postgresql.zep", 391);
			for (
			  ; zephir_hash_get_current_data_ex(_2$$4, (void**) &_3$$4, &_1$$4) == SUCCESS
			  ; zephir_hash_move_forward_ex(_2$$4, &_1$$4)
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
			ZEPHIR_CPY_WRT(exception, EG(exception));
			if (zephir_instance_of_ev(exception, zend_exception_get_default(TSRMLS_C) TSRMLS_CC)) {
				zend_clear_exception(TSRMLS_C);
				ZEPHIR_CALL_METHOD(NULL, this_ptr, "rollback", NULL, 0);
				zephir_check_call_status();
				zephir_throw_exception_debug(exception, "phalcon/db/adapter/pdo/postgresql.zep", 396 TSRMLS_CC);
				ZEPHIR_MM_RESTORE();
				return;
			}
		}
	} else {
		ZEPHIR_INIT_VAR(_6$$8);
		if (!(ZEPHIR_IS_EMPTY(sql))) {
			zephir_array_fetch_long(&_7$$8, queries, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/postgresql.zep", 400 TSRMLS_CC);
			ZEPHIR_INIT_VAR(_8$$8);
			ZEPHIR_CONCAT_VS(_8$$8, _7$$8, ";");
			ZEPHIR_CALL_METHOD(&_6$$8, this_ptr, "execute", NULL, 0, _8$$8);
			zephir_check_call_status();
		} else {
			ZVAL_BOOL(_6$$8, 1);
		}
		RETURN_CCTOR(_6$$8);
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
 * //Inserting a new robot with a valid default value for the column 'id'
 * $success = $connection->insert(
 *     "robots",
 *     array($connection->getDefaultIdValue(), "Astro Boy", 1952),
 *     array("id", "name", "year")
 * );
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Postgresql, getDefaultIdValue) {

	zval *_0;
	int ZEPHIR_LAST_CALL_STATUS;

	ZEPHIR_MM_GROW();

	object_init_ex(return_value, phalcon_db_rawvalue_ce);
	ZEPHIR_INIT_VAR(_0);
	ZVAL_STRING(_0, "DEFAULT", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 24, _0);
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

