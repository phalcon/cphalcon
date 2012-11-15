
/*
  +------------------------------------------------------------------------+
  | Phalcon Framework                                                      |
  +------------------------------------------------------------------------+
  | Copyright (c) 2011-2012 Phalcon Team (http://www.phalconphp.com)       |
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
  +------------------------------------------------------------------------+
*/

extern zend_class_entry *phalcon_mvc_view_ce;

PHALCON_INIT_CLASS(Phalcon_Mvc_View);

PHP_METHOD(Phalcon_Mvc_View, __construct);
PHP_METHOD(Phalcon_Mvc_View, setViewsDir);
PHP_METHOD(Phalcon_Mvc_View, getViewsDir);
PHP_METHOD(Phalcon_Mvc_View, setBasePath);
PHP_METHOD(Phalcon_Mvc_View, setRenderLevel);
PHP_METHOD(Phalcon_Mvc_View, setMainView);
PHP_METHOD(Phalcon_Mvc_View, setTemplateBefore);
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateBefore);
PHP_METHOD(Phalcon_Mvc_View, setTemplateAfter);
PHP_METHOD(Phalcon_Mvc_View, cleanTemplateAfter);
PHP_METHOD(Phalcon_Mvc_View, setParamToView);
PHP_METHOD(Phalcon_Mvc_View, setVar);
PHP_METHOD(Phalcon_Mvc_View, getParamsToView);
PHP_METHOD(Phalcon_Mvc_View, getControllerName);
PHP_METHOD(Phalcon_Mvc_View, getActionName);
PHP_METHOD(Phalcon_Mvc_View, getParams);
PHP_METHOD(Phalcon_Mvc_View, start);
PHP_METHOD(Phalcon_Mvc_View, _loadTemplateEngines);
PHP_METHOD(Phalcon_Mvc_View, _engineRender);
PHP_METHOD(Phalcon_Mvc_View, registerEngines);
PHP_METHOD(Phalcon_Mvc_View, render);
PHP_METHOD(Phalcon_Mvc_View, pick);
PHP_METHOD(Phalcon_Mvc_View, partial);
PHP_METHOD(Phalcon_Mvc_View, finish);
PHP_METHOD(Phalcon_Mvc_View, _createCache);
PHP_METHOD(Phalcon_Mvc_View, getCache);
PHP_METHOD(Phalcon_Mvc_View, cache);
PHP_METHOD(Phalcon_Mvc_View, setContent);
PHP_METHOD(Phalcon_Mvc_View, getContent);
PHP_METHOD(Phalcon_Mvc_View, getActiveRenderPath);
PHP_METHOD(Phalcon_Mvc_View, disable);
PHP_METHOD(Phalcon_Mvc_View, enable);
PHP_METHOD(Phalcon_Mvc_View, reset);

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view___construct, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setviewsdir, 0, 0, 1)
	ZEND_ARG_INFO(0, viewsDir)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setbasepath, 0, 0, 1)
	ZEND_ARG_INFO(0, basePath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setrenderlevel, 0, 0, 1)
	ZEND_ARG_INFO(0, level)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setmainview, 0, 0, 1)
	ZEND_ARG_INFO(0, viewPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_settemplatebefore, 0, 0, 1)
	ZEND_ARG_INFO(0, templateBefore)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_settemplateafter, 0, 0, 1)
	ZEND_ARG_INFO(0, templateAfter)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setparamtoview, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setvar, 0, 0, 2)
	ZEND_ARG_INFO(0, key)
	ZEND_ARG_INFO(0, value)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_registerengines, 0, 0, 1)
	ZEND_ARG_INFO(0, engines)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_render, 0, 0, 2)
	ZEND_ARG_INFO(0, controllerName)
	ZEND_ARG_INFO(0, actionName)
	ZEND_ARG_INFO(0, params)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_pick, 0, 0, 1)
	ZEND_ARG_INFO(0, renderView)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_partial, 0, 0, 1)
	ZEND_ARG_INFO(0, partialPath)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_cache, 0, 0, 0)
	ZEND_ARG_INFO(0, options)
ZEND_END_ARG_INFO()

ZEND_BEGIN_ARG_INFO_EX(arginfo_phalcon_mvc_view_setcontent, 0, 0, 1)
	ZEND_ARG_INFO(0, content)
ZEND_END_ARG_INFO()

PHALCON_INIT_FUNCS(phalcon_mvc_view_method_entry){
	PHP_ME(Phalcon_Mvc_View, __construct, arginfo_phalcon_mvc_view___construct, ZEND_ACC_PUBLIC|ZEND_ACC_CTOR) 
	PHP_ME(Phalcon_Mvc_View, setViewsDir, arginfo_phalcon_mvc_view_setviewsdir, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getViewsDir, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setBasePath, arginfo_phalcon_mvc_view_setbasepath, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setRenderLevel, arginfo_phalcon_mvc_view_setrenderlevel, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setMainView, arginfo_phalcon_mvc_view_setmainview, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setTemplateBefore, arginfo_phalcon_mvc_view_settemplatebefore, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, cleanTemplateBefore, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setTemplateAfter, arginfo_phalcon_mvc_view_settemplateafter, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, cleanTemplateAfter, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setParamToView, arginfo_phalcon_mvc_view_setparamtoview, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setVar, arginfo_phalcon_mvc_view_setvar, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getParamsToView, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getControllerName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getActionName, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getParams, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, start, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, _loadTemplateEngines, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View, _engineRender, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View, registerEngines, arginfo_phalcon_mvc_view_registerengines, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, render, arginfo_phalcon_mvc_view_render, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, pick, arginfo_phalcon_mvc_view_pick, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, partial, arginfo_phalcon_mvc_view_partial, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, finish, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, _createCache, NULL, ZEND_ACC_PROTECTED) 
	PHP_ME(Phalcon_Mvc_View, getCache, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, cache, arginfo_phalcon_mvc_view_cache, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, setContent, arginfo_phalcon_mvc_view_setcontent, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getContent, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, getActiveRenderPath, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, disable, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, enable, NULL, ZEND_ACC_PUBLIC) 
	PHP_ME(Phalcon_Mvc_View, reset, NULL, ZEND_ACC_PUBLIC) 
	PHP_FE_END
};

