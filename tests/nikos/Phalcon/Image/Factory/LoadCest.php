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

namespace Phalcon\Test\Unit\Image\Factory;

use UnitTester;

/**
 * Class LoadCest
 */
class LoadCest
{
    /**
     * Tests Phalcon\Image\Factory :: load()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-02-10
     */
    public function imageFactoryLoad(UnitTester $I)
    {
        $I->wantToTest('Image\Factory - load()');
        $I->skipTest('Need implementation');
    }
}
