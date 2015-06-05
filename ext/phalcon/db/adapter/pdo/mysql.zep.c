
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
 *	$connection = new \Phalcon\Db\Adapter\Pdo\Mysql($config);
 *
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
 * @param string|array identifier
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter_Pdo_Mysql, escapeIdentifier) {

	zval *identifier, *domain, *name;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &identifier);



	if (Z_TYPE_P(identifier) == IS_ARRAY) {
		ZEPHIR_OBS_VAR(domain);
		zephir_array_fetch_long(&domain, identifier, 0, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 64 TSRMLS_CC);
		ZEPHIR_OBS_VAR(name);
		zephir_array_fetch_long(&name, identifier, 1, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 65 TSRMLS_CC);
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

	zephir_fcall_cache_entry *_16 = NULL;
	zend_bool _9;
	HashTable *_5;
	HashPosition _4;
	int ZEPHIR_LAST_CALL_STATUS;
	zval *table_param = NULL, *schema_param = NULL, *columns, *columnType = NULL, *field = NULL, *definition = NULL, *oldColumn = NULL, *sizePattern, *matches = NULL, *matchOne = NULL, *matchTwo = NULL, *columnName, *_0 = NULL, *_1, *_2 = NULL, *_3 = NULL, **_6, *_7 = NULL, *_8 = NULL, *_10 = NULL, *_11, *_12, *_13, *_14 = NULL, *_15;
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
	zephir_is_iterable(_0, &_5, &_4, 0, 0, "phalcon/db/adapter/pdo/mysql.zep", 268);
	for (
	  ; zephir_hash_get_current_data_ex(_5, (void**) &_6, &_4) == SUCCESS
	  ; zephir_hash_move_forward_ex(_5, &_4)
	) {
		ZEPHIR_GET_HVALUE(field, _6);
		ZEPHIR_INIT_NVAR(definition);
		zephir_create_array(definition, 1, 0 TSRMLS_CC);
		add_assoc_long_ex(definition, SS("bindType"), 2);
		ZEPHIR_OBS_NVAR(columnType);
		zephir_array_fetch_long(&columnType, field, 1, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 112 TSRMLS_CC);
		while (1) {
			if (zephir_memnstr_str(columnType, SL("enum"), "phalcon/db/adapter/pdo/mysql.zep", 119)) {
				ZEPHIR_INIT_NVAR(_3);
				ZVAL_LONG(_3, 5);
				zephir_array_update_string(&definition, SL("type"), &_3, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("int"), "phalcon/db/adapter/pdo/mysql.zep", 127)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 0);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 1);
				zephir_array_update_string(&definition, SL("bindType"), &_8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("varchar"), "phalcon/db/adapter/pdo/mysql.zep", 137)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 2);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("datetime"), "phalcon/db/adapter/pdo/mysql.zep", 145)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 4);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			_9 = zephir_memnstr_str(columnType, SL("decimal"), "phalcon/db/adapter/pdo/mysql.zep", 153);
			if (!(_9)) {
				_9 = zephir_memnstr_str(columnType, SL("double"), "phalcon/db/adapter/pdo/mysql.zep", 153);
			}
			if (_9) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 3);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 32);
				zephir_array_update_string(&definition, SL("bindType"), &_8, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("char"), "phalcon/db/adapter/pdo/mysql.zep", 163)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 5);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("date"), "phalcon/db/adapter/pdo/mysql.zep", 171)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 1);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("text"), "phalcon/db/adapter/pdo/mysql.zep", 179)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 6);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				break;
			}
			if (zephir_memnstr_str(columnType, SL("float"), "phalcon/db/adapter/pdo/mysql.zep", 187)) {
				ZEPHIR_INIT_NVAR(_7);
				ZVAL_LONG(_7, 7);
				zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
				zephir_array_update_string(&definition, SL("isNumeric"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
				ZEPHIR_INIT_NVAR(_8);
				ZVAL_LONG(_8, 3);
				zephir_array_update_string(&definition, SL("bindType"), &_8, PH_COPY | PH_SEPARATE);
				break;
			}
			ZEPHIR_INIT_NVAR(_7);
			ZVAL_LONG(_7, 2);
			zephir_array_update_string(&definition, SL("type"), &_7, PH_COPY | PH_SEPARATE);
			break;
		}
		if (zephir_memnstr_str(columnType, SL("("), "phalcon/db/adapter/pdo/mysql.zep", 204)) {
			ZEPHIR_INIT_NVAR(matches);
			ZVAL_NULL(matches);
			ZEPHIR_INIT_NVAR(_8);
			zephir_preg_match(_8, sizePattern, columnType, matches, 0, 0 , 0  TSRMLS_CC);
			if (zephir_is_true(_8)) {
				ZEPHIR_OBS_NVAR(matchOne);
				if (zephir_array_isset_long_fetch(&matchOne, matches, 1, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_10);
					ZVAL_LONG(_10, zephir_get_intval(matchOne));
					zephir_array_update_string(&definition, SL("size"), &_10, PH_COPY | PH_SEPARATE);
				}
				ZEPHIR_OBS_NVAR(matchTwo);
				if (zephir_array_isset_long_fetch(&matchTwo, matches, 2, 0 TSRMLS_CC)) {
					ZEPHIR_INIT_NVAR(_10);
					ZVAL_LONG(_10, zephir_get_intval(matchTwo));
					zephir_array_update_string(&definition, SL("scale"), &_10, PH_COPY | PH_SEPARATE);
				}
			}
		}
		if (zephir_memnstr_str(columnType, SL("unsigned"), "phalcon/db/adapter/pdo/mysql.zep", 219)) {
			zephir_array_update_string(&definition, SL("unsigned"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		if (Z_TYPE_P(oldColumn) == IS_NULL) {
			zephir_array_update_string(&definition, SL("first"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		} else {
			zephir_array_update_string(&definition, SL("after"), &oldColumn, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_11, field, 3, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 235 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_11, "PRI")) {
			zephir_array_update_string(&definition, SL("primary"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_12, field, 2, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 242 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_12, "NO")) {
			zephir_array_update_string(&definition, SL("notNull"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&_13, field, 5, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 249 TSRMLS_CC);
		if (ZEPHIR_IS_STRING(_13, "auto_increment")) {
			zephir_array_update_string(&definition, SL("autoIncrement"), &ZEPHIR_GLOBAL(global_true), PH_COPY | PH_SEPARATE);
		}
		ZEPHIR_OBS_NVAR(_14);
		zephir_array_fetch_long(&_14, field, 4, PH_NOISY, "phalcon/db/adapter/pdo/mysql.zep", 256 TSRMLS_CC);
		if (Z_TYPE_P(_14) != IS_NULL) {
			zephir_array_fetch_long(&_15, field, 4, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 257 TSRMLS_CC);
			zephir_array_update_string(&definition, SL("default"), &_15, PH_COPY | PH_SEPARATE);
		}
		zephir_array_fetch_long(&columnName, field, 0, PH_NOISY | PH_READONLY, "phalcon/db/adapter/pdo/mysql.zep", 263 TSRMLS_CC);
		ZEPHIR_INIT_NVAR(_7);
		object_init_ex(_7, phalcon_db_column_ce);
		ZEPHIR_CALL_METHOD(NULL, _7, "__construct", &_16, 83, columnName, definition);
		zephir_check_call_status();
		zephir_array_append(&columns, _7, PH_SEPARATE, "phalcon/db/adapter/pdo/mysql.zep", 264);
		ZEPHIR_CPY_WRT(oldColumn, columnName);
	}
	RETURN_CCTOR(columns);

}

