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

namespace Phalcon\Test\Unit\Http\Message\Stream;

use UnitTester;

class SetStreamCest
{
    /**
     * Unit Tests Phalcon\Http\Message\Stream :: setStream()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-25
     */
    public function httpMessageStreamSetStream(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - setStream()');

        $I->skipTest('Need implementation');
    }
}
