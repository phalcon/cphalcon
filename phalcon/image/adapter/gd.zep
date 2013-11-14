
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2013 Phalcon Team (http://www.phalconphp.com)       |
 +------------------------------------------------------------------------+
 | This source file is subject to the New BSD License that is bundled     |
 | with this package in the file docs/LICENSE.txt.                        |
 |                                                                        |
 | If you did not receive a copy of the license and are unable to         |
 | obtain it through the world-wide-web, please send an email             |
 | to license@phalconphp.com so we can send you a copy immediately.       |
 +------------------------------------------------------------------------+
 | Authors: Andres Gutierrez <andres@phalconphp.com>                      |
 |          Eduar Carvajal <eduar@phalconphp.com>                         |
 +------------------------------------------------------------------------+
 */

namespace Phalcon\Image\Adapter;

class GD extends Phalcon\Logger\Adapter implements Phalcon\Image\AdapterInterface
{
	public static function check()
	{
		var version, info, matches;

		if (self::_checked) {
			return true;
		}

		if !function_exists('gd_info') {
			throw new \Phalcon\Image\Exception('GD is either not installed or not enabled, check your configuration');
			return;
		}

		if defined('GD_VERSION') {
			let version = GD_VERSION;
		} else {
			let info = gd_info();

			preg_match('/\d+\.\d+(?:\.\d+)?/', info['GD Version'], matches);

			let version = matches[0];
		}

		if !version_compare(version, '2.0.1', '>=') {
			throw new \Phalcon\Image\Exception("Phalcon\\Image\\Adapter\\GD requires GD version '2.0.1' or greater, you have " . version);
		}

		self::_checked = true;
	}
}