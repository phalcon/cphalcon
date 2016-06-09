
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
 *
 * use Phalcon\Db\Adapter\Pdo\Mysql;
 *
 * $config = [
 *   "host"     => "192.168.0.11",
 *   "dbname"   => "blog",
 *   "port"     => 3306,
 *   "username" => "sigma",
 *   "password" => "secret"
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

	zval *identifier, identifier_sub, domain, name;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&identifier_sub);
	ZVAL_UNDEF(&domain);
	ZVAL_UNDEF(&name);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier);



	if (Z_TYPE_P(identifier) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(&domain);
		zephir_array_fetch_long(&domain, identifier, 0, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 72 TSRMLS_CC);
		ZEPHIR_OBS_VAR(&name);
		zephir_array_fetch_long(&name, identifier, 1, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 73 TSRMLS_CC);
		if (ZEPHIR_GLOBAL(db).escape_identifiers) {
			ZEPHIR_CONCAT_SVSVS(return_value, "`", &domain, "`.`", &name, "`");
			RETURN_MM();
		}
		ZEPHIR_CONCAT_VSV(return_value, &domain, ".", &name);
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

	zephir_fcall_cache_entry *_39 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, __$true, columns, columnType, field, definition, oldColumn, sizePattern, matches, matchOne, matchTwo, columnName, _0, _1, _2, _3, *_4, _5$$5, _6$$6, _7$$6, _8$$7, _9$$7, _10$$8, _11$$9, _12$$10, _13$$11, _14$$12, _15$$13, _16$$14, _17$$14, _18$$15, _19$$15, _20$$16, _21$$16, _22$$17, _23$$17, _24$$18, _25$$18, _26$$19, _27$$20, _28$$21, _29$$4, _30$$22, _31$$24, _32$$25, _33$$3, _34$$3, _35$$3, _36$$3, _38$$3, _37$$32;
	zval table, schema;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&columnType);
	ZVAL_UNDEF(&field);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&oldColumn);
	ZVAL_UNDEF(&sizePattern);
	ZVAL_UNDEF(&matches);
	ZVAL_UNDEF(&matchOne);
	ZVAL_UNDEF(&matchTwo);
	ZVAL_UNDEF(&columnName);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$6);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_8$$7);
	ZVAL_UNDEF(&_9$$7);
	ZVAL_UNDEF(&_10$$8);
	ZVAL_UNDEF(&_11$$9);
	ZVAL_UNDEF(&_12$$10);
	ZVAL_UNDEF(&_13$$11);
	ZVAL_UNDEF(&_14$$12);
	ZVAL_UNDEF(&_15$$13);
	ZVAL_UNDEF(&_16$$14);
	ZVAL_UNDEF(&_17$$14);
	ZVAL_UNDEF(&_18$$15);
	ZVAL_UNDEF(&_19$$15);
	ZVAL_UNDEF(&_20$$16);
	ZVAL_UNDEF(&_21$$16);
	ZVAL_UNDEF(&_22$$17);
	ZVAL_UNDEF(&_23$$17);
	ZVAL_UNDEF(&_24$$18);
	ZVAL_UNDEF(&_25$$18);
	ZVAL_UNDEF(&_26$$19);
	ZVAL_UNDEF(&_27$$20);
	ZVAL_UNDEF(&_28$$21);
	ZVAL_UNDEF(&_29$$4);
	ZVAL_UNDEF(&_30$$22);
	ZVAL_UNDEF(&_31$$24);
	ZVAL_UNDEF(&_32$$25);
	ZVAL_UNDEF(&_33$$3);
	ZVAL_UNDEF(&_34$$3);
	ZVAL_UNDEF(&_35$$3);
	ZVAL_UNDEF(&_36$$3);
	ZVAL_UNDEF(&_38$$3);
	ZVAL_UNDEF(&_37$$32);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	zephir_get_strval(&table, table_param);
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
		zephir_get_strval(&schema, schema_param);
	}


	ZEPHIR_INIT_VAR(&oldColumn);
	ZVAL_NULL(&oldColumn);
	ZEPHIR_INIT_VAR(&sizePattern);
	ZVAL_STRING(&sizePattern, "#\\(([0-9]+)(?:,\\s*([0-9]+))*\\)#");
	ZEPHIR_INIT_VAR(&columns);
	array_init(&columns);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describecolumns", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/mysql.zep", 346);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&field);
		ZVAL_COPY(&field, _4);
		ZEPHIR_INIT_NVAR(&definition);
		zephir_create_array(&definition, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(&definition, SL("bindType"), 2);
		ZEPHIR_OBS_NVAR(&columnType);
		zephir_array_fetch_long(&columnType, &field, 1, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 120 TSRMLS_CC);
		while (1) {
			if (zephir_memnstr_str(&columnType, SL("enum"), "phalcon/db/adapter/pdo/mysql.zep", 127)) {
				ZEPHIR_INIT_NVAR(&_5$$5);
				ZVAL_LONG(&_5$$5, 5);
				zephir_array_update_string(&definition, SL("type"), &_5$$5, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("bigint"), "phalcon/db/adapter/pdo/mysql.zep", 135)) {
				ZEPHIR_INIT_NVAR(&_6$$6);
				ZVAL_LONG(&_6$$6, 14);
				zephir_array_update_string(&definition, SL("type"), &_6$$6, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_7$$6);
				ZVAL_LONG(&_7$$6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_7$$6, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("int"), "phalcon/db/adapter/pdo/mysql.zep", 145)) {
				ZEPHIR_INIT_NVAR(&_8$$7);
				ZVAL_LONG(&_8$$7, 0);
				zephir_array_update_string(&definition, SL("type"), &_8$$7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_9$$7);
				ZVAL_LONG(&_9$$7, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_9$$7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("varchar"), "phalcon/db/adapter/pdo/mysql.zep", 155)) {
				ZEPHIR_INIT_NVAR(&_10$$8);
				ZVAL_LONG(&_10$$8, 2);
				zephir_array_update_string(&definition, SL("type"), &_10$$8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("datetime"), "phalcon/db/adapter/pdo/mysql.zep", 163)) {
				ZEPHIR_INIT_NVAR(&_11$$9);
				ZVAL_LONG(&_11$$9, 4);
				zephir_array_update_string(&definition, SL("type"), &_11$$9, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("char"), "phalcon/db/adapter/pdo/mysql.zep", 171)) {
				ZEPHIR_INIT_NVAR(&_12$$10);
				ZVAL_LONG(&_12$$10, 5);
				zephir_array_update_string(&definition, SL("type"), &_12$$10, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("date"), "phalcon/db/adapter/pdo/mysql.zep", 179)) {
				ZEPHIR_INIT_NVAR(&_13$$11);
				ZVAL_LONG(&_13$$11, 1);
				zephir_array_update_string(&definition, SL("type"), &_13$$11, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("timestamp"), "phalcon/db/adapter/pdo/mysql.zep", 187)) {
				ZEPHIR_INIT_NVAR(&_14$$12);
				ZVAL_LONG(&_14$$12, 17);
				zephir_array_update_string(&definition, SL("type"), &_14$$12, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("text"), "phalcon/db/adapter/pdo/mysql.zep", 195)) {
				ZEPHIR_INIT_NVAR(&_15$$13);
				ZVAL_LONG(&_15$$13, 6);
				zephir_array_update_string(&definition, SL("type"), &_15$$13, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("decimal"), "phalcon/db/adapter/pdo/mysql.zep", 203)) {
				ZEPHIR_INIT_NVAR(&_16$$14);
				ZVAL_LONG(&_16$$14, 3);
				zephir_array_update_string(&definition, SL("type"), &_16$$14, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_17$$14);
				ZVAL_LONG(&_17$$14, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_17$$14, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("double"), "phalcon/db/adapter/pdo/mysql.zep", 213)) {
				ZEPHIR_INIT_NVAR(&_18$$15);
				ZVAL_LONG(&_18$$15, 9);
				zephir_array_update_string(&definition, SL("type"), &_18$$15, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_19$$15);
				ZVAL_LONG(&_19$$15, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_19$$15, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("float"), "phalcon/db/adapter/pdo/mysql.zep", 223)) {
				ZEPHIR_INIT_NVAR(&_20$$16);
				ZVAL_LONG(&_20$$16, 7);
				zephir_array_update_string(&definition, SL("type"), &_20$$16, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &__$true, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_21$$16);
				ZVAL_LONG(&_21$$16, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_21$$16, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("bit"), "phalcon/db/adapter/pdo/mysql.zep", 233)) {
				ZEPHIR_INIT_NVAR(&_22$$17);
				ZVAL_LONG(&_22$$17, 8);
				zephir_array_update_string(&definition, SL("type"), &_22$$17, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_23$$17);
				ZVAL_LONG(&_23$$17, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_23$$17, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("tinyblob"), "phalcon/db/adapter/pdo/mysql.zep", 242)) {
				ZEPHIR_INIT_NVAR(&_24$$18);
				ZVAL_LONG(&_24$$18, 10);
				zephir_array_update_string(&definition, SL("type"), &_24$$18, PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(&_25$$18);
				ZVAL_LONG(&_25$$18, 5);
				zephir_array_update_string(&definition, SL("bindType"), &_25$$18, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("mediumblob"), "phalcon/db/adapter/pdo/mysql.zep", 251)) {
				ZEPHIR_INIT_NVAR(&_26$$19);
				ZVAL_LONG(&_26$$19, 12);
				zephir_array_update_string(&definition, SL("type"), &_26$$19, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("longblob"), "phalcon/db/adapter/pdo/mysql.zep", 259)) {
				ZEPHIR_INIT_NVAR(&_27$$20);
				ZVAL_LONG(&_27$$20, 13);
				zephir_array_update_string(&definition, SL("type"), &_27$$20, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(&columnType, SL("blob"), "phalcon/db/adapter/pdo/mysql.zep", 267)) {
				ZEPHIR_INIT_NVAR(&_28$$21);
				ZVAL_LONG(&_28$$21, 11);
				zephir_array_update_string(&definition, SL("type"), &_28$$21, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(&_29$$4);
			ZVAL_LONG(&_29$$4, 2);
			zephir_array_update_string(&definition, SL("type"), &_29$$4, PH_COPY | PH_SEPARATE);
			break;
		}
		if (zephir_memnstr_str(&columnType, SL("("), "phalcon/db/adapter/pdo/mysql.zep", 282)) {
			ZEPHIR_INIT_NVAR(&matches);
			ZVAL_NULL(&matches);
			ZEPHIR_INIT_NVAR(&_30$$22);
			zephir_preg_match(&_30$$22, &sizePattern, &columnType, &matches, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(&_30$$22)) {
				ZEPHIR_OBS_NVAR(&matchOne);
				if (zephir_array_isset_long_fetch(&matchOne, &matches, 1, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(&_31$$24);
					ZVAL_LONG(&_31$$24, zephir_get_intval(&matchOne));
					zephir_array_update_string(&definition, SL("size"), &_31$$24, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(&matchTwo);
				if (zephir_array_isset_long_fetch(&matchTwo, &matches, 2, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(&_32$$25);
					ZVAL_LONG(&_32$$25, zephir_get_intval(&matchTwo));
					zephir_array_update_string(&definition, SL("scale"), &_32$$25, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_memnstr_str(&columnType, SL("unsigned"), "phalcon/db/adapter/pdo/mysql.zep", 297)) {
			zephir_array_update_string(&definition, SL("unsigned"), &__$true, PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(&oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &__$true, PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_33$$3, &field, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 313 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_33$$3, "PRI")) {
			zephir_array_update_string(&definition, SL("primary"), &__$true, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_34$$3, &field, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 320 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_34$$3, "NO")) {
			zephir_array_update_string(&definition, SL("notNull"), &__$true, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_35$$3, &field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 327 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&_35$$3, "auto_increment")) {
			zephir_array_update_string(&definition, SL("autoIncrement"), &__$true, PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_NVAR(&_36$$3);
		zephir_array_fetch_long(&_36$$3, &field, 4, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 334 TSRMLS_CC);
		if (Z_TYPE_P(&_36$$3) != IS_NULL) {
			zephir_array_fetch_long(&_37$$32, &field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 335 TSRMLS_CC);
			zephir_array_update_string(&definition, SL("default"), &_37$$32, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&columnName, &field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 341 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(&_38$$3);
		object_init_ex(&_38$$3, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, &_38$$3, "__construct", &_39, 151, &columnName, &definition);
		zephir_check_call_status();
		zephir_array_append(&columns, &_38$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 342);
		ZEPHIR_CPY_WRT(&oldColumn, &columnName);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&field);
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

	zend_string *_15;
	zend_ulong _14;
	zephir_fcall_cache_entry *_19 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema = NULL, schema_sub, __$null, indexes, index, keyName, indexType, indexObjects, columns, name, _0, _1, _2, _3, *_4, *_13, _5$$4, _6$$3, _8$$3, _9$$3, _7$$6, _10$$7, _11$$8, _12$$9, _16$$11, _17$$11, _18$$11;
	zval table;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&indexes);
	ZVAL_UNDEF(&index);
	ZVAL_UNDEF(&keyName);
	ZVAL_UNDEF(&indexType);
	ZVAL_UNDEF(&indexObjects);
	ZVAL_UNDEF(&columns);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_5$$4);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&_8$$3);
	ZVAL_UNDEF(&_9$$3);
	ZVAL_UNDEF(&_7$$6);
	ZVAL_UNDEF(&_10$$7);
	ZVAL_UNDEF(&_11$$8);
	ZVAL_UNDEF(&_12$$9);
	ZVAL_UNDEF(&_16$$11);
	ZVAL_UNDEF(&_17$$11);
	ZVAL_UNDEF(&_18$$11);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema) {
		schema = &schema_sub;
		schema = &__$null;
	}


	ZEPHIR_INIT_VAR(&indexes);
	array_init(&indexes);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describeindexes", NULL, 0, &table, schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 2);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/mysql.zep", 393);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_COPY(&index, _4);
		zephir_array_fetch_string(&keyName, &index, SL("Key_name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 366 TSRMLS_CC);
		zephir_array_fetch_string(&indexType, &index, SL("Index_type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 367 TSRMLS_CC);
		if (!(zephir_array_isset(&indexes, &keyName))) {
			ZEPHIR_INIT_NVAR(&_5$$4);
			array_init(&_5$$4);
			zephir_array_update_zval(&indexes, &keyName, &_5$$4, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch(&_6$$3, &indexes, &keyName, PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 373 TSRMLS_CC);
		if (!(zephir_array_isset_string(&_6$$3, SL("columns")))) {
			ZEPHIR_INIT_NVAR(&columns);
			array_init(&columns);
		} else {
			zephir_array_fetch(&_7$$6, &indexes, &keyName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 376 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&columns);
			zephir_array_fetch_string(&columns, &_7$$6, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 376 TSRMLS_CC);
		}
		zephir_array_fetch_string(&_8$$3, &index, SL("Column_name"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 379 TSRMLS_CC);
		zephir_array_append(&columns, &_8$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 379);
		zephir_array_update_multi(&indexes, &columns TSRMLS_CC, SL("zs"), 3, &keyName, SL("columns"));
		zephir_array_fetch_string(&_9$$3, &index, SL("Non_unique"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 386 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(&keyName, "PRIMARY")) {
			ZEPHIR_INIT_NVAR(&_10$$7);
			ZVAL_STRING(&_10$$7, "PRIMARY");
			zephir_array_update_multi(&indexes, &_10$$7 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
		} else if (ZEPHIR_IS_STRING(&indexType, "FULLTEXT")) {
			ZEPHIR_INIT_NVAR(&_11$$8);
			ZVAL_STRING(&_11$$8, "FULLTEXT");
			zephir_array_update_multi(&indexes, &_11$$8 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
		} else if (ZEPHIR_IS_LONG(&_9$$3, 0)) {
			ZEPHIR_INIT_NVAR(&_12$$9);
			ZVAL_STRING(&_12$$9, "UNIQUE");
			zephir_array_update_multi(&indexes, &_12$$9 TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
		} else {
			zephir_array_update_multi(&indexes, &__$null TSRMLS_CC, SL("zs"), 3, &keyName, SL("type"));
		}
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_VAR(&indexObjects);
	array_init(&indexObjects);
	zephir_is_iterable(&indexes, 0, "phalcon/db/adapter/pdo/mysql.zep", 398);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&indexes), _14, _15, _13)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_15 != NULL) { 
			ZVAL_STR_COPY(&name, _15);
		} else {
			ZVAL_LONG(&name, _14);
		}
		ZEPHIR_INIT_NVAR(&index);
		ZVAL_COPY(&index, _13);
		ZEPHIR_INIT_NVAR(&_16$$11);
		object_init_ex(&_16$$11, phalcon_db_index_ce);
		zephir_array_fetch_string(&_17$$11, &index, SL("columns"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 395 TSRMLS_CC);
		zephir_array_fetch_string(&_18$$11, &index, SL("type"), PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 395 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(NULL, &_16$$11, "__construct", &_19, 19, &name, &_17$$11, &_18$$11);
		zephir_check_call_status();
		zephir_array_update_zval(&indexObjects, &name, &_16$$11, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&index);
	ZEPHIR_INIT_NVAR(&name);
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

	zval _13$$3, _18$$6;
	zend_string *_16;
	zend_ulong _15;
	zephir_fcall_cache_entry *_20 = NULL;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, references, reference, arrayReference, constraintName, referenceObjects, name, referencedSchema, referencedTable, columns, referencedColumns, referenceUpdate, referenceDelete, _0, _1, _2, _3, *_4, *_14, _5$$5, _6$$5, _7$$5, _8$$5, _9$$5, _10$$5, _11$$3, _12$$3, _17$$6, _19$$6;
	zval table, schema;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&table);
	ZVAL_UNDEF(&schema);
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
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);
	ZVAL_UNDEF(&_9$$5);
	ZVAL_UNDEF(&_10$$5);
	ZVAL_UNDEF(&_11$$3);
	ZVAL_UNDEF(&_12$$3);
	ZVAL_UNDEF(&_17$$6);
	ZVAL_UNDEF(&_19$$6);
	ZVAL_UNDEF(&_13$$3);
	ZVAL_UNDEF(&_18$$6);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

	if (unlikely(Z_TYPE_P(table_param) != IS_STRING && Z_TYPE_P(table_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'table' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(table_param) == IS_STRING)) {
		zephir_get_strval(&table, table_param);
	} else {
		ZEPHIR_INIT_VAR(&table);
		ZVAL_EMPTY_STRING(&table);
	}
	if (!schema_param) {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_STRING(&schema, "");
	} else {
	if (unlikely(Z_TYPE_P(schema_param) != IS_STRING && Z_TYPE_P(schema_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'schema' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(schema_param) == IS_STRING)) {
		zephir_get_strval(&schema, schema_param);
	} else {
		ZEPHIR_INIT_VAR(&schema);
		ZVAL_EMPTY_STRING(&schema);
	}
	}


	ZEPHIR_INIT_VAR(&references);
	array_init(&references);
	zephir_read_property(&_1, this_ptr, SL("_dialect"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, &_1, "describereferences", NULL, 0, &table, &schema);
	zephir_check_call_status();
	ZVAL_LONG(&_3, 3);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "fetchall", NULL, 0, &_2, &_3);
	zephir_check_call_status();
	zephir_is_iterable(&_0, 0, "phalcon/db/adapter/pdo/mysql.zep", 450);
	ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(&_0), _4)
	{
		ZEPHIR_INIT_NVAR(&reference);
		ZVAL_COPY(&reference, _4);
		zephir_array_fetch_long(&constraintName, &reference, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 419 TSRMLS_CC);
		if (!(zephir_array_isset(&references, &constraintName))) {
			ZEPHIR_OBS_NVAR(&referencedSchema);
			zephir_array_fetch_long(&referencedSchema, &reference, 3, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 421 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedTable);
			zephir_array_fetch_long(&referencedTable, &reference, 4, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 422 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referenceUpdate);
			zephir_array_fetch_long(&referenceUpdate, &reference, 6, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 423 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referenceDelete);
			zephir_array_fetch_long(&referenceDelete, &reference, 7, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 424 TSRMLS_CC);
			ZEPHIR_INIT_NVAR(&columns);
			array_init(&columns);
			ZEPHIR_INIT_NVAR(&referencedColumns);
			array_init(&referencedColumns);
		} else {
			zephir_array_fetch(&_5$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 429 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedSchema);
			zephir_array_fetch_string(&referencedSchema, &_5$$5, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 429 TSRMLS_CC);
			zephir_array_fetch(&_6$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 430 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedTable);
			zephir_array_fetch_string(&referencedTable, &_6$$5, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 430 TSRMLS_CC);
			zephir_array_fetch(&_7$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 431 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&columns);
			zephir_array_fetch_string(&columns, &_7$$5, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 431 TSRMLS_CC);
			zephir_array_fetch(&_8$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 432 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referencedColumns);
			zephir_array_fetch_string(&referencedColumns, &_8$$5, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 432 TSRMLS_CC);
			zephir_array_fetch(&_9$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 433 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referenceUpdate);
			zephir_array_fetch_string(&referenceUpdate, &_9$$5, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 433 TSRMLS_CC);
			zephir_array_fetch(&_10$$5, &references, &constraintName, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 434 TSRMLS_CC);
			ZEPHIR_OBS_NVAR(&referenceDelete);
			zephir_array_fetch_string(&referenceDelete, &_10$$5, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 434 TSRMLS_CC);
		}
		zephir_array_fetch_long(&_11$$3, &reference, 1, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 437 TSRMLS_CC);
		zephir_array_append(&columns, &_11$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 437);
		zephir_array_fetch_long(&_12$$3, &reference, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 438 TSRMLS_CC);
		zephir_array_append(&referencedColumns, &_12$$3, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 438);
		ZEPHIR_INIT_NVAR(&_13$$3);
		zephir_create_array(&_13$$3, 6, 0 TSRMLS_CC);
		zephir_array_update_string(&_13$$3, SL("referencedSchema"), &referencedSchema, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("referencedTable"), &referencedTable, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("columns"), &columns, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("referencedColumns"), &referencedColumns, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("onUpdate"), &referenceUpdate, PH_COPY | PH_SEPARATE);
		zephir_array_update_string(&_13$$3, SL("onDelete"), &referenceDelete, PH_COPY | PH_SEPARATE);
		zephir_array_update_zval(&references, &constraintName, &_13$$3, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&reference);
	ZEPHIR_INIT_VAR(&referenceObjects);
	array_init(&referenceObjects);
	zephir_is_iterable(&references, 0, "phalcon/db/adapter/pdo/mysql.zep", 462);
	ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&references), _15, _16, _14)
	{
		ZEPHIR_INIT_NVAR(&name);
		if (_16 != NULL) { 
			ZVAL_STR_COPY(&name, _16);
		} else {
			ZVAL_LONG(&name, _15);
		}
		ZEPHIR_INIT_NVAR(&arrayReference);
		ZVAL_COPY(&arrayReference, _14);
		ZEPHIR_INIT_NVAR(&_17$$6);
		object_init_ex(&_17$$6, phalcon_db_reference_ce);
		ZEPHIR_INIT_NVAR(&_18$$6);
		zephir_create_array(&_18$$6, 6, 0 TSRMLS_CC);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("referencedSchema"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 453 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedSchema"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("referencedTable"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 454 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedTable"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("columns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 455 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("columns"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("referencedColumns"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 456 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("referencedColumns"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("onUpdate"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 457 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("onUpdate"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_OBS_NVAR(&_19$$6);
		zephir_array_fetch_string(&_19$$6, &arrayReference, SL("onDelete"), PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 459 TSRMLS_CC);
		zephir_array_update_string(&_18$$6, SL("onDelete"), &_19$$6, PH_COPY | PH_SEPARATE);
		ZEPHIR_CALL_METHOD(NULL, &_17$$6, "__construct", &_20, 20, &name, &_18$$6);
		zephir_check_call_status();
		zephir_array_update_zval(&referenceObjects, &name, &_17$$6, PH_COPY | PH_SEPARATE);
	} ZEND_HASH_FOREACH_END();
	ZEPHIR_INIT_NVAR(&arrayReference);
	ZEPHIR_INIT_NVAR(&name);
	RETURN_CCTOR(referenceObjects);

}

