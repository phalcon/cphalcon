
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
  +------------------------------------------------------------------------+
  | This source file is subject to the New BSD License that is bundled     |
  | with this package in the file docs/LICENSE.txt.                        |
  |                                                                        |
  | If you did not receive a copy of the license and are unable to         |
  | obtain it through the world-wide-web, please send an email             |
  | to license@phalconphp.com so we can send you a copy immediately.       |
  +------------------------------------------------------------------------+
  | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
  |          Eduar Carvajal <eduar@phalconphp.com>                         |
  |          ZhuZongXin <dreamsxin@qq.com>                                 |
  +------------------------------------------------------------------------+
*/

#include "mvc/view/model.h"
#include "mvc/view/exception.h"
#include "mvc/viewinterface.h"
#include "mvc/view/modelinterface.h"
#include "di.h"

#include <Zend/zend_closures.h>

#include "kernel/main.h"
#include "kernel/memory.h"
#include "kernel/object.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"
#include "kernel/hash.h"
#include "kernel/concat.h"
#include "kernel/file.h"
#include "kernel/string.h"
#include "kernel/output.h"
#include "kernel/debug.h"

#include "internal/arginfo.h"

/**
 * Phalcon\Mvc\View\Model
 *
 * This component allows to render views without hicherquical levels
 *
 *<code>
 * $view = new Phalcon\Mvc\View\Model();
 * echo $view->render('templates/my-view', array('content' => $html));
 *</code>
 *
 */
zend_class_entry *phalcon_mvc_view_model_ce;

PHP_METHOD(Phalcon_Mvc_View_Model, __construct);
PHP_METHOD(Phalcon_Mvc_View_Model, setTemplate);
PHP_METHOD(Phalcon_Mvc_View_Model, getTemplate);
PHP_METHOD(Phalcon_Mvc_View_Model, setVars);
PHP_METHOD(Phalcon_Mvc_View_Model, getVars);
PHP_METHOD(Phalcon_Mvc_View_Model, setVar);
PHP_METHOD(Phalcon_Mvc_View_Model, getVar);
PHP_METHOD(Phalcon_Mvc_View_Model, addChild);
PHP_METHOD(Phalcon_Mvc_View_Model, appendChild);
PHP_METHOD(Phalcon_Mvc_View_Model, getChild);
PHP_METHOD(Phalcon_Mvc_View_Model, hasChild);
PHP_METHOD(Phalcon_Mvc_View_Model, setCaptureTo);
PHP_METHOD(Phalcon_Mvc_View_Model, getCaptureTo);
PHP_METHOD(Phalcon_Mvc_View_Model, setTerminal);
PHP_METHOD(Phalcon_Mvc_View_Model, getTerminal);
PHP_METHOD(Phalcon_Mvc_View_Model, setAppend);
PHP_METHOD(Phalcon_Mvc_View_Model, isAppend);
PHP_METHOD(Phalcon_Mvc_View_Model, setView);
PHP_METHOD(Phalcon_Mvc_View_Model, getView);
PHP_METHOD(Phalcon_Mvc_View_Model, render);
PHP_METHOD(Phalcon_Mvc_View_Model, __set);
PHP_METHOD(Phalcon_Mvc_View_Model, __get);
PHP_METHOD(Phalcon_Mvc_View_Model, __isset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_model___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, vars)
	ZEND_ARG_INFO(0, template)
	ZEND_ARG_INFO(0, capture)
ZEND_END_ARG_INFO()

static const zend_function_entry phalcon_mvc_view_model_method_entry[] = {
	PHP_ME(Phalcon_Mvc_View_Model, __construct, arginfo_phalcon_mvc_view_model___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR)
	PHP_ME(Phalcon_Mvc_View_Model, setTemplate, arginfo_phalcon_mvc_view_modelinterface_settemplate, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, getTemplate, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, setVars, arginfo_phalcon_mvc_view_modelinterface_setvars, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, getVars, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, setVar, arginfo_phalcon_mvc_view_modelinterface_setvar, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, getVar, arginfo_phalcon_mvc_view_modelinterface_getvar, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, addChild, arginfo_phalcon_mvc_view_modelinterface_addchild, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, appendChild, arginfo_phalcon_mvc_view_modelinterface_appendchild, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, getChild, arginfo_phalcon_mvc_view_modelinterface_getchild, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, hasChild, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, setCaptureTo, arginfo_phalcon_mvc_view_modelinterface_setcaptureto, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, getCaptureTo, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, setTerminal, arginfo_phalcon_mvc_view_modelinterface_setterminal, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, getTerminal, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, setAppend, arginfo_phalcon_mvc_view_modelinterface_setappend, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, isAppend, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, setView, arginfo_phalcon_mvc_view_modelinterface_setview, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, getView, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, render, NULL, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, __set, arginfo___set, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, __get, arginfo___get, ZEND_ACC_PUBLIC)
	PHP_ME(Phalcon_Mvc_View_Model, __isset, arginfo___isset, ZEND_ACC_PUBLIC)
	PHP_FE_END
};

