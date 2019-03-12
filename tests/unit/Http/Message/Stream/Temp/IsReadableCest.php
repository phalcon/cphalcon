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

use Phalcon\Http\Message\Stream\Temp;
use UnitTester;

/**
 * Class IsReadableCest
 */
class IsReadableCest
{
    /**
     * Tests Phalcon\Http\Message\Stream\Temp :: isReadable()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-19
     */
    public function httpMessageStreamTempIsReadable(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream\Temp - isReadable()');

        $stream = new Temp();
        $I->assertTrue($stream->isReadable());
    }
}
