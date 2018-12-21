<?php

namespace Phalcon\Test\Unit\Validation\Validator;

use Phalcon\Test\Module\UnitTest;
use Phalcon\Validation;
use Phalcon\Validation\Validator\Ip;

/**
 * \Phalcon\Test\Unit\Validation\Validator\DateTest
 * Tests the \Phalcon\Validation\Validator\Date component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link      http://www.phalconphp.com
 * @author    Gorka Guridi <gorka.guridi@gmail.com>
 * @package   Phalcon\Test\Unit\Validation\Validator
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file docs/LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class IpTest extends UnitTest
{
    /**
     * Tests date validator with single field
     *
     * @author Gorka Guridi <gorka.guridi@gmail.com>
     * @since  2016-12-17
     */
    public function testSingleField()
    {
        $this->specify('Test single ip address validator with single field.', function () {
            $validation = new Validation();
            $validation->add('ip', new Ip([
                'message' => 'This is a test message',
                'version' => Ip::VERSION_4,
                'allowPrivate' => true,
                'allowReserved' => true,
                'allowEmpty' => true,
            ]));

            expect($validation->validate(['ip' => '127.0.0.1']))->isEmpty();
            expect($validation->validate(['ip' => '192.168.10.20']))->isEmpty();
            expect($validation->validate(['ip' => '']))->isEmpty();
            $messages = $validation->validate(['ip' => '2001:cdba:0000:0000:0000:0000:3257:9652']);
            expect($messages)->notEmpty();
            expect((string) $messages[0])->equals('This is a test message');

            $validation = new Validation();
            $validation->add('ip', new Ip([
                'message' => 'This is a test message',
                'version' => Ip::VERSION_4 | Ip::VERSION_6,
                'allowPrivate' => false,
                'allowReserved' => false,
                'allowEmpty' => false,
            ]));

            expect($validation->validate(['ip' => '127.0.0.1']))->notEmpty();
            expect($validation->validate(['ip' => '192.168.10.20']))->notEmpty();
            expect($validation->validate(['ip' => '']))->notEmpty();
            expect($validation->validate(['ip' => '2001:cdba:0000:0000:0000:0000:3257:9652']))->isEmpty();
        });
    }

    /**
     * Tests ip addresses with multiple field
     *
     * @author Gorka Guridi <gorka.guridi@gmail.com>
     * @since  2016-12-17
     */
    public function testMultipleField()
    {
        $this->specify('Test multiple ip addresses behaviour.', function () {
            $validation = new Validation();
            $validation->add(['ip', 'anotherIp'], new Ip([
                'message' => [
                    'ip' => 'This is a test message for ip',
                    'anotherIp' => 'This is a test message for another ip',
                ],
                'version' => [
                    'ip' => Ip::VERSION_4,
                    'anotherIp' => Ip::VERSION_6,
                ],
                'allowPrivate' => [
                    'ip' => true,
                    'anotherIp' => false,
                ],
                'allowReserved' => [
                    'ip' => true,
                    'anotherIp' => false,
                ],
                'allowEmpty' => [
                    'ip' => false,
                    'anotherIp' => true,
                ],
            ]));

            $messages = $validation->validate([
                'ip' => '127.0.0.1',
                'anotherIp' => '127.0.0.1',
            ]);
            expect($messages)->count(1);
            $messages = $validation->validate([
                'ip' => '192.168.10.20',
                'anotherIp' => '192.168.10.20',
            ]);
            expect($messages)->count(1);
            $messages = $validation->validate([
                'ip' => '192.168.10.20',
                'anotherIp' => '',
            ]);
            expect($messages)->count(0);
            $messages = $validation->validate([
                'ip' => '2001:cdba:0000:0000:0000:0000:3257:9652',
                'anotherIp' => '2001:cdba:0000:0000:0000:0000:3257:9652',
            ]);
            expect($messages)->count(1);
        });
    }
}
