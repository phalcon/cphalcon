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

namespace Phalcon\Test\Unit\Http\Message\Stream;

use UnitTester;

/**
 * Class SeekCest
 */
class SeekCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: seek()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function httpMessageStreamSeek(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - seek()');
        $I->skipTest('Need implementation');
    }
}
