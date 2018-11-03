<?php

namespace Phalcon\Test\Unit;

use Phalcon\Loader;
use Phalcon\Events\Manager;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\LoaderTest
 * Tests the \Phalcon\Loader component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class LoaderTest extends UnitTest
{
    protected $loaders;
    protected $includePath;

    /**
     * executed before each test
     */
    protected function _before()
    {
        parent::_before();

        $this->loaders = spl_autoload_functions();
        if (!is_array($this->loaders)) {
            $this->loaders = [];
        }

        $this->includePath = get_include_path();
    }

    /**
     * executed after each test
     */
    protected function _after()
    {
        parent::_after();

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

    public function testNamespaces()
    {
        $this->specify(
            "The loader does not register namespaces correctly",
            function () {
                $loader = new Loader();

                $loader->registerNamespaces([
                    'Example\Base' => PATH_DATA . 'vendor/Example/Base/',
                ]);

                $loader->registerNamespaces([
                    'Example\Adapter' => PATH_DATA . 'vendor/Example/Adapter/',
                    'Example' => PATH_DATA . 'vendor/Example/'
                ], true);

                $loader->register();

                expect(new \Example\Adapter\Some())->isInstanceOf('Example\Adapter\Some');
                expect(new \Example\Adapter\LeSome())->isInstanceOf('Example\Adapter\LeSome');
                expect(new \Example\Engines\LeEngine())->isInstanceOf('Example\Engines\LeEngine');
                expect(new \Example\Example\Example())->isInstanceOf('Example\Example\Example');

                $loader->unregister();
            }
        );
    }

    public function testNamespacesExtensions()
    {
        $this->specify(
            "The loader does not register namespaces correctly with different extension",
            function () {
                $loader = new Loader();

                $loader->setExtensions(['inc', 'php']);
                $loader->registerNamespaces([
                    'Example\Base' => PATH_DATA . 'vendor/Example/Base/',
                    'Example\Adapter' => PATH_DATA . 'vendor/Example/Adapter/',
                ]);

                $loader->registerNamespaces([
                    'Example' => PATH_DATA . 'vendor/Example/'
                ], true);

                $loader->register();

                expect(new \Example\Engines\LeOtherEngine())->isInstanceOf('Example\Engines\LeOtherEngine');

                $loader->unregister();
            }
        );
    }

    public function testDirectories()
    {
        $this->specify(
            "The loader does not load classes correctly with using directories strategy",
            function () {
                $loader = new Loader();

                $loader->registerDirs([
                    // missing trailing slash
                    PATH_DATA . 'vendor/Example/Dialects',
                ]);

                $loader->registerDirs([
                    PATH_DATA . 'vendor/',
                    PATH_DATA . 'vendor/Example/Types/',
                ], true);

                $loader->register();

                expect(new \LeDialect())->isInstanceOf('LeDialect');
                expect(new \SomeType())->isInstanceOf('SomeType');
                expect(new \Example\Adapter\SomeCool())->isInstanceOf('Example\Adapter\SomeCool');
                expect(new \Example\Adapter\LeCoolSome())->isInstanceOf('Example\Adapter\LeCoolSome');

                $loader->unregister();
            }
        );
    }

    public function testFiles()
    {
        $this->specify(
            "The loader does not load files correctly when using the files strategy",
            function () {
                // TEST CASE : Register the file and check if functions in the file is accessible
                expect(function_exists('noClassFoo'))->false();
                expect(function_exists('noClassBar'))->false();
                expect(function_exists('noClass1Foo'))->false();
                expect(function_exists('noClass1Bar'))->false();
                expect(function_exists('noClass2Foo'))->false();
                expect(function_exists('noClass2Bar'))->false();
                $loader = new Loader();
                $loader->registerFiles([
                    PATH_DATA . 'vendor/Example/Other/NoClass.php',
                    PATH_DATA . 'vendor/Example/Other/NoClass1.php'
                ]);
                $loader->registerFiles([
                    PATH_DATA . 'vendor/Example/Other/NoClass2.php'
                ], true);
                $loader->register();
                expect(function_exists('noClassFoo'))->true();
                expect(function_exists('noClassBar'))->true();
                expect(function_exists('noClass1Foo'))->true();
                expect(function_exists('noClass1Bar'))->true();
                expect(function_exists('noClass2Foo'))->true();
                expect(function_exists('noClass2Bar'))->true();
                // TEST CASE : We are going to un-register it, but the functions should still be accessible
                $loader->unregister();
                expect(function_exists('noClassFoo'))->true();
                expect(function_exists('noClassBar'))->true();
                expect(function_exists('noClass1Foo'))->true();
                expect(function_exists('noClass1Bar'))->true();
                expect(function_exists('noClass2Foo'))->true();
                expect(function_exists('noClass2Bar'))->true();
            }
        );
    }

    public function testNamespacesForMultipleDirectories()
    {
        $this->specify(
            "The loader does not load classes correctly with using multiple directories strategy",
            function () {
                $loader = new Loader();

                $loader->registerNamespaces(["Example\\Base" => PATH_DATA . 'vendor/Example/Base/']);

                expect($loader->getNamespaces())->equals(["Example\\Base" => [PATH_DATA . 'vendor/Example/Base/']]);

                $loader->registerNamespaces(
                    [
                        "Example\\Adapter" =>
                        [
                            PATH_DATA . 'vendor/Example/Adapter/',
                            PATH_DATA . 'vendor/Example/Adapter2/',
                        ],
                    ],
                    true
                );

                expect($loader->getNamespaces())->equals([
                    "Example\\Base" => [
                        PATH_DATA . 'vendor/Example/Base/'
                    ],
                    "Example\\Adapter" =>
                    [
                        PATH_DATA . 'vendor/Example/Adapter/',
                        PATH_DATA . 'vendor/Example/Adapter2/',
                    ],
                ]);

                $loader->register();

                expect(new \Example\Adapter\Some())->isInstanceOf('Example\Adapter\Some');
                expect(new \Example\Adapter\Another())->isInstanceOf('Example\Adapter\Another');
                expect(new \Example\Adapter\LeSome())->isInstanceOf('Example\Adapter\LeSome');

                $loader->unregister();
            }
        );
    }

    public function testDirectoriesExtensions()
    {
        $this->specify(
            "The loader does not load classes correctly with using directories strategy and different extension",
            function () {
                $loader = new Loader();

                $loader->setExtensions(['inc', 'php']);
                $loader->registerDirs([
                    PATH_DATA . 'vendor/Example/Dialects/',
                    PATH_DATA . 'vendor/Example/Types/',
                    PATH_DATA . 'vendor/',
                ]);

                $loader->register();

                expect(new \Example\Adapter\LeAnotherSome())->isInstanceOf('Example\Adapter\LeAnotherSome');

                $loader->unregister();
            }
        );
    }

    public function testClasses()
    {
        $this->specify(
            "The loader does not load classes correctly",
            function () {
                $loader = new Loader();

                $loader->registerClasses(['MoiTest' => PATH_DATA . 'vendor/Example/Test/MoiTest.php']);
                $loader->registerClasses(['LeTest' => PATH_DATA . 'vendor/Example/Test/LeTest.php'], true);
                $loader->register();

                expect(new \MoiTest())->isInstanceOf('MoiTest');
                expect(new \LeTest())->isInstanceOf('LeTest');

                $loader->unregister();
            }
        );
    }

    public function testEvents()
    {
        $this->specify(
            "The loader does not fire events correctly",
            function () {
                $loader = new Loader();

                $loader->registerDirs([
                    PATH_DATA . 'vendor/Example/Other/'
                ]);

                $loader->registerClasses([
                    'AvecTest' => PATH_DATA . 'vendor/Example/Other/Avec/'
                ]);

                $loader->registerNamespaces([
                    'Avec\Test' => PATH_DATA . 'vendor/Example/Other/Avec/'
                ]);

                $eventsManager = new Manager();
                $trace = [];

                $eventsManager->attach('loader', function ($event, $loader) use (&$trace) {
                    /** @var \Phalcon\Events\Event $event */
                    /** @var Loader $loader */
                    if (!isset($trace[$event->getType()])) {
                        $trace[$event->getType()] = [];
                    }
                    $trace[$event->getType()][] = $loader->getCheckedPath();
                });

                $loader->setEventsManager($eventsManager);

                $loader->register();

                expect(new \VousTest())->isInstanceOf('VousTest');
                expect($trace)->equals([
                    'beforeCheckClass' => [0 => null],
                    'beforeCheckPath'  => [0 => PATH_DATA . 'vendor/Example/Other/VousTest.php'],
                    'pathFound'        => [0 => PATH_DATA . 'vendor/Example/Other/VousTest.php'],
                ]);

                $loader->unregister();
            }
        );
    }

    /**
     * Tests Loader::setFileCheckingCallback
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2018-04-29
     * @issue  https://github.com/phalcon/cphalcon/issues/13360
     * @issue  https://github.com/phalcon/cphalcon/issues/10472
     */
    public function shouldNotFindFilesWithFalseCallback()
    {
        $this->specify(
            'File checking does not work as expected',
            function () {
                $loader = new Loader();
                $loader->setFileCheckingCallback(function ($file) {
                    return false;
                });

                $loader->registerFiles([
                    PATH_DATA . 'vendor/Example/Other/NoClass3.php'
                ]);

                $loader->registerNamespaces([
                    'Example' => PATH_DATA . 'vendor/Example/'
                ], true);

                $loader->register();

                expect(function_exists('noClass3Foo'))->false();
                expect(function_exists('noClass3Bar'))->false();
            }
        );
    }

    /**
     * Tests Loader::setFileCheckingCallback
     *
     * @test
     * @author Serghei Iakovlev <serghei@phalconphp.com>
     * @since  2018-04-29
     * @issue  https://github.com/phalcon/cphalcon/issues/13360
     * @issue  https://github.com/phalcon/cphalcon/issues/10472
     */
    public function shouldWorkWithCustomFileCheckCallback()
    {
        $this->specify(
            'File checking does not work as expected',
            function () {
                $loader = new Loader();
                $loader->setFileCheckingCallback('stream_resolve_include_path');

                $loader->registerFiles([
                    PATH_DATA . 'vendor/Example/Other/NoClass3.php'
                ]);

                $loader->registerNamespaces([
                    'Example' => PATH_DATA . 'vendor/Example/'
                ], true);

                $loader->register();

                expect(function_exists('noClass3Foo'))->true();
                expect(function_exists('noClass3Bar'))->true();
                expect(class_exists('\Example\Engines\LeEngine2'))->true();
            }
        );
    }
}
