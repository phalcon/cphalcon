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
            'cache/models',
            'image',
            'image/gd',
            'image/imagick',
            'logs',
            'session',
            'stream',
        ];
        foreach ($folders as $folder) {
            $item = outputDir('tests/' . $folder);
            if (true !== file_exists($item)) {
                mkdir($item, 0777, true);
            }
        }

        if (true !== file_exists(cacheDir())) {
            mkdir(cacheDir(), 0777, true);
        }
    }
}

/**
 * Returns the cache folder
 */
if (!function_exists('cacheDir')) {
    /**
     * @param string $fileName
     *
     * @return string
     */
    function cacheDir(string $fileName = '')
    {
        return env('PATH_CACHE') . $fileName;
    }
}

/**
 * Returns the output folder
 */
if (!function_exists('dataDir')) {
    /**
     * @param string $fileName
     *
     * @return string
     */
    function dataDir(string $fileName = '')
    {
        return codecept_data_dir() . $fileName;
    }
}

/**
 * Returns the output folder
 */
if (true !== function_exists('outputDir')) {
    /**
     * @param string $fileName
     *
     * @return string
     */
    function outputDir(string $fileName = '')
    {
        return codecept_output_dir() . $fileName;
    }
}

/**
 * Returns the output folder
 */
if (true !== function_exists('cacheModelsDir')) {
    /**
     * @param string $fileName
     *
     * @return string
     */
    function cacheModelsDir(string $fileName = '')
    {
        return codecept_output_dir() . 'tests/cache/models/' . $fileName;
    }
}

/*******************************************************************************
 * Options
 *******************************************************************************/
if (true !== function_exists('getOptionsLibmemcached')) {
    /**
     * @return array
     */
    function getOptionsLibmemcached(): array
    {
        return [
            'client'  => [],
            'servers' => [
                [
                    'host'   => env('DATA_MEMCACHED_HOST', '127.0.0.1'),
                    'port'   => env('DATA_MEMCACHED_PORT', 11211),
                    'weight' => env('DATA_MEMCACHED_WEIGHT', 0),
                ],
            ],
        ];
    }
}

if (true !== function_exists('getOptionsRedis')) {
    /**
     * @return array
     */
    function getOptionsRedis(): array
    {
        return [
            'host'  => env('DATA_REDIS_HOST'),
            'port'  => env('DATA_REDIS_PORT'),
            'index' => env('DATA_REDIS_NAME'),
        ];
    }
}

if (true !== function_exists('getOptionsSessionStream')) {
    /**
     * @return array
     */
    /**
     * Get Session Stream options
     */
    function getOptionsSessionStream()
    {
        if (!is_dir(cacheDir('sessions'))) {
            mkdir(cacheDir('sessions'));
        }

        return [
            'savePath' => cacheDir('sessions'),
        ];
    }
}

if (true !== function_exists('getOptionsModelCacheStream')) {
    /**
     * Get Model cache options - Stream
     */
    function getOptionsModelCacheStream(): array
    {
        if (!is_dir(cacheDir('models'))) {
            mkdir(cacheDir('models'));
        }

        return [
            'lifetime' => 3600,
            'cacheDir' => cacheModelsDir(),
        ];
    }
}

if (true !== function_exists('getOptionsMysql')) {
    /**
     * Get mysql db options
     */
    function getOptionsMysql(): array
    {
        return [
            'host'     => env('DATA_MYSQL_HOST'),
            'username' => env('DATA_MYSQL_USER'),
            'password' => env('DATA_MYSQL_PASS'),
            'dbname'   => env('DATA_MYSQL_NAME'),
            'charset'  => env('DATA_MYSQL_CHARSET'),
        ];
    }
}

if (true !== function_exists('getOptionsPostgresql')) {
    /**
     * Get postgresql db options
     */
    function getOptionsPostgresql(): array
    {
        return [
            'host'     => env('DATA_POSTGRES_HOST'),
            'username' => env('DATA_POSTGRES_USER'),
            'password' => env('DATA_POSTGRES_PASS'),
            'dbname'   => env('DATA_POSTGRES_NAME'),
            'schema'   => env('DATA_POSTGRES_SCHEMA'),
        ];
    }
}

if (true !== function_exists('getOptionsSqlite')) {
    /**
     * Get sqlite db options
     */
    function getOptionsSqlite(): array
    {
        return [
            'dbname' => env('DATA_SQLITE_NAME'),
        ];
    }
}
