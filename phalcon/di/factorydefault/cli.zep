
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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

use Phalcon\Di\Service;
use Phalcon\Di\FactoryDefault;

 /**
 * Phalcon\Di\FactoryDefault\CLI
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework.
 * Thanks to this, the developer does not need to register each service individually.
 * This class is specially suitable for CLI applications
 */
class Cli extends FactoryDefault
{

	/**
	 * Phalcon\Di\FactoryDefault\CLI constructor
	 */
	public function __construct()
	{
		parent::__construct();

		let this->_services = [
			"router":             new Service("router", "Phalcon\\CLI\\Router", true),
			"dispatcher":         new Service("dispatcher", "Phalcon\\CLI\\Dispatcher", true),
			"modelsManager":      new Service("modelsManager", "Phalcon\\Mvc\\Model\\Manager", true),
			"modelsMetadata":     new Service("modelsMetadata", "Phalcon\\Mvc\\Model\\MetaData\\Memory", true),
			"filter":             new Service("filter", "Phalcon\\Filter", true),
			"escaper":            new Service("escaper", "Phalcon\\Escaper", true),
			"annotations":        new Service("annotations", "Phalcon\\Annotations\\Adapter\\Memory", true),
			"security":           new Service("security", "Phalcon\\Security", true),
			"eventsManager":      new Service("eventsManager", "Phalcon\\Events\\Manager", true),
			"transactionManager": new Service("transactionManager", "Phalcon\\Mvc\\Model\\Transaction\\Manager", true)
		];
	}
}
