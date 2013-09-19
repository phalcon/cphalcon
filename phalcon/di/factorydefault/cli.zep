
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

namespace Phalcon\Di\FactoryDefault;

 /**
 * Phalcon\Di\FactoryDefault\CLI
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework.
 * Thanks to this, the developer does not need to register each service individually.
 * This class is specially suitable for CLI applications
 */
class Cli extends Phalcon\Di\FactoryDefault
{

	/**
	 * Phalcon\Di\FactoryDefault\CLI constructor
	 */
	public function __construct()
	{

		parent::__construct();

		let this->_services = [
			"router": new Phalcon\Di\Service("router", "Phalcon\\CLI\\Router"),
			"dispatcher": new Phalcon\Di\Service("dispatcher", "Phalcon\\CLI\\Dispatcher"),
			"modelsManager": new Phalcon\Di\Service("modelsManager", "Phalcon\\Mvc\\Model\\Manager"),
			"modelsMetadata": new Phalcon\Di\Service("modelsMetadata", "Phalcon\\Mvc\\Model\\Metadata\\Memory"),
			"filter": new Phalcon\Di\Service("filter", "Phalcon\\Filter", true),
			"escaper": new Phalcon\Di\Service("escaper", "Phalcon\\Escaper", true),
			"annotations": new Phalcon\Di\Service("annotations", "Phalcon\\Annotations\\Adapter\\Memory", true),
			"security": new Phalcon\Di\Service("security", "Phalcon\\Security", true),
			"eventsManager": new Phalcon\Di\Service("eventsManager", "Phalcon\\Events\\Manage", true),
			"transactionManager": new Phalcon\Di\Service("transactionManager", "Phalcon\\Mvc\\Model\\Transaction\\Manager", true)
		];
	}

}
