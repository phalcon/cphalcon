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

namespace Phalcon\Test\Unit\Http\Message\Stream\Memory;

use Phalcon\Http\Message\Stream\Memory;
use UnitTester;

class IsReadableCest
{
    /**
     * Tests Phalcon\Http\Message\Stream\Memory :: isReadable()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-02-19
     */
    public function httpMessageStreamMemoryIsReadable(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream\Memory - isReadable()');

        $stream = new Memory();

        $I->assertTrue(
            $stream->isReadable()
        );
    }
}
