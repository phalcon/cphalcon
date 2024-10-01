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

namespace Phalcon\Tests\Integration\Filter\Validation;

use IntegrationTester;
use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use stdClass;

use function date;

class ValidateCest
{
    /**
     * Tests Phalcon\Filter\Validation :: validate() - message to non object
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-06-27
     * @issue  10405
     */
    public function filterValidationValidateMessageToNonObject(IntegrationTester $I): void
    {
        $myValidator = new PresenceOf();
        $validation  = new Validation();

        $validation->bind(
            new stdClass(),
            [
                'day'   => date('d'),
                'month' => date('m'),
                'year'  => (string) (intval(date('Y')) + 1),
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

        $I->assertEquals($expectedMessages, $validation->getMessages());
    }
}
