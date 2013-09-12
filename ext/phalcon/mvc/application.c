
#ifdef HAVE_CONFIG_H
#include "ext_config.h"
#endif

#include "php.h"
#include "../php_ext.h"
#include "../ext.h"

#include "Zend/zend_operators.h"
#include "Zend/zend_exceptions.h"
#include "Zend/zend_interfaces.h"

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"


/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
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
/**
 * Phalcon\Mvc\Application
 *
 * This component encapsulates all the complex operations behind instantiating every component
 * needed and integrating it with the rest to allow the MVC pattern to operate as desired.
 *
 *<code>
 *
 * class Application extends \Phalcon\Mvc\Application
 * {
 *
 *		/**
 *		 * Register the services here to make them general or register
 *		 * in the ModuleDefinition to make them module-specific
 *		 *\/
 *		protected function _registerServices()
 *		{
 *
 *		}
 *
 *		/**
 *		 * This method registers all the modules in the application
 *		 *\/
 *		public function main()
 *		{
 *			$this->registerModules(array(
 *				'frontend' => array(
 *					'className' => 'Multiple\Frontend\Module',
 *					'path' => '../apps/frontend/Module.php'
 *				),
 *				'backend' => array(
 *					'className' => 'Multiple\Backend\Module',
 *					'path' => '../apps/backend/Module.php'
 *				)
 *			));
 *		}
 *	}
 *
 *	$application = new Application();
 *	$application->main();
 *
 *</code>
 */
ZEPHIR_INIT_CLASS(Phalcon_Mvc_Application) {

	ZEPHIR_REGISTER_CLASS_EX(Phalcon\\Mvc, Application, phalcon, mvc_application, phalcon_di_injectable_ce, phalcon_mvc_application_method_entry, 0);

	zend_declare_property_null(phalcon_mvc_application_ce, SL("_defaultModule"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_application_ce, SL("_modules"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_null(phalcon_mvc_application_ce, SL("_moduleObject"), ZEND_ACC_PROTECTED TSRMLS_CC);
	zend_declare_property_bool(phalcon_mvc_application_ce, SL("_implicitView"), 1, ZEND_ACC_PROTECTED TSRMLS_CC);

	return SUCCESS;

}

/**
 * Phalcon\Mvc\Application
 *
 * @param Phalcon\DiInterface dependencyInjector
 */
PHP_METHOD(Phalcon_Mvc_Application, __construct) {

	zval *dependencyInjector = NULL;

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 0, 1, &dependencyInjector);

	if (!dependencyInjector) {
		ZEPHIR_CPY_WRT(dependencyInjector, ZEPHIR_GLOBAL(global_null));
	}


	if (Z_TYPE_P(dependencyInjector) == IS_OBJECT) {
		zephir_update_property_this(this_ptr, SL("_dependencyInjector"), dependencyInjector TSRMLS_CC);
	}
	ZEPHIR_MM_RESTORE();

}

