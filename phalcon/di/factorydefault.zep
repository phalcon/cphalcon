
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

namespace Phalcon\Di;

/**
 * Phalcon\Di\FactoryDefault
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the developer does not need
 * to register each service individually providing a full stack framework
 */
class FactoryDefault extends Phalcon\Di
{

	/**
	 * Phalcon\Di\FactoryDefault constructor
	 */
	public function __construct()
	{

		parent::__construct();

		let this->_services = [
			"router": new Phalcon\Di\Service("router", "Phalcon\\Mvc\\Router", true),
			"dispatcher": new Phalcon\Di\Service("dispatcher", "Phalcon\\Mvc\\Dispatcher", true),
			"url": new Phalcon\Di\Service("url", "Phalcon\\Mvc\\Url", true),
			"modelsManager": new Phalcon\Di\Service("modelsManager", "Phalcon\\Mvc\\Model\\Manager", true),
			"modelsMetadata": new Phalcon\Di\Service("modelsMetadata", "Phalcon\\Mvc\\Model\\MetaData\\Memory", true),
			"response": new Phalcon\Di\Service("response", "Phalcon\\Http\\Response", true),
			"cookies": new Phalcon\Di\Service("cookies", "Phalcon\\Http\\Response\\Cookies", true),
			"request": new Phalcon\Di\Service("request", "Phalcon\\Http\\Request", true),
			"filter": new Phalcon\Di\Service("filter", "Phalcon\\Filter", true),
			"escaper": new Phalcon\Di\Service("escaper", "Phalcon\\Escaper", true),
			"security": new Phalcon\Di\Service("security", "Phalcon\\Security", true),
			"crypt": new Phalcon\Di\Service("crypt", "Phalcon\\Crypt", true),
			"annotations": new Phalcon\Di\Service("annotations", "Phalcon\\Annotations\\Adapter\\Memory", true),
			"flash": new Phalcon\Di\Service("flash", "Phalcon\\Flash\\Direct", true),
			"flashSession": new Phalcon\Di\Service("flashSession", "Phalcon\\Flash\\Session", true),
			"tag": new Phalcon\Di\Service("tag", "Phalcon\\Tag", true),
			"session": new Phalcon\Di\Service("session", "Phalcon\\Session\\Adapter\\Files", true),
			"sessionBag": new Phalcon\Di\Service("sessionBag", "Phalcon\\Session\\Bag"),
			"eventsManager": new Phalcon\Di\Service("eventsManager", "Phalcon\\Events\\Manager", true),
			"transactionManager": new Phalcon\Di\Service("transactions", "Phalcon\\Mvc\\Model\\Transaction\\Manager", true),
			"assets": new Phalcon\Di\Service("assets", "Phalcon\\Assets\\Manager", true)
		];

	}

}