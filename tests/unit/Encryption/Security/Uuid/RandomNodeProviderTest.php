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
use Phalcon\Encryption\Security\Uuid\RandomNodeProvider;
use Phalcon\Tests\AbstractUnitTestCase;

final class RandomNodeProviderTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testRandomNodeProviderImplementsInterface(): void
    {
        $provider = new RandomNodeProvider();

        $this->assertInstanceOf(NodeProviderInterface::class, $provider);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testRandomNodeProviderMulticastBitSet(): void
    {
        $provider  = new RandomNodeProvider();
        $node      = $provider->getNode();
        $firstByte = hexdec(substr($node, 0, 2));

        $this->assertSame(1, $firstByte & 0x01);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testRandomNodeProviderReturnsDifferentValues(): void
    {
        $provider = new RandomNodeProvider();

        $this->assertNotSame($provider->getNode(), $provider->getNode());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testRandomNodeProviderReturnsHex(): void
    {
        $provider = new RandomNodeProvider();
        $node     = $provider->getNode();

        $this->assertMatchesRegularExpression('/^[a-f0-9]{12}$/', $node);
    }
}
