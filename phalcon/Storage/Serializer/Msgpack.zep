
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

class Msgpack extends AbstractSerializer
{
	/**
	 * Serializes data
	 */
	public function serialize() -> string|null
	{
        if !this->isSerializable(this->data) {
            return this->data;
        }

		return msgpack_pack(this->data);
	}

	/**
	 * Unserializes data
	 */
	public function unserialize(var data) -> void
	{
	    globals_set("warning.enable", false);
        set_error_handler(
            function (number, message, file, line) {
        	    globals_set("warning.enable", true);
            },
            E_WARNING
        );

        let this->data = msgpack_unpack(data);

        restore_error_handler();

        if unlikely globals_get("warning.enable") {
            let this->data = null;
        }
	}
}
