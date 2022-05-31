
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

class Php extends AbstractSerializer
{
    /**
     * Serializes data
     *
     * @return string
     */
	public function serialize() -> string
	{
        if (true !== this->isSerializable(this->data)) {
            return this->data;
        }

		return serialize(this->data);
	}

    /**
     * Unserializes data
     *
     * @param mixed $data
     */
    public function unserialize(mixed data) -> void
    {
        var result, version;

        if (true !== this->isSerializable(data)) {
            let this->data = data;

            return;
        }

        let version = phpversion();

        globals_set("warning.enable", false);

        if version_compare(version, "8.0", ">=") {
            set_error_handler(
                function (number, message, file, line) {
                    globals_set("warning.enable", true);
                },
                E_NOTICE
            );
        } else {
            set_error_handler(
                function (number, message, file, line, context) {
                    globals_set("warning.enable", true);
                },
                E_NOTICE
            );
        }

        let result = this->phpUnserialize(data);

        restore_error_handler();

        if unlikely globals_get("warning.enable") || result === false {
            let this->isSuccess = false,
                result          = "";
        }

        let this->data = result;
    }

    /**
     * @param string $data
     * @param array  $options
     *
     * @return mixed
     */
    private function phpUnserialize(string data, array options = []) -> mixed
    {
        return unserialize(data, options);
    }
}
