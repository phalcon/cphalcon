<?php
/**
 * UnitTest.php
 * \Phalcon\Acl\Role\UnitTest
 *
 * Tests the \Phalcon\Acl\Role component
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

use \Phalcon\Acl\Role as AclRole;

class Acl_Role_UnitTest extends Phalcon_Test_UnitTestCase
{
    /**
     * Tests the creation of an Acl Role (name)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testAclRoleName()
    {
        $aclRole = new AclRole('Administrators');

        $expected = 'Administrators';
        $actual   = $aclRole->getName();
        $this->assertEquals(
            $expected,
            $actual,
            'Acl\Role does not return correct name'
        );

        $expected = '';
        $actual   = $aclRole->getDescription();
        $this->assertEquals(
            $expected,
            $actual,
            'Acl\Role does not return correct description'
        );

    }

    /**
     * Tests the creation of an Acl Role (name / description)
     *
     * @author Nikos Dimopoulos <nikos@niden.net>
     * @since  2012-09-30
     */
    public function testAclRoleNameDescription()
    {
        $aclRole = new AclRole('Administrators', 'Super-User role');

        $expected = 'Administrators';
        $actual   = $aclRole->getName();
        $this->assertEquals(
            $expected,
            $actual,
            'Acl\Role does not return correct name'
        );

        $expected = 'Super-User role';
        $actual   = $aclRole->getDescription();
        $this->assertEquals(
            $expected,
            $actual,
            'Acl\Role does not return correct description'
        );

    }
}
