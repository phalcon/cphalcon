
#ifdef HAVE_CONFIG_H
#include "../../../ext_config.h"
#endif

#include <php.h>
#include "../../../php_ext.h"
#include "../../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/operators.h"
#include "kernel/object.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 *
 * Implementation of this file has been influenced by AuraPHP
 * @link    https://github.com/auraphp/Aura.Html
 * @license https://github.com/auraphp/Aura.Html/blob/2.x/LICENSE
 */
/**
 * @property array $attributes
 * @property array $store
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_AbstractSeries)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, AbstractSeries, phalcon, html_helper_abstractseries, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_abstractseries_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_abstractseries_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_abstractseries_ce, SL("store"), ZEND_ACC_PROTECTED);
	phalcon_html_helper_abstractseries_ce->create_object = zephir_init_properties_Phalcon_Html_Helper_AbstractSeries;

	return SUCCESS;
}

/**
 * @param string $indent
 * @param string $delimiter
 *
 * @return static
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractSeries, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval indent_zv, delimiter_zv, _0;
	zend_string *indent = NULL, *delimiter = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&indent_zv);
	ZVAL_UNDEF(&delimiter_zv);
	ZVAL_UNDEF(&_0);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 2)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(indent)
		Z_PARAM_STR_OR_NULL(delimiter)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (!indent) {
		indent = zend_string_init(ZEND_STRL("    "), 0);
		zephir_memory_observe(&indent_zv);
		ZVAL_STR(&indent_zv, indent);
	} else {
		zephir_memory_observe(&indent_zv);
	ZVAL_STR_COPY(&indent_zv, indent);
	}
	if (!delimiter) {
		ZEPHIR_INIT_VAR(&delimiter_zv);
	} else {
		zephir_memory_observe(&delimiter_zv);
	ZVAL_STR_COPY(&delimiter_zv, delimiter);
	}
	ZEPHIR_INIT_VAR(&_0);
	if (Z_TYPE_P(&delimiter_zv) == IS_NULL) {
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	} else {
		ZEPHIR_CPY_WRT(&_0, &delimiter_zv);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("delimiter"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("indent"), &indent_zv);
	RETURN_THIS();
}

/**
 * Generates and returns the HTML for the list. Entries are sorted by
 * their integer key first, so an asset registered with a lower position
 * renders before one registered with a higher position regardless of
 * registration order.
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractSeries, __toString)
{
	zval sorted, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sorted);
	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&sorted);
	zephir_read_property(&sorted, this_ptr, ZEND_STRL("store"), PH_NOISY_CC);
	ZEPHIR_MAKE_REF(&sorted);
	ZEPHIR_CALL_FUNCTION(NULL, "ksort", NULL, 72, &sorted);
	ZEPHIR_UNREF(&sorted);
	zephir_check_call_status();
	zephir_read_property(&_0, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderarrayelements", NULL, 0, &sorted, &_0);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 * Resets the internal store.
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractSeries, reset)
{
	zval _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&_0);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("store"), &_0);
	RETURN_THIS();
}

/**
 * Appends an entry to the store, optionally at a specific integer
 * position. When `position` is negative the entry is pushed onto the next
 * available auto-increment slot. When `position` is non-negative the entry
 * is placed at that key, advancing past any already-occupied slots so
 * existing entries are not overwritten. The store is ksort()ed in
 * `__toString`, so positions act as a sort key, not a strict address.
 *
 * @param array $entry
 * @param int   $position
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractSeries, pushOrPlace)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long position, key = 0;
	zval *entry_param = NULL, *position_param = NULL, _0, _1;
	zval entry;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&entry);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZEND_PARSE_PARAMETERS_START(1, 2)
		ZEPHIR_Z_PARAM_ARRAY(entry, entry_param)
		Z_PARAM_OPTIONAL
		Z_PARAM_LONG(position)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &entry_param, &position_param);
	zephir_get_arrval(&entry, entry_param);
	if (!position_param) {
		position = -1;
	} else {
		}
	if (position < 0) {
		zephir_update_property_array_append(this_ptr, SL("store"), &entry);
		RETURN_MM_NULL();
	}
	key = position;
	while (1) {
		zephir_read_property(&_0, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
		if (!(zephir_array_isset_value_long(&_0, key))) {
			break;
		}
		key += 1;
	}
	ZEPHIR_INIT_VAR(&_1);
	ZVAL_LONG(&_1, key);
	zephir_update_property_array(this_ptr, SL("store"), &_1, &entry);
	ZEPHIR_MM_RESTORE();
}

/**
 * Returns the tag name.
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractSeries, getTag)
{
}

zend_object *zephir_init_properties_Phalcon_Html_Helper_AbstractSeries(zend_class_entry *class_type)
{
		zval _0, _2, _1$$3, _3$$4;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
		ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_1$$3);
	ZVAL_UNDEF(&_3$$4);
	

		ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
		zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	
	{
		zval local_this_ptr, *this_ptr = &local_this_ptr;
		ZEPHIR_CREATE_OBJECT(this_ptr, class_type);
		zephir_read_property_ex(&_0, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_0) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_1$$3);
			array_init(&_1$$3);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("store"), &_1$$3);
		}
		zephir_read_property_ex(&_2, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
		if (Z_TYPE_P(&_2) == IS_NULL) {
			ZEPHIR_INIT_VAR(&_3$$4);
			array_init(&_3$$4);
			zephir_update_property_zval_ex(this_ptr, ZEND_STRL("attributes"), &_3$$4);
		}
		ZEPHIR_MM_RESTORE();
		return Z_OBJ_P(this_ptr);
	}
}

