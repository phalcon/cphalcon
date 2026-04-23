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

namespace Phalcon\Tests\Unit\Filter\Validation\Validator\Ip;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\Ip;
use Phalcon\Tests\AbstractUnitTestCase;

final class ValidateTest extends AbstractUnitTestCase
{
    /**
     * @author Gorka Guridi <gorka.guridi@gmail.com>
     * @since  2016-12-17
     */
    public function testFilterValidationValidatorIpMultipleField(): void
    {
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

        $this->assertCount(1, $messages);


        $messages = $validation->validate(
            [
                'ip'        => '192.168.10.20',
                'anotherIp' => '192.168.10.20',
            ]
        );

        $this->assertCount(1, $messages);


        $messages = $validation->validate(
            [
                'ip'        => '192.168.10.20',
                'anotherIp' => '',
            ]
        );

        $this->assertCount(0, $messages);


        $messages = $validation->validate(
            [
                'ip'        => '2001:cdba:0000:0000:0000:0000:3257:9652',
                'anotherIp' => '2001:cdba:0000:0000:0000:0000:3257:9652',
            ]
        );

        $this->assertCount(1, $messages);
    }

    /**
     * @author Gorka Guridi <gorka.guridi@gmail.com>
     * @since  2016-12-17
     */
    public function testFilterValidationValidatorIpSingleField(): void
    {
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

        $this->assertEmpty(
            $validation->validate(
                [
                    'ip' => '127.0.0.1',
                ]
            )
        );

        $this->assertEmpty(
            $validation->validate(
                [
                    'ip' => '',
                ]
            )
        );

        $this->assertEmpty(
            $validation->validate(
                [
                    'ip' => '',
                ]
            )
        );


        $messages = $validation->validate(
            [
                'ip' => '2001:cdba:0000:0000:0000:0000:3257:9652',
            ]
        );

        $this->assertNotEmpty($messages);

        $this->assertSame(
            'This is a test message',
            (string)$messages[0]
        );


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

        $this->assertNotEmpty(
            $validation->validate(
                [
                    'ip' => '127.0.0.1',
                ]
            )
        );

        $this->assertNotEmpty(
            $validation->validate(
                [
                    'ip' => '',
                ]
            )
        );

        $this->assertNotEmpty(
            $validation->validate(
                [
                    'ip' => '',
                ]
            )
        );

        $this->assertEmpty(
            $validation->validate(
                [
                    'ip' => '2001:cdba:0000:0000:0000:0000:3257:9652',
                ]
            )
        );
    }
}
