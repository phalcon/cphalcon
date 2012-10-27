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

$root = realpath(dirname(__FILE__));
define('ROOT_PATH', $root);

if (!defined('UNIT_TESTING'))
{
    define('UNIT_TESTING', TRUE);
}

error_reporting(E_ALL);
set_include_path(
    ROOT_PATH . PATH_SEPARATOR .
    ROOT_PATH . '/Models' . PATH_SEPARATOR .
    get_include_path()
);

require_once ROOT_PATH . '/Helpers/PhalconConfig.php';
require_once ROOT_PATH . '/Helpers/PhalconUnitTestCase.php';
require_once ROOT_PATH . '/Helpers/PhalconModelTestCase.php';
require_once ROOT_PATH . '/Helpers/PhalconFunctionalTestCase.php';

