<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Acl;

use Phalcon\Acl\Resource;
use UnitTester;

class ResourceCest
{
    /**
     * Tests the creation of an Acl Resource (name)
     *
     * @author Nikolaos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-03
     */
    public function testAclResourceName(UnitTester $I)
    {
        $aclResource = new Resource('Schedules');
        $expected    = 'Schedules';
        $actual      = $aclResource->getName();
        $I->assertEquals($expected, $actual);

        $actual = $aclResource->getDescription();
        $I->assertEmpty($actual);
    }

    /**
     * Tests the creation of an Acl Resource (name / description)
     *
     * @author Nikos Dimopoulos <nikos@phalconphp.com>
     * @since  2014-10-03
     */
    public function testAclResourceNameDescription(UnitTester $I)
    {
        $aclResource = new Resource('Schedules', 'Schedules resource');
        $expected    = 'Schedules';
        $actual      = $aclResource->getName();
        $I->assertEquals($expected, $actual);

        $expected = 'Schedules resource';
        $actual   = $aclResource->getDescription();
        $I->assertEquals($expected, $actual);
    }
}
