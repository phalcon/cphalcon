<?php
/**
 * ACLRoleTest.php
 * \Phalcon\Text\ACLRoleTest
 *
 * Tests the Phalcon\Acl component
 *
 * Phalcon Framework
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

namespace Phalcon\Tests\unit\Phalcon\Acl;

use \PhalconTest\Acl\Role as PhTAclRole;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class ACLRoleTest extends TBase
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

                $aclRole  = new PhTAclRole('Administrators');
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

                $aclRole  = new PhTAclRole('Administrators', 'Super-User role');
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
