
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Service;

/**
 * Phalcon\Service\ServiceInterface
 *
 * Interface for the Service
 */
interface ServiceInterface
{
	/**
	 * Where the magic happens. It must utilzie the `func_get_args` to
	 * retrieve data
	 */
	public function __invoke();
}
