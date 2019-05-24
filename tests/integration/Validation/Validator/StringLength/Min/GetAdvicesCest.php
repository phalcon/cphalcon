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

namespace Phalcon\Test\Integration\Validation\Validator\StringLength\Min;

use IntegrationTester;
use Phalcon\Collection;
use Phalcon\Validation\Validator\StringLength\Min;

class GetAdvicesCest
{
    /**
     * Tests Phalcon\Validation\Validator\StringLength\Min :: getAdvices()
     *
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2019-05-23
     */
    public function validationValidatorStringLengthMinGetAdvices(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Min - getAdvices()');

        $validator = new Min();

        $I->assertInstanceOf(Collection::class, $validator->getAdvices(), 'Advices instance of Collection');
        $I->assertCount(0, $validator->getAdvices(), 'Advices count 0');

        $messageLastName = "We don't like really long last names";
        $messageFirstName = "We don't like really long first names";

        $validator = new Min(
            [
                "min"      => [
                    "name_last"  => 50,
                    "name_first" => 40,
                ],
                "message"  => [
                    "name_last"  => $messageLastName,
                    "name_first" => $messageFirstName,
                ],
                "included" => [
                    "name_last"  => false,
                    "name_first" => true,
                ],
            ]
        );

        $I->assertInstanceOf(Collection::class, $validator->getAdvices(), 'Multi advices instance of Collection');
        $I->assertEquals(
            $messageLastName,
            $validator->getAdvices()->get('name_last'),
            'Last name advice'
        );
        $I->assertEquals(
            $messageFirstName,
            $validator->getAdvices()->get('name_first'),
            'First name advice'
        );
    }
}
