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

namespace Phalcon\Test\Integration\Validation;

use IntegrationTester;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Alpha;
use Phalcon\Validation\Validator\Email;
use Phalcon\Validation\Validator\PresenceOf;

class RulesCest
{
    /**
     * Tests Phalcon\Validation :: rules()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-27
     */
    public function validationRules(IntegrationTester $I)
    {
        $I->wantToTest('Validation - rules()');

        $alpha      = new Alpha();
        $presenceOf = new PresenceOf();
        $email      = new Email();

        $validation = new Validation();

        $validation->rules(
            'name',
            [
                $alpha,
                $presenceOf,
            ]
        );

        $validation->rules(
            'email',
            [
                $email,
            ]
        );

        $I->assertEquals(
            [
                'name'  => [
                    $alpha,
                    $presenceOf,
                ],
                'email' => [
                    $email,
                ],
            ],
            $validation->getValidators()
        );
    }
}
