
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

 /**
 * Phalcon\Di\Presets\Cli
 *
 * This is a variant of the standard Phalcon\Di. By default it automatically
 * registers all the services provided by the framework.
 * Thanks to this, the developer does not need to register each service individually.
 * This class is specially suitable for CLI applications
 */
class Cli extends Di implements PresetInterface
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
			"dispatcher":         "Phalcon\\Cli\\Dispatcher",
			"escaper":            "Phalcon\\Escaper",
			"escaper":            "Phalcon\\Escaper",
			"eventsManager":      "Phalcon\\Events\\Manager",
			"filter":             filter->newInstance(),
			// "filter":             "Phalcon\\Filter",
			"flash":              "Phalcon\\Flash\\Direct",
			"flashSession":       "Phalcon\\Flash\\Session",
			"modelsManager":      "Phalcon\\Mvc\\Model\\Manager",
			"modelsMetadata":     "Phalcon\\Mvc\\Model\\MetaData\\Memory",
			"router":             "Phalcon\\Cli\\Router",
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
	 * Phalcon\Di\Presets\Cli constructor
	 */
	public function __construct()
	{
		parent::__construct();

		self::configure(this);
	}
}
