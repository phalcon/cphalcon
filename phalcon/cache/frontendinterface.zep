
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2015 Phalcon Team (http://www.phalconphp.com)       |
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
	public function isBuffering() -> boolean;

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
