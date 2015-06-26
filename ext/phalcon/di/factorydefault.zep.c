
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

	zval *_2 = NULL, *_3 = NULL, *_4 = NULL, _5 = zval_used_for_init;
	zval *_1;
	int ZEPHIR_LAST_CALL_STATUS;
	zephir_fcall_cache_entry *_0 = NULL, *_6 = NULL;

	ZEPHIR_MM_GROW();

	ZEPHIR_CALL_PARENT(NULL, phalcon_di_factorydefault_ce, this_ptr, "__construct", &_0, 145);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(_1);
	zephir_create_array(_1, 21, 0 TSRMLS_CC);
	ZEPHIR_INIT_VAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_VAR(_3);
	ZVAL_STRING(_3, "router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_VAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Router", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_VAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("router"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Dispatcher", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("dispatcher"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "url", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Url", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("url"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "modelsManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Model\\Manager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("modelsManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "modelsMetadata", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Model\\MetaData\\Memory", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("modelsMetadata"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "response", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Http\\Response", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("response"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "cookies", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Http\\Response\\Cookies", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("cookies"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Http\\Request", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("request"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "filter", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Filter", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("filter"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "escaper", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Escaper", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("escaper"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "security", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Security", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("security"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "crypt", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Crypt", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("crypt"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "annotations", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Annotations\\Adapter\\Memory", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("annotations"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "flash", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Flash\\Direct", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("flash"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "flashSession", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Flash\\Session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("flashSession"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "tag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Tag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("tag"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "session", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Session\\Adapter\\Files", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("session"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "sessionBag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Session\\Bag", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("sessionBag"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "eventsManager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Events\\Manager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("eventsManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "transactions", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Mvc\\Model\\Transaction\\Manager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("transactionManager"), &_2, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(_2);
	object_init_ex(_2, phalcon_di_service_ce);
	ZEPHIR_INIT_NVAR(_3);
	ZVAL_STRING(_3, "assets", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_INIT_NVAR(_4);
	ZVAL_STRING(_4, "Phalcon\\Assets\\Manager", ZEPHIR_TEMP_PARAM_COPY);
	ZEPHIR_SINIT_NVAR(_5);
	ZVAL_BOOL(&_5, 1);
	ZEPHIR_CALL_METHOD(NULL, _2, "__construct", &_6, 141, _3, _4, &_5);
	zephir_check_temp_parameter(_3);
	zephir_check_temp_parameter(_4);
	zephir_check_call_status();
	zephir_array_update_string(&_1, SL("assets"), &_2, PH_COPY | PH_SEPARATE);
	zephir_update_property_this(this_ptr, SL("_services"), _1 TSRMLS_CC);
	ZEPHIR_MM_RESTORE();

}

