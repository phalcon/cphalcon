<?php
/**
 * UnitTest.php
 * \Phalcon\Acl\Adapter\Memory\UnitTest
 *
 * Tests the \Phalcon\Acl\Adapter\Memory component
 *
 * PhalconPHP Framework
 *
 * @copyright (c) 2011-2014 Phalcon Team
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

namespace Phalcon\Test\Acl\Adapter\Memory;

use \Phalcon\Test\UnitTestCase as PhTestUnitTestCase;

use \Phalcon\Acl as PhAcl;
use \Phalcon\Acl\Role as PhAclRole;
use \Phalcon\Acl\Resource as PhAclResource;
use \Phalcon\Acl\Adapter\Memory as PhAclMem;

class UnitTest extends PhTestUnitTestCase
{
    /**
     * Tests the setDefaultAction
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testAclDefaultAction()
    {
        $acl = new PhAclMem();

        $acl->setDefaultAction(PhAcl::ALLOW);

        $expected = PhAcl::ALLOW;
        $actual   = $acl->getDefaultAction();
        $this->assertEquals(
            $expected,
            $actual,
            'Acl\Adapter\Memory does not get/set the default action correctly'
        );
    }

    /**
     * Tests the addRole
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testAddRoleExists()
    {
        $acl     = new PhAclMem();
        $aclRole = new PhAclRole('Administrators', 'Super User access');

        $acl->addRole($aclRole);

        $actual = $acl->isRole('Administrators');

        $this->assertTrue($actual, 'Acl\Role does not exist in Acl');
    }

    /**
     * Tests the addRole
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testAddRoleTwiceReturnsFalse()
    {
        $acl     = new PhAclMem();
        $aclRole = new PhAclRole('Administrators', 'Super User access');

        $acl->addRole($aclRole);
        $actual = $acl->addRole($aclRole);

        $this->assertFalse($actual, 'Acl\Role added twice returns true');
    }

    /**
     * Tests the addRole
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testAddRoleTwiceByKeyReturnsFalse()
    {
        $acl     = new PhAclMem();
        $aclRole = new PhAclRole('Administrators', 'Super User access');

        $acl->addRole($aclRole);
        $actual = $acl->addRole('Administrators');

        $this->assertFalse($actual, 'Acl\Role added twice by key returns true');
    }

    /**
     * Tests the isRole with wrong keyword
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-30
     */
    public function testIsRoleWithWrongKeyReturnsFalse()
    {
        $acl     = new PhAclMem();

        $actual = $acl->isRole('Wrong');

        $this->assertFalse($actual, 'Acl\Role added with wrong key returns true in isRole');
    }

    /**
     * Tests the role name
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-04
     */
    public function testRoleName()
    {
        $acl     = new PhAclMem();
        $aclRole = new PhAclRole('Administrators', 'Super User access');

        $acl->addRole($aclRole);

        $exists = $acl->isRole('Administrators');

        $this->assertTrue($exists, 'Acl\Role does not exist in Acl');
    }

    /**
     * Tests the addResource
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testAddResourceExists()
    {
        $acl         = new PhAclMem();
        $aclResource = new PhAclResource('Customers', 'Customer management');

        $actual = $acl->addResource($aclResource. 'search');

        $this->assertTrue($actual, 'Acl\Resource does not exist in Acl');
    }

    /**
     * Tests the resource name
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testResourceName()
    {
        $acl         = new PhAclMem();
        $aclResource = new PhAclResource('Customers', 'Customer management');

        $acl->addResource($aclResource. 'search');

        $exists = $acl->isResource('Customers');

        $this->assertFalse($exists, 'Acl\Resource does not exist in the acl');
    }

    /**
     * Tests the ACL objects default
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testAclObjectsDefault()
    {
        $acl         = new PhAclMem();
        $aclRole     = new PhAclRole('Administrators', 'Super User access');
        $aclResource = new PhAclResource('Customers', 'Customer management');

        $acl->setDefaultAction(PhAcl::DENY);

        $acl->addRole($aclRole);
        $acl->addResource($aclResource, array('search', 'destroy'));

        $expected = PhAcl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
        $this->assertEquals(
            $expected,
            $actual,
            'Object does not contain correct ACL for search (default)'
        );

        $expected = PhAcl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
        $this->assertEquals(
            $expected,
            $actual,
            'Object does not contain correct ACL for destroy (default)'
        );
    }

    /**
     * Tests the ACL objects
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testAclObjects()
    {
        $acl         = new PhAclMem();
        $aclRole     = new PhAclRole('Administrators', 'Super User access');
        $aclResource = new PhAclResource('Customers', 'Customer management');

        $acl->addRole($aclRole);
        $acl->addResource($aclResource, array('search', 'destroy'));

        $acl->allow('Administrators', 'Customers', 'search');
        $acl->deny('Administrators', 'Customers', 'destroy');

        $expected = PhAcl::ALLOW;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
        $this->assertEquals(
            $expected,
            $actual,
            'Object does not contain correct ACL for search'
        );

        $expected = PhAcl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
        $this->assertEquals(
            $expected,
            $actual,
            'Object does not contain correct ACL for destroy'
        );
    }

    /**
     * Tests serializing the ACL
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-11-12
     */
    public function testSerialize()
    {
        $filename    = $this->getFileName('acl', 'log');

        $acl         = new PhAclMem();
        $aclRole     = new PhAclRole('Administrators', 'Super User access');
        $aclResource = new PhAclResource('Customers', 'Customer management');

        $acl->addRole($aclRole);
        $acl->addResource($aclResource, array('search', 'destroy'));

        $acl->allow('Administrators', 'Customers', 'search');
        $acl->deny('Administrators', 'Customers', 'destroy');

        $contents =serialize($acl);
        file_put_contents(PATH_CACHE . $filename, $contents);

        $acl = null;

        $contents = file_get_contents(PATH_CACHE . $filename);

        $this->cleanFile(PATH_CACHE, $filename);

        $acl = unserialize($contents);

        $this->assertInstanceOf(
            '\Phalcon\Acl\Adapter\Memory',
            $acl,
            'Unserialized object not of correct type'
        );

        $exists = $acl->isRole('Administrators');
        $this->assertTrue(
            $exists,
            'Role does not exist in unserialized object'
        );

        $exists = $acl->isResource('Customers');
        $this->assertTrue(
            $exists,
            'Resource does not exist in unserialized object'
        );

        $expected = PhAcl::ALLOW;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'search');
        $this->assertEquals(
            $expected,
            $actual,
            'Unserialized object does not contain correct ACL for search'
        );

        $expected = PhAcl::DENY;
        $actual   = $acl->isAllowed('Administrators', 'Customers', 'destroy');
        $this->assertEquals(
            $expected,
            $actual,
            'Unserialized object does not contain correct ACL for destroy'
        );
    }

    /**
     * Tests the negation of inherited roles
     *
     * @issue T65
     */
    public function testNegationOfInheritedRoles_T65()
    {
        $acl = new PhAclMem;
        $acl->setDefaultAction(PhAcl::DENY);

        $acl->addRole('Guests');
        $acl->addRole('Members', 'Guests');

        $acl->addResource('Login', array('index'));

        $acl->allow('Guests', 'Login', 'index');
        $acl->deny('Members', 'Login', 'index');

        $actual = (bool) $acl->isAllowed('Members', 'Login', 'index');
        $this->assertFalse($actual, 'Negation of inherited roles not correct');
    }

}
