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
use Phalcon\Encryption\Security\Uuid\Version6;
use Phalcon\Tests\AbstractUnitTestCase;

final class Version6Test extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion6Format(): void
    {
        $uuid = new Version6();

        $this->assertMatchesRegularExpression(
            '/^[a-f0-9]{8}-[a-f0-9]{4}-6[a-f0-9]{3}-[89ab][a-f0-9]{3}-[a-f0-9]{12}$/',
            (string) $uuid
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion6GetDateTime(): void
    {
        $before = new DateTimeImmutable();
        $uuid   = new Version6();
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
    public function testEncryptionSecurityUuidVersion6GetNode(): void
    {
        $uuid = new Version6();

        $this->assertMatchesRegularExpression('/^[a-f0-9]{12}$/', $uuid->getNode());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion6ImplementsTimeBasedInterface(): void
    {
        $uuid = new Version6();

        $this->assertInstanceOf(TimeBasedUuidInterface::class, $uuid);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion6Sortable(): void
    {
        $uuid1 = new Version6();
        usleep(1000);
        $uuid2 = new Version6();

        $this->assertLessThan((string) $uuid2, (string) $uuid1);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion6Unique(): void
    {
        $uuid1 = new Version6();
        $uuid2 = new Version6();

        $this->assertNotSame((string) $uuid1, (string) $uuid2);
    }
}
