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

namespace Phalcon\Test\Unit\Validation\Validator\StringLength;

use Phalcon\Collection;
use Phalcon\Validation\Validator\StringLength;
use UnitTester;

class GetAdvicesCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength :: getAdvices()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthGetAdvices(UnitTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength - getAdvices()');

        $validator = new StringLength();

        $I->assertInstanceOf(
            Collection::class,
            $validator->getAdvices(),
            'Instance of Collection'
        );

        $I->assertCount(
            0,
            $validator->getAdvices(),
            'Empty advices'
        );
    }
}
