
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

/**
 * Phalcon\Html\TagLocator
 *
 * ServiceLocator implementation for Tag helpers
 */
class TagFactory
{
    /**
     * @var <EscaperInterface>
     */
    private escaper;

    /**
     * @var array
     */
    private mapper = [];

    /**
     * @var array
     */
    private services = [];

    /**
     * TagFactory constructor.
     */
    public function __construct(<EscaperInterface> escaper, array! services = [])
    {
        var helpers, name, service;
        
        let this->escaper = escaper;

        /**
         * Available helpers
         */
        let helpers = [
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

        let helpers = array_merge(helpers, services);

        for name, service in helpers {
            let this->mapper[name] = service;
            unset(this->services[name]);
        }
    }

    /**
     * @param string name
     *
     * @return mixed
     * @throws Exception
     */
    public function newInstance(string name) -> var
    {
        var definition;

        if !isset this->mapper[name] {
            throw new Exception("Service " . name . " is not registered");
        }

        if !isset this->services[name] {
            let definition           = this->mapper[name],
                this->services[name] = new {definition}(this->escaper);
        }

        return this->services[name];
    }
}
