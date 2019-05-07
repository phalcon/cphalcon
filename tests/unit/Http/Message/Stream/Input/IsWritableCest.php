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

namespace Phalcon\Test\Unit\Http\Message\Stream\Input;

use Phalcon\Http\Message\Stream\Input;
use UnitTester;

/**
 * Class IsWritableCest
 */
class IsWritableCest
{
    /**
     * Tests Phalcon\Http\Message\Stream\Input :: isWritable()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-19
     */
    public function httpMessageStreamInputIsWritable(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream\Input - isWritable()');

        $stream = new Input();
        $I->assertFalse($stream->isWritable());
    }
}
