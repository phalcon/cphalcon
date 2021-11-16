<?php

namespace Helper;

use function cacheDir;
use Codeception\Configuration;
use Codeception\Exception\ModuleConfigException;
use Codeception\Lib\ModuleContainer;
use Codeception\Module\Filesystem;
use Phalcon\Cache\Backend\File as FileBackend;
use Phalcon\Cache\Frontend\Data;
use Phalcon\Cache\Frontend\Igbinary;
use Phalcon\Cache\FrontendInterface;

/**
 * Phalcon\Tests\Module\Cache\Backend\File
 *
 * Module for testing backend cache adapters
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          https://phalcon.io
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalcon.io
 * so that we can send you a copy immediately.
 */
class PhalconCacheFile extends Filesystem
{
    /**
     * @var null|FileBackend
     */
    protected $backend = null;

    /**
     * @var null|FrontendInterface
     */
    protected $frontend = null;

    protected $projectPath = '';

    /**
     * @var null|callable
     */
    protected $serializeCallback = null;

    /**
     * @var null|callable
     */
    protected $unserializeCallback = null;

    /**
     * {@inheritdoc}
     * @var array
     */
    protected $config = [];

    /**
     * {@inheritdoc}
     * @var array
     */
    protected $requiredFields = ['frontend', 'backend'];

    /**
     * File Constructor.
     *
     * @throws ModuleConfigException
     */
    public function __construct(ModuleContainer $container, array $config = [])
    {
        $defaults = [
            'frontend'  => Data::class,
            'backend'   => FileBackend::class,
            'prefix'    => 'data_',
            'lifetime'  => 10,
            'cache_dir' => cacheDir(),
        ];

        $this->projectPath = Configuration::projectDir();

        $this->config = array_merge($defaults, $config);

        parent::__construct($container);
    }

    /**
     * ```php
     * <?php
     * use Phalcon\Cache\Frontend\Data;
     *
     * $I->haveFrontendAdapter(Data::class);
     * $I->haveFrontendAdapter(Data::class, ['prefix' => 'my_prefix_']);
     * ?>
     * ```
     *
     * @param string $className
     * @param array  $config
     */
    public function haveFrontendAdapter($className, array $config = null)
    {
        $defaults = [
            'frontend' => $className,
            'backend'  => $this->config['backend'],
        ];

        $config = array_merge($defaults, $config);

        $this->_reconfigure($config);

        $this->debugSection(
            'Frontend',
            get_class($this->frontend)
        );
    }

    public function dontSeeCacheStarted()
    {
        $this->assertFalse(
            $this->backend->isStarted()
        );
    }

    public function seeCacheStarted()
    {
        $this->assertTrue(
            $this->backend->isStarted()
        );
    }

    /**
     * Stores an item `$value` with `$key` on the cache backend.
     *
     * @param string $key
     * @param string $content
     * @param int    $lifetime
     * @param bool   $stopBuffer
     */
    public function haveInCacheStorage($key, $content = null, $lifetime = null, $stopBuffer = true)
    {
        $this->assertTrue(
            $this->backend->save($key, $content, $lifetime, $stopBuffer)
        );
    }

    /**
     * @param int|string $keyName
     */
    public function deleteCacheData($keyName)
    {
        $this->assertTrue(
            $this->backend->delete($keyName)
        );
    }

    /**
     * {@inheritdoc}
     *
     * @param string $filename
     * @param string $path
     */
    public function dontSeeCacheFound($filename, $path = '')
    {
        $filename = $this->config['prefix'] . $this->backend->getKey($filename);

        parent::dontSeeFileFound($filename, $path);
    }

