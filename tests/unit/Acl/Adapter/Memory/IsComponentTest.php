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
use Phalcon\Tests\AbstractUnitTestCase;

final class IsComponentTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryIsComponent(): void
    {
        $acl          = new Memory();
        $aclComponent = new Component('Customers', 'Customer management');

        $acl->addComponent($aclComponent, 'search');

        $actual = $acl->isComponent('Customers');
        $this->assertTrue($actual);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function testAclAdapterMemoryIsComponentUnknown(): void
    {
        $acl          = new Memory();
        $aclComponent = new Component('Customers', 'Customer management');

        $acl->addComponent($aclComponent, 'search');

        $actual = $acl->isComponent('unknown');
        $this->assertFalse($actual);
    }
}
