
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
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

namespace Phalcon\Session;

use Phalcon\Factory as BaseFactory;


/**
 * Loads Session Adapter class using 'adapter' option
 *
 *<code>
 * use Phalcon\Session\Factory;
 *
 * $options = [
 *     "uniqueId"   => "my-private-app",
 *     "host"       => "127.0.0.1",
 *     "port"       => 11211,
 *     "persistent" => true,
 *     "lifetime"   => 3600,
 *     "prefix"     => "my_",
 *     "adapter"    => "memcache",
 * ];
 * $session = Factory::load($options);
 *</code>
 */
class Factory extends BaseFactory
{
	/**
	 * @param \Phalcon\Config|array config
	 */
	public static function load(var config) -> <AdapterInterface>
	{
		return self::loadClass("Phalcon\\Session\\Adapter", config);
	}
}
