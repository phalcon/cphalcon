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

namespace Phalcon\Test\Unit\Http\Message\Stream\Input;

use Phalcon\Http\Message\Stream\Input;
use UnitTester;

class IsWritableCest
{
    /**
     * Tests Phalcon\Http\Message\Stream\Input :: isWritable()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-19
     */
    public function httpMessageStreamInputIsWritable(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream\Input - isWritable()');

        $stream = new Input();

        $I->assertFalse(
            $stream->isWritable()
        );
    }
}
