
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Exception;

/**
 * Class Form
 */
class Form extends AbstractHelper
{
    /**
     * Produce a `<form>` tag.
     *
     * @param array $attributes
     *
     * @return string
     * @throws Exception
     */
    public function __invoke(array attributes = []) -> string
    {
        var overrides;

        let overrides = [
            "method"  : "post",
            "enctype" : "multipart/form-data"
        ];

        let overrides = this->orderAttributes(overrides, attributes);

        return this->renderElement("form", overrides);
    }
}
