
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

namespace Phalcon\Config;

use Phalcon\Factory as BaseFactory;
use Phalcon\Factory\Exception;
use Phalcon\Config;

/**
 * Loads Config Adapter class using 'adapter' option, if no extension is provided it will be added to filePath
 *
 *<code>
 * use Phalcon\Config\Factory;
 *
 * $options = [
 *     "filePath" => "path/config",
 *     "adapter"  => "php",
 * ];
 * $config = Factory::load($options);
 *</code>
 */
class Factory extends BaseFactory
{
	/**
	 * @param \Phalcon\Config|array config
	 */
	public static function load(var config) -> <Config>
	{
		return self::loadClass("Phalcon\\Config\\Adapter", config);
	}

	public static function loadForDi(var config) -> array
	{
		return self::loadAsArray("Phalcon\\Config\\Adapter", config);
	}

	protected static function loadClass(string $namespace, var config)
	{
		var className, mode, callbacks, params;

		let params = self::checkArguments($namespace, config);
		let className = params["className"];

		if className == "Phalcon\\Config\\Adapter\\Ini" && fetch mode, params["mode"] {
			return new {className}(params["filePath"], mode);
		} elseif className == "Phalcon\\Config\\Adapter\\Yaml" && fetch callbacks, params["callbacks"] {
			return new {className}(params["filePath"], callbacks);
		}

		return new {className}(params["filePath"]);
	}

	protected static function loadAsArray(string $namespace, var config)
	{
		var className, mode, callbacks, params;

		let params = self::checkArguments($namespace, config);

		let className = params["className"];

		if className == "Phalcon\\Config\\Adapter\\Ini" && fetch mode, params["mode"] {
			return [
				"className" : className,
				"arguments" : [
					[
						"type" : "parameter",
						"value" : params["filePath"]
					],
					[
						"type" : "parameter",
						"value" : mode
					]
				]
			];
		} elseif className == "Phalcon\\Config\\Adapter\\Yaml" && fetch callbacks, params["callbacks"] {
			return [
				"className" : className,
				"arguments" : [
					[
						"type" : "parameter",
						"value" : params["filePath"]
					],
					[
						"type" : "parameter",
						"value" : callbacks
					]
				]
			];
		}

		return [
			"className" : className,
			"arguments" : [
				[
					"type" : "parameter",
					"value" : params["filePath"]
				]
			]
		];
	}

	protected static function checkArguments(string $namespace, var config)
	{
		var adapter, className, mode, callbacks, filePath, params;

		let params = [];

		if typeof config == "object" && config instanceof Config {
			let config = config->toArray();
		}

		if typeof config != "array" {
			throw new Exception("Config must be array or Phalcon\\Config object");
		}

		if !fetch filePath, config["filePath"] {
			throw new Exception("You must provide 'filePath' option in factory config parameter.");
		}

		if fetch adapter, config["adapter"] {
			let className = $namespace."\\".camelize(adapter);
			if !strpos(filePath, ".") {
				let filePath = filePath.".".lcfirst(adapter);
			}

			let params["className"] = className;
			let params["filePath"] = filePath;

			if className == "Phalcon\\Config\\Adapter\\Ini" {
				if fetch mode, config["mode"] {
					let params["mode"] = mode;
				}
			} elseif className == "Phalcon\\Config\\Adapter\\Yaml" {
				if fetch callbacks, config["callbacks"] {
					let params["callbacks"] = callbacks;
				}
			}

			return params;
		} else {
			throw new Exception("You must provide 'adapter' option in factory config parameter.");
		}
	}
}
