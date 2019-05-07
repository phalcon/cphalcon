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

namespace Phalcon\Test\Unit\Db\Profiler;

use UnitTester;

class StartProfileCest
{
    /**
     * Tests Phalcon\Db\Profiler :: startProfile()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-07
     */
    public function dbProfilerStartProfile(UnitTester $I)
    {
        $I->wantToTest('Db\Profiler - startProfile()');

        $I->skipTest('Need implementation');
    }
}
