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

namespace Phalcon\Test\Unit\Annotations\Adapter\Memory;

use UnitTester;

/**
 * Class ReadCest
 */
class ReadCest
{
    /**
     * Tests Phalcon\Annotations\Adapter\Memory :: read()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function annotationsAdapterMemoryRead(UnitTester $I)
    {
        $I->wantToTest('Annotations\Adapter\Memory - read()');
        $I->skipTest('Need implementation');
    }
}
