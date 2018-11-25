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

use Phalcon\Acl;
use UnitTester;

class ConstantsCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: constants
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclConstants(UnitTester $I)
    {
        $I->assertEquals(1, Acl::ALLOW);
        $I->assertEquals(0, Acl::DENY);
    }
}
