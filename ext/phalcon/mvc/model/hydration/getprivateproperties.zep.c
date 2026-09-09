
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
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/fcall.h"
#include "kernel/string.h"
#include "kernel/operators.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Model_Hydration_GetPrivateProperties)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Mvc\\Model\\Hydration, GetPrivateProperties, phalcon, mvc_model_hydration_getprivateproperties, phalcon_mvc_model_hydration_getprivateproperties_method_entry, 0);

	/**
	 * Per-process cache of declared private model properties as
	 * [class name => [property name => ReflectionProperty]], used during
	 * hydration - see getPrivateProperties()
	 *
	 * @var array
	 *
	 * @phpstan-var array<class-string, array<string, \ReflectionProperty>>
	 */
	zend_declare_property_null(phalcon_mvc_model_hydration_getprivateproperties_ce, SL("privatePropertiesCache"), ZEND_ACC_PRIVATE|ZEND_ACC_STATIC);
	return SUCCESS;
}

/**
 * Returns the declared private properties of a class (including inherited
 * ones) as [property name => ReflectionProperty], cached per class.
 *
 * Hydration (cloneResult/cloneResultMap) cannot write private properties
 * directly: the engine write from Model scope falls back to __set(),
 * which invokes a possible setter - or throws for a non-public property
 * without one. Writing through ReflectionProperty stores the raw
 * database value instead.
 *
 * @see https://github.com/phalcon/cphalcon/issues/16454
 *
 * @phpstan-param class-string $className
 */
