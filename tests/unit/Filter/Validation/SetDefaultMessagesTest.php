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

namespace Phalcon\Tests\Unit\Filter\Validation;

use Phalcon\Filter\Validation;
use Phalcon\Filter\Validation\Validator\PresenceOf;
use Phalcon\Talon\PHPUnit\AbstractUnitTestCase;
use ReflectionProperty;

final class SetDefaultMessagesTest extends AbstractUnitTestCase
{
    /**
     * Reset the process-global default messages after each test so that the
     * registered defaults do not leak into other tests.
     */
    protected function tearDown(): void
    {
        $property = new ReflectionProperty(Validation::class, 'defaultMessages');
        $property->setAccessible(true);
        $property->setValue(null, []);

        parent::tearDown();
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function testFilterValidationSetDefaultMessages(): void
    {
        /**
         * No default registered - the validator class default is used
         */
        $validation = new Validation();
        $validation->add('name', new PresenceOf());
        $messages = $validation->validate([]);

        $this->assertSame(
            'Field name is required',
            $messages->offsetGet(0)->getMessage()
        );

        /**
         * A registered default overrides the validator class default
         */
        Validation::setDefaultMessages(
            [
                PresenceOf::class => 'Default message :field is required',
            ]
        );

        $validation = new Validation();
        $validation->add('name', new PresenceOf());
        $messages = $validation->validate([]);

        $this->assertSame(
            'Default message name is required',
            $messages->offsetGet(0)->getMessage()
        );

        /**
         * A message set on the validator instance wins over the default
         */
        $validation = new Validation();
        $validation->add(
            'name',
            new PresenceOf(
                [
                    'message' => 'Custom message :field is required',
                ]
            )
        );
        $messages = $validation->validate([]);

        $this->assertSame(
            'Custom message name is required',
            $messages->offsetGet(0)->getMessage()
        );
    }

    /**
     * @author Phalcon Team <team@phalcon.io>
     * @since  2019-04-16
     */
    public function testFilterValidationSetDefaultMessagesMergesAndReturns(): void
    {
        $expected = [
            PresenceOf::class => 'One :field',
        ];
        $actual = Validation::setDefaultMessages($expected);
        $this->assertSame($expected, $actual);

        $this->assertSame(
            'One :field',
            Validation::getDefaultMessage(PresenceOf::class)
        );

        /**
         * A second call merges rather than replaces
         */
        $expected = [
            PresenceOf::class    => 'One :field',
            'Some\Fake\Validator' => 'Two',
        ];
        $actual = Validation::setDefaultMessages(
            [
                'Some\Fake\Validator' => 'Two',
            ]
        );
        $this->assertSame($expected, $actual);

        /**
         * An unregistered class returns an empty string
         */
        $this->assertSame(
            '',
            Validation::getDefaultMessage('Unregistered\Validator')
        );
    }
}
