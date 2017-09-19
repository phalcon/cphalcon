<?php

namespace Phalcon\Test\Unit\Annotations\Adapter;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Annotations\Adapter\Files;

/**
 * Phalcon\Test\Unit\Annotations\Adapter\FilesTest
 * Tests for \Phalcon\Annotations\Adapter\Files component
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
class FilesTest extends UnitTest
{
    public function testFilesAdapter()
    {
        require_once PATH_DATA . 'annotations/TestClass.php';
        require_once PATH_DATA . 'annotations/TestClassNs.php';

        $adapter = new Files(['annotationsDir' => PATH_OUTPUT . 'tests/annotations/']);

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

        unset($adapter);

        $this->tester->amInPath(PATH_OUTPUT . 'tests/annotations/');

        $this->tester->deleteFile('testclass.php');
        $this->tester->deleteFile('user_testclassns.php');
    }
}
