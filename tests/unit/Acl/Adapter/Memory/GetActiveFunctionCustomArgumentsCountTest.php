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
use Phalcon\Acl\Component;
use Phalcon\Acl\Role;
use Phalcon\Tests\AbstractUnitTestCase;

final class GetActiveFunctionCustomArgumentsCountTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryGetActiveFunctionCustomArgumentsCount(): void
    {
        $acl = new Memory();

        $acl->addRole(new Role('member'));
        $acl->addComponent(new Component('group'), 'add');
        $acl->allow(
            'member',
            'group',
            'add',
            function ($accountType, $active) {
                if ('premium' === $accountType && true === $active) {
                    return true;
                }

                return false;
            }
        );

        $actual = $acl->isAllowed(
            'member',
            'group',
            'add',
            [
                'accountType' => 'premium',
                'active'      => true,
            ]
        );

        $this->assertTrue($actual);

        $expected = 2;
        $actual   = $acl->getActiveFunctionCustomArgumentsCount();
        $this->assertSame($expected, $actual);
    }
}
