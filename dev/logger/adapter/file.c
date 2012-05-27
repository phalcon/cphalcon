
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

#include "kernel/main.h"
#include "kernel/fcall.h"
#include "kernel/require.h"
#include "kernel/object.h"
#include "kernel/debug.h"
#include "kernel/assert.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/memory.h"

#include "zend_operators.h"
#include "zend_exceptions.h"
#include "zend_interfaces.h"

/**
 * Phalcon_Logger_Adapter_File
 *
 * Adapter to store logs in plain text files
 *
 */

/**
 * Phalcon_Logger_Adapter_File constructor
 *
 * @param string $name
 * @param array $options
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, __construct){

	zval *name = NULL, *options = NULL, *mode = NULL;
	zval *a0 = NULL, *a1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;
	int eval_int;

	PHALCON_MM_GROW();
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_logger_adapter_file_ce, this_ptr, "_quenue", strlen("_quenue"), a0 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &name, &options) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!options) {
		
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(options, a1);
	}
	
	eval_int = phalcon_array_isset_string(options, "mode", strlen("mode")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, options, "mode", strlen("mode"), PHALCON_NOISY TSRMLS_CC);
		PHALCON_CPY_WRT(mode, r0);
	} else {
		PHALCON_INIT_VAR(mode);
		ZVAL_STRING(mode, "ab", 1);
	}
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_2(r1, "fopen", name, mode, 0x025);
	phalcon_update_property_zval(this_ptr, "_fileHandler", strlen("_fileHandler"), r1 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_ce);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Can't open log file at '", name, "'");
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", r2, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
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

	phalcon_update_property_zval(this_ptr, "_format", strlen("_format"), format TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the log format
 *
 * @param string $format
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getFormat){

	zval *format = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &format) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_format", sizeof("_format")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns the string meaning of a logger constant
 *
 * @param  integer $type
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getTypeString){

	zval *type = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &type) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(type);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_logger_ce, "DEBUG", strlen("DEBUG") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, type, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "DEBUG", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_ce, "ERROR", strlen("ERROR") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, type, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "ERROR", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_get_class_constant(t2, phalcon_logger_ce, "WARNING", strlen("WARNING") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, type, t2 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "WARNING", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_get_class_constant(t3, phalcon_logger_ce, "CUSTOM", strlen("CUSTOM") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	is_equal_function(r3, type, t3 TSRMLS_CC);
	if (zend_is_true(r3)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "CUSTOM", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_get_class_constant(t4, phalcon_logger_ce, "CRITICAL", strlen("CRITICAL") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	is_equal_function(r4, type, t4 TSRMLS_CC);
	if (zend_is_true(r4)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "CRITICAL", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_get_class_constant(t5, phalcon_logger_ce, "ALERT", strlen("ALERT") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r5);
	is_equal_function(r5, type, t5 TSRMLS_CC);
	if (zend_is_true(r5)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "ALERT", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t6);
	phalcon_get_class_constant(t6, phalcon_logger_ce, "NOTICE", strlen("NOTICE") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_equal_function(r6, type, t6 TSRMLS_CC);
	if (zend_is_true(r6)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "NOTICE", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t7);
	phalcon_get_class_constant(t7, phalcon_logger_ce, "EMERGENCE", strlen("EMERGENCE") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r7);
	is_equal_function(r7, type, t7 TSRMLS_CC);
	if (zend_is_true(r7)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "EMERGENCE", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_get_class_constant(t8, phalcon_logger_ce, "INFO", strlen("INFO") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r8);
	is_equal_function(r8, type, t8 TSRMLS_CC);
	if (zend_is_true(r8)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "INFO", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t9);
	phalcon_get_class_constant(t9, phalcon_logger_ce, "SPECIAL", strlen("SPECIAL") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r9);
	is_equal_function(r9, type, t9 TSRMLS_CC);
	if (zend_is_true(r9)) {
		PHALCON_INIT_VAR(type);
		ZVAL_STRING(type, "SPECIAL", 1);
		goto se_654f_0;
	}
	PHALCON_INIT_VAR(type);
	ZVAL_STRING(type, "CUSTOM", 1);
	se_654f_0:
	if(0) { };
	
	PHALCON_RETURN_CHECK_CTOR(type);
}

/**
 * Applies the internal format to the message
 *
 * @param  string $message
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, _applyFormat){

	zval *message = NULL, *type = NULL, *time = NULL, *format = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *c0 = NULL, *c1 = NULL, *c2 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &message, &type, &time) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	if (!time) {
		
		PHALCON_INIT_VAR(time);
		ZVAL_LONG(time, 0);
	} else {
		PHALCON_SEPARATE_PARAM(time);
	}
	
	if (!zend_is_true(time)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC(r0, "time", 0x018);
		PHALCON_CPY_WRT(time, r0);
	}
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_format", sizeof("_format")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CPY_WRT(format, t0);
	
	PHALCON_ALLOC_ZVAL_MM(r1);
	
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "%date%", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r2);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_dateFormat", sizeof("_dateFormat")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_2(r2, "date", t1, time, 0x04E);
	PHALCON_CALL_FUNC_PARAMS_3(r1, "str_replace", c0, r2, format, 0x003);
	PHALCON_CPY_WRT(format, r1);
	
	PHALCON_ALLOC_ZVAL_MM(r3);
	
	PHALCON_INIT_VAR(c1);
	ZVAL_STRING(c1, "%type%", 1);
	
	PHALCON_ALLOC_ZVAL_MM(r4);
	PHALCON_CALL_METHOD_PARAMS_1(r4, this_ptr, "gettypestring", type, PHALCON_NO_CHECK);
	PHALCON_CALL_FUNC_PARAMS_3(r3, "str_replace", c1, r4, format, 0x003);
	PHALCON_CPY_WRT(format, r3);
	
	PHALCON_ALLOC_ZVAL_MM(r5);
	
	PHALCON_INIT_VAR(c2);
	ZVAL_STRING(c2, "%message%", 1);
	PHALCON_CALL_FUNC_PARAMS_3(r5, "str_replace", c2, message, format, 0x003);
	PHALCON_CPY_WRT(format, r5);
	
	PHALCON_RETURN_CHECK_CTOR(format);
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

	phalcon_update_property_zval(this_ptr, "_dateFormat", strlen("_dateFormat"), date TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
 * Returns the internal date format
 *
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getDateFormat){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_dateFormat", sizeof("_dateFormat")-1, PHALCON_NOISY TSRMLS_CC);
	
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sends/Writes messages to the file log
 *
 * @param string $message
 * @param int $type
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, log){

	zval *message = NULL, *type = NULL, *msg = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *c0 = NULL, *c1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &message, &type) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "Cannot send message to the log because it is invalid", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_scalar", message, 0x045);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_INIT_VAR(c1);
		ZVAL_BOOL(c1, 1);
		PHALCON_CALL_FUNC_PARAMS_2(r1, "print_r", message, c1, 0x008);
		PHALCON_CPY_WRT(msg, r1);
	}
	
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_transaction", sizeof("_transaction")-1, PHALCON_NOISY TSRMLS_CC);
	if (zend_is_true(t1)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_logger_item_ce);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_FUNC(r2, "time", 0x018);
		PHALCON_CALL_METHOD_PARAMS_3_NORETURN(i1, "__construct", message, type, r2, PHALCON_CHECK);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_quenue", sizeof("_quenue")-1, PHALCON_NOISY TSRMLS_CC);
		phalcon_array_append(&t2, i1, PHALCON_NO_SEPARATE_THX TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_quenue", strlen("_quenue"), t2 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r3);
		PHALCON_CALL_METHOD_PARAMS_2(r3, this_ptr, "_applyformat", message, type, PHALCON_NO_CHECK);
		PHALCON_ALLOC_ZVAL_MM(t4);
		zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t4 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		concat_function(r4, r3, t4 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fputs", t3, r4, 0x04F);
	}
	
	PHALCON_MM_RESTORE();
}

/**
  * Starts a transaccion
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, begin){


	PHALCON_MM_GROW();
	phalcon_update_property_bool(this_ptr, "_transaction", strlen("_transaction"), 1 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
  * Commits the internal transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, commit){

	zval *message = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_transaction", sizeof("_transaction")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "There is no active transaction", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	phalcon_update_property_bool(this_ptr, "_transaction", strlen("_transaction"), 0 TSRMLS_CC);
	
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_quenue", sizeof("_quenue")-1, PHALCON_NOISY TSRMLS_CC);
	if (phalcon_valid_foreach(t1 TSRMLS_CC)) {
		ah0 = Z_ARRVAL_P(t1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_654f_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_654f_1;
		}
		
		PHALCON_INIT_VAR(message);
		ZVAL_ZVAL(message, *hd, 1, 0);
		PHALCON_INIT_VAR(t2);
		phalcon_read_property(&t2, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY TSRMLS_CC);
		PHALCON_INIT_VAR(r0);
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, message, "getmessage", PHALCON_NO_CHECK);
		PHALCON_INIT_VAR(r2);
		PHALCON_CALL_METHOD(r2, message, "gettype", PHALCON_NO_CHECK);
		PHALCON_INIT_VAR(r3);
		PHALCON_CALL_METHOD(r3, message, "gettime", PHALCON_NO_CHECK);
		PHALCON_CALL_METHOD_PARAMS_3(r0, this_ptr, "_applyformat", r1, r2, r3, PHALCON_NO_CHECK);
		PHALCON_INIT_VAR(t3);
		zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t3 TSRMLS_CC);
		PHALCON_INIT_VAR(r4);
		concat_function(r4, r0, t3 TSRMLS_CC);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fputs", t2, r4, 0x04F);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_654f_1;
		fee_654f_1:
		if(0){ };
	}
	
	PHALCON_MM_RESTORE();
}

/**
  * Rollbacks the internal transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, rollback){

	zval *t0 = NULL;
	zval *i0 = NULL;
	zval *c0 = NULL;
	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_transaction", sizeof("_transaction")-1, PHALCON_NOISY TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_ce);
		PHALCON_INIT_VAR(c0);
		ZVAL_STRING(c0, "There is no active transaction", 1);
		PHALCON_CALL_METHOD_PARAMS_1_NORETURN(i0, "__construct", c0, PHALCON_CHECK);
		phalcon_throw_exception(i0 TSRMLS_CC);
		return;
	}
	phalcon_update_property_bool(this_ptr, "_transaction", strlen("_transaction"), 0 TSRMLS_CC);
	
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_quenue", strlen("_quenue"), a0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

/**
  * Closes the logger
  *
  * @return boolean
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, close){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "fclose", t0, 0x027);
	
	PHALCON_RETURN_CHECK_CTOR(r0);
}

/**
 * Opens the internal file handler on unserialization
 *
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, __wakeup){

	zval *r0 = NULL;
	zval *t0 = NULL;
	zval *c0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_path", sizeof("_path")-1, PHALCON_NOISY TSRMLS_CC);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "ab", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "fopen", t0, c0, 0x025);
	phalcon_update_property_zval(this_ptr, "_fileHandler", strlen("_fileHandler"), r0 TSRMLS_CC);
	
	PHALCON_MM_RESTORE();
}

