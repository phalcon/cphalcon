
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon;

/**
 * Phalcon\FlashInterface
 *
 * Interface for Phalcon\Flash
 */
interface FlashInterface
{

	/**
	 * Shows a HTML error message
	 */
	public function error(string message);

	/**
	 * Outputs a message
	 */
	public function message(string type, string message);

	/**
	 * Shows a HTML notice/information message
	 */
	public function notice(string message);

	/**
	 * Shows a HTML success message
	 */
	public function success(string message);

	/**
	 * Shows a HTML warning message
	 */
	public function warning(string message);
}
