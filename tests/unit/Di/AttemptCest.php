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

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Di\Service;
use Phalcon\Escaper;
use UnitTester;

class AttemptCest
{
    /**
     * Tests Phalcon\Di :: attempt()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function diAttempt(UnitTester $I)
    {
        $I->wantToTest('Di - attempt()');

        $di = new Di();

        $actual = $di->attempt('escaper', Escaper::class);

        $I->assertInstanceOf(Service::class, $actual);

        $actual = $di->attempt('escaper', Escaper::class);

        $I->assertFalse($actual);
    }
}
