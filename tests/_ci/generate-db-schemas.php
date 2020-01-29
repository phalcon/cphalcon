<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

use Phalcon\Test\Fixtures\Migrations\AbstractMigration;

$root = dirname(dirname(__DIR__));

require_once $root . '/vendor/autoload.php';

$drivers = [
    'mysql',
    'sqlite',
    //    'pgsql',
    //    'sqlsrv',
];

$migrations     = getMigrations($root);
$migrationClass = 'Phalcon\Test\Fixtures\Migrations\%s';

foreach ($drivers as $driver) {
    $schema = $root . '/tests/_data/assets/schemas/' . $driver . '.sql';
    cleanFile($schema);
    echo "Driver: " . $driver . " - ";
    foreach ($migrations as $migration) {
        $className  = sprintf($migrationClass, $migration);
        /** @var AbstractMigration $class */
        $class      = new $className();
        $statements = $class->getSql($driver);

        logStatements($statements, $schema);
    }

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
    $path       = $root . '/tests/_data/fixtures/Migrations/';
    $migrations = [];
    foreach (glob($path . '*.php') as $file) {
        $file = str_replace([$path, '.php'], '', $file);
        if ($file !== 'AbstractMigration') {
            $migrations[] = $file;
        }
    }

    asort($migrations);

    return $migrations;
}

function logStatements(array $statements, string $schema)
{

    error_log(PHP_EOL, 3, $schema);

    foreach ($statements as $statement) {
        error_log($statement, 3, $schema);
        echo ".";
    }

    error_log(PHP_EOL, 3, $schema);
}
