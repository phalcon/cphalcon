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

class DestroyCest
{
    /**
     * Tests Phalcon\Session\Adapter\Stream :: destroy()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function sessionAdapterStreamDestroy(UnitTester $I)
    {
        $I->wantToTest('Session\Adapter\Stream - destroy()');

        $I->skipTest('Need implementation');
    }
}
