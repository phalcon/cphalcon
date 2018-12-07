
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger;

use Phalcon\Config;
use Phalcon\Factory as BaseFactory;
use Phalcon\Factory\Exception;
use Phalcon\Logger;

/**
 * Loads Logger Adapter class using 'adapter' option
 *
 *<code>
 *  use Phalcon\Logger\Factory;
 *
 *  $options = [
 *      'adapters' => [
 *          'type' => 'stream',
 *          'name' => 'log.txt',
 *      ]
 *  ];
 *
 *  $logger = Factory::load($options);
 *</code>
 */
class Factory extends BaseFactory
{
	/**
	 * @param \Phalcon\Config|array config
	 */
	public static function load(var config) -> object
	{
		return self::loadClass("Phalcon\\Logger\\Adapter", config);
	}

	protected static function loadClass(string objectName, var config)
	{
		var adapter, adapterName, adapters, className, element, key, logger, loggerName, name, type;

		if typeof config == "object" && config instanceof Config {
			let config = config->toArray();
		}

		if typeof config != "array" {
			throw new Exception("Config must be array or Phalcon\\Config object");
		}

		if !fetch loggerName, config["name"] {
			throw new Exception("You must provide the 'name' option in factory config parameter.");
		}

		if !fetch adapters, config["adapters"] {
			throw new Exception("You must provide the 'adapters' option in factory config parameter.");
		}

		/**
		 * Loop through the adapters and ensure that they are ok.
		 */
		for adapter in adapters {
			if !fetch name, adapter["name"] {
				throw new Exception("The adapters section of your configuration is missing the 'name' option");
			}

			if !fetch type, adapter["adapter"] {
				throw new Exception("The adapters section of your configuration is missing the 'adapter' option");
			}
		}

		/**
		 * If we got to here everything is OK. Lets set the objects
		 */
		let logger = new Logger(loggerName);

		for key, element in adapters {
			let name = element["name"],
				type = element["adapter"],
				adapterName = "A" . key,
				className = objectName . "\\" . camelize(type),
				adapter = new {className}(name);

			logger->addAdapter(adapterName, adapter);
		}

		return logger;
	}
}
