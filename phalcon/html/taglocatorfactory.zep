
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Html;

use Phalcon\Di;
use Phalcon\DiInterface;
use Phalcon\Escaper;
use Phalcon\EscaperInterface;
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
	 * @var EscaperInterface
	 */
	private escaper;

	/**
	 * Returns a Locator object with all the helpers defined in anonynous
	 * functions
	 */
	public function newInstance() -> <LocatorInterface>
	{
		var escaper, helpers;

		/**
		 * The escaper service
		 */
		let escaper = this->getEscaper();

		/**
		 * Available helpers
		 */
		let helpers = [
			"a"          : function (escaper) { return new \Phalcon\Html\Helper\Anchor(escaper); },
			"abbr"       : function (escaper) { return null; },
			"address"    : function (escaper) { return null; },
			"area"       : function (escaper) { return null; },
			"article"    : function (escaper) { return null; },
			"aside"      : function (escaper) { return null; },
			"audio"      : function (escaper) { return null; },
			"b"          : function (escaper) { return null; },
			"base"       : function (escaper) { return null; },
			"bdi"        : function (escaper) { return null; },
			"bdo"        : function (escaper) { return null; },
			"blockquote" : function (escaper) { return null; },
			"body"       : function (escaper) { return null; },
			"br"         : function (escaper) { return null; },
			"button"     : function (escaper) { return null; },
			"canvas"     : function (escaper) { return null; },
			"caption"    : function (escaper) { return null; },
			"cite"       : function (escaper) { return null; },
			"code"       : function (escaper) { return null; },
			"col"        : function (escaper) { return null; },
			"colgroup"   : function (escaper) { return null; },
			"comment"    : function (escaper) { return null; },
			"data"       : function (escaper) { return null; },
			"datalist"   : function (escaper) { return null; },
			"dd"         : function (escaper) { return null; },
			"del"        : function (escaper) { return null; },
			"details"    : function (escaper) { return null; },
			"dfn"        : function (escaper) { return null; },
			"dialog"     : function (escaper) { return null; },
			"div"        : function (escaper) { return null; },
			"dl"         : function (escaper) { return null; },
			"doctype"    : function (escaper) { return null; },
			"dt"         : function (escaper) { return null; },
			"em"         : function (escaper) { return null; },
			"embed"      : function (escaper) { return null; },
			"fieldset"   : function (escaper) { return null; },
			"figcaption" : function (escaper) { return null; },
			"figure"     : function (escaper) { return null; },
			"footer"     : function (escaper) { return null; },
			"form"       : function (escaper) { return null; },
			"h1"         : function (escaper) { return null; },
			"h2"         : function (escaper) { return null; },
			"h3"         : function (escaper) { return null; },
			"h4"         : function (escaper) { return null; },
			"h5"         : function (escaper) { return null; },
			"h6"         : function (escaper) { return null; },
			"head"       : function (escaper) { return null; },
			"header"     : function (escaper) { return null; },
			"hgroup"     : function (escaper) { return null; },
			"hr"         : function (escaper) { return null; },
			"html"       : function (escaper) { return null; },
			"i"          : function (escaper) { return null; },
			"iframe"     : function (escaper) { return null; },
			"img"        : function (escaper) { return null; },
			"input"      : function (escaper) { return null; },
			"ins"        : function (escaper) { return null; },
			"kbd"        : function (escaper) { return null; },
			"keygen"     : function (escaper) { return null; },
			"label"      : function (escaper) { return null; },
			"legend"     : function (escaper) { return null; },
			"li"         : function (escaper) { return null; },
			"link"       : function (escaper) { return null; },
			"main"       : function (escaper) { return null; },
			"map"        : function (escaper) { return null; },
			"mark"       : function (escaper) { return null; },
			"menu"       : function (escaper) { return null; },
			"menuitem"   : function (escaper) { return null; },
			"meta"       : function (escaper) { return null; },
			"meter"      : function (escaper) { return null; },
			"nav"        : function (escaper) { return null; },
			"noscript"   : function (escaper) { return null; },
			"object"     : function (escaper) { return null; },
			"ol"         : function (escaper) { return null; },
			"optgroup"   : function (escaper) { return null; },
			"option"     : function (escaper) { return null; },
			"output"     : function (escaper) { return null; },
			"p"          : function (escaper) { return null; },
			"param"      : function (escaper) { return null; },
			"pre"        : function (escaper) { return null; },
			"progress"   : function (escaper) { return null; },
			"q"          : function (escaper) { return null; },
			"rb"         : function (escaper) { return null; },
			"rp"         : function (escaper) { return null; },
			"rt"         : function (escaper) { return null; },
			"rtc"        : function (escaper) { return null; },
			"ruby"       : function (escaper) { return null; },
			"s"          : function (escaper) { return null; },
			"samp"       : function (escaper) { return null; },
			"script"     : function (escaper) { return null; },
			"section"    : function (escaper) { return null; },
			"select"     : function (escaper) { return null; },
			"small"      : function (escaper) { return null; },
			"source"     : function (escaper) { return null; },
			"span"       : function (escaper) { return null; },
			"strong"     : function (escaper) { return null; },
			"style"      : function (escaper) { return null; },
			"sub"        : function (escaper) { return null; },
			"summary"    : function (escaper) { return null; },
			"sup"        : function (escaper) { return null; },
			"table"      : function (escaper) { return null; },
			"tbody"      : function (escaper) { return null; },
			"td"         : function (escaper) { return null; },
			"template"   : function (escaper) { return null; },
			"textarea"   : function (escaper) { return null; },
			"tfoot"      : function (escaper) { return null; },
			"th"         : function (escaper) { return null; },
			"thead"      : function (escaper) { return null; },
			"time"       : function (escaper) { return null; },
			"title"      : function (escaper) { return null; },
			"tr"         : function (escaper) { return null; },
			"track"      : function (escaper) { return null; },
			"u"          : function (escaper) { return null; },
			"ul"         : function (escaper) { return null; },
			"var"        : function (escaper) { return null; },
			"video"      : function (escaper) { return null; },
			"wbr"        : function (escaper) { return null; }
		];

		return new Locator(helpers);
	}

	/**
	 * Get the escaper service
	 *
	 * I really don't like this here but it has to be here this way because there
	 * is a lot mroe groundwork to be done to refactor the whole DI implementation
	 */
	private function getEscaper() -> <EscaperInterface>
	{
		var container, escaper;

		let container = Di::getDefault();

		if (true !== container->has("escaper")) {
			let escaper = container->getService("escaper");
		} else {
			let escaper = new Escaper();
		}

		return escaper;
	}
}
