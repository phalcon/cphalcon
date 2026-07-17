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

use Phalcon\Talon\Bootstrap\Runner;
use Phalcon\Talon\Bootstrap\Stage;
use Phalcon\Talon\Contracts\Settings as SettingsContract;
use Phalcon\Talon\Settings;

error_reporting(E_ALL);

$root       = dirname(__DIR__);
$autoloader = $root . '/vendor/autoload.php';

if (! file_exists($autoloader)) {
    echo "Composer autoloader not found: $autoloader" . PHP_EOL;
    echo "Please issue 'composer install' and try again." . PHP_EOL;
    exit(1);
}

require_once $autoloader;

if (file_exists($root . '/.env')) {
    $dotenv = Dotenv\Dotenv::createImmutable($root);
    $dotenv->load();
}

Runner::for(Settings::fromEnv())
    ->before(
        Stage::Environment,
        static function (SettingsContract $settings): void {
            $mysql = $settings->getDatabaseOptions('mysql');

            $constants = [
                'DATA_MYSQL_CHARSET' => (string) $mysql['charset'],
                'DATA_MYSQL_HOST'    => (string) $mysql['host'],
                'DATA_MYSQL_NAME'    => (string) $mysql['dbname'],
                'DATA_MYSQL_PASS'    => (string) $mysql['password'],
                'DATA_MYSQL_PORT'    => (string) $mysql['port'],
                'DATA_MYSQL_USER'    => (string) $mysql['username'],
            ];

            foreach ($constants as $name => $value) {
                if (!defined($name)) {
                    define($name, $value);
                }
            }

            if (!defined('PATH_DATA')) {
                define('PATH_DATA', $settings->dataPath() . '/');
            }

            if (!defined('PATH_SUPPORT')) {
                define('PATH_SUPPORT', $settings->supportPath() . '/');
            }

            if (!defined('PATH_OUTPUT')) {
                define('PATH_OUTPUT', $settings->outputPath() . '/');
            }
        }
    )
    ->after(
        Stage::Directories,
        static function (SettingsContract $settings): void {
            $folders = [
                'tests/annotations',
                'tests/assets',
                'tests/cache',
                'tests/cache/models',
                'tests/image/gd',
                'tests/image/imagick',
                'tests/logs',
                'tests/session',
                'tests/stream',
            ];

            foreach ($folders as $folder) {
                $path = $settings->outputPath($folder);
                if (!file_exists($path)) {
                    mkdir($path, 0777, true);
                }
            }
        }
    )
    ->boot();
