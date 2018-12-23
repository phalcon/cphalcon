
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Cache;

/**
 * Phalcon\Cache\FrontendInterface
 *
 * Interface for Phalcon\Cache\Frontend adapters
 */
interface FrontendInterface
{

	/**
	 * Returns the cache lifetime
	 */
	public function getLifetime() -> int;

	/**
	 * Check whether if frontend is buffering output
	 */
	public function isBuffering() -> bool;

	/**
	 * Starts the frontend
	 */
	public function start();

	/**
	 * Returns output cached content
	 *
	 * @return string
	 */
	public function getContent();

	/**
	 * Stops the frontend
	 */
	public function stop();

	/**
	 * Serializes data before storing it
	 *
	 * @param mixed data
	 */
	public function beforeStore(data);

	/**
	 * Unserializes data after retrieving it
	 *
	 * @param mixed data
	 */
	public function afterRetrieve(data);
}
