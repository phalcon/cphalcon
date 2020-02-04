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

namespace Phalcon\Test\Integration\Validation;

use IntegrationTester;
use Phalcon\Messages\Message;
use Phalcon\Messages\Messages;
use Phalcon\Validation;
use Phalcon\Validation\Validator\PresenceOf;
use stdClass;

use function date;

/**
 * Class ValidateCest
 */
class ValidateCest
{
    /**
     * Tests Phalcon\Validation :: validate()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function validationValidate(IntegrationTester $I)
    {
        $I->wantToTest('Validation - validate()');

        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Validation :: validate() - message to non object
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2016-06-27
     * @issue  10405
     */
    public function validationValidateMessageToNonObject(IntegrationTester $I)
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

        $I->assertEquals($expectedMessages, $validation->getMessages());
    }
}
