
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

namespace Phalcon;

use Phalcon\Config\Exception;

/**
 * Phalcon\Config
 *
 * Phalcon\Config is designed to simplify the access to, and the use of, configuration data within applications.
 * It provides a nested object property based user interface for accessing this configuration data within
 * application code.
 *
 *<code>
 *	$config = new \Phalcon\Config(array(
 *		"database" => array(
 *			"adapter" => "Mysql",
 *			"host" => "localhost",
 *			"username" => "scott",
 *			"password" => "cheetah",
 *			"dbname" => "test_db"
 *		),
 *		"phalcon" => array(
 *			"controllersDir" => "../app/controllers/",
 *			"modelsDir" => "../app/models/",
 *			"viewsDir" => "../app/views/"
 *		)
 * ));
 *</code>
 *
 */
class Config implements \ArrayAccess, \Countable
{

	/**
	 * Phalcon\Config constructor
	 */
	public function __construct(array! arrayConfig = null)
	{
		var key, value;

		for key, value in arrayConfig {
			this->offsetSet(key, value);
		}
	}

	/**
	 * Allows to check whether an attribute is defined using the array-syntax
	 *
	 *<code>
	 * var_dump(isset($config['database']));
	 *</code>
	 */
	public function offsetExists(var index) -> boolean
	{
		let index = strval(index);

		return isset this->{index};
	}

	/**
	 * Gets an attribute from the configuration, if the attribute isn't defined returns null
	 * If the value is exactly null or is not defined the default value will be used instead
	 *
	 *<code>
	 * echo $config->get('controllersDir', '../app/controllers/');
	 *</code>
	 */
	public function get(var index, var defaultValue = null)
	{
		let index = strval(index);

		if isset this->{index} {
			return this->{index};
		}

		return defaultValue;
	}

	/**
	 * Gets an attribute using the array-syntax
	 *
	 *<code>
	 * print_r($config['database']);
	 *</code>
	 */
	public function offsetGet(var index) -> string
	{
		let index = strval(index);

		return this->{index};
	}

	/**
	 * Sets an attribute using the array-syntax
	 *
	 *<code>
	 * $config['database'] = array('type' => 'Sqlite');
	 *</code>
	 */
	public function offsetSet(var index, var value)
	{
		let index = strval(index);

		if typeof value === "array" {
			let this->{index} = new self(value);
		} else {
			let this->{index} = value;
		}
	}

	/**
	 * Unsets an attribute using the array-syntax
	 *
	 *<code>
	 * unset($config['database']);
	 *</code>
	 */
	public function offsetUnset(var index)
	{
		let index = strval(index);

		//unset(this->{index});
		let this->{index} = null;
	}

	/**
	 * Merges a configuration into the current one
	 *
	 *<code>
	 * $appConfig = new \Phalcon\Config(array('database' => array('host' => 'localhost')));
	 * $globalConfig->merge($config2);
	 *</code>
	 */
	public function merge(<Config> config) -> <Config>
	{
		return this->_merge(config);
	}

	/**
	 * Converts recursively the object to an array
	 *
	 *<code>
	 *	print_r($config->toArray());
	 *</code>
	 */
	public function toArray() -> array
	{
		var key, value, arrayConfig;

		let arrayConfig = [];
		for key, value in get_object_vars(this) {
			if typeof value === "object" {
				if method_exists(value, "toArray") {
					let arrayConfig[key] = value->toArray();
				} else {
					let arrayConfig[key] = value;
				}
			} else {
				let arrayConfig[key] = value;
			}
		}
		return arrayConfig;
	}

	/**
	 * Returns the count of properties set in the config
	 *
	 *<code>
	 * print count($config);
	 *</code>
	 *
	 * or
	 *
	 *<code>
	 * print $config->count();
	 *</code>
	 */
	public function count() -> int
	{
		return count(get_object_vars(this));
	}

	/**
	 * Restores the state of a Phalcon\Config object
	 */
	public static function __set_state(array! data) -> <Config>
	{
		return new self(data);
	}

	/**
	 * Helper method for merge configs (forwarding nested config instance)
	 *
	 * @param Config config
	 * @param Config instance = null
	 *
	 * @return Config merged config
	 */
	protected final function _merge(<Config> config, var instance = null) -> <Config>
	{
		var key, value, number;

		if typeof instance !== "object" {
			let instance = this;
		}

		let number = instance->count();

		for key, value in get_object_vars(config) {
			if isset(instance->{key}) && typeof value === "object" && typeof instance->{key} === "object" {
				this->_merge(value, instance->{key});
			} else {
				if typeof key == "integer" {
					let key = strval(number);
					let number++;
				}
				let instance->{key} = value;
			}
		}

		return instance;
	}
}
