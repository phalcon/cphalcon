
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
#include "kernel/fcall.h"
#include "kernel/operators.h"
#include "kernel/array.h"


/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 *
 * Based on the Action Domain Responder pattern
 * @link    https://pmjones.io/adr/
 */
/**
 * Renders a template from the payload and returns it as an HTML response.
 *
 * The HTML sibling of `JsonResponder`: serialization is swapped for rendering,
 * the status mapping and the `Responder` contract stay the same. It depends on
 * the neutral `Renderer` contract only, so the ADR component never imports the
 * MVC view.
 */
ZEPHIR_INIT_CLASS(Phalcon_ADR_Responder_ViewResponder)
{
	ZEPHIR_REGISTER_CLASS(Phalcon\\ADR\\Responder, ViewResponder, phalcon, adr_responder_viewresponder, phalcon_adr_responder_viewresponder_method_entry, ZEND_ACC_FINAL_CLASS);

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_responder_viewresponder_ce, SL("renderer"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\Contracts\\View\\Renderer"));
	}

	{
		zval _zc0;
		ZVAL_UNDEF(&_zc0);
		zephir_declare_typed_property(phalcon_adr_responder_viewresponder_ce, SL("statusMapper"), &_zc0, ZEND_ACC_PROTECTED, 0, SL("Phalcon\\ADR\\Responder\\StatusMapper"));
	}

	{
		zval _zc0;
		ZVAL_STRINGL(&_zc0, "", sizeof("") - 1);
		zephir_declare_typed_property(phalcon_adr_responder_viewresponder_ce, SL("template"), &_zc0, ZEND_ACC_PROTECTED, MAY_BE_STRING, NULL, 0);
	}

	zend_class_implements(phalcon_adr_responder_viewresponder_ce, 1, phalcon_contracts_adr_responder_responder_ce);
	return SUCCESS;
}

PHP_METHOD(Phalcon_ADR_Responder_ViewResponder, __construct)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_string *template = NULL;
	zval *renderer, renderer_sub, *statusMapper, statusMapper_sub, template_zv;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&renderer_sub);
	ZVAL_UNDEF(&statusMapper_sub);
	ZVAL_UNDEF(&template_zv);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("renderer", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("statusMapper", 12, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("template", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(2, 3)
		Z_PARAM_OBJECT_OF_CLASS(renderer, phalcon_contracts_view_renderer_ce)
		Z_PARAM_OBJECT_OF_CLASS(statusMapper, phalcon_adr_responder_statusmapper_ce)
		Z_PARAM_OPTIONAL
		Z_PARAM_STR(template)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	renderer = ZEND_CALL_ARG(execute_data, 1);
	statusMapper = ZEND_CALL_ARG(execute_data, 2);
	if (!template) {
		template = zend_string_init(ZEND_STRL(""), 0);
		zephir_memory_observe(&template_zv);
		ZVAL_STR(&template_zv, template);
	} else {
		zephir_memory_observe(&template_zv);
	ZVAL_STR_COPY(&template_zv, template);
	}
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_0, 363, renderer);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_1, 364, statusMapper);
	zephir_update_property_zval_cached(this_ptr, _zephir_prop_2, 365, &template_zv);
	ZEPHIR_MM_RESTORE();
}

