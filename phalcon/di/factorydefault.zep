
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
			"router":             new Service("router", "Phalcon\\Mvc\\Router", true),
			"dispatcher":         new Service("dispatcher", "Phalcon\\Mvc\\Dispatcher", true),
			"url":                new Service("url", "Phalcon\\Mvc\\Url", true),
			"modelsManager":      new Service("modelsManager", "Phalcon\\Mvc\\Model\\Manager", true),
			"modelsMetadata":     new Service("modelsMetadata", "Phalcon\\Mvc\\Model\\MetaData\\Memory", true),
			"response":           new Service("response", "Phalcon\\Http\\Response", true),
			"cookies":            new Service("cookies", "Phalcon\\Http\\Response\\Cookies", true),
			"request":            new Service("request", "Phalcon\\Http\\Request", true),
			"filter":             new Service("filter", "Phalcon\\Filter", true),
			"escaper":            new Service("escaper", "Phalcon\\Escaper", true),
			"security":           new Service("security", "Phalcon\\Security", true),
			"crypt":              new Service("crypt", "Phalcon\\Crypt", true),
			"annotations":        new Service("annotations", "Phalcon\\Annotations\\Adapter\\Memory", true),
			"flash":              new Service("flash", "Phalcon\\Flash\\Direct", true),
			"flashSession":       new Service("flashSession", "Phalcon\\Flash\\Session", true),
			"tag":                new Service("tag", "Phalcon\\Tag", true),
			"session":            new Service("session", "Phalcon\\Session\\Adapter\\Files", true),
			"sessionBag":         new Service("sessionBag", "Phalcon\\Session\\Bag"),
			"eventsManager":      new Service("eventsManager", "Phalcon\\Events\\Manager", true),
			"transactionManager": new Service("transactions", "Phalcon\\Mvc\\Model\\Transaction\\Manager", true),
			"assets":             new Service("assets", "Phalcon\\Assets\\Manager", true)
		];
	}
}