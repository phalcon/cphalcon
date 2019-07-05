<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Acl\Adapter\Memory;

use Phalcon\Acl\Adapter\Memory;
use Phalcon\Acl\Enum;
use UnitTester;

class DenyCest
{
    /**
     * Tests Phalcon\Acl\Adapter\Memory :: deny()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function aclAdapterMemoryDeny(UnitTester $I)
    {
        $I->wantToTest('Acl\Adapter\Memory - deny()');

        $acl = new Memory();

        $acl->setDefaultAction(
            Enum::ALLOW
        );

        $acl->addRole('Guests');
        $acl->addRole('Member');

        $acl->addComponent(
            'Post',
            ['update']
        );

        $acl->deny('Member', 'Post', 'update');

        $I->assertTrue(
            $acl->isAllowed('Guest', 'Post', 'update')
        );

        $I->assertFalse(
            $acl->isAllowed('Member', 'Post', 'update')
        );
    }
}
