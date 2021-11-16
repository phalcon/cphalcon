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
use Phalcon\Validation;
use Phalcon\Validation\Validator\Date;
use Phalcon\Validation\Validator\Email;

class SetValidatorsCest
{
    /**
     * Tests Phalcon\Validation :: setValidators()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function validationSetValidators(IntegrationTester $I)
    {
        $I->wantToTest('Validation - setValidators()');

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

        $I->assertEquals(
            $validators,
            $validation->getValidators()
        );
    }
}
