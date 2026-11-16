
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
#include "kernel/memory.h"
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/exception.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * A closure-based registry for named forms and element type factories.
 *
 * **Form registry** (`get`/`has`/`set`):
 * Each entry is a callable `fn(?object $entity): Form`. Without an entity the
 * resolved form is cached; with an entity a fresh form is always produced.
 *
 * **Element registry** (`getElement`/`hasElement`/`setElement`):
 * Maps type strings (e.g. 'text', 'email') to factories used by Form::load().
 * Each callable has the signature `fn(string $name, array $options, array $attributes): ElementInterface`.
 * Default types are seeded by `getDefaultServices()`. Users may add or override
 * types with `setElement()`.
 *
 * @phpstan-import-type forms_locator_element_factory from FormsTypes
 * @phpstan-import-type forms_locator_elements from FormsTypes
 * @phpstan-import-type forms_locator_factories from FormsTypes
 * @phpstan-import-type forms_locator_factory from FormsTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Forms_FormsLocator)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\Forms, FormsLocator, phalcon, forms_formslocator, phalcon_forms_formslocator_method_entry, 0);

	/**
	 * Element type → factory callable.
	 *
	 * @phpstan-var forms_locator_elements
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_forms_formslocator_ce, SL("elements"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Form name → factory callable.
	 *
	 * @phpstan-var forms_locator_factories
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_forms_formslocator_ce, SL("factories"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * Cached entity-less form instances.
	 *
	 * @phpstan-var array<string, Form>
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_forms_formslocator_ce, SL("instances"), &_zc0, ZEND_ACC_PRIVATE, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
 * @phpstan-param forms_locator_factories $definitions
 */
PHP_METHOD(Phalcon_Forms_FormsLocator, __construct)
{
	zend_bool _5;
	zend_string *_3;
	zend_ulong _2;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *definitions_param = NULL, name, definition, _0, *_1, _4;
	zval definitions;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&definitions);
	ZVAL_UNDEF(&name);
	ZVAL_UNDEF(&definition);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_4);
	ZEND_TLS zephir_method_cache _zephir_call_cache[8];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(0, 1)
		Z_PARAM_OPTIONAL
		ZEPHIR_Z_PARAM_ARRAY(definitions, definitions_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 0, 1, &definitions_param);
	if (!definitions_param) {
		ZEPHIR_INIT_VAR(&definitions);
		array_init(&definitions);
	} else {
		zephir_get_arrval(&definitions, definitions_param);
	}
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "getDefaultServices", &_zephir_call_cache[0]);
	zephir_check_call_status();
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 813, &_0);
	zephir_is_iterable(&definitions, 0, "phalcon/Forms/FormsLocator.zep", 85);
	if (Z_TYPE_P(&definitions) == IS_ARRAY) {
		ZEND_HASH_FOREACH_KEY_VAL(Z_ARRVAL_P(&definitions), _2, _3, _1)
		{
			ZEPHIR_INIT_NVAR(&name);
			if (_3 != NULL) { 
				ZVAL_STR_COPY(&name, _3);
			} else {
				ZVAL_LONG(&name, _2);
			}
			ZEPHIR_INIT_NVAR(&definition);
			ZVAL_COPY(&definition, _1);
			ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "set", &_zephir_call_cache[1], &name, &definition);
			zephir_check_call_status();
		} ZEND_HASH_FOREACH_END();
	} else {
		ZEPHIR_CALL_METHOD_CACHED(NULL, &definitions, "rewind", &_zephir_call_cache[2]);
		zephir_check_call_status();
		_5 = 1;
		while (1) {
			if (_5) {
				_5 = 0;
			} else {
				ZEPHIR_CALL_METHOD_CACHED(NULL, &definitions, "next", &_zephir_call_cache[3]);
				zephir_check_call_status();
			}
			ZEPHIR_CALL_METHOD_CACHED(&_4, &definitions, "valid", &_zephir_call_cache[4]);
			zephir_check_call_status();
			if (!zend_is_true(&_4)) {
				break;
			}
			ZEPHIR_CALL_METHOD_CACHED(&name, &definitions, "key", &_zephir_call_cache[5]);
			zephir_check_call_status();
			ZEPHIR_CALL_METHOD_CACHED(&definition, &definitions, "current", &_zephir_call_cache[6]);
			zephir_check_call_status();
				ZEPHIR_CALL_METHOD_CACHED(NULL, this_ptr, "set", &_zephir_call_cache[7], &name, &definition);
				zephir_check_call_status();
		}
	}
	ZEPHIR_INIT_NVAR(&definition);
	ZEPHIR_INIT_NVAR(&name);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the named form.
 *
 * Without an entity the result is lazily created and cached.
 * With an entity a fresh form is always produced.
 *
 * @param object|null $entity
 *
 * @throws Exception
 */
