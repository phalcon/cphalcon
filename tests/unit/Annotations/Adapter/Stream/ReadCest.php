<?php
declare(strict_types=1);

/**
 * This file is part of the Phalcon Framework.
 *
 * (c) Phalcon Team <team@phalcon.io>
 *
 * For the full copyright and license information, please view the LICENSE.txt
 * file that was distributed with this source code.
 */

namespace Phalcon\Test\Unit\Annotations\Adapter\Stream;

use UnitTester;

class ReadCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Stream :: read()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function annotationsAdapterStreamRead(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Stream - read()');

        $I->skipTest('Need implementation');
    }
}
