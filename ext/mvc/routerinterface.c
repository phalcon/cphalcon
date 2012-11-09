
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
 * Phalcon\Mvc\RouterInterface initializer
 */
PHALCON_INIT_CLASS(Phalcon_Mvc_RouterInterface){

	PHALCON_REGISTER_CLASS(Phalcon\\Mvc, RouterInterface, mvc_routerinterface, phalcon_mvc_routerinterface_method_entry, ZEND_ACC_INTERFACE);

	return SUCCESS;
}

PHP_METHOD(Phalcon_Mvc_RouterInterface, setDefaultModule){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, setDefaultController){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, setDefaultAction){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, setDefaults){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, handle){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, add){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, addGet){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, addPost){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, addPut){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, addDelete){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, addOptions){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, addHead){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, clear){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, getModuleName){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, getControllerName){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, getActionName){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, getParams){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, getMatchedRoute){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, getMatches){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, wasMatched){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, getRoutes){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, getRouteById){ }

PHP_METHOD(Phalcon_Mvc_RouterInterface, getRouteByName){ }

