
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Logger\Formatter;

use Phalcon\Helper\Json as JsonHelper;
use Phalcon\Logger\Item;
use Phalcon\Support\Helper\Str\Interpolate;

/**
 * Phalcon\Logger\Formatter\Json
 *
 * Formats messages using JSON encoding
 */
class Json extends AbstractFormatter
{
    /**
     * Phalcon\Logger\Formatter\Json construct
     */
    public function __construct(string dateFormat = "c")
    {
        let this->dateFormat = dateFormat;
    }

    /**
     * Applies a format to a message before sent it to the internal log
     */
    public function format(<Item> item) -> string
    {
        var interpolate, message, time;

        let time        = item->getTime(),
            interpolate = new Interpolate(),
            message     = interpolate(item->getMessage(), item->getContext());

        return JsonHelper::encode(
            [
                "level"     : item->getLevelName(),
                "message"   : message,
                "timestamp" : time->format(this->dateFormat)
            ]
        );
    }
}
