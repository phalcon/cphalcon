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

namespace Phalcon\Tests\Unit\Flash\Direct;

use Phalcon\Flash\Direct;
use Phalcon\Flash\FlashInterface;
use UnitTester;

/**
 * Class ConstructCest
 *
 * @package Phalcon\Tests\Unit\Flash\Direct
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Flash\Direct :: __construct()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function flashDirectConstruct(UnitTester $I)
    {
        $I->wantToTest('Flash\Direct - __construct()');

        $flash = new Direct();
        $I->assertInstanceOf(FlashInterface::class, $flash);
    }
}
