
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
#include "kernel/object.h"
#include "kernel/operators.h"
#include "kernel/concat.h"
#include "kernel/fcall.h"


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
 * Class AbstractList
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_AbstractList)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, AbstractList, phalcon, html_helper_abstractlist, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_abstractlist_method_entry, ZEND_ACC_EXPLICIT_ABSTRACT_CLASS);

	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_abstractlist_ce, SL("attributes"), ZEND_ACC_PROTECTED);
	/**
	 * @var string
	 */
	zend_declare_property_string(phalcon_html_helper_abstractlist_ce, SL("elementTag"), "li", ZEND_ACC_PROTECTED);
	/**
	 * @var array
	 */
	zend_declare_property_null(phalcon_html_helper_abstractlist_ce, SL("store"), ZEND_ACC_PROTECTED);
	phalcon_html_helper_abstractlist_ce->create_object = zephir_init_properties_Phalcon_Html_Helper_AbstractList;

	return SUCCESS;
}

/**
 * @param string $indent
 * @param string $delimiter
 * @param array  $attributes
 *
 * @return AbstractList
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractList, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval attributes;
	zval indent_zv, delimiter_zv, *attributes_param = NULL, _0, _1;
	zend_string *indent = NULL, *delimiter = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&indent_zv);
	ZVAL_UNDEF(&delimiter_zv);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&attributes);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(0, 3)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(indent)
		Z_PARAM_STR_OR_NULL(delimiter)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		attributes_param = ZEND_CALL_ARG(execute_data, 3);
	}
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
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("attributes"), &attributes);
	ZEPHIR_INIT_VAR(&_0);
	if (ZEPHIR_IS_EMPTY(&delimiter_zv)) {
		ZEPHIR_INIT_NVAR(&_0);
		ZEPHIR_GET_CONSTANT(&_0, "PHP_EOL");
	} else {
		ZEPHIR_CPY_WRT(&_0, &delimiter_zv);
	}
	zephir_update_property_zval(this_ptr, ZEND_STRL("delimiter"), &_0);
	zephir_update_property_zval(this_ptr, ZEND_STRL("indent"), &indent_zv);
	ZEPHIR_INIT_VAR(&_1);
	array_init(&_1);
	zephir_update_property_zval(this_ptr, ZEND_STRL("store"), &_1);
	RETURN_THIS();
}

/**
 * Generates and returns the HTML for the list.
 *
 * @return string
 * @throws Exception
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractList, __toString)
{
	zval contents, _0, _1, _2, _3, _4, _5, _6, _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&contents);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_7);
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);

	zephir_read_property(&_0, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	if (ZEPHIR_IS_EMPTY(&_0)) {
		RETURN_MM_STRING("");
	}
	zephir_read_property(&_1, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_3, this_ptr, ZEND_STRL("store"), PH_NOISY_CC | PH_READONLY);
	zephir_read_property(&_4, this_ptr, ZEND_STRL("delimiter"), PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "renderarrayelements", NULL, 0, &_3, &_4);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&contents);
	ZEPHIR_CONCAT_VV(&contents, &_1, &_2);
	ZEPHIR_CALL_METHOD(&_5, this_ptr, "gettag", NULL, 0);
	zephir_check_call_status();
	zephir_read_property(&_6, this_ptr, ZEND_STRL("attributes"), PH_NOISY_CC | PH_READONLY);
	ZVAL_BOOL(&_7, 1);
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "renderfullelement", NULL, 0, &_5, &contents, &_6, &_7);
	zephir_check_call_status();
	RETURN_MM();
}

/**
 *
 * Returns the tag name.
 *
 * @return string
 *
 */
PHP_METHOD(Phalcon_Html_Helper_AbstractList, getTag)
{
}

zend_object *zephir_init_properties_Phalcon_Html_Helper_AbstractList(zend_class_entry *class_type)
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

