<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

use Dotenv\Dotenv;

if (!function_exists('env')) {
    function env($key, $default = null)
    {
        if (defined($key)) {
            return constant($key);
        }

        return getenv($key) ?: $default;
    }
}

/**
 * Calls .env and merges the global and local configurations
 */
if (!function_exists('loadEnvironment')) {
    function loadEnvironment(string $root)
    {
        /**
         * Load the defaults first
         */
        (new Dotenv($root . 'tests/_ci/', '.env.default'))->load();

        /**
         * Now load your own environment
         */
        (new Dotenv($root))->overload();
    }
}

/**
 * Gets the necessary variables from the global .env configuration and
 * creates constants for this run from them to be used in the suite
 */
if (!function_exists('loadConstants')) {
    function loadConstants(string $root)
    {
        /**
         * Environments are loaded so let's read the variables we need and then "print"
         * them in an env file that travis and codeception can use
         */
        $autodetect = ini_get('auto_detect_line_endings');
        ini_set('auto_detect_line_endings', '1');
        $lines = file($root . 'tests/_ci/.env.default', FILE_IGNORE_NEW_LINES | FILE_SKIP_EMPTY_LINES);
        ini_set('auto_detect_line_endings', $autodetect);

        /**
         * $lines has all we need. We will create an array of names to use
         */
        foreach ($lines as $line) {
            if (strpos($line, '=') > 0) {
                $name = substr($line, 0, strpos($line, '='));
                (defined($name) || define($name, $_ENV[$name]));
            }
        }
    }
}

/**
 * Ensures that certain folders are always ready for us.
 */
if (!function_exists('loadFolders')) {
    function loadFolders()
    {
        $folders = [
            'annotations',
            'assets',
            'cache',
            'image',
            'image/gd',
            'image/imagick',
            'logs',
            'session',
            'stream',
        ];
        foreach ($folders as $folder) {
            $item = sprintf('%s/tests/%s', PATH_OUTPUT, $folder);
            if (true !== file_exists($item)) {
                mkdir($item, 0777, true);
            }
        }
    }
}
