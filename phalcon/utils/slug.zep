
/*
 +------------------------------------------------------------------------+
 | Phalcon Framework                                                      |
 +------------------------------------------------------------------------+
 | Copyright (c) 2011-2014 Phalcon Team (http://www.phalconphp.com)       |
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

namespace Phalcon\Utils;

use Phalcon\Utils\Exception;

class Slug extends \Phalcon\Utils\Adapter implements \Phalcon\Utils\AdapterInterface
{
    /**
     * Creates a slug to be used for pretty URLs
     * @link http://cubiq.org/the-perfect-php-clean-url-generator
     * @example unit-test/utisl/SlugTest.php
     * 
     * @return string
     */
    public static function generate(string! str, array replace = null, string! delimiter = "-") ->string
    {

        var oldLocale, clean;
        if !extension_loaded("iconv") {
            throw new Exception("iconv module not loaded");
        }
        if replace && typeof replace != "array" {
			throw new Exception("The replace must be an array");
		}
        // Save the old locale and set the new locale to UTF-8
        let oldLocale = setlocale(LC_ALL, "en_US.UTF-8");

        if typeof replace == "array" {
        	var key, value;
        	for key, value in replace {
        		let str = str_replace(replace[key]," ", str);
        	}
        }
        let clean = iconv("UTF-8", "ASCII//TRANSLIT", str),
        	clean = preg_replace("/[^a-zA-Z0-9\\/_|+ -]/", "", clean),
        	clean = strtolower(clean),
        	clean = preg_replace("/[\\/_|+ -]+/", delimiter, clean),
        	clean = trim(clean, delimiter);

        // Revert back to the old locale
        setlocale(LC_ALL, oldLocale);

        return clean;
    }
}