<?php
/**
 * UnitTest.php
 * Loader_UnitTest
 *
 * Tests the \Phalcon\Loader component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2012 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Eduar Carvajal <eduar@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@niden.net>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

use \Phalcon\Loader as PhLoader;

class Loader_UnitTest extends Phalcon_Test_UnitTestCase
{
    public function testNamespaces()
    {

        $loader = new PhLoader();

        $loader->registerNamespaces(
            array(
                "Example\Base"    => PATH_VENDORS . "example/base/",
                "Example\Adapter" => PATH_VENDORS . "example/adapter/",
                "Example"         => PATH_VENDORS . "example/"
            )
        );

        $loader->register();

        $some = new \Example\Adapter\Some();
        $this->assertEquals(get_class($some), 'Example\Adapter\Some');

        $leSome = new \Example\Adapter\LeSome();
        $this->assertEquals(get_class($leSome), 'Example\Adapter\LeSome');

        $leEngine = new \Example\Engines\LeEngine();
        $this->assertEquals(get_class($leEngine), 'Example\Engines\LeEngine');

        $loader->unregister();
    }

    public function testNamespacesExtensions()
    {

        $loader = new PhLoader();

        $loader->setExtensions(array('inc', 'php'));

        $loader->registerNamespaces(
            array(
                "Example\Base"    => PATH_VENDORS . "example/base/",
                "Example\Adapter" => PATH_VENDORS . "example/adapter/",
                "Example"         => PATH_VENDORS . "example/"
            )
        );

        $loader->register();

        $leEngine = new \Example\Engines\LeOtherEngine();
        $this->assertEquals(get_class($leEngine), 'Example\Engines\LeOtherEngine');
        $this->assertTrue($leEngine->some());

        $loader->unregister();
    }

    public function testDirectories()
    {

        $loader = new PhLoader();

        $loader->registerDirs(
            array(
                PATH_VENDORS . "example/dialects/",
                PATH_VENDORS . "example/types/",
                PATH_VENDORS,
            )
        );

        $loader->register();

        $dialect = new LeDialect();
        $this->assertEquals(get_class($dialect), 'LeDialect');

        $someType = new SomeType();
        $this->assertEquals(get_class($someType), 'SomeType');

        $some = new \example\adapter\SomeCool();
        $this->assertEquals(get_class($some), 'Example\Adapter\SomeCool');

        $leSome = new \example\adapter\LeCoolSome();
        $this->assertEquals(get_class($leSome), 'Example\Adapter\LeCoolSome');

        $loader->unregister();
    }

    public function testDirectoriesExtensions()
    {

        $loader = new PhLoader();

        $loader->setExtensions(array('inc', 'php'));

        $loader->registerDirs(
            array(
                PATH_VENDORS . "example/dialects/",
                PATH_VENDORS . "example/types/",
                PATH_VENDORS,
            )
        );

        $loader->register();

        $leSome = new \example\adapter\LeAnotherSome();
        $this->assertEquals(get_class($leSome), 'Example\Adapter\LeAnotherSome');

        $loader->unregister();
    }

    public function testClasses()
    {

        $loader = new PhLoader();

        $loader->registerClasses(
            array(
                "MoiTest" => PATH_VENDORS . "example/test/MoiTest.php",
                "LeTest"  => PATH_VENDORS . "example/test/LeTest.php",
            )
        );

        $loader->register();

        $test = new MoiTest();
        $this->assertEquals(get_class($test), 'MoiTest');

        $leTest = new LeTest();
        $this->assertEquals(get_class($leTest), 'LeTest');

        $loader->unregister();
    }

    public function testPrefixes()
    {

        $loader = new PhLoader();

        $loader->registerPrefixes(
            array(
                "Pseudo" => PATH_VENDORS . "example/Pseudo/",
            )
        );

        $loader->register();

        $pseudoClass = new Pseudo_Some_Something();
        $this->assertEquals(get_class($pseudoClass), 'Pseudo_Some_Something');

        $pseudoClass = new Pseudo_Base();
        $this->assertEquals(get_class($pseudoClass), 'Pseudo_Base');

        $loader->unregister();
    }

    public function testEvents()
    {
        $this->markTestSkipped('This test needs some love from Andres');
        
        $loader = new PhLoader();

        $loader->registerDirs(
            array(PATH_VENDORS . "example/other/")
        );

        $loader->registerClasses(
            array("AvecTest" => PATH_VENDORS . "example/other/Avec/")
        );

        $loader->registerNamespaces(
            array("Avec\Test" => PATH_VENDORS . "example/other/Avec/")
        );

        $loader->registerPrefixes(
            array("Avec_" => PATH_VENDORS . "example/other/Avec/")
        );

        $loader->register();

        $eventsManager = new \Phalcon\Events\Manager();

        $trace = array();

        $eventsManager->attach(
            'loader',
            function($event, $loader) use (&$trace)
            {
                if (!isset($trace[$event->getType()]))
                {
                    $trace[$event->getType()] = array();
                }
                $trace[$event->getType()][] = $loader->getCheckedPath();
            }
        );

        $loader->setEventsManager($eventsManager);

        $loader->register();

        $test = new VousTest();
        $this->assertEquals(get_class($test), 'VousTest');

        $this->assertEquals(
            $trace,
            array(
                'beforeCheckClass' => array(0 => NULL),
                'beforeCheckPath'  => array(0 => PATH_VENDORS . 'example/other/VousTest.php'),
                'pathFound'        => array(0 => PATH_VENDORS . 'example/other/VousTest.php'),
            )
        );

        $loader->unregister();

    }
}