/**
 * Phalcon\Mvc\View\Model initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_View_Model){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc\\View, Model, mvc_view_model, phalcon_mvc_view_model_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_view_model_ce, SL("_viewParams"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_string(phalcon_mvc_view_model_ce, SL("_captureTo"), "content", ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_model_ce, SL("_template"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_model_ce, SL("_childs"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_model_ce, SL("_terminal"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_model_ce, SL("_append"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_view_model_ce, SL("_view"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_mvc_view_model_ce TSRMLS_CC, 1, phalcon_mvc_view_modelinterface_ce);

	return SUCCESS;
}

/**
 * Phalcon\Mvc\View\Model constructor
 *
 * @param array $options
 */
PHP_METHOD(Phalcon_Mvc_View_Model, __construct){

	zval *variables = NULL, *template = NULL, *capture = NULL;

	phalcon_fetch_params(0, 0, 3, &variables, &template, &capture);

	if (variables && Z_TYPE_P(variables) != IS_NULL) {
		PHALCON_CALL_SELFW(NULL, "setvars", variables);
	}

	if (template && Z_TYPE_P(template) != IS_NULL) {
		PHALCON_CALL_SELFW(NULL, "settemplate", template);
	}

	if (capture && Z_TYPE_P(capture) != IS_NULL) {
		PHALCON_CALL_SELFW(NULL, "setcaptureto", capture);
	}
}

