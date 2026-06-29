
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
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
/**
 * @property InterpolatorFactory $interpolator
 *
 * @psalm-type TConfig array{
 *      adapter: string,
 *      options?: array{
 *          content: string,
 *          delimiter: string,
 *          enclosure: string,
 *          locale: string,
 *          defaultDomain: string,
 *          directory: string,
 *          category: string,
 *          triggerError: bool,
 *      }
 *  }
 */
ZEPHIR_INIT_CLASS(Phalcon_Translate_TranslateFactory)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Translate, TranslateFactory, phalcon, translate_translatefactory, phalcon_factory_abstractfactory_ce, phalcon_translate_translatefactory_method_entry, 0);

	/**
	 * @var InterpolatorFactory
	 */
	zend_declare_property_null(phalcon_translate_translatefactory_ce, SL("interpolator"), ZEND_ACC_PRIVATE);
	return SUCCESS;
}

/**
 * @phpstan-param array<string, string> $services
 */
PHP_METHOD(Phalcon_Translate_TranslateFactory, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval services;
	zval *interpolator, interpolator_sub, *services_param = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&interpolator_sub);
	ZVAL_UNDEF(&services);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(interpolator, phalcon_translate_interpolatorfactory_ce)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(services, services_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &interpolator, &services_param);
	if (!services_param) {
		ZEPHIR_INIT_VAR(&services);
		array_init(&services);
	} else {
		zephir_get_arrval(&services, services_param);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("interpolator"), interpolator);
	ZEPHIR_CALL_METHOD(NULL, this_ptr, "init", NULL, 0, &services);
	zephir_check_call_status();
	ZEPHIR_MM_RESTORE();
}

/**
 * Factory to create an instance from a Config object
 *
 * @param ConfigInterface|TConfig $config
 *
 * @return AdapterInterface
 * @throws Exception
 */
PHP_METHOD(Phalcon_Translate_TranslateFactory, load)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *config = NULL, config_sub, name, options, _0, _1;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&config_sub);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_ZVAL(config)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &config);
	ZEPHIR_SEPARATE_PARAM(config);
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkconfig", NULL, 0, config);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, &_0);
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_STRING(&_1, "adapter");
	ZEPHIR_CALL_METHOD(&_0, this_ptr, "checkconfigelement", NULL, 0, config, &_1);
	zephir_check_call_status();
	ZEPHIR_CPY_WRT(config, &_0);
	zephir_memory_observe(&name);
	zephir_array_fetch_string(&name, config, SL("adapter"), PH_NOISY, "phalcon/Translate/TranslateFactory.zep", 67);
	zephir_memory_observe(&options);
	if (!(zephir_array_isset_string_fetch(&options, config, SL("options"), 0))) {
		ZEPHIR_INIT_NVAR(&options);
		array_init(&options);
	}
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "newinstance", NULL, 0, &name, &options);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Create a new instance of the adapter
 *
 * @phpstan-param array<string, mixed> $options
 *
 * @return AdapterInterface
 */
PHP_METHOD(Phalcon_Translate_TranslateFactory, newInstance)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval options, _0;
	zval name_zv, *options_param = NULL, definition, _1;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&options);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(options, options_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		options_param = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!options_param) {
		ZEPHIR_INIT_VAR(&options);
		array_init(&options);
	} else {
		zephir_get_arrval(&options, options_param);
	}
	ZEPHIR_CALL_METHOD(&definition, this_ptr, "getservice", NULL, 0, &name_zv);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_0);
	zephir_create_array(&_0, 2, 0);
	zephir_memory_observe(&_1);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("interpolator"), PH_NOISY_CC);
	zephir_array_fast_append(&_0, &_1);
	zephir_array_fast_append(&_0, &options);
	ZEPHIR_LAST_CALL_STATUS = zephir_create_instance_params(return_value, &definition, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * @return string
 */
PHP_METHOD(Phalcon_Translate_TranslateFactory, getExceptionClass)
{

	RETURN_STRING("Phalcon\\Translate\\Exceptions\\TranslatorNotRegistered");
}

/**
 * Returns the available adapters
 *
 * @return string[]
 */
PHP_METHOD(Phalcon_Translate_TranslateFactory, getServices)
{

	zephir_create_array(return_value, 3, 0);
	add_assoc_stringl_ex(return_value, SL("csv"), SL("Phalcon\\Translate\\Adapter\\Csv"));
	add_assoc_stringl_ex(return_value, SL("gettext"), SL("Phalcon\\Translate\\Adapter\\Gettext"));
	add_assoc_stringl_ex(return_value, SL("array"), SL("Phalcon\\Translate\\Adapter\\NativeArray"));
	return;
}

