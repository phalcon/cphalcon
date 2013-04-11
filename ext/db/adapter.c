
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/memory.h"

#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/file.h"
#include "kernel/string.h"

/**
 * Phalcon\Db\Adapter
 *
 * Base class for Phalcon\Db adapters
 */


/**
 * Phalcon\Db\Adapter initializer
 */
PHALCON_INIT_CLASS(Phalcon_Db_Adapter){

	PHALCON_REGISTER_CLASS(Phalcon\\Db, Adapter, db_adapter, phalcon_db_adapter_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	zend_declare_property_null(phalcon_db_adapter_ce, SL("_eventsManager"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_descriptor"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_dialectType"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_dialect"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_connectionId"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_sqlStatement"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_sqlVariables"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_db_adapter_ce, SL("_sqlBindTypes"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_long(phalcon_db_adapter_ce, SL("_connectionConsecutive"), 0, ZEND_ACC_PROTECTED|ZEND_ACC_STATIC TSRMLS_CC);

	zend_class_implements(phalcon_db_adapter_ce TSRMLS_CC, 1, phalcon_events_eventsawareinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Db\Adapter constructor
 *
 * @param array $descriptor
 */
PHP_METHOD(Phalcon_Db_Adapter, __construct){

	zval *descriptor, *one, *connection_consecutive;
	zval *next_consecutive, *dialect_type, *dialect_class = NULL;
	zval *dialect_object;
	zend_class_entry *ce0;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &descriptor) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_INIT_VAR(one);
	ZVAL_LONG(one, 1);
	
	/** 
	 * Every new connection created obtain a consecutive number from the static
	 * property self::$_connectionConsecutive
	 */
	PHALCON_OBS_VAR(connection_consecutive);
	phalcon_read_static_property(&connection_consecutive, SL("phalcon\\db\\adapter"), SL("_connectionConsecutive") TSRMLS_CC);
	
	PHALCON_INIT_VAR(next_consecutive);
	phalcon_add_function(next_consecutive, connection_consecutive, one TSRMLS_CC);
	phalcon_update_static_property(SL("phalcon\\db\\adapter"), SL("_connectionConsecutive"), next_consecutive TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_connectionId"), connection_consecutive TSRMLS_CC);
	
	/** 
	 * Dialect class can override the default dialect
	 */
	if (!phalcon_array_isset_string(descriptor, SS("dialectClass"))) {
		PHALCON_OBS_VAR(dialect_type);
		phalcon_read_property_this(&dialect_type, this_ptr, SL("_dialectType"), PH_NOISY_CC);
	
		PHALCON_INIT_VAR(dialect_class);
		PHALCON_CONCAT_SV(dialect_class, "phalcon\\db\\dialect\\", dialect_type);
	} else {
		PHALCON_OBS_NVAR(dialect_class);
		phalcon_array_fetch_string(&dialect_class, descriptor, SL("dialectClass"), PH_NOISY_CC);
	}
	
	ce0 = phalcon_fetch_class(dialect_class TSRMLS_CC);
	
	PHALCON_INIT_VAR(dialect_object);
	object_init_ex(dialect_object, ce0);
	if (phalcon_has_constructor(dialect_object TSRMLS_CC)) {
		PHALCON_CALL_METHOD_NORETURN(dialect_object, "__construct");
	}
	phalcon_update_property_zval(this_ptr, SL("_dialect"), dialect_object TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_descriptor"), descriptor TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Sets the event manager
 *
 * @param Phalcon\Events\ManagerInterface $eventsManager
 */
PHP_METHOD(Phalcon_Db_Adapter, setEventsManager){

	zval *events_manager;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &events_manager) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_eventsManager"), events_manager TSRMLS_CC);
	
}

/**
 * Returns the internal event manager
 *
 * @return Phalcon\Events\ManagerInterface
 */
PHP_METHOD(Phalcon_Db_Adapter, getEventsManager){


	RETURN_MEMBER(this_ptr, "_eventsManager");
}

/**
 * Returns the first row in a SQL query result
 *
 *<code>
 *	//Getting first robot
 *	$robot = $connection->fecthOne("SELECT * FROM robots");
 *	print_r($robot);
 *
 *	//Getting first robot with associative indexes only
 *	$robot = $connection->fecthOne("SELECT * FROM robots", Phalcon\Db::FETCH_ASSOC);
 *	print_r($robot);
 *</code>
 *
 * @param string $sqlQuery
 * @param int $fetchMode
 * @param array $bindParams
 * @param array $bindTypes
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, fetchOne){

	zval *sql_query, *fetch_mode = NULL, *bind_params = NULL, *bind_types = NULL;
	zval *result, *row, *empty_row;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zzz", &sql_query, &fetch_mode, &bind_params, &bind_types) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!fetch_mode) {
		PHALCON_INIT_VAR(fetch_mode);
		ZVAL_LONG(fetch_mode, 2);
	}
	
	if (!bind_params) {
		PHALCON_INIT_VAR(bind_params);
	}
	
	if (!bind_types) {
		PHALCON_INIT_VAR(bind_types);
	}
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_3(result, this_ptr, "query", sql_query, bind_params, bind_types);
	if (Z_TYPE_P(result) == IS_OBJECT) {
		if (Z_TYPE_P(fetch_mode) != IS_NULL) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "setfetchmode", fetch_mode);
		}
	
		PHALCON_INIT_VAR(row);
		PHALCON_CALL_METHOD(row, result, "fetch");
	
		RETURN_CCTOR(row);
	}
	
	PHALCON_INIT_VAR(empty_row);
	array_init(empty_row);
	
	RETURN_CTOR(empty_row);
}

/**
 * Dumps the complete result of a query into an array
 *
 *<code>
 *	//Getting all robots with associative indexes only
 *	$robots = $connection->fetchAll("SELECT * FROM robots", Phalcon\Db::FETCH_ASSOC);
 *	foreach ($robots as $robot) {
 *		print_r($robot);
 *	}
 *
 *  //Getting all robots that contains word "robot" withing the name
 *  $robots = $connection->fetchAll("SELECT * FROM robots WHERE name LIKE :name",
 *		Phalcon\Db::FETCH_ASSOC,
 *		array('name' => '%robot%')
 *  );
 *	foreach($robots as $robot){
 *		print_r($robot);
 *	}
 *</code>
 *
 * @param string $sqlQuery
 * @param int $fetchMode
 * @param array $bindParams
 * @param array $bindTypes
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, fetchAll){

	zval *sql_query, *fetch_mode = NULL, *bind_params = NULL, *bind_types = NULL;
	zval *results, *result, *row = NULL;
	zval *r0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zzz", &sql_query, &fetch_mode, &bind_params, &bind_types) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!fetch_mode) {
		PHALCON_INIT_VAR(fetch_mode);
		ZVAL_LONG(fetch_mode, 2);
	}
	
	if (!bind_params) {
		PHALCON_INIT_VAR(bind_params);
	}
	
	if (!bind_types) {
		PHALCON_INIT_VAR(bind_types);
	}
	
	PHALCON_INIT_VAR(results);
	array_init(results);
	
	PHALCON_INIT_VAR(result);
	PHALCON_CALL_METHOD_PARAMS_3(result, this_ptr, "query", sql_query, bind_params, bind_types);
	if (Z_TYPE_P(result) == IS_OBJECT) {
		if (Z_TYPE_P(fetch_mode) != IS_NULL) {
			PHALCON_CALL_METHOD_PARAMS_1_NORETURN(result, "setfetchmode", fetch_mode);
		}
	
		while (1) {
	
			PHALCON_INIT_NVAR(r0);
			PHALCON_CALL_METHOD(r0, result, "fetch");
			PHALCON_CPY_WRT(row, r0);
			if (zend_is_true(row)) {
			} else {
				break;
			}
	
			phalcon_array_append(&results, row, PH_SEPARATE TSRMLS_CC);
		}
	}
	
	
	RETURN_CTOR(results);
}

/**
 * Inserts data into a table using custom RBDM SQL syntax
 *
 * <code>
 * //Inserting a new robot
 * $success = $connection->insert(
 *     "robots",
 *     array("Astro Boy", 1952),
 *     array("name", "year")
 * );
 *
 * //Next SQL sentence is sent to the database system
 * INSERT INTO `robots` (`name`, `year`) VALUES ("Astro boy", 1952);
 * </code>
 *
 * @param 	string $table
 * @param 	array $values
 * @param 	array $fields
 * @param 	array $dataTypes
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, insert){

	zval *table, *values, *fields = NULL, *data_types = NULL, *exception_message;
	zval *placeholders, *insert_values, *bind_data_types = NULL;
	zval *value = NULL, *position = NULL, *str_value = NULL, *bind_type = NULL;
	zval *escaped_table = NULL, *joined_values, *escaped_fields = NULL;
	zval *field = NULL, *escaped_field = NULL, *joined_fields;
	zval *insert_sql = NULL, *success;
	HashTable *ah0, *ah1;
	HashPosition hp0, hp1;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|zz", &table, &values, &fields, &data_types) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!fields) {
		PHALCON_INIT_VAR(fields);
	}
	
	if (!data_types) {
		PHALCON_INIT_VAR(data_types);
	}
	
	if (Z_TYPE_P(values) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The second parameter for insert isn't an Array");
		return;
	}
	
	/** 
	 * A valid array with more than one element is required
	 */
	if (!phalcon_fast_count_ev(values TSRMLS_CC)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Unable to insert into ", table, " without data");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_db_exception_ce, exception_message);
		return;
	}
	
	PHALCON_INIT_VAR(placeholders);
	array_init(placeholders);
	
	PHALCON_INIT_VAR(insert_values);
	array_init(insert_values);
	if (Z_TYPE_P(data_types) == IS_ARRAY) { 
		PHALCON_INIT_VAR(bind_data_types);
		array_init(bind_data_types);
	} else {
		PHALCON_CPY_WRT(bind_data_types, data_types);
	}
	
	/** 
	 * Objects are casted using __toString, null values are converted to string 'null',
	 * everything else is passed as '?'
	 */
	
	if (!phalcon_is_iterable(values, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_KEY(position, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(value);
	
		if (Z_TYPE_P(value) == IS_OBJECT) {
			PHALCON_INIT_NVAR(str_value);
			PHALCON_CALL_FUNC_PARAMS_1(str_value, "strval", value);
			phalcon_array_append(&placeholders, str_value, PH_SEPARATE TSRMLS_CC);
		} else {
			if (Z_TYPE_P(value) == IS_NULL) {
				phalcon_array_append_string(&placeholders, SL("null"), PH_SEPARATE TSRMLS_CC);
			} else {
				phalcon_array_append_string(&placeholders, SL("?"), PH_SEPARATE TSRMLS_CC);
				phalcon_array_append(&insert_values, value, PH_SEPARATE TSRMLS_CC);
				if (Z_TYPE_P(data_types) == IS_ARRAY) { 
					if (!phalcon_array_isset(data_types, position)) {
						PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Incomplete number of bind types");
						return;
					}
	
					PHALCON_OBS_NVAR(bind_type);
					phalcon_array_fetch(&bind_type, data_types, position, PH_NOISY_CC);
					phalcon_array_append(&bind_data_types, bind_type, PH_SEPARATE TSRMLS_CC);
				}
			}
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_INIT_VAR(escaped_table);
		PHALCON_CALL_METHOD_PARAMS_1(escaped_table, this_ptr, "escapeidentifier", table);
	} else {
		PHALCON_CPY_WRT(escaped_table, table);
	}
	
	/** 
	 * Build the final SQL INSERT statement
	 */
	PHALCON_INIT_VAR(joined_values);
	phalcon_fast_join_str(joined_values, SL(", "), placeholders TSRMLS_CC);
	if (Z_TYPE_P(fields) == IS_ARRAY) { 
		if (PHALCON_GLOBAL(db).escape_identifiers) {
	
			PHALCON_INIT_VAR(escaped_fields);
			array_init(escaped_fields);
	
			if (!phalcon_is_iterable(fields, &ah1, &hp1, 0, 0 TSRMLS_CC)) {
				return;
			}
	
			while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {
	
				PHALCON_GET_FOREACH_VALUE(field);
	
				PHALCON_INIT_NVAR(escaped_field);
				PHALCON_CALL_METHOD_PARAMS_1(escaped_field, this_ptr, "escapeidentifier", field);
				phalcon_array_append(&escaped_fields, escaped_field, PH_SEPARATE TSRMLS_CC);
	
				zend_hash_move_forward_ex(ah1, &hp1);
			}
	
		} else {
			PHALCON_CPY_WRT(escaped_fields, fields);
		}
	
		PHALCON_INIT_VAR(joined_fields);
		phalcon_fast_join_str(joined_fields, SL(", "), escaped_fields TSRMLS_CC);
	
		PHALCON_INIT_VAR(insert_sql);
		PHALCON_CONCAT_SVSVSVS(insert_sql, "INSERT INTO ", escaped_table, " (", joined_fields, ") VALUES (", joined_values, ")");
	} else {
		PHALCON_INIT_NVAR(insert_sql);
		PHALCON_CONCAT_SVSVS(insert_sql, "INSERT INTO ", escaped_table, " VALUES (", joined_values, ")");
	}
	
	/** 
	 * Perform the execution via PDO::execute
	 */
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_3(success, this_ptr, "execute", insert_sql, insert_values, bind_data_types);
	
	RETURN_CCTOR(success);
}

/**
 * Updates data on a table using custom RBDM SQL syntax
 *
 * <code>
 * //Updating existing robot
 * $success = $connection->update(
 *     "robots",
 *     array("name")
 *     array("New Astro Boy"),
 *     "id = 101"
 * );
 *
 * //Next SQL sentence is sent to the database system
 * UPDATE `robots` SET `name` = "Astro boy" WHERE id = 101
 * </code>
 *
 * @param 	string $table
 * @param 	array $fields
 * @param 	array $values
 * @param 	string $whereCondition
 * @param 	array $dataTypes
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, update){

	zval *table, *fields, *values, *where_condition = NULL;
	zval *data_types = NULL, *placeholders, *update_values;
	zval *bind_data_types = NULL, *value = NULL, *position = NULL, *field = NULL;
	zval *escaped_field = NULL, *set_clause_part = NULL, *bind_type = NULL;
	zval *escaped_table = NULL, *set_clause, *update_sql = NULL;
	zval *conditions, *where_bind, *where_types;
	zval *success;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz|zz", &table, &fields, &values, &where_condition, &data_types) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!where_condition) {
		PHALCON_INIT_VAR(where_condition);
	}
	
	if (!data_types) {
		PHALCON_INIT_VAR(data_types);
	}
	
	PHALCON_INIT_VAR(placeholders);
	array_init(placeholders);
	
	PHALCON_INIT_VAR(update_values);
	array_init(update_values);
	if (Z_TYPE_P(data_types) == IS_ARRAY) { 
		PHALCON_INIT_VAR(bind_data_types);
		array_init(bind_data_types);
	} else {
		PHALCON_CPY_WRT(bind_data_types, data_types);
	}
	
	/** 
	 * Objects are casted using __toString, null values are converted to string 'null',
	 * everything else is passed as '?'
	 */
	
	if (!phalcon_is_iterable(values, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_KEY(position, ah0, hp0);
		PHALCON_GET_FOREACH_VALUE(value);
	
		if (phalcon_array_isset(fields, position)) {
	
			PHALCON_OBS_NVAR(field);
			phalcon_array_fetch(&field, fields, position, PH_NOISY_CC);
			if (PHALCON_GLOBAL(db).escape_identifiers) {
				PHALCON_INIT_NVAR(escaped_field);
				PHALCON_CALL_METHOD_PARAMS_1(escaped_field, this_ptr, "escapeidentifier", field);
			} else {
				PHALCON_CPY_WRT(escaped_field, field);
			}
	
			if (Z_TYPE_P(value) == IS_OBJECT) {
				PHALCON_INIT_NVAR(set_clause_part);
				PHALCON_CONCAT_VSV(set_clause_part, escaped_field, " = ", value);
				phalcon_array_append(&placeholders, set_clause_part, PH_SEPARATE TSRMLS_CC);
			} else {
				if (Z_TYPE_P(value) == IS_NULL) {
					PHALCON_INIT_NVAR(set_clause_part);
					PHALCON_CONCAT_VS(set_clause_part, escaped_field, " = null");
				} else {
					PHALCON_INIT_NVAR(set_clause_part);
					PHALCON_CONCAT_VS(set_clause_part, escaped_field, " = ?");
					phalcon_array_append(&update_values, value, PH_SEPARATE TSRMLS_CC);
					if (Z_TYPE_P(data_types) == IS_ARRAY) { 
						if (!phalcon_array_isset(data_types, position)) {
							PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Incomplete number of bind types");
							return;
						}
	
						PHALCON_OBS_NVAR(bind_type);
						phalcon_array_fetch(&bind_type, data_types, position, PH_NOISY_CC);
						phalcon_array_append(&bind_data_types, bind_type, PH_SEPARATE TSRMLS_CC);
					}
				}
				phalcon_array_append(&placeholders, set_clause_part, PH_SEPARATE TSRMLS_CC);
			}
		} else {
			PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The number of values in the update is not the same as fields");
			return;
		}
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_INIT_VAR(escaped_table);
		PHALCON_CALL_METHOD_PARAMS_1(escaped_table, this_ptr, "escapeidentifier", table);
	} else {
		PHALCON_CPY_WRT(escaped_table, table);
	}
	
	PHALCON_INIT_VAR(set_clause);
	phalcon_fast_join_str(set_clause, SL(", "), placeholders TSRMLS_CC);
	if (Z_TYPE_P(where_condition) != IS_NULL) {
	
		PHALCON_INIT_VAR(update_sql);
		PHALCON_CONCAT_SVSVS(update_sql, "UPDATE ", escaped_table, " SET ", set_clause, " WHERE ");
	
		/** 
		 * String conditions are simply appended to the SQL
		 */
		if (Z_TYPE_P(where_condition) == IS_STRING) {
			phalcon_concat_self(&update_sql, where_condition TSRMLS_CC);
		} else {
			/** 
			 * Array conditions may have bound params and bound types
			 */
			if (Z_TYPE_P(where_condition) == IS_ARRAY) { 
	
				/** 
				 * If an index 'conditions' is present it contains string where conditions that are
				 * appended to the UPDATE sql
				 */
				if (phalcon_array_isset_string(where_condition, SS("conditions"))) {
					PHALCON_OBS_VAR(conditions);
					phalcon_array_fetch_string(&conditions, where_condition, SL("conditions"), PH_NOISY_CC);
					phalcon_concat_self(&update_sql, conditions TSRMLS_CC);
				}
	
				/** 
				 * Bound parameters are arbitrary values that are passed by separate
				 */
				if (phalcon_array_isset_string(where_condition, SS("bind"))) {
					PHALCON_OBS_VAR(where_bind);
					phalcon_array_fetch_string(&where_bind, where_condition, SL("bind"), PH_NOISY_CC);
					phalcon_merge_append(update_values, where_bind TSRMLS_CC);
				}
	
				/** 
				 * Bind types is how the bound parameters must be casted before be sent to the
				 * database system
				 */
				if (phalcon_array_isset_string(where_condition, SS("bindTypes"))) {
					PHALCON_OBS_VAR(where_types);
					phalcon_array_fetch_string(&where_types, where_condition, SL("bindTypes"), PH_NOISY_CC);
					phalcon_merge_append(bind_data_types, where_types TSRMLS_CC);
				}
			} else {
				PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "Invalid WHERE clause conditions");
				return;
			}
		}
	} else {
		PHALCON_INIT_NVAR(update_sql);
		PHALCON_CONCAT_SVSV(update_sql, "UPDATE ", escaped_table, " SET ", set_clause);
	}
	
	/** 
	 * Perform the update via PDO::execute
	 */
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_3(success, this_ptr, "execute", update_sql, update_values, bind_data_types);
	
	RETURN_CCTOR(success);
}

/**
 * Deletes data from a table using custom RBDM SQL syntax
 *
 * <code>
 * //Deleting existing robot
 * $success = $connection->delete(
 *     "robots",
 *     "id = 101"
 * );
 *
 * //Next SQL sentence is generated
 * DELETE FROM `robots` WHERE `id` = 101
 * </code>
 *
 * @param  string $table
 * @param  string $whereCondition
 * @param  array $placeholders
 * @param  array $dataTypes
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, delete){

	zval *table, *where_condition = NULL, *placeholders = NULL;
	zval *data_types = NULL, *escaped_table = NULL, *sql = NULL, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|zzz", &table, &where_condition, &placeholders, &data_types) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!where_condition) {
		PHALCON_INIT_VAR(where_condition);
	}
	
	if (!placeholders) {
		PHALCON_INIT_VAR(placeholders);
	}
	
	if (!data_types) {
		PHALCON_INIT_VAR(data_types);
	}
	
	if (PHALCON_GLOBAL(db).escape_identifiers) {
		PHALCON_INIT_VAR(escaped_table);
		PHALCON_CALL_METHOD_PARAMS_1(escaped_table, this_ptr, "escapeidentifier", table);
	} else {
		PHALCON_CPY_WRT(escaped_table, table);
	}
	if (Z_TYPE_P(where_condition) != IS_NULL) {
		PHALCON_INIT_VAR(sql);
		PHALCON_CONCAT_SVSV(sql, "DELETE FROM ", escaped_table, " WHERE ", where_condition);
	} else {
		PHALCON_INIT_NVAR(sql);
		PHALCON_CONCAT_SV(sql, "DELETE FROM ", escaped_table);
	}
	
	/** 
	 * Perform the update via PDO::execute
	 */
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_3(success, this_ptr, "execute", sql, placeholders, data_types);
	
	RETURN_CCTOR(success);
}

/**
 * Gets a list of columns
 *
 * @param array $columnList
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getColumnList){

	zval *column_list, *dialect, *transformed_list;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column_list) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(transformed_list);
	PHALCON_CALL_METHOD_PARAMS_1(transformed_list, dialect, "getcolumnlist", column_list);
	RETURN_CCTOR(transformed_list);
}

/**
 * Appends a LIMIT clause to $sqlQuery argument
 *
 * <code>
 * 	echo $connection->limit("SELECT * FROM robots", 5);
 * </code>
 *
 * @param  	string $sqlQuery
 * @param 	int $number
 * @return 	string
 */
PHP_METHOD(Phalcon_Db_Adapter, limit){

	zval *sql_query, *number, *dialect, *sql;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &sql_query, &number) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "limit", sql_query, number);
	RETURN_CCTOR(sql);
}

/**
 * Generates SQL checking for the existence of a schema.table
 *
 * <code>
 * 	var_dump($connection->tableExists("blog", "posts"));
 * </code>
 *
 * @param string $tableName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, tableExists){

	zval *table_name, *schema_name = NULL, *dialect, *sql;
	zval *fetch_num, *num, *first;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &table_name, &schema_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}
	
	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "tableexists", table_name, schema_name);
	
	PHALCON_INIT_VAR(fetch_num);
	phalcon_get_class_constant(fetch_num, phalcon_db_ce, SS("FETCH_NUM") TSRMLS_CC);
	
	PHALCON_INIT_VAR(num);
	PHALCON_CALL_METHOD_PARAMS_2(num, this_ptr, "fetchone", sql, fetch_num);
	
	PHALCON_OBS_VAR(first);
	phalcon_array_fetch_long(&first, num, 0, PH_NOISY_CC);
	RETURN_CCTOR(first);
}

/**
 * Generates SQL checking for the existence of a schema.view
 *
 *<code>
 * var_dump($connection->viewExists("active_users", "posts"));
 *</code>
 *
 * @param string $viewName
 * @param string $schemaName
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, viewExists){

	zval *view_name, *schema_name = NULL, *exists;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &view_name, &schema_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}
	
	PHALCON_INIT_VAR(exists);
	PHALCON_CALL_METHOD_PARAMS_2(exists, this_ptr, "tableexists", view_name, schema_name);
	RETURN_CCTOR(exists);
}

/**
 * Returns a SQL modified with a FOR UPDATE clause
 *
 * @param string $sqlQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, forUpdate){

	zval *sql_query, *dialect, *sql;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_query) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_1(sql, dialect, "forupdate", sql_query);
	RETURN_CCTOR(sql);
}

/**
 * Returns a SQL modified with a LOCK IN SHARE MODE clause
 *
 * @param string $sqlQuery
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, sharedLock){

	zval *sql_query, *dialect, *sql;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &sql_query) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_1(sql, dialect, "sharedlock", sql_query);
	RETURN_CCTOR(sql);
}

/**
 * Creates a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param array $definition
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, createTable){

	zval *table_name, *schema_name, *definition;
	zval *exception_message, *columns, *dialect;
	zval *sql, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &definition) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (Z_TYPE_P(definition) != IS_ARRAY) { 
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Invalid definition to create the table '", table_name, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_db_exception_ce, exception_message);
		return;
	}
	if (!phalcon_array_isset_string(definition, SS("columns"))) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The table must contain at least one column");
		return;
	}
	
	PHALCON_OBS_VAR(columns);
	phalcon_array_fetch_string(&columns, definition, SL("columns"), PH_NOISY_CC);
	if (!phalcon_fast_count_ev(columns TSRMLS_CC)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_db_exception_ce, "The table must contain at least one column");
		return;
	}
	
	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, dialect, "createtable", table_name, schema_name, definition);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, this_ptr, "execute", sql);
	
	RETURN_CCTOR(success);
}

/**
 * Drops a table from a schema/database
 *
 * @param string $tableName
 * @param   string $schemaName
 * @param boolean $ifExists
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, dropTable){

	zval *table_name, *schema_name, *if_exists = NULL, *dialect;
	zval *sql, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &table_name, &schema_name, &if_exists) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!if_exists) {
		PHALCON_INIT_VAR(if_exists);
		ZVAL_BOOL(if_exists, 1);
	}
	
	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, dialect, "droptable", table_name, schema_name, if_exists);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, this_ptr, "execute", sql);
	RETURN_CCTOR(success);
}

/**
 * Adds a column to a table
 *
 * @param string $tableName
 * @param 	string $schemaName
 * @param Phalcon\Db\ColumnInterface $column
 * @return boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, addColumn){

	zval *table_name, *schema_name, *column, *dialect;
	zval *sql, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, dialect, "addcolumn", table_name, schema_name, column);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, this_ptr, "execute", sql);
	RETURN_CCTOR(success);
}

/**
 * Modifies a table column based on a definition
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\ColumnInterface $column
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, modifyColumn){

	zval *table_name, *schema_name, *column, *dialect;
	zval *sql, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, dialect, "modifycolumn", table_name, schema_name, column);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, this_ptr, "execute", sql);
	RETURN_CCTOR(success);
}

/**
 * Drops a column from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $columnName
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, dropColumn){

	zval *table_name, *schema_name, *column_name;
	zval *dialect, *sql, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &column_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, dialect, "dropcolumn", table_name, schema_name, column_name);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, this_ptr, "execute", sql);
	RETURN_CCTOR(success);
}

/**
 * Adds an index to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\IndexInterface $index
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, addIndex){

	zval *table_name, *schema_name, *index, *dialect;
	zval *sql, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, dialect, "addindex", table_name, schema_name, index);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, this_ptr, "execute", sql);
	RETURN_CCTOR(success);
}

/**
 * Drop an index from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $indexName
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, dropIndex){

	zval *table_name, *schema_name, *index_name;
	zval *dialect, *sql, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, dialect, "dropindex", table_name, schema_name, index_name);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, this_ptr, "execute", sql);
	RETURN_CCTOR(success);
}

/**
 * Adds a primary key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\IndexInterface $index
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, addPrimaryKey){

	zval *table_name, *schema_name, *index, *sql, *success;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &index) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(t0);
	phalcon_read_property_this(&t0, this_ptr, SL("_dialect"), PH_NOISY_CC);
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, t0, "addprimarykey", table_name, schema_name, index);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, this_ptr, "execute", sql);
	RETURN_CCTOR(success);
}

/**
 * Drops a table's primary key
 *
 * @param string $tableName
 * @param string $schemaName
 * @return 	boolean
 */
PHP_METHOD(Phalcon_Db_Adapter, dropPrimaryKey){

	zval *table_name, *schema_name, *dialect, *sql;
	zval *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &table_name, &schema_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_2(sql, dialect, "dropprimarykey", table_name, schema_name);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, this_ptr, "execute", sql);
	RETURN_CCTOR(success);
}

/**
 * Adds a foreign key to a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param Phalcon\Db\ReferenceInterface $reference
 * @return boolean true
 */
PHP_METHOD(Phalcon_Db_Adapter, addForeignKey){

	zval *table_name, *schema_name, *reference, *dialect;
	zval *sql, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &reference) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, dialect, "addforeignkey", table_name, schema_name, reference);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, this_ptr, "execute", sql);
	RETURN_CCTOR(success);
}

/**
 * Drops a foreign key from a table
 *
 * @param string $tableName
 * @param string $schemaName
 * @param string $referenceName
 * @return boolean true
 */
PHP_METHOD(Phalcon_Db_Adapter, dropForeignKey){

	zval *table_name, *schema_name, *reference_name;
	zval *dialect, *sql, *success;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zzz", &table_name, &schema_name, &reference_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_3(sql, dialect, "dropforeignkey", table_name, schema_name, reference_name);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_METHOD_PARAMS_1(success, this_ptr, "execute", sql);
	RETURN_CCTOR(success);
}

/**
 * Returns the SQL column definition from a column
 *
 * @param Phalcon\Db\ColumnInterface $column
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getColumnDefinition){

	zval *column, *dialect, *definition;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &column) == FAILURE) {
		RETURN_MM_NULL();
	}

	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(definition);
	PHALCON_CALL_METHOD_PARAMS_1(definition, dialect, "getcolumndefinition", column);
	RETURN_CCTOR(definition);
}

/**
 * List all tables on a database
 *
 *<code>
 * 	print_r($connection->listTables("blog");
 *</code>
 *
 * @param string $schemaName
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, listTables){

	zval *schema_name = NULL, *dialect, *sql, *fetch_num, *tables;
	zval *all_tables, *table = NULL, *table_name = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "|z", &schema_name) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!schema_name) {
		PHALCON_INIT_VAR(schema_name);
	}
	
	PHALCON_OBS_VAR(dialect);
	phalcon_read_property_this(&dialect, this_ptr, SL("_dialect"), PH_NOISY_CC);
	
	/** 
	 * Get the SQL to list the tables
	 */
	PHALCON_INIT_VAR(sql);
	PHALCON_CALL_METHOD_PARAMS_1(sql, dialect, "listtables", schema_name);
	
	/** 
	 * Use fetch Num
	 */
	PHALCON_INIT_VAR(fetch_num);
	ZVAL_LONG(fetch_num, 3);
	
	/** 
	 * Execute the SQL returning the tables
	 */
	PHALCON_INIT_VAR(tables);
	PHALCON_CALL_METHOD_PARAMS_2(tables, this_ptr, "fetchall", sql, fetch_num);
	
	PHALCON_INIT_VAR(all_tables);
	array_init(all_tables);
	
	if (!phalcon_is_iterable(tables, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
		return;
	}
	
	while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
		PHALCON_GET_FOREACH_VALUE(table);
	
		PHALCON_OBS_NVAR(table_name);
		phalcon_array_fetch_long(&table_name, table, 0, PH_NOISY_CC);
		phalcon_array_append(&all_tables, table_name, PH_SEPARATE TSRMLS_CC);
	
		zend_hash_move_forward_ex(ah0, &hp0);
	}
	
	
	RETURN_CTOR(all_tables);
}

