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

use Phalcon\Events\Manager;
use Phalcon\Loader;
use UnitTester;
use function dataFolder;

class LoaderCest
{
    protected $loaders;
    protected $includePath;

    public function testNamespaces(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerNamespaces(
            [
                'Example\Namespaces\Base' => dataFolder('fixtures/Loader/Example/Namespaces/Base/'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Example\Namespaces\Adapter' => dataFolder('fixtures/Loader/Example/Namespaces/Adapter/'),
                'Example\Namespaces'         => dataFolder('fixtures/Loader/Example/Namespaces/'),
            ],
            true
        );

        $loader->register();

        $I->assertInstanceOf('Example\Namespaces\Adapter\Mongo', new \Example\Namespaces\Adapter\Mongo());
        $I->assertInstanceOf('Example\Namespaces\Adapter\Redis', new \Example\Namespaces\Adapter\Redis());
        $I->assertInstanceOf('Example\Namespaces\Engines\Gasoline', new \Example\Namespaces\Engines\Gasoline());
        $I->assertInstanceOf('Example\Namespaces\Example\Example', new \Example\Namespaces\Example\Example());

        $loader->unregister();
    }

    public function testNamespacesExtensions(UnitTester $I)
    {
        $loader = new Loader();

        $loader->setExtensions(['inc', 'php']);
        $loader->registerNamespaces(
            [
                'Example\Namespaces\Base' => dataFolder('fixtures/Loader/Example/Namespaces/Base/'),
                'Example\Namespaces'      => dataFolder('fixtures/Loader/Example/Namespaces/'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Example' => dataFolder('fixtures/Loader/Example/Namespaces/'),
            ],
            true
        );

        $loader->register();

        $I->assertInstanceOf('Example\Namespaces\Engines\Alcohol', new \Example\Namespaces\Engines\Alcohol());

        $loader->unregister();
    }

    public function testDirectories(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerDirs(
            [
                // missing trailing slash
                dataFolder('fixtures/Loader/Example/Folders/Dialects'),
            ]
        );

        $loader->registerDirs(
            [
                dataFolder('fixtures/Loader/Example/Folders/Types/'),
            ],
            true
        );

        $loader->register();

        $I->assertInstanceOf('Sqlite', new \Sqlite());
        $I->assertInstanceOf('Integer', new \Integer());

        $loader->unregister();
    }

    public function testFiles(UnitTester $I)
    {
        // TEST CASE : Register the file and check if functions in the file is accessible
        $I->assertFalse(function_exists('noClassFoo'));
        $I->assertFalse(function_exists('noClassBar'));
        $I->assertFalse(function_exists('noClass1Foo'));
        $I->assertFalse(function_exists('noClass1Bar'));
        $I->assertFalse(function_exists('noClass2Foo'));
        $I->assertFalse(function_exists('noClass2Bar'));

        $loader = new Loader();
        $loader->registerFiles(
            [
                dataFolder('fixtures/Loader/Example/Functions/FunctionsNoClass.php'),
                dataFolder('fixtures/Loader/Example/Functions/FunctionsNoClassOne.php'),
            ]
        );
        $loader->registerFiles(
            [
                dataFolder('fixtures/Loader/Example/Functions/FunctionsNoClassTwo.php'),
            ],
            true
        );
        $loader->register();

        $I->assertTrue(function_exists('noClassFoo'));
        $I->assertTrue(function_exists('noClassBar'));
        $I->assertTrue(function_exists('noClass1Foo'));
        $I->assertTrue(function_exists('noClass1Bar'));
        $I->assertTrue(function_exists('noClass2Foo'));
        $I->assertTrue(function_exists('noClass2Bar'));

        // TEST CASE : We are going to un-register it, but the functions should still be accessible
        $loader->unregister();

        $I->assertTrue(function_exists('noClassFoo'));
        $I->assertTrue(function_exists('noClassBar'));
        $I->assertTrue(function_exists('noClass1Foo'));
        $I->assertTrue(function_exists('noClass1Bar'));
        $I->assertTrue(function_exists('noClass2Foo'));
        $I->assertTrue(function_exists('noClass2Bar'));
    }

    public function testNamespacesForMultipleDirectories(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerNamespaces(
            [
                "Example\\Namespaces\\Base" => dataFolder('fixtures/Loader/Example/Namespaces/Base/'),
            ]
        );

        $expected = [
            "Example\\Namespaces\\Base" => [
                dataFolder('fixtures/Loader/Example/Namespaces/Base/'),
            ],
        ];
        $actual   = $loader->getNamespaces();
        $I->assertEquals($expected, $actual);

        $loader->registerNamespaces(
            [
                "Example\\Namespaces\\Adapter" => [
                    dataFolder('fixtures/Loader/Example/Namespaces/Adapter/'),
                    dataFolder('fixtures/Loader/Example/Namespaces/Plugin/'),
                ],
            ],
            true
        );

        $expected = [
            "Example\\Namespaces\\Base"    => [
                dataFolder('fixtures/Loader/Example/Namespaces/Base/'),
            ],
            "Example\\Namespaces\\Adapter" => [
                dataFolder('fixtures/Loader/Example/Namespaces/Adapter/'),
                dataFolder('fixtures/Loader/Example/Namespaces/Plugin/'),
            ],
        ];
        $actual   = $loader->getNamespaces();
        $I->assertEquals($expected, $actual);

        $loader->register();

        $I->assertInstanceOf('Example\Namespaces\Adapter\Mongo', new \Example\Namespaces\Adapter\Mongo());
        $I->assertInstanceOf('Example\Namespaces\Adapter\Another', new \Example\Namespaces\Adapter\Another());
        $I->assertInstanceOf('Example\Namespaces\Adapter\Redis', new \Example\Namespaces\Adapter\Redis());

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
                dataFolder('fixtures/Loader/Example/Folders/Dialects'),
                dataFolder('fixtures/Loader/Example/Folders/Types'),
                dataFolder('fixtures/Loader/Example/Namespaces/Adapter'),
            ]
        );

        $loader->register();

        $I->assertInstanceOf('Example\Namespaces\Adapter\File', new \Example\Namespaces\Adapter\File());

        $loader->unregister();
    }

