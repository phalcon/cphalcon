/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Session;

/**
 * Phalcon\Session\AdapterInterface
 *
 * Interface for Phalcon\Session adapters
 */
interface AdapterInterface
{
	/**
	 * Destroys the active session
	 */
	public function destroy(boolean removeData = false) -> boolean;

	/**
	 * Gets a session variable from an application context
	 */
	public function get(string index, var defaultValue = null) -> var;

	/**
	 * Returns active session id
	 */
	public function getId() -> string;

	/**
	 * Get session name
	 */
	public function getName() -> string;

	/**
	 * Get internal options
	 */
	public function getOptions() -> array;

	/**
	 * Check whether a session variable is set in an application context
	 */
	public function has(string index) -> boolean;

	/**
	 * Check whether the session has been started
	 */
	public function isStarted() -> boolean;

	/**
	 * Regenerate session's id
	 */
	public function regenerateId(bool deleteOldSession = true) -> <AdapterInterface>;

	/**
	 * Removes a session variable from an application context
	 */
	public function remove(string index);

	/**
	 * Sets a session variable in an application context
	 */
	public function set(string index, var value);

	/**
	 * Set session name
	 */
	public function setName(string name);

	/**
	 * Sets session options
	 */
	public function setOptions(array! options);

	/**
	 * Starts session, optionally using an adapter
	 */
	public function start();
}
