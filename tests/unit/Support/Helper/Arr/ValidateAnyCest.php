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

use Phalcon\Support\Helper\Arr\ValidateAny;
use UnitTester;

/**
 * Class ValidateAnyCest
 *
 * @package Phalcon\Tests\Unit\Support\Helper\Arr
 */
class ValidateAnyCest
{
    /**
     * Tests Phalcon\Support\Helper\Arr :: validateAny()
     *
     * @param UnitTester $I
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2020-09-09
     */
    public function supportHelperArrValidateAny(UnitTester $I)
    {
        $I->wantToTest('Support\Helper\Arr - validateAny()');

        $object     = new ValidateAny();
        $collection = [1, 2, 3, 4, 5];
        $actual     = $object(
            $collection,
            function ($element) {
                return $element < 2;
            }
        );
        $I->assertTrue($actual);
    }
}
