<?php

namespace Phalcon\Test\Unit\Validation;

use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\PresenceOf;
use UnitTester;

/**
 * Phalcon\Test\Integration\ValidationCest
 * Tests the \Phalcon\Validation component
 *
 * @copyright (c) 2011-2017 Phalcon Team
 * @link          http://www.phalconphp.com
 * @author        Andres Gutierrez <andres@phalconphp.com>
 * @author        Phalcon Team <team@phalconphp.com>
 * @package       Phalcon\Test\Integration
 *
 * The contents of this file are subject to the New BSD License that is
 * bundled with this package in the file LICENSE.txt
 *
 * If you did not receive a copy of the license and are unable to obtain it
 * through the world-wide-web, please send an email to license@phalconphp.com
 * so that we can send you a copy immediately.
 */
class ValidationCest
{
    /**
     * Tests the get
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10405
     * @author Phalcon Team <team@phalconphp.com>
     * @since  2016-06-27
     *
     * @param IntegrationTester $I
     */
    public function appendValidationMessageToTheNonObject(UnitTester $I)
    {
        $myValidator = new PresenceOf();
        $validation  = new Validation();

        $validation->bind(
            new \stdClass(),
            [
                'day'   => date('d'),
                'month' => date('m'),
                'year'  => date('Y') + 1,
            ]
        );

        $myValidator->validate($validation, 'foo');

        $expectedMessages = Messages::__set_state([
            '_position' => 0,
            '_messages' => [
                new Message('Field foo is required', 'foo', 'PresenceOf', 0),
            ],
        ]);

        $I->assertEquals($expectedMessages, $validation->getMessages());
    }
}