/**
 * Set the template to be used by this model
 *
 * @param  string $template
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Model, setTemplate){

	zval *template;

	phalcon_fetch_params(0, 1, 0, &template);

	phalcon_update_property_this(this_ptr, SL("_template"), template TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Get the template to be used by this model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Model, getTemplate){

	RETURN_MEMBER(this_ptr, "_template");
}

/**
 * Set all the render params
 *
 * @param array $params
 * @param boolean $merge
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Model, setVars){

	zval *params, *merge = NULL, *view_params, *merged_params = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &params, &merge);

	if (!merge) {
		merge = PHALCON_GLOBAL(z_true);
	}

	if (Z_TYPE_P(params) != IS_ARRAY) { 
		PHALCON_THROW_EXCEPTION_STR(phalcon_mvc_view_exception_ce, "The render parameters must be an array");
		return;
	}

	if (zend_is_true(merge)) {
		PHALCON_OBS_VAR(view_params);
		phalcon_read_property_this(&view_params, this_ptr, SL("_viewParams"), PH_NOISY TSRMLS_CC);
		if (Z_TYPE_P(view_params) == IS_ARRAY) { 
			PHALCON_INIT_VAR(merged_params);
			phalcon_fast_array_merge(merged_params, &view_params, &params TSRMLS_CC);
		} else {
			PHALCON_CPY_WRT(merged_params, params);
		}

		phalcon_update_property_this(this_ptr, SL("_viewParams"), merged_params TSRMLS_CC);
	} else {
		phalcon_update_property_this(this_ptr, SL("_viewParams"), params TSRMLS_CC);
	}

	RETURN_THIS();
}

/**
 * Get the vars
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Model, getVars){

	RETURN_MEMBER(this_ptr, "_viewParams");
}

/**
 * Set a single view parameter
 *
 * @param string $key
 * @param mixed $value
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Model, setVar){

	zval *key, *value, *isappend = NULL, *view_params, *var, *var_append;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 2, 1, &key, &value, &isappend);

	if (!isappend) {
		isappend = PHALCON_GLOBAL(z_false);
	}

	if (zend_is_true(isappend)) {		
		PHALCON_OBS_VAR(view_params);
		phalcon_read_property_this(&view_params, this_ptr, SL("_viewParams"), PH_NOISY TSRMLS_CC);

		if (Z_TYPE_P(view_params) == IS_ARRAY && phalcon_array_isset(view_params, key)) { 
			PHALCON_OBS_VAR(var);
			phalcon_array_fetch(&var, view_params, key, PH_NOISY);

			PHALCON_INIT_VAR(var_append);
			PHALCON_CONCAT_VV(var_append, var, value);
		} else {
			PHALCON_CPY_WRT(var_append, value);
		}
	} else {
		PHALCON_CPY_WRT(var_append, value);
	}

	phalcon_update_property_array(this_ptr, SL("_viewParams"), key, var_append TSRMLS_CC);

	RETURN_THIS();
}

/**
 * Get the vars
 *
 * @param string $key
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Model, getVar){

	zval *key, *default_value = NULL, *view_params, *var;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &key, &default_value);

	if (!default_value) {
		default_value = PHALCON_GLOBAL(z_null);
	}

	PHALCON_OBS_VAR(view_params);
	phalcon_read_property_this(&view_params, this_ptr, SL("_viewParams"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(view_params) == IS_ARRAY && phalcon_array_isset(view_params, key)) { 
		PHALCON_OBS_VAR(var);
		phalcon_array_fetch(&var, view_params, key, PH_NOISY);
	} else {
		PHALCON_CPY_WRT(var, default_value);
	}

	RETURN_CTOR(var);
}

/**
 * Add a child model
 *
 * @param  Phalcon\Mvc\View\ModelInterface $child
 * @param  null|string $captureTo Optional; if specified, the "capture to" value to set on the child
 * @param  null|bool $append Optional; if specified, append to child  with the same capture
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Model, addChild){

	zval *child, *capture_to = NULL, *append = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 2, &child, &capture_to, &append);

	if (capture_to && !PHALCON_IS_EMPTY(capture_to)) {
		PHALCON_CALL_METHOD(NULL, child, "setcaptureto", capture_to);
	}

	if (append) {
		PHALCON_CALL_METHOD(NULL, child, "setappend", append);
	}

	phalcon_update_property_array_append(this_ptr, SL("_childs"), child TSRMLS_CC);

	RETURN_THIS();
}

/**
 * Append a child model
 *
 * @param  Phalcon\Mvc\View\ModelInterface $child
 * @param  null|string $captureTo Optional; if specified, the "capture to" value to set on the child
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Model, appendChild){

	zval *child, *capture_to = NULL;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 1, 1, &child, &capture_to);

	if (!capture_to) {
		capture_to = PHALCON_GLOBAL(z_null);
	}

	PHALCON_CALL_SELF(NULL, "addchild", child, capture_to, PHALCON_GLOBAL(z_true));

	RETURN_THIS();
}

/**
 * Return a child model or all child model
 *
 * @param null|string $captureTo
 * @return array
 */
PHP_METHOD(Phalcon_Mvc_View_Model, getChild){

	zval *capture_to = NULL, *childs, *child = NULL, *child_capture_to = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &capture_to);

	if (capture_to) {
		array_init(return_value);

		PHALCON_OBS_VAR(childs);
		phalcon_read_property_this(&childs, this_ptr, SL("_childs"), PH_NOISY TSRMLS_CC);

		if (Z_TYPE_P(childs) != IS_ARRAY) {
			RETURN_MM_EMPTY_ARRAY();
		}

		phalcon_is_iterable(childs, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

			PHALCON_GET_HVALUE(child);

			PHALCON_CALL_METHOD(&child_capture_to, child, "getcaptureto");

			if (phalcon_memnstr(capture_to, child_capture_to)) {
				phalcon_array_append(&return_value, child, PH_COPY);
			}

			zend_hash_move_forward_ex(ah0, &hp0);
		}

	} else {
		RETURN_MM_MEMBER(this_ptr, "_childs");
	}
}