    /**
     * Checks item in the cache backend exists and the same as expected.
     *
     * Examples:
     *
     * ``` php
     * <?php
     * // With only one argument, only checks the key exists
     * $I->seeInCacheStorage('users_count');
     *
     * // Checks a 'users_count' exists and has the value 200
     * $I->seeInCacheStorage('users_count', 200);
     * ?>
     * ```
     *
     * @param string $key
     * @param int    $lifetime
     */
    public function seeInCacheStorage($key, $value = null, $lifetime = null)
    {
        $this->assertTrue(
            $this->backend->exists($key, $lifetime)
        );

        $this->amInPath(
            $this->config['cache_dir']
        );

        $this->seeFileFound(
            $this->config['prefix'] . $this->backend->getKey($key)
        );

        $actual = $this->backend->get($key, $lifetime);

        $this->debugSection('Value', $actual);

        $serializeCallback = $this->serializeCallback;

        if (null === $value || !is_callable($serializeCallback)) {
            return;
        }

        $serialized = call_user_func_array($serializeCallback, [$value]);

        $this->assertSame(
            $serialized,
            $this->file
        );

        $this->assertSame(
            $serialized,
            $this->frontend->beforeStore($value)
        );
    }

    /**
     * {@inheritdoc}
     *
     * @throws ModuleConfigException
     */
    protected function onReconfigure()
    {
        $this->_initialize();
    }

    /**
     * {@inheritdoc}
     */
    public function _initialize()
    {
        $this->initializeCachePath(
            $this->config['cache_dir']
        );

        $this->initializeFrontend(
            $this->config['frontend']
        );

        $this->initializeBackend(
            $this->config['backend']
        );
    }

    /**
     * @throws ModuleConfigException
     */
    protected function initializeCachePath(string $dir)
    {
        $cacheDir = $this->absolutizePath($dir);

        if (is_file($cacheDir) || !is_dir($cacheDir) || !is_writable($cacheDir)) {
            throw new ModuleConfigException(
                __CLASS__,
                "The 'cache_dir' parameter should be a writable path to the cache directory."
            );
        }

        $this->config['cache_dir'] = $cacheDir;
    }

    /**
     * @throws ModuleConfigException
     */
    protected function initializeFrontend(string $className)
    {
        if (!class_exists($className)) {
            throw new ModuleConfigException(
                __CLASS__,
                "The 'frontend' parameter should be a fully qualified class name of the frontend adapter."
            );
        }

        $supportedFrontends = $this->getSupportedFrontends();

        $this->assertArrayHasKey($className, $supportedFrontends);

        if (isset($supportedFrontends[$className]['validate_cb'])) {
            call_user_func(
                $supportedFrontends[$className]['validate_cb']
            );
        }

        if (isset($supportedFrontends[$className]['serialize_cb'])) {
            $this->serializeCallback = $supportedFrontends[$className]['serialize_cb'];
        }

        if (isset($supportedFrontends[$className]['unserialize_cb'])) {
            $this->unserializeCallback = $supportedFrontends[$className]['unserialize_cb'];
        }

        $adapter = new $className(
            [
                'lifetime' => $this->config['lifetime'],
            ]
        );

        $this->config['frontend'] = $className;
        $this->frontend           = $adapter;
    }

    protected function getSupportedFrontends()
    {
        return [
            Data::class     => [
                'validate_cb'    => function () {
                    return true;
                },
                'serialize_cb'   => function ($data) {
                    return serialize($data);
                },
                'unserialize_cb' => function ($data) {
                    return unserialize($data);
                },
            ],
            Igbinary::class => [
                'validate_cb'    => function () {
                    if (!extension_loaded('igbinary')) {
                        throw new SkippedTestError(
                            "The 'igbinary' extension is not loaded."
                        );
                    }
                },
                'serialize_cb'   => function ($data) {
                    return igbinary_serialize($data);
                },
                'unserialize_cb' => function ($data) {
                    return is_numeric($data) ? $data : igbinary_unserialize($data);
                },
            ],
        ];
    }

    protected function initializeBackend($className)
    {
        $adapter = new FileBackend(
            $this->frontend,
            [
                'cacheDir' => $this->config['cache_dir'],
                'prefix'   => $this->config['prefix'],
            ]
        );

        $this->config['backend'] = $className;
        $this->backend           = $adapter;
    }
}
