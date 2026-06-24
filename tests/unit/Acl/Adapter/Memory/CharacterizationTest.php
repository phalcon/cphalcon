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

final class CharacterizationTest extends AbstractUnitTestCase
{
    public function testSpecificRuleOverridesWildcardForSingleRole(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('user');
        $acl->addComponent('posts', ['browse', 'edit']);
        $acl->allow('user', 'posts', '*');
        $acl->deny('user', 'posts', 'edit');

        $this->assertTrue($acl->isAllowed('user', 'posts', 'browse'));
        $this->assertFalse($acl->isAllowed('user', 'posts', 'edit'));
    }

    public function testInheritedAllowReachesChild(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::DENY);
        $acl->addRole('admin');
        $acl->addRole('editor');
        $acl->addInherit('admin', 'editor');
        $acl->addComponent('posts', ['edit']);
        $acl->allow('editor', 'posts', 'edit');

        $this->assertTrue($acl->isAllowed('admin', 'posts', 'edit'));
    }

    public function testClosureDenyOverridesNoArgumentsDefaultAllow(): void
    {
        $acl = new Memory();
        $acl->setNoArgumentsDefaultAction(Enum::ALLOW);
        $acl->addRole('user');
        $acl->addComponent('posts', ['edit']);
        $acl->allow('user', 'posts', 'edit', fn () => false);

        $this->assertFalse($acl->isAllowed('user', 'posts', 'edit'));
    }
}
