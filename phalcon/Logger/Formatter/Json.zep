
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
 * Formats messages using JSON encoding
 */
class Json extends AbstractFormatter
{
    /**
     * Json constructor.
     *
     * @param string $dateFormat
     * @param string $interpolatorLeft
     * @param string $interpolatorRight
     */
    public function __construct(
        string dateFormat = "c",
        string interpolatorLeft = "%",
        string interpolatorRight = "%"
    ) {
        let this->dateFormat        = dateFormat;
        let this->interpolatorLeft  = interpolatorLeft;
        let this->interpolatorRight = interpolatorRight;
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

        let message = $this->getInterpolatedMessage($item, $item->getMessage());
        let options = JSON_HEX_TAG
            + JSON_HEX_APOS
            + JSON_HEX_AMP
            + JSON_HEX_QUOT
            + JSON_UNESCAPED_SLASHES
            + JSON_THROW_ON_ERROR;

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
