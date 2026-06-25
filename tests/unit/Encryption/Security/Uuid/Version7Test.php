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

use Phalcon\Encryption\Security\Uuid\Version7;
use Phalcon\Tests\AbstractUnitTestCase;

final class Version7Test extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion7Format(): void
    {
        $uuid = new Version7();

        $this->assertMatchesRegularExpression(
            '/^[a-f0-9]{8}-[a-f0-9]{4}-7[a-f0-9]{3}-[89ab][a-f0-9]{3}-[a-f0-9]{12}$/',
            (string) $uuid
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion7Sortable(): void
    {
        $uuid1 = new Version7();
        usleep(1000);
        $uuid2 = new Version7();

        $this->assertLessThan((string) $uuid2, (string) $uuid1);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2026-04-29
     */
    public function testEncryptionSecurityUuidVersion7Unique(): void
    {
        $uuid1 = new Version7();
        $uuid2 = new Version7();

        $this->assertNotSame((string) $uuid1, (string) $uuid2);
    }
}
