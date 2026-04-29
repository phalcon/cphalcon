
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
#include "kernel/fcall.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "kernel/array.h"
#include "kernel/operators.h"
#include "kernel/concat.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */
/**
 * Generates a <link rel="preload"> tag for resource hinting.
 * If a ResponseInterface is provided, also sets the HTTP Link header.
 */
ZEPHIR_INIT_CLASS(Phalcon_Html_Helper_Preload)
{
	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Html\\Helper, Preload, phalcon, html_helper_preload, phalcon_html_helper_abstracthelper_ce, phalcon_html_helper_preload_method_entry, 0);

	/**
	 * @var ResponseInterface|null
	 */
	zend_declare_property_null(phalcon_html_helper_preload_ce, SL("response"), ZEND_ACC_PROTECTED);
	return SUCCESS;
}

/**
 * @param EscaperInterface      $escaper
 * @param ResponseInterface|null $response
 */
PHP_METHOD(Phalcon_Html_Helper_Preload, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *escaper, escaper_sub, *response = NULL, response_sub, __$null;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&escaper_sub);
	ZVAL_UNDEF(&response_sub);
	ZVAL_NULL(&__$null);
	bool is_null_true = 1;
	ZEND_PARSE_PARAMETERS_START(1, 2)
		Z_PARAM_OBJECT_OF_CLASS(escaper, phalcon_html_escaper_escaperinterface_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_OBJECT_OF_CLASS_OR_NULL(response, phalcon_http_responseinterface_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 1, &escaper, &response);
	if (!response) {
		response = &response_sub;
		response = &__$null;
	}
	ZEPHIR_CALL_PARENT(NULL, phalcon_html_helper_preload_ce, getThis(), "__construct", NULL, 0, escaper);
	zephir_check_call_status();
	zephir_update_property_zval(this_ptr, ZEND_STRL("response"), response);
	ZEPHIR_MM_RESTORE();
}

/**
 * @param string $href
 * @param string $type
 * @param array  $attributes
 *
 * @return string
 */
PHP_METHOD(Phalcon_Html_Helper_Preload, __invoke)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval attributes, _2$$3, _5$$3;
	zval href_zv, type_zv, *attributes_param = NULL, link, header, overrides, _0, _1, _3$$3, _4$$3, _6$$3;
	zend_string *href = NULL, *type = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&href_zv);
	ZVAL_UNDEF(&type_zv);
	ZVAL_UNDEF(&link);
	ZVAL_UNDEF(&header);
	ZVAL_UNDEF(&overrides);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_3$$3);
	ZVAL_UNDEF(&_4$$3);
	ZVAL_UNDEF(&_6$$3);
	ZVAL_UNDEF(&attributes);
	ZVAL_UNDEF(&_2$$3);
	ZVAL_UNDEF(&_5$$3);
	ZEND_PARSE_PARAMETERS_START(1, 3)
		Z_PARAM_STR(href)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(type)
		ZEPHIR_Z_PARAM_ARRAY(attributes, attributes_param)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	if (ZEND_NUM_ARGS() > 2) {
		attributes_param = ZEND_CALL_ARG(execute_data, 3);
	}
	ZVAL_STR_COPY(&href_zv, href);
	if (!type) {
		type = zend_string_init(ZEND_STRL("style"), 0);
		ZVAL_STR(&type_zv, type);
	} else {
		ZVAL_STR_COPY(&type_zv, type);
	}
	if (!attributes_param) {
		ZEPHIR_INIT_VAR(&attributes);
		array_init(&attributes);
	} else {
		zephir_get_arrval(&attributes, attributes_param);
	}
	ZEPHIR_INIT_VAR(&overrides);
	zephir_create_array(&overrides, 3, 0);
	add_assoc_stringl_ex(&overrides, SL("rel"), SL("preload"));
	zephir_array_update_string(&overrides, SL("href"), &href_zv, PH_COPY | PH_SEPARATE);
	zephir_array_update_string(&overrides, SL("as"), &type_zv, PH_COPY | PH_SEPARATE);
	zephir_array_unset_string(&attributes, SL("rel"), PH_SEPARATE);
	zephir_array_unset_string(&attributes, SL("href"), PH_SEPARATE);
	zephir_array_unset_string(&attributes, SL("as"), PH_SEPARATE);
	ZEPHIR_INIT_VAR(&_0);
	zephir_fast_array_merge(&_0, &overrides, &attributes);
	ZEPHIR_CPY_WRT(&overrides, &_0);
	zephir_read_property(&_1, this_ptr, ZEND_STRL("response"), PH_NOISY_CC | PH_READONLY);
	if (Z_TYPE_P(&_1) != IS_NULL) {
		ZEPHIR_INIT_VAR(&link);
		object_init_ex(&link, phalcon_html_link_link_ce);
		ZEPHIR_INIT_VAR(&_2$$3);
		zephir_create_array(&_2$$3, 1, 0);
		zephir_array_update_string(&_2$$3, SL("as"), &type_zv, PH_COPY | PH_SEPARATE);
		ZEPHIR_INIT_VAR(&_3$$3);
		ZVAL_STRING(&_3$$3, "preload");
		ZEPHIR_CALL_METHOD(NULL, &link, "__construct", NULL, 337, &_3$$3, &href_zv, &_2$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_NVAR(&_3$$3);
		object_init_ex(&_3$$3, phalcon_html_link_serializer_header_ce);
		if (zephir_has_constructor(&_3$$3)) {
			ZEPHIR_CALL_METHOD(NULL, &_3$$3, "__construct", NULL, 0);
			zephir_check_call_status();
		}

		ZEPHIR_INIT_VAR(&_5$$3);
		zephir_create_array(&_5$$3, 1, 0);
		zephir_array_fast_append(&_5$$3, &link);
		ZEPHIR_CALL_METHOD(&_4$$3, &_3$$3, "serialize", NULL, 338, &_5$$3);
		zephir_check_call_status();
		ZEPHIR_INIT_VAR(&header);
		ZEPHIR_CONCAT_SV(&header, "Link: ", &_4$$3);
		zephir_read_property(&_6$$3, this_ptr, ZEND_STRL("response"), PH_NOISY_CC | PH_READONLY);
		ZEPHIR_CALL_METHOD(NULL, &_6$$3, "setrawheader", NULL, 0, &header);
		zephir_check_call_status();
	}
	ZEPHIR_INIT_NVAR(&_0);
	ZVAL_STRING(&_0, "link");
	ZEPHIR_RETURN_CALL_METHOD(this_ptr, "selfclose", NULL, 0, &_0, &overrides);
	zephir_check_call_status();
	RETURN_MM();
}

