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

namespace Phalcon\Tests\Integration\Filter\Validation\Validator;

use IntegrationTester;
use Phalcon\Filter\Validation\Validator\PresenceOf;

/**
 * Class ConstructCest
 */
class ConstructCest
{
    /**
     * Tests Phalcon\Filter\Validation\Validator :: __construct()
     * with message option
     *
     * @author Phalcon Team <team@phalcon.io>
     * @since  2018-11-13
     */
    public function filterValidationValidatorConstruct(IntegrationTester $I)
    {
        $message = uniqid('mes-');
        $default = new PresenceOf();                        // default message
        $custom  = new PresenceOf(['message' => $message]); // custom message

        // expected: null - empty message for default text (not set)
        $actual = $default->getOption('message');
        $I->assertNull($actual);

        // expected: text message - has custom message (developer set this message)
        $expected = $message;
        $actual   = $custom->getOption('message');
        $I->assertSame($expected, $actual);

        $custom   = new PresenceOf(['template' => $message]); // custom message
        $expected = $message;
        $actual   = $custom->getOption('message');
        $I->assertSame($expected, $actual);

        $custom   = new PresenceOf([$message]); // custom message
        $expected = $message;
        $actual   = $custom->getOption('message');
        $I->assertSame($expected, $actual);
    }
}
