<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Http\Message\Stream;

use UnitTester;

class SetStreamCest
{
    /**
     * Unit Tests Phalcon\Http\Message\Stream :: setStream()
     *
     * @since  2019-05-25
     */
    public function httpMessageStreamSetStream(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - setStream()');

        $I->skipTest('Need implementation');
    }
}
