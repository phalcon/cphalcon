
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2017 Phalcon Team (https://phalconphp.com)          |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file LICENSE.txt.                             |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 |          Wojciech Ślawski <jurigag@gmail.com>                          |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Translate;

use Phalcon\Factory as BaseFactory;

/**
 * Loads Translate Adapter class using 'adapter' option
 *
 *<code>
 * use Phalcon\Translate\Factory;
 *
 * $options = [
 *     "locale"        => "de_DE.UTF-8",
 *     "defaultDomain" => "translations",
 *     "directory"     => "/path/to/application/locales",
 *     "category"      => LC_MESSAGES,
 *     "adapter"       => "gettext",
 * ];
 * $translate = Factory::load($options);
 *</code>
 */
class Factory extends BaseFactory
{
	/**
	 * @param \Phalcon\Config|array config
	 */
	public static function load(var config) -> <AdapterInterface>
	{
		return self::loadClass("Phalcon\\Translate\\Adapter", config);
	}
}
