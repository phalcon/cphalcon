
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

use Phalcon\Service\Locator;
use Phalcon\Service\LocatorInterface;
use Phalcon\Service\LocatorFactoryInterface;

/**
 * Phalcon\Html\TagLocator
 *
 * ServiceLocator implementation for Tag helpers
 */
class TagLocatorFactory implements LocatorFactoryInterface
{
    /**
     * Returns a Locator object with all the helpers defined in anonynous
     * functions
     */
    public function newInstance() -> <LocatorInterface>
    {
        var helpers, locator;

        /**
         * Available helpers
         */
        let helpers = [
            "a"          : function () { return new \Phalcon\Html\Helper\Anchor(); },
            "base"       : function () { return null; },
            "blockquote" : function () { return null; },
            "body"       : function () { return null; },
            "button"     : function () { return null; },
            "code"       : function () { return null; },
            "comment"    : function () { return null; },
            "data"       : function () { return null; },
            "datalist"   : function () { return null; },
            "doctype"    : function () { return null; },
            "element"    : function () { return new \Phalcon\Html\Helper\Element(); },
            "form"       : function () { return new \Phalcon\Html\Helper\Form(); },
            "formClose"  : function () { return new \Phalcon\Html\Helper\FormClose(); },
            "head"       : function () { return null; },
            "header"     : function () { return null; },
            "hr"         : function () { return null; },
            "img"        : function () { return null; },
            "input"      : function () { return null; },
            "label"      : function () { return null; },
            "link"       : function () { return null; },
            "script"     : function () { return null; },
            "span"       : function () { return null; },
            "style"      : function () { return null; },
            "textarea"   : function () { return new \Phalcon\Html\Helper\TextArea(); },
            "title"      : function () { return null; }
        ];

        let locator = new Locator(helpers);

        return locator;
    }
}
