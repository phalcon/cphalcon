
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
#include "kernel/concat.h"
#include "kernel/memory.h"
#include "kernel/string.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/file.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Implementation of this component has been inspired by the queue-interop and
 * enqueue projects.
 *
 * @link    https://github.com/queue-interop/queue-interop
 * @license https://github.com/queue-interop/queue-interop/blob/master/LICENSE
 *
 * @link    https://github.com/php-enqueue/enqueue-dev
 * @license https://github.com/php-enqueue/enqueue-dev/blob/master/LICENSE
 */
/**
 * Filesystem transport session. Each queue is one append-only file under the
 * configured directory; cross-process safety comes from flock. One message
 * per line, stored as base64(serialize([...])) so bodies with newlines are
 * safe. The destination factories come from AbstractContext.
 */
ZEPHIR_INIT_CLASS(Phalcon_Queue_Adapter_Stream_StreamContext)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Queue\\Adapter\\Stream, StreamContext, phalcon, queue_adapter_stream_streamcontext, phalcon_queue_adapter_abstractcontext_ce, phalcon_queue_adapter_stream_streamcontext_method_entry, 0);

	/**
	 * Milliseconds slept between poll attempts by consumers.
	 *
	 * @var int
	 */
	zend_declare_property_long(phalcon_queue_adapter_stream_streamcontext_ce, SL("pollInterval"), 200, ZEND_ACC_PROTECTED);
	/**
	 * Directory (with trailing separator) that holds the queue files.
	 *
	 * @var string
	 */
	zend_declare_property_string(phalcon_queue_adapter_stream_streamcontext_ce, SL("storageDir"), "", ZEND_ACC_PROTECTED);
	return SUCCESS;
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long pollInterval;
	zval storageDir_zv, *pollInterval_param = NULL, _0, _1, _2, _3;
	zend_string *storageDir = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&storageDir_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(storageDir)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(pollInterval)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		pollInterval_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&storageDir_zv);
	ZVAL_STR_COPY(&storageDir_zv, storageDir);
	if (!pollInterval_param) {
		pollInterval = 200;
	} else {
		}
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/");
	zephir_fast_trim(&_0, &storageDir_zv, &_1, ZEPHIR_TRIM_RIGHT);
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_CONCAT_VS(&_2, &_0, "/");
	zephir_update_property_zval(this_ptr, ZEND_STRL("storageDir"), &_2);
	ZVAL_UNDEF(&_3);
	ZVAL_LONG(&_3, pollInterval);
	zephir_update_property_zval(this_ptr, ZEND_STRL("pollInterval"), &_3);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, close)
{

}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, createConsumer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *destination, destination_sub, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&destination_sub);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(destination, phalcon_contracts_queue_destination_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &destination);
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "consume from");
	ZEPHIR_CALL_CE_STATIC(NULL, phalcon_queue_adapter_queuedestinationguard_ce, "assertqueue", NULL, 0, destination, &_0);
	zephir_check_call_status();
	object_init_ex(return_value, phalcon_queue_adapter_stream_streamconsumer_ce);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("pollInterval"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr, destination, &_1);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, createMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval properties, headers;
	zval body_zv, *properties_param = NULL, *headers_param = NULL;
	zend_string *body = NULL;

	ZVAL_UNDEF(&body_zv);
	ZVAL_UNDEF(&properties);
	ZVAL_UNDEF(&headers);
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(body)
		ZEPHIR_Z_PARAM_ARRAY(properties, properties_param)
		ZEPHIR_Z_PARAM_ARRAY(headers, headers_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		properties_param = ZEND_CALL_ARG(execute_data, 2);
	}
	if (ZEND_NUM_ARGS() > 2) {
		headers_param = ZEND_CALL_ARG(execute_data, 3);
	}
	if (!body) {
		body = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&body_zv);
		ZVAL_STR(&body_zv, body);
	} else {
		zephir_memory_observe(&body_zv);
	ZVAL_STR_COPY(&body_zv, body);
	}
	if (!properties_param) {
		ZEPHIR_INIT_VAR(&properties);
		array_init(&properties);
	} else {
		zephir_get_arrval(&properties, properties_param);
	}
	if (!headers_param) {
		ZEPHIR_INIT_VAR(&headers);
		array_init(&headers);
	} else {
		zephir_get_arrval(&headers, headers_param);
	}
	object_init_ex(return_value, phalcon_queue_adapter_stream_streammessage_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &body_zv, &properties, &headers);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, createProducer)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_queue_adapter_stream_streamproducer_ce);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, createSubscriptionConsumer)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	object_init_ex(return_value, phalcon_queue_adapter_stream_streamsubscriptionconsumer_ce);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("pollInterval"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, this_ptr, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Removes the front message from a queue file, or null when it is empty.
 * Internal transport API used by StreamConsumer.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, popMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval queueName_zv, filepath, pointer, contents, lines, line, data, remaining, _0, _1, _2, _3, _8, _9, _10, _11, _4$$6, _5$$7, _6$$7, _7$$7;
	zend_string *queueName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queueName_zv);
	ZVAL_UNDEF(&filepath);
	ZVAL_UNDEF(&pointer);
	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&lines);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&data);
	ZVAL_UNDEF(&remaining);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_10);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_4$$6);
	ZVAL_UNDEF(&_5$$7);
	ZVAL_UNDEF(&_6$$7);
	ZVAL_UNDEF(&_7$$7);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(queueName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&queueName_zv);
	ZVAL_STR_COPY(&queueName_zv, queueName);
	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getfilepath", NULL, 0, &queueName_zv);
	zephir_check_call_status();
	if (!((zephir_file_exists(&filepath) == SUCCESS))) {
		RETURN_MM_NULL();
	}
	ZEPHIR_INIT_VAR(&_0);
	ZVAL_STRING(&_0, "c+");
	ZEPHIR_CALL_FUNCTION(&pointer, "fopen", NULL, 283, &filepath, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_FALSE_IDENTICAL(&pointer)) {
		RETURN_MM_NULL();
	}
	ZVAL_LONG(&_1, 2);
	ZEPHIR_CALL_FUNCTION(&_2, "flock", NULL, 277, &pointer, &_1);
	zephir_check_call_status();
	if (!(zephir_is_true(&_2))) {
		zephir_fclose(&pointer);
		RETURN_MM_NULL();
	}
	ZEPHIR_CALL_FUNCTION(&contents, "stream_get_contents", NULL, 0, &pointer);
	zephir_check_call_status();
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_VAR(&_3);
	ZEPHIR_GET_CONSTANT(&_3, "PHP_EOL");
	zephir_fast_explode(&_0, &_3, &contents, LONG_MAX);
	ZEPHIR_CALL_FUNCTION(&lines, "array_filter", NULL, 32, &_0);
	zephir_check_call_status();
	if (ZEPHIR_IS_EMPTY(&lines)) {
		ZVAL_LONG(&_4$$6, 3);
		ZEPHIR_CALL_FUNCTION(NULL, "flock", NULL, 277, &pointer, &_4$$6);
		zephir_check_call_status();
		zephir_fclose(&pointer);
		RETURN_MM_NULL();
	}
	ZEPHIR_MAKE_REF(&lines);
	ZEPHIR_CALL_FUNCTION(&line, "array_shift", NULL, 41, &lines);
	ZEPHIR_UNREF(&lines);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&remaining);
	if (zephir_fast_count_int(&lines) > 0) {
		ZEPHIR_INIT_VAR(&_5$$7);
		ZEPHIR_INIT_VAR(&_6$$7);
		ZEPHIR_GET_CONSTANT(&_6$$7, "PHP_EOL");
		zephir_fast_join(&_5$$7, &_6$$7, &lines);
		ZEPHIR_INIT_VAR(&_7$$7);
		ZEPHIR_GET_CONSTANT(&_7$$7, "PHP_EOL");
		ZEPHIR_CONCAT_VV(&remaining, &_5$$7, &_7$$7);
	} else {
		ZVAL_STRING(&remaining, "");
	}
	ZVAL_LONG(&_1, 0);
	ZEPHIR_CALL_FUNCTION(NULL, "ftruncate", NULL, 0, &pointer, &_1);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(NULL, "rewind", NULL, 0, &pointer);
	zephir_check_call_status();
	zephir_fwrite(NULL, &pointer, &remaining);
	ZVAL_LONG(&_1, 3);
	ZEPHIR_CALL_FUNCTION(NULL, "flock", NULL, 277, &pointer, &_1);
	zephir_check_call_status();
	zephir_fclose(&pointer);
	ZEPHIR_CALL_FUNCTION(&_8, "base64_decode", NULL, 0, &line);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&data, phalcon_queue_adapter_messageenvelope_ce, "decode", NULL, 0, &_8);
	zephir_check_call_status();
	if (Z_TYPE_P(&data) == IS_NULL) {
		RETURN_MM_NULL();
	}
	object_init_ex(return_value, phalcon_queue_adapter_stream_streammessage_ce);
	zephir_array_fetch_string(&_9, &data, SL("body"), PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Stream/StreamContext.zep", 142);
	zephir_array_fetch_string(&_10, &data, SL("properties"), PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Stream/StreamContext.zep", 142);
	zephir_array_fetch_string(&_11, &data, SL("headers"), PH_NOISY | PH_READONLY, "phalcon/Queue/Adapter/Stream/StreamContext.zep", 142);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 0, &_9, &_10, &_11);
	zephir_check_call_status();
	RETURN_MM();
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, purgeQueue)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *queue, queue_sub, filepath, _0;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queue_sub);
	ZVAL_UNDEF(&filepath);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(queue, phalcon_contracts_queue_queue_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &queue);
	ZEPHIR_CALL_METHOD(&_0, queue, "getqueuename", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getfilepath", NULL, 0, &_0);
	zephir_check_call_status();
	if ((zephir_file_exists(&filepath) == SUCCESS)) {
		ZEPHIR_CALL_FUNCTION(NULL, "unlink", NULL, 241, &filepath);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

/**
 * Appends a message to the back of a queue file.
 * Internal transport API used by StreamProducer.
 */
PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, pushMessage)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval queueName_zv, *message, message_sub, filepath, line, _0, _1, _2, _3;
	zend_string *queueName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queueName_zv);
	ZVAL_UNDEF(&message_sub);
	ZVAL_UNDEF(&filepath);
	ZVAL_UNDEF(&line);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(queueName)
		Z_PARAM_OBJECT_OF_CLASS(message, phalcon_contracts_queue_message_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	message = ZEND_CALL_ARG(execute_data, 2);
	zephir_memory_observe(&queueName_zv);
	ZVAL_STR_COPY(&queueName_zv, queueName);
	ZEPHIR_CALL_METHOD(&filepath, this_ptr, "getfilepath", NULL, 0, &queueName_zv);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "ensuredir", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_CALL_CE_STATIC(&_0, phalcon_queue_adapter_messageenvelope_ce, "encode", NULL, 0, message);
	zephir_check_call_status();
	ZEPHIR_CALL_FUNCTION(&_1, "base64_encode", NULL, 0, &_0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_2);
	ZEPHIR_GET_CONSTANT(&_2, "PHP_EOL");
	ZEPHIR_INIT_VAR(&line);
	ZEPHIR_CONCAT_VV(&line, &_1, &_2);
	ZVAL_LONG(&_3, (8 | 2));
	ZEPHIR_CALL_FUNCTION(NULL, "file_put_contents", NULL, 282, &filepath, &line, &_3);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, ensureDir)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval __$true, _0, _1, _2$$3, _3$$3;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_BOOL(&__$true, 1);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_3$$3);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("storageDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_FUNCTION(&_1, "is_dir", NULL, 280, &_0);
	zephir_check_call_status();
	if (!(zephir_is_true(&_1))) {
		zephir_read_property(&_2$$3, this_ptr, ZEND_STRL("storageDir"), PH_NOISY_CC | PH_READONLY);
		ZVAL_LONG(&_3$$3, 0777);
		ZEPHIR_CALL_FUNCTION(NULL, "mkdir", NULL, 281, &_2$$3, &_3$$3, &__$true);
		zephir_check_call_status();
	}
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_Queue_Adapter_Stream_StreamContext, getFilepath)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval queueName_zv, _0, _1, _2, _3;
	zend_string *queueName = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&queueName_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(queueName)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&queueName_zv);
	ZVAL_STR_COPY(&queueName_zv, queueName);
	zephir_read_property(&_0, this_ptr, ZEND_STRL("storageDir"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "/[^a-zA-Z0-9_-]/");
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "_");
	ZEPHIR_CALL_FUNCTION(&_3, "preg_replace", NULL, 90, &_1, &_2, &queueName_zv);
	zephir_check_call_status();
	ZEPHIR_CONCAT_VVS(return_value, &_0, &_3, ".queue");
	RETURN_MM();
}

