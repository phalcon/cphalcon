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
use Phalcon\Tests\AbstractUnitTestCase;

final class DropComponentAccessTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryDropComponentAccess(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
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

        $actual = $acl->isAllowed('Guests', 'Post', 'update');
        $this->assertTrue($actual);

        $actual = $acl->isAllowed('Guests', 'News', 'index');
        $this->assertTrue($actual);

        $acl->dropComponentAccess('Post', 'index');
        $actual = $acl->isAllowed('Guests', 'Post', 'index');
        $this->assertTrue($actual);

        $acl->dropComponentAccess(
            'News',
            [
                'index',
                'create',
            ]
        );
        $actual = $acl->isAllowed('Guests', 'News', 'index');
        $this->assertTrue($actual);

        $actual = $acl->isAllowed('Guests', 'News', 'create');
        $this->assertTrue($actual);
    }
}
