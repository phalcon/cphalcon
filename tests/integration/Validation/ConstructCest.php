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

namespace Phalcon\Test\Integration\Validation;

use IntegrationTester;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Date;
use Phalcon\Validation\Validator\Email;

class ConstructCest
{
    /**
     * Tests Phalcon\Validation :: __construct()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-25
     */
    public function validationConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Validation - __construct()');

        $validators = [
            'date'  => [
                new Date(),
            ],
            'email' => [
                new Email(),
            ],
        ];

        $validation = new Validation($validators);

        $I->assertEquals(
            $validators,
            $validation->getValidators()
        );
    }
}
