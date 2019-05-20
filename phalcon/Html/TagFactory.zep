
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

use Phalcon\Escaper;
use Phalcon\EscaperInterface;
use Phalcon\Factory\AbstractFactory;

/**
 * ServiceLocator implementation for Tag helpers
 */
class TagFactory extends AbstractFactory
{
    /**
     * @var <EscaperInterface>
     */
    private escaper;

    /**
     * TagFactory constructor.
     */
    public function __construct(<EscaperInterface> escaper, array! services = [])
    {
        let this->escaper = escaper;

        this->init(services);
    }

    /**
     * @param string name
     *
     * @return mixed
     * @throws Exception
     */
    public function newInstance(string name) -> var
    {
        this->checkService(name);

        return this->services[name];
    }

    protected function getAdapters() -> array
    {
        return [
            "a"          : "\\Phalcon\\Html\\Helper\\Anchor",
            "aRaw"       : "\\Phalcon\\Html\\Helper\\AnchorRaw",
            "body"       : "\\Phalcon\\Html\\Helper\\Body",
            "button"     : "\\Phalcon\\Html\\Helper\\Button",
            "close"      : "\\Phalcon\\Html\\Helper\\Close",
            "element"    : "\\Phalcon\\Html\\Helper\\Element",
            "elementRaw" : "\\Phalcon\\Html\\Helper\\ElementRaw",
            "form"       : "\\Phalcon\\Html\\Helper\\Form",
            "img"        : "\\Phalcon\\Html\\Helper\\Img",
            "label"      : "\\Phalcon\\Html\\Helper\\Label",
            "textarea"   : "\\Phalcon\\Html\\Helper\\TextArea"
        ];
    }
}
