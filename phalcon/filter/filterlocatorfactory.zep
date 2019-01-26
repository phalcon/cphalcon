
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
use Phalcon\Filter\Sanitize\AbsInt;
use Phalcon\Filter\Sanitize\Alnum;
use Phalcon\Filter\Sanitize\Alpha;
use Phalcon\Filter\Sanitize\BoolVal;
use Phalcon\Filter\Sanitize\Email;
use Phalcon\Filter\Sanitize\FloatVal;
use Phalcon\Filter\Sanitize\IntVal;
use Phalcon\Filter\Sanitize\Lower;
use Phalcon\Filter\Sanitize\LowerFirst;
use Phalcon\Filter\Sanitize\Regex;
use Phalcon\Filter\Sanitize\Remove;
use Phalcon\Filter\Sanitize\Replace;
use Phalcon\Filter\Sanitize\Special;
use Phalcon\Filter\Sanitize\SpecialFull;
use Phalcon\Filter\Sanitize\StringVal;
use Phalcon\Filter\Sanitize\Striptags;
use Phalcon\Filter\Sanitize\Trim;
use Phalcon\Filter\Sanitize\Upper;
use Phalcon\Filter\Sanitize\UpperFirst;
use Phalcon\Filter\Sanitize\UpperWords;
use Phalcon\Filter\Sanitize\Url;
use Phalcon\Service\LocatorInterface;
use Phalcon\Service\LocatorFactoryInterface;

class FilterLocatorFactory implements LocatorFactoryInterface
{
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
			FilterLocator::FILTER_ABSINT      : "Phalcon\\Filter\\Sanitize\\AbsInt",
			FilterLocator::FILTER_ALNUM       : "Phalcon\\Filter\\Sanitize\\Alnum",
			FilterLocator::FILTER_ALPHA       : "Phalcon\\Filter\\Sanitize\\Alpha",
			FilterLocator::FILTER_BOOL        : "Phalcon\\Filter\\Sanitize\\BoolVal",
			FilterLocator::FILTER_EMAIL       : "Phalcon\\Filter\\Sanitize\\Email",
			FilterLocator::FILTER_FLOAT       : "Phalcon\\Filter\\Sanitize\\FloatVal",
			FilterLocator::FILTER_INT         : "Phalcon\\Filter\\Sanitize\\IntVal",
			FilterLocator::FILTER_LOWER       : "Phalcon\\Filter\\Sanitize\\Lower",
			FilterLocator::FILTER_LOWERFIRST  : "Phalcon\\Filter\\Sanitize\\LowerFirst",
			FilterLocator::FILTER_REGEX       : "Phalcon\\Filter\\Sanitize\\Regex",
			FilterLocator::FILTER_REMOVE      : "Phalcon\\Filter\\Sanitize\\Remove",
			FilterLocator::FILTER_REPLACE     : "Phalcon\\Filter\\Sanitize\\Replace",
			FilterLocator::FILTER_SPECIAL     : "Phalcon\\Filter\\Sanitize\\Special",
			FilterLocator::FILTER_SPECIALFULL : "Phalcon\\Filter\\Sanitize\\SpecialFull",
			FilterLocator::FILTER_STRING      : "Phalcon\\Filter\\Sanitize\\StringVal",
			FilterLocator::FILTER_STRIPTAGS   : "Phalcon\\Filter\\Sanitize\\Striptags",
			FilterLocator::FILTER_TRIM        : "Phalcon\\Filter\\Sanitize\\Trim",
			FilterLocator::FILTER_UPPER       : "Phalcon\\Filter\\Sanitize\\Upper",
			FilterLocator::FILTER_UPPERFIRST  : "Phalcon\\Filter\\Sanitize\\UpperFirst",
			FilterLocator::FILTER_UPPERWORDS  : "Phalcon\\Filter\\Sanitize\\UpperWords",
			FilterLocator::FILTER_URL         : "Phalcon\\Filter\\Sanitize\\Url"
		];

		return new FilterLocator(helpers);
	}
}


