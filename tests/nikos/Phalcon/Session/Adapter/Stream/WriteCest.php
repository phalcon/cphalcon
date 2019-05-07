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

namespace Phalcon\Test\Unit\Session\Adapter\Stream;

use UnitTester;

class WriteCest
{
    /**
     * Tests Phalcon\Session\Adapter\Stream :: write()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function sessionAdapterStreamWrite(UnitTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - write()');

        $I->skipTest('Need implementation');
    }
}
