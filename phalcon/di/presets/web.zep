
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Di\Presets;

use Phalcon\Di;
use Phalcon\Di\PresetInterface;
use Phalcon\Di\Service;
use Phalcon\DiInterface;
use Phalcon\Filter\FilterLocatorFactory;

/**
 * Phalcon\Di\Presets\Web
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework. Thanks to this, the developer does not need
 * to register each service individually providing a full stack framework
 */
class Web extends Di implements PresetInterface
{

	/**
	 *
	 */
	public static function configure(<DiInterface> di, bool force = true)
	{
		var filter, serviceDefinition, serviceName, services;

		let filter = new FilterLocatorFactory();

		let services = [
			"annotations":        new Service("Phalcon\\Annotations\\Adapter\\Memory", true),
			"assets":             new Service("Phalcon\\Assets\\Manager", true),
			"crypt":              new Service("Phalcon\\Crypt", true),
			"cookies":            new Service("Phalcon\\Http\\Response\\Cookies", true),
			"dispatcher":         new Service("Phalcon\\Mvc\\Dispatcher", true),
			"escaper":            new Service("Phalcon\\Escaper", true),
			"eventsManager":      new Service("Phalcon\\Events\\Manager", true),
			"flash":              new Service("Phalcon\\Flash\\Direct", true),
			"flashSession":       new Service("Phalcon\\Flash\\Session", true),
			"filter":             new Service(filter->newInstance(), true),
//			"filter":             new Service("Phalcon\\Filter", true),
			"modelsManager":      new Service("Phalcon\\Mvc\\Model\\Manager", true),
			"modelsMetadata":     new Service("Phalcon\\Mvc\\Model\\MetaData\\Memory", true),
			"request":            new Service("Phalcon\\Http\\Request", true),
			"response":           new Service("Phalcon\\Http\\Response", true),
			"router":             new Service("Phalcon\\Mvc\\Router", true),
			"security":           new Service("Phalcon\\Security", true),
			"tag":                new Service("Phalcon\\Tag", true),
			"transactionManager": new Service("Phalcon\\Mvc\\Model\\Transaction\\Manager", true),
			"url":                new Service("Phalcon\\Url", true)
		];

		for serviceName, serviceDefinition in services {
			if force {
				di->set(serviceName, serviceDefinition, true);
			} else {
				di->attempt(serviceName, serviceDefinition, true);
			}
		}
	}

	/**
	 * Phalcon\Di\Presets\Web constructor
	 */
	public function __construct()
	{
		parent::__construct();

		self::configure(this);
	}
}