PHP_METHOD(Phalcon_ADR_Responder_ViewResponder, __invoke)
{
	zval _7;
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *request, request_sub, *response, response_sub, *payload, payload_sub, html, _0, _1, _2, _3, _4, _5, _6, _8, _9;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&request_sub);
	ZVAL_UNDEF(&response_sub);
	ZVAL_UNDEF(&payload_sub);
	ZVAL_UNDEF(&html);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);
	ZVAL_UNDEF(&_3);
	ZVAL_UNDEF(&_4);
	ZVAL_UNDEF(&_5);
	ZVAL_UNDEF(&_6);
	ZVAL_UNDEF(&_8);
	ZVAL_UNDEF(&_9);
	ZVAL_UNDEF(&_7);
	static zend_string *_zephir_prop_0 = NULL;
	static zend_string *_zephir_prop_1 = NULL;
	static zend_string *_zephir_prop_2 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("renderer", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_1)) {
		_zephir_prop_1 = zend_string_init("template", 8, 1);
	}
	if (UNEXPECTED(!_zephir_prop_2)) {
		_zephir_prop_2 = zend_string_init("statusMapper", 12, 1);
	}

	ZEND_PARSE_PARAMETERS_START(3, 3)
		Z_PARAM_OBJECT_OF_CLASS(request, phalcon_http_requestinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(response, phalcon_http_responseinterface_ce)
		Z_PARAM_OBJECT_OF_CLASS(payload, phalcon_contracts_adr_payload_payload_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 3, 0, &request, &response, &payload);
	zephir_read_property_cached(&_0, this_ptr, _zephir_prop_0, 363, PH_NOISY_CC | PH_READONLY);
	zephir_read_property_cached(&_1, this_ptr, _zephir_prop_1, 365, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_2, this_ptr, "viewdata", NULL, 329, payload);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&html, &_0, "render", NULL, 0, &_1, &_2);
	zephir_check_call_status();
	zephir_read_property_cached(&_4, this_ptr, _zephir_prop_2, 364, PH_NOISY_CC | PH_READONLY);
	ZEPHIR_CALL_METHOD(&_6, payload, "getstatus", NULL, 0);
	zephir_check_call_status();
	zephir_cast_to_string(&_7, &_6);
	ZEPHIR_CALL_METHOD(&_5, &_4, "tohttpcode", NULL, 0, &_7);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(&_3, response, "setstatuscode", NULL, 0, &_5);
	zephir_check_call_status();
	ZEPHIR_INIT_VAR(&_9);
	ZVAL_STRING(&_9, "text/html");
	ZEPHIR_CALL_METHOD(&_8, &_3, "setcontenttype", NULL, 0, &_9);
	zephir_check_call_status();
	ZEPHIR_CALL_METHOD(NULL, &_8, "setcontent", NULL, 0, &html);
	zephir_check_call_status();
	RETVAL_ZVAL(response, 1, 0);
	RETURN_MM();
}

/**
 * Returns a copy of the responder bound to the given template. The action
 * names the view; the payload stays free of presentation concerns.
 */
PHP_METHOD(Phalcon_ADR_Responder_ViewResponder, withTemplate)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zval template_zv, cloned;
	zend_string *template = NULL;
	zval *this_ptr = getThis();

	ZVAL_UNDEF(&template_zv);
	ZVAL_UNDEF(&cloned);
	static zend_string *_zephir_prop_0 = NULL;
	if (UNEXPECTED(!_zephir_prop_0)) {
		_zephir_prop_0 = zend_string_init("template", 8, 1);
	}

	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_STR(template)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_memory_observe(&template_zv);
	ZVAL_STR_COPY(&template_zv, template);
	ZEPHIR_INIT_VAR(&cloned);
	if (zephir_clone(&cloned, this_ptr) == FAILURE) {
		RETURN_MM();
	}
	zephir_update_property_zval_cached(&cloned, _zephir_prop_0, 0, &template_zv);
	RETURN_CCTOR(&cloned);
}

/**
 * Flattens the payload into the variables handed to the template. The
 * extras travel as they are, so an action can hand the view whatever the
 * result should not carry.
 */
PHP_METHOD(Phalcon_ADR_Responder_ViewResponder, viewData)
{
	zephir_method_globals *ZEPHIR_METHOD_GLOBALS_PTR = NULL;
	zend_long ZEPHIR_LAST_CALL_STATUS;
	zval *payload, payload_sub, _0;

	ZVAL_UNDEF(&payload_sub);
	ZVAL_UNDEF(&_0);
	ZEND_PARSE_PARAMETERS_START(1, 1)
		Z_PARAM_OBJECT_OF_CLASS(payload, phalcon_contracts_adr_payload_payload_ce)
	ZEND_PARSE_PARAMETERS_END();
	ZEPHIR_METHOD_GLOBALS_PTR = pecalloc(1, sizeof(zephir_method_globals), 0);
	zephir_memory_grow_stack(ZEPHIR_METHOD_GLOBALS_PTR, __func__);
	zephir_fetch_params(1, 1, 0, &payload);
	zephir_create_array(return_value, 4, 0);
	ZEPHIR_CALL_METHOD(&_0, payload, "getextras", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("extras"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, payload, "getresult", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("result"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, payload, "getmessages", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("messages"), &_0, PH_COPY | PH_SEPARATE);
	ZEPHIR_CALL_METHOD(&_0, payload, "getstatus", NULL, 0);
	zephir_check_call_status();
	zephir_array_update_string(return_value, SL("status"), &_0, PH_COPY | PH_SEPARATE);
	RETURN_MM();
}

