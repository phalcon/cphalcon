
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
			"base"       : function (escaper) { return null; },
			"blockquote" : function (escaper) { return null; },
			"body"       : function (escaper) { return null; },
			"button"     : function (escaper) { return null; },
			"code"       : function (escaper) { return null; },
			"comment"    : function (escaper) { return null; },
			"data"       : function (escaper) { return null; },
			"datalist"   : function (escaper) { return null; },
			"doctype"    : function (escaper) { return null; },
			"element"    : function (escaper) { return new \Phalcon\Html\Helper\Element(escaper); },
			"form"       : function (escaper) { return new \Phalcon\Html\Helper\Form(escaper); },
			"formClose"  : function (escaper) { return new \Phalcon\Html\Helper\FormClose(escaper); },
			"head"       : function (escaper) { return null; },
			"header"     : function (escaper) { return null; },
			"hr"         : function (escaper) { return null; },
			"img"        : function (escaper) { return null; },
			"input"      : function (escaper) { return null; },
			"label"      : function (escaper) { return null; },
			"link"       : function (escaper) { return null; },
			"script"     : function (escaper) { return null; },
			"span"       : function (escaper) { return null; },
			"style"      : function (escaper) { return null; },
			"textarea"   : function (escaper) { return new \Phalcon\Html\Helper\TextArea(escaper); },
			"title"      : function (escaper) { return null; }
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