    public function testClasses(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerClasses(
            [
                'One' => dataFolder('fixtures/Loader/Example/Classes/One.php'),
            ]
        );
        $loader->registerClasses(
            [
                'Two' => dataFolder('fixtures/Loader/Example/Classes/Two.php'),
            ],
            true
        );
        $loader->register();

        $I->assertInstanceOf('One', new \One());
        $I->assertInstanceOf('Two', new \Two());

        $loader->unregister();
    }

    public function testEvents(UnitTester $I)
    {
        $loader = new Loader();

        $loader->registerDirs(
            [
                dataFolder('fixtures/Loader/Example/Events/'),
            ]
        );

        $loader->registerClasses(
            [
                'OtherClass' => dataFolder('fixtures/Loader/Example/Events/Other/'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Other\OtherClass' => dataFolder('fixtures/Loader/Example/Events/Other/'),
            ]
        );

        $eventsManager = new Manager();
        $trace         = [];

        $eventsManager->attach(
            'loader',
            function ($event, $loader) use (&$trace) {
                /** @var \Phalcon\Events\Event $event */
                /** @var Loader $loader */
                if (!isset($trace[$event->getType()])) {
                    $trace[$event->getType()] = [];
                }
                $trace[$event->getType()][] = $loader->getCheckedPath();
            }
        );

        $loader->setEventsManager($eventsManager);
        $loader->register();

        $I->assertInstanceOf('LoaderEvent', new \LoaderEvent());

        $expected = [
            'beforeCheckClass' => [0 => null],
            'beforeCheckPath'  => [0 => dataFolder('fixtures/Loader/Example/Events/LoaderEvent.php')],
            'pathFound'        => [0 => dataFolder('fixtures/Loader/Example/Events/LoaderEvent.php')],
        ];
        $actual   = $trace;
        $I->assertEquals($expected, $actual);

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
                dataFolder('fixtures/Loader/Example/Functions/FunctionsNoClassThree.php'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Example' => dataFolder('fixtures/Loader/Example/'),
            ],
            true
        );

        $loader->register();

        $I->assertFalse(function_exists('noClass3Foo'));
        $I->assertFalse(function_exists('noClass3Bar'));
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
                dataFolder('fixtures/Loader/Example/Functions/FunctionsNoClassThree.php'),
            ]
        );

        $loader->registerNamespaces(
            [
                'Example\Namespaces' => dataFolder('fixtures/Loader/Example/Namespaces'),
            ],
            true
        );

        $loader->register();

        $I->assertTrue(function_exists('noClass3Foo'));
        $I->assertTrue(function_exists('noClass3Bar'));
        $I->assertTrue(class_exists('\Example\Namespaces\Engines\Diesel'));
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

        set_include_path($this->includePath);
    }
}
