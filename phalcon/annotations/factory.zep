
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Annotations;

use Phalcon\Factory as BaseFactory;

/**
 * Loads Annotations Adapter class using 'adapter' option
 *
 *<code>
 * use Phalcon\Annotations\Factory;
 *
 * $options = [
 *     "prefix"   => "annotations",
 *     "lifetime" => "3600",
 *     "adapter"  => "apc",
 * ];
 * $annotations = Factory::load($options);
 *</code>
 */
class Factory extends BaseFactory
{
	/**
	 * @param \Phalcon\Config|array config
	 */
	public static function load(var config) -> object
	{
		return self::loadClass("Phalcon\\Annotations\\Adapter", config);
	}
}
