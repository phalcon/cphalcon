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

namespace Phalcon\Tests\Integration\Validation;

use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\Date;
use Phalcon\Filter\Validation\Validator\Email;

class GetSetValidatorsCest
{
    /**
     * Tests Phalcon\Filter\Validation :: getValidators()/setValidators()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function filterValidationGetSetValidators(IntegrationTester $I)
    {
        $I->wantToTest('Validation - getValidators()/setValidators()');

        $validators = [
            'date'  => [
                new Date(),
            ],
            'email' => [
                new Email(),
            ],
        ];

        $validation = new Validation();

        $validation->setValidators($validators);

        $expected = $validators;
        $actual   = $validation->getValidators();
        $I->assertEquals($expected, $actual);
    }
}