/**
 * Does the model have any children?
 *
 * @param null|string $captureTo
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_View_Model, hasChild){

	zval *capture_to = NULL, *childs, *child = NULL, *child_capture_to = NULL;
	HashTable *ah0;
	HashPosition hp0;
	zval **hd;

	PHALCON_MM_GROW();

	phalcon_fetch_params(1, 0, 1, &capture_to);

	PHALCON_OBS_VAR(childs);
	phalcon_read_property_this(&childs, this_ptr, SL("_childs"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(childs) != IS_ARRAY) {
		RETURN_MM_FALSE;
	}

	if (!phalcon_fast_count_ev(childs TSRMLS_CC)) {
		RETURN_MM_FALSE;
	}

	if (capture_to) {
		phalcon_is_iterable(childs, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

			PHALCON_GET_HVALUE(child);

			PHALCON_CALL_METHOD(&child_capture_to, child, "getcaptureto");

			if (phalcon_memnstr(capture_to, child_capture_to)) {
				RETURN_MM_TRUE;
			}

			zend_hash_move_forward_ex(ah0, &hp0);
		}

		RETURN_MM_FALSE;
	}

	RETURN_MM_TRUE;
}

/**
 * Set the name of the variable to capture this model to, if it is a child model
 *
 * @param string $capture
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Model, setCaptureTo){

	zval *capture;

	phalcon_fetch_params(0, 1, 0, &capture);

	phalcon_update_property_this(this_ptr, SL("_captureTo"), capture TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Get the name of the variable to which to capture this model
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Model, getCaptureTo){

	RETURN_MEMBER(this_ptr, "_captureTo");
}

/**
 * Set flag indicating whether or not this is considered a terminal or standalone model
 *
 * @param boolean $terminate
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Model, setTerminal){

	zval *terminate;

	phalcon_fetch_params(0, 1, 0, &terminate);

	phalcon_update_property_this(this_ptr, SL("_terminate"), terminate TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Is this considered a terminal or standalone model?
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_View_Model, getTerminal){

	RETURN_MEMBER(this_ptr, "_terminate");
}

/**
 * Set flag indicating whether or not append to child  with the same capture
 *
 * @param boolean $append
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Model, setAppend){

	zval *append;

	phalcon_fetch_params(0, 1, 0, &append);

	phalcon_update_property_this(this_ptr, SL("_append"), append TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Is this append to child  with the same capture?
 *
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_View_Model, isAppend){

	zval *append;

	PHALCON_MM_GROW();

	PHALCON_OBS_VAR(append);
	phalcon_read_property_this(&append, this_ptr, SL("_append"), PH_NOISY TSRMLS_CC);

	if (zend_is_true(append)) {
		RETURN_MM_TRUE;
	}

	RETURN_MM_FALSE;
}

/**
 * Set the view
 *
 * @param Phalcon\Mvc\ViewInterface $view
 * @return Phalcon\Mvc\View\ModelInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Model, setView){

	zval *view;

	phalcon_fetch_params(0, 1, 0, &view);

	phalcon_update_property_this(this_ptr, SL("_view"), view TSRMLS_CC);

	RETURN_THISW();
}

/**
 * Get the view
 *
 * @return Phalcon\Mvc\ViewInterface
 */
PHP_METHOD(Phalcon_Mvc_View_Model, getView){


	RETURN_MEMBER(this_ptr, "_view");
}

/**
 * Renders the view
 *
 * @return string
 */
