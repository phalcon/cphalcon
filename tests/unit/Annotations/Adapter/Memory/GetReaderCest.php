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

class GetReaderCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Memory :: getReader()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAdapterMemoryGetReader(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Memory - getReader()');

        $I->skipTest('Need implementation');
    }
}
