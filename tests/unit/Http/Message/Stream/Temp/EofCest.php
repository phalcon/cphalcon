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

namespace Phalcon\Test\Unit\Http\Message\Stream\Temp;

use UnitTester;

/**
 * Class EofCest
 */
class EofCest
{
    /**
     * Tests Phalcon\Http\Message\Stream\Temp :: eof()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-19
     */
    public function httpMessageStreamTempEof(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream\Temp - eof()');
        $I->skipTest('Need implementation');
    }
}
