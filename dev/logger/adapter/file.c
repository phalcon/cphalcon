
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

	zval *a0 = NULL, *a1 = NULL;
	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL;
	zval *t0 = NULL;
	zval *i0 = NULL;
	zval *p1[] = { NULL };
	int eval_int;
	zend_bool silence;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_logger_adapter_file_class_entry, this_ptr, "_quenue", strlen("_quenue"), a0 TSRMLS_CC);
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z|z", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v1) {
		PHALCON_INIT_VAR(a1);
		array_init(a1);
		PHALCON_CPY_WRT(v1, a1);
	}
	
	eval_int = phalcon_array_isset_string(v1, "mode", strlen("mode")+1);
	if (eval_int) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		phalcon_array_fetch_string(&r0, v1, "mode", strlen("mode"), PHALCON_NOISY_FETCH TSRMLS_CC);
		PHALCON_CPY_WRT(v2, r0);
	} else {
		PHALCON_INIT_VAR(v2);
		ZVAL_STRING(v2, "ab", 1);
	}
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_CALL_FUNC_PARAMS_2(r1, "fopen", v0, v2, 0x023);
	PG(display_errors) = silence;
	phalcon_update_property_zval(this_ptr, "_fileHandler", strlen("_fileHandler"), r1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_class_entry);
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CONCAT_BOTH(r2,  "Can't open log file at '", v0, "'");
		Z_ADDREF_P(r2);
		p1[0] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p1, PHALCON_CALL_CHECK);
		Z_DELREF_P(p1[0]);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Set the log format
 *
 * @param string $format
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, setFormat){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_format", strlen("_format"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the log format
 *
 * @param string $format
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getFormat){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_format", strlen("_format"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the string meaning of a logger constant
 *
 * @param  integer $type
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, getTypeString){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL, *r6 = NULL;
	zval *r7 = NULL, *r8 = NULL, *r9 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL, *t6 = NULL;
	zval *t7 = NULL, *t8 = NULL, *t9 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	PHALCON_SEPARATE_PARAM(v0);
	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_get_class_constant(t0, phalcon_logger_class_entry, "DEBUG", strlen("DEBUG") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	is_equal_function(r0, v0, t0 TSRMLS_CC);
	if (zend_is_true(r0)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "DEBUG", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_get_class_constant(t1, phalcon_logger_class_entry, "ERROR", strlen("ERROR") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	is_equal_function(r1, v0, t1 TSRMLS_CC);
	if (zend_is_true(r1)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "ERROR", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_get_class_constant(t2, phalcon_logger_class_entry, "WARNING", strlen("WARNING") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r2);
	is_equal_function(r2, v0, t2 TSRMLS_CC);
	if (zend_is_true(r2)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "WARNING", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_get_class_constant(t3, phalcon_logger_class_entry, "CUSTOM", strlen("CUSTOM") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	is_equal_function(r3, v0, t3 TSRMLS_CC);
	if (zend_is_true(r3)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "CUSTOM", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_get_class_constant(t4, phalcon_logger_class_entry, "CRITICAL", strlen("CRITICAL") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r4);
	is_equal_function(r4, v0, t4 TSRMLS_CC);
	if (zend_is_true(r4)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "CRITICAL", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t5);
	phalcon_get_class_constant(t5, phalcon_logger_class_entry, "ALERT", strlen("ALERT") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r5);
	is_equal_function(r5, v0, t5 TSRMLS_CC);
	if (zend_is_true(r5)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "ALERT", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t6);
	phalcon_get_class_constant(t6, phalcon_logger_class_entry, "NOTICE", strlen("NOTICE") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r6);
	is_equal_function(r6, v0, t6 TSRMLS_CC);
	if (zend_is_true(r6)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "NOTICE", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t7);
	phalcon_get_class_constant(t7, phalcon_logger_class_entry, "EMERGENCE", strlen("EMERGENCE") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r7);
	is_equal_function(r7, v0, t7 TSRMLS_CC);
	if (zend_is_true(r7)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "EMERGENCE", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t8);
	phalcon_get_class_constant(t8, phalcon_logger_class_entry, "INFO", strlen("INFO") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r8);
	is_equal_function(r8, v0, t8 TSRMLS_CC);
	if (zend_is_true(r8)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "INFO", 1);
		goto se_654f_0;
	}
	PHALCON_ALLOC_ZVAL_MM(t9);
	phalcon_get_class_constant(t9, phalcon_logger_class_entry, "SPECIAL", strlen("SPECIAL") TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r9);
	is_equal_function(r9, v0, t9 TSRMLS_CC);
	if (zend_is_true(r9)) {
		PHALCON_INIT_VAR(v0);
		ZVAL_STRING(v0, "SPECIAL", 1);
		goto se_654f_0;
	}
	PHALCON_INIT_VAR(v0);
	ZVAL_STRING(v0, "CUSTOM", 1);
	se_654f_0:
	if(0) { };
	PHALCON_RETURN_CHECK_CTOR(v0);
}

/**
 * Applies the internal format to the message
 *
 * @param  string $message
 * @return string
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, _applyFormat){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL, *v3 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL, *r5 = NULL;
	zval *t0 = NULL, *t1 = NULL;
	zval *p1[] = { NULL, NULL, NULL }, *p4[] = { NULL }, *p3[] = { NULL, NULL, NULL }, *p5[] = { NULL, NULL, NULL };
	zend_bool silence;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz|z", &v0, &v1, &v2) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	if (!v2) {
		PHALCON_INIT_VAR(v2);
		ZVAL_LONG(v2, 0);
	} else {
		PHALCON_SEPARATE_PARAM(v2);
	}
	
	if (!zend_is_true(v2)) {
		PHALCON_ALLOC_ZVAL_MM(r0);
		PHALCON_CALL_FUNC(r0, "time", 0x015);
		PHALCON_CPY_WRT(v2, r0);
	}
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_format", sizeof("_format")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CPY_WRT(v3, t0);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_INIT_VAR(p1[0]);
	ZVAL_STRING(p1[0], "%date%", 1);
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r2);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_dateFormat", sizeof("_dateFormat")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t1);
	Z_ADDREF_P(v2);
	PHALCON_CALL_FUNC_PARAMS_2(r2, "date", t1, v2, 0x04D);
	Z_DELREF_P(t1);
	Z_DELREF_P(v2);
	PG(display_errors) = silence;
	p1[1] = r2;
	p1[2] = v3;
	PHALCON_CALL_FUNC_PARAMS(r1, "str_replace", 3, p1, 0x003);
	PHALCON_CPY_WRT(v3, r1);
	PHALCON_ALLOC_ZVAL_MM(r3);
	PHALCON_INIT_VAR(p3[0]);
	ZVAL_STRING(p3[0], "%type%", 1);
	PHALCON_ALLOC_ZVAL_MM(r4);
	Z_ADDREF_P(v1);
	p4[0] = v1;
	PHALCON_CALL_METHOD_PARAMS(r4, this_ptr, "gettypestring", 1, p4, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p4[0]);
	p3[1] = r4;
	p3[2] = v3;
	PHALCON_CALL_FUNC_PARAMS(r3, "str_replace", 3, p3, 0x003);
	PHALCON_CPY_WRT(v3, r3);
	PHALCON_ALLOC_ZVAL_MM(r5);
	PHALCON_INIT_VAR(p5[0]);
	ZVAL_STRING(p5[0], "%message%", 1);
	p5[1] = v0;
	p5[2] = v3;
	PHALCON_CALL_FUNC_PARAMS(r5, "str_replace", 3, p5, 0x003);
	PHALCON_CPY_WRT(v3, r5);
	PHALCON_RETURN_CHECK_CTOR(v3);
}

/**
 * Sets the internal date format
 *
 * @param string $date
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, setDateFormat){

	zval *v0 = NULL;

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	phalcon_update_property_zval(this_ptr, "_dateFormat", strlen("_dateFormat"), v0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
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
	phalcon_read_property(&t0, this_ptr, "_dateFormat", sizeof("_dateFormat")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Sends/Writes messages to the file log
 *
 * @param string $message
 * @param int $type
 */
PHP_METHOD(Phalcon_Logger_Adapter_File, log){

	zval *v0 = NULL, *v1 = NULL, *v2 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL;
	zval *i0 = NULL, *i1 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *c0 = NULL;
	zval *p0[] = { NULL }, *p3[] = { NULL, NULL, NULL }, *p6[] = { NULL, NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "zz", &v0, &v1) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "Cannot send message to the log because it is invalid", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	PHALCON_ALLOC_ZVAL_MM(r0);
	Z_ADDREF_P(v0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "is_scalar", v0, 0x043);
	Z_DELREF_P(v0);
	if (zend_is_true(r0)) {
		PHALCON_ALLOC_ZVAL_MM(r1);
		PHALCON_INIT_VAR(c0);
		ZVAL_BOOL(c0, 1);
		PHALCON_CALL_FUNC_PARAMS_2(r1, "print_r", v0, c0, 0x004);
		PHALCON_CPY_WRT(v2, r1);
	}
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_transaction", sizeof("_transaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (zend_is_true(t1)) {
		PHALCON_ALLOC_ZVAL_MM(i1);
		object_init_ex(i1, phalcon_logger_item_class_entry);
		Z_ADDREF_P(v0);
		p3[0] = v0;
		Z_ADDREF_P(v1);
		p3[1] = v1;
		PHALCON_ALLOC_ZVAL_MM(r2);
		PHALCON_CALL_FUNC(r2, "time", 0x015);
		Z_ADDREF_P(r2);
		p3[2] = r2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i1, "__construct", 3, p3, PHALCON_CALL_CHECK);
		Z_DELREF_P(p3[0]);
		Z_DELREF_P(p3[1]);
		Z_DELREF_P(p3[2]);
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_quenue", sizeof("_quenue")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(i1);
		phalcon_array_append(t2, i1 TSRMLS_CC);
		phalcon_update_property_zval(this_ptr, "_quenue", strlen("_quenue"), t2 TSRMLS_CC);
	} else {
		PHALCON_ALLOC_ZVAL_MM(t3);
		phalcon_read_property(&t3, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t3);
		PHALCON_ALLOC_ZVAL_MM(r3);
		Z_ADDREF_P(v0);
		p6[0] = v0;
		Z_ADDREF_P(v1);
		p6[1] = v1;
		PHALCON_CALL_METHOD_PARAMS(r3, this_ptr, "_applyformat", 2, p6, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p6[0]);
		Z_DELREF_P(p6[1]);
		PHALCON_ALLOC_ZVAL_MM(t4);
		zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t4 TSRMLS_CC);
		PHALCON_ALLOC_ZVAL_MM(r4);
		concat_function(r4, r3, t4 TSRMLS_CC);
		Z_ADDREF_P(r4);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fputs", t3, r4, 0x04E);
		Z_DELREF_P(t3);
		Z_DELREF_P(r4);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Starts a transaccion
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, begin){


	PHALCON_MM_GROW();
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_transaction", strlen("_transaction"), 1 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Commits the internal transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, commit){

	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL;
	zval *i0 = NULL;
	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL, *r4 = NULL;
	zval *p0[] = { NULL }, *p2[] = { NULL, NULL, NULL };
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_transaction", sizeof("_transaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "There is no active transaction", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_transaction", strlen("_transaction"), 0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_quenue", sizeof("_quenue")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (Z_TYPE_P(t1) != IS_ARRAY) {
		php_error_docref(NULL TSRMLS_CC, E_WARNING, "Invalid argument supplied for foreach()");
	} else {
		ah0 = Z_ARRVAL_P(t1);
		zend_hash_internal_pointer_reset_ex(ah0, &hp0);
		fes_654f_1:
		if(zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) != SUCCESS){
			goto fee_654f_1;
		}
		PHALCON_INIT_VAR(v0);
		ZVAL_ZVAL(v0, *hd, 1, 0);
		PHALCON_INIT_VAR(t2);
		phalcon_read_property(&t2, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t2);
		PHALCON_INIT_VAR(r0);
		PHALCON_INIT_VAR(r1);
		PHALCON_CALL_METHOD(r1, v0, "getmessage", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r1);
		p2[0] = r1;
		PHALCON_INIT_VAR(r2);
		PHALCON_CALL_METHOD(r2, v0, "gettype", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r2);
		p2[1] = r2;
		PHALCON_INIT_VAR(r3);
		PHALCON_CALL_METHOD(r3, v0, "gettime", PHALCON_CALL_DEFAULT);
		Z_ADDREF_P(r3);
		p2[2] = r3;
		PHALCON_CALL_METHOD_PARAMS(r0, this_ptr, "_applyformat", 3, p2, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p2[0]);
		Z_DELREF_P(p2[1]);
		Z_DELREF_P(p2[2]);
		PHALCON_INIT_VAR(t3);
		zend_get_constant("PHP_EOL", strlen("PHP_EOL"), t3 TSRMLS_CC);
		PHALCON_INIT_VAR(r4);
		concat_function(r4, r0, t3 TSRMLS_CC);
		Z_ADDREF_P(r4);
		PHALCON_CALL_FUNC_PARAMS_2_NORETURN("fputs", t2, r4, 0x04E);
		Z_DELREF_P(t2);
		Z_DELREF_P(r4);
		zend_hash_move_forward_ex(ah0, &hp0);
		goto fes_654f_1;
		fee_654f_1:
		if(0){ };
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Rollbacks the internal transaction
  *
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, rollback){

	zval *t0 = NULL;
	zval *i0 = NULL;
	zval *a0 = NULL;
	zval *p0[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_transaction", sizeof("_transaction")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	if (!zend_is_true(t0)) {
		PHALCON_ALLOC_ZVAL_MM(i0);
		object_init_ex(i0, phalcon_logger_exception_class_entry);
		PHALCON_INIT_VAR(p0[0]);
		ZVAL_STRING(p0[0], "There is no active transaction", 1);
		PHALCON_CALL_METHOD_PARAMS_NORETURN(i0, "__construct", 1, p0, PHALCON_CALL_CHECK);
		zend_throw_exception_object(i0 TSRMLS_CC);
		Z_ADDREF_P(i0);
		PHALCON_MM_RESTORE();
		return;
	}
	zend_update_property_bool(Z_OBJCE_P(this_ptr), this_ptr, "_transaction", strlen("_transaction"), 0 TSRMLS_CC);
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_quenue", strlen("_quenue"), a0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
  * Closes the logger
  *
  * @return boolean
  */
PHP_METHOD(Phalcon_Logger_Adapter_File, close){

	zval *r0 = NULL;
	zval *t0 = NULL;
	zend_bool silence;

	PHALCON_MM_GROW();
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_fileHandler", sizeof("_fileHandler")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t0);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "fclose", t0, 0x025);
	Z_DELREF_P(t0);
	PG(display_errors) = silence;
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
	zend_bool silence;

	PHALCON_MM_GROW();
	silence = PG(display_errors);
	PG(display_errors) = 0;
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_path", sizeof("_path")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_INIT_VAR(c0);
	ZVAL_STRING(c0, "ab", 1);
	PHALCON_CALL_FUNC_PARAMS_2(r0, "fopen", t0, c0, 0x023);
	PG(display_errors) = silence;
	phalcon_update_property_zval(this_ptr, "_fileHandler", strlen("_fileHandler"), r0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

