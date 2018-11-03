<?php

namespace Phalcon\Test\Unit\Acl;

use Phalcon\Acl\Role;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Acl\RoleTest
 * Tests for \Phalcon\Acl\Role component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      https://phalconphp.com
 * @author    Andres Gutierrez <andres@phalconphp.com>
 * @author    Nikolaos Dimopoulos <nikos@phalconphp.com>
 * @package   Phalcon\Test\Unit\Acl
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class RoleTest extends UnitTest
{
    /**
     * Tests the creation of an Acl Role (name)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-03
     */
    public function testAclRoleNameEmptyDescription()
    {
        $this->specify(
            "getting the name from the ACL role does not return the correct result",
            function () {
                $aclRole  = new Role('Administrators');
                $expected = 'Administrators';
                $actual   = $aclRole->getName();
                expect($actual)->equals($expected);

                $actual   = $aclRole->getDescription();
                expect($actual)->isEmpty();
            }
        );
    }
    /**
     * Tests the creation of an Acl Role (name/description)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-03
     */
    public function testAclRoleNameDescription()
    {
        $this->specify(
            "getting the name from the ACL role does not return the correct result",
            function () {
                $aclRole  = new Role('Administrators', 'Super-User role');

                $expected = 'Administrators';
                $actual   = $aclRole->getName();
                expect($actual)->equals($expected);

                $actual   = $aclRole->getDescription();
                $expected = 'Super-User role';
                expect($actual)->equals($expected);
            }
        );
    }
}
