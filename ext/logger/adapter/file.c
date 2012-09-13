
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

#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/concat.h"
#include "kernel/exception.h"
#include "kernel/object.h"
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
 * Phalcon\Logger\Adapter\File constructor
 *
 * @param string $name
 * @param array $options
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, __construct){

	zval *name = NULL, *options = NULL, *mode = NULL, *handler = NULL, *exception_message = NULL;
	zval *exception = NULL;
	zval *a0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	PHALCON_ALLOC_ZVAL_MM(a0);
	array_init(a0);
	zend_update_property(phalcon_logger_adapter_file_ce, this_ptr, SL("_quenue"), a0 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		PHALCON_INIT_VAR(options);
		array_init(options);
	}
	
	eval_int = phalcon_array_isset_string(options, SL("mode")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(mode);
		phalcon_array_fetch_string(&mode, options, SL("mode"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(mode);
		ZVAL_STRING(mode, "ab", 1);
	}
	
	PHALCON_INIT_VAR(handler);
	PHALCON_CALL_FUNC_PARAMS_2(handler, "fopen", name, mode);
	if (!zend_is_true(handler)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "Can't open log file at '", name, "'");
		
		PHALCON_INIT_VAR(exception);
		object_init_ex(exception, phalcon_logger_exception_ce);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(exception, "__construct", exception_message, PH_CHECK);
		phalcon_throw_exception(exception TSRMLS_CC);
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

	zval *format = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &format) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_format"), format TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the log format
 *
 * @return format
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getFormat){

	zval *format = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(format);
	phalcon_read_property(&format, this_ptr, SL("_format"), PH_NOISY_CC);
	
	RETURN_CCTOR(format);
}

/**
 * Returns the string meaning of a logger constant
 *
 * @param  integer $type
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getTypeString){

	zval *type = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &type) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(type);
	
	if (phalcon_compare_strict_long(type, 7 TSRMLS_CC)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "DEBUG", 1);
		goto se_654f_0;
	}
	if (phalcon_compare_strict_long(type, 3 TSRMLS_CC)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "ERROR", 1);
		goto se_654f_0;
	}
	if (phalcon_compare_strict_long(type, 4 TSRMLS_CC)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "WARNING", 1);
		goto se_654f_0;
	}
	if (phalcon_compare_strict_long(type, 1 TSRMLS_CC)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "CRITICAL", 1);
		goto se_654f_0;
	}
	if (phalcon_compare_strict_long(type, 8 TSRMLS_CC)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "CUSTOM", 1);
		goto se_654f_0;
	}
	if (phalcon_compare_strict_long(type, 2 TSRMLS_CC)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "ALERT", 1);
		goto se_654f_0;
	}
	if (phalcon_compare_strict_long(type, 5 TSRMLS_CC)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "NOTICE", 1);
		goto se_654f_0;
	}
	if (phalcon_compare_strict_long(type, 6 TSRMLS_CC)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "INFO", 1);
		goto se_654f_0;
	}
	if (phalcon_compare_strict_long(type, 0 TSRMLS_CC)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "EMERGENCE", 1);
		goto se_654f_0;
	}
	if (phalcon_compare_strict_long(type, 9 TSRMLS_CC)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "SPECIAL", 1);
		goto se_654f_0;
	}
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "CUSTOM", 1);
	se_654f_0:
	
	RETURN_CCTOR(type);
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

	zval *message = NULL, *type = NULL, *time = NULL, *format = NULL, *date_format = NULL;
	zval *date = NULL, *new_format = NULL, *type_string = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &message, &type, &time) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!time) {
		PHALCON_ALLOC_ZVAL_MM(time);
		ZVAL_LONG(time, 0);
	} else {
		PHALCON_SEPARATE_PARAM(time);
	}
	
	if (!zend_is_true(time)) {
		PHALCON_INIT_VAR(time);
		PHALCON_CALL_FUNC(time, "time");
	}
	
	PHALCON_INIT_VAR(format);
	phalcon_read_property(&format, this_ptr, SL("_format"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(date_format);
	phalcon_read_property(&date_format, this_ptr, SL("_dateFormat"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(date);
	PHALCON_CALL_FUNC_PARAMS_2(date, "date", date_format, time);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "%date%", 1);
	
	PHALCON_INIT_VAR(new_format);
	phalcon_fast_str_replace(new_format, c0, date, format TSRMLS_CC);
	
	PHALCON_INIT_VAR(type_string);
	PHALCON_CALL_METHOD_PARAMS_1(type_string, this_ptr, "gettypestring", type, PH_NO_CHECK);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "%type%", 1);
	
	PHALCON_INIT_VAR(format);
	phalcon_fast_str_replace(format, c1, type_string, new_format TSRMLS_CC);
	
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "%message%", 1);
	
	PHALCON_INIT_VAR(new_format);
	phalcon_fast_str_replace(new_format, c2, message, format TSRMLS_CC);
	
	RETURN_CTOR(new_format);
}

/**
 * Sets the internal date format
 *
 * @param string $date
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, setDateFormat){

	zval *date = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &date) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	phalcon_update_property_zval(this_ptr, SL("_dateFormat"), date TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal date format
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getDateFormat){

	zval *date_format = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(date_format);
	phalcon_read_property(&date_format, this_ptr, SL("_dateFormat"), PH_NOISY_CC);
	
	RETURN_CCTOR(date_format);
}

/**
 * Sends/Writes messages to the file log
 *
 * @param string $message
 * @param int $type
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, log){

	zval *message = NULL, *type = NULL, *file_handler = NULL, *transaction = NULL;
	zval *time = NULL, *quenue_item = NULL, *applied_format = NULL, *applied_eol = NULL;
	zval *t0 = NULL, *t1 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &message, &type) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!type) {
		PHALCON_ALLOC_ZVAL_MM(type);
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
		
		PHALCON_ALLOC_ZVAL_MM(t0);
		phalcon_read_property(&t0, this_ptr, SL("_quenue"), PH_NOISY_CC);
		phalcon_array_append(&t0, quenue_item, 0 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, SL("_quenue"), t0 TSRMLS_CC);
	} else {
		PHALCON_INIT_VAR(applied_format);
		PHALCON_CALL_METHOD_PARAMS_2(applied_format, this_ptr, "_applyformat", message, type, PH_NO_CHECK);
		
		PHALCON_ALLOC_ZVAL_MM(t1);
		zend_get_constant(SL("PHP_EOL"), t1 TSRMLS_CC);
		
		PHALCON_INIT_VAR(applied_eol);
		PHALCON_CONCAT_VV(applied_eol, applied_format, t1);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fputs", file_handler, applied_eol);
	}
	
	PHALCON_MM_RESTORE();
}

/**
  * Starts a transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, begin){


	PHALCON_MM_GROW();
	phalcon_update_property_bool(this_ptr, SL("_transaction"), 1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
  * Commits the internal transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, commit){

	zval *transaction = NULL, *file_handler = NULL, *quenue = NULL, *message = NULL;
	zval *message_str = NULL, *type = NULL, *time = NULL, *applied_format = NULL;
	zval *applied_eol = NULL;
	zval *t0 = NULL;
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
	if (!phalcon_valid_foreach(quenue TSRMLS_CC)) {
		return;
	}
	
	ah0 = Z_ARRVAL_P(quenue);
	zend_hash_internal_pointer_reset_ex(ah0, &hp0);
	fes_654f_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_654f_1;
		}
		
		PHALCON_INIT_VAR(message);
		ZVAL_ZVAL(message, *hd, 1, 0);
		PHALCON_INIT_VAR(message_str);
		PHALCON_CALL_METHOD(message_str, message, "getmessage", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(type);
		PHALCON_CALL_METHOD(type, message, "gettype", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(time);
		PHALCON_CALL_METHOD(time, message, "gettime", PH_NO_CHECK);
		
		PHALCON_INIT_VAR(applied_format);
		PHALCON_CALL_METHOD_PARAMS_3(applied_format, this_ptr, "_applyformat", message_str, type, time, PH_NO_CHECK);
		
		PHALCON_INIT_VAR(t0);
		zend_get_constant(SL("PHP_EOL"), t0 TSRMLS_CC);
		
		PHALCON_INIT_VAR(applied_eol);
		PHALCON_CONCAT_VV(applied_eol, applied_format, t0);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fputs", file_handler, applied_eol);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_654f_1;
	fee_654f_1:
	if(0){}
	
	
	PHALCON_MM_RESTORE();
}

/**
  * Rollbacks the internal transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, rollback){

	zval *transaction = NULL, *quenue = NULL;

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

	zval *file_handler = NULL, *success = NULL;

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

	zval *path = NULL, *options = NULL, *mode = NULL, *file_handler = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(path);
	phalcon_read_property(&path, this_ptr, SL("_path"), PH_NOISY_CC);
	
	PHALCON_INIT_VAR(options);
	phalcon_read_property(&options, this_ptr, SL("_options"), PH_NOISY_CC);
	eval_int = phalcon_array_isset_string(options, SL("mode")+1);
	if (eval_int) {
		PHALCON_INIT_VAR(mode);
		phalcon_array_fetch_string(&mode, options, SL("mode"), PH_NOISY_CC);
	} else {
		PHALCON_INIT_VAR(mode);
		ZVAL_STRING(mode, "ab", 1);
	}
	
	PHALCON_INIT_VAR(file_handler);
	PHALCON_CALL_FUNC_PARAMS_2(file_handler, "fopen", path, mode);
	phalcon_update_property_zval(this_ptr, SL("_fileHandler"), file_handler TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

