<?php

/**
 * PhalconTestHelper.php
 * PhalconTestHelper
 *
 * Test Helper
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2015 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
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
define('PATH_LIBRARY', $root . '/library/');
define('PATH_TESTS', $root . '/tests/Phalcon/');

define('PATH_CONFIG', $root . '/tests/var/config/');
define('PATH_CACHE', $root . '/tests/var/cache/');
define('PATH_LOGS', $root . '/tests/var/logs/');

define('PATH_MICRO', $root . '/tests/app_micro/');
define('PATH_SINGLE', $root . '/tests/app_single/');
define('PATH_MULTI', $root . '/tests/app_multi/');

define('PATH_MODELS', $root . '/tests/app/models/');
define('PATH_VIEWS', $root . '/tests/app/views/');
define('PATH_CONTROLLERS', $root . '/tests/app/controllers/');

define('PATH_COLLECTIONS', $root . '/tests/app/collections/');
define('PATH_VENDORS', $root . '/tests/app/vendor/');
define('PATH_TASKS', $root . '/tests/app/tasks/');

define('PATH_CONFIGS', $root . '/tests/app/configs/');

error_reporting(E_ALL);
set_include_path(
    ROOT_PATH . PATH_SEPARATOR . get_include_path()
);

require_once ROOT_PATH . '/library/Phalcon/Test/UnitTestCase.php';

// Register the autoloader
spl_autoload_register('phalconTestAutoloader');

function phalconTestAutoloader($className)
{
    if (strpos($className, '\\') > 0) {
        $className = str_replace('\\', DIRECTORY_SEPARATOR, $className);
    }

    $filename = $className . '.php';

    $paths    = array(
        PATH_LIBRARY,
        PATH_TESTS,
        PATH_TASKS,
        PATH_COLLECTIONS,
        PATH_MODELS,
        PATH_CONTROLLERS,
    );

    /**
     * Check the Library first, then the Models, then the controllers
     */
    foreach ($paths as $path) {
        if ($path == PATH_TESTS) {
            $fullFile = $path . str_replace('Phalcon/Test/', '', $filename);
        } else {
            $fullFile = $path . $filename;
        }

        if (file_exists($fullFile)) {
            require_once $fullFile;
            break;
        }
    }
}
