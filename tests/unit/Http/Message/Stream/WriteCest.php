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
 * Class WriteCest
 */
class WriteCest
{
    /**
     * Tests Phalcon\Http\Message\Stream :: write()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-09
     */
    public function httpMessageStreamWrite(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream - write()');
        $I->skipTest('Need implementation');
    }
}
