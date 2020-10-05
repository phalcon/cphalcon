
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/string.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AtlasPHP
 *
 * @link    https://github.com/atlasphp/Atlas.Query
 * @license https://github.com/atlasphp/Atlas.Qyert/blob/1.x/LICENSE.md
 */
/**
 * Class AbstractQuery
 *
 * @property Bind       $bind
 * @property Connection $connection
 * @property array      $store
 */
ZEPHIR_INIT_CLASS(Phalcon_DataMapper_Query_AbstractQuery) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\DataMapper\\Query, AbstractQuery, phalcon, datamapper_query_abstractquery, phalcon_datamapper_query_abstractquery_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var Bind
	 */
	zend_declare_property_null(phalcon_datamapper_query_abstractquery_ce, SL("bind"), ZEND_ACC_PROTECTED);

	/**
	 * @var Connection
	 */
	zend_declare_property_null(phalcon_datamapper_query_abstractquery_ce, SL("connection"), ZEND_ACC_PROTECTED);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_datamapper_query_abstractquery_ce, SL("store"), ZEND_ACC_PROTECTED);

	phalcon_datamapper_query_abstractquery_ce->create_object = zephir_init_properties_Phalcon_DataMapper_Query_AbstractQuery;
	return SUCCESS;

}

/**
 * AbstractQuery constructor.
 *
 * @param Connection $connection
 * @param Bind       $bind
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, __construct) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *connection, connection_sub, *bind, bind_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection_sub);
	ZVAL_UNDEF(&bind_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &connection, &bind);



	zephir_update_property_zval(this_ptr, SL("bind"), bind);
	zephir_update_property_zval(this_ptr, SL("connection"), connection);
	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "UNION");
	zephir_update_property_array(this_ptr, SL("store"), &_1, &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "reset", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();

}

/**
 * Binds a value inline
 *
 * @param mixed $value
 * @param int   $type
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, bindInline) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *value, value_sub, *type_param = NULL, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &value, &type_param);

	if (!type_param) {
		type = -1;
	} else {
		type = zephir_get_intval(type_param);
	}


	zephir_read_property(&_0, this_ptr, SL("bind"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, type);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "bindinline", NULL, 0, value, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Binds a value - auto-detects the type if necessary
 *
 * @param string $key
 * @param mixed  $value
 * @param int    $type
 *
 * @return AbstractQuery
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, bindValue) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *key_param = NULL, *value, value_sub, *type_param = NULL, _0, _1;
	zval key;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&key);
	ZVAL_UNDEF(&value_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 1, &key_param, &value, &type_param);

	zephir_get_strval(&key, key_param);
	if (!type_param) {
		type = -1;
	} else {
		type = zephir_get_intval(type_param);
	}


	zephir_read_property(&_0, this_ptr, SL("bind"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, type);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setvalue", NULL, 0, &key, value, &_1);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Binds an array of values
 *
 * @param array $values
 *
 * @return AbstractQuery
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, bindValues) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *values_param = NULL, _0;
	zval values;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&values);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &values_param);

	zephir_get_arrval(&values, values_param);


	zephir_read_property(&_0, this_ptr, SL("bind"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, &_0, "setvalues", NULL, 0, &values);
	zephir_check_call_status();
	RETURN_THIS();

}

/**
 * Returns all the bound values
 *
 * @return array
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, getBindValues) {

	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("bind"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "toarray", NULL, 0);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the generated statement
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, getStatement) {

}

/**
 * Performs a statement in the connection
 *
 * @return PDOStatement
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, perform) {

	zval _0, _1, _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("connection"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_1, this_ptr, "getstatement", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "getbindvalues", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_RETURN_CALL_METHOD(&_0, "perform", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Sets a flag for the query such as "DISTINCT"
 *
 * @param string $flag
 * @param bool   $enable
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, setFlag) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_bool enable;
	zval *flag_param = NULL, *enable_param = NULL, __$true, flags, _0$$4, _1$$4;
	zval flag;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&flag);
	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&flags);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &flag_param, &enable_param);

	zephir_get_strval(&flag, flag_param);
	if (!enable_param) {
		enable = 1;
	} else {
		enable = zephir_get_boolval(enable_param);
	}


	if (enable) {
		zephir_update_property_array_multi(this_ptr, SL("store"), &__$true, SL("sz"), 3, SL("FLAGS"), &flag);
	} else {
		zephir_read_property(&_0$$4, this_ptr, SL("store"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_OBS_VAR(&flags);
		zephir_array_fetch_string(&flags, &_0$$4, SL("FLAGS"), PH_NOISY, "phalcon/DataMapper/Query/AbstractQuery.zep", 148);
		zephir_array_unset(&flags, &flag, PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_STRING(&_1$$4, "FLAGS");
		zephir_update_property_array(this_ptr, SL("store"), &_1$$4, &flags);
	}
	ZEPHIR_MM_RESTORE();

}

/**
 * Quotes the identifier
 *
 * @param string $name
 * @param int    $type
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, quoteIdentifier) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long type, ZEPHIR_LAST_CALL_STATUS;
	zval *name_param = NULL, *type_param = NULL, _0, _1;
	zval name;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &name_param, &type_param);

	zephir_get_strval(&name, name_param);
	if (!type_param) {
		type = 2;
	} else {
		type = zephir_get_intval(type_param);
	}


	zephir_read_property(&_0, this_ptr, SL("connection"), PH_NOISY_CC | PH_READONLY);
	ZVAL_LONG(&_1, type);
	ZEPHIR_RETURN_CALL_METHOD(&_0, "quote", NULL, 0, &name, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Resets the internal array
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, reset) {

	zval _0, _1, _2, _3, _4, _5, _6, _7, _8, _9, _10, _11, _12, _13, _14, _15, _16, _17;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_12);
	ZVAL_UNDEF(&_13);
	ZVAL_UNDEF(&_14);
	ZVAL_UNDEF(&_15);
	ZVAL_UNDEF(&_16);
	ZVAL_UNDEF(&_17);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "COLUMNS");
	zephir_update_property_array(this_ptr, SL("store"), &_1, &_0);
	ZEPHIR_INIT_VAR(&_2);
	array_init(&_2);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "FLAGS");
	zephir_update_property_array(this_ptr, SL("store"), &_3, &_2);
	ZEPHIR_INIT_VAR(&_4);
	array_init(&_4);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, "FROM");
	zephir_update_property_array(this_ptr, SL("store"), &_5, &_4);
	ZEPHIR_INIT_VAR(&_6);
	array_init(&_6);
	ZEPHIR_INIT_VAR(&_7);
	ZVAL_STRING(&_7, "GROUP");
	zephir_update_property_array(this_ptr, SL("store"), &_7, &_6);
	ZEPHIR_INIT_VAR(&_8);
	array_init(&_8);
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "HAVING");
	zephir_update_property_array(this_ptr, SL("store"), &_9, &_8);
	ZEPHIR_INIT_VAR(&_10);
	ZVAL_STRING(&_10, "LIMIT");
	ZEPHIR_INIT_VAR(&_11);
	ZVAL_LONG(&_11, 0);
	zephir_update_property_array(this_ptr, SL("store"), &_10, &_11);
	ZEPHIR_INIT_VAR(&_12);
	array_init(&_12);
	ZEPHIR_INIT_VAR(&_13);
	ZVAL_STRING(&_13, "ORDER");
	zephir_update_property_array(this_ptr, SL("store"), &_13, &_12);
	ZEPHIR_INIT_VAR(&_14);
	ZVAL_STRING(&_14, "OFFSET");
	ZEPHIR_INIT_VAR(&_15);
	ZVAL_LONG(&_15, 0);
	zephir_update_property_array(this_ptr, SL("store"), &_14, &_15);
	ZEPHIR_INIT_VAR(&_16);
	array_init(&_16);
	ZEPHIR_INIT_VAR(&_17);
	ZVAL_STRING(&_17, "WHERE");
	zephir_update_property_array(this_ptr, SL("store"), &_17, &_16);
	ZEPHIR_MM_RESTORE();

}

/**
 * Builds the flags statement(s)
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, buildFlags) {

	zval _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("FLAGS"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractQuery.zep", 194);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_INIT_VAR(&_3);
	zephir_read_property(&_4, this_ptr, SL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_5, &_4, SL("FLAGS"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractQuery.zep", 198);
	zephir_array_keys(&_3, &_5);
	zephir_fast_join_str(&_2, SL(" "), &_3);
	ZEPHIR_CONCAT_SV(return_value, " ", &_2);
	RETURN_MM();

}

/**
 * Builds the `RETURNING` clause
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, buildReturning) {

	zval _0, _1, _2, _3, _4, _5;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	zephir_read_property(&_0, this_ptr, SL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_1, &_0, SL("RETURNING"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractQuery.zep", 208);
	if (ZEPHIR_IS_EMPTY(&_1)) {
		RETURN_MM_STRING("");
	}
	zephir_read_property(&_3, this_ptr, SL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_array_fetch_string(&_4, &_3, SL("RETURNING"), PH_NOISY | PH_READONLY, "phalcon/DataMapper/Query/AbstractQuery.zep", 212);
	ZEPHIR_INIT_VAR(&_5);
	ZVAL_STRING(&_5, ",");
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "indent", NULL, 0, &_4, &_5);
	zephir_check_call_status();
	ZEPHIR_CONCAT_SV(return_value, " RETURNING", &_2);
	RETURN_MM();

}

/**
 * Indents a collection
 *
 * @param array  $collection
 * @param string $glue
 *
 * @return string
 */
PHP_METHOD(Phalcon_DataMapper_Query_AbstractQuery, indent) {

	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval glue, _1;
	zval *collection_param = NULL, *glue_param = NULL, _0;
	zval collection;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&collection);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&glue);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &collection_param, &glue_param);

	zephir_get_arrval(&collection, collection_param);
	if (!glue_param) {
		ZEPHIR_INIT_VAR(&glue);
		ZVAL_STRING(&glue, "");
	} else {
		zephir_get_strval(&glue, glue_param);
	}


	if (ZEPHIR_IS_EMPTY(&collection)) {
		RETURN_MM_STRING("");
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_VS(&_1, &glue, " ");
	zephir_fast_join(&_0, &_1, &collection);
	ZEPHIR_CONCAT_SV(return_value, " ", &_0);
	RETURN_MM();

}

zend_object *zephir_init_properties_Phalcon_DataMapper_Query_AbstractQuery(zend_class_entry *class_type TSRMLS_DC) {

		zval _0, _1$$3;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1$$3);

		ZEPHIR_MM_GROW();
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property(&_0, this_ptr, SL("store"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval(this_ptr, SL("store"), &_1$$3);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}

}