PHP_METHOD(Phalcon_Mvc_Model_Hydration_GetPrivateProperties, getPrivateProperties)
{
	zend_bool _7$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zephir_fcall_cache_entry *_1 = NULL, *_10 = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval className_zv, cache, privateProperties, propertyName, reflection, reflectionProperties, reflectionProperty, _11, _0$$4, *_2$$4, _3$$4, *_4$$4, _6$$4, _9$$4, _5$$5, _8$$8;
	zend_string *className = NULL;

	ZVAL_UNDEF(&className_zv);
	ZVAL_UNDEF(&cache);
	ZVAL_UNDEF(&privateProperties);
	ZVAL_UNDEF(&propertyName);
	ZVAL_UNDEF(&reflection);
	ZVAL_UNDEF(&reflectionProperties);
	ZVAL_UNDEF(&reflectionProperty);
	ZVAL_UNDEF(&_11);
	ZVAL_UNDEF(&_0$$4);
	ZVAL_UNDEF(&_3$$4);
	ZVAL_UNDEF(&_6$$4);
	ZVAL_UNDEF(&_9$$4);
	ZVAL_UNDEF(&_5$$5);
	ZVAL_UNDEF(&_8$$8);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(className)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&className_zv);
	ZVAL_STR_COPY(&className_zv, className);
	zephir_memory_observe(&cache);
	zephir_read_static_property_ce(&cache, phalcon_mvc_model_hydration_getprivateproperties_ce, SL("privatePropertiesCache"), PH_NOISY_CC);
	if (!(zephir_array_isset_value(&cache, &className_zv))) {
		ZEPHIR_INIT_VAR(&privateProperties);
		array_init(&privateProperties);
		ZEPHIR_INIT_VAR(&reflection);
		object_init_ex(&reflection, zephir_get_internal_ce(SL("reflectionclass")));
		ZEPHIR_CALL_METHOD(NULL, &reflection, "__construct", NULL, 251, &className_zv);
		zephir_check_call_status();
		while (1) {
			if (!(Z_TYPE_P(&reflection) == IS_OBJECT)) {
				break;
			}
			ZVAL_LONG(&_0$$4, 4);
			ZEPHIR_CALL_METHOD(&reflectionProperties, &reflection, "getproperties", &_1, 372, &_0$$4);
			zephir_check_call_status();
			if (Z_TYPE_P(&reflectionProperties) == IS_STRING) {
				ZEPHIR_INIT_NVAR(&_3$$4);
				zephir_string_to_char_array(&_3$$4, &reflectionProperties);
				_2$$4 = &_3$$4;
			} else {
				_2$$4 = &reflectionProperties;
			}
			zephir_is_iterable(_2$$4, 0, "phalcon/Mvc/Model/Hydration/GetPrivateProperties.zep", 69);
			if (Z_TYPE_P(_2$$4) == IS_ARRAY) {
				ZEND_HASH_FOREACH_VAL(Z_ARRVAL_P(_2$$4), _4$$4)
				{
					ZEPHIR_INIT_NVAR(&reflectionProperty);
					ZVAL_COPY(&reflectionProperty, _4$$4);
					ZEPHIR_CALL_METHOD(&_5$$5, &reflectionProperty, "isstatic", NULL, 0);
					zephir_check_call_status();
					if (zephir_is_true(&_5$$5)) {
						continue;
					}
					ZEPHIR_CALL_METHOD(&propertyName, &reflectionProperty, "getname", NULL, 0);
					zephir_check_call_status();
					if (!(zephir_array_isset_value(&privateProperties, &propertyName))) {
						zephir_array_update_zval(&privateProperties, &propertyName, &reflectionProperty, PH_COPY | PH_SEPARATE);
					}
				} ZEND_HASH_FOREACH_END();
			} else {
				ZEPHIR_CALL_METHOD(NULL, _2$$4, "rewind", NULL, 0);
				zephir_check_call_status();
				_7$$4 = 1;
				while (1) {
					if (_7$$4) {
						_7$$4 = 0;
					} else {
						ZEPHIR_CALL_METHOD(NULL, _2$$4, "next", NULL, 0);
						zephir_check_call_status();
					}
					ZEPHIR_CALL_METHOD(&_6$$4, _2$$4, "valid", NULL, 0);
					zephir_check_call_status();
					if (!zend_is_true(&_6$$4)) {
						break;
					}
					ZEPHIR_CALL_METHOD(&reflectionProperty, _2$$4, "current", NULL, 0);
					zephir_check_call_status();
						ZEPHIR_CALL_METHOD(&_8$$8, &reflectionProperty, "isstatic", NULL, 0);
						zephir_check_call_status();
						if (zephir_is_true(&_8$$8)) {
							continue;
						}
						ZEPHIR_CALL_METHOD(&propertyName, &reflectionProperty, "getname", NULL, 0);
						zephir_check_call_status();
						if (!(zephir_array_isset_value(&privateProperties, &propertyName))) {
							zephir_array_update_zval(&privateProperties, &propertyName, &reflectionProperty, PH_COPY | PH_SEPARATE);
						}
				}
			}
			ZEPHIR_INIT_NVAR(&reflectionProperty);
			ZEPHIR_CALL_METHOD(&_9$$4, &reflection, "getparentclass", &_10, 0);
			zephir_check_call_status();
			ZEPHIR_CPY_WRT(&reflection, &_9$$4);
		}
		zephir_array_update_zval(&cache, &className_zv, &privateProperties, PH_COPY | PH_SEPARATE);
		zephir_update_static_property_ce(phalcon_mvc_model_hydration_getprivateproperties_ce, ZEND_STRL("privatePropertiesCache"), &cache);
	}
	zephir_memory_observe(&_11);
	zephir_array_fetch(&_11, &cache, &className_zv, PH_NOISY, "phalcon/Mvc/Model/Hydration/GetPrivateProperties.zep", 76);
	RETURN_CCTOR(&_11);
}

void zephir_init_static_properties_Phalcon_Mvc_Model_Hydration_GetPrivateProperties()
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_static_property_ce(phalcon_mvc_model_hydration_getprivateproperties_ce, ZEND_STRL("privatePropertiesCache"), &_0);
	ZEPHIR_MM_RESTORE();
}

