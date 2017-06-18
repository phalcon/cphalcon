<?php

namespace Phalcon\Test\Unit\Annotations\Adapter;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Annotations\Adapter\Apcu;

/**
 * \Phalcon\Test\Unit\Annotations\Adapter\ApcuTest
 * Tests for \Phalcon\Annotations\Adapter\Apcu component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Serghei Iakovlev <serghei@phalconphp.com>
 * @package   Phalcon\Test\Unit\Annotations
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ApcuTest extends UnitTest
{
    /**
     * executed before each test
     */
    public function _before()
    {
        parent::_before();

        if (!function_exists('apcu_fetch')) {
            $this->markTestSkipped('Warning: APCu extension is not loaded');
        }

        require_once PATH_DATA . 'annotations/TestClass.php';
        require_once PATH_DATA . 'annotations/TestClassNs.php';
    }

    public function testApcAdapter()
    {
        $adapter = new Apcu();

        $classAnnotations = $adapter->get('TestClass');
        $this->assertTrue(is_object($classAnnotations));
        $this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
        $this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

        $classAnnotations = $adapter->get('TestClass');
        $this->assertTrue(is_object($classAnnotations));
        $this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
        $this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

        $classAnnotations = $adapter->get('User\TestClassNs');
        $this->assertTrue(is_object($classAnnotations));
        $this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
        $this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

        $classAnnotations = $adapter->get('User\TestClassNs');
        $this->assertTrue(is_object($classAnnotations));
        $this->assertEquals(get_class($classAnnotations), 'Phalcon\Annotations\Reflection');
        $this->assertEquals(get_class($classAnnotations->getClassAnnotations()), 'Phalcon\Annotations\Collection');

        $property = $adapter->getProperty('TestClass', 'testProp1');
        $this->assertTrue(is_object($property));
        $this->assertEquals(get_class($property), 'Phalcon\Annotations\Collection');
        $this->assertEquals($property->count(), 4);
    }
}
