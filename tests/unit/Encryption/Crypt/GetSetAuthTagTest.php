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

namespace Phalcon\Tests\Unit\Encryption\Crypt;

use Phalcon\Encryption\Crypt;
use Phalcon\Tests\AbstractUnitTestCase;

use function uniqid;

final class GetSetAuthTagTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2021-10-18
     */
    public function testEncryptionCryptGetSetAuthTag(): void
    {
        $crypt = new Crypt();

        $data = uniqid('t-');
        $crypt->setAuthTag($data);

        $expected = $data;
        $actual   = $crypt->getAuthTag();
        $this->assertSame($expected, $actual);
    }
}
