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

namespace Phalcon\Test\Unit\Http\Message\StreamFactory;

use UnitTester;

/**
 * Class CreateStreamCest
 */
class CreateStreamCest
{
    /**
     * Tests Phalcon\Http\Message\StreamFactory :: createStream()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-09
     */
    public function httpMessageStreamFactoryCreateStream(UnitTester $I)
    {
        $I->wantToTest('Http\Message\StreamFactory - createStream()');
        $I->skipTest('Need implementation');
    }
}
