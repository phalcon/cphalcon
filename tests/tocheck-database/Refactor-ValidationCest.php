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

namespace Phalcon\Test\Integration;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\PresenceOf;
use stdClass;

class ValidationCest
{
    /**
     * Tests the get
     *
     * @issue  https://github.com/phalcon/cphalcon/issues/10405
     *
     * @since  2016-06-27
     *
     * @author Phalcon Team <team@phalcon.io>
     */
    public function appendValidationMessageToTheNonObject(IntegrationTester $I)
    {
        $myValidator = new PresenceOf();
        $validation  = new Validation();

        $validation->bind(
            new stdClass(),
            [
                'day'   => date('d'),
                'month' => date('m'),
                'year'  => date('Y') + 1,
            ]
        );

        $myValidator->validate($validation, 'foo');

        $expectedMessages = new Messages(
            [
                new Message(
                    'Field foo is required',
                    'foo',
                    PresenceOf::class,
                    0
                ),
            ]
        );

        $I->assertEquals(
            $expectedMessages,
            $validation->getMessages()
        );
    }
}
