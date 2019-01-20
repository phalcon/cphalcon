
/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Filter;

use Phalcon\Filter\Exception;
use Phalcon\Filter\FilterLocator;
use Phalcon\Service\LocatorInterface;
use Phalcon\Service\LocatorFactoryInterface;

class FilterLocatorFactory implements LocatorFactoryInterface
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
		var helpers;

		/**
		 * Available helpers
		 */
		let helpers = [
			"absint"        : function () { return new \Phalcon\Filter\Sanitize\AbsInt(); },
			"alnum"         : function () { return new \Phalcon\Filter\Sanitize\Alnum(); },
			"alpha"         : function () { return new \Phalcon\Filter\Sanitize\Alpha(); },
			"alphanum"      : function () { return new \Phalcon\Filter\Sanitize\Alnum(); },
			"bool"          : function () { return new \Phalcon\Filter\Sanitize\BoolVal(); },
			"email"         : function () { return new \Phalcon\Filter\Sanitize\Email(); },
			"float"         : function () { return new \Phalcon\Filter\Sanitize\FloatVal(); },
			"float!"        : function () { return new \Phalcon\Filter\Sanitize\FloatValCast(); },
			"int"           : function () { return new \Phalcon\Filter\Sanitize\IntVal(); },
			"int!"          : function () { return new \Phalcon\Filter\Sanitize\IntValCast(); },
			"lower"         : function () { return new \Phalcon\Filter\Sanitize\Lower(); },
			"lowerFirst"    : function () { return new \Phalcon\Filter\Sanitize\LowerFirst(); },
			"regex"         : function () { return new \Phalcon\Filter\Sanitize\Regex(); },
			"remove"        : function () { return new \Phalcon\Filter\Sanitize\Remove(); },
			"replace"       : function () { return new \Phalcon\Filter\Sanitize\Replace(); },
			"special_chars" : function () { return new \Phalcon\Filter\Sanitize\Special(); },
			"string"        : function () { return new \Phalcon\Filter\Sanitize\StringVal(); },
			"striptags"     : function () { return new \Phalcon\Filter\Sanitize\Striptags(); },
			"trim"          : function () { return new \Phalcon\Filter\Sanitize\Trim(); },
			"upper"         : function () { return new \Phalcon\Filter\Sanitize\Upper(); },
			"upperFirst"    : function () { return new \Phalcon\Filter\Sanitize\UpperFirst(); },
			"upperWords"    : function () { return new \Phalcon\Filter\Sanitize\UpperWords(); },
			"url"           : function () { return new \Phalcon\Filter\Sanitize\Url(); }
		];

		return new FilterLocator(helpers);
	}
}


