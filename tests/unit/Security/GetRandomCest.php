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

namespace Phalcon\Test\Unit\Security;

use Phalcon\Security;
use Phalcon\Security\Random;
use UnitTester;

class GetRandomCest
{
    /**
     * Tests Phalcon\Security :: getRandom()
     *
     * @author Ruud Boon
     * @since  2018-11-13
     */
    public function securityGetRandom(UnitTester $I)
    {
        $I->wantToTest('Security - getRandom()');

        $security = new Security();

        $random = $security->getRandom();

        $I->assertInstanceOf(
            Random::class,
            $random
        );
    }
}
