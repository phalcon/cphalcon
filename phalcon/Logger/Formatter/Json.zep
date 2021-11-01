
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use JsonException;
use Phalcon\Logger\Item;

/**
 * Phalcon\Logger\Formatter\Json
 *
 * Formats messages using JSON encoding
 */
class Json extends AbstractFormatter
{
    /**
     * Json constructor.
     *
     * @param string $dateFormat
     */
    public function __construct(string dateFormat = "c")
    {
        let this->dateFormat = dateFormat;
    }

    /**
     * Applies a format to a message before sent it to the internal log
     *
     * @param Item $item
     *
     * @return string
     * @throws JsonException
     */
    public function format(<Item> item) -> string
    {
        var message, options;

        let options = JSON_HEX_TAG
            + JSON_HEX_APOS
            + JSON_HEX_AMP
            + JSON_HEX_QUOT
            + JSON_UNESCAPED_SLASHES
            + JSON_THROW_ON_ERROR;

        let message = this->toInterpolate(
            item->getMessage(),
            item->getContext()
        );

        return json_encode(
            [
                "level"     : item->getLevelName(),
                "message"   : message,
                "timestamp" : this->getFormattedDate(item)
            ],
            options
        );
    }
}
