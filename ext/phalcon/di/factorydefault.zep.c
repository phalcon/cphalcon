
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
	zval _0, _4, _5, _6, _8;
	zval filter, _1, _2, _3, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&filter);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_7);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_CALL_PARENT(NULL, phalcon_di_factorydefault_ce, getThis(), "__construct", NULL, 0);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&filter);
	object_init_ex(&filter, phalcon_filter_filterfactory_ce);
	if (zephir_has_constructor(&filter)) {
		ZEPHIR_CALL_METHOD(NULL, &filter, "__construct", NULL, 0);
		zephir_check_call_status();
	}

	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 20, 0);
	ZEPHIR_INIT_VAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_VAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Annotations\\Adapter\\Memory");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("annotations"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_VAR(&_4);
	zephir_create_array(&_4, 2, 0);
	add_assoc_stringl_ex(&_4, SL("className"), SL("Phalcon\\Assets\\Manager"));
	ZEPHIR_INIT_VAR(&_5);
	zephir_create_array(&_5, 1, 0);
	ZEPHIR_INIT_VAR(&_6);
	zephir_create_array(&_6, 2, 0);
	add_assoc_stringl_ex(&_6, SL("type"), SL("service"));
	add_assoc_stringl_ex(&_6, SL("name"), SL("tag"));
	zephir_array_fast_append(&_5, &_6);
	zephir_array_update_string(&_4, SL("arguments"), &_5, PH_COPY | PH_SEPARATE);
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_4, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("assets"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Encryption\\Crypt");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("crypt"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Http\\Response\\Cookies");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("cookies"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Mvc\\Dispatcher");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("dispatcher"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Html\\Escaper");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("escaper"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Events\\Manager");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("eventsManager"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Flash\\Direct");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("flash"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Flash\\Session");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("flashSession"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_CALL_METHOD(&_7, &filter, "newinstance", NULL, 94);
	zephir_check_call_status();
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_7, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("filter"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Support\\HelperFactory");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("helper"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Mvc\\Model\\Manager");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("modelsManager"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Mvc\\Model\\MetaData\\Memory");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("modelsMetadata"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Http\\Request");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("request"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Http\\Response");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("response"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Mvc\\Router");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("router"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Encryption\\Security");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("security"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_5);
	zephir_create_array(&_5, 2, 0);
	add_assoc_stringl_ex(&_5, SL("className"), SL("Phalcon\\Html\\TagFactory"));
	ZEPHIR_INIT_NVAR(&_6);
	zephir_create_array(&_6, 1, 0);
	ZEPHIR_INIT_VAR(&_8);
	zephir_create_array(&_8, 2, 0);
	add_assoc_stringl_ex(&_8, SL("type"), SL("service"));
	add_assoc_stringl_ex(&_8, SL("name"), SL("escaper"));
	zephir_array_fast_append(&_6, &_8);
	zephir_array_update_string(&_5, SL("arguments"), &_6, PH_COPY | PH_SEPARATE);
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_5, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("tag"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Mvc\\Model\\Transaction\\Manager");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("transactionManager"), &_1, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_1);
	object_init_ex(&_1, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_2);
	ZVAL_STRING(&_2, "Phalcon\\Mvc\\Url");
	ZVAL_BOOL(&_3, 1);
	ZEPHIR_CALL_METHOD(NULL, &_1, "__construct", NULL, 77, &_2, &_3);
	zephir_check_call_status();
	zephir_array_update_string(&_0, SL("url"), &_1, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, ZEND_STRL("services"), &_0);
	ZEPHIR_MM_RESTORE();
}

