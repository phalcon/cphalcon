
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

namespace Phalcon\DI\FactoryDefault;

 /**
 * Phalcon\DI\FactoryDefault\CLI
 *
 * This is a variant of the standard Phalcon\DI. By default it automatically
 * registers all the services provided by the framework.
 * Thanks to this, the developer does not need to register each service individually.
 * This class is specially suitable for CLI applications
 */
class Cli extends Phalcon\DI\FactoryDefault
{

	/**
	 * Phalcon\DI\FactoryDefault\CLI constructor
	 */
	public function __construct(){

		var shared;

		parent::__construct();

		let shared = true;

		let this->_services = [
			"router": new Phalcon\DI\Service("router", "Phalcon\\CLI\\Router"),
			"dispatcher": new Phalcon\DI\Service("dispatcher", "Phalcon\\CLI\\Dispatcher"),
			"modelsManager": new Phalcon\DI\Service("modelsManager", "Phalcon\\Mvc\\Model\\Manager"),
			"modelsMetadata": new Phalcon\DI\Service("modelsMetadata", "Phalcon\\Mvc\\Model\\Metadata\\Memory"),
			"filter": new Phalcon\DI\Service("filter", "Phalcon\\Filter", shared),
			"escaper": new Phalcon\DI\Service("escaper", "Phalcon\\Escaper", shared),
			"annotations": new Phalcon\DI\Service("annotations", "Phalcon\\Annotations\\Adapter\\Memory", shared),
			"security": new Phalcon\DI\Service("security", "Phalcon\\Security", shared),
			"eventsManager": new Phalcon\DI\Service("eventsManager", "Phalcon\\Events\\Manage", shared),
			"transactionManager": new Phalcon\DI\Service("transactionManager", "Phalcon\\Mvc\\Model\\Transaction\\Manager", shared)
		];
	}

}