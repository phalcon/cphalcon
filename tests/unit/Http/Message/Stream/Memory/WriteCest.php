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

namespace Phalcon\Test\Unit\Http\Message\Stream\Memory;

use UnitTester;

class WriteCest
{
    /**
     * Unit Tests Phalcon\Http\Message\Stream\Memory :: write()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-25
     */
    public function httpMessageStreamMemoryWrite(UnitTester $I)
    {
        $I->wantToTest('Http\Message\Stream\Memory - write()');

        $I->skipTest('Need implementation');
    }
}
