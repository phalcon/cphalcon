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

namespace Phalcon\Test\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

/**
 * Class ValidateAllCest
 */
class ValidateAllCest
{
    /**
     * Tests Phalcon\Helper\Arr :: validateAll()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-04-07
     */
    public function helperArrValidateAll(UnitTester $I)
    {
        $I->wantToTest('Helper\Arr - validateAll()');
        $collection = [2, 3, 4, 5];
        $actual     = Arr::validateAll(
            $collection,
            function ($element) {
                return $element > 1;
            }
        );
        $I->assertTrue($actual);
    }
}
