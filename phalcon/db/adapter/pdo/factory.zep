
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Db\Adapter\Pdo;

use Phalcon\Factory as BaseFactory;
use Phalcon\Db\AdapterInterface;

/**
 * Loads PDO Adapter class using 'adapter' option
 *
 *<code>
 * use Phalcon\Db\Adapter\Pdo\Factory;
 *
 * $options = [
 *     "host"     => "localhost",
 *     "dbname"   => "blog",
 *     "port"     => 3306,
 *     "username" => "sigma",
 *     "password" => "secret",
 *     "adapter"  => "mysql",
 * ];
 * $db = Factory::load($options);
 *</code>
 */
class Factory extends BaseFactory
{
	/**
	 * @param \Phalcon\Config|array config
	 */
	public static function load(var config) -> object
	{
		return self::loadClass("Phalcon\\Db\\Adapter\\Pdo", config);
	}
}
