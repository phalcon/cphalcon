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
use Phalcon\Filter\Validation\Validator\Alpha;
use Phalcon\Filter\Validation\Validator\Email;
use Phalcon\Filter\Validation\Validator\PresenceOf;

class RuleCest
{
    /**
     * Tests Phalcon\Filter\Validation :: rule()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-27
     */
    public function filterValidationRule(IntegrationTester $I)
    {
        $I->wantToTest('Validation - rule()');

        $alpha      = new Alpha();
        $presenceOf = new PresenceOf();
        $email      = new Email();

        $validation = new Validation();

        $validation->rule(
            'name',
            $alpha
        );

        $validation->rule(
            'name',
            $presenceOf
        );

        $validation->rule(
            'email',
            $email
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
