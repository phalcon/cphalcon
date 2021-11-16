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

namespace Phalcon\Tests\Integration\Validation\Validator;

use IntegrationTester;
use Phalcon\Validation\Validator\PresenceOf;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Validation\Validator :: __construct()
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function validationValidatorConstruct(IntegrationTester $I)
    {
        $I->wantToTest('Validation\Validator - __construct()');
        $I->skipTest('Need implementation');
    }

    /**
     * Tests Phalcon\Validation\Validator :: __construct() with message option
     */
    public function validationValidatorConstructWithMessage(IntegrationTester $I)
    {
        $validator_default = new PresenceOf(); // default message
        $validator_custom = new PresenceOf(['message' => 'Custom message']); // custom message

        // expected: FALSE - empty message for default text (not set)
        $I->assertEquals(
            false,
            $validator_default->getOption('message')
        );

        // expected: text message - has custom message (developer set this message)
        $I->assertEquals(
            'Custom message',
            $validator_custom->getOption('message')
        );

        $validator_custom = new PresenceOf(['template' => 'Custom message']); // custom message
        $I->assertEquals(
            'Custom message',
            $validator_custom->getOption('message')
        );

        $validator_custom = new PresenceOf(['Custom message']); // custom message
        $I->assertEquals(
            'Custom message',
            $validator_custom->getOption('message')
        );
    }
}
