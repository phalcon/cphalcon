<?php

declare(strict_types=1);

use Codeception\Util\Autoload;

$root = dirname(realpath(__DIR__) . DIRECTORY_SEPARATOR) . DIRECTORY_SEPARATOR;
define('PROJECT_PATH', $root);

require_once $root . 'tests/_ci/functions.php';

loadIni();
loadAutoloader($root);




//
///**
// * Setting this in the $_ENV so that DotLoad sets everything up properly
// */
//$_ENV['PROJECT_PATH'] = $root;
//
//require_once $root . 'tests/shim.php';
//
//
//define('APP_DATA', dataDir());
//define('APP_PATH', codecept_root_dir());
//define('APP_PATH_OUTPUT', outputDir());
//
//
//loadEnvironment($root);
//loadFolders();
//

unset($root);
