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

namespace Phalcon\Tests\Unit\Helper\Arr;

use Phalcon\Helper\Arr;
use UnitTester;

class ValidateAllCest
{
    /**
     * Tests Phalcon\Helper\Arr :: validateAll()
     *
     * @author Phalcon Team <team@phalcon.io>
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
