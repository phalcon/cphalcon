#!/usr/bin/env php
<?php

declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

use Phalcon\Tests\Support\Migrations\AbstractMigration;
use Phalcon\Tests\Support\Migrations\BootstrapMigration;
use Phalcon\Tests\Support\Migrations\FooterMigration;

error_reporting(E_ALL);
ini_set('display_errors', 'On');

$root = dirname(__DIR__);

require_once $root . '/vendor/autoload.php';

$drivers = [
    'mysql',
    'sqlite',
    'pgsql',
    //    'sqlsrv',
];

$migrations     = getMigrations($root);
$migrationClass = 'Phalcon\Tests\Support\Migrations\%s';

foreach ($drivers as $driver) {
    $schema = $root . '/tests/support/assets/schema/' . $driver . '.sql';
    cleanFile($schema);
    echo "Driver: " . $driver . " - ";

    // Always run the bootstrap migration first
    $bootstrap  = new BootstrapMigration();
    $statements = $bootstrap->getSql($driver);
    logStatements($statements, $schema);

    foreach ($migrations as $migration) {
        $className  = sprintf($migrationClass, $migration);
        /** @var AbstractMigration $class */
        $class      = new $className();
        $statements = $class->getSql($driver);

        logStatements($statements, $schema);
    }

    // Always run the footer migration last
    $footer     = new FooterMigration();
    $statements = $footer->getSql($driver);
    logStatements($statements, $schema);

    echo PHP_EOL;
}


function cleanFile(string $schema)
{
    if (file_exists($schema)) {
        $handle = fopen($schema, "r+");
        if ($schema !== false) {
            ftruncate($handle, 0);
            fclose($handle);
        }
    }
}

/**
 * @param string $root
 *
 * @return array
 */
function getMigrations(string $root): array
{
    $path       = $root . '/tests/support/Migrations/';
    $migrations = [];
    foreach (glob($path . '*.php') as $file) {
        $file = str_replace([$path, '.php'], '', $file);
        if ($file !== 'AbstractMigration' && $file !== 'BootstrapMigration' && $file !== 'FooterMigration') {
            $migrations[] = $file;
        }
    }

    asort($migrations);

    return $migrations;
}

function logStatements(array $statements, string $schema)
{
    foreach ($statements as $statement) {
        error_log(PHP_EOL . $statement . PHP_EOL, 3, $schema);
        echo ".";
    }
}
