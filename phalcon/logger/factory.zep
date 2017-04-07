
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
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
 |          Wojciech Ślawski <jurigag@gmail.com>                          |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Logger;

use Phalcon\Factory as BaseFactory;
use Phalcon\Factory\Exception;
use Phalcon\Config;

/**
 * Loads Logger Adapter class using 'adapter' option
 *
 *<code>
 * use Phalcon\Logger\Factory;
 *
 * $options = [
 *     "name"    => "log.txt",
 *     "adapter" => "file",
 * ];
 * $logger = Factory::load($options);
 *</code>
 */
class Factory extends BaseFactory
{
	/**
	 * @param \Phalcon\Config|array config
	 */
	public static function load(var config) -> <AdapterInterface>
	{
		return self::loadClass("Phalcon\\Logger\\Adapter", config);
	}

	public static function loadForDi(var config) -> array
	{
		return self::loadAsArray("Phalcon\\Logger\\Adapter", config);
	}

	protected static function loadClass(string $namespace, var config)
	{
		var className, params;

		let params = self::checkArguments($namespace, config);
		let className = params["className"];

		if className != "Phalcon\\Logger\\Adapter\\Firephp" {
			return new {className}(params["name"], params["config"]);
		}

		return new {className}();
	}

	protected static function loadAsArray(string $namespace, var config)
	{
		var className, params;

		let params = self::checkArguments($namespace, config);

		let className = params["className"];

		if className != "Phalcon\\Logger\\Adapter\\Firephp" {
			return [
				"className" : className,
				"arguments" : [
					[
						"type" : "parameter",
						"value" : params["name"]
					],
					[
						"type" : "parameter",
						"value" : params["config"]
					]
				]
			];
		}

		return [
			"className" : "Phalcon\\Logger\\Adapter\\Firephp"
		];
	}

	protected static function checkArguments(string $namespace, var config)
	{
		var adapter, className, name, params;

		let params = [];

		if typeof config == "object" && config instanceof Config {
        	let config = config->toArray();
        }

        if typeof config != "array" {
        	throw new Exception("Config must be array or Phalcon\\Config object");
        }

        if fetch adapter, config["adapter"] {
        	let className = $namespace."\\".camelize(adapter);
        	let params["className"] = className;

        	if className != "Phalcon\\Logger\\Adapter\\Firephp" {
				unset config["adapter"];
				if !fetch name, config["name"] {
					throw new Exception("You must provide 'name' option in factory config parameter.");
				}

				let params["name"] = name;
				unset config["name"];
				let params["config"] = config;
			}

			return params;
		} else {
			throw new Exception("You must provide 'adapter' option in factory config parameter.");
		}
	}
}
