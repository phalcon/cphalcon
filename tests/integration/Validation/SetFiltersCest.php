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
use Phalcon\Validation\Validator\PresenceOf;

class SetFiltersCest
{
    /**
     * Tests Phalcon\Validation :: setFilters()
     *
     * @author Sid Roberts <https://github.com/SidRoberts>
     * @since  2019-05-27
     */
    public function validationSetFilters(IntegrationTester $I)
    {
        $I->wantToTest('Validation - setFilters()');

        $validation = new Validation();

        $validation->add(
            'name',
            new PresenceOf(
                [
                    'message' => 'The name is required',
                ]
            )
        );

        $validation->setFilters('name', 'trim');

        $messages = $validation->validate(
            [
                'name' => '    Sid    ',
            ]
        );

        $I->assertEquals(
            'Sid',
            $validation->getValue('name')
        );


        $messages = $validation->validate(
            [
                'name' => '        ',
            ]
        );

        $I->assertEmpty(
            '',
            $validation->getValue('name')
        );


        $I->assertEquals(
            'The name is required',
            $messages[0]->getMessage()
        );
    }
}
