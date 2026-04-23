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

namespace Phalcon\Tests\Unit\Encryption\Security\Random;

use Phalcon\Encryption\Security\Exception;
use Phalcon\Encryption\Security\Random;
use Phalcon\Tests\AbstractUnitTestCase;

final class NumberTest extends AbstractUnitTestCase
{
    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityRandomNumber(): void
    {
        $random     = new Random();
        $maxRand    = 1;
        $randNumber = $random->number($maxRand);

        $this->assertGreaterThanOrEqual(0, $randNumber);
        $this->assertLessThanOrEqual($maxRand, $randNumber);


        $maxRand    = 1000000000000000000;
        $randNumber = $random->number($maxRand);

        $this->assertGreaterThanOrEqual(0, $randNumber);
        $this->assertLessThanOrEqual($maxRand, $randNumber);


        //Buy lottery ticket if this fails (or fix the bug)
        $this->assertNotEquals(
            $randNumber,
            $random->number($maxRand)
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityRandomNumberNegative(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Input number must be a positive integer');

        $random = new Random();
        $random->number(-1);
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function testEncryptionSecurityRandomNumberZero(): void
    {
        $this->expectException(Exception::class);
        $this->expectExceptionMessage('Input number must be a positive integer');

        $random = new Random();
        $random->number(0);
    }
}
