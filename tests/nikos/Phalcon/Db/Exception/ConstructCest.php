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

namespace Phalcon\Test\Unit\Db\Exception;

use UnitTester;

class ConstructCest
{
    /**
     * Tests Phalcon\Db\Exception :: __construct()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function dbExceptionConstruct(UnitTester $I)
    {
        $I->wantToTest('Db\Exception - __construct()');

        $I->skipTest('Need implementation');
    }
}
