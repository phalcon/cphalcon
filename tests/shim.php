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
         * Load local environment if it exists
         */
        (new Dotenv($root, 'tests/_ci/.env.default'))->load();

        /**
         * Necessary evil. We need to set some constants for INI files to work
         */
        (defined('DATA_MYSQL_CHARSET') || define('DATA_MYSQL_CHARSET', env('DATA_MYSQL_CHARSET')));
        (defined('DATA_MYSQL_HOST') || define('DATA_MYSQL_HOST', env('DATA_MYSQL_HOST')));
        (defined('DATA_MYSQL_NAME') || define('DATA_MYSQL_NAME', env('DATA_MYSQL_NAME')));
        (defined('DATA_MYSQL_PASS') || define('DATA_MYSQL_PASS', env('DATA_MYSQL_PASS')));
        (defined('DATA_MYSQL_PORT') || define('DATA_MYSQL_PORT', env('DATA_MYSQL_PORT')));
        (defined('DATA_MYSQL_USER') || define('DATA_MYSQL_USER', env('DATA_MYSQL_USER')));
        (defined('PATH_CACHE') || define('PATH_CACHE', env('PATH_CACHE')));
        (defined('PATH_DATA') || define('PATH_DATA', env('PATH_DATA')));
        (defined('PATH_OUTPUT') || define('PATH_OUTPUT', env('PATH_OUTPUT')));
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
            $item = outputFolder('tests/' . $folder);
            if (true !== file_exists($item)) {
                mkdir($item, 0777, true);
            }
        }

        if (true !== file_exists(cacheFolder())) {
            mkdir(cacheFolder(), 0777, true);
        }
    }
}

/**
 * Returns the cache folder
 */
if (!function_exists('cacheFolder')) {
    /**
     * @param string $fileName
     *
     * @return string
     */
    function cacheFolder(string $fileName = '')
    {
        return env('PATH_CACHE') . $fileName;
    }
}

/**
 * Returns the output folder
 */
if (!function_exists('dataFolder')) {
    /**
     * @param string $fileName
     *
     * @return string
     */
    function dataFolder(string $fileName = '')
    {
        return env('PATH_DATA') . $fileName;
    }
}

/**
 * Returns the output folder
 */
if (!function_exists('outputFolder')) {
    /**
     * @param string $fileName
     *
     * @return string
     */
    function outputFolder(string $fileName = '')
    {
        return env('PATH_OUTPUT') . $fileName;
    }
}
