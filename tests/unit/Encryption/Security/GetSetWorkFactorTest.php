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

final class GetSetWorkFactorTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityGetSetWorkFactor(): void
    {
        $security = new Security();

        $expected = 10;
        $actual   = $security->getWorkFactor();
        $this->assertSame($expected, $actual);

        $expected = 31;
        $security->setWorkFactor($expected);

        $actual = $security->getWorkFactor();
        $this->assertSame($expected, $actual);
    }
}
