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

namespace Phalcon\Test\Unit\Di;

use Phalcon\Di;
use Phalcon\Escaper;
use UnitTester;

class GetServicesCest
{
    /**
     * Tests Phalcon\Di :: getServices()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function diGetServices(UnitTester $I)
    {
        $I->wantToTest('Di - getServices()');

        $di = new Di();

        $I->assertEmpty($di->getServices());

        $di->set('escaper', Escaper::class);

        $I->assertCount(1, $di->getServices());

        $di->remove('escaper');

        $I->assertCount(0, $di->getServices());
    }
}
