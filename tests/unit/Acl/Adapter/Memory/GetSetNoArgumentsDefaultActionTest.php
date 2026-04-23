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

final class GetSetNoArgumentsDefaultActionTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryGetSetNoArgumentsDefaultAction(): void
    {
        $acl = new Memory();
        $acl->setNoArgumentsDefaultAction(Enum::ALLOW);

        $expected = Enum::ALLOW;
        $actual   = $acl->getNoArgumentsDefaultAction();
        $this->assertSame($expected, $actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryGetSetNoArgumentsDefaultActionDefault(): void
    {
        $acl = new Memory();

        $expected = Enum::DENY;
        $actual   = $acl->getNoArgumentsDefaultAction();
        $this->assertSame($expected, $actual);
    }
}
