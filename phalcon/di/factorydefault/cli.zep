
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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
 * Phalcon\Di\FactoryDefault\Cli
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework.
 * Thanks to this, the developer does not need to register each service individually.
 * This class is specially suitable for CLI applications
 */
class Cli extends FactoryDefault
{

	/**
	 * Phalcon\Di\FactoryDefault\Cli constructor
	 */
	public function __construct()
	{
		parent::__construct();

		let this->_services = [
			"router":             new Service("Phalcon\\Cli\\Router", true),
			"dispatcher":         new Service("Phalcon\\Cli\\Dispatcher", true),
			"modelsManager":      new Service("Phalcon\\Mvc\\Model\\Manager", true),
			"modelsMetadata":     new Service("Phalcon\\Mvc\\Model\\MetaData\\Memory", true),
			"filter":             new Service("Phalcon\\Filter", true),
			"escaper":            new Service("Phalcon\\Escaper", true),
			"annotations":        new Service("Phalcon\\Annotations\\Adapter\\Memory", true),
			"security":           new Service("Phalcon\\Security", true),
			"eventsManager":      new Service("Phalcon\\Events\\Manager", true),
			"transactionManager": new Service("Phalcon\\Mvc\\Model\\Transaction\\Manager", true)
		];
	}
}
