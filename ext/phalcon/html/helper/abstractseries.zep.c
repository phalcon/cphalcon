
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
 * @phpstan-import-type html_attributes from HtmlTypes
 * @phpstan-import-type html_element_entry from HtmlTypes
 * @phpstan-import-type html_element_store from HtmlTypes
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_AbstractSeries)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, AbstractSeries, phalcon, html_helper_abstractseries, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_abstractseries_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @phpstan-var html_attributes
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_helper_abstractseries_ce, SL("attributes"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	/**
	 * @phpstan-var html_element_store
	 */
	{
		zval _zc0;
		array_init_size(&_zc0, 1);
		zephir_declare_typed_property(phalcon_html_helper_abstractseries_ce, SL("store"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_ARRAY, NULL, 0);
	}

	return SUCCESS;
}

/**
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
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("delimiter", 9, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("indent", 6, 1);
	}

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
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 77, &_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 78, &indent_zv);
	RETURN_THIS();
}

/**
 * Generates and returns the HTML for the list. Entries are sorted by
 * their integer key first, so an asset registered with a lower position
 * renders before one registered with a higher position regardless of
 * registration order.
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractSeries, __toString)
{
	zval sorted, _0;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&sorted);
	ZVAL_UNDEF(&_0);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("store", 5, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("delimiter", 9, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_memory_observe(&sorted);
	zephir_read_property_cached(&sorted, this_ptr, _zephir_prop_0, 79, PH_NOISY_CC);
	ZEPHIR_MAKE_REF(&sorted);
	ZEPHIR_CALL_FUNCTION(NULL, "ksort", NULL, 71, &sorted);
	ZEPHIR_UNREF(&sorted);
	zephir_check_call_status();
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_1, 77, PH_NOISY_CC | PH_READONLY);
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("store", 5, 1);
	}
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	ZEPHIR_INIT_VAR(&_0);
	array_init(&_0);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 79, &_0);
	RETURN_THIS();
}

/**
 * Returns the tag name.
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractSeries, getTag)
{
}

/**
 * Appends an entry to the store, optionally at a specific integer
 * position. When `$pos` is negative the entry is pushed onto the next
 * available auto-increment slot. When `$pos` is non-negative the entry
 * is placed at that key, advancing past any already-occupied slots so
 * existing entries are not overwritten. The store is ksort()ed in
 * `__toString`, so positions act as a sort key, not a strict address.
 *
 * @phpstan-param html_element_entry $entry
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
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("store", 5, 1);
	}

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
		zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 79, PH_NOISY_CC | PH_READONLY);
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

