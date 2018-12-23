
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Mvc\Model;

use Phalcon\Cache\BackendInterface;

/**
 * Phalcon\Mvc\Model\BinderInterface
 *
 * Interface for Phalcon\Mvc\Model\Binder
 */
interface BinderInterface
{
	/**
	 * Gets active bound models
	 */
	public function getBoundModels() -> array;

	/**
	 * Gets cache instance
	 */
	public function getCache() -> <BackendInterface>;

	/**
	 * Sets cache instance
	 */
	public function setCache(<BackendInterface> cache) -> <BinderInterface>;

	/**
	 * Bind models into params in proper handler
	 */
	public function bindToHandler(object handler, array params, string cacheKey, string! methodName = null) -> array;
}
