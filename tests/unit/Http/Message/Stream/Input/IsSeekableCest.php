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

namespace Phalcon\Tests\Unit\Http\Message\Stream\Input;

use Phalcon\Http\Message\Stream\Input;
use UnitTester;

class IsSeekableCest
{
    /**
     * Tests Phalcon\Http\Message\Stream\Input :: isSeekable()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-19
     */
    public function httpMessageStreamInputIsSeekable(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream\Input - isSeekable()');

        $stream = new Input();

        $I->assertTrue(
            $stream->isSeekable()
        );
    }
}
