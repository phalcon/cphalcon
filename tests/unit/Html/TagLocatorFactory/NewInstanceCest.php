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

namespace Phalcon\Test\Unit\Html\TagLocatorFactory;

use UnitTester;

/**
 * Class NewInstanceCest
 */
class NewInstanceCest
{
    /**
     * Tests Phalcon\Html\TagLocatorFactory :: newInstance()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function htmlTaglocatorfactoryNewInstance(UnitTester $I)
    {
        $I->wantToTest('Html\TagLocatorFactory - newInstance()');
        $I->skipTest('Need implementation');
    }
}
