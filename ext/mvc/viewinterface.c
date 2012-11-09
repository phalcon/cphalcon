
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

#ifdef HAVE_CONFIG_H
#include "config.h"
#endif

#include "php.h"
#include "php_phalcon.h"
#include "phalcon.h"

#include "kernel/main.h"

/**
 * Phalcon\Mvc\ViewInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_ViewInterface){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, ViewInterface, mvc_viewinterface, phalcon_mvc_viewinterface_method_entry, ZEND_ACC_INTERFACE);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_ViewInterface, setViewsDir){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, getViewsDir){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, setBasePath){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, setRenderLevel){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, setMainView){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, setTemplateBefore){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, cleanTemplateBefore){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, setTemplateAfter){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, cleanTemplateAfter){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, setParamToView){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, setVar){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, getParamsToView){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, getControllerName){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, getActionName){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, getParams){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, start){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, registerEngines){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, render){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, pick){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, partial){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, finish){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, getCache){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, cache){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, setContent){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, getContent){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, getActiveRenderPath){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, disable){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, enable){ }

PHP_METHOD(Phalcon_Mvc_ViewInterface, reset){ }

