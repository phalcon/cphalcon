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
use Phalcon\Encryption\Security\Random;
use UnitTester;

class GetRandomCest
{
    /**
     * Tests Phalcon\Security :: getRandom()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function securityGetRandom(UnitTester $I)
    {
        $I->wantToTest('Security - getRandom()');

        $security = new Security();
        $random   = $security->getRandom();

        $I->assertInstanceOf(Random::class, $random);
    }
}
