<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

if (!function_exists('env')) {
    function env(string $key, $default = null)
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
         * Necessary evil. We need to set some constants for INI files to work
         */
        defineFromEnv('DATA_MYSQL_CHARSET');
        defineFromEnv('DATA_MYSQL_HOST');
        defineFromEnv('DATA_MYSQL_NAME');
        defineFromEnv('DATA_MYSQL_PASS');
        defineFromEnv('DATA_MYSQL_PORT');
        defineFromEnv('DATA_MYSQL_USER');
        defineFromEnv('PATH_CACHE');
        defineFromEnv('PATH_DATA');
        defineFromEnv('PATH_OUTPUT');
    }
}

if (!function_exists('defineFromEnv')) {
    function defineFromEnv(string $name)
    {
        if (defined($name)) {
            return;
        }

        define(
            $name,
            env($name)
        );
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
            $item = outputDir('tests' . PHP_EOL  . $folder);

            if (true !== file_exists($item)) {
                mkdir($item, 0777, true);
            }
        }
    }
}

/**
 * Returns the cache folder
 */
if (!function_exists('cacheDir')) {
    function cacheDir(string $fileName = ''): string
    {
        return codecept_output_dir() . 'tests' . PHP_EOL . 'cache' . PHP_EOL . $fileName;
    }
}

/**
 * Returns the output folder
 */
if (!function_exists('dataDir')) {
    function dataDir(string $fileName = ''): string
    {
        return codecept_data_dir() . $fileName;
    }
}

/**
 * Returns the output folder
 */
if (!function_exists('logsDir')) {
    function logsDir(string $fileName = ''): string
    {
        return codecept_output_dir() . 'tests' . PHP_EOL . 'logs' . PHP_EOL . $fileName;
    }
}

/**
 * Returns the output folder
 */
if (!function_exists('outputDir')) {
    function outputDir(string $fileName = ''): string
    {
        return codecept_output_dir() . $fileName;
    }
}

/**
 * Returns the output folder
 */
if (!function_exists('cacheModelsDir')) {
    function cacheModelsDir(string $fileName = ''): string
    {
        return codecept_output_dir() . 'tests' . PHP_EOL . 'cache' . PHP_EOL . 'models' . PHP_EOL . $fileName;
    }
}

/*******************************************************************************
 * Options
 *******************************************************************************/
if (!function_exists('getOptionsLibmemcached')) {
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

if (!function_exists('getOptionsRedis')) {
    function getOptionsRedis(): array
    {
        return [
            'host'  => env('DATA_REDIS_HOST'),
            'port'  => env('DATA_REDIS_PORT'),
            'index' => env('DATA_REDIS_NAME'),
        ];
    }
}

if (!function_exists('getOptionsSessionStream')) {
    /**
     * Get Session Stream options
     */
    function getOptionsSessionStream(): array
    {
        if (!is_dir(cacheDir('sessions'))) {
            mkdir(cacheDir('sessions'));
        }

        return [
            'savePath' => cacheDir('sessions'),
        ];
    }
}

if (!function_exists('getOptionsModelCacheStream')) {
    /**
     * Get Model cache options - Stream
     */
    function getOptionsModelCacheStream(): array
    {
        if (!is_dir(cacheDir('models'))) {
            mkdir(
                cacheDir('models')
            );
        }

        return [
            'lifetime' => 3600,
            'storageDir' => cacheModelsDir(),
        ];
    }
}

if (!function_exists('getOptionsMysql')) {
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
            'port'     => env('DATA_MYSQL_PORT'),
            'charset'  => env('DATA_MYSQL_CHARSET'),
        ];
    }
}

if (!function_exists('getOptionsPostgresql')) {
    /**
     * Get postgresql db options
     */
    function getOptionsPostgresql(): array
    {
        return [
            'host'     => env('DATA_POSTGRES_HOST'),
            'username' => env('DATA_POSTGRES_USER'),
            'password' => env('DATA_POSTGRES_PASS'),
            'port'     => env('DATA_POSTGRES_PORT'),
            'dbname'   => env('DATA_POSTGRES_NAME'),
            'schema'   => env('DATA_POSTGRES_SCHEMA'),
        ];
    }
}

if (!function_exists('getOptionsSqlite')) {
    /**
     * Get sqlite db options
     */
    function getOptionsSqlite(): array
    {
        return [
            'dbname' => dirname(__DIR__ ) . PHP_EOL . env('DATA_SQLITE_NAME'),
        ];
    }
}
