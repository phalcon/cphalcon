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

namespace Phalcon\Test\Integration\Validation\Validator\Numericality;

use Codeception\Example;
use IntegrationTester;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Numericality;
use stdClass;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\Numericality :: validate()
     *
     * @dataProvider getExamples
     *
     * @author       Phalcon Team <team@phalcon.io>
     * @since        2018-11-13
     */
    public function validationValidatorNumericalityValidate(IntegrationTester $I, Example $example)
    {
        $I->wantToTest('Validation\Validator\Numericality - validate() ' . $example[0]);

        $entity        = new stdClass();
        $entity->price = $example[0];

        $validation = new Validation();
        $validation->setEntity($entity);
        $validator = new Numericality();

        $actual = $validator->validate($validation, 'price');
        $I->assertEquals($actual, $example[1]);
    }

    private function getExamples(): array
    {
        return [
            [1, true],
            [123, true],
            [123.45, true],
            ['1 234.56', true],
            ['1,234.56', true],
            ['1.23', true],
            ['1.123,56', true],
            ['1 234.56aa', false],
            ['1,234.56aa', false],
            ['1.23aa', false],
            ['1.123,56aa', false],
            [-1, true],
            [-123, true],
            [-123.45, true],
            ['-1 234.56', true],
            ['-1,234.56', true],
            ['-1.23', true],
            ['-1.123,56', true],
            ['-1 234.56aa', false],
            ['-1,234.56aa', false],
            ['-1.23aa', false],
            ['-1.123,56aa', false],
        ];
    }
}
