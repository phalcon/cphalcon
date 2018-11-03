<?php

namespace Phalcon\Test\Unit\Acl;

use Phalcon\Acl\Resource;
use Phalcon\Test\Module\UnitTest;

/**
 * \Phalcon\Test\Unit\Acl\ResourceTest
 * Tests for \Phalcon\Acl\Resource component
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
class ResourceTest extends UnitTest
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
                $aclResource = new Resource('Schedules');
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
                $aclResource = new Resource('Schedules', 'Schedules resource');
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