/**
 * Return descriptor used to connect to the active database
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, getDescriptor){


	RETURN_MEMBER(this_ptr, "_descriptor");
}

/**
 * Gets the active connection unique identifier
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getConnectionId){


	RETURN_MEMBER(this_ptr, "_connectionId");
}

/**
 * Active SQL statement in the object
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getSQLStatement){


	RETURN_MEMBER(this_ptr, "_sqlStatement");
}

/**
 * Active SQL statement in the object without replace bound paramters
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getRealSQLStatement){


	RETURN_MEMBER(this_ptr, "_sqlStatement");
}

/**
 * Active SQL statement in the object
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, getSQLVariables){


	RETURN_MEMBER(this_ptr, "_sqlVariables");
}

/**
 * Active SQL statement in the object
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Adapter, getSQLBindTypes){


	RETURN_MEMBER(this_ptr, "_sqlBindTypes");
}

/**
 * Returns type of database system the adapter is used for
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getType){


	RETURN_MEMBER(this_ptr, "_type");
}

/**
 * Returns the name of the dialect used
 *
 * @return string
 */
PHP_METHOD(Phalcon_Db_Adapter, getDialectType){


	RETURN_MEMBER(this_ptr, "_dialectType");
}

/**
 * Returns internal dialect instance
 *
 * @return Phalcon\Db\DialectInterface
 */
PHP_METHOD(Phalcon_Db_Adapter, getDialect){


	RETURN_MEMBER(this_ptr, "_dialect");
}

