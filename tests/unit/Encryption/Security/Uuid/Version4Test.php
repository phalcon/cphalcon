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

use Phalcon\Encryption\Security\Uuid\Version4;
use Phalcon\Tests\AbstractUnitTestCase;

final class Version4Test extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidAbstractUuidConstants(): void
    {
        $this->assertSame(
            '00000000-0000-0000-0000-000000000000',
            Version4::NIL
        );

        $this->assertSame(
            'ffffffff-ffff-ffff-ffff-ffffffffffff',
            Version4::MAX
        );

        $this->assertSame(
            0x01B21DD213814000,
            Version4::TIME_OFFSET_INT
        );
    }
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion4Format(): void
    {
        $uuid = new Version4();

        $this->assertMatchesRegularExpression(
            '/^[a-f0-9]{8}-[a-f0-9]{4}-4[a-f0-9]{3}-[89ab][a-f0-9]{3}-[a-f0-9]{12}$/',
            (string) $uuid
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion4JsonSerialize(): void
    {
        $uuid = new Version4();

        $this->assertSame((string) $uuid, $uuid->jsonSerialize());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion4ToString(): void
    {
        $uuid = new Version4();

        $this->assertIsString((string) $uuid);
        $this->assertSame((string) $uuid, $uuid->__toString());
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion4Unique(): void
    {
        $uuid1 = new Version4();
        $uuid2 = new Version4();

        $this->assertNotSame((string) $uuid1, (string) $uuid2);
    }
}
