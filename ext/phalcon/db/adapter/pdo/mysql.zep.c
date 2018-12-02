
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/operators.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"


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

	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_type"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_dialectType"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

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

	HashTable *_5;
	HashPosition _4;
	zephir_fcall_cache_entry *_40 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *columns = NULL, *columnType = NULL, *field = NULL, *definition = NULL, *oldColumn = NULL, *sizePattern = NULL, *matches = NULL, *matchOne = NULL, *matchTwo = NULL, *columnName = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, *_7$$4 = NULL, *_8$$5 = NULL, *_9$$5 = NULL, *_10$$6 = NULL, *_11$$6 = NULL, *_12$$7 = NULL, *_13$$8 = NULL, *_14$$9 = NULL, *_15$$10 = NULL, *_16$$11 = NULL, *_17$$12 = NULL, *_18$$13 = NULL, *_19$$13 = NULL, *_20$$14 = NULL, *_21$$14 = NULL, *_22$$15 = NULL, *_23$$15 = NULL, *_24$$16 = NULL, *_25$$16 = NULL, *_26$$17 = NULL, *_27$$18 = NULL, *_28$$19 = NULL, *_29$$20 = NULL, *_30$$21 = NULL, *_31$$22 = NULL, *_32$$24 = NULL, *_33$$25 = NULL, *_34$$3, *_35$$3, *_36$$3, *_37$$3 = NULL, *_39$$3 = NULL, *_38$$32;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}


	ZEPHIR_INIT_VAR(oldColumn);
	ZVAL_NULL(oldColumn);
	ZEPHIR_INIT_VAR(sizePattern);
	ZVAL_STRING(sizePattern, "#\\(([0-9]+)(?:,\\s*([0-9]+))*\\)#", 1);
	ZEPHIR_INIT_VAR(columns);
	array_init(columns);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "describecolumns", NULL, 0, table, schema);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/mysql.zep", 264);
	for (
	  ; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(field, _6);
		ZEPHIR_INIT_NVAR(definition);
		zephir_create_array(definition, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(definition, SS("bindType"), 2);
		ZEPHIR_OBS_NVAR(columnType);
		zephir_array_fetch_long(&columnType, field, 1, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 92 TSRMLS_CC);
		if (zephir_memnstr_str(columnType, SL("enum"), "phalcon/db/adapter/pdo/mysql.zep", 94)) {
			ZEPHIR_INIT_NVAR(_7$$4);
			ZVAL_LONG(_7$$4, 5);
			zephir_array_update_string(&definition, SL("type"), &_7$$4, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("bigint"), "phalcon/db/adapter/pdo/mysql.zep", 99)) {
			ZEPHIR_INIT_NVAR(_8$$5);
			ZVAL_LONG(_8$$5, 14);
			zephir_array_update_string(&definition, SL("type"), &_8$$5, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_9$$5);
			ZVAL_LONG(_9$$5, 1);
			zephir_array_update_string(&definition, SL("bindType"), &_9$$5, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("int"), "phalcon/db/adapter/pdo/mysql.zep", 106)) {
			ZEPHIR_INIT_NVAR(_10$$6);
			ZVAL_LONG(_10$$6, 0);
			zephir_array_update_string(&definition, SL("type"), &_10$$6, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_11$$6);
			ZVAL_LONG(_11$$6, 1);
			zephir_array_update_string(&definition, SL("bindType"), &_11$$6, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("varchar"), "phalcon/db/adapter/pdo/mysql.zep", 113)) {
			ZEPHIR_INIT_NVAR(_12$$7);
			ZVAL_LONG(_12$$7, 2);
			zephir_array_update_string(&definition, SL("type"), &_12$$7, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("datetime"), "phalcon/db/adapter/pdo/mysql.zep", 118)) {
			ZEPHIR_INIT_NVAR(_13$$8);
			ZVAL_LONG(_13$$8, 4);
			zephir_array_update_string(&definition, SL("type"), &_13$$8, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("char"), "phalcon/db/adapter/pdo/mysql.zep", 123)) {
			ZEPHIR_INIT_NVAR(_14$$9);
			ZVAL_LONG(_14$$9, 5);
			zephir_array_update_string(&definition, SL("type"), &_14$$9, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("date"), "phalcon/db/adapter/pdo/mysql.zep", 128)) {
			ZEPHIR_INIT_NVAR(_15$$10);
			ZVAL_LONG(_15$$10, 1);
			zephir_array_update_string(&definition, SL("type"), &_15$$10, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("timestamp"), "phalcon/db/adapter/pdo/mysql.zep", 133)) {
			ZEPHIR_INIT_NVAR(_16$$11);
			ZVAL_LONG(_16$$11, 17);
			zephir_array_update_string(&definition, SL("type"), &_16$$11, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("text"), "phalcon/db/adapter/pdo/mysql.zep", 138)) {
			ZEPHIR_INIT_NVAR(_17$$12);
			ZVAL_LONG(_17$$12, 6);
			zephir_array_update_string(&definition, SL("type"), &_17$$12, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("decimal"), "phalcon/db/adapter/pdo/mysql.zep", 143)) {
			ZEPHIR_INIT_NVAR(_18$$13);
			ZVAL_LONG(_18$$13, 3);
			zephir_array_update_string(&definition, SL("type"), &_18$$13, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_19$$13);
			ZVAL_LONG(_19$$13, 32);
			zephir_array_update_string(&definition, SL("bindType"), &_19$$13, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("double"), "phalcon/db/adapter/pdo/mysql.zep", 150)) {
			ZEPHIR_INIT_NVAR(_20$$14);
			ZVAL_LONG(_20$$14, 9);
			zephir_array_update_string(&definition, SL("type"), &_20$$14, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_21$$14);
			ZVAL_LONG(_21$$14, 32);
			zephir_array_update_string(&definition, SL("bindType"), &_21$$14, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("float"), "phalcon/db/adapter/pdo/mysql.zep", 157)) {
			ZEPHIR_INIT_NVAR(_22$$15);
			ZVAL_LONG(_22$$15, 7);
			zephir_array_update_string(&definition, SL("type"), &_22$$15, PH_COPY | PH_SEPARATE);
			zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_23$$15);
			ZVAL_LONG(_23$$15, 32);
			zephir_array_update_string(&definition, SL("bindType"), &_23$$15, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("bit"), "phalcon/db/adapter/pdo/mysql.zep", 164)) {
			ZEPHIR_INIT_NVAR(_24$$16);
			ZVAL_LONG(_24$$16, 8);
			zephir_array_update_string(&definition, SL("type"), &_24$$16, PH_COPY | PH_SEPARATE);
			ZEPHIR_INIT_NVAR(_25$$16);
			ZVAL_LONG(_25$$16, 5);
			zephir_array_update_string(&definition, SL("bindType"), &_25$$16, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("tinyblob"), "phalcon/db/adapter/pdo/mysql.zep", 170)) {
			ZEPHIR_INIT_NVAR(_26$$17);
			ZVAL_LONG(_26$$17, 10);
			zephir_array_update_string(&definition, SL("type"), &_26$$17, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("mediumblob"), "phalcon/db/adapter/pdo/mysql.zep", 175)) {
			ZEPHIR_INIT_NVAR(_27$$18);
			ZVAL_LONG(_27$$18, 12);
			zephir_array_update_string(&definition, SL("type"), &_27$$18, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("longblob"), "phalcon/db/adapter/pdo/mysql.zep", 180)) {
			ZEPHIR_INIT_NVAR(_28$$19);
			ZVAL_LONG(_28$$19, 13);
			zephir_array_update_string(&definition, SL("type"), &_28$$19, PH_COPY | PH_SEPARATE);
		} else if (zephir_memnstr_str(columnType, SL("blob"), "phalcon/db/adapter/pdo/mysql.zep", 185)) {
			ZEPHIR_INIT_NVAR(_29$$20);
			ZVAL_LONG(_29$$20, 11);
			zephir_array_update_string(&definition, SL("type"), &_29$$20, PH_COPY | PH_SEPARATE);
		} else {
			ZEPHIR_INIT_NVAR(_30$$21);
			ZVAL_LONG(_30$$21, 2);
			zephir_array_update_string(&definition, SL("type"), &_30$$21, PH_COPY | PH_SEPARATE);
		}
		if (zephir_memnstr_str(columnType, SL("("), "phalcon/db/adapter/pdo/mysql.zep", 200)) {
			ZEPHIR_INIT_NVAR(matches);
			ZVAL_NULL(matches);
			ZEPHIR_INIT_NVAR(_31$$22);
			zephir_preg_match(_31$$22, sizePattern, columnType, matches, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(_31$$22)) {
				ZEPHIR_OBS_NVAR(matchOne);
				if (zephir_array_isset_long_fetch(&matchOne, matches, 1, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_32$$24);
					ZVAL_LONG(_32$$24, zephir_get_intval(matchOne));
					zephir_array_update_string(&definition, SL("size"), &_32$$24, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(matchTwo);
				if (zephir_array_isset_long_fetch(&matchTwo, matches, 2, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_33$$25);
					ZVAL_LONG(_33$$25, zephir_get_intval(matchTwo));
					zephir_array_update_string(&definition, SL("scale"), &_33$$25, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_memnstr_str(columnType, SL("unsigned"), "phalcon/db/adapter/pdo/mysql.zep", 215)) {
			zephir_array_update_string(&definition, SL("unsigned"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_34$$3, field, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 231 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_34$$3, "PRI")) {
			zephir_array_update_string(&definition, SL("primary"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_35$$3, field, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 238 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_35$$3, "NO")) {
			zephir_array_update_string(&definition, SL("notNull"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_36$$3, field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 245 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_36$$3, "auto_increment")) {
			zephir_array_update_string(&definition, SL("autoIncrement"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_NVAR(_37$$3);
		zephir_array_fetch_long(&_37$$3, field, 4, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 252 TSRMLS_CC);
		if (Z_TYPE_P(_37$$3) != IS_NULL) {
			zephir_array_fetch_long(&_38$$32, field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 253 TSRMLS_CC);
			zephir_array_update_string(&definition, SL("default"), &_38$$32, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&columnName, field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 259 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_39$$3);
		object_init_ex(_39$$3, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, _39$$3, "__construct", &_40, 167, columnName, definition);
		zephir_check_call_status();
		zephir_array_append(&columns, _39$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 260);
		ZEPHIR_CPY_WRT(oldColumn, columnName);
	}
	RETURN_CCTOR(columns);

}

/**
 * Lists table indexes
 *
 * <code>
 * print_r(
 *     $connection->describeIndexes("robots_parts")
 * );
 * </code>
 *
 * @param  string table
 * @param  string schema
 * @return \Phalcon\Db\IndexInterface[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeIndexes) {

	HashTable *_5, *_16;
	HashPosition _4, _15;
	zephir_fcall_cache_entry *_21 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *indexes = NULL, *index = NULL, *keyName = NULL, *indexType = NULL, *indexObjects = NULL, *columns = NULL, *name = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, **_17, *_7$$4 = NULL, *_8$$3, *_10$$3, *_11$$3, *_9$$6, *_12$$7 = NULL, *_13$$8 = NULL, *_14$$9 = NULL, *_18$$11 = NULL, *_19$$11, *_20$$11;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}


	ZEPHIR_INIT_VAR(indexes);
	array_init(indexes);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "describeindexes", NULL, 0, table, schema);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/mysql.zep", 313);
	for (
	  ; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(index, _6);
		zephir_array_fetch_string(&keyName, index, SL("Key_name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 286 TSRMLS_CC);
		zephir_array_fetch_string(&indexType, index, SL("Index_type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 287 TSRMLS_CC);
		if (!(zephir_array_isset(indexes, keyName))) {
			ZEPHIR_INIT_NVAR(_7$$4);
			array_init(_7$$4);
			zephir_array_update_zval(&indexes, keyName, &_7$$4, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch(&_8$$3, indexes, keyName, PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 293 TSRMLS_CC);
		if (!(zephir_array_isset_string(_8$$3, SS("columns")))) {
			ZEPHIR_INIT_NVAR(columns);
			array_init(columns);
		} else {
			zephir_array_fetch(&_9$$6, indexes, keyName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 296 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(columns);
			zephir_array_fetch_string(&columns, _9$$6, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 296 TSRMLS_CC);
		}
		zephir_array_fetch_string(&_10$$3, index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 299 TSRMLS_CC);
		zephir_array_append(&columns, _10$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 299);
		zephir_array_update_multi(&indexes, &columns TSRMLS_CC, SL("zs"), 3, keyName, SL("columns"));
		zephir_array_fetch_string(&_11$$3, index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 306 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(keyName, "PRIMARY")) {
			ZEPHIR_INIT_NVAR(_12$$7);
			ZVAL_STRING(_12$$7, "PRIMARY", 1);
			zephir_array_update_multi(&indexes, &_12$$7 TSRMLS_CC, SL("zs"), 3, keyName, SL("type"));
		} else if (ZEPHIR_IS_STRING(indexType, "FULLTEXT")) {
			ZEPHIR_INIT_NVAR(_13$$8);
			ZVAL_STRING(_13$$8, "FULLTEXT", 1);
			zephir_array_update_multi(&indexes, &_13$$8 TSRMLS_CC, SL("zs"), 3, keyName, SL("type"));
		} else if (ZEPHIR_IS_LONG(_11$$3, 0)) {
			ZEPHIR_INIT_NVAR(_14$$9);
			ZVAL_STRING(_14$$9, "UNIQUE", 1);
			zephir_array_update_multi(&indexes, &_14$$9 TSRMLS_CC, SL("zs"), 3, keyName, SL("type"));
		} else {
			zephir_array_update_multi(&indexes, &ZEPHIR_GLOBAL(global_null) TSRMLS_CC, SL("zs"), 3, keyName, SL("type"));
		}
	}
	ZEPHIR_INIT_VAR(indexObjects);
	array_init(indexObjects);
	zephir_is_iterable(indexes, &_16, &_15, 0, 0, "phalcon/db/adapter/pdo/mysql.zep", 318);
	for (
	  ; zend_hash_get_current_data_ex(_16, (void**) &_17, &_15) == SUCCESS
	  ; zend_hash_move_forward_ex(_16, &_15)
	) {
		ZEPHIR_GET_HMKEY(name, _16, _15);
		ZEPHIR_GET_HVALUE(index, _17);
		ZEPHIR_INIT_NVAR(_18$$11);
		object_init_ex(_18$$11, phalcon_db_index_ce);
		zephir_array_fetch_string(&_19$$11, index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 315 TSRMLS_CC);
		zephir_array_fetch_string(&_20$$11, index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 315 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, _18$$11, "__construct", &_21, 24, name, _19$$11, _20$$11);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, name, &_18$$11, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(indexObjects);

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

	zval *_15$$3 = NULL, *_20$$6 = NULL;
	HashTable *_5, *_17;
	HashPosition _4, _16;
	zephir_fcall_cache_entry *_22 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *references = NULL, *reference = NULL, *arrayReference = NULL, *constraintName = NULL, *referenceObjects = NULL, *name = NULL, *referencedSchema = NULL, *referencedTable = NULL, *columns = NULL, *referencedColumns = NULL, *referenceUpdate = NULL, *referenceDelete = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, **_18, *_7$$5, *_8$$5, *_9$$5, *_10$$5, *_11$$5, *_12$$5, *_13$$3, *_14$$3, *_19$$6 = NULL, *_21$$6 = NULL;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (UNEXPECTED(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}


	ZEPHIR_INIT_VAR(references);
	array_init(references);
	_1 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_2, _1, "describereferences", NULL, 0, table, schema);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_3);
	ZVAL_LONG(_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, _2, _3);
	zephir_check_call_status();
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/mysql.zep", 372);
	for (
	  ; zend_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zend_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(reference, _6);
		zephir_array_fetch_long(&constraintName, reference, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 341 TSRMLS_CC);
		if (!(zephir_array_isset(references, constraintName))) {
			ZEPHIR_OBS_NVAR(referencedSchema);
			zephir_array_fetch_long(&referencedSchema, reference, 3, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 343 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedTable);
			zephir_array_fetch_long(&referencedTable, reference, 4, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 344 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referenceUpdate);
			zephir_array_fetch_long(&referenceUpdate, reference, 6, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 345 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referenceDelete);
			zephir_array_fetch_long(&referenceDelete, reference, 7, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 346 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(columns);
			array_init(columns);
			ZEPHIR_INIT_NVAR(referencedColumns);
			array_init(referencedColumns);
		} else {
			zephir_array_fetch(&_7$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 351 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedSchema);
			zephir_array_fetch_string(&referencedSchema, _7$$5, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 351 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 352 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedTable);
			zephir_array_fetch_string(&referencedTable, _8$$5, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 352 TSRMLS_CC);
			zephir_array_fetch(&_9$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 353 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(columns);
			zephir_array_fetch_string(&columns, _9$$5, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 353 TSRMLS_CC);
			zephir_array_fetch(&_10$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 354 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedColumns);
			zephir_array_fetch_string(&referencedColumns, _10$$5, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 354 TSRMLS_CC);
			zephir_array_fetch(&_11$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 355 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referenceUpdate);
			zephir_array_fetch_string(&referenceUpdate, _11$$5, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 355 TSRMLS_CC);
			zephir_array_fetch(&_12$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 356 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referenceDelete);
			zephir_array_fetch_string(&referenceDelete, _12$$5, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 356 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_13$$3, reference, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 359 TSRMLS_CC);
		zephir_array_append(&columns, _13$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 359);
		zephir_array_fetch_long(&_14$$3, reference, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 360 TSRMLS_CC);
		zephir_array_append(&referencedColumns, _14$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 360);
		ZEPHIR_INIT_NVAR(_15$$3);
		zephir_create_array(_15$$3, 6, 0 TSRMLS_CC);
		zephir_array_update_string(&_15$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_15$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_15$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_15$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_15$$3, SL("onUpdate"), &referenceUpdate, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_15$$3, SL("onDelete"), &referenceDelete, PH_COPY | PH_SEPARATE);
		zephir_array_update_zval(&references, constraintName, &_15$$3, PH_COPY | PH_SEPARATE);
	}
	ZEPHIR_INIT_VAR(referenceObjects);
	array_init(referenceObjects);
	zephir_is_iterable(references, &_17, &_16, 0, 0, "phalcon/db/adapter/pdo/mysql.zep", 384);
	for (
	  ; zend_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
	  ; zend_hash_move_forward_ex(_17, &_16)
	) {
		ZEPHIR_GET_HMKEY(name, _17, _16);
		ZEPHIR_GET_HVALUE(arrayReference, _18);
		ZEPHIR_INIT_NVAR(_19$$6);
		object_init_ex(_19$$6, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(_20$$6);
		zephir_create_array(_20$$6, 6, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_21$$6);
		zephir_array_fetch_string(&_21$$6, arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 375 TSRMLS_CC);
		zephir_array_update_string(&_20$$6, SL("referencedSchema"), &_21$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_21$$6);
		zephir_array_fetch_string(&_21$$6, arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 376 TSRMLS_CC);
		zephir_array_update_string(&_20$$6, SL("referencedTable"), &_21$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_21$$6);
		zephir_array_fetch_string(&_21$$6, arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 377 TSRMLS_CC);
		zephir_array_update_string(&_20$$6, SL("columns"), &_21$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_21$$6);
		zephir_array_fetch_string(&_21$$6, arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 378 TSRMLS_CC);
		zephir_array_update_string(&_20$$6, SL("referencedColumns"), &_21$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_21$$6);
		zephir_array_fetch_string(&_21$$6, arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 379 TSRMLS_CC);
		zephir_array_update_string(&_20$$6, SL("onUpdate"), &_21$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_21$$6);
		zephir_array_fetch_string(&_21$$6, arrayReference, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 381 TSRMLS_CC);
		zephir_array_update_string(&_20$$6, SL("onDelete"), &_21$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, _19$$6, "__construct", &_22, 25, name, _20$$6);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, name, &_19$$6, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(referenceObjects);

}

/**
 * Adds a foreign key to a table
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, addForeignKey) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tableName_param = NULL, *schemaName_param = NULL, *reference, *foreignKeyCheck = NULL, *_0, *_1 = NULL, *_2 = NULL, *_3, *_4 = NULL;
	zval *tableName = NULL, *schemaName = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 3, 0, &tableName_param, &schemaName_param, &reference);

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


	_0 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_1, _0, "getforeignkeychecks", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&foreignKeyCheck, this_ptr, "prepare", NULL, 0, _1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, foreignKeyCheck, "execute", NULL, 0);
	zephir_check_call_status();
	if (!(zephir_is_true(_2))) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_application_exception_ce, "DATABASE PARAMETER 'FOREIGN_KEY_CHECKS' HAS TO BE 1", "phalcon/db/adapter/pdo/mysql.zep", 396);
		return;
	}
	_3 = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_CALL_METHOD(&_4, _3, "addforeignkey", NULL, 0, tableName, schemaName, reference);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "execute", NULL, 0, _4);
	zephir_check_call_status();
	RETURN_MM();

}

