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

namespace Phalcon\Tests\Unit\Support\Helper\Arr;

use Phalcon\Support\Helper\Arr\ValidateAll;
use UnitTester;

/**
 * Class ValidateAllCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class ValidateAllCest
{
    /**
     * Tests Phalcon\Support\Helper\Arr :: validateAll()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrValidateAll(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - validateAll()');

        $object     = new ValidateAll();
        $collection = [2, 3, 4, 5];
        $actual     = $object(
            $collection,
            function ($element) {
                return $element > 1;
            }
        );
        $I->assertTrue($actual);
    }
}
