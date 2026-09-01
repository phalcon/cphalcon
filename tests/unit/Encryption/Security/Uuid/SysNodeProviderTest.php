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

namespace Phalcon\Tests\Unit\Encryption\Security\Uuid;

use Phalcon\Encryption\Security\Uuid\NodeProviderInterface;
use Phalcon\Encryption\Security\Uuid\SysNodeProvider;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;

final class SysNodeProviderTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testSysNodeProviderImplementsInterface(): void
    {
        $provider = new SysNodeProvider();

        $this->assertInstanceOf(NodeProviderInterface::class, $provider);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testSysNodeProviderReturnsHex(): void
    {
        $provider = new SysNodeProvider();

        $this->assertMatchesRegularExpression('/^[a-f0-9]{12}$/', $provider->getNode());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testSysNodeProviderReturnsSameValueOnSameInstance(): void
    {
        $provider = new SysNodeProvider();

        $this->assertSame($provider->getNode(), $provider->getNode());
    }
}
