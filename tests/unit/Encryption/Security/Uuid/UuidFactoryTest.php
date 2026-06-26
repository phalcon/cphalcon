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

use Phalcon\Encryption\Security\Uuid;
use Phalcon\Encryption\Security\Uuid\UuidInterface;
use Phalcon\Encryption\Security\Uuid\Version1;
use Phalcon\Encryption\Security\Uuid\Version3;
use Phalcon\Encryption\Security\Uuid\Version4;
use Phalcon\Encryption\Security\Uuid\Version5;
use Phalcon\Encryption\Security\Uuid\Version6;
use Phalcon\Encryption\Security\Uuid\Version7;
use Phalcon\Tests\AbstractUnitTestCase;

final class UuidFactoryTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidFactoryNamespaceConstants(): void
    {
        $this->assertSame(
            '6ba7b810-9dad-11d1-80b4-00c04fd430c8',
            UuidInterface::NAMESPACE_DNS
        );

        $this->assertSame(
            '6ba7b811-9dad-11d1-80b4-00c04fd430c8',
            UuidInterface::NAMESPACE_URL
        );

        $this->assertSame(
            '6ba7b812-9dad-11d1-80b4-00c04fd430c8',
            UuidInterface::NAMESPACE_OID
        );

        $this->assertSame(
            '6ba7b814-9dad-11d1-80b4-00c04fd430c8',
            UuidInterface::NAMESPACE_X500
        );
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidFactoryV1(): void
    {
        $uuid   = new Uuid();
        $result = $uuid->v1();

        $this->assertInstanceOf(Version1::class, $result);
        $this->assertMatchesRegularExpression(
            '/^[a-f0-9]{8}-[a-f0-9]{4}-1[a-f0-9]{3}-[89ab][a-f0-9]{3}-[a-f0-9]{12}$/',
            (string) $result
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidFactoryV3(): void
    {
        $uuid   = new Uuid();
        $result = $uuid->v3(UuidInterface::NAMESPACE_DNS, 'phalcon.io');

        $this->assertInstanceOf(Version3::class, $result);
        $this->assertMatchesRegularExpression(
            '/^[a-f0-9]{8}-[a-f0-9]{4}-3[a-f0-9]{3}-[89ab][a-f0-9]{3}-[a-f0-9]{12}$/',
            (string) $result
        );

        $this->assertSame(
            (string) $result,
            (string) $uuid->v3(UuidInterface::NAMESPACE_DNS, 'phalcon.io')
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidFactoryV4(): void
    {
        $uuid   = new Uuid();
        $result = $uuid->v4();

        $this->assertInstanceOf(Version4::class, $result);
        $this->assertMatchesRegularExpression(
            '/^[a-f0-9]{8}-[a-f0-9]{4}-4[a-f0-9]{3}-[89ab][a-f0-9]{3}-[a-f0-9]{12}$/',
            (string) $result
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidFactoryV5(): void
    {
        $uuid   = new Uuid();
        $result = $uuid->v5(UuidInterface::NAMESPACE_DNS, 'phalcon.io');

        $this->assertInstanceOf(Version5::class, $result);
        $this->assertMatchesRegularExpression(
            '/^[a-f0-9]{8}-[a-f0-9]{4}-5[a-f0-9]{3}-[89ab][a-f0-9]{3}-[a-f0-9]{12}$/',
            (string) $result
        );

        $this->assertSame(
            (string) $result,
            (string) $uuid->v5(UuidInterface::NAMESPACE_DNS, 'phalcon.io')
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidFactoryV6(): void
    {
        $uuid   = new Uuid();
        $result = $uuid->v6();

        $this->assertInstanceOf(Version6::class, $result);
        $this->assertMatchesRegularExpression(
            '/^[a-f0-9]{8}-[a-f0-9]{4}-6[a-f0-9]{3}-[89ab][a-f0-9]{3}-[a-f0-9]{12}$/',
            (string) $result
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidFactoryV7(): void
    {
        $uuid   = new Uuid();
        $result = $uuid->v7();

        $this->assertInstanceOf(Version7::class, $result);
        $this->assertMatchesRegularExpression(
            '/^[a-f0-9]{8}-[a-f0-9]{4}-7[a-f0-9]{3}-[89ab][a-f0-9]{3}-[a-f0-9]{12}$/',
            (string) $result
        );
    }
}
