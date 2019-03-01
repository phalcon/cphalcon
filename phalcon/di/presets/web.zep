
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
			"annotations":        "Phalcon\\Annotations\\Adapter\\Memory",
			"assets":             "Phalcon\\Assets\\Manager",
			"crypt":              "Phalcon\\Crypt",
			"cookies":            "Phalcon\\Http\\Response\\Cookies",
			"dispatcher":         "Phalcon\\Mvc\\Dispatcher",
			"escaper":            "Phalcon\\Escaper",
			"eventsManager":      "Phalcon\\Events\\Manager",
			"flash":              "Phalcon\\Flash\\Direct",
			"flashSession":       "Phalcon\\Flash\\Session",
			"filter":             filter->newInstance(),
			// "filter":             "Phalcon\\Filter",
			"modelsManager":      "Phalcon\\Mvc\\Model\\Manager",
			"modelsMetadata":     "Phalcon\\Mvc\\Model\\MetaData\\Memory",
			"request":            "Phalcon\\Http\\Request",
			"response":           "Phalcon\\Http\\Response",
			"router":             "Phalcon\\Mvc\\Router",
			"security":           "Phalcon\\Security",
			"tag":                "Phalcon\\Tag",
			"transactionManager": "Phalcon\\Mvc\\Model\\Transaction\\Manager",
			"url":                "Phalcon\\Url"
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
