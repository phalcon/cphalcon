
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */
/**
 * Phalcon\Db\Adapter\Pdo\Mysql
 *
 * Specific functions for the Mysql database system
 *
 *<code>
 *
 *	$config = array(
 *		"host" => "192.168.0.11",
 *		"dbname" => "blog",
 *		"port" => 3306,
 *		"username" => "sigma",
 *		"password" => "secret"
 *	);
 *
 *	$connection = new Phalcon\Db\Adapter\Pdo\Mysql($config);
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Db_Adapter_Pdo_Mysql) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Db\\Adapter\\Pdo, Mysql, phalcon, db_adapter_pdo_mysql, phalcon_db_adapter_pdo_ce, phalcon_db_adapter_pdo_mysql_method_entry, 0);

	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_type"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_db_adapter_pdo_mysql_ce, SL("_dialectType"), "mysql", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Escapes a column/table/schema name
 *
 * @param string|array identifier
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, escapeIdentifier) {

	zval *identifier, *domain, *name;

	zephir_fetch_params(0, 1, 0, &identifier);



	if ((Z_TYPE_P(identifier) == IS_ARRAY)) {
		zephir_array_fetch_long(&domain, identifier, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		zephir_array_fetch_long(&name, identifier, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_GLOBAL(db).escape_identifiers) {
			ZEPHIR_CONCAT_SVSVS(return_value, "`", domain, "`.`", name, "`");
			return;
		}
		ZEPHIR_CONCAT_VSV(return_value, domain, ".", name);
		return;
	}
	if (ZEPHIR_GLOBAL(db).escape_identifiers) {
		ZEPHIR_CONCAT_SVS(return_value, "`", identifier, "`");
		return;
	}
	RETURN_CCTORW(identifier);

}

/**
 * Returns an array of Phalcon\Db\Column objects describing a table
 *
 * <code>
 * print_r($connection->describeColumns("posts"));
 * </code>
 *
 * @param string table
 * @param string schema
 * @return Phalcon\Db\Column[]
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, describeColumns) {

	zend_function *_12 = NULL;
	HashTable *_3;
	HashPosition _2;
	zval *table_param = NULL, *schema_param = NULL, *describe, *columns, *columnType, *field = NULL, *definition = NULL, *oldColumn = NULL, *dialect, *sizePattern, *matches = NULL, *matchOne, *columnName, *_0, *_1 = NULL, **_4, *_5 = NULL, *_6 = NULL, _7 = zval_used_for_init, *_8 = NULL, *_9, *_10, *_11;
	zval *table = NULL, *schema = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &table_param, &schema_param);

		zephir_get_strval(table, table_param);
	if (!schema_param || Z_TYPE_P(schema_param) == IS_NULL) {
		ZEPHIR_INIT_VAR(schema);
		ZVAL_EMPTY_STRING(schema);
	} else {
		zephir_get_strval(schema, schema_param);
	}


	dialect = zephir_fetch_nproperty_this(this_ptr, SL("_dialect"), PH_NOISY_CC);
	ZEPHIR_INIT_VAR(_0);
	zephir_call_method_p2(_0, dialect, "describecolumns", table, schema);
	ZEPHIR_INIT_VAR(_1);
	ZVAL_LONG(_1, 3);
	ZEPHIR_INIT_VAR(describe);
	zephir_call_method_p2(describe, this_ptr, "fetchall", _0, _1);
	ZEPHIR_INIT_VAR(oldColumn);
	ZVAL_NULL(oldColumn);
	ZEPHIR_INIT_VAR(sizePattern);
	ZVAL_STRING(sizePattern, "#\\(([0-9]+)(,[0-9]+)*\\)#", 1);
	ZEPHIR_INIT_VAR(columns);
	array_init(columns);
	zephir_is_iterable(describe, &_3, &_2, 0, 0);
	for (
		; zend_hash_get_current_data_ex(_3, (void**) &_4, &_2) == SUCCESS
		; zend_hash_move_forward_ex(_3, &_2)
	) {
		ZEPHIR_GET_HVALUE(field, _4);
		ZEPHIR_INIT_NVAR(definition);
		array_init(definition);
		add_assoc_long_ex(definition, SS("bindType"), 2);
		zephir_array_fetch_long(&columnType, field, 1, PH_NOISY | PH_READONLY TSRMLS_CC);
		while (1) {
			if (zephir_memnstr_str(columnType, SL("enum"), "phalcon/db/adapter/pdo/mysql.zep", 123)) {
				ZEPHIR_INIT_NVAR(_1);
				ZVAL_LONG(_1, 2);
				zephir_array_update_string(&definition, SL("type"), &_1, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("int"), "phalcon/db/adapter/pdo/mysql.zep", 131)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 0);
				zephir_array_update_string(&definition, SL("type"), &_5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_LONG(_6, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_6, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("varchar"), "phalcon/db/adapter/pdo/mysql.zep", 141)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 2);
				zephir_array_update_string(&definition, SL("type"), &_5, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("datetime"), "phalcon/db/adapter/pdo/mysql.zep", 149)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 4);
				zephir_array_update_string(&definition, SL("type"), &_5, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("decimal"), "phalcon/db/adapter/pdo/mysql.zep", 157)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 3);
				zephir_array_update_string(&definition, SL("type"), &_5, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_LONG(_6, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_6, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("char"), "phalcon/db/adapter/pdo/mysql.zep", 167)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 5);
				zephir_array_update_string(&definition, SL("type"), &_5, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("date"), "phalcon/db/adapter/pdo/mysql.zep", 175)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 1);
				zephir_array_update_string(&definition, SL("type"), &_5, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("text"), "phalcon/db/adapter/pdo/mysql.zep", 183)) {
				ZEPHIR_INIT_NVAR(_5);
				ZVAL_LONG(_5, 6);
				zephir_array_update_string(&definition, SL("type"), &_5, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_SINIT_NVAR(_7);
			ZVAL_STRING(&_7, "float", 0);
			ZEPHIR_INIT_NVAR(_5);
			zephir_call_func_p2(_5, "strpos", columnType, &_7);
			if (zephir_is_true(_5)) {
				ZEPHIR_INIT_NVAR(_6);
				ZVAL_LONG(_6, 7);
				zephir_array_update_string(&definition, SL("type"), &_6, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 3);
				zephir_array_update_string(&definition, SL("bindType"), &_8, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(_5);
			ZVAL_LONG(_5, 2);
			zephir_array_update_string(&definition, SL("type"), &_5, PH_COPY | PH_SEPARATE);
			break;
		}
		if (zephir_memnstr_str(columnType, SL("("), "phalcon/db/adapter/pdo/mysql.zep", 208)) {
			ZEPHIR_INIT_NVAR(matches);
			ZVAL_NULL(matches);
			Z_SET_ISREF_P(matches);
			ZEPHIR_INIT_NVAR(_6);
			zephir_call_func_p3(_6, "preg_match", sizePattern, columnType, matches);
			if (zephir_is_true(_6)) {
				if (zephir_array_isset_long_fetch(&matchOne, matches, 1, 1 TSRMLS_CC)) {
					zephir_array_update_string(&definition, SL("size"), &matchOne, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_memnstr_str(columnType, SL("unsigned"), "phalcon/db/adapter/pdo/mysql.zep", 220)) {
			zephir_array_update_string(&definition, SL("unsigned"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		if (!(zephir_is_true(oldColumn))) {
			zephir_array_update_string(&definition, SL("first"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_9, field, 3, PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_9, "PRI")) {
			zephir_array_update_string(&definition, SL("primary"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_10, field, 2, PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_10, "NO")) {
			zephir_array_update_string(&definition, SL("notNull"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_11, field, 5, PH_NOISY | PH_READONLY TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_11, "auto_increment")) {
			zephir_array_update_string(&definition, SL("autoIncrement"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&columnName, field, 0, PH_NOISY | PH_READONLY TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_5);
		object_init_ex(_5, phalcon_db_column_ce);
		zephir_call_method_p2_cache_noret(_5, "__construct", &_12, columnName, definition);
		zephir_array_append(&columns, _5, PH_SEPARATE);
		ZEPHIR_CPY_WRT(oldColumn, columnName);
	}
	RETURN_CCTOR(columns);

}

