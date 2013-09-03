
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

namespace Phalcon\DI;

/**
 * Phalcon\DI\FactoryDefault
 *
 * This is a variant of the standard Phalcon\DI. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the developer does not need
 * to register each service individually providing a full stack framework
 */
class FactoryDefault extends Phalcon\DI
{

	/**
	 * Phalcon\DI\FactoryDefault constructor
	 */
	public function __construct()
	{
		var shared;

		parent::__construct();

		let shared = true;

		let this->_services = [
			"router" => new Phalcon\DI\Service("router", "Phalcon\\Mvc\\Router", shared),
			"dispatcher" => new Phalcon\DI\Service("dispatcher", "Phalcon\\Mvc\\Dispatcher", shared),
			"url" => new Phalcon\DI\Service("url", "Phalcon\\Mvc\\Url", shared),
			"modelsManager" => new Phalcon\DI\Service("modelsManager", "Phalcon\\Mvc\\Model\\Manager", shared),
			"modelsMetadata" => new Phalcon\DI\Service("modelsMetadata", "Phalcon\\Mvc\\Model\\MetaData\\Memory", shared),
			"response" => new Phalcon\DI\Service("response", "Phalcon\\Http\\Response", shared),
			"cookies" => new Phalcon\DI\Service("cookies", "Phalcon\\Http\\Response\\Cookies", shared),
			"request" => new Phalcon\DI\Service("request", "Phalcon\\Http\\Request", shared),
			"filter" => new Phalcon\DI\Service("filter", "Phalcon\\Filter", shared),
			"escaper" => new Phalcon\DI\Service("escaper", "Phalcon\\Escaper", shared),
			"security" => new Phalcon\DI\Service("security", "Phalcon\\Security", shared),
			"crypt" => new Phalcon\DI\Service("crypt", "Phalcon\\Crypt", shared),
			"annotations" => new Phalcon\DI\Service("annotations", "Phalcon\\Annotations\\Adapter\\Memory", shared),
			"flash" => new Phalcon\DI\Service("flash", "Phalcon\\Flash\\Direct", shared),
			"flashSession" => new Phalcon\DI\Service("flashSession", "Phalcon\\Flash\\Session", shared),
			"tag" => new Phalcon\DI\Service("tag", "Phalcon\\Tag", shared),
			"session" => new Phalcon\DI\Service("session", "Phalcon\\Session\\Adapter\\Files", shared),
			"sessionBag" => new Phalcon\DI\Service("sessionBag", "Phalcon\\Session\\Bag"),
			"eventsManager" => new Phalcon\DI\Service("eventsManager", "Phalcon\\Events\\Manager", shared),
			"transactionManager" => new Phalcon\DI\Service("transactions", "Phalcon\\Mvc\\Model\\Transaction\\Manager", shared),
			"assets" => new Phalcon_DI_Service("assets", "Phalcon\\Assets\\Manager", shared)
		];

	}

}