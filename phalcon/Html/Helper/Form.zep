
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html\Helper;

use Phalcon\Html\Helper\AbstractHelper;

/**
 * Phalcon\Html\Helper\Form
 *
 * Creates a form opening tag
 */
class Form extends AbstractHelper
{
    /**
     * @var array  attributes Any additional attributes
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
