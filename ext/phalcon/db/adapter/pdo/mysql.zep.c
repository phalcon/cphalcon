
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
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/hash.h"
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
 *   'host'     => 'localhost',
 *   'dbname'   => 'blog',
 *   'port'     => 3306,
 *   'username' => 'sigma',
 *   'password' => 'secret'
 * ];
 *
 * $connection = new Mysql($config);
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Mysql, phalcon, db_adapter_pdo_mysql, phalcon_db_adapter_pdo_ce, phalcon_db_adapter_pdo_mysql_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_type"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_dialectType"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_db_adapter_pdo_mysql_ce TSRMLS_CC, 1, phalcon_db_adapterinterface_ce);
	return SUCCESS;

}

/**
 * Escapes a column/table/schema name
 *
 * <code>
 * echo $connection->escapeIdentifier('my_table'); // `my_table`
 * echo $connection->escapeIdentifier(['companies', 'name']); // `companies`.`name`
 * <code>
 *
 * @param string|array identifier
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, escapeIdentifier) {

	zval *identifier, *domain = NULL, *name = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier);



	if (Z_TYPE_P(identifier) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(domain);
		zephir_array_fetch_long(&domain, identifier, 0, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 71 TSRMLS_CC);
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_long(&name, identifier, 1, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 72 TSRMLS_CC);
		if (ZEPHIR_GLOBAL(db).escape_identifiers) {
			ZEPHIR_CONCAT_SVSVS(return_value, "`", domain, "`.`", name, "`");
			RETURN_MM();
		}
		ZEPHIR_CONCAT_VSV(return_value, domain, ".", name);
		RETURN_MM();
	}
	if (ZEPHIR_GLOBAL(db).escape_identifiers) {
		ZEPHIR_CONCAT_SVS(return_value, "`", identifier, "`");
		RETURN_MM();
	}
	RETVAL_ZVAL(identifier, 1, 0);
	RETURN_MM();

}

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 *
 * <code>
 * print_r($connection->describeColumns("posts"));
 * </code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns) {

	HashTable *_5;
	HashPosition _4;
	zephir_fcall_cache_entry *_41 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *columns = NULL, *columnType = NULL, *field = NULL, *definition = NULL, *oldColumn = NULL, *sizePattern = NULL, *matches = NULL, *matchOne = NULL, *matchTwo = NULL, *columnName = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, *_7$$5 = NULL, *_8$$6 = NULL, *_9$$6 = NULL, *_10$$7 = NULL, *_11$$7 = NULL, *_12$$8 = NULL, *_13$$9 = NULL, *_14$$10 = NULL, *_15$$11 = NULL, *_16$$12 = NULL, *_17$$13 = NULL, *_18$$14 = NULL, *_19$$14 = NULL, *_20$$15 = NULL, *_21$$15 = NULL, *_22$$16 = NULL, *_23$$16 = NULL, *_24$$17 = NULL, *_25$$17 = NULL, *_26$$18 = NULL, *_27$$18 = NULL, *_28$$19 = NULL, *_29$$20 = NULL, *_30$$21 = NULL, *_31$$4 = NULL, *_32$$22 = NULL, *_33$$24 = NULL, *_34$$25 = NULL, *_35$$3, *_36$$3, *_37$$3, *_38$$3 = NULL, *_40$$3 = NULL, *_39$$32;
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
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/mysql.zep", 345);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(field, _6);
		ZEPHIR_INIT_NVAR(definition);
		zephir_create_array(definition, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(definition, SS("bindType"), 2);
		ZEPHIR_OBS_NVAR(columnType);
		zephir_array_fetch_long(&columnType, field, 1, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 119 TSRMLS_CC);
		while (1) {
			if (zephir_memnstr_str(columnType, SL("enum"), "phalcon/db/adapter/pdo/mysql.zep", 126)) {
				ZEPHIR_INIT_NVAR(_7$$5);
				ZVAL_LONG(_7$$5, 5);
				zephir_array_update_string(&definition, SL("type"), &_7$$5, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("bigint"), "phalcon/db/adapter/pdo/mysql.zep", 134)) {
				ZEPHIR_INIT_NVAR(_8$$6);
				ZVAL_LONG(_8$$6, 14);
				zephir_array_update_string(&definition, SL("type"), &_8$$6, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_9$$6);
				ZVAL_LONG(_9$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_9$$6, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("int"), "phalcon/db/adapter/pdo/mysql.zep", 144)) {
				ZEPHIR_INIT_NVAR(_10$$7);
				ZVAL_LONG(_10$$7, 0);
				zephir_array_update_string(&definition, SL("type"), &_10$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_11$$7);
				ZVAL_LONG(_11$$7, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_11$$7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("varchar"), "phalcon/db/adapter/pdo/mysql.zep", 154)) {
				ZEPHIR_INIT_NVAR(_12$$8);
				ZVAL_LONG(_12$$8, 2);
				zephir_array_update_string(&definition, SL("type"), &_12$$8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("datetime"), "phalcon/db/adapter/pdo/mysql.zep", 162)) {
				ZEPHIR_INIT_NVAR(_13$$9);
				ZVAL_LONG(_13$$9, 4);
				zephir_array_update_string(&definition, SL("type"), &_13$$9, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("char"), "phalcon/db/adapter/pdo/mysql.zep", 170)) {
				ZEPHIR_INIT_NVAR(_14$$10);
				ZVAL_LONG(_14$$10, 5);
				zephir_array_update_string(&definition, SL("type"), &_14$$10, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("date"), "phalcon/db/adapter/pdo/mysql.zep", 178)) {
				ZEPHIR_INIT_NVAR(_15$$11);
				ZVAL_LONG(_15$$11, 1);
				zephir_array_update_string(&definition, SL("type"), &_15$$11, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("timestamp"), "phalcon/db/adapter/pdo/mysql.zep", 186)) {
				ZEPHIR_INIT_NVAR(_16$$12);
				ZVAL_LONG(_16$$12, 17);
				zephir_array_update_string(&definition, SL("type"), &_16$$12, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("text"), "phalcon/db/adapter/pdo/mysql.zep", 194)) {
				ZEPHIR_INIT_NVAR(_17$$13);
				ZVAL_LONG(_17$$13, 6);
				zephir_array_update_string(&definition, SL("type"), &_17$$13, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("decimal"), "phalcon/db/adapter/pdo/mysql.zep", 202)) {
				ZEPHIR_INIT_NVAR(_18$$14);
				ZVAL_LONG(_18$$14, 3);
				zephir_array_update_string(&definition, SL("type"), &_18$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_19$$14);
				ZVAL_LONG(_19$$14, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_19$$14, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("double"), "phalcon/db/adapter/pdo/mysql.zep", 212)) {
				ZEPHIR_INIT_NVAR(_20$$15);
				ZVAL_LONG(_20$$15, 9);
				zephir_array_update_string(&definition, SL("type"), &_20$$15, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_21$$15);
				ZVAL_LONG(_21$$15, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_21$$15, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("float"), "phalcon/db/adapter/pdo/mysql.zep", 222)) {
				ZEPHIR_INIT_NVAR(_22$$16);
				ZVAL_LONG(_22$$16, 7);
				zephir_array_update_string(&definition, SL("type"), &_22$$16, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_23$$16);
				ZVAL_LONG(_23$$16, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_23$$16, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("bit"), "phalcon/db/adapter/pdo/mysql.zep", 232)) {
				ZEPHIR_INIT_NVAR(_24$$17);
				ZVAL_LONG(_24$$17, 8);
				zephir_array_update_string(&definition, SL("type"), &_24$$17, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_25$$17);
				ZVAL_LONG(_25$$17, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_25$$17, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("tinyblob"), "phalcon/db/adapter/pdo/mysql.zep", 241)) {
				ZEPHIR_INIT_NVAR(_26$$18);
				ZVAL_LONG(_26$$18, 10);
				zephir_array_update_string(&definition, SL("type"), &_26$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_27$$18);
				ZVAL_LONG(_27$$18, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_27$$18, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("mediumblob"), "phalcon/db/adapter/pdo/mysql.zep", 250)) {
				ZEPHIR_INIT_NVAR(_28$$19);
				ZVAL_LONG(_28$$19, 12);
				zephir_array_update_string(&definition, SL("type"), &_28$$19, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("longblob"), "phalcon/db/adapter/pdo/mysql.zep", 258)) {
				ZEPHIR_INIT_NVAR(_29$$20);
				ZVAL_LONG(_29$$20, 13);
				zephir_array_update_string(&definition, SL("type"), &_29$$20, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("blob"), "phalcon/db/adapter/pdo/mysql.zep", 266)) {
				ZEPHIR_INIT_NVAR(_30$$21);
				ZVAL_LONG(_30$$21, 11);
				zephir_array_update_string(&definition, SL("type"), &_30$$21, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(_31$$4);
			ZVAL_LONG(_31$$4, 2);
			zephir_array_update_string(&definition, SL("type"), &_31$$4, PH_COPY | PH_SEPARATE);
			break;
		}
		if (zephir_memnstr_str(columnType, SL("("), "phalcon/db/adapter/pdo/mysql.zep", 281)) {
			ZEPHIR_INIT_NVAR(matches);
			ZVAL_NULL(matches);
			ZEPHIR_INIT_NVAR(_32$$22);
			zephir_preg_match(_32$$22, sizePattern, columnType, matches, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(_32$$22)) {
				ZEPHIR_OBS_NVAR(matchOne);
				if (zephir_array_isset_long_fetch(&matchOne, matches, 1, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_33$$24);
					ZVAL_LONG(_33$$24, zephir_get_intval(matchOne));
					zephir_array_update_string(&definition, SL("size"), &_33$$24, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(matchTwo);
				if (zephir_array_isset_long_fetch(&matchTwo, matches, 2, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_34$$25);
					ZVAL_LONG(_34$$25, zephir_get_intval(matchTwo));
					zephir_array_update_string(&definition, SL("scale"), &_34$$25, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_memnstr_str(columnType, SL("unsigned"), "phalcon/db/adapter/pdo/mysql.zep", 296)) {
			zephir_array_update_string(&definition, SL("unsigned"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_35$$3, field, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 312 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_35$$3, "PRI")) {
			zephir_array_update_string(&definition, SL("primary"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_36$$3, field, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 319 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_36$$3, "NO")) {
			zephir_array_update_string(&definition, SL("notNull"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_37$$3, field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 326 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_37$$3, "auto_increment")) {
			zephir_array_update_string(&definition, SL("autoIncrement"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_NVAR(_38$$3);
		zephir_array_fetch_long(&_38$$3, field, 4, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 333 TSRMLS_CC);
		if (Z_TYPE_P(_38$$3) != IS_NULL) {
			zephir_array_fetch_long(&_39$$32, field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 334 TSRMLS_CC);
			zephir_array_update_string(&definition, SL("default"), &_39$$32, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&columnName, field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 340 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_40$$3);
		object_init_ex(_40$$3, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, _40$$3, "__construct", &_41, 149, columnName, definition);
		zephir_check_call_status();
		zephir_array_append(&columns, _40$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 341);
		ZEPHIR_CPY_WRT(oldColumn, columnName);
	}
	RETURN_CCTOR(columns);

}

/**
 * Lists table indexes
 *
 * <code>
 *   print_r($connection->describeIndexes('robots_parts'));
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
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema = NULL, *indexes = NULL, *index = NULL, *keyName = NULL, *indexType = NULL, *indexObjects = NULL, *columns = NULL, *name = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, **_17, *_7$$4 = NULL, *_8$$3, *_10$$3, *_11$$3, *_9$$6, *_12$$7 = NULL, *_13$$8 = NULL, *_14$$9 = NULL, *_18$$11 = NULL, *_19$$11, *_20$$11;
	zval *table = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema) {
		schema = ZEPHIR_GLOBAL(global_null);
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
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/mysql.zep", 392);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(index, _6);
		zephir_array_fetch_string(&keyName, index, SL("Key_name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 365 TSRMLS_CC);
		zephir_array_fetch_string(&indexType, index, SL("Index_type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 366 TSRMLS_CC);
		if (!(zephir_array_isset(indexes, keyName))) {
			ZEPHIR_INIT_NVAR(_7$$4);
			array_init(_7$$4);
			zephir_array_update_zval(&indexes, keyName, &_7$$4, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch(&_8$$3, indexes, keyName, PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 372 TSRMLS_CC);
		if (!(zephir_array_isset_string(_8$$3, SS("columns")))) {
			ZEPHIR_INIT_NVAR(columns);
			array_init(columns);
		} else {
			zephir_array_fetch(&_9$$6, indexes, keyName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 375 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(columns);
			zephir_array_fetch_string(&columns, _9$$6, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 375 TSRMLS_CC);
		}
		zephir_array_fetch_string(&_10$$3, index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 378 TSRMLS_CC);
		zephir_array_append(&columns, _10$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 378);
		zephir_array_update_multi(&indexes, &columns TSRMLS_CC, SL("zs"), 3, keyName, SL("columns"));
		zephir_array_fetch_string(&_11$$3, index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 385 TSRMLS_CC);
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
	zephir_is_iterable(indexes, &_16, &_15, 0, 0, "phalcon/db/adapter/pdo/mysql.zep", 397);
	for (
	  ; zephir_hash_get_current_data_ex(_16, (void**) &_17, &_15) == SUCCESS
	  ; zephir_hash_move_forward_ex(_16, &_15)
	) {
		ZEPHIR_GET_HMKEY(name, _16, _15);
		ZEPHIR_GET_HVALUE(index, _17);
		ZEPHIR_INIT_NVAR(_18$$11);
		object_init_ex(_18$$11, phalcon_db_index_ce);
		zephir_array_fetch_string(&_19$$11, index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 394 TSRMLS_CC);
		zephir_array_fetch_string(&_20$$11, index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 394 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, _18$$11, "__construct", &_21, 22, name, _19$$11, _20$$11);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, name, &_18$$11, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(indexObjects);

}

/**
 * Lists table references
 *
 *<code>
 * print_r($connection->describeReferences('robots_parts'));
 *</code>
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeReferences) {

	zval *_15$$3 = NULL, *_20$$6 = NULL;
	HashTable *_5, *_17;
	HashPosition _4, _16;
	zephir_fcall_cache_entry *_22 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *references = NULL, *reference = NULL, *arrayReference = NULL, *constraintName = NULL, *referenceObjects = NULL, *name = NULL, *referencedSchema = NULL, *referencedTable = NULL, *columns = NULL, *referencedColumns = NULL, *referenceUpdate = NULL, *referenceDelete = NULL, *_0 = NULL, *_1, *_2 = NULL, *_3, **_6, **_18, *_7$$5, *_8$$5, *_9$$5, *_10$$5, *_11$$5, *_12$$5, *_13$$3, *_14$$3, *_19$$6 = NULL, *_21$$6 = NULL;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(table, table_param);
	} else {
		ZEPHIR_INIT_VAR(table);
		ZVAL_EMPTY_STRING(table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
	if (unlikely(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schema_param) == IS_STRING)) {
		zephir_get_strval(schema, schema_param);
	} else {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	}
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
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/mysql.zep", 449);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(reference, _6);
		zephir_array_fetch_long(&constraintName, reference, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 418 TSRMLS_CC);
		if (!(zephir_array_isset(references, constraintName))) {
			ZEPHIR_OBS_NVAR(referencedSchema);
			zephir_array_fetch_long(&referencedSchema, reference, 3, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 420 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedTable);
			zephir_array_fetch_long(&referencedTable, reference, 4, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 421 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referenceUpdate);
			zephir_array_fetch_long(&referenceUpdate, reference, 6, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 422 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referenceDelete);
			zephir_array_fetch_long(&referenceDelete, reference, 7, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 423 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(columns);
			array_init(columns);
			ZEPHIR_INIT_NVAR(referencedColumns);
			array_init(referencedColumns);
		} else {
			zephir_array_fetch(&_7$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 428 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedSchema);
			zephir_array_fetch_string(&referencedSchema, _7$$5, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 428 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 429 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedTable);
			zephir_array_fetch_string(&referencedTable, _8$$5, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 429 TSRMLS_CC);
			zephir_array_fetch(&_9$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 430 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(columns);
			zephir_array_fetch_string(&columns, _9$$5, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 430 TSRMLS_CC);
			zephir_array_fetch(&_10$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 431 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referencedColumns);
			zephir_array_fetch_string(&referencedColumns, _10$$5, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 431 TSRMLS_CC);
			zephir_array_fetch(&_11$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 432 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referenceUpdate);
			zephir_array_fetch_string(&referenceUpdate, _11$$5, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 432 TSRMLS_CC);
			zephir_array_fetch(&_12$$5, references, constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 433 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(referenceDelete);
			zephir_array_fetch_string(&referenceDelete, _12$$5, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 433 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_13$$3, reference, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 436 TSRMLS_CC);
		zephir_array_append(&columns, _13$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 436);
		zephir_array_fetch_long(&_14$$3, reference, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 437 TSRMLS_CC);
		zephir_array_append(&referencedColumns, _14$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 437);
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
	zephir_is_iterable(references, &_17, &_16, 0, 0, "phalcon/db/adapter/pdo/mysql.zep", 461);
	for (
	  ; zephir_hash_get_current_data_ex(_17, (void**) &_18, &_16) == SUCCESS
	  ; zephir_hash_move_forward_ex(_17, &_16)
	) {
		ZEPHIR_GET_HMKEY(name, _17, _16);
		ZEPHIR_GET_HVALUE(arrayReference, _18);
		ZEPHIR_INIT_NVAR(_19$$6);
		object_init_ex(_19$$6, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(_20$$6);
		zephir_create_array(_20$$6, 6, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(_21$$6);
		zephir_array_fetch_string(&_21$$6, arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 452 TSRMLS_CC);
		zephir_array_update_string(&_20$$6, SL("referencedSchema"), &_21$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_21$$6);
		zephir_array_fetch_string(&_21$$6, arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 453 TSRMLS_CC);
		zephir_array_update_string(&_20$$6, SL("referencedTable"), &_21$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_21$$6);
		zephir_array_fetch_string(&_21$$6, arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 454 TSRMLS_CC);
		zephir_array_update_string(&_20$$6, SL("columns"), &_21$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_21$$6);
		zephir_array_fetch_string(&_21$$6, arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 455 TSRMLS_CC);
		zephir_array_update_string(&_20$$6, SL("referencedColumns"), &_21$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_21$$6);
		zephir_array_fetch_string(&_21$$6, arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 456 TSRMLS_CC);
		zephir_array_update_string(&_20$$6, SL("onUpdate"), &_21$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(_21$$6);
		zephir_array_fetch_string(&_21$$6, arrayReference, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 458 TSRMLS_CC);
		zephir_array_update_string(&_20$$6, SL("onDelete"), &_21$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, _19$$6, "__construct", &_22, 23, name, _20$$6);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, name, &_19$$6, PH_COPY | PH_SEPARATE);
	}
	RETURN_CCTOR(referenceObjects);

}

