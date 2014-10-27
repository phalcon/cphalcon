
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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
class Config implements \ArrayAccess
{

	/**
	 * Phalcon\Config constructor
	 */
	public function __construct(array! arrayConfig = null)
	{
		var key, value, subkey, subvalue;
		boolean hasNumericKey;

		for key, value in arrayConfig {

			/**
			 * Phalcon\Config does not support numeric keys as properties
			 */
			if typeof key != "string" {
				throw new Exception("Only string keys are allowed as configuration properties");
			}

			if typeof value == "array" {
				let hasNumericKey = false;
				for subkey, subvalue in value {
					if typeof subkey == "int" {
						let hasNumericKey = true;
						break;
					}
				}
				if hasNumericKey {
					let this->{key} = value;
				} else {
					let this->{key} = new \Phalcon\Config(value);
				}
			} else {
				let this->{key} = value;
			}

		}
	}

	/**
	 * Allows to check whether an attribute is defined using the array-syntax
	 *
	 *<code>
	 * var_dump(isset($config['database']));
	 *</code>
	 */
	public function offsetExists(string! index) -> boolean
	{
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
	public function get(string! index, var defaultValue = null)
	{
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
	public function offsetGet(string! index) -> string
	{
		return this->{index};
	}

	/**
	 * Sets an attribute using the array-syntax
	 *
	 *<code>
	 * $config['database'] = array('type' => 'Sqlite');
	 *</code>
	 */
	public function offsetSet(string! index, var value)
	{
	    let this->{index} = value;
	}

	/**
	 * Unsets an attribute using the array-syntax
	 *
	 *<code>
	 * unset($config['database']);
	 *</code>
	 */
	public function offsetUnset(string! index)
	{
		//unset(this->{index});
		let this->{index} = null;
	}

	/**
	 * Merges a configuration into the current one
	 *
	 *<code>
	 *	$appConfig = new \Phalcon\Config(array('database' => array('host' => 'localhost')));
	 *	$globalConfig->merge($config2);
	 *</code>
	 */
	public function merge(<Config> config)
	{
        var key, value;

        for key, value in get_object_vars(config) {
            if (isset(this->{key})) {

            } else {
                let this->{key} = value;
            }
        }
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
			if typeof value == "object" {
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
	 * Restores the state of a Phalcon\Config object
	 */
	public static function __set_state(array! data) -> <Config>
	{
		return new self(data);
	}
}
