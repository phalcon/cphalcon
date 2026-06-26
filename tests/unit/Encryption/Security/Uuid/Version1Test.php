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

use DateTimeImmutable;
use Phalcon\Encryption\Security\Uuid\TimeBasedUuidInterface;
use Phalcon\Encryption\Security\Uuid\Version1;
use Phalcon\Tests\AbstractUnitTestCase;

final class Version1Test extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion1CustomDateTime(): void
    {
        $dt   = new DateTimeImmutable('2024-01-15 12:00:00');
        $uuid = new Version1($dt);

        $result = $uuid->getDateTime();

        $this->assertSame($dt->getTimestamp(), $result->getTimestamp());
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion1Format(): void
    {
        $uuid = new Version1();

        $this->assertMatchesRegularExpression(
            '/^[a-f0-9]{8}-[a-f0-9]{4}-1[a-f0-9]{3}-[89ab][a-f0-9]{3}-[a-f0-9]{12}$/',
            (string) $uuid
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion1GetDateTime(): void
    {
        $before = new DateTimeImmutable();
        $uuid   = new Version1();
        $after  = new DateTimeImmutable();

        $dt = $uuid->getDateTime();

        $this->assertInstanceOf(DateTimeImmutable::class, $dt);
        $this->assertGreaterThanOrEqual($before->getTimestamp(), $dt->getTimestamp());
        $this->assertLessThanOrEqual($after->getTimestamp(), $dt->getTimestamp());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion1GetNode(): void
    {
        $uuid = new Version1();

        $this->assertMatchesRegularExpression('/^[a-f0-9]{12}$/', $uuid->getNode());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion1ImplementsTimeBasedInterface(): void
    {
        $uuid = new Version1();

        $this->assertInstanceOf(TimeBasedUuidInterface::class, $uuid);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion1Unique(): void
    {
        $uuid1 = new Version1();
        $uuid2 = new Version1();

        $this->assertNotSame((string) $uuid1, (string) $uuid2);
    }
}
