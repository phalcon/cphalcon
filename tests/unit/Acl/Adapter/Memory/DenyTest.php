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

final class DenyTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryDeny(): void
    {
        $acl = new Memory();
        $acl->setDefaultAction(Enum::ALLOW);
        $acl->addRole('Guests');
        $acl->addRole('Member');
        $acl->addComponent('Post', ['update']);

        $acl->deny('Member', 'Post', 'update');

        $actual = $acl->isAllowed('Guest', 'Post', 'update');
        $this->assertTrue($actual);

        $actual = $acl->isAllowed('Member', 'Post', 'update');
        $this->assertFalse($actual);
    }
}
