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

namespace Phalcon\Tests\Unit\Support\Debug;

use Phalcon\Html\Escaper;
use Phalcon\Html\TagFactory;
use Phalcon\Support\Debug;
use Phalcon\Support\Debug\Exception;
use UnitTester;

/**
 * Class HaltCest
 *
 * @package Phalcon\Tests\Unit\Support\Debug
 */
class HaltCest
{
    /**
     * Tests Phalcon\Debug :: halt()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function debugHalt(UnitTester $I)
    {
        $I->wantToTest('Debug - halt()');

        $I->expectThrowable(
            new Exception('Halted request'),
            function () {
                $debug = new Debug(new TagFactory(new Escaper()));
                $debug->halt();
            }
        );
    }
}
