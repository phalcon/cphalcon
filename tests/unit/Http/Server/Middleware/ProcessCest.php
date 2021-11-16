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

namespace Phalcon\Tests\Unit\Http\Server\Middleware;

use UnitTester;

class ProcessCest
{
    /**
     * Tests Phalcon\Http\Server\Middleware :: process()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-10
     */
    public function httpServerMiddlewareProcess(UnitTester $I)
    {
        $I->wantToTest('Http\Server\Middleware - process()');
        $I->skipTest('Need implementation');
    }
}
