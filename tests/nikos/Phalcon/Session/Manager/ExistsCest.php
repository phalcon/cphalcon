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

namespace Phalcon\Test\Unit\Session\Manager;

use UnitTester;

class ExistsCest
{
    /**
     * Tests Phalcon\Session\Manager :: exists()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function sessionManagerExists(UnitTester $I)
    {
        $I->wantToTest('Session\Manager - exists()');

        $I->skipTest('Need implementation');
    }
}
