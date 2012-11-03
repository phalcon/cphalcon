<?php
/**
 * PhalconTestHelper.php
 * PhalconTestHelper
 *
 * Test Helper
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

$root = realpath(dirname(dirname(__FILE__)));
define('ROOT_PATH', $root);

if (!defined('UNIT_TESTING'))
{
    define('UNIT_TESTING', true);
}

error_reporting(E_ALL);
set_include_path(
    ROOT_PATH . PATH_SEPARATOR .
    ROOT_PATH . '/library' . PATH_SEPARATOR .
    get_include_path()
);

require_once ROOT_PATH . '/library/Phalcon/Test/UnitTestCase.php';

// Register the autoloader
spl_autoload_register('phalcon_test_autoloader');

function phalcon_test_autoloader($className)
{
    $filename = str_replace('_', DIRECTORY_SEPARATOR, $className).'.php';
    $paths    = array(
        '/library/',
        '/tests/Phalcon/',
        '/tests/app/models/',
        '/tests/app/controllers/',
    );

    /**
     * Check the Library first, then the Models, then the controllers
     */
    foreach ($paths as $path)
    {
        if (file_exists(ROOT_PATH . $path . $filename))
        {
            require_once ROOT_PATH . $path . $filename;
            break;
        }
    }
}

