<?php

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

declare(strict_types=1);

namespace Phalcon\Tests\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Enum;
use UnitTester;

/**
 * Class DenyCest
 *
 * @package Phalcon\Tests\Unit\Acl\Adapter\Memory
 */
class DenyCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: deny()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryDeny(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - deny()');

        $acl = new Memory();
        $acl->setDefaultAction(Enum::ALLOW);
        $acl->addRole('Guests');
        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);

        $acl->deny('Member', 'Post', 'update');

        $I->assertTrue(
            $acl->isAllowed('Guest', 'Post', 'update')
        );

        $I->assertFalse(
            $acl->isAllowed('Member', 'Post', 'update')
        );
    }
}
