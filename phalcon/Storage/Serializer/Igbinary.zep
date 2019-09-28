
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

use Phalcon\Storage\Serializer\AbstractSerializer;

class Igbinary extends AbstractSerializer
{
	/**
	 * Serializes data
	 */
	public function serialize() -> string
	{
        if !this->isSerializable(this->data) {
            return this->data;
        }

		return igbinary_serialize(this->data);
	}

	/**
	 * Unserializes data
	 */
	public function unserialize(var data) -> void
	{
		let this->data = igbinary_unserialize(data);
	}

	/**
     * Workaround for warning
     * Related to https://github.com/msgpack/msgpack-php/issues/41 ?
     */
    private function igbinary_unserialize(var data)
    {
        let this->warning = false;

        set_error_handler(
            function (number, message, file, line, context) {
                if number === E_WARNING {
                    let this->warning = true;
                }
            }
        );

        let data = igbinary_unserialize(data);

        restore_error_handler();

        return data;
    }
}
