<?php
/**
 * ACLResourceTest.php
 * \Phalcon\Text\ACLResourceTest
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

use \PhalconTest\Acl\Resource as PhAclTResource;

use \Phalcon\Tests\unit\Phalcon\_Helper\TestsBase as TBase;

class ACLResourceTest extends TBase
{
    /**
     * Tests the creation of an Acl Resource (name)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-03
     */
    public function testAclResourceName()
    {
        $this->specify(
            "getting the name from the ACL resource does not return the correct result",
            function () {

                $aclResource = new PhAclTResource('Schedules');
                $expected    = 'Schedules';
                $actual      = $aclResource->getName();
                expect($actual)->equals($expected);

                $actual      = $aclResource->getDescription();
                expect($actual)->isEmpty();
            }
        );
    }

    /**
     * Tests the creation of an Acl Resource (name / description)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-03
     */
    public function testAclResourceNameDescription()
    {
        $this->specify(
            "getting the name from the ACL resource does not return the correct result",
            function () {

                $aclResource = new PhAclTResource('Schedules', 'Schedules resource');
                $expected    = 'Schedules';
                $actual      = $aclResource->getName();
                expect($actual)->equals($expected);

                $expected    = 'Schedules resource';
                $actual      = $aclResource->getDescription();
                expect($actual)->equals($expected);
            }
        );
    }
}
