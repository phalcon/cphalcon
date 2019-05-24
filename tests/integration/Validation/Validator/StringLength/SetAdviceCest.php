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

class SetAdviceCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength :: setAdvice()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthSetAdvice(UnitTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength - setAdvice()');

        $validator = new StringLength();

        $expected = 'New custom advice message';

        $actual = $validator->setAdvice($expected);

        $I->assertInstanceOf(StringLength::class, $actual, 'Instance of StringLenght');

        $I->assertEquals(
            $expected,
            $validator->getAdvice(),
            'Get equals advice message'
        );
    }
}
