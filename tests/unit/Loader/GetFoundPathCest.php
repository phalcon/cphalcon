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

namespace Phalcon\Tests\Unit\Loader;

use UnitTester;

class GetFoundPathCest
{
    /**
     * Tests Phalcon\Loader :: getFoundPath()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function loaderGetFoundPath(UnitTester $I)
    {
        $I->wantToTest('Loader - getFoundPath()');

        $I->skipTest('Need implementation');
    }
}
