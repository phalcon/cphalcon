
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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

#include "kernel/object.h"
#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/operators.h"

/**
 * Phalcon\Logger\Adapter\File
 *
 * Adapter to store logs in plain text files
 *
 *<code>
 *$logger = new Phalcon\Logger\Adapter\File("app/logs/test.log");
 *$logger->log("This is a message");
 *$logger->log("This is an error", Phalcon\Logger::ERROR);
 *$logger->error("This is another error");
 *$logger->close();
 *</code>
 */


/**
 * Phalcon\Logger\Adapter\File initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Adapter_File){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, File, logger_adapter_file, "phalcon\\logger", phalcon_logger_adapter_file_method_entry, 0);

	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_fileHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_logger_adapter_file_ce, SL("_transaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_path"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_quenue"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_adapter_file_ce, SL("_dateFormat"), "D, d M y H:i:s O", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_logger_adapter_file_ce, SL("_format"), "[%date%][%type%] %message%", ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;
}

/**
 * Phalcon\Logger\Adapter\File constructor
 *
 * @param string $name
 * @param array $options
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, __construct){

	zval *name, *options = NULL, *mode = NULL, *handler, *exception_message;
	int eval_int;

	PHALCON_MM_GROW();

	phalcon_update_property_empty_array(phalcon_logger_adapter_file_ce, this_ptr, SL("_quenue") TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_NVAR(options);
		array_init(options);
	}
	
	eval_int = phalcon_array_isset_string(options, SS("mode"));
	if (eval_int) {
		PHALCON_INIT_VAR(mode);
		phalcon_array_fetch_string(&mode, options, SL("mode"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(mode);
		ZVAL_STRING(mode, "ab", 1);
	}
	if (phalcon_memnstr_str(mode, SL("r") TSRMLS_CC)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "Logger must be opened in append or write mode");
		return;
	}
	
	PHALCON_INIT_VAR(handler);
	PHALCON_CALL_FUNC_PARAMS_2(handler, "fopen", name, mode);
	if (!zend_is_true(handler)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Can't open log file at '", name, "'");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_logger_exception_ce, exception_message);
		return;
	}
	
	phalcon_update_property_zval(this_ptr, SL("_path"), name TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_options"), options TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, SL("_fileHandler"), handler TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Set the log format
 *
 * @param string $format
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, setFormat){

	zval *format;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &format) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_format"), format TSRMLS_CC);
	
}

/**
 * Returns the log format
 *
 * @return format
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getFormat){


	RETURN_MEMBER(this_ptr, "_format");
}

/**
 * Returns the string meaning of a logger constant
 *
 * @param  integer $type
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getTypeString){

	zval *type, *type_str = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &type) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (phalcon_compare_strict_long(type, 7 TSRMLS_CC)) {
		PHALCON_INIT_VAR(type_str);
		ZVAL_STRING(type_str, "DEBUG", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 3 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "ERROR", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 4 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "WARNING", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 1 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "CRITICAL", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 8 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "CUSTOM", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 2 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "ALERT", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 5 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "NOTICE", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 6 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "INFO", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 0 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "EMERGENCE", 1);
		goto ph_end_0;
	}
	
	if (phalcon_compare_strict_long(type, 9 TSRMLS_CC)) {
		PHALCON_INIT_NVAR(type_str);
		ZVAL_STRING(type_str, "SPECIAL", 1);
		goto ph_end_0;
	}
	
	PHALCON_INIT_NVAR(type_str);
	ZVAL_STRING(type_str, "CUSTOM", 1);
	
	ph_end_0:
	
	RETURN_CTOR(type_str);
}

/**
 * Applies the internal format to the message
 *
 * @param  string $message
 * @param  int $type
 * @param  int $time
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, _applyFormat){

	zval *message, *type, *time = NULL, *format = NULL, *date_format;
	zval *date, *date_wildcard, *new_format = NULL, *type_string;
	zval *type_wildcard, *message_wildcard;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &message, &type, &time) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!time) {
		PHALCON_INIT_NVAR(time);
		ZVAL_LONG(time, 0);
	} else {
		PHALCON_SEPARATE_PARAM(time);
	}
	
	if (!zend_is_true(time)) {
		PHALCON_INIT_NVAR(time);
		PHALCON_CALL_FUNC(time, "time");
	}
	
	PHALCON_INIT_VAR(format);
	phalcon_read_property(&format, this_ptr, SL("_format"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(date_format);
	phalcon_read_property(&date_format, this_ptr, SL("_dateFormat"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(date);
	PHALCON_CALL_FUNC_PARAMS_2(date, "date", date_format, time);
	
	PHALCON_INIT_VAR(date_wildcard);
	ZVAL_STRING(date_wildcard, "%date%", 1);
	
	PHALCON_INIT_VAR(new_format);
	phalcon_fast_str_replace(new_format, date_wildcard, date, format TSRMLS_CC);
	
	PHALCON_INIT_VAR(type_string);
	PHALCON_CALL_METHOD_PARAMS_1(type_string, this_ptr, "gettypestring", type, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(type_wildcard);
	ZVAL_STRING(type_wildcard, "%type%", 1);
	
	PHALCON_INIT_NVAR(format);
	phalcon_fast_str_replace(format, type_wildcard, type_string, new_format TSRMLS_CC);
	
	PHALCON_INIT_VAR(message_wildcard);
	ZVAL_STRING(message_wildcard, "%message%", 1);
	
	PHALCON_INIT_NVAR(new_format);
	phalcon_fast_str_replace(new_format, message_wildcard, message, format TSRMLS_CC);
	
	RETURN_CTOR(new_format);
}

/**
 * Sets the internal date format
 *
 * @param string $date
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, setDateFormat){

	zval *date;

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &date) == FAILURE) {
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dateFormat"), date TSRMLS_CC);
	
}

/**
 * Returns the internal date format
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getDateFormat){


	RETURN_MEMBER(this_ptr, "_dateFormat");
}

/**
 * Sends/Writes messages to the file log
 *
 * @param string $message
 * @param int $type
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, log){

	zval *message, *type = NULL, *file_handler, *transaction;
	zval *time, *quenue_item, *applied_format, *eol;
	zval *applied_eol;
	zval *t0 = NULL;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &message, &type) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!type) {
		PHALCON_INIT_NVAR(type);
		ZVAL_LONG(type, 7);
	}
	
	PHALCON_INIT_VAR(file_handler);
	phalcon_read_property(&file_handler, this_ptr, SL("_fileHandler"), PH_NOISY_CC);
	if (!zend_is_true(file_handler)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "Cannot send message to the log because it is invalid");
		return;
	}
	
	PHALCON_INIT_VAR(transaction);
	phalcon_read_property(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (zend_is_true(transaction)) {
		PHALCON_INIT_VAR(time);
		PHALCON_CALL_FUNC(time, "time");
	
		PHALCON_INIT_VAR(quenue_item);
		object_init_ex(quenue_item, phalcon_logger_item_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(quenue_item, "__construct", message, type, time, PH_CHECK);
	
		PHALCON_INIT_VAR(t0);
		phalcon_read_property(&t0, this_ptr, SL("_quenue"), PH_NOISY_CC);
		phalcon_array_append(&t0, quenue_item, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_quenue"), t0 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(applied_format);
		PHALCON_CALL_METHOD_PARAMS_2(applied_format, this_ptr, "_applyformat", message, type, PH_NO_CHECK);
	
		PHALCON_INIT_VAR(eol);
		zend_get_constant(SL("PHP_EOL"), eol TSRMLS_CC);
	
		PHALCON_INIT_VAR(applied_eol);
		PHALCON_CONCAT_VV(applied_eol, applied_format, eol);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fwrite", file_handler, applied_eol);
	}
	
	PHALCON_MM_RESTORE();
}

/**
  * Starts a transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, begin){


	phalcon_update_property_bool(this_ptr, SL("_transaction"), 1 TSRMLS_CC);
	
}

/**
  * Commits the internal transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, commit){

	zval *transaction, *file_handler, *quenue, *eol;
	zval *message = NULL, *message_str = NULL, *type = NULL, *time = NULL, *applied_format = NULL;
	zval *applied_eol = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(transaction);
	phalcon_read_property(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (!zend_is_true(transaction)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "There is no active transaction");
		return;
	}
	
	phalcon_update_property_bool(this_ptr, SL("_transaction"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(file_handler);
	phalcon_read_property(&file_handler, this_ptr, SL("_fileHandler"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(quenue);
	phalcon_read_property(&quenue, this_ptr, SL("_quenue"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(eol);
	zend_get_constant(SL("PHP_EOL"), eol TSRMLS_CC);
	
	if (!phalcon_valid_foreach(quenue TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(quenue);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	
	ph_cycle_start_0:
	
		if (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS) {
			goto ph_cycle_end_0;
		}
	
		PHALCON_GET_FOREACH_VALUE(message);
	
		PHALCON_INIT_NVAR(message_str);
		PHALCON_CALL_METHOD(message_str, message, "getmessage", PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(type);
		PHALCON_CALL_METHOD(type, message, "gettype", PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(time);
		PHALCON_CALL_METHOD(time, message, "gettime", PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(applied_format);
		PHALCON_CALL_METHOD_PARAMS_3(applied_format, this_ptr, "_applyformat", message_str, type, time, PH_NO_CHECK);
	
		PHALCON_INIT_NVAR(applied_eol);
		PHALCON_CONCAT_VV(applied_eol, applied_format, eol);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fwrite", file_handler, applied_eol);
	
		zend_hash_move_forward_ex(ah0, &hp0);
		goto ph_cycle_start_0;
	
	ph_cycle_end_0:
	if(0){}
	
	
	PHALCON_MM_RESTORE();
}

/**
  * Rollbacks the internal transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, rollback){

	zval *transaction, *quenue;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(transaction);
	phalcon_read_property(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (!zend_is_true(transaction)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "There is no active transaction");
		return;
	}
	
	phalcon_update_property_bool(this_ptr, SL("_transaction"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(quenue);
	array_init(quenue);
	phalcon_update_property_zval(this_ptr, SL("_quenue"), quenue TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
  * Closes the logger
  *
  * @return boolean
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, close){

	zval *file_handler, *success;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(file_handler);
	phalcon_read_property(&file_handler, this_ptr, SL("_fileHandler"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(success);
	PHALCON_CALL_FUNC_PARAMS_1(success, "fclose", file_handler);
	
	RETURN_CCTOR(success);
}

/**
 * Opens the internal file handler after unserialization
 *
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, __wakeup){

	zval *path, *options, *mode = NULL, *file_handler;
	int eval_int;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(path);
	phalcon_read_property(&path, this_ptr, SL("_path"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(options, SS("mode"));
	if (eval_int) {
		PHALCON_INIT_VAR(mode);
		phalcon_array_fetch_string(&mode, options, SL("mode"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_NVAR(mode);
		ZVAL_STRING(mode, "ab", 1);
	}
	
	PHALCON_INIT_VAR(file_handler);
	PHALCON_CALL_FUNC_PARAMS_2(file_handler, "fopen", path, mode);
	phalcon_update_property_zval(this_ptr, SL("_fileHandler"), file_handler TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

