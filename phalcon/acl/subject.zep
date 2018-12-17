
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
 * Phalcon\Acl\Subject
 *
 * This class defines subject entity and its description
 */
class Subject implements SubjectInterface
{

	/**
	 * Subject description
	 * @var string
	 */
	protected description { get };

	/**
	 * Subject name
	 * @var string
	 */
	protected name { get, __toString };

	/**
	 * Phalcon\Acl\Subject constructor
	 */
	public function __construct(string! name, string description = null)
	{
		if name == "*" {
			throw new Exception("Subject name cannot be '*'");
		}

		let this->name = name;
		if description {
			let this->description = description;
		}
	}
}
