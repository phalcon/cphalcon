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

namespace Phalcon\Test\Unit\Cache\Frontend\Json;

use UnitTester;

class StartCest
{
    /**
     * Tests Phalcon\Cache\Frontend\Json :: start()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function cacheFrontendJsonStart(UnitTester $I)
    {
        $I->wantToTest('Cache\Frontend\Json - start()');

        $I->skipTest('Need implementation');
    }
}