PHP_METHOD(Phalcon_Mvc_View_Model, render){

	zval *child_contents, *child_content = NULL, *content_append = NULL, *debug_message = NULL;
	zval *childs = NULL, *child = NULL, *isappend = NULL, *capture = NULL, *content = NULL;
	zval *view, *dependency_injector = NULL, *service = NULL, *events_manager = NULL, *event_name = NULL;
	zval *status = NULL, *not_exists = NULL, *base_path = NULL, *paths = NULL, *views_dir = NULL, *vars = NULL, *new_vars, *template = NULL;
	zval *views_dir_path, *engines = NULL, *engine = NULL, *extension = NULL, *path = NULL;
	zval *view_engine_path = NULL, *exception_message, *contents;
	HashTable *ah0, *ah1, *ah2;
	HashPosition hp0, hp1, hp2;
	zval **hd;

	PHALCON_MM_GROW();

	PHALCON_INIT_VAR(child_contents);
	array_init(child_contents);

	PHALCON_CALL_SELF(&childs, "getchild");

	if (Z_TYPE_P(childs) == IS_ARRAY && phalcon_fast_count_ev(childs TSRMLS_CC)) {
		phalcon_is_iterable(childs, &ah0, &hp0, 0, 0);

		while (zend_hash_get_current_data_ex(ah0, (void**) &hd, &hp0) == SUCCESS) {

			PHALCON_GET_HVALUE(child);

			PHALCON_CALL_METHOD(&isappend, child, "isappend");
			PHALCON_CALL_METHOD(&capture, child, "getcaptureto");
			PHALCON_CALL_METHOD(&content, child, "render");

			if (zend_is_true(isappend)) {
				if (Z_TYPE_P(child_contents) == IS_ARRAY && phalcon_array_isset(child_contents, capture)) { 
					PHALCON_OBS_NVAR(child_content);
					phalcon_array_fetch(&child_content, child_contents, capture, PH_NOISY);

					PHALCON_INIT_NVAR(content_append);
					PHALCON_CONCAT_VV(content_append, child_content, content);
					phalcon_array_update_zval(&child_contents, capture, content_append, PH_COPY);
				} else {
					phalcon_array_update_zval(&child_contents, capture, content, PH_COPY);
				}
			} else {
				phalcon_array_update_zval(&child_contents, capture, content, PH_COPY);
			}

			zend_hash_move_forward_ex(ah0, &hp0);
		}
	}

	phalcon_ob_start(TSRMLS_C);

	PHALCON_OBS_VAR(view);
	phalcon_read_property_this(&view, this_ptr, SL("_view"), PH_NOISY TSRMLS_CC);

	if (Z_TYPE_P(view) != IS_OBJECT) {
		PHALCON_CALL_CE_STATIC(&dependency_injector, phalcon_di_ce, "getdefault");

		PHALCON_INIT_NVAR(service);
		ZVAL_STRING(service, "view", 1);

		PHALCON_CALL_METHOD(&view, dependency_injector, "getshared", service);
	}

	PHALCON_VERIFY_INTERFACE(view, phalcon_mvc_viewinterface_ce);

	PHALCON_CALL_METHOD(&events_manager, view, "geteventsmanager");

	/** 
	 * Call beforeRender if there is an events manager
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {

		PHALCON_INIT_VAR(event_name);
		ZVAL_STRING(event_name, "view:beforeRender", 1);

		PHALCON_CALL_METHOD(&status, events_manager, "fire", event_name, this_ptr);
		if (PHALCON_IS_FALSE(status)) {
			RETURN_MM_NULL();
		}
	}

	PHALCON_INIT_VAR(not_exists);
	ZVAL_TRUE(not_exists);

	PHALCON_CALL_METHOD(&base_path, view, "getbasepath");
	if (Z_TYPE_P(base_path) != IS_ARRAY) {
		PHALCON_INIT_VAR(paths);
		array_init(paths);
		phalcon_array_append(&paths, base_path, PH_COPY);
	} else {
		PHALCON_CPY_WRT(paths, base_path);
	}

	PHALCON_CALL_METHOD(&views_dir, view, "getviewsdir");

	PHALCON_CALL_SELF(&template, "gettemplate");
	PHALCON_CALL_SELF(&vars, "getVars");

	if (unlikely(PHALCON_GLOBAL(debug).enable_debug)) {
		PHALCON_INIT_NVAR(debug_message);
		PHALCON_CONCAT_SV(debug_message, "Render Model View: ", template);
		phalcon_debug_print_r(debug_message TSRMLS_CC);
	}

	PHALCON_INIT_VAR(new_vars);
	phalcon_fast_array_merge(new_vars, &vars, &child_contents TSRMLS_CC);

	PHALCON_INIT_VAR(views_dir_path);
	PHALCON_CONCAT_VV(views_dir_path, views_dir, template);

	PHALCON_CALL_METHOD(&engines, view, "getEngines");

	/** 
	 * Views are rendered in each engine
	 */
	phalcon_is_iterable(engines, &ah1, &hp1, 0, 0);

	while (zend_hash_get_current_data_ex(ah1, (void**) &hd, &hp1) == SUCCESS) {

		PHALCON_GET_HKEY(extension, ah1, hp1);
		PHALCON_GET_HVALUE(engine);

		phalcon_is_iterable(paths, &ah2, &hp2, 0, 0);

		while (zend_hash_get_current_data_ex(ah2, (void**) &hd, &hp2) == SUCCESS) {

			PHALCON_GET_HVALUE(path);

			PHALCON_INIT_NVAR(view_engine_path);
			PHALCON_CONCAT_VVV(view_engine_path, path, views_dir_path, extension);

			if (phalcon_file_exists(view_engine_path TSRMLS_CC) == SUCCESS) {

				if (unlikely(PHALCON_GLOBAL(debug).enable_debug)) {
					PHALCON_INIT_NVAR(debug_message);
					PHALCON_CONCAT_SV(debug_message, "--Found: ", view_engine_path);
					phalcon_debug_print_r(debug_message TSRMLS_CC);
				}

				/** 
				 * Call beforeRenderView if there is a events manager available
				 */
				if (Z_TYPE_P(events_manager) == IS_OBJECT) {

					PHALCON_INIT_NVAR(event_name);
					ZVAL_STRING(event_name, "view:beforeRenderView", 1);

					PHALCON_CALL_METHOD(&status, events_manager, "fire", event_name, this_ptr, view_engine_path);
					if (PHALCON_IS_FALSE(status)) {
						zend_hash_move_forward_ex(ah0, &hp0);
						continue;
					}
				}

				PHALCON_CALL_METHOD(NULL, engine, "render", view_engine_path, new_vars, PHALCON_GLOBAL(z_true));

				/** 
				 * Call afterRenderView if there is a events manager available
				 */
				PHALCON_INIT_NVAR(not_exists);
				ZVAL_FALSE(not_exists);
				if (Z_TYPE_P(events_manager) == IS_OBJECT) {
					PHALCON_INIT_NVAR(event_name);
					ZVAL_STRING(event_name, "view:afterRenderView", 1);
					PHALCON_CALL_METHOD(NULL, events_manager, "fire", event_name, this_ptr);
				}

				break;
			} else if (unlikely(PHALCON_GLOBAL(debug).enable_debug)) {
				PHALCON_INIT_NVAR(debug_message);
				PHALCON_CONCAT_SV(debug_message, "--Not Found: ", view_engine_path);
				phalcon_debug_print_r(debug_message TSRMLS_CC);
			}

			zend_hash_move_forward_ex(ah2, &hp2);
		}

		zend_hash_move_forward_ex(ah1, &hp1);
	}

	/** 
	 * Always throw an exception if the view does not exist
	 */
	if (PHALCON_IS_TRUE(not_exists)) {
		PHALCON_INIT_VAR(exception_message);
		PHALCON_CONCAT_SVS(exception_message, "View '", views_dir_path, "' was not found in the views directory");
		PHALCON_THROW_EXCEPTION_ZVAL(phalcon_mvc_view_exception_ce, exception_message);
		return;
	}

	/** 
	 * Call afterRender event
	 */
	if (Z_TYPE_P(events_manager) == IS_OBJECT) {
		PHALCON_INIT_NVAR(event_name);
		ZVAL_STRING(event_name, "view:afterRender", 1);
		PHALCON_CALL_METHOD(NULL, events_manager, "fire", event_name, this_ptr);
	}

	PHALCON_INIT_VAR(contents);
	phalcon_ob_get_contents(contents TSRMLS_CC);

	phalcon_ob_end_clean(TSRMLS_C);

	RETURN_CTOR(contents);
}

