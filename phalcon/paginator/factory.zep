
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Paginator;

use Phalcon\Factory as BaseFactory;

/**
 * Loads Paginator Adapter class using 'adapter' option
 *
 *<code>
 * use Phalcon\Paginator\Factory;
 * $builder = $this->modelsManager->createBuilder()
 *                 ->columns("id, name")
 *                 ->from("Robots")
 *                 ->orderBy("name");
 *
 * $options = [
 *     "builder" => $builder,
 *     "limit"   => 20,
 *     "page"    => 1,
 *     "adapter" => "queryBuilder",
 * ];
 * $paginator = Factory::load($options);
 *</code>
 */
class Factory extends BaseFactory
{
	/**
	 * @param \Phalcon\Config|array config
	 */
	public static function load(var config) -> object
	{
		return self::loadClass("Phalcon\\Paginator\\Adapter", config);
	}
}
