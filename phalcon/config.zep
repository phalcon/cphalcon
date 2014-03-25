
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
	 *
	 * @param	array arrayConfig
	 */
	public function __construct(arrayConfig=null)
	{
		var key, value, subkey, subvalue;
		boolean hasNumericKey;

		/**
		 * Throw exceptions if bad parameters are passed
		 */
		if typeof arrayConfig != "array" {
			if typeof arrayConfig != "null" {
				throw new \Phalcon\Config\Exception("The configuration must be an Array");
			} else {
				return;
			}
		}

		for key, value in arrayConfig {

			/**
			 * Phalcon\Config does not support numeric keys as properties
			 */
			if typeof key != "string" {
				throw new \Phalcon\Config\Exception("Only string keys are allowed as configuration properties");
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
	 *
	 * @param string index
	 * @return boolean
	 */
	public function offsetExists(string! index)
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
	 *
	 * @param string index
	 * @param mixed defaultValue
	 * @return mixed
	 */
	public function get(index, defaultValue=null)
	{

	}

	/**
	 * Gets an attribute using the array-syntax
	 *
	 *<code>
	 * print_r($config['database']);
	 *</code>
	 *
	 * @param string index
	 * @return string
	 */
	public function offsetGet(string! index)
	{
		return this->{index};
	}

	/**
	 * Sets an attribute using the array-syntax
	 *
	 *<code>
	 * $config['database'] = array('type' => 'Sqlite');
	 *</code>
	 *
	 * @param string $index
	 * @param mixed $value
	 */
	public function offsetSet($index, $value)
	{
	}

	/**
	 * Unsets an attribute using the array-syntax
	 *
	 *<code>
	 * unset($config['database']);
	 *</code>
	 *
	 * @param string index
	 */
	public function offsetUnset(index)
	{
		return true;
	}

	/**
	 * Merges a configuration into the current one
	 *
	 *<code>
	 *	$appConfig = new \Phalcon\Config(array('database' => array('host' => 'localhost')));
	 *	$globalConfig->merge($config2);
	 *</code>
	 *
	 * @param Phalcon\Config $config
	 */
	public function merge(config)
	{

	}

	/**
	 * Converts recursively the object to an array
	 *
	 *<code>
	 *	print_r($config->toArray());
	 *</code>
	 *
	 * @return array
	 */
	public function toArray()
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
	 *
	 * @param array data
	 * @return Phalcon\Config
	 */
	public static function __set_state(data) -> <\Phalcon\Config>
	{
		return new self(data);
	}

}
