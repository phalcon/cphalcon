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

namespace Phalcon\Test\Unit\Session\Adapter\Noop;

use UnitTester;

/**
 * Class CloseCest
 */
class CloseCest
{
    /**
     * Tests Phalcon\Session\Adapter\Noop :: close()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function sessionAdapterNoopClose(UnitTester $I)
    {
        $I->wantToTest('Session\Adapter\Noop - close()');
        $I->skipTest('Need implementation');
    }
}
