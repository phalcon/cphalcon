<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalconphp.com>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Server\AbstractMiddleware;

use UnitTester;

class ProcessCest
{
    /**
     * Tests Phalcon\Http\Server\AbstractMiddleware :: process()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function httpServerAbstractMiddlewareProcess(UnitTester $I)
    {
        $I->wantToTest('Http\Server\AbstractMiddleware - process()');

        $I->skipTest('Need implementation');
    }
}
