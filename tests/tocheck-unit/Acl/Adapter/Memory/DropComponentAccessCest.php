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

namespace Phalcon\Test\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Enum;
use UnitTester;

class DropComponentAccessCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: dropComponentAccess()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryDropComponentAccess(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - dropComponentAccess()');

        $acl = new Memory();

        $acl->setDefaultAction(
            Enum::DENY
        );

        $acl->addRole('Guests');
        $acl->addComponent(
            'Post',
            [
                'index',
                'create',
                'delete',
                'update',
            ]
        );
        $acl->addComponent(
            'News',
            [
                'index',
                'create',
                'delete',
                'update',
            ]
        );
        $acl->allow(
            'Guests',
            'Post',
            [
                'index',
                'create',
                'delete',
                'update',
            ]
        );
        $acl->allow(
            'Guests',
            'News',
            [
                'index',
                'create',
                'delete',
                'update',
            ]
        );

        $I->assertTrue(
            $acl->isAllowed('Guests', 'Post', 'update')
        );
        $I->assertTrue(
            $acl->isAllowed('Guests', 'News', 'index')
        );

        $acl->dropComponentAccess('Post', 'index');
        $I->assertTrue(
            $acl->isAllowed('Guests', 'Post', 'index')
        );

        $acl->dropComponentAccess(
            'News',
            [
                'index',
                'create',
            ]
        );
        $I->assertTrue(
            $acl->isAllowed('Guests', 'News', 'index')
        );
        $I->assertTrue(
            $acl->isAllowed('Guests', 'News', 'create')
        );
    }
}
