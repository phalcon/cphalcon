<?php
/**
 * UnitTest.php
 * \Phalcon\Acl\Adapter\Memory\UnitTest
 *
 * Tests the \Phalcon\Acl\Adapter\Memory component
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

use \Phalcon\Acl as PhAcl;
use \Phalcon\Acl\Role as PhAclRole;
use \Phalcon\Acl\Resource as PhAclResource;
use \Phalcon\Acl\Adapter\Memory as PhAclMem;

class Acl_Adapter_Memory_UnitTest extends Phalcon_Test_UnitTestCase
{
    /**
     * Tests the setDefaultAction
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
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
     * @since  2012-09-30
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
     * @since  2012-09-30
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
     * @since  2012-09-30
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
     * @since  2012-09-30
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

    public function testAcl()
    {

        $this->markTestSkipped('Complete ACL Tests');
        $acl = new PhAclMem();

        $acl->setDefaultAction(PhAcl::DENY);

        $roleAdmins = new PhAclRole('Administrators', 'Super-User role');
        $roleGuests = new PhAclRole('Guests');


        $this->assertTrue($acl->isRole('Guests'));
        $this->assertFalse($acl->isRole('ReadOnly'));

        $customersResource = new PhResource('Customers', 'Customers management');
        $this->assertEquals($customersResource->getName(), 'Customers');
        $this->assertEquals($customersResource->getDescription(), 'Customers management');

        $this->assertTrue($acl->addResource($customersResource, 'search'));
        $this->assertTrue($acl->addResource($customersResource, array('create', 'update')));

        $this->assertTrue($acl->isResource('Customers'));
        $this->assertFalse($acl->isResource('Products'));

        $acl->allow('Guests', 'Customers', 'search');
        $acl->allow('Guests', 'Customers', 'create');
        $acl->deny('Guests', 'Customers', 'update');

        $this->assertEquals($acl->isAllowed('Guests', 'Customers', 'edit'), PhAcl::DENY);
        $this->assertEquals($acl->isAllowed('Guests', 'Customers', 'search'), PhAcl::ALLOW);
        $this->assertEquals($acl->isAllowed('Guests', 'Customers', 'create'), PhAcl::ALLOW);

        $this->assertTrue($acl->addRole($roleAdmins, 'Guests'));
        $this->assertFalse($acl->addRole($roleAdmins, 'Guests'));

        $this->assertEquals($acl->isAllowed('Administrators', 'Customers', 'edit'), PhAcl::DENY);
        $this->assertEquals($acl->isAllowed('Administrators', 'Customers', 'search'), PhAcl::ALLOW);
        $this->assertEquals($acl->isAllowed('Administrators', 'Customers', 'create'), PhAcl::ALLOW);

        //Serialize ACL list
        file_put_contents('unit-tests/acl/acl.data', serialize($acl));

        $aclObject = unserialize(file_get_contents('unit-tests/acl/acl.data'));
        $this->assertEquals(get_class($aclObject), 'Phalcon\Acl\Adapter\Memory');

        $this->assertTrue($aclObject->isRole('Guests'));
        $this->assertFalse($aclObject->isRole('ReadOnly'));

        $this->assertTrue($aclObject->isResource('Customers'));
        $this->assertFalse($aclObject->isResource('Products'));

        $this->assertEquals($aclObject->isAllowed('Administrators', 'Customers', 'edit'), PhAcl::DENY);
        $this->assertEquals($aclObject->isAllowed('Administrators', 'Customers', 'search'), PhAcl::ALLOW);
        $this->assertEquals($aclObject->isAllowed('Administrators', 'Customers', 'create'), PhAcl::ALLOW);
    }

    public function testNegationOfInheritedRoles_T65()
    {
        $acl = new PhAclMem;
        $acl->setDefaultAction(PhAcl::DENY);

        $acl->addRole('Guests');
        $acl->addRole('Members', 'Guests');

        $acl->addResource('Login', array('index'));

        $acl->allow('Guests', 'Login', 'index');
        $acl->deny('Members', 'Login', 'index');

        $this->assertFalse((bool) $acl->isAllowed('Members', 'Login', 'index'));
    }

}
