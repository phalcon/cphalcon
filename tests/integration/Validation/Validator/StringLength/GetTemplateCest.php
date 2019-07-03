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

use Phalcon\Validation\Validator\StringLength;
use UnitTester;

class GetTemplateCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength :: getTemplate()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthGetTemplate(UnitTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength - getTemplate()');

        $validator = new StringLength();

        $expected = 'The field :field is not valid for ' . StringLength::class;

        $I->assertEquals(
            $expected,
            $validator->getTemplate(),
            'Default template message'
        );

        $expected = 'New custom template message';

        $actual = $validator->setTemplate($expected);

        $I->assertInstanceOf(StringLength::class, $actual, 'Instance of StringLenght');

        $I->assertEquals(
            $expected,
            $validator->getTemplate(),
            'Get equals template message'
        );
    }
}
