<?php
// This is global bootstrap for autoloading

define('UNIT_TESTING', true);

$root = realpath(dirname(__FILE__));

define('ROOT_PATH', $root);
define('PATH_DATA', $root . '/_data/');
define('PATH_CACHE', $root . '/_output/tests/cache/');
define('PATH_LOGS', $root . '/_output/tests/logs/');

/*

define('PATH_CONFIG', $root . '/_output/tests/var/config/');
define('PATH_MICRO', $root . '/tests/app_micro/');
define('PATH_SINGLE', $root . '/tests/app_single/');
define('PATH_MULTI', $root . '/tests/app_multi/');

define('PATH_MODELS', $root . '/tests/app/models/');
define('PATH_VIEWS', $root . '/tests/app/views/');
define('PATH_CONTROLLERS', $root . '/tests/app/controllers/');

define('PATH_COLLECTIONS', $root . '/tests/app/collections/');
define('PATH_VENDORS', $root . '/tests/app/vendor/');
define('PATH_TASKS', $root . '/tests/app/tasks/');
*/

// loading verify assert BDD style assert
require_once ROOT_PATH . '/_support/Verify.php';

error_reporting(E_ALL);
set_include_path(
    ROOT_PATH . PATH_SEPARATOR . get_include_path()
);

// \Codeception\Specify\Config::setDeepClone(false);

// Register the autoloader
spl_autoload_register('phalconTestAutoloader');

function phalconTestAutoloader($className)
{
    if (strpos($className, '\\') > 0) {
        $className = str_replace('\\', DIRECTORY_SEPARATOR, $className);
    }

    $filename = $className . '.php';
    $fullFile = ROOT_PATH  . '/' . str_replace('Phalcon/Tests/', '', $filename);

    if (file_exists($fullFile)) {
        require_once $fullFile;
    }
}

function expect($description, $actual = null)
{
    return new Codeception\Verify($description, $actual);
}

function expect_that($truth)
{
    expect($truth)->notEmpty();
}

function expect_not($fallacy)
{
    expect($fallacy)->isEmpty();
}

/**
 * Returns a unique file name
 *
 * @author Nikos Dimopoulos <nikos@phalconphp.com>
 * @since  2014-09-13
 *
 * @param string $prefix    A prefix for the file
 * @param string $suffix    A suffix for the file
 *
 * @return string
 *
 */
function newFileName($prefix = '', $suffix = 'log')
{
    $prefix = ($prefix) ? $prefix . '_' : '';
    $suffix = ($suffix) ? $suffix       : 'log';

    return uniqid($prefix, true) . '.' . $suffix;
}

/**
 * Removes a file from the system
 *
 * @author Nikos Dimopoulos <nikos@phalconphp.com>
 * @since  2014-09-13
 *
 * @param string $path
 * @param string $fileName
 */
function cleanFile($path, $fileName)
{
    $file  = (substr($path, -1, 1) != "/") ? ($path . '/') : $path;
    $file .= $fileName;

    $actual = file_exists($file);

    if ($actual) {
        unlink($file);
    }
}
