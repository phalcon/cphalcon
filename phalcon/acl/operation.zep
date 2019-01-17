
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Acl;

use Phalcon\Acl\Exception;

/**
 * Phalcon\Acl\Operation
 *
 * This class defines operation entity and its description
 */
class Operation implements OperationInterface
{
	/**
	 * Operation name
	 * @var string
	 */
	protected name { get, __toString };

	/**
	 * Operation description
	 * @var string
	 */
	protected description { get };

	/**
	 * Phalcon\Acl\Operation constructor
	 */
	public function __construct(string! name, string description = null)
	{
		if name == "*" {
			throw new Exception("Operation name cannot be '*'");
		}
		let this->name = name;

		if description {
			let this->description = description;
		}
	}
}
