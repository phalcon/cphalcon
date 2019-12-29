
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
use JsonSerializable;
use Phalcon\Helper\Json as JsonHelper;

class Json extends AbstractSerializer
{
	/**
	 * Serializes data
	 */
	public function serialize() -> string
	{
	    if typeof this->data == "object" && !(this->data instanceof JsonSerializable) {
            throw new InvalidArgumentException(
                "Data for the JSON serializer cannot be of type 'object' " .
                "without implementing 'JsonSerializable'"
            );
        }

        if !this->isSerializable(this->data) {
            return this->data;
        }

		return JsonHelper::encode(this->data);
	}

	/**
	 * Unserializes data
	 */
	public function unserialize(var data) -> void
	{
		let this->data = JsonHelper::decode(data);
	}
}
