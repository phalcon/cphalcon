
/**
 * This file is part of the Phalcon.
 *
 * (c) Phalcon Team <team@phalcon.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper\Input;

use Phalcon\Helper\Arr;
use Phalcon\Html\Exception;

/**
 * Class Textarea
 */
class Textarea extends AbstractInput
{
    /**
     * @var string
     */
    protected type = "textarea";

    /**
     * Returns the HTML for the input.
     *
     * @return string
     * @throws Exception
     */
    public function __toString()
    {
        var value;
        array attributes;

        let attributes       = this->attributes,
            value            = Arr::get(attributes, "value", ""),
            this->attributes = [];

        unset attributes["type"];
        unset attributes["value"];

        return this->renderFullElement(
            this->type,
            value,
            attributes
        );
    }
}
