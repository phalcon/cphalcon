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

namespace Phalcon\Test\Unit\Annotations\Adapter\Memory;

use UnitTester;

class GetCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Memory :: get()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAdapterMemoryGet(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Memory - get()');

        $I->skipTest('Need implementation');
    }
}
