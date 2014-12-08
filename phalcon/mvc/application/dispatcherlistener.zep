
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
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Mvc\Application;

use Phalcon\Mvc\Application;
use Phalcon\DispatcherInterface;
use Phalcon\Events\Event;
use Phalcon\Mvc\Application\Exception;
use Phalcon\Mvc\ModuleDefinitionInterface;

/**
 * Phalcon\Mvc\Application\DispatcherListener
 *
 * Listener for dispatcher with Application Instance
 * Used for current module initialising
 */
class DispatcherListener
{
	protected _application;

	/**
	 * Phalcon\Mvc\Application\DispatcherListener
	 *
	 * @param Phalcon\DiInterface dependencyInjector
	 */
	public function __construct(<Application> application)
	{
		let this->_application = application;
	}

	/**
	 * Listener of beforeExecuteRoute event of dispatcher
	 * used to initialize services of module
	 *
	 * @param Phalcon\Events\Event event
	 * @param Phalcon\DispatcherInterface dispatcher
	 * @param data
	 */
	public function beforeExecuteRoute(<Event> event, <DispatcherInterface> dispatcher, data)
	{
		var moduleName, module, modules, eventsManager, dependencyInjector;

		let moduleName = dispatcher->getModuleName();
		let dependencyInjector = this->_application->getDI();

		/**
		 * Process the module definition
		 */
		if moduleName {
			let eventsManager = this->_application->getEventsManager();

			if typeof eventsManager == "object" {
				if eventsManager->fire("application:beforeStartModule", this->_application) === false {
					return false;
				}
			}

			let modules = this->_application->getModules();

			/**
			 * Check if the module passed by the router is registered in the modules container
			 */
			if !fetch module, modules[moduleName] {
				throw new Exception("Module '" . moduleName . "' isn't registered in the application container");
			}

			/**
			 * 'registerServices' are automatically called
			 */
			if typeof module == "object" {
				if module instanceof ModuleDefinitionInterface {
					module->registerServices(dependencyInjector);
				} else {
					if module instanceof \Closure {
						call_user_func_array(module, [dependencyInjector]);
					}
				}
			}

			/**
			 * Calling afterStartModule event
			 */
			if typeof eventsManager == "object" {
				eventsManager->fire("application:afterStartModule", this->_application, module);
			}
		}

		if this->_application->isUseImplicitView() === true {
			dependencyInjector->getShared("view")->start();
		}
	}
}

