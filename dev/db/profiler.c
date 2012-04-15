
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
 * Phalcon_Db_Profiler
 *
 * Instances of Phalcon_Db can generate execution profiles
 * on SQL statements sended to the relational database. Profiled
 * information includes excution time in miliseconds.
 * This helps you to identify bottlenecks in your applications.
 *
 */

PHP_METHOD(Phalcon_Db_Profiler, __construct){

	zval *a0 = NULL;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(a0);
	array_init(a0);
	zend_update_property(phalcon_db_profiler_class_entry, this_ptr, "_allProfiles", strlen("_allProfiles"), a0 TSRMLS_CC);

	PHALCON_MM_RESTORE();
}

/**
 * Starts the profile of a SQL sentence
 *
 * @param string $sqlStatement
 */
PHP_METHOD(Phalcon_Db_Profiler, startProfile){

	zval *v0 = NULL;
	zval *i0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL;
	zval *r0 = NULL;
	zval *c0 = NULL;
	zval *p1[] = { NULL }, *p2[] = { NULL }, *p4[] = { NULL };

	PHALCON_MM_GROW();
	
	if (zend_parse_parameters(ZEND_NUM_ARGS() TSRMLS_CC, "z", &v0) == FAILURE) {
		PHALCON_MM_RESTORE();
		RETURN_NULL();
	}

	
	PHALCON_ALLOC_ZVAL_MM(i0);
	object_init_ex(i0, phalcon_db_profiler_item_class_entry);
	PHALCON_CALL_METHOD_NORETURN(i0, "__construct", PHALCON_CALL_CHECK);
	phalcon_update_property_zval(this_ptr, "_activeProfile", strlen("_activeProfile"), i0 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "setsqlstatement", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "microtime", c0, 0x034);
	Z_ADDREF_P(r0);
	p2[0] = r0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t1, "setinitialtime", 1, p2, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p2[0]);
	if (phalcon_method_exists_ex(this_ptr, "beforestartprofile", strlen("beforestartprofile") TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(t2);
		phalcon_read_property(&t2, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t2);
		p4[0] = t2;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "beforestartprofile", 1, p4, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p4[0]);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Stops the active profile
 *
 * @access public
 */
PHP_METHOD(Phalcon_Db_Profiler, stopProfile){

	zval *v0 = NULL;
	zval *r0 = NULL, *r1 = NULL, *r2 = NULL, *r3 = NULL;
	zval *c0 = NULL;
	zval *t0 = NULL, *t1 = NULL, *t2 = NULL, *t3 = NULL, *t4 = NULL, *t5 = NULL;
	zval *p1[] = { NULL }, *p3[] = { NULL };

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_INIT_VAR(c0);
	ZVAL_BOOL(c0, 1);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "microtime", c0, 0x034);
	PHALCON_CPY_WRT(v0, r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(v0);
	p1[0] = v0;
	PHALCON_CALL_METHOD_PARAMS_NORETURN(t0, "setfinaltime", 1, p1, PHALCON_CALL_DEFAULT);
	Z_DELREF_P(p1[0]);
	PHALCON_ALLOC_ZVAL_MM(t1);
	phalcon_read_property(&t1, this_ptr, "_totalSeconds", sizeof("_totalSeconds")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r1);
	PHALCON_ALLOC_ZVAL_MM(t2);
	phalcon_read_property(&t2, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_METHOD(r1, t2, "getinitialtime", PHALCON_CALL_DEFAULT);
	PHALCON_ALLOC_ZVAL_MM(r2);
	sub_function(r2, v0, r1 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(r3);
	phalcon_add_function(r3, t1, r2 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_totalSeconds", strlen("_totalSeconds"), r3 TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t3);
	phalcon_read_property(&t3, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_ALLOC_ZVAL_MM(t4);
	phalcon_read_property(&t4, this_ptr, "_allProfiles", sizeof("_allProfiles")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	Z_ADDREF_P(t3);
	phalcon_array_append(t4, t3 TSRMLS_CC);
	phalcon_update_property_zval(this_ptr, "_allProfiles", strlen("_allProfiles"), t4 TSRMLS_CC);
	if (phalcon_method_exists_ex(this_ptr, "afterendprofile", strlen("afterendprofile") TSRMLS_CC) == SUCCESS) {
		PHALCON_ALLOC_ZVAL_MM(t5);
		phalcon_read_property(&t5, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
		Z_ADDREF_P(t5);
		p3[0] = t5;
		PHALCON_CALL_METHOD_PARAMS_NORETURN(this_ptr, "afterendprofile", 1, p3, PHALCON_CALL_DEFAULT);
		Z_DELREF_P(p3[0]);
	}
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
     * Returns the total number of SQL statements processed
 *
 * @return integer
 */
PHP_METHOD(Phalcon_Db_Profiler, getNumberTotalStatements){

	zval *r0 = NULL;
	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(r0);
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_allProfiles", sizeof("_allProfiles")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_CALL_FUNC_PARAMS_1(r0, "count", t0, 0x008);
	PHALCON_RETURN_DZVAL(r0);
}

/**
 * Returns the total time in seconds spent by the profiles
 *
 * @return double
 */
PHP_METHOD(Phalcon_Db_Profiler, getTotalElapsedSeconds){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_totalSeconds", sizeof("_totalSeconds")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Returns all the processed profiles
 *
 * @return array
 */
PHP_METHOD(Phalcon_Db_Profiler, getProfiles){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_allProfiles", sizeof("_allProfiles")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

/**
 * Resets the profiler, cleaning up all the profiles
 *
 */
PHP_METHOD(Phalcon_Db_Profiler, reset){

	zval *a0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_INIT_VAR(a0);
	array_init(a0);
	phalcon_update_property_zval(this_ptr, "_allProfiles", strlen("_allProfiles"), a0 TSRMLS_CC);
	PHALCON_MM_RESTORE();
	RETURN_NULL();
}

/**
 * Returns the last profile executed in the profiler
 *
 * @returnPhalcon_Db_Profiler_Item
 */
PHP_METHOD(Phalcon_Db_Profiler, getLastProfile){

	zval *t0 = NULL;

	PHALCON_MM_GROW();
	PHALCON_ALLOC_ZVAL_MM(t0);
	phalcon_read_property(&t0, this_ptr, "_activeProfile", sizeof("_activeProfile")-1, PHALCON_NOISY_FETCH TSRMLS_CC);
	PHALCON_RETURN_CHECK_CTOR(t0);
}

