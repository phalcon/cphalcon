
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/array.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/exception.h"
#include "kernel/string.h"
#include "kernel/concat.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/file.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * Phalcon\Queue\Beanstalk
 *
 * Class to access the beanstalk queue service.
 * Partially implements the protocol version 1.2
 *
 * <code>
 * use Phalcon\Queue\Beanstalk;
 *
 * $queue = new Beanstalk(
 *     [
 *         "host"       => "127.0.0.1",
 *         "port"       => 11300,
 *         "persistent" => true,
 *     ]
 * );
 * </code>
 *
 * @link http://www.igvita.com/2010/05/20/scalable-work-queues-with-beanstalk/
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Beanstalk) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Queue, Beanstalk, phalcon, queue_beanstalk, phalcon_queue_beanstalk_method_entry, 0);

	/**
	 * Connection resource
	 * @var resource
	 */
	zend_declare_property_null(phalcon_queue_beanstalk_ce, SL("_connection"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Connection options
	 * @var array
	 */
	zend_declare_property_null(phalcon_queue_beanstalk_ce, SL("_parameters"), ZEND_ACC_PROTECTED TSRMLS_CC);

	/**
	 * Seconds to wait before putting the job in the ready queue.
	 * The job will be in the "delayed" state during this time.
	 *
	 * @const integer
	 */
	zephir_declare_class_constant_long(phalcon_queue_beanstalk_ce, SL("DEFAULT_DELAY"), 0);

	/**
	 * Jobs with smaller priority values will be scheduled before jobs with larger priorities.
	 * The most urgent priority is 0, the least urgent priority is 4294967295.
	 *
	 * @const integer
	 */
	zephir_declare_class_constant_long(phalcon_queue_beanstalk_ce, SL("DEFAULT_PRIORITY"), 100);

	/**
	 * Time to run - number of seconds to allow a worker to run this job.
	 * The minimum ttr is 1.
	 *
	 * @const integer
	 */
	zephir_declare_class_constant_long(phalcon_queue_beanstalk_ce, SL("DEFAULT_TTR"), 86400);

	/**
	 * Default tube name
	 * @const string
	 */
	zephir_declare_class_constant_string(phalcon_queue_beanstalk_ce, SL("DEFAULT_TUBE"), "default");

	/**
	 * Default connected host
	 * @const string
	 */
	zephir_declare_class_constant_string(phalcon_queue_beanstalk_ce, SL("DEFAULT_HOST"), "127.0.0.1");

	/**
	 * Default connected port
	 * @const integer
	 */
	zephir_declare_class_constant_long(phalcon_queue_beanstalk_ce, SL("DEFAULT_PORT"), 11300);

	return SUCCESS;

}

/**
 * Phalcon\Queue\Beanstalk
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, __construct) {

	zval *parameters_param = NULL, __$false, _0$$3, _1$$4;
	zval parameters;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&parameters);
	ZVAL_BOOL(&__$false, 0);
	ZVAL_UNDEF(&_0$$3);
	ZVAL_UNDEF(&_1$$4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &parameters_param);

	if (!parameters_param) {
		ZEPHIR_INIT_VAR(&parameters);
		array_init(&parameters);
	} else {
		zephir_get_arrval(&parameters, parameters_param);
	}


	if (!(zephir_array_isset_string(&parameters, SL("host")))) {
		ZEPHIR_INIT_VAR(&_0$$3);
		ZVAL_STRING(&_0$$3, "127.0.0.1");
		zephir_array_update_string(&parameters, SL("host"), &_0$$3, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(&parameters, SL("port")))) {
		ZEPHIR_INIT_VAR(&_1$$4);
		ZVAL_LONG(&_1$$4, 11300);
		zephir_array_update_string(&parameters, SL("port"), &_1$$4, PH_COPY | PH_SEPARATE);
	}
	if (!(zephir_array_isset_string(&parameters, SL("persistent")))) {
		zephir_array_update_string(&parameters, SL("persistent"), &__$false, PH_COPY | PH_SEPARATE);
	}
	zephir_update_property_zval(this_ptr, SL("_parameters"), &parameters);
	ZEPHIR_MM_RESTORE();

}

/**
 * Makes a connection to the Beanstalkd server
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, connect) {

	zval __$null, connection, parameters, _0, _9, _1$$4, _2$$4, _3$$4, _4$$4, _5$$5, _6$$5, _7$$5, _8$$5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&parameters);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_1$$4);
	ZVAL_UNDEF(&_2$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_4$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_6$$5);
	ZVAL_UNDEF(&_7$$5);
	ZVAL_UNDEF(&_8$$5);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&connection);
	zephir_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(&connection) == IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", NULL, 0);
		zephir_check_call_status();
	}
	ZEPHIR_OBS_VAR(&parameters);
	zephir_read_property(&parameters, this_ptr, SL("_parameters"), PH_NOISY_CC);
	zephir_array_fetch_string(&_0, &parameters, SL("persistent"), PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 129 TSRMLS_CC);
	if (zephir_is_true(&_0)) {
		zephir_array_fetch_string(&_1$$4, &parameters, SL("host"), PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 130 TSRMLS_CC);
		zephir_array_fetch_string(&_2$$4, &parameters, SL("port"), PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 130 TSRMLS_CC);
		ZVAL_NULL(&_3$$4);
		ZVAL_NULL(&_4$$4);
		ZEPHIR_MAKE_REF(&_3$$4);
		ZEPHIR_MAKE_REF(&_4$$4);
		ZEPHIR_CALL_FUNCTION(&connection, "pfsockopen", NULL, 397, &_1$$4, &_2$$4, &_3$$4, &_4$$4);
		ZEPHIR_UNREF(&_3$$4);
		ZEPHIR_UNREF(&_4$$4);
		zephir_check_call_status();
	} else {
		zephir_array_fetch_string(&_5$$5, &parameters, SL("host"), PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 132 TSRMLS_CC);
		zephir_array_fetch_string(&_6$$5, &parameters, SL("port"), PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 132 TSRMLS_CC);
		ZVAL_NULL(&_7$$5);
		ZVAL_NULL(&_8$$5);
		ZEPHIR_MAKE_REF(&_7$$5);
		ZEPHIR_MAKE_REF(&_8$$5);
		ZEPHIR_CALL_FUNCTION(&connection, "fsockopen", NULL, 398, &_5$$5, &_6$$5, &_7$$5, &_8$$5);
		ZEPHIR_UNREF(&_7$$5);
		ZEPHIR_UNREF(&_8$$5);
		zephir_check_call_status();
	}
	if (Z_TYPE_P(&connection) != IS_RESOURCE) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_beanstalk_exception_ce, "Can't connect to Beanstalk server", "phalcon/queue/beanstalk.zep", 136);
		return;
	}
	ZVAL_LONG(&_9, -1);
	ZEPHIR_CALL_FUNCTION(NULL, "stream_set_timeout", NULL, 399, &connection, &_9, &__$null);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, SL("_connection"), &connection);
	RETURN_CCTOR(&connection);

}

/**
 * Puts a job on the queue using specified tube.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, put) {

	zend_bool _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options;
	zval *data, data_sub, *options_param = NULL, priority, delay, ttr, serialized, response, status, length, _0, _2;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data_sub);
	ZVAL_UNDEF(&priority);
	ZVAL_UNDEF(&delay);
	ZVAL_UNDEF(&ttr);
	ZVAL_UNDEF(&serialized);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&length);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&options);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 1, &data, &options_param);

	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}


	ZEPHIR_OBS_VAR(&priority);
	if (!(zephir_array_isset_string_fetch(&priority, &options, SL("priority"), 0))) {
		ZEPHIR_INIT_NVAR(&priority);
		ZVAL_LONG(&priority, 100);
	}
	ZEPHIR_OBS_VAR(&delay);
	if (!(zephir_array_isset_string_fetch(&delay, &options, SL("delay"), 0))) {
		ZEPHIR_INIT_NVAR(&delay);
		ZVAL_LONG(&delay, 0);
	}
	ZEPHIR_OBS_VAR(&ttr);
	if (!(zephir_array_isset_string_fetch(&ttr, &options, SL("ttr"), 0))) {
		ZEPHIR_INIT_NVAR(&ttr);
		ZVAL_LONG(&ttr, 86400);
	}
	ZEPHIR_CALL_FUNCTION(&serialized, "serialize", NULL, 52, data);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&length);
	ZVAL_LONG(&length, zephir_fast_strlen_ev(&serialized));
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SVSVSVSVSV(&_0, "put ", &priority, " ", &delay, " ", &ttr, " ", &length, "\r\n", &serialized);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 400);
	zephir_check_call_status();
	zephir_array_fetch_long(&status, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 180 TSRMLS_CC);
	_1 = !ZEPHIR_IS_STRING(&status, "INSERTED");
	if (_1) {
		_1 = !ZEPHIR_IS_STRING(&status, "BURIED");
	}
	if (_1) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(&_2);
	zephir_array_fetch_long(&_2, &response, 1, PH_NOISY, "phalcon/queue/beanstalk.zep", 186 TSRMLS_CC);
	RETURN_MM_LONG(zephir_get_intval(&_2));

}

/**
 * Reserves/locks a ready job from the specified tube.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, reserve) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *timeout = NULL, timeout_sub, __$null, command, response, _0, _1, _2, _3, _4;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&timeout_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&command);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &timeout);

	if (!timeout) {
		timeout = &timeout_sub;
		timeout = &__$null;
	}


	ZEPHIR_INIT_VAR(&command);
	if (Z_TYPE_P(timeout) != IS_NULL) {
		ZEPHIR_CONCAT_SV(&command, "reserve-with-timeout ", timeout);
	} else {
		ZVAL_STRING(&command, "reserve");
	}
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &command);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 400);
	zephir_check_call_status();
	zephir_array_fetch_long(&_0, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 205 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_0, "RESERVED")) {
		RETURN_MM_BOOL(0);
	}
	object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
	zephir_array_fetch_long(&_1, &response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 215 TSRMLS_CC);
	zephir_array_fetch_long(&_3, &response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 215 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "read", NULL, 0, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_4, "unserialize", NULL, 53, &_2);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 401, this_ptr, &_1, &_4);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Change the active tube. By default the tube is "default".
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, choose) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tube_param = NULL, response, _1, _2;
	zval tube, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tube_param);

	if (UNEXPECTED(Z_TYPE_P(tube_param) != IS_STRING && Z_TYPE_P(tube_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tube' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tube_param) == IS_STRING)) {
		zephir_get_strval(&tube, tube_param);
	} else {
		ZEPHIR_INIT_VAR(&tube);
		ZVAL_EMPTY_STRING(&tube);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "use ", &tube);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 400);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 228 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_1, "USING")) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_2, &response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 232 TSRMLS_CC);
	RETURN_CTOR(&_2);

}

/**
 * The watch command adds the named tube to the watch list for the current connection.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, watch) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tube_param = NULL, response, _1, _2;
	zval tube, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tube_param);

	if (UNEXPECTED(Z_TYPE_P(tube_param) != IS_STRING && Z_TYPE_P(tube_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tube' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tube_param) == IS_STRING)) {
		zephir_get_strval(&tube, tube_param);
	} else {
		ZEPHIR_INIT_VAR(&tube);
		ZVAL_EMPTY_STRING(&tube);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "watch ", &tube);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 400);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 245 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_1, "WATCHING")) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(&_2);
	zephir_array_fetch_long(&_2, &response, 1, PH_NOISY, "phalcon/queue/beanstalk.zep", 249 TSRMLS_CC);
	RETURN_MM_LONG(zephir_get_intval(&_2));

}

/**
 * It removes the named tube from the watch list for the current connection.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, ignore) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tube_param = NULL, response, _1, _2;
	zval tube, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tube_param);

	if (UNEXPECTED(Z_TYPE_P(tube_param) != IS_STRING && Z_TYPE_P(tube_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tube' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tube_param) == IS_STRING)) {
		zephir_get_strval(&tube, tube_param);
	} else {
		ZEPHIR_INIT_VAR(&tube);
		ZVAL_EMPTY_STRING(&tube);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "ignore ", &tube);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 400);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 262 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_1, "WATCHING")) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(&_2);
	zephir_array_fetch_long(&_2, &response, 1, PH_NOISY, "phalcon/queue/beanstalk.zep", 266 TSRMLS_CC);
	RETURN_MM_LONG(zephir_get_intval(&_2));

}

/**
 * Can delay any new job being reserved for a given time.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, pauseTube) {

	zend_long delay, ZEPHIR_LAST_CALL_STATUS;
	zval *tube_param = NULL, *delay_param = NULL, response, _0, _2;
	zval tube, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 2, 0, &tube_param, &delay_param);

	if (UNEXPECTED(Z_TYPE_P(tube_param) != IS_STRING && Z_TYPE_P(tube_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tube' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tube_param) == IS_STRING)) {
		zephir_get_strval(&tube, tube_param);
	} else {
		ZEPHIR_INIT_VAR(&tube);
		ZVAL_EMPTY_STRING(&tube);
	}
	delay = zephir_get_intval(delay_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, delay);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SVSV(&_1, "pause-tube ", &tube, " ", &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 400);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 279 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_2, "PAUSED")) {
		RETURN_MM_BOOL(0);
	}
	RETURN_MM_BOOL(1);

}

/**
 * The kick command applies only to the currently used tube.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, kick) {

	zval _1;
	zval *bound_param = NULL, response, _0, _2, _3;
	zend_long bound, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &bound_param);

	bound = zephir_get_intval(bound_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, bound);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "kick ", &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 400);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 296 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_2, "KICKED")) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_OBS_VAR(&_3);
	zephir_array_fetch_long(&_3, &response, 1, PH_NOISY, "phalcon/queue/beanstalk.zep", 300 TSRMLS_CC);
	RETURN_MM_LONG(zephir_get_intval(&_3));

}

/**
 * Gives statistical information about the system as a whole.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, stats) {

	zval response, _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "stats");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readyaml", NULL, 402);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 313 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_1, "OK")) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_2, &response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 317 TSRMLS_CC);
	RETURN_CTOR(&_2);

}

/**
 * Gives statistical information about the specified tube if it exists.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, statsTube) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *tube_param = NULL, response, _1, _2;
	zval tube, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&tube);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &tube_param);

	if (UNEXPECTED(Z_TYPE_P(tube_param) != IS_STRING && Z_TYPE_P(tube_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'tube' must be of the type string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (EXPECTED(Z_TYPE_P(tube_param) == IS_STRING)) {
		zephir_get_strval(&tube, tube_param);
	} else {
		ZEPHIR_INIT_VAR(&tube);
		ZVAL_EMPTY_STRING(&tube);
	}


	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_SV(&_0, "stats-tube ", &tube);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readyaml", NULL, 402);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 330 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_1, "OK")) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_2, &response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 334 TSRMLS_CC);
	RETURN_CTOR(&_2);

}

/**
 * Returns a list of all existing tubes.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, listTubes) {

	zval response, _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "list-tubes");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readyaml", NULL, 402);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 347 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_1, "OK")) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_2, &response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 351 TSRMLS_CC);
	RETURN_CTOR(&_2);

}

/**
 * Returns the tube currently being used by the client.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, listTubeUsed) {

	zval response, _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "list-tube-used");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 400);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 364 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_1, "USING")) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_2, &response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 368 TSRMLS_CC);
	RETURN_CTOR(&_2);

}

/**
 * Returns a list tubes currently being watched by the client.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, listTubesWatched) {

	zval response, _0, _1, _2;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "list-tubes-watched");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readyaml", NULL, 402);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 381 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_1, "OK")) {
		RETURN_MM_BOOL(0);
	}
	zephir_array_fetch_long(&_2, &response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 385 TSRMLS_CC);
	RETURN_CTOR(&_2);

}

/**
 * Inspect the next ready job.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, peekReady) {

	zval response, _0, _1, _2, _3, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "peek-ready");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 400);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 398 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_1, "FOUND")) {
		RETURN_MM_BOOL(0);
	}
	object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
	zephir_array_fetch_long(&_2, &response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 402 TSRMLS_CC);
	zephir_array_fetch_long(&_4, &response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 402 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "read", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "unserialize", NULL, 53, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 401, this_ptr, &_2, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the next job in the list of buried jobs.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, peekBuried) {

	zval response, _0, _1, _2, _3, _4, _5;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "peek-buried");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 400);
	zephir_check_call_status();
	zephir_array_fetch_long(&_1, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 415 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_1, "FOUND")) {
		RETURN_MM_BOOL(0);
	}
	object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
	zephir_array_fetch_long(&_2, &response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 419 TSRMLS_CC);
	zephir_array_fetch_long(&_4, &response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 419 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_3, this_ptr, "read", NULL, 0, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_5, "unserialize", NULL, 53, &_3);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 401, this_ptr, &_2, &_5);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Return the next job in the list of buried jobs.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, peekDelayed) {

	zval response, _0, _1, _2, _3, _4, _5, _6;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "peek-delayed");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "write", NULL, 0, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		RETURN_MM_BOOL(0);
	}
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 400);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 434 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_2, "FOUND")) {
		RETURN_MM_BOOL(0);
	}
	object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
	zephir_array_fetch_long(&_3, &response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 438 TSRMLS_CC);
	zephir_array_fetch_long(&_5, &response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 438 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "read", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "unserialize", NULL, 53, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 401, this_ptr, &_3, &_6);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * The peek commands let the client inspect a job in the system.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, jobPeek) {

	zval _1;
	zval *id_param = NULL, response, _0, _2, _3, _4, _5, _6;
	zend_long id, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &id_param);

	id = zephir_get_intval(id_param);


	ZEPHIR_SINIT_VAR(_0);
	ZVAL_LONG(&_0, id);
	ZEPHIR_INIT_VAR(&_1);
	ZEPHIR_CONCAT_SV(&_1, "peek ", &_0);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 400);
	zephir_check_call_status();
	zephir_array_fetch_long(&_2, &response, 0, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 452 TSRMLS_CC);
	if (!ZEPHIR_IS_STRING(&_2, "FOUND")) {
		RETURN_MM_BOOL(0);
	}
	object_init_ex(return_value, phalcon_queue_beanstalk_job_ce);
	zephir_array_fetch_long(&_3, &response, 1, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 456 TSRMLS_CC);
	zephir_array_fetch_long(&_5, &response, 2, PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 456 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(&_4, this_ptr, "read", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_6, "unserialize", NULL, 53, &_4);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 401, this_ptr, &_3, &_6);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Reads the latest status from the Beanstalkd server
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, readStatus) {

	zval status;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&status);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&status, this_ptr, "read", NULL, 0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&status)) {
		array_init(return_value);
		RETURN_MM();
	}
	zephir_fast_explode_str(return_value, SL(" "), &status, LONG_MAX TSRMLS_CC);
	RETURN_MM();

}

/**
 * Fetch a YAML payload from the Beanstalkd server
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, readYaml) {

	zval response, status, numberOfBytes, data;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&response);
	ZVAL_UNDEF(&status);
	ZVAL_UNDEF(&numberOfBytes);
	ZVAL_UNDEF(&data);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_METHOD(&response, this_ptr, "readstatus", NULL, 400);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&status);
	zephir_array_fetch_long(&status, &response, 0, PH_NOISY, "phalcon/queue/beanstalk.zep", 481 TSRMLS_CC);
	if (zephir_fast_count_int(&response TSRMLS_CC) > 1) {
		ZEPHIR_OBS_VAR(&numberOfBytes);
		zephir_array_fetch_long(&numberOfBytes, &response, 1, PH_NOISY, "phalcon/queue/beanstalk.zep", 484 TSRMLS_CC);
		ZEPHIR_CALL_METHOD(&response, this_ptr, "read", NULL, 0);
		zephir_check_call_status();
		ZEPHIR_CALL_FUNCTION(&data, "yaml_parse", NULL, 403, &response);
		zephir_check_call_status();
	} else {
		ZEPHIR_INIT_NVAR(&numberOfBytes);
		ZVAL_LONG(&numberOfBytes, 0);
		ZEPHIR_INIT_NVAR(&data);
		array_init(&data);
	}
	zephir_create_array(return_value, 3, 0 TSRMLS_CC);
	zephir_array_fast_append(return_value, &status);
	zephir_array_fast_append(return_value, &numberOfBytes);
	zephir_array_fast_append(return_value, &data);
	RETURN_MM();

}

/**
 * Reads a packet from the socket. Prior to reading from the socket will
 * check for availability of the connection.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, read) {

	zval *length_param = NULL, connection, data, _0$$5, _1$$5, _2$$5, _3$$5, _4$$5, _5$$8, _6$$8;
	zend_long length, ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0$$5);
	ZVAL_UNDEF(&_1$$5);
	ZVAL_UNDEF(&_2$$5);
	ZVAL_UNDEF(&_3$$5);
	ZVAL_UNDEF(&_4$$5);
	ZVAL_UNDEF(&_5$$8);
	ZVAL_UNDEF(&_6$$8);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &length_param);

	if (!length_param) {
		length = 0;
	} else {
		length = zephir_get_intval(length_param);
	}


	ZEPHIR_OBS_VAR(&connection);
	zephir_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(&connection) != IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(&connection, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&connection) != IS_RESOURCE) {
			RETURN_MM_BOOL(0);
		}
	}
	if (length) {
		if (zephir_feof(&connection TSRMLS_CC)) {
			RETURN_MM_BOOL(0);
		}
		ZVAL_LONG(&_0$$5, (length + 2));
		ZEPHIR_CALL_FUNCTION(&_1$$5, "stream_get_line", NULL, 404, &connection, &_0$$5);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&_2$$5);
		ZVAL_STRING(&_2$$5, "\r\n");
		ZEPHIR_INIT_VAR(&data);
		zephir_fast_trim(&data, &_1$$5, &_2$$5, ZEPHIR_TRIM_RIGHT TSRMLS_CC);
		ZEPHIR_CALL_FUNCTION(&_3$$5, "stream_get_meta_data", NULL, 405, &connection);
		zephir_check_call_status();
		zephir_array_fetch_string(&_4$$5, &_3$$5, SL("timed_out"), PH_NOISY | PH_READONLY, "phalcon/queue/beanstalk.zep", 525 TSRMLS_CC);
		if (zephir_is_true(&_4$$5)) {
			ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_beanstalk_exception_ce, "Connection timed out", "phalcon/queue/beanstalk.zep", 526);
			return;
		}
	} else {
		ZVAL_LONG(&_5$$8, 16384);
		ZEPHIR_INIT_VAR(&_6$$8);
		ZVAL_STRING(&_6$$8, "\r\n");
		ZEPHIR_CALL_FUNCTION(&data, "stream_get_line", NULL, 404, &connection, &_5$$8, &_6$$8);
		zephir_check_call_status();
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&data, "UNKNOWN_COMMAND")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_beanstalk_exception_ce, "UNKNOWN_COMMAND", "phalcon/queue/beanstalk.zep", 534);
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&data, "JOB_TOO_BIG")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_beanstalk_exception_ce, "JOB_TOO_BIG", "phalcon/queue/beanstalk.zep", 538);
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&data, "BAD_FORMAT")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_beanstalk_exception_ce, "BAD_FORMAT", "phalcon/queue/beanstalk.zep", 542);
		return;
	}
	if (ZEPHIR_IS_STRING_IDENTICAL(&data, "OUT_OF_MEMORY")) {
		ZEPHIR_THROW_EXCEPTION_DEBUG_STR(phalcon_queue_beanstalk_exception_ce, "OUT_OF_MEMORY", "phalcon/queue/beanstalk.zep", 546);
		return;
	}
	RETURN_CCTOR(&data);

}

/**
 * Writes data to the socket. Performs a connection if none is available
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, write) {

	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *data_param = NULL, connection, packet, _1;
	zval data, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&connection);
	ZVAL_UNDEF(&packet);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &data_param);

	zephir_get_strval(&data, data_param);


	ZEPHIR_OBS_VAR(&connection);
	zephir_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(&connection) != IS_RESOURCE) {
		ZEPHIR_CALL_METHOD(&connection, this_ptr, "connect", NULL, 0);
		zephir_check_call_status();
		if (Z_TYPE_P(&connection) != IS_RESOURCE) {
			RETURN_MM_BOOL(0);
		}
	}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_CONCAT_VS(&_0, &data, "\r\n");
	ZEPHIR_CPY_WRT(&packet, &_0);
	ZVAL_LONG(&_1, zephir_fast_strlen_ev(&packet));
	ZEPHIR_RETURN_CALL_FUNCTION("fwrite", NULL, 406, &connection, &packet, &_1);
	zephir_check_call_status();
	RETURN_MM();

}

/**
 * Closes the connection to the beanstalk server.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, disconnect) {

	zval __$null, connection;
	zval *this_ptr = getThis();

	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&connection);

	ZEPHIR_MM_GROW();

	ZEPHIR_OBS_VAR(&connection);
	zephir_read_property(&connection, this_ptr, SL("_connection"), PH_NOISY_CC);
	if (Z_TYPE_P(&connection) != IS_RESOURCE) {
		RETURN_MM_BOOL(0);
	}
	zephir_fclose(&connection TSRMLS_CC);
	zephir_update_property_zval(this_ptr, SL("_connection"), &__$null);
	RETURN_MM_BOOL(1);

}

/**
 * Simply closes the connection.
 */
PHP_METHOD(Phalcon_Queue_Beanstalk, quit) {

	zval _0, _1;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);

	ZEPHIR_MM_GROW();

	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "quit");
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "write", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "disconnect", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_OBS_VAR(&_1);
	zephir_read_property(&_1, this_ptr, SL("_connection"), PH_NOISY_CC);
	RETURN_MM_BOOL(Z_TYPE_P(&_1) != IS_RESOURCE);

}

