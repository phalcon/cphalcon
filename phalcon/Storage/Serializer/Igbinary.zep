
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
     *
     * @return string
     */
    public function serialize()
    {
        if (true !== this->isSerializable(this->data)) {
            return this->data;
        }

        return igbinary_serialize(this->data);
    }

    /**
     * Unserializes data
     *
     * @param string $data
     *
     * @return void
     */
	public function unserialize(var data) -> void
	{
	    var version;

	    let version = phpversion();

	    globals_set("warning.enable", false);

	    if version_compare(version, "8.0", ">=") {
	        set_error_handler(
                function (number, message, file, line) {
                    globals_set("warning.enable", true);
                },
                E_WARNING
            );
	    } else {
	        set_error_handler(
                function (number, message, file, line, context) {
                    globals_set("warning.enable", true);
                },
                E_WARNING
            );
	    }

		let this->data = igbinary_unserialize(data);

        restore_error_handler();

        if unlikely globals_get("warning.enable") {
            let this->data = null;
        }
    }
}
