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

use Phalcon\Encryption\Security\Uuid\UuidInterface;
use Phalcon\Encryption\Security\Uuid\Version3;
use Phalcon\Tests\AbstractUnitTestCase;

final class Version3Test extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion3Deterministic(): void
    {
        $uuid1 = new Version3(UuidInterface::NAMESPACE_DNS, 'phalcon.io');
        $uuid2 = new Version3(UuidInterface::NAMESPACE_DNS, 'phalcon.io');

        $this->assertSame((string) $uuid1, (string) $uuid2);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion3DifferentNames(): void
    {
        $uuid1 = new Version3(UuidInterface::NAMESPACE_DNS, 'phalcon.io');
        $uuid2 = new Version3(UuidInterface::NAMESPACE_DNS, 'phalcon.org');

        $this->assertNotSame((string) $uuid1, (string) $uuid2);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion3DifferentNamespaces(): void
    {
        $uuid1 = new Version3(UuidInterface::NAMESPACE_DNS, 'phalcon.io');
        $uuid2 = new Version3(UuidInterface::NAMESPACE_URL, 'phalcon.io');

        $this->assertNotSame((string) $uuid1, (string) $uuid2);
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion3Format(): void
    {
        $uuid = new Version3(UuidInterface::NAMESPACE_DNS, 'phalcon.io');

        $this->assertMatchesRegularExpression(
            '/^[a-f0-9]{8}-[a-f0-9]{4}-3[a-f0-9]{3}-[89ab][a-f0-9]{3}-[a-f0-9]{12}$/',
            (string) $uuid
        );
    }
}
