
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl;

/**
 * Phalcon\Acl\OperationInterface
 *
 * Interface for Phalcon\Acl\Operation
 */
interface OperationInterface
{
	/**
	 * Returns the operation name
	 */
	public function getName() -> string;

	/**
	 * Returns operation description
	 */
	public function getDescription() -> string;

	/**
	 * Magic method __toString
	 */
	public function __toString() -> string;

}
