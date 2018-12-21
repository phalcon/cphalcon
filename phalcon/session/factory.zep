/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
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
	public static function load(var config) -> object
	{
		return self::loadClass("Phalcon\\Session\\Adapter", config);
	}
}
