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

namespace Phalcon\Tests\Unit\Encryption\Security;

use Phalcon\Encryption\Security;
use Phalcon\Tests\AbstractUnitTestCase;

final class IsLegacyHashTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityIsLegacyHash(): void
    {
        $oldHash  = '$2a$10$JnD9Za73U2dIIjd.Uvn1IuNVQhXNQpHIu13WzlL70q.WhfKT9Yuc2';
        $security = new Security();

        $actual = $security->isLegacyHash($oldHash);
        $this->assertTrue($actual);

        $actual = $security->isLegacyHash('Phalcon');
        $this->assertFalse($actual);
    }
}
