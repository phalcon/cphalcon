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

namespace Phalcon\Test\Unit\Annotations\Collection;

use UnitTester;

/**
 * Class HasCest
 */
class HasCest
{
    /**
     * Tests Phalcon\Annotations\Collection :: has()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function annotationsCollectionHas(UnitTester $I)
    {
        $I->wantToTest('Annotations\Collection - has()');
        $I->skipTest('Need implementation');
    }
}
