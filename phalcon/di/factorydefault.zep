
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

namespace Phalcon\Di;

/**
 * Phalcon\Di\FactoryDefault
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the developer does not need
 * to register each service individually providing a full stack framework
 */
class FactoryDefault extends \Phalcon\Di
{

	/**
	 * Phalcon\Di\FactoryDefault constructor
	 */
	public function __construct()
	{
		parent::__construct();

		let this->_services = [
			"router":             new Service("Phalcon\\Mvc\\Router", true),
			"dispatcher":         new Service("Phalcon\\Mvc\\Dispatcher", true),
			"url":                new Service("Phalcon\\Mvc\\Url", true),
			"modelsManager":      new Service("Phalcon\\Mvc\\Model\\Manager", true),
			"modelsMetadata":     new Service("Phalcon\\Mvc\\Model\\MetaData\\Memory", true),
			"response":           new Service("Phalcon\\Http\\Response", true),
			"cookies":            new Service("Phalcon\\Http\\Response\\Cookies", true),
			"request":            new Service("Phalcon\\Http\\Request", true),
			"filter":             new Service("Phalcon\\Filter", true),
			"escaper":            new Service("Phalcon\\Escaper", true),
			"security":           new Service("Phalcon\\Security", true),
			"crypt":              new Service("Phalcon\\Crypt", true),
			"annotations":        new Service("Phalcon\\Annotations\\Adapter\\Memory", true),
			"flash":              new Service("Phalcon\\Flash\\Direct", true),
			"flashSession":       new Service("Phalcon\\Flash\\Session", true),
			"tag":                new Service("Phalcon\\Tag", true),
			"session":            new Service("Phalcon\\Session\\Adapter\\Files", true),
			"sessionBag":         new Service("Phalcon\\Session\\Bag"),
			"eventsManager":      new Service("Phalcon\\Events\\Manager", true),
			"transactionManager": new Service("Phalcon\\Mvc\\Model\\Transaction\\Manager", true),
			"assets":             new Service("Phalcon\\Assets\\Manager", true)
		];
	}
}
