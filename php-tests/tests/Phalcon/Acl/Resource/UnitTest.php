<?php
/**
 * UnitTest.php
 * \Phalcon\Acl\Resource\UnitTest
 *
 * Tests the \Phalcon\Acl\Resource component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */

namespace Phalcon\Test\Acl\Resource;

use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;

use \Phalcon\Acl\Resource as AclResource;

class UnitTest extends PhTestUnitTestCase
{
    /**
     * Tests the creation of an Acl Resource (name)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testAclResourceName()
    {
        $aclResource = new AclResource('Administrators');

        $expected = 'Administrators';
        $actual   = $aclResource->getName();
        $this->assertEquals(
            $expected,
            $actual,
            'Acl\Resource does not return correct name'
        );

        $expected = '';
        $actual   = $aclResource->getDescription();
        $this->assertEquals(
            $expected,
            $actual,
            'Acl\Resource does not return correct description'
        );

    }

    /**
     * Tests the creation of an Acl Resource (name / description)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2012-11-30
     */
    public function testAclResourceNameDescription()
    {
        $aclResource = new AclResource('Administrators', 'Super-User Resource');

        $expected = 'Administrators';
        $actual   = $aclResource->getName();
        $this->assertEquals(
            $expected,
            $actual,
            'Acl\Resource does not return correct name'
        );

        $expected = 'Super-User Resource';
        $actual   = $aclResource->getDescription();
        $this->assertEquals(
            $expected,
            $actual,
            'Acl\Resource does not return correct description'
        );

    }
}
