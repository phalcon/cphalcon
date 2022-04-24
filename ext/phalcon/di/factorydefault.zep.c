
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
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/object.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * This is a variant of the standard Phalcon\Di\Di. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the
 * developer does not need to register each service individually providing a
 * full stack framework
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_FactoryDefault)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Di, FactoryDefault, phalcon, di_factorydefault, phalcon_di_di_ce, phalcon_di_factorydefault_method_entry, 0);

	return SUCCESS;
}

/**
 * Phalcon\Di\FactoryDefault constructor
 */
PHP_METHOD(Phalcon_Di_FactoryDefault, __construct)
{
	zval _1, _5, _6, _7, _9;
	zval filter, _2, _3, _4, _8;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_9);


	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phalcon_di_factorydefault_ce, getThis(), "__construct", &_0, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&filter);
	object_init_ex(&filter, phalcon_filter_filterfactory_ce);
	if (zephir_has_constructor(&filter)) {
		ZEPHIR_CALL_METHOD(NULL, &filter, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 20, 0);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Annotations\\Adapter\\Memory");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("annotations"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 2, 0);
	add_assoc_stringl_ex(&_5, SL("className"), SL("Phalcon\\Assets\\Manager"));
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 1, 0);
	ZEPHIR_INIT_VAR(&_7);
	zephir_create_array(&_7, 2, 0);
	add_assoc_stringl_ex(&_7, SL("type"), SL("service"));
	add_assoc_stringl_ex(&_7, SL("name"), SL("tag"));
	zephir_array_fast_append(&_6, &_7);
	zephir_array_update_string(&_5, SL("arguments"), &_6, PH_COPY | PH_SEPARATE);
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_5, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("assets"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Encryption\\Crypt");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("crypt"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Http\\Response\\Cookies");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("cookies"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Mvc\\Dispatcher");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("dispatcher"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Html\\Escaper");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("escaper"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Events\\Manager");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("eventsManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Flash\\Direct");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("flash"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Flash\\Session");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("flashSession"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_CALL_METHOD(&_8, &filter, "newinstance", NULL, 122);
	zephir_check_call_status();
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_8, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("filter"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Support\\HelperFactory");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("helper"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Mvc\\Model\\Manager");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("modelsManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Mvc\\Model\\MetaData\\Memory");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("modelsMetadata"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Http\\Request");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("request"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Http\\Response");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("response"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Mvc\\Router");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("router"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Encryption\\Security");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("security"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_6);
	zephir_create_array(&_6, 2, 0);
	add_assoc_stringl_ex(&_6, SL("className"), SL("Phalcon\\Html\\TagFactory"));
	ZEPHIR_INIT_NVAR(&_7);
	zephir_create_array(&_7, 1, 0);
	ZEPHIR_INIT_VAR(&_9);
	zephir_create_array(&_9, 2, 0);
	add_assoc_stringl_ex(&_9, SL("type"), SL("service"));
	add_assoc_stringl_ex(&_9, SL("name"), SL("escaper"));
	zephir_array_fast_append(&_7, &_9);
	zephir_array_update_string(&_6, SL("arguments"), &_7, PH_COPY | PH_SEPARATE);
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_6, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("tag"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Mvc\\Model\\Transaction\\Manager");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("transactionManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "Phalcon\\Mvc\\Url");
	ZVAL_BOOL(&_4, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", NULL, 105, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("url"), &_2, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("services"), &_1);
	ZEPHIR_MM_RESTORE();
}

