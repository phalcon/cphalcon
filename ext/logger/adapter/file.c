
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

#include "kernel/array.h"
#include "kernel/string.h"
#include "kernel/exception.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/object.h"

/**
 * Phalcon\Logger\Adapter\File
 *
 * Adapter to store logs in plain text files
 *
 *<code>
 *	$logger = new \Phalcon\Logger\Adapter\File("app/logs/test.log");
 *	$logger->log("This is a message");
 *	$logger->log("This is an error", \Phalcon\Logger::ERROR);
 *	$logger->error("This is another error");
 *	$logger->close();
 *</code>
 */


/**
 * Phalcon\Logger\Adapter\File initializer
 */
PHALCON_INIT_CLASS(Phalcon_Logger_Adapter_File){

	PHALCON_REGISTER_CLASS_EX(Phalcon\\Logger\\Adapter, File, logger_adapter_file, "phalcon\\logger\\adapter", phalcon_logger_adapter_file_method_entry, 0);

	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_fileHandler"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_logger_adapter_file_ce, SL("_transaction"), 0, ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_path"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_options"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_logger_adapter_file_ce, SL("_quenue"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_logger_adapter_file_ce TSRMLS_CC, 1, phalcon_logger_adapterinterface_ce);

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

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &options) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
	}
	
	if (phalcon_array_isset_string(options, SS("mode"))) {
		PHALCON_OBS_VAR(mode);
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
 * Sends/Writes messages to the file log
 *
 * @param string $message
 * @param int $type
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, log){

	zval *message, *type = NULL, *file_handler, *transaction;
	zval *timestamp, *quenue_item, *applied_format;
	zval *eol, *applied_eol;

	PHALCON_MM_GROW();

	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &message, &type) == FAILURE) {
		RETURN_MM_NULL();
	}

	if (!type) {
		PHALCON_INIT_VAR(type);
		ZVAL_LONG(type, 7);
	}
	
	PHALCON_OBS_VAR(file_handler);
	phalcon_read_property(&file_handler, this_ptr, SL("_fileHandler"), PH_NOISY_CC);
	if (!zend_is_true(file_handler)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "Cannot send message to the log because it is invalid");
		return;
	}
	
	PHALCON_OBS_VAR(transaction);
	phalcon_read_property(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (zend_is_true(transaction)) {
		PHALCON_INIT_VAR(timestamp);
		ZVAL_LONG(timestamp, (long) time(NULL));
	
		PHALCON_INIT_VAR(quenue_item);
		object_init_ex(quenue_item, phalcon_logger_item_ce);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(quenue_item, "__construct", message, type, timestamp);
	
		phalcon_update_property_array_append(this_ptr, SL("_quenue"), quenue_item TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(applied_format);
		PHALCON_CALL_METHOD_PARAMS_2(applied_format, this_ptr, "_applyformat", message, type);
	
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

	zval *transaction, *quenue, *eol, *file_handler;
	zval *message = NULL, *message_str = NULL, *type = NULL, *time = NULL, *applied_format = NULL;
	zval *applied_eol = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(transaction);
	phalcon_read_property(&transaction, this_ptr, SL("_transaction"), PH_NOISY_CC);
	if (!zend_is_true(transaction)) {
		PHALCON_THROW_EXCEPTION_STR(phalcon_logger_exception_ce, "There is no active transaction");
		return;
	}
	
	phalcon_update_property_bool(this_ptr, SL("_transaction"), 0 TSRMLS_CC);
	
	/** 
	 * Check if the quenue has something to log
	 */
	PHALCON_OBS_VAR(quenue);
	phalcon_read_property(&quenue, this_ptr, SL("_quenue"), PH_NOISY_CC);
	if (Z_TYPE_P(quenue) == IS_ARRAY) { 
	
		PHALCON_INIT_VAR(eol);
		zend_get_constant(SL("PHP_EOL"), eol TSRMLS_CC);
	
		PHALCON_OBS_VAR(file_handler);
		phalcon_read_property(&file_handler, this_ptr, SL("_fileHandler"), PH_NOISY_CC);
	
		if (!phalcon_is_iterable(quenue, &ah0, &hp0, 0, 0 TSRMLS_CC)) {
			return;
		}
	
		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {
	
			PHALCON_GET_FOREACH_VALUE(message);
	
			PHALCON_INIT_NVAR(message_str);
			PHALCON_CALL_METHOD(message_str, message, "getmessage");
	
			PHALCON_INIT_NVAR(type);
			PHALCON_CALL_METHOD(type, message, "gettype");
	
			PHALCON_INIT_NVAR(time);
			PHALCON_CALL_METHOD(time, message, "gettime");
	
			PHALCON_INIT_NVAR(applied_format);
			PHALCON_CALL_METHOD_PARAMS_3(applied_format, this_ptr, "_applyformat", message_str, type, time);
	
			PHALCON_INIT_NVAR(applied_eol);
			PHALCON_CONCAT_VV(applied_eol, applied_format, eol);
			PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fwrite", file_handler, applied_eol);
	
			zend_hash_move_forward_ex(ah0, &hp0);
		}
	
	}
	
	PHALCON_MM_RESTORE();
}

/**
  * Rollbacks the internal transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, rollback){

	zval *transaction, *quenue;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(transaction);
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

	PHALCON_OBS_VAR(file_handler);
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

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(path);
	phalcon_read_property(&path, this_ptr, SL("_path"), PH_NOISY_CC);
	
	PHALCON_OBS_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	if (phalcon_array_isset_string(options, SS("mode"))) {
		PHALCON_OBS_VAR(mode);
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

