
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

use Phalcon\Support\Collection;
use Phalcon\Html\Attributes\RenderInterface;
use Phalcon\Tag;

/**
 * This class helps to work with HTML Attributes
 */
class Attributes extends Collection implements RenderInterface
{
    /**
     * Render attributes as HTML attributes
     */
    public function render() -> string
    {
        return Tag::renderAttributes("", this->toArray());
    }

    /**
     * Alias of the render method
     */
    public function __toString() -> string
    {
        return this->render();
    }
}
