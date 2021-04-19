
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
        var context, message, time;

        let context = item->getContext(),
            time    = item->getTime();

        if !empty context {
            let message = this->interpolate(item->getMessage(), context);
        } else {
            let message = item->getMessage();
        }

        return JsonHelper::encode(
            [
                "level"     : item->getLevelName(),
                "message"   : message,
                "timestamp" : time->format(this->dateFormat)
            ]
        );
    }
}
