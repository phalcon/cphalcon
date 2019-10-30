
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

use InvalidArgumentException;

class None extends AbstractSerializer
{
	/**
	 * Serializes data
	 */
	public function serialize() -> string
	{
		return this->data;
	}

	/**
	 * Unserializes data
	 */
	public function unserialize(var data) -> void
	{
		let this->data = data;
	}
}
