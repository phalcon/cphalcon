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

namespace Phalcon\Tests\Integration\Validation\Validator\StringLength\Min;

use IntegrationTester;
use Phalcon\Filter\Validation\Validator\StringLength\Min;

class GetTemplatesCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator\StringLength\Min :: getTemplates()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-05-23
     */
    public function filterValidationValidatorStringLengthMinGetTemplates(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\StringLength\Min - getTemplates()');

        $validator = new Min();

        $I->assertTrue(is_array($validator->getTemplates()), 'Templates have to be an array');
        $I->assertCount(0, $validator->getTemplates(), 'templates count 0');

        $messageLastName  = "We don't like really long last names";
        $messageFirstName = "We don't like really long first names";

        $validator = new Min(
            [
                'min'      => [
                    'name_last'  => 50,
                    'name_first' => 40,
                ],
                'message'  => [
                    'name_last'  => $messageLastName,
                    'name_first' => $messageFirstName,
                ],
                'included' => [
                    'name_last'  => false,
                    'name_first' => true,
                ],
            ]
        );

        $I->assertTrue(is_array($validator->getTemplates()), 'Multi templates have to be an array');
        $I->assertEquals(
            $messageLastName,
            $validator->getTemplate('name_last'),
            'Last name template'
        );
        $I->assertEquals(
            $messageFirstName,
            $validator->getTemplate('name_first'),
            'First name template'
        );
    }
}