PHP_METHOD(Phalcon_Forms_FormsLocator, get)
{
	zend_bool _4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval name_zv, *entity = NULL, entity_sub, __$null, factory, instance, _0, _2, _3, _1$$3, _5$$5;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&entity_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&factory);
	ZVAL_UNDEF(&instance);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_5$$5);
	ZEND_TLS zephir_method_cache _zephir_call_cache[2];
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("factories", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("instances", 9, 1);
	}

	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_STR(name)
		Z_PARAM_OPTIONAL
		Z_PARAM_ZVAL_OR_NULL(entity)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 1) {
		entity = ZEND_CALL_ARG(execute_data, 2);
	}
	zephir_memory_observe(&name_zv);
	ZVAL_STR_COPY(&name_zv, name);
	if (!entity) {
		entity = &entity_sub;
		entity = &__$null;
	}
	ZEPHIR_CALL_METHOD_CACHED(&_0, this_ptr, "has", &_zephir_call_cache[0], &name_zv);
	zephir_check_call_status();
	if (!(zephir_is_true(&_0))) {
		ZEPHIR_INIT_VAR(&_1$$3);
		object_init_ex(&_1$$3, phalcon_forms_exceptions_formnotinlocator_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_1$$3, "__construct", &_zephir_call_cache[1], &name_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_1$$3, "phalcon/Forms/FormsLocator.zep", 102);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_2, this_ptr, _zephir_prop_0, 814, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&factory);
	zephir_array_fetch(&factory, &_2, &name_zv, PH_NOISY, "phalcon/Forms/FormsLocator.zep", 105);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (Z_TYPE_P(entity) != IS_NULL) {
		ZEPHIR_RETURN_CALL_ZVAL_FUNCTION(&factory, NULL, 0, entity);
		zephir_check_call_status();
		RETURN_MM();
	}
	zephir_memory_observe(&instance);
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_1, 815, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_4 = zephir_array_isset_fetch(&instance, &_3, &name_zv, 0);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_4)) {
		ZVAL_NULL(&_5$$5);
		ZEPHIR_CALL_ZVAL_FUNCTION(&instance, &factory, NULL, 0, &_5$$5);
		zephir_check_call_status();
		zephir_update_property_array(this_ptr, SL("instances"), &name_zv, &instance);
		if (UNEXPECTED(EG(exception))) {
			ZEPHIR_MM_RESTORE();
			return;
		}
	}
	RETURN_CCTOR(&instance);
}

/**
 * Returns the factory callable for the given element type.
 *
 * @phpstan-return forms_locator_element_factory
 */
