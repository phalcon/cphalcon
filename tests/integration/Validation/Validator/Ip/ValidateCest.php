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

namespace Phalcon\Test\Integration\Validation\Validator\Ip;

use IntegrationTester;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Ip;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Validation\Validator\Ip :: validate() - single field
     *
     * @param IntegrationTester $I
     *
     * @author Gorka Guridi <gorka.guridi@gmail.com>
     * @since  2016-12-17
     */
    public function validationValidatorIpSingleField(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\Ip :: validate() - single field');
        $validation = new Validation();
        $validation->add(
            'ip',
            new Ip(
                [
                    'message'       => 'This is a test message',
                    'version'       => Ip::VERSION_4,
                    'allowPrivate'  => true,
                    'allowReserved' => true,
                    'allowEmpty'    => true,
                ]
            )
        );

        $actual = $validation->validate(['ip' => '127.0.0.1']);
        $I->assertEmpty($actual);

        $actual = $validation->validate(['ip' => '']);
        $I->assertEmpty($actual);

        $actual = $validation->validate(['ip' => '']);
        $I->assertEmpty($actual);

        $messages = $validation->validate(
            [
                'ip' => '2001:cdba:0000:0000:0000:0000:3257:9652',
            ]
        );
        $I->assertNotEmpty($messages);

        $expected = 'This is a test message';
        $actual   = (string) $messages[0];
        $I->assertEquals($expected, $actual);

        $validation = new Validation();
        $validation->add(
            'ip',
            new Ip(
                [
                    'message'       => 'This is a test message',
                    'version'       => Ip::VERSION_4 | Ip::VERSION_6,
                    'allowPrivate'  => false,
                    'allowReserved' => false,
                    'allowEmpty'    => false,
                ]
            )
        );

        $actual = $validation->validate(['ip' => '127.0.0.1']);
        $I->assertNotEmpty($actual);

        $actual = $validation->validate(['ip' => '']);
        $I->assertNotEmpty($actual);

        $actual = $validation->validate(['ip' => '']);
        $I->assertNotEmpty($actual);

        $messages = $validation->validate(
            [
                'ip' => '2001:cdba:0000:0000:0000:0000:3257:9652',
            ]
        );
        $I->assertEmpty($messages);
    }

    /**
     * Tests Phalcon\Validation\Validator\Ip :: validate() - multiple field
     *
     * @param IntegrationTester $I
     *
     * @author Gorka Guridi <gorka.guridi@gmail.com>
     * @since  2016-12-17
     */
    public function validationValidatorIpMultipleField(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator\Ip :: validate() - multiple field');
        $validation = new Validation();
        $validation->add(
            [
                'ip',
                'anotherIp',
            ],
            new Ip(
                [
                    'message'       => [
                        'ip'        => 'This is a test message for ip',
                        'anotherIp' => 'This is a test message for another ip',
                    ],
                    'version'       => [
                        'ip'        => Ip::VERSION_4,
                        'anotherIp' => Ip::VERSION_6,
                    ],
                    'allowPrivate'  => [
                        'ip'        => true,
                        'anotherIp' => false,
                    ],
                    'allowReserved' => [
                        'ip'        => true,
                        'anotherIp' => false,
                    ],
                    'allowEmpty'    => [
                        'ip'        => false,
                        'anotherIp' => true,
                    ],
                ]
            )
        );

        $messages = $validation->validate(
            [
                'ip'        => '127.0.0.1',
                'anotherIp' => '127.0.0.1',
            ]
        );
        $I->assertCount(1, $messages);

        $messages = $validation->validate(
            [
                'ip'        => '192.168.10.20',
                'anotherIp' => '192.168.10.20',
            ]
        );
        $I->assertCount(1, $messages);

        $messages = $validation->validate(
            [
                'ip'        => '192.168.10.20',
                'anotherIp' => '',
            ]
        );
        $I->assertCount(0, $messages);

        $messages = $validation->validate(
            [
                'ip'        => '2001:cdba:0000:0000:0000:0000:3257:9652',
                'anotherIp' => '2001:cdba:0000:0000:0000:0000:3257:9652',
            ]
        );
        $I->assertCount(1, $messages);
    }
}