/**
 * Magic method to pass variables to the views
 *
 * @param string $key
 * @param mixed $value
 */
PHP_METHOD(Phalcon_Mvc_View_Model, __set){

	zval *key, *value;

	phalcon_fetch_params(0, 2, 0, &key, &value);

	phalcon_update_property_array(this_ptr, SL("_viewParams"), key, value TSRMLS_CC);

}

/**
 * Magic method to retrieve a variable passed to the view
 *
 * @param string $key
 * @return mixed
 */
PHP_METHOD(Phalcon_Mvc_View_Model, __get){

	zval *key, *params, *value;

	phalcon_fetch_params(0, 1, 0, &key);

	params = phalcon_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset_fetch(&value, params, key)) {
		RETURN_ZVAL(value, 1, 0);
	}

	RETURN_NULL();
}

/**
 * Magic method to inaccessible a variable passed to the view
 *
 * @param string $key
 * @return boolean
 */
PHP_METHOD(Phalcon_Mvc_View_Model, __isset){

	zval *key, *params;

	phalcon_fetch_params(0, 1, 0, &key);

	params = phalcon_fetch_nproperty_this(this_ptr, SL("_viewParams"), PH_NOISY TSRMLS_CC);
	if (phalcon_array_isset(params, key)) {
		RETURN_TRUE;
	}

	RETURN_FALSE;
}
