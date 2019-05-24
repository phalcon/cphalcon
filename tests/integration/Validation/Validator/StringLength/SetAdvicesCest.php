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

use UnitTester;
use Phalcon\Validation\Validator\StringLength;

class SetAdvicesCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength :: setAdvices()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthSetAdvices(UnitTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength - setAdvices()');

        $validator = new StringLength();

        $expected = [
            'key-1' => 'value-1',
            'key-2' => 'value-2',
            'key-3' => 'value-3',
        ];

        $actual = $validator->setAdvices($expected);

        $I->assertInstanceOf(StringLength::class, $actual, 'Instance of StringLenght');

        $I->assertEquals(
            $expected,
            $validator->getAdvices()->toArray(),
            'Get equals advices'
        );
    }
}