PHP_METHOD(Phalcon_Forms_FormsLocator, getElement)
{
	zend_bool _1;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval type_zv, _0, _3, _4, _2$$3;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_2$$3);
	ZEND_TLS zephir_method_cache _zephir_call_cache[1];
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&type_zv);
	ZVAL_STR_COPY(&type_zv, type);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 813, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	_1 = zephir_array_isset_value(&_0, &type_zv);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	if (!(_1)) {
		ZEPHIR_INIT_VAR(&_2$$3);
		object_init_ex(&_2$$3, phalcon_forms_exceptions_unknownformelementtype_ce);
		ZEPHIR_CALL_METHOD_CACHED(NULL, &_2$$3, "__construct", &_zephir_call_cache[0], &type_zv);
		zephir_check_call_status();
		zephir_throw_exception_debug(&_2$$3, "phalcon/Forms/FormsLocator.zep", 127);
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_read_property_cached(&_3, this_ptr, _zephir_prop_0, 813, PH_NOISY_CC | PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	zephir_memory_observe(&_4);
	zephir_array_fetch(&_4, &_3, &type_zv, PH_NOISY, "phalcon/Forms/FormsLocator.zep", 130);
	if (UNEXPECTED(EG(exception))) {
		ZEPHIR_MM_RESTORE();
		return;
	}
	RETURN_CCTOR(&_4);
}

/**
 * Checks whether a named form factory is registered.
 */
PHP_METHOD(Phalcon_Forms_FormsLocator, has)
{
	zend_bool _1;
	zval name_zv, _0;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("factories", 9, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(name)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&name_zv, name);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 814, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	_1 = zephir_array_isset_value(&_0, &name_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(_1);
}

/**
 * Checks whether an element type is registered.
 */
PHP_METHOD(Phalcon_Forms_FormsLocator, hasElement)
{
	zend_bool _1;
	zval type_zv, _0;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("elements", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(type)
	ZEND_PARSE_PARAMETERS_END();
	ZVAL_STR(&type_zv, type);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 813, PH_READONLY);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	_1 = zephir_array_isset_value(&_0, &type_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	RETURN_BOOL(_1);
}

/**
 * Registers or replaces a named form factory.
 *
 * The callable must accept one argument (?object $entity) and return a
 * Form instance. Replacing a registration clears any cached instance so
 * the next get() call rebuilds from the new factory.
 *
 * @phpstan-param forms_locator_factory $factory
 */
PHP_METHOD(Phalcon_Forms_FormsLocator, set)
{
	zval name_zv, *factory, factory_sub;
	zend_string *name = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&name_zv);
	ZVAL_UNDEF(&factory_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(name)
		Z_PARAM_ZVAL(factory)
	ZEND_PARSE_PARAMETERS_END();
	factory = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&name_zv, name);
	zephir_unset_property_array(this_ptr, ZEND_STRL("instances"), &name_zv);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
	zephir_update_property_array(this_ptr, SL("factories"), &name_zv, factory);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
}

/**
 * Registers or replaces an element type factory.
 *
 * The callable must accept (string $name, array $options, array $attributes)
 * and return an ElementInterface instance.
 *
 * @phpstan-param forms_locator_element_factory $factory
 */
PHP_METHOD(Phalcon_Forms_FormsLocator, setElement)
{
	zval type_zv, *factory, factory_sub;
	zend_string *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&factory_sub);
	ZEND_PARSE_PARAMETERS_START(2, 2)
		Z_PARAM_STR(type)
		Z_PARAM_ZVAL(factory)
	ZEND_PARSE_PARAMETERS_END();
	factory = ZEND_CALL_ARG(execute_data, 2);
	ZVAL_STR(&type_zv, type);
	zephir_update_property_array(this_ptr, SL("elements"), &type_zv, factory);
	if (UNEXPECTED(EG(exception))) {
		return;
	}
}

/**
 * Returns the built-in element type factories.
 *
 * Each value is a callable: fn(string $name, array $options, array $attributes): ElementInterface
 *
 * @phpstan-return forms_locator_elements
 */
PHP_METHOD(Phalcon_Forms_FormsLocator, getDefaultServices)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_create_array(return_value, 14, 0);
	ZEPHIR_INIT_VAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_19__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("check"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_20__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("checkgroup"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_21__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("date"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_22__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("email"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_23__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("file"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_24__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("hidden"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_25__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("numeric"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_26__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("password"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_27__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("radio"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_28__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("radiogroup"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_29__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("select"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_30__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("submit"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_31__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("text"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_INIT_NVAR(&_0);
	ZEPHIR_INIT_NVAR(&_0);
	zephir_create_closure_ex(&_0, NULL, phalcon_32__closure_ce, SL("__invoke"));
	zephir_array_update_string(return_value, SL("textarea"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

