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
 * Class ValidCest
 */
class ValidCest
{
    /**
     * Tests Phalcon\Annotations\Collection :: valid()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2018-11-13
     */
    public function annotationsCollectionValid(UnitTester $I)
    {
        $I->wantToTest('Annotations\Collection - valid()');
        $I->skipTest('Need implementation');
    }
}
