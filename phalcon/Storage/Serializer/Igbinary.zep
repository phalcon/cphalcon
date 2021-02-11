
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Storage\Serializer;

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
	    globals_set("warning.enable", false);
        set_error_handler(
            function (number, message, file, line) {
        	    globals_set("warning.enable", true);
            },
            E_WARNING
        );

		let this->data = igbinary_unserialize(data);

        restore_error_handler();

        if unlikely globals_get("warning.enable") {
            let this->data = null;
        }
    }
}
