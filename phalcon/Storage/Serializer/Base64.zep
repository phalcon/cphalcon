
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

class Base64 extends AbstractSerializer
{
	/**
	 * Serializes data
	 */
	public function serialize() -> string
	{
	    if typeof this->data !== "string" {
	        throw new InvalidArgumentException(
	        	"Data for the serializer must of type string"
	        );
	    }

		return base64_encode(this->data);
	}

	/**
	 * Unserializes data
	 */
	public function unserialize(var data) -> void
	{
	    if typeof data !== "string" {
	        throw new InvalidArgumentException(
	        	"Data for the unserializer must of type string"
	        );
	    }

		let this->data = base64_decode(data);
	}
}
