
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
 * Phalcon\Di\FactoryDefault
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the developer does not need
 * to register each service individually providing a full stack framework
 */
ZEPHIR_INIT_CLASS(Phalcon_Di_FactoryDefault) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Di, FactoryDefault, phalcon, di_factorydefault, phalcon_di_ce, phalcon_di_factorydefault_method_entry, 0);

	return SUCCESS;

}

/**
 * Phalcon\Di\FactoryDefault constructor
 */
PHP_METHOD(Phalcon_Di_FactoryDefault, __construct) {

	zval _2, _3, _4, _5;
	zval _1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_6 = NULL;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phalcon_di_factorydefault_ce, this_ptr, "__construct", &_0, 79);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_1);
	zephir_create_array(&_1, 21, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_VAR(&_3);
	ZVAL_STRING(&_3, "router");
	ZEPHIR_INIT_VAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Mvc\\Router");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("router"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "dispatcher");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Mvc\\Dispatcher");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("dispatcher"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "url");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Mvc\\Url");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("url"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "modelsManager");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Mvc\\Model\\Manager");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("modelsManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "modelsMetadata");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Mvc\\Model\\MetaData\\Memory");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("modelsMetadata"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "response");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Http\\Response");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("response"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "cookies");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Http\\Response\\Cookies");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("cookies"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "request");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Http\\Request");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("request"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "filter");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Filter");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("filter"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "escaper");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Escaper");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("escaper"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "security");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Security");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("security"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "crypt");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Crypt");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("crypt"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "annotations");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Annotations\\Adapter\\Memory");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("annotations"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "flash");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Flash\\Direct");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("flash"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "flashSession");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Flash\\Session");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("flashSession"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "tag");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Tag");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("tag"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "session");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Session\\Adapter\\Files");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("session"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "sessionBag");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Session\\Bag");
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("sessionBag"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "eventsManager");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Events\\Manager");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("eventsManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "transactionManager");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Mvc\\Model\\Transaction\\Manager");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("transactionManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_2);
	object_init_ex(&_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(&_3);
	ZVAL_STRING(&_3, "assets");
	ZEPHIR_INIT_NVAR(&_4);
	ZVAL_STRING(&_4, "Phalcon\\Assets\\Manager");
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, &_2, "__construct", &_6, 67, &_3, &_4, &_5);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("assets"), &_2, PH_COPY | PH_SEPARATE);
	zephir_update_property_zval(this_ptr, SL("_services"), &_1);
	ZEPHIR_MM_RESTORE();

}

