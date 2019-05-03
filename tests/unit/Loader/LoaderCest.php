<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit;

use Example\Namespaces\Adapter\Another;
use Example\Namespaces\Adapter\File;
use Example\Namespaces\Adapter\Mongo;
use Example\Namespaces\Adapter\Redis;
use Example\Namespaces\Engines\Alcohol;
use Example\Namespaces\Engines\Gasoline;
use Example\Namespaces\Example\Example;
use LoaderEvent;
use One;
use Phalcon\Events\Event;
use Phalcon\Events\Manager;
use Phalcon\Loader;
use Sqlite;
use Two;
use UnitTester;
use function dataDir;

class LoaderCest
{
    protected $loaders;
    protected $includePath;

    public function testNamespaces(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerNamespaces(
            [
                'Example\Namespaces\Base' => dataDir('fixtures/Loader/Example/Namespaces/Base/'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Example\Namespaces\Adapter' => dataDir('fixtures/Loader/Example/Namespaces/Adapter/'),
                'Example\Namespaces'         => dataDir('fixtures/Loader/Example/Namespaces/'),
            ],
            true
        );

        $loader->register();

        $I->assertInstanceOf(
            Mongo::class,
            new Mongo()
        );

        $I->assertInstanceOf(
            Redis::class,
            new Redis()
        );

        $I->assertInstanceOf(
            Gasoline::class,
            new Gasoline()
        );

        $I->assertInstanceOf(
            Example::class,
            new Example()
        );

        $loader->unregister();
    }

    public function testNamespacesExtensions(UnitTester $I)
    {
        $loader = new Loader();

        $loader->setExtensions(
            [
                'inc',
                'php',
            ]
        );

        $loader->registerNamespaces(
            [
                'Example\Namespaces\Base' => dataDir('fixtures/Loader/Example/Namespaces/Base/'),
                'Example\Namespaces'      => dataDir('fixtures/Loader/Example/Namespaces/'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Example' => dataDir('fixtures/Loader/Example/Namespaces/'),
            ],
            true
        );

        $loader->register();

        $I->assertInstanceOf(
            Alcohol::class,
            new Alcohol()
        );

        $loader->unregister();
    }

    public function testDirectories(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerDirs(
            [
                // missing trailing slash
                dataDir('fixtures/Loader/Example/Folders/Dialects'),
            ]
        );

        $loader->registerDirs(
            [
                dataDir('fixtures/Loader/Example/Folders/Types/'),
            ],
            true
        );

        $loader->register();

        $I->assertInstanceOf(
            \Sqlite::class,
            new Sqlite()
        );

        $I->assertInstanceOf(
            \Integer::class,
            new \Integer()
        );

        $loader->unregister();
    }

    public function testFiles(UnitTester $I)
    {
        // TEST CASE : Register the file and check if functions in the file is accessible

        $I->assertFalse(
            function_exists('noClassFoo')
        );

        $I->assertFalse(
            function_exists('noClassBar')
        );

        $I->assertFalse(
            function_exists('noClass1Foo')
        );

        $I->assertFalse(
            function_exists('noClass1Bar')
        );

        $I->assertFalse(
            function_exists('noClass2Foo')
        );

        $I->assertFalse(
            function_exists('noClass2Bar')
        );

        $loader = new Loader();

        $loader->registerFiles(
            [
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClass.php'),
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassOne.php'),
            ]
        );
        $loader->registerFiles(
            [
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassTwo.php'),
            ],
            true
        );
        $loader->register();

        $I->assertTrue(
            function_exists('noClassFoo')
        );

        $I->assertTrue(
            function_exists('noClassBar')
        );

        $I->assertTrue(
            function_exists('noClass1Foo')
        );

        $I->assertTrue(
            function_exists('noClass1Bar')
        );

        $I->assertTrue(
            function_exists('noClass2Foo')
        );

        $I->assertTrue(
            function_exists('noClass2Bar')
        );

        // TEST CASE : We are going to un-register it, but the functions should still be accessible
        $loader->unregister();

        $I->assertTrue(
            function_exists('noClassFoo')
        );

        $I->assertTrue(
            function_exists('noClassBar')
        );

        $I->assertTrue(
            function_exists('noClass1Foo')
        );

        $I->assertTrue(
            function_exists('noClass1Bar')
        );

        $I->assertTrue(
            function_exists('noClass2Foo')
        );

        $I->assertTrue(
            function_exists('noClass2Bar')
        );
    }

    public function testNamespacesForMultipleDirectories(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerNamespaces(
            [
                "Example\\Namespaces\\Base" => dataDir('fixtures/Loader/Example/Namespaces/Base/'),
            ]
        );

        $expected = [
            "Example\\Namespaces\\Base" => [
                dataDir('fixtures/Loader/Example/Namespaces/Base/'),
            ],
        ];

        $I->assertEquals(
            $expected,
            $loader->getNamespaces()
        );

        $loader->registerNamespaces(
            [
                "Example\\Namespaces\\Adapter" => [
                    dataDir('fixtures/Loader/Example/Namespaces/Adapter/'),
                    dataDir('fixtures/Loader/Example/Namespaces/Plugin/'),
                ],
            ],
            true
        );

        $expected = [
            "Example\\Namespaces\\Base"    => [
                dataDir('fixtures/Loader/Example/Namespaces/Base/'),
            ],
            "Example\\Namespaces\\Adapter" => [
                dataDir('fixtures/Loader/Example/Namespaces/Adapter/'),
                dataDir('fixtures/Loader/Example/Namespaces/Plugin/'),
            ],
        ];

        $I->assertEquals(
            $expected,
            $loader->getNamespaces()
        );

        $loader->register();

        $I->assertInstanceOf(
            Mongo::class,
            new Mongo()
        );

        $I->assertInstanceOf(
            Another::class,
            new Another()
        );

        $I->assertInstanceOf(
            Redis::class,
            new Redis()
        );

        $loader->unregister();
    }

    public function testDirectoriesExtensions(UnitTester $I)
    {
        /**
         * @TODO: Check Extensions for this test
         */
        $I->skipTest('TODO: Check Extensions for this test');

        $loader = new Loader();

        $loader->setExtensions(
            [
                'inc',
                'php',
            ]
        );
        $loader->registerDirs(
            [
                dataDir('fixtures/Loader/Example/Folders/Dialects'),
                dataDir('fixtures/Loader/Example/Folders/Types'),
                dataDir('fixtures/Loader/Example/Namespaces/Adapter'),
            ]
        );

        $loader->register();

        $I->assertInstanceOf(
            File::class,
            new File()
        );

        $loader->unregister();
    }

    public function testClasses(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerClasses(
            [
                'One' => dataDir('fixtures/Loader/Example/Classes/One.php'),
            ]
        );
        $loader->registerClasses(
            [
                'Two' => dataDir('fixtures/Loader/Example/Classes/Two.php'),
            ],
            true
        );

        $loader->register();

        $I->assertInstanceOf(
            One::class,
            new One()
        );

        $I->assertInstanceOf(
            Two::class,
            new Two()
        );

        $loader->unregister();
    }

    public function testEvents(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerDirs(
            [
                dataDir('fixtures/Loader/Example/Events/'),
            ]
        );

        $loader->registerClasses(
            [
                'OtherClass' => dataDir('fixtures/Loader/Example/Events/Other/'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Other\OtherClass' => dataDir('fixtures/Loader/Example/Events/Other/'),
            ]
        );

        $eventsManager = new Manager();

        $trace = [];

        $eventsManager->attach(
            'loader',
            function ($event, $loader) use (&$trace) {
                $type = $event->getType();

                /** @var Event $event */
                /** @var Loader $loader */
                if (!isset($trace[$type])) {
                    $trace[$type] = [];
                }

                $trace[$type][] = $loader->getCheckedPath();
            }
        );

        $loader->setEventsManager($eventsManager);
        $loader->register();

        $I->assertInstanceOf('LoaderEvent', new LoaderEvent());

        $expected = [
            'beforeCheckClass' => [0 => null],
            'beforeCheckPath'  => [0 => dataDir('fixtures/Loader/Example/Events/LoaderEvent.php')],
            'pathFound'        => [0 => dataDir('fixtures/Loader/Example/Events/LoaderEvent.php')],
        ];

        $I->assertEquals($expected, $trace);

        $loader->unregister();
    }

    /**
     * Tests Loader::setFileCheckingCallback
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-04-29
     * @issue  https://github.com/phalcon/cphalcon/issues/13360
     * @issue  https://github.com/phalcon/cphalcon/issues/10472
     */
    public function shouldNotFindFilesWithFalseCallback(UnitTester $I)
    {
        $loader = new Loader();

        $loader->setFileCheckingCallback(
            function ($file) {
                return false;
            }
        );

        $loader->registerFiles(
            [
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassThree.php'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Example' => dataDir('fixtures/Loader/Example/'),
            ],
            true
        );

        $loader->register();

        $I->assertFalse(
            function_exists('noClass3Foo')
        );

        $I->assertFalse(
            function_exists('noClass3Bar')
        );
    }

    /**
     * Tests Loader::setFileCheckingCallback
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-04-29
     * @issue  https://github.com/phalcon/cphalcon/issues/13360
     * @issue  https://github.com/phalcon/cphalcon/issues/10472
     */
    public function shouldWorkWithCustomFileCheckCallback(UnitTester $I)
    {
        $loader = new Loader();

        $loader->setFileCheckingCallback('stream_resolve_include_path');

        $loader->registerFiles(
            [
                dataDir('fixtures/Loader/Example/Functions/FunctionsNoClassThree.php'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Example\Namespaces' => dataDir('fixtures/Loader/Example/Namespaces'),
            ],
            true
        );

        $loader->register();

        $I->assertTrue(
            function_exists('noClass3Foo')
        );

        $I->assertTrue(
            function_exists('noClass3Bar')
        );

        $I->assertTrue(
            class_exists('\Example\Namespaces\Engines\Diesel')
        );
    }

    /**
     * executed before each test
     */
    protected function _before(UnitTester $I)
    {
        $this->loaders = spl_autoload_functions();

        if (!is_array($this->loaders)) {
            $this->loaders = [];
        }

        $this->includePath = get_include_path();
    }

    /**
     * executed after each test
     */
    protected function _after(UnitTester $I)
    {
        $loaders = spl_autoload_functions();

        if (is_array($loaders)) {
            foreach ($loaders as $loader) {
                spl_autoload_unregister($loader);
            }
        }

        foreach ($this->loaders as $loader) {
            spl_autoload_register($loader);
        }

        set_include_path(
            $this->includePath
        );
    }
}
