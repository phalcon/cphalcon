
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

use Phalcon\Escaper;
use Phalcon\Escaper\EscaperInterface;
use Phalcon\Factory\AbstractFactory;

/**
 * ServiceLocator implementation for Tag helpers
 */
class TagFactory extends AbstractFactory
{
    protected exception = "Phalcon\\Html\\Exception";

    /**
     * @var EscaperInterface
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
        var definition;

        if !isset this->services[name] {
            let definition           = this->getService(name),
                this->services[name] = create_instance_params(
                    definition,
                    [
                        this->escaper
                    ]
                );
        }

        return this->services[name];
    }

    protected function getServices() -> array
    {
        return [
            "a"                  : "Phalcon\\Html\\Helper\\Anchor",
            "base"               : "Phalcon\\Html\\Helper\\Base",
            "body"               : "Phalcon\\Html\\Helper\\Body",
            "button"             : "Phalcon\\Html\\Helper\\Button",
            "close"              : "Phalcon\\Html\\Helper\\Close",
            "element"            : "Phalcon\\Html\\Helper\\Element",
            "form"               : "Phalcon\\Html\\Helper\\Form",
            "img"                : "Phalcon\\Html\\Helper\\Img",
            "inputColor"         : "Phalcon\\Html\\Helper\\Input\\Color",
            "inputDate"          : "Phalcon\\Html\\Helper\\Input\\Date",
            "inputDateTime"      : "Phalcon\\Html\\Helper\\Input\\DateTime",
            "inputDateTimeLocal" : "Phalcon\\Html\\Helper\\Input\\DateTimeLocal",
            "inputEmail"         : "Phalcon\\Html\\Helper\\Input\\Email",
            "inputFile"          : "Phalcon\\Html\\Helper\\Input\\File",
            "inputHidden"        : "Phalcon\\Html\\Helper\\Input\\Hidden",
            "inputImage"         : "Phalcon\\Html\\Helper\\Input\\Image",
            "inputInput"         : "Phalcon\\Html\\Helper\\Input\\Input",
            "inputMonth"         : "Phalcon\\Html\\Helper\\Input\\Month",
            "inputNumeric"       : "Phalcon\\Html\\Helper\\Input\\Numeric",
            "inputPassword"      : "Phalcon\\Html\\Helper\\Input\\Password",
            "inputRange"         : "Phalcon\\Html\\Helper\\Input\\Range",
            "inputSelect"        : "Phalcon\\Html\\Helper\\Input\\Select",
            "inputSearch"        : "Phalcon\\Html\\Helper\\Input\\Search",
            "inputSubmit"        : "Phalcon\\Html\\Helper\\Input\\Submit",
            "inputTel"           : "Phalcon\\Html\\Helper\\Input\\Tel",
            "inputText"          : "Phalcon\\Html\\Helper\\Input\\Text",
            "inputTextarea"      : "Phalcon\\Html\\Helper\\Input\\Textarea",
            "inputTime"          : "Phalcon\\Html\\Helper\\Input\\Time",
            "inputUrl"           : "Phalcon\\Html\\Helper\\Input\\Url",
            "inputWeek"          : "Phalcon\\Html\\Helper\\Input\\Week",
            "label"              : "Phalcon\\Html\\Helper\\Label",
            "link"               : "Phalcon\\Html\\Helper\\Link",
            "meta"               : "Phalcon\\Html\\Helper\\Meta",
            "ol"                 : "Phalcon\\Html\\Helper\\Ol",
            "script"             : "Phalcon\\Html\\Helper\\Script",
            "style"              : "Phalcon\\Html\\Helper\\Style",
            "title"              : "Phalcon\\Html\\Helper\\Title",
            "ul"                 : "Phalcon\\Html\\Helper\\Ul"
        ];
    }
}